#pragma once
class Bossprop : public Animation
{
private:
	float hp;
public:
	Bossprop(float px, float py);
	~Bossprop();

	void Start();
	void Update();

	void Explosion();

	void OnTriggerStay2D(GameObject * other);


};

