#pragma once

#include "Sprite.h"

class BossRadar : public Sprite
{
private:

public:
	BossRadar(float px, float py);
	~BossRadar();

	void Start();
	void Update();
};

