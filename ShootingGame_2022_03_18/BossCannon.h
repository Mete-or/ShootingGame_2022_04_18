#pragma once
#include "BossChildSprite.h"

class BossCannon : public BossChildSprite
{
private:
	float hp;

	float fireTimer;
	float fireDelay;

	bool doFire;

public:
	BossCannon(float px, float py,string name);
	~BossCannon();

	void Start();

	//void Update();
	//void Explosion();
	//void OnTriggerStay2D(GameObject *other);

	void Update();

	//�߻� ���� �̺�Ʈ �Լ� //
	void OnStartFire();

};

