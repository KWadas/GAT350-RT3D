#include "World01.h"
#include "Framework/Framework.h"
#include "Renderer/Renderer.h"
#include "Input/InputSystem.h"

namespace nc
{
    bool World01::Initialize()
    {
        for (int i = 0; i < 10; i++)
        {
            m_positions.push_back({ randomf(-1, 1), randomf(-1, 1) });
        }

        return true;
    }

    void World01::Shutdown()
    {
    }

    void World01::Update(float dt)
    {
        m_angle += 90 * dt;
        m_position.x += ENGINE.GetSystem<InputSystem>()->GetKeyDown(SDL_SCANCODE_A) ? -dt : 0;
        m_position.x += ENGINE.GetSystem<InputSystem>()->GetKeyDown(SDL_SCANCODE_D) ? dt : 0;
        m_position.y += ENGINE.GetSystem<InputSystem>()->GetKeyDown(SDL_SCANCODE_S) ? -dt : 0;
        m_position.y += ENGINE.GetSystem<InputSystem>()->GetKeyDown(SDL_SCANCODE_W) ? dt : 0;
        m_time += dt;
    }

    void World01::Draw(Renderer& renderer)
    {
        // pre-render
        renderer.BeginFrame();

        //for (int i = 0; i < 10; i++)
        //{
        //    // render
        //    glPushMatrix();
        //    glTranslatef(m_positions[i].x, -0.5f, 0);
        //    //glRotatef(m_angle, 1, 1, 1);
        //    //glScalef((sin(m_time * 5) + 1) * 0.5f, 1, 1);

        //    glBegin(GL_TRIANGLES);

        //    glColor3f(0.2f, 0.2f, 0.2f);
        //    glVertex2f(-0.5f, -0.5f);

        //    glColor3f(0.75f, 0.75f, 0.75f);
        //    glVertex2f(0, 0.5f);

        //    glColor3f(0.2f, 0.2f, 0.2f);
        //    glVertex2f(0.5f, -0.5f);

        //    glEnd();

        //    glPopMatrix();
        //}

        glPushMatrix();

        // EYES
        glBegin(GL_QUADS);

        glColor3f(0, 0, 1);
        glVertex2f(-0.2f, -0.2f);

        glColor3f(0, 0, 1);
        glVertex2f(-0.2f, 0);

        glColor3f(0, 0, 1);
        glVertex2f(0.2f, 0);

        glColor3f(0, 0, 1);
        glVertex2f(0.2f, -0.2f);

        glEnd();

        // FACEPLATE
        glBegin(GL_QUADS);

        glColor3f(0.7f, 0.7f, 0.7f);
        glVertex2f(0.1f, -0.6f);

        glColor3f(0.7f, 0.7f, 0.7f);
        glVertex2f(-0.1f, -0.6f);

        glColor3f(0.7f, 0.7f, 0.7f);
        glVertex2f(-0.2f, -0.2f);

        glColor3f(0.7f, 0.7f, 0.7f);
        glVertex2f(0.2f, -0.2f);

        glEnd();

        // VISOR
        glBegin(GL_POLYGON);

        glColor3f(0, 0, 0.5f);
        glVertex2f(-0.1f, -0.025f);

        glColor3f(0, 0, 0.5f);
        glVertex2f(-0.2f, 0);

        glColor3f(0, 0, 0.5f);
        glVertex2f(-0.2f, 0.05f);

        glColor3f(0, 0, 0.5f);
        glVertex2f(-0.1f, 0.1f);

        glColor3f(0, 0, 0.5f);
        glVertex2f(0.1f, 0.1f);

        glColor3f(0, 0, 0.5f);
        glVertex2f(0.2f, 0.05f);

        glColor3f(0, 0, 0.5f);
        glVertex2f(0.2f, 0);

        glColor3f(0, 0, 0.5f);
        glVertex2f(0.1f, -0.025f);

        glEnd();

        glPopMatrix();

        //// render
        //glPushMatrix();
        //glTranslatef(m_position.x, m_position.y, 0);
        //glRotatef(m_angle, 1, 1, 1);
        //glScalef(1.5f, 1, 1);

        //glBegin(GL_TRIANGLES);

        //glColor3f(0.1f, 0.1f, 0.1f);
        //glVertex2f(-0.5f, -0.5f);

        //glColor3f(0.1f, 0.1f, 0.1f);
        //glVertex2f(0, 0.5f);

        //glColor3f(0.1f, 0.1f, 0.1f);
        //glVertex2f(0.5f, -0.5f);

        //glEnd();

        //glPopMatrix();

        //// render
        //glPushMatrix();
        //glTranslatef(m_position.x, m_position.y, 0);
        //glRotatef(m_angle, 1, 1, 1);
        ////glScalef((sin(m_time * 5) + 1) * 0.5f, 1, 1);

        //glBegin(GL_TRIANGLES);

        //glColor3f(1, 0, 0);
        //glVertex2f(-0.5f, -0.5f);

        //glColor3f(1, 0, 0);
        //glVertex2f(0, 0.5f);

        //glColor3f(1, 0, 0);
        //glVertex2f(0.5f, -0.5f);

        //glEnd();

        //glPopMatrix();

        

        // post-render
        renderer.EndFrame();
    }
}
