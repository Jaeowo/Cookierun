#include "yaScoreNumber5.h"
#include "yaImage.h"
#include "yaResources.h"
#include "yaPlayer.h"
#include "yaApplication.h"
#include "yaGameObjectManager.h"
#include "yaAnimator.h"

namespace ya
{
	ScoreNumber5::ScoreNumber5(eUIType type)
		: UiBase(type)
		, mScore(0)

	{


		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Score5", L"..\\Resources\\Image\\UI\\Score.bmp");
		}

		mAnimator = new Animator();


		mAnimator->CreateAnimation(L"05", mImage
			, Vector2(0.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"15", mImage
			, Vector2(35.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"25", mImage
			, Vector2(70.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"35", mImage
			, Vector2(105.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"45", mImage
			, Vector2(140.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"55", mImage
			, Vector2(175.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"65", mImage
			, Vector2(210.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"75", mImage
			, Vector2(245.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"85", mImage
			, Vector2(280.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"95", mImage
			, Vector2(315.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);





	}
	ScoreNumber5::~ScoreNumber5()
	{
	}
	void ScoreNumber5::OnInit()
	{
	}
	void ScoreNumber5::OnActive()
	{
	}
	void ScoreNumber5::OnInActive()
	{
	}
	void ScoreNumber5::OnTick()
	{

	}
	void ScoreNumber5::OnRender(HDC hdc)
	{
		Player* playerObj = dynamic_cast<Player*>(mTarget);
		mScore = playerObj->GetScore();
		mScore = mScore % 100000;

		if (mScore < 10000)
		{
			mAnimator->Play(L"05", true);
		}
		else if (10000 <= mScore <= 19999)
		{
			mAnimator->Play(L"15", true);
		}
		else if (20000 <= mScore <= 29999)
		{
			mAnimator->Play(L"25", true);
		}
		else if (30000 <= mScore <= 39999)
		{
			mAnimator->Play(L"35", true);
		}
		else if (40000 <= mScore <= 49999)
		{
			mAnimator->Play(L"45", true);
		}
		else if (50000 <= mScore <= 59999)
		{
			mAnimator->Play(L"55", true);
		}
		else if (60000 <= mScore <= 69999)
		{
			mAnimator->Play(L"65", true);
		}
		else if (70000 <= mScore <= 79999)
		{
			mAnimator->Play(L"75", true);
		}
		else if (80000 <= mScore <= 89999)
		{
			mAnimator->Play(L"85", true);
		}
		else if (90000 <= mScore <= 99999)
		{
			mAnimator->Play(L"95", true);
		}

		if (mImage == nullptr)
			return;

		if (mTarget == nullptr)
			return;

	}
	void ScoreNumber5::OnClear()
	{
	}
}
