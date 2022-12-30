#include "yaRope2Trigger.h"
#include "yaCollider.h"
#include "yaRope02.h"
#include "yaAnimator.h"

namespace ya
{
	Rope2Trigger::Rope2Trigger(Vector2 pos)
		: mSpeed(-300.0f)
	{
		Collider* col = new Collider();
		col->SetPos(pos);
		col->SetScale(Vector2(900.0f, 1000.0f));
		//col->SetOffset(Vector2(50.0f, 55.0f));
		AddComponent(col);
	}
	Rope2Trigger::Rope2Trigger()
	{
	}
	Rope2Trigger::~Rope2Trigger()
	{
	}
	void Rope2Trigger::Tick()
	{
		Translate(mSpeed);
		GameObject::Tick();
	}
	void Rope2Trigger::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Rope2Trigger::OnCollisionEnter(Collider* other)
	{
		Rope02* rope2obj = dynamic_cast<Rope02*>(mTarget);
		rope2obj->GetComponent<Animator>()->Play(L"Rope02Active", false);
	}
}