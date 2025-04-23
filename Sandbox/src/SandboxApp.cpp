#include <Cherry.h>

class Sandbox : public Cherry::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}


};

Cherry::Application* Cherry::CreateApplication()
{
	return new Sandbox();
}