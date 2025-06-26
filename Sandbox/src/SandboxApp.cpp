#include <Cherry.h>

class ExampleLayer : public Cherry::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//CR_INFO("ExampleLayer::OnUpdate");
	}
	void OnEvent(Cherry::Event& event) override
	{
		//CR_TRACE("{0}", event);
	}
};

class Sandbox : public Cherry::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Cherry::ImGuiLayer());
	}

	~Sandbox()
	{

	}


};

Cherry::Application* Cherry::CreateApplication()
{
	return new Sandbox();
}