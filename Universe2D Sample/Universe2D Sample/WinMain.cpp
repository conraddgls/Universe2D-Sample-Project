#include "Precompiled.h"
#include "SampleScene.h"

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	Application* app = Application::GetInstance();
	app->Initialize(L"Universe2D.Sample1", 1280, 820, false);

	Director::GetInstance()->SetScene(new SampleScene());

	app->Run();
	app->Release();
}