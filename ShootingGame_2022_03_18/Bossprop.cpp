#include "ShootingGame.h"


Bossprop::Bossprop(float px, float py) : Animation("", "", true, px, py)
{

}
Bossprop::~Bossprop()
{

}

void Bossprop::Start()
{
	//���ؾ��� �����緯 �ִϸ��̼� - 0��//
	AddSprite("Asset/����.bmp",   6, 438, 32, 12, 0);
	AddSprite("Asset/����.bmp",  42, 438, 32, 12, 0);
	//AddSprite("Asset/����.bmp",  74, 439, 28, 12, 0);
	//AddSprite("Asset/����.bmp", 105, 439, 23, 12, 0);

	//AddSprite("Asset/����.bmp", 132, 439, 19, 12, 0);
	//AddSprite("Asset/����.bmp", 155, 439, 24, 12, 0);
	//AddSprite("Asset/����.bmp", 183, 439, 27, 12, 0);
	//AddSprite("Asset/����.bmp", 214, 439, 29, 12, 0);



	//�������� �����緯 �ִϸ��̼� - 1��//
	
	//AddSprite("Asset/����.bmp",   7, 457, 32, 47, 1);
	//AddSprite("Asset/����.bmp",  42, 457, 31, 47, 1);
	//AddSprite("Asset/����.bmp",  76, 457, 29, 47, 1);
	//AddSprite("Asset/����.bmp", 108, 457, 31, 47, 1);

	AddSprite("Asset/����.bmp", 142, 457, 31, 47, 1);
	AddSprite("Asset/����.bmp", 176, 457, 31, 47, 1);
	AddSprite("Asset/����.bmp", 210, 457, 31, 47, 1);
	AddSprite("Asset/����.bmp", 244, 457, 32, 47, 1);
	
	

	Play(0); //0�� �ִϸ��̼Ǻ��� ����
	Speed(3);
}
void Bossprop::Update()
{

}