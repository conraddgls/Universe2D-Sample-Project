#include "Precompiled.h"
#include "Player.h"

Player::Player() : playerInfo(PlayerState::Right)
{
	speed = 100.0f;

	leftWalk = new AnimationSprite(5, 5);
	leftWalk->AddFrame(0, L"Resources\\Left\\0.png");
	leftWalk->AddFrame(1, L"Resources\\Left\\1.png");
	leftWalk->AddFrame(2, L"Resources\\Left\\2.png");
	leftWalk->AddFrame(3, L"Resources\\Left\\3.png");
	leftWalk->AddFrame(4, L"Resources\\Left\\4.png");
	leftWalk->SetUpdate(false);
	leftWalk->SetVisible(false);

	rightWalk = new AnimationSprite(5, 5);
	rightWalk->AddFrame(0, L"Resources\\Right\\0.png");
	rightWalk->AddFrame(1, L"Resources\\Right\\1.png");
	rightWalk->AddFrame(2, L"Resources\\Right\\2.png");
	rightWalk->AddFrame(3, L"Resources\\Right\\3.png");
	rightWalk->AddFrame(4, L"Resources\\Right\\4.png");
	rightWalk->SetUpdate(false);
	rightWalk->SetVisible(true);

	AddChild(leftWalk);
	AddChild(rightWalk);
}

Player::~Player()
{
	delete leftWalk;
	delete rightWalk;
}

void Player::Update(float deltaTime)
{
	Object::Render();
	// ÀÌµ¿
	if (Input::GetInstance()->GetKeyState('A') == KeyState::KEY_PRESSED)
	{
		this->Transform(-speed * deltaTime, 0);
		leftWalk->SetUpdate(true);
		leftWalk->SetVisible(true);
		rightWalk->SetVisible(false);
		if (GetPosition().x > 640 && GetPosition().x < 740)
		{
			Director::GetInstance()->GetScene()->Transform(speed * deltaTime, 0);
		}
	}
	else if (Input::GetInstance()->GetKeyState('D') == KeyState::KEY_PRESSED)
	{
		this->Transform(speed * deltaTime, 0);
		rightWalk->SetUpdate(true);
		rightWalk->SetVisible(true);
		leftWalk->SetVisible(false);
		if (GetPosition().x > 640 && GetPosition().x < 740)
		{
			Director::GetInstance()->GetScene()->Transform(-speed * deltaTime, 0);
		}
	}
	else
	{
		leftWalk->SetUpdate(false);
		rightWalk->SetUpdate(false);
	}
}

void Player::Render()
{
	Object::Render();
}