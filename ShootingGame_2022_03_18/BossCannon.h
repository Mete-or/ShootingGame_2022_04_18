#pragma once
#include "Sprite.h"

class BossCannon : public Sprite
{
private:

public:
	BossCannon(float px, float py);
	~BossCannon();

	void Start();
	void Update();

};

