#pragma once

#ifdef CR_PLATFORM_WINDOWS

extern Cherry::Application* Cherry::CreateApplication();

int main(int argc, char** argv)
{
	Cherry::Log::Init();
	CR_CORE_WARN("Initialized Log!");

	auto app = Cherry::CreateApplication();
	app->Run();
	delete app;
}
#endif