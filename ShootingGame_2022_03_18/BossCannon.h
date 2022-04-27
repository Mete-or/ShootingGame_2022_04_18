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

	//발사 시작 이벤트 함수 //
	void OnStartFire();

};

