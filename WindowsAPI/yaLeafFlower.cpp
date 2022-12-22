#include "yaLeafFlower.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaPlayer.h"
#include "yaApplication.h"
#include "yaObject.h"
#include "yaSkillJelly1.h"
#include "yaSkillJelly2.h"
#include "yaSkillJelly3.h"
#include "yaSkillJelly4.h"

namespace ya
{
	
	LeafFlower::LeafFlower()
		:mSpeed(-300.0f)
		,mState(eState::Wait)
		,mCount(0)
	{

		mAnimator = new Animator();

		//std::filesystem::path clear();
		mAnimator->CreateAnimations(L"..\\Resources\\Image\\SkillData\\LeafFlower\\Wait"
			, L"WaitL", Vector2(0, 0), 0.25f);

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\SkillData\\LeafFlower\\Bloom"
			, L"BloomL", Vector2(0, 0), 0.15f);

		mAnimator->Play(L"WaitL", false);

		AddComponent(mAnimator);

		SetScale({ 0.5f, 0.5f });
	/*	Collider* col = new Collider();
		AddComponent(col);*/
		mCollider = new Collider();
		AddComponent(mCollider);
		mCollider->SetScale(Vector2(150.0f, 200.0f));

	}
	LeafFlower::~LeafFlower()
	{
	}
	void LeafFlower::Tick()
	{
		GameObject::Tick();
		Translate(mSpeed);
		mCollider->SetOffset(mColPos);

		switch (mState)
		{
		case ya::LeafFlower::eState::Wait:
		{
		}
		break;
		case ya::LeafFlower::eState::Bloom:
		{
			Bloom();
		}
		break;
		default:
			break;
		}

	}

	void LeafFlower::Bloom()
	{

		
		if (mCount == 0)
		{

			mAnimator->Play(L"BloomL", false);

			Vector2 Pos = GetPos();

			SkillJelly1* skilljelly1 = ya::object::Instantiate<SkillJelly1>(eColliderLayer::Jelly);
			skilljelly1->SetPos(Vector2((Pos.x-300.0f), (Pos.y-280.0f )));

			SkillJelly2* skilljelly2 = ya::object::Instantiate<SkillJelly2>(eColliderLayer::Jelly);
			skilljelly2->SetPos(Vector2((Pos.x - 280.0f), (Pos.y - 240.0f)));

			SkillJelly3* skilljelly3 = ya::object::Instantiate<SkillJelly3>(eColliderLayer::Jelly);
			skilljelly3->SetPos(Vector2((Pos.x - 290.0f), (Pos.y - 230.0f)));

			SkillJelly1* skilljelly11 = ya::object::Instantiate<SkillJelly1>(eColliderLayer::Jelly);
			skilljelly11->SetPos(Vector2((Pos.x - 285.0f), (Pos.y-210.0f)));

			SkillJelly3* skilljelly31 = ya::object::Instantiate<SkillJelly3>(eColliderLayer::Jelly);
			skilljelly31->SetPos(Vector2((Pos.x - 300.0f), (Pos.y - 170.0f)));


			SkillJelly4* skilljelly4 = ya::object::Instantiate<SkillJelly4>(eColliderLayer::Jelly);
			skilljelly4->SetPos(Vector2((Pos.x - 100.0f), (Pos.y - 280.0f)));

			SkillJelly2* skilljelly21 = ya::object::Instantiate<SkillJelly2>(eColliderLayer::Jelly);
			skilljelly21->SetPos(Vector2((Pos.x - 130.0f), (Pos.y - 240.0f)));

			SkillJelly3* skilljelly32 = ya::object::Instantiate<SkillJelly3>(eColliderLayer::Jelly);
			skilljelly32->SetPos(Vector2((Pos.x - 140.0f), (Pos.y - 230.0f)));

			SkillJelly1* skilljelly12 = ya::object::Instantiate<SkillJelly1>(eColliderLayer::Jelly);
			skilljelly12->SetPos(Vector2((Pos.x - 135.0f), (Pos.y - 210.0f)));

			SkillJelly3* skilljelly33 = ya::object::Instantiate<SkillJelly3>(eColliderLayer::Jelly);
			skilljelly33->SetPos(Vector2((Pos.x - 110.0f), (Pos.y - 170.0f)));

			mCount = 1;
		}
		else
		{
			return;
		}

	}

	void LeafFlower::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void LeafFlower::OnCollisionEnter(Collider* other)
	{
		mState = eState::Bloom;

	
	}

}

