#include "ShootingGame.h"


Bossprop::Bossprop(float px, float py) : Animation("�����ڽ�", "�����緯", true, px, py)
{
	this->hp = 100;
}
Bossprop::~Bossprop()
{

}

void Bossprop::Start()
{
	//���ؾ��� �����緯 �ִϸ��̼� - 0��//
	AddSprite("Asset/�����緯1.bmp",   5, 5, 32, 12 , 0, 16, 6);
	AddSprite("Asset/�����緯1.bmp",  39, 5, 32, 12 , 0, 16, 6);
	AddSprite("Asset/�����緯1.bmp",  72, 5, 30, 12 , 0, 15, 6);
	AddSprite("Asset/�����緯1.bmp", 104, 5, 24, 12 , 0, 12, 6);

	AddSprite("Asset/�����緯1.bmp", 131, 5, 20, 12 , 0, 10, 6);
	AddSprite("Asset/�����緯1.bmp", 153, 5, 26, 12 , 0, 13, 6);
	AddSprite("Asset/�����緯1.bmp", 182, 5, 28, 12 , 0, 14, 6);
	AddSprite("Asset/�����緯1.bmp", 213, 5, 30, 12 , 0, 15, 6);



	//�������� �����緯 �ִϸ��̼� - 1��//
	
	AddSprite("Asset/�����緯2.bmp",   7, 4, 32, 48, 1, 16, 6);
	AddSprite("Asset/�����緯2.bmp",  42, 4, 31, 48, 1, 15, 6);
	AddSprite("Asset/�����緯2.bmp",  76, 4, 29, 48, 1, 15, 6);
	AddSprite("Asset/�����緯2.bmp", 108, 4, 31, 48, 1, 18, 6);
	AddSprite("Asset/�����緯2.bmp", 142, 4, 31, 48, 1, 17, 6);
	AddSprite("Asset/�����緯2.bmp", 176, 4, 32, 48, 1, 16, 6);
	AddSprite("Asset/�����緯2.bmp", 210, 4, 31, 48, 1, 16, 6);
	AddSprite("Asset/�����緯2.bmp", 244, 4, 32, 48, 1, 16, 6);
	
	

	Play(0); //0�� �ִϸ��̼Ǻ��� ����
	Speed(3);

	//�浹ü �߰�

	AddBoxCollider2D(-16, -5, 32, 12);
}
void Bossprop::Update()
{
	//�θ� ������ Ȯ���ϱ�
	string tag = parent->GetTag();
}
void Bossprop::Explosion()
{
	float px = GetPx();
	float py = GetPy();

	//����ȿ�� �̵� ������ ���ϱ�//

	float offx = (32 - 64) / 2;
	float offy = (12 - 64) / 2;


	Instantiate(new BossChildExp(px + offx, py + offy));

	Destroy(this);

	//�����緯�� �θ�ü�� ������ �����緯�� ���ŵǾ����� �˷��ֱ�

	//parent->On ����ȯ�� �������

	((Boss*)parent)->OnChildDestroy(this->GetName());

	//�θ� ��ü�� �������� �ڽ��� ���ŵǾ����� �˸�//
	((Boss*)parent)->OnChildDestroy(this->GetName());
	
}

void Bossprop::OnTriggerStay2D(GameObject* other)
{
	string tag = other->GetTag();

	if (tag == "������")
	{
		//ü�¿� ���� �����ϱ�
		hp -= 10;

		if (0 < hp && hp <= 50)
		{
			Play(1); // ���⳪�� �ִϸ��̼�
		}
		else if (hp <= 0)
		{
			Explosion();
		}

	}
	else if (tag == "��ź����")
	{
		Explosion();
	}

}