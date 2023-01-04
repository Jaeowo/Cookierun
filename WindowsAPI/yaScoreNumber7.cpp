#include "yaScoreNumber7.h"
#include "yaImage.h"
#include "yaResources.h"
#include "yaPlayer.h"
#include "yaApplication.h"
#include "yaGameObjectManager.h"
#include "yaAnimator.h"

namespace ya
{
	ScoreNumber7::ScoreNumber7(eUIType type)
		: UiBase(type)
		, mScore(0)

	{


		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Score7", L"..\\Resources\\Image\\UI\\Score.bmp");
		}

		mAnimator = new Animator();


		mAnimator->CreateAnimation(L"07", mImage
			, Vector2(0.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"17", mImage
			, Vector2(35.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"27", mImage
			, Vector2(70.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"37", mImage
			, Vector2(105.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"47", mImage
			, Vector2(140.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"57", mImage
			, Vector2(175.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"67", mImage
			, Vector2(210.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"77", mImage
			, Vector2(245.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"87", mImage
			, Vector2(280.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"97", mImage
			, Vector2(315.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);





	}
	ScoreNumber7::~ScoreNumber7()
	{
	}
	void ScoreNumber7::OnInit()
	{
	}
	void ScoreNumber7::OnActive()
	{
	}
	void ScoreNumber7::OnInActive()
	{
	}
	void ScoreNumber7::OnTick()
	{

	}
	void ScoreNumber7::OnRender(HDC hdc)
	{
		Player* playerObj = dynamic_cast<Player*>(mTarget);
		mScore = playerObj->GetScore();
		mScore = mScore % 10000000;

		if (mScore < 1000000)
		{
			mAnimator->Play(L"07", true);
		}
		else if (1000000 <= mScore <= 1999999)
		{
			mAnimator->Play(L"17", true);
		}
		else if (2000000 <= mScore <= 2999999)
		{
			mAnimator->Play(L"27", true);
		}
		else if (3000000 <= mScore <= 3999999)
		{
			mAnimator->Play(L"37", true);
		}
		else if (4000000 <= mScore <= 4999999)
		{
			mAnimator->Play(L"47", true);
		}
		else if (5000000 <= mScore <= 5999999)
		{
			mAnimator->Play(L"57", true);
		}
		else if (6000000 <= mScore <= 6999999)
		{
			mAnimator->Play(L"67", true);
		}
		else if (7000000 <= mScore <= 7999999)
		{
			mAnimator->Play(L"77", true);
		}
		else if (8000000 <= mScore <= 8999999)
		{
			mAnimator->Play(L"87", true);
		}
		else if (9000000 <= mScore <= 9999999)
		{
			mAnimator->Play(L"97", true);
		}

		if (mImage == nullptr)
			return;

		if (mTarget == nullptr)
			return;

	}
	void ScoreNumber7::OnClear()
	{
	}
}
