#include "ShootingGame.h"


BossChildSprite::BossChildSprite(string tag, string name, bool active, float px, float py) 
			    : Sprite(tag,name,active,px,py)
{
	this->hp     = 100;
	this->damage = 10;
}
BossChildSprite::~BossChildSprite()
{

}


void BossChildSprite::Update()
{

}

void BossChildSprite::Explosion()
{
	float px = GetPx();
	float py = GetPy();

	//����ȿ�� �̵� ������ ���ϱ�//

	int width, height; //��������Ʈ �̹��� ũ��

	ImageRect(width, height);

	float offx = (width  - 64) / 2;
	float offy = (height - 64) / 2;


	Instantiate(new BossChildExp(px + offx, py + offy));

	//���� ����
	Destroy(this);

	//�θ� ��ü�� �������� �ڽ��� ���ŵǾ����� �˸�//
	((Boss*)parent)->OnChildDestroy(this->GetName());
}

void BossChildSprite::OnTriggerStay2D(GameObject* other)
{
	string tag = other->GetTag();

	if (tag == "������")
	{
		//ü�� ���̱�
		hp = hp - damage;

		if (hp <= 0)
		{
			//���� ����
			Explosion();
		}

	}
	else if (tag == "��ź����")
	{
		Explosion();
	}
}
void BossChildSprite::SetDamage(float damage)
{
	this->damage = damage;
}