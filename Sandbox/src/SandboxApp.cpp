#include <Lupus.h>

class Sandbox : public Lupus::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

Lupus::Application* Lupus::CreateApplication()
{
	return new Sandbox();
}