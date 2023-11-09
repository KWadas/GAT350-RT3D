#include "World05.h"
#include "Framework/Framework.h"
#include "Input/InputSystem.h"

#include <glm/glm/gtc/type_ptr.hpp>
#include <glm/glm/gtx/color_space.hpp>

#define INTERLEAVE

namespace nc
{
    bool World05::Initialize()
    {
        m_scene = std::make_unique<Scene>();
        m_scene->Load("scenes/scene.json");
        m_scene->Initialize();

        //{
        //    auto actor = CREATE_CLASS(Actor);
        //    actor->name = "light1";
        //    actor->transform.position = glm::vec3{ 3, 3, 3 };
        //    auto lightComponent = CREATE_CLASS(LightComponent);
        //    lightComponent->type = LightComponent::eType::Point;
        //    lightComponent->color = glm::vec3{ 1, 1, 1 }; //glm::rgbColor(glm::vec3{ randomf() * 360, 1, 1 });
        //    lightComponent->intensity = 1;
        //    lightComponent->range = 20;
        //    lightComponent->innerAngle = 10.0f;
        //    lightComponent->outerAngle = 30.0f;
        //    actor->AddComponent(std::move(lightComponent));
        //    m_scene->Add(std::move(actor));
        //}

        {
            auto actor = CREATE_CLASS(Actor);
            actor->name = "camera1";
            actor->transform.position = glm::vec3{ 0, 3, 7 };
            actor->transform.rotation = glm::radians(glm::vec3{ 0, 180, 0 });

            auto cameraComponent = CREATE_CLASS(CameraComponent);
            cameraComponent->SetPerspective(70.0f, ENGINE.GetSystem<Renderer>()->GetWidth() / (float)ENGINE.GetSystem<Renderer>()->GetHeight(), 0.1f, 100.0f);
            actor->AddComponent(std::move(cameraComponent));

            auto cameraController = CREATE_CLASS(CameraController);
            cameraController->speed = 5;
            cameraController->sensitivity = 0.5f;
            cameraController->m_owner = actor.get();
            cameraController->Initialize();
            actor->AddComponent(std::move(cameraController));

            m_scene->Add(std::move(actor));
        }

        /*for (int i = 0; i < 0; i++)
        {
            auto actor = CREATE_CLASS_BASE(Actor, "tree");
            actor->name = StringUtils::CreateUnique("tree");
            actor->transform.position = glm::vec3{ randomf(-10, 10), 0, randomf(-10, 10) };
            actor->transform.scale = glm::vec3{ random(0.5f, 3.0f), random(0.5f, 3.0f), 0 };
            actor->active = true;
            actor->Initialize();
            m_scene->Add(std::move(actor));
        }*/

        return true;
    }

    void World05::Shutdown()
    {
    }

    void World05::Update(float dt)
    {
        ENGINE.GetSystem<Gui>()->BeginFrame();

        m_scene->Update(dt);
        m_scene->ProcessGui();

        auto actor = m_scene->GetActorByName<Actor>("actor1");

        auto material = actor->GetComponent<ModelComponent>()->material;

        material->ProcessGui();
        material->Bind();

        material = GET_RESOURCE(Material, "materials/refraction.mtrl");
        if (material) 
        {
            ImGui::Begin("Refraction");

            m_refraction = 1.0f + std::fabs(std::sin(m_time * 0.01f));

            ImGui::DragFloat("IOR", &m_refraction, 0.01f, 1, 3);
            auto program = material->GetProgram();
            program->Use();
            program->SetUniform("ior", m_refraction);

            ImGui::End();
        }

        m_time += dt;

        ENGINE.GetSystem<Gui>()->EndFrame();
    }

    void World05::Draw(Renderer& renderer)
    {
        // pre-render
        renderer.BeginFrame();
        // render
        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        m_scene->Draw(renderer);
        //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        ENGINE.GetSystem<Gui>()->Draw();
        // post-render
        renderer.EndFrame();
    }
}

/*
        {
            "type": "Actor",
            "name": "camera1",
            "persistent": true,
            "active": true,
            "transform": {
                "position": [ 0, 3, 7 ],
                "rotation": [ 0, 180, 0 ]
            },
            "components": [
                {
                    "type": "CameraComponent",
                    "fov": 80.0,
                    "aspect": 0,
                    "near": 0.1,
                    "far": 100
                },
                {
                    "type": "CameraController",
                    "sensitivity": 0.1,
                    "speed": 0,
                    "yaw": 0,
                    "pitch": 0
                }
            ]
        },
*/