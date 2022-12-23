#include "yaFlower4.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaPlayer.h"
#include "yaApplication.h"
#include "yaSkillJelly4.h"
#include "yaObject.h"

namespace ya
{
	Flower4::Flower4(Vector2 pos)
		:mSpeed(-300.0f)
	{

		mAnimator = new Animator();

		//std::filesystem::path clear();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\SkillData\\Flower4\\Wait"
			, L"Wait4", Vector2(0, 0), 0.25f);

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\SkillData\\Flower4\\Bloom"
			, L"Bloom4", Vector2(0, 0), 0.15f);

		mAnimator->Play(L"Wait4", false);
		SetPos(pos);
		AddComponent(mAnimator);
		
		Collider* col = new Collider();
		col->SetPos(pos);
		col->SetScale(Vector2(400.0f, 1100.0f));
		AddComponent(col);


	}

	Flower4::Flower4()
		:mSpeed(-300.0f)
	{

		mAnimator = new Animator();

		//std::filesystem::path clear();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\SkillData\\Flower4\\Wait"
			, L"Wait4", Vector2(0, 0), 0.25f);

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\SkillData\\Flower4\\Bloom"
			, L"Bloom4", Vector2(0, 0), 0.15f);

		mAnimator->Play(L"Wait4", false);

		AddComponent(mAnimator);

		Collider* col = new Collider();
		col->SetScale(Vector2(400.0f, 1100.0f));
		AddComponent(col);


	}
	Flower4::~Flower4()
	{
	}
	void Flower4::Tick()
	{
		GameObject::Tick();
		Translate(mSpeed);


	}
	void Flower4::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Flower4::OnCollisionEnter(Collider* other)
	{
		mAnimator->Play(L"Bloom4", false);

		Vector2 Pos = GetPos();
		SkillJelly4* skilljelly4 = ya::object::Instantiate<SkillJelly4>(eColliderLayer::Jelly);
		skilljelly4->SetPos(Vector2((Pos.x - 100.0f), (Pos.y - 200.0f)));

		SkillJelly4* skilljelly41 = ya::object::Instantiate<SkillJelly4>(eColliderLayer::Jelly);
		skilljelly41->SetPos(Vector2((Pos.x + 100.0f), (Pos.y - 200.0f)));
	}

}
