#include "ShootingGame.h"
#include "framework.h"

BossBullet::BossBullet(float px, float py) : Sprite("","",true,px,py)
{
	this->speed = 150;
	this->angle = 0;

	this->lifeTime = 5;
}
BossBullet::~BossBullet()
{

}

void BossBullet::Start()
{
	SetSprite("Asset/ÃÑ¾Ë2.bmp");
}
void BossBullet::Update()
{

	float theta = angle * M_PI / 180; // 90µµ

	float dx = cos(theta) * speed * Time::deltaTime;
	float dy = sin(theta) * speed * Time::deltaTime;

	Translate(dx,dy);
	
	lifeTime -= Time::deltaTime;

	if (lifeTime < 0)
	{
		Destroy(this);
	}

}
void BossBullet::SetAngle(float angle)
{
	this->angle = angle;
}
