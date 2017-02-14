#pragma once

namespace PlayerState
{
	enum Info
	{
		Left,
		Right
	};
}

class Player : public Object
{
private:
	AnimationSprite* leftWalk;
	AnimationSprite* rightWalk;
	PlayerState::Info playerInfo;

	float speed;

public:
	Player();
	~Player();

	void Update(float deltaTime) override;
	void Render();
};