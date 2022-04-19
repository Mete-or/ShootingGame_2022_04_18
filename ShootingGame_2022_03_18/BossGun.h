#pragma once
#include "Sprite.h"
class BossGun : public Sprite
{
private:
	


public:
	BossGun(float px, float py);
	~BossGun();

	void Start();
	void Update();
};

