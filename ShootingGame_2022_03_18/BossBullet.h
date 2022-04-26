#pragma once

#include "Sprite.h"

class BossBullet : public Sprite
{
private:
	float speed;

	float angle;
	float lifeTime;

public:
	BossBullet(float px, float py);
	~BossBullet();

	void Start();
	void Update();
	void SetAngle(float angle);

};

