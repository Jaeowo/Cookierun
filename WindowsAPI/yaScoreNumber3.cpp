#include "yaScoreNumber3.h"
#include "yaImage.h"
#include "yaResources.h"
#include "yaPlayer.h"
#include "yaApplication.h"
#include "yaGameObjectManager.h"
#include "yaAnimator.h"

namespace ya
{
	ScoreNumber3::ScoreNumber3(eUIType type)
		: UiBase(type)
		, mScore(0)

	{


		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Score3", L"..\\Resources\\Image\\UI\\Score.bmp");
		}

		mAnimator = new Animator();


		mAnimator->CreateAnimation(L"03", mImage
			, Vector2(0.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"13", mImage
			, Vector2(35.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"23", mImage
			, Vector2(70.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"33", mImage
			, Vector2(105.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"43", mImage
			, Vector2(140.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"53", mImage
			, Vector2(175.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"63", mImage
			, Vector2(210.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"73", mImage
			, Vector2(245.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"83", mImage
			, Vector2(280.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"93", mImage
			, Vector2(315.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);





	}
	ScoreNumber3::~ScoreNumber3()
	{
	}
	void ScoreNumber3::OnInit()
	{
	}
	void ScoreNumber3::OnActive()
	{
	}
	void ScoreNumber3::OnInActive()
	{
	}
	void ScoreNumber3::OnTick()
	{

	}
	void ScoreNumber3::OnRender(HDC hdc)
	{
		Player* playerObj = dynamic_cast<Player*>(mTarget);
		mScore = playerObj->GetScore();
		mScore = mScore % 1000;

		if (mScore < 100)
		{
			mAnimator->Play(L"03", true);
		}
		else if (100 <= mScore <= 199)
		{
			mAnimator->Play(L"13", true);
		}
		else if (200 <= mScore <= 299)
		{
			mAnimator->Play(L"23", true);
		}
		else if (300 <= mScore <= 399)
		{
			mAnimator->Play(L"33", true);
		}
		else if (400 <= mScore <= 499)
		{
			mAnimator->Play(L"43", true);
		}
		else if (500 <= mScore <= 599)
		{
			mAnimator->Play(L"53", true);
		}
		else if (600 <= mScore <= 699)
		{
			mAnimator->Play(L"63", true);
		}
		else if (700 <= mScore <= 799)
		{
			mAnimator->Play(L"73", true);
		}
		else if (800 <= mScore <= 899)
		{
			mAnimator->Play(L"83", true);
		}
		else if (900 <= mScore <= 999)
		{
			mAnimator->Play(L"93", true);
		}

		if (mImage == nullptr)
			return;

		if (mTarget == nullptr)
			return;

	}
	void ScoreNumber3::OnClear()
	{
	}
}

