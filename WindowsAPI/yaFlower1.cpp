#include "yaFlower1.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaPlayer.h"
#include "yaApplication.h"
#include "yaSkillJelly1.h"
#include "yaObject.h"
#include "yaSound.h"

namespace ya
{
	Flower1::Flower1(Vector2 pos)
		:mSpeed(-300.0f)
	{

		mAnimator = new Animator();

		//std::filesystem::path clear();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\SkillData\\Flower1\\Wait"
			, L"Wait", Vector2(0, 0), 0.25f);

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\SkillData\\Flower1\\Bloom"
			, L"Bloom", Vector2(0, 0), 0.15f);

		mAnimator->Play(L"Wait", false);

		AddComponent(mAnimator);
		SetPos(pos);
		Collider* col = new Collider();
		col->SetScale(Vector2(400.0f, 1100.0f));
		col->SetPos(pos);
		AddComponent(col);


	}

	Flower1::Flower1()
		:mSpeed(-300.0f)
	{
	
		mAnimator = new Animator();

		//std::filesystem::path clear();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\SkillData\\Flower1\\Wait"
			, L"Wait", Vector2(0, 0), 0.25f);

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\SkillData\\Flower1\\Bloom"
			, L"Bloom", Vector2(0, 0), 0.15f);

		mAnimator->Play(L"Wait", false);

		AddComponent(mAnimator);

		Collider* col = new Collider();
		col->SetScale(Vector2(400.0f, 1100.0f));
		AddComponent(col);


	}
	Flower1::~Flower1()
	{
	}
	void Flower1::Tick()
	{
		GameObject::Tick();
		Translate(mSpeed);


	}
	void Flower1::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Flower1::OnCollisionEnter(Collider* other)
	{
		mAnimator->Play(L"Bloom", false);
		
		Sound* sound = ya::object::Instantiate<Sound>(eColliderLayer::BGM);
		sound->Load(L"..\\Resources\\Sound\\jicho_smallflower_01.wav");
		sound->Play(false);

		Vector2 Pos = GetPos();
		SkillJelly1* skilljelly1 = ya::object::Instantiate<SkillJelly1>(eColliderLayer::Jelly);
		skilljelly1->SetPos(Vector2((Pos.x-100.0f),(Pos.y-200.0f)));

		SkillJelly1* skilljelly11 = ya::object::Instantiate<SkillJelly1>(eColliderLayer::Jelly);
		skilljelly11->SetPos(Vector2((Pos.x +100.0f ), (Pos.y - 200.0f)));
	}
	
}