#include "yaScoreNumber6.h"
#include "yaImage.h"
#include "yaResources.h"
#include "yaPlayer.h"
#include "yaApplication.h"
#include "yaGameObjectManager.h"
#include "yaAnimator.h"

namespace ya
{
	ScoreNumber6::ScoreNumber6(eUIType type)
		: UiBase(type)
		, mScore(0)

	{


		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Score6", L"..\\Resources\\Image\\UI\\Score.bmp");
		}

		mAnimator = new Animator();


		mAnimator->CreateAnimation(L"06", mImage
			, Vector2(0.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"16", mImage
			, Vector2(35.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"26", mImage
			, Vector2(70.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"36", mImage
			, Vector2(105.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"46", mImage
			, Vector2(140.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"56", mImage
			, Vector2(175.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"66", mImage
			, Vector2(210.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"76", mImage
			, Vector2(245.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"86", mImage
			, Vector2(280.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"96", mImage
			, Vector2(315.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);





	}
	ScoreNumber6::~ScoreNumber6()
	{
	}
	void ScoreNumber6::OnInit()
	{
	}
	void ScoreNumber6::OnActive()
	{
	}
	void ScoreNumber6::OnInActive()
	{
	}
	void ScoreNumber6::OnTick()
	{

	}
	void ScoreNumber6::OnRender(HDC hdc)
	{
		Player* playerObj = dynamic_cast<Player*>(mTarget);
		mScore = playerObj->GetScore();
		mScore = mScore % 1000000;

		if (mScore < 100000)
		{
			mAnimator->Play(L"06", true);
		}
		else if (100000 <= mScore <= 199999)
		{
			mAnimator->Play(L"16", true);
		}
		else if (200000 <= mScore <= 299999)
		{
			mAnimator->Play(L"26", true);
		}
		else if (300000 <= mScore <= 399999)
		{
			mAnimator->Play(L"36", true);
		}
		else if (400000 <= mScore <= 499999)
		{
			mAnimator->Play(L"46", true);
		}
		else if (500000 <= mScore <= 599999)
		{
			mAnimator->Play(L"56", true);
		}
		else if (600000 <= mScore <= 699999)
		{
			mAnimator->Play(L"66", true);
		}
		else if (700000 <= mScore <= 799999)
		{
			mAnimator->Play(L"76", true);
		}
		else if (800000 <= mScore <= 899999)
		{
			mAnimator->Play(L"86", true);
		}
		else if (900000 <= mScore <= 999999)
		{
			mAnimator->Play(L"96", true);
		}

		if (mImage == nullptr)
			return;

		if (mTarget == nullptr)
			return;

	}
	void ScoreNumber6::OnClear()
	{
	}
}
