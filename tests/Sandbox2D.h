#pragma once

#include <Placeholder.h>

class Sandbox2D : public Placeholder::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Placeholder::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Placeholder::Event& e) override;
private:
	Placeholder::OrthographicCameraController m_CameraController;
	
	// Temp
	Placeholder::Ref<Placeholder::VertexArray> m_SquareVA;
	Placeholder::Ref<Placeholder::Shader> m_FlatColorShader;

	Placeholder::Ref<Placeholder::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};