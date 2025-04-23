#pragma once

#ifdef CR_PLATFORM_WINDOWS

extern Cherry::Application* Cherry::CreateApplication();

int main(int argc, char** argv)
{
	printf("Welcome to the Cherry Engine!");
	auto app = Cherry::CreateApplication();
	app->Run();
	delete app;
}
#endif