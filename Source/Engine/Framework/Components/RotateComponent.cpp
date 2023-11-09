#include "RotateComponent.h"
#include "Core/Math/MathUtils.h"
#include "Framework/Framework.h"

namespace nc
{
	CLASS_DEFINITION(RotateComponent);

	bool RotateComponent::Initialize()
	{
		return true;
	}

	void RotateComponent::Update(float dt)
	{
		m_owner->transform.euler += euler * dt;
		
		glm::quat rotation = EulerToQuaternion(euler * dt);
		m_owner->transform.rotation = m_owner->transform.rotation * rotation;
	}

	void RotateComponent::ProcessGui()
	{
		ImGui::DragFloat3("Euler Rotation", glm::value_ptr(euler), 1);
	}

	void RotateComponent::SetProgram(const res_t<Program> program)
	{
		program->SetUniform("euler", euler);
	}

	void RotateComponent::Read(const nc::json_t& value)
	{
		// read json file
		READ_DATA(value, euler);
	}
}