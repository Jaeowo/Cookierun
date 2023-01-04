#include "yaScoreNumber2.h"
#include "yaImage.h"
#include "yaResources.h"
#include "yaPlayer.h"
#include "yaApplication.h"
#include "yaGameObjectManager.h"
#include "yaAnimator.h"

namespace ya
{
	ScoreNumber2::ScoreNumber2(eUIType type)
		: UiBase(type)
		, mScore(0)

	{


		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Score2", L"..\\Resources\\Image\\UI\\Score.bmp");
		}

		mAnimator = new Animator();


		mAnimator->CreateAnimation(L"02", mImage
			, Vector2(0.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"12", mImage
			, Vector2(35.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"22", mImage
			, Vector2(70.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"32", mImage
			, Vector2(105.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"42", mImage
			, Vector2(140.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"52", mImage
			, Vector2(175.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"62", mImage
			, Vector2(210.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"72", mImage
			, Vector2(245.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"82", mImage
			, Vector2(280.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"92", mImage
			, Vector2(315.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);





	}
	ScoreNumber2::~ScoreNumber2()
	{
	}
	void ScoreNumber2::OnInit()
	{
	}
	void ScoreNumber2::OnActive()
	{
	}
	void ScoreNumber2::OnInActive()
	{
	}
	void ScoreNumber2::OnTick()
	{
		Player* playerObj = dynamic_cast<Player*>(mTarget);
		mScore = playerObj->GetScore();
		mScore = mScore % 100;

		if (mScore < 10)
		{
			mAnimator->Play(L"02", true);
		}
		else if (10 <= mScore <= 19)
		{
			mAnimator->Play(L"12", true);
		}
		else if (20 <= mScore <= 29)
		{
			mAnimator->Play(L"22", true);
		}
		else if (30 <= mScore <= 39)
		{
			mAnimator->Play(L"32", true);
		}
		else if (40 <= mScore <= 49)
		{
			mAnimator->Play(L"42", true);
		}
		else if (50 <= mScore <= 59)
		{
			mAnimator->Play(L"52", true);
		}
		else if (60 <= mScore <= 69)
		{
			mAnimator->Play(L"62", true);
		}
		else if (70 <= mScore <= 79)
		{
			mAnimator->Play(L"72", true);
		}
		else if (80 <= mScore <= 89)
		{
			mAnimator->Play(L"82", true);
		}
		else if (90 <= mScore <= 99)
		{
			mAnimator->Play(L"92", true);
		}

		if (mImage == nullptr)
			return;

		if (mTarget == nullptr)
			return;
	}
	void ScoreNumber2::OnRender(HDC hdc)
	{
		

	}
	void ScoreNumber2::OnClear()
	{
	}
}
