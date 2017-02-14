#pragma once

class SampleScene : public Scene
{
private:
	Sprite* Background;

public:
	SampleScene();
	~SampleScene();

	void Update(float deltaTime);
	void Render();
};