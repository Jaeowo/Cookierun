#include "yaBigBear.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaPlayer.h"

namespace ya
{
	BigBear::BigBear()
		:mSpeed(-300.0f)
	{
		SetPos({ 1400.0f, 405.0f });
		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\Image\\Jelly\\BigBear"
			, L"BigBear", Vector2(0, 0), 0.25f);

		mAnimator->Play(L"BigBear", true);

		AddComponent(mAnimator);

		Collider* col = new Collider();
		//col->SetScale(Vector2(70.0f, 70.0f));
		AddComponent(col);

	}
	BigBear::~BigBear()
	{
	}
	void BigBear::Tick()
	{

		Translate(mSpeed);
		GameObject::Tick();
	}
	void BigBear::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void BigBear::OnCollisionEnter(Collider* other)
	{
		Player* playerObj = dynamic_cast<Player*>(other->GetOwner());
		int Score = playerObj->GetScore();
		Score += 7000;
		playerObj->SetScore(Score);

		this->Death();
	}
}