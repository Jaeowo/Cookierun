#include "yaFlower3.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaPlayer.h"
#include "yaApplication.h"
#include "yaSkillJelly3.h"
#include "yaObject.h"

namespace ya
{
	Flower3::Flower3()
		:mSpeed(-300.0f)
	{

		mAnimator = new Animator();

		//std::filesystem::path clear();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\SkillData\\Flower3\\Wait"
			, L"Wait3", Vector2(0, 0), 0.25f);

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\SkillData\\Flower3\\Bloom"
			, L"Bloom3", Vector2(0, 0), 0.15f);

		mAnimator->Play(L"Wait3", false);

		AddComponent(mAnimator);

		Collider* col = new Collider();
		col->SetScale(Vector2(400.0f, 1100.0f));
		AddComponent(col);


	}
	Flower3::~Flower3()
	{
	}
	void Flower3::Tick()
	{
		GameObject::Tick();
		Translate(mSpeed);


	}
	void Flower3::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Flower3::OnCollisionEnter(Collider* other)
	{
		mAnimator->Play(L"Bloom3", false);

		Vector2 Pos = GetPos();
		SkillJelly3* skilljelly3 = ya::object::Instantiate<SkillJelly3>(eColliderLayer::Jelly);
		skilljelly3->SetPos(Vector2((Pos.x - 100.0f), (Pos.y - 200.0f)));

		SkillJelly3* skilljelly31 = ya::object::Instantiate<SkillJelly3>(eColliderLayer::Jelly);
		skilljelly31->SetPos(Vector2((Pos.x + 100.0f), (Pos.y - 200.0f)));
	}

}
