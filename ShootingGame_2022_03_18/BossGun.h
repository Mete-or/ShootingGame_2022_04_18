#pragma once
#include "BossChildSprite.h"
class BossGun : public BossChildSprite
{
private:
	
	
public:
	BossGun(float px, float py, string name);
	~BossGun();

	void Start();
	void Update();
	void OnStartFire();
	void OnFire();

};

