#include "yaFlower2.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaPlayer.h"
#include "yaApplication.h"
#include "yaSkillJelly2.h"
#include "yaObject.h"

namespace ya
{
	Flower2::Flower2(Vector2 pos)
		:mSpeed(-300.0f)
	{

		mAnimator = new Animator();

		//std::filesystem::path clear();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\SkillData\\Flower2\\Wait"
			, L"Wait2", Vector2(0, 0), 0.25f);

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\SkillData\\Flower2\\Bloom"
			, L"Bloom2", Vector2(0, 0), 0.15f);

		mAnimator->Play(L"Wait2", false);
		SetPos(pos);
		AddComponent(mAnimator);

		Collider* col = new Collider();
		col->SetPos(pos);
		col->SetScale(Vector2(400.0f, 1100.0f));
		AddComponent(col);


	}

	Flower2::Flower2()
		:mSpeed(-300.0f)
	{
	
		mAnimator = new Animator();

		//std::filesystem::path clear();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\SkillData\\Flower2\\Wait"
			, L"Wait2", Vector2(0, 0), 0.25f);

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\SkillData\\Flower2\\Bloom"
			, L"Bloom2", Vector2(0, 0), 0.15f);

		mAnimator->Play(L"Wait2", false);

		AddComponent(mAnimator);

		Collider* col = new Collider();
		col->SetScale(Vector2(400.0f, 1100.0f));
		AddComponent(col);


	}
	Flower2::~Flower2()
	{
	}
	void Flower2::Tick()
	{
		GameObject::Tick();
		Translate(mSpeed);


	}
	void Flower2::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Flower2::OnCollisionEnter(Collider* other)
	{
		mAnimator->Play(L"Bloom2", false);

		Vector2 Pos = GetPos();
		SkillJelly2* skilljelly2 = ya::object::Instantiate<SkillJelly2>(eColliderLayer::Jelly);
		skilljelly2->SetPos(Vector2((Pos.x - 100.0f), (Pos.y - 200.0f)));

		SkillJelly2* skilljelly21 = ya::object::Instantiate<SkillJelly2>(eColliderLayer::Jelly);
		skilljelly21->SetPos(Vector2((Pos.x + 100.0f), (Pos.y - 200.0f)));
	}

}
