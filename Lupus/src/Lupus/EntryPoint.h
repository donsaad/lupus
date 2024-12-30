#pragma once

#ifdef LP_PLATFORM_WINDOWS

extern Lupus::Application* Lupus::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Lupus::CreateApplication();
	app->Run();
	delete app;
}
#endif