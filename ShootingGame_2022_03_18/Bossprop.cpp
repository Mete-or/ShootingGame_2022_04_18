#include "ShootingGame.h"


Bossprop::Bossprop(float px, float py) : Animation("", "", true, px, py)
{

}
Bossprop::~Bossprop()
{

}

void Bossprop::Start()
{
	//피해없는 프로펠러 애니메이션 - 0번//
	AddSprite("Asset/보스.bmp",   6, 438, 32, 12, 0);
	AddSprite("Asset/보스.bmp",  42, 438, 32, 12, 0);
	//AddSprite("Asset/보스.bmp",  74, 439, 28, 12, 0);
	//AddSprite("Asset/보스.bmp", 105, 439, 23, 12, 0);

	//AddSprite("Asset/보스.bmp", 132, 439, 19, 12, 0);
	//AddSprite("Asset/보스.bmp", 155, 439, 24, 12, 0);
	//AddSprite("Asset/보스.bmp", 183, 439, 27, 12, 0);
	//AddSprite("Asset/보스.bmp", 214, 439, 29, 12, 0);



	//피해입은 프로펠러 애니메이션 - 1번//
	
	//AddSprite("Asset/보스.bmp",   7, 457, 32, 47, 1);
	//AddSprite("Asset/보스.bmp",  42, 457, 31, 47, 1);
	//AddSprite("Asset/보스.bmp",  76, 457, 29, 47, 1);
	//AddSprite("Asset/보스.bmp", 108, 457, 31, 47, 1);

	AddSprite("Asset/보스.bmp", 142, 457, 31, 47, 1);
	AddSprite("Asset/보스.bmp", 176, 457, 31, 47, 1);
	AddSprite("Asset/보스.bmp", 210, 457, 31, 47, 1);
	AddSprite("Asset/보스.bmp", 244, 457, 32, 47, 1);
	
	

	Play(0); //0번 애니메이션부터 시작
	Speed(3);
}
void Bossprop::Update()
{

}