#pragma once

#include "BossChildSprite.h"

class BossRadar : public BossChildSprite
{
private:

public:
	BossRadar(float px, float py);
	~BossRadar();

	void Start();
	void Update();
};

