#pragma once
#include "Framework/World.h"
#include "Renderer/Renderer.h"
#include "Core/Math/Transform.h"
#include <vector>

namespace nc
{
	class World06 : public World
	{
	public:
		uint32_t INVERT_MASK		= (1 << 0);
		uint32_t GRAYSCALE_MASK		= (1 << 1);
		uint32_t COLORTINT_MASK		= (1 << 2);
		uint32_t GRAIN_MASK			= (1 << 3);
		uint32_t SCANLINE_MASK		= (1 << 4);
		uint32_t KERNEL_MASK		= (1 << 5);

	public:
		bool Initialize() override;
		void Shutdown() override;
		void Update(float dt) override;
		void Draw(Renderer& renderer) override;

	private:
		float m_time;
		float m_speed = 5;
		float m_blend{ 1 };
		glm::vec3 tint{ 1, 1, 1 };

		uint32_t m_params{ 0 };

		float m_refraction{ 1 };
		glm::vec3 m_ambientLight{ 0.2f };
		int m_postSelect = 1;
	};
}