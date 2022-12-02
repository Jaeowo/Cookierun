#include "yaJelly.h"

namespace ya
{
	Jelly::Jelly()
		:mSpeed(-300.0f)
	{
	}
	Jelly::~Jelly()
	{
	}
	void Jelly::Tick()
	{
	}
	void Jelly::Render(HDC hdc)
	{
	}
	void Jelly::OnCollisionEnter(Collider* other)
	{
		//점수추가
		this->Death();
	}

}