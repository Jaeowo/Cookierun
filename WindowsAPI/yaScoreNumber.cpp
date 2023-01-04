#include "yaScoreNumber.h"
#include "yaImage.h"
#include "yaResources.h"
#include "yaPlayer.h"
#include "yaApplication.h"
#include "yaGameObjectManager.h"
#include "yaAnimator.h"


namespace ya
{
	ScoreNumber::ScoreNumber(eUIType type)
		: UiBase(type)
		, mScore (0)

	{
	

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Score", L"..\\Resources\\Image\\UI\\Score.bmp");
		}

		mAnimator = new Animator();

		//AddComponent(mAnimator);

		mAnimator->CreateAnimation(L"0", mImage
			, Vector2(0.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"1", mImage
			, Vector2(35.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"2", mImage
			, Vector2(70.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"3", mImage
			, Vector2(105.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"4", mImage
			, Vector2(140.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"5", mImage
			, Vector2(175.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"6", mImage
			, Vector2(210.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"7", mImage
			, Vector2(245.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"8", mImage
			, Vector2(280.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"9", mImage
			, Vector2(315.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->Play(L"0", true);
	


	}
	ScoreNumber::~ScoreNumber()
	{
	}
	void ScoreNumber::OnInit()
	{
	

	}
	void ScoreNumber::OnActive()
	{
	}
	void ScoreNumber::OnInActive()
	{
	}
	void ScoreNumber::OnTick()
	{
		Player* playerObj = dynamic_cast<Player*>(mTarget);
		mScore = playerObj->GetScore();

		if (mImage == nullptr)
			return;

		if (mTarget == nullptr)
			return;

		if (mScore % 10 == 0)
		{
			mAnimator->Play(L"0", true);
		}
		else if (mScore % 10 == 1)
		{
			mAnimator->Play(L"1", true);
		}
		else if (mScore % 10 == 2)
		{
			mAnimator->Play(L"2", true);
		}
		else if (mScore % 10 == 3)
		{
			mAnimator->Play(L"3", true);
		}
		else if (mScore % 10 == 4)
		{
			mAnimator->Play(L"4", true);
		}
		else if (mScore % 10 == 5)
		{
			mAnimator->Play(L"5", true);
		}
		else if (mScore % 10 == 6)
		{
			mAnimator->Play(L"6", true);
		}
		else if (mScore % 10 == 7)
		{
			mAnimator->Play(L"7", true);
		}
		else if (mScore % 10 == 8)
		{
			mAnimator->Play(L"8", true);
		}
		else if (mScore % 10 == 9)
		{
			mAnimator->Play(L"9", true);
		}

	}
	void ScoreNumber::OnRender(HDC hdc)
	{
		
		

	}
	void ScoreNumber::OnClear()
	{
	}
}
