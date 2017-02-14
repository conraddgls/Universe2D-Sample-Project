#include "Precompiled.h"
#include "SampleScene.h"
#include "Player.h"

SampleScene::SampleScene()
{
	Background = Sprite::Create(L"Resources\\Background\\image.jpg");

	Player* player = new Player();
	player->Transform(0, 630);

	AddChild(Background);
	AddChild(player);
}

SampleScene::~SampleScene()
{
}

void SampleScene::Update(float deltaTime)
{
	Scene::Update(deltaTime);
}

void SampleScene::Render()
{
	Object::Render();
}
