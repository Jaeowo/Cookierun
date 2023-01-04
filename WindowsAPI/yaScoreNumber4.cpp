#include "yaScoreNumber4.h"
#include "yaImage.h"
#include "yaResources.h"
#include "yaPlayer.h"
#include "yaApplication.h"
#include "yaGameObjectManager.h"
#include "yaAnimator.h"

namespace ya
{
	ScoreNumber4::ScoreNumber4(eUIType type)
		: UiBase(type)
		, mScore(0)

	{


		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Score4", L"..\\Resources\\Image\\UI\\Score.bmp");
		}

		mAnimator = new Animator();


		mAnimator->CreateAnimation(L"04", mImage
			, Vector2(0.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"14", mImage
			, Vector2(35.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"24", mImage
			, Vector2(70.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"34", mImage
			, Vector2(105.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"44", mImage
			, Vector2(140.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"54", mImage
			, Vector2(175.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"64", mImage
			, Vector2(210.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"74", mImage
			, Vector2(245.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"84", mImage
			, Vector2(280.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);

		mAnimator->CreateAnimation(L"94", mImage
			, Vector2(315.0f, 0.0f), Vector2(35.0f, 53.0f)
			, Vector2(0.0f, 0.0f), 1, 0.1f);





	}
	ScoreNumber4::~ScoreNumber4()
	{
	}
	void ScoreNumber4::OnInit()
	{
	}
	void ScoreNumber4::OnActive()
	{
	}
	void ScoreNumber4::OnInActive()
	{
	}
	void ScoreNumber4::OnTick()
	{

	}
	void ScoreNumber4::OnRender(HDC hdc)
	{
		Player* playerObj = dynamic_cast<Player*>(mTarget);
		mScore = playerObj->GetScore();
		mScore = mScore % 10000;

		if (mScore < 1000)
		{
			mAnimator->Play(L"04", true);
		}
		else if (1000 <= mScore <= 1999)
		{
			mAnimator->Play(L"14", true);
		}
		else if (2000 <= mScore <= 2999)
		{
			mAnimator->Play(L"24", true);
		}
		else if (3000 <= mScore <= 3999)
		{
			mAnimator->Play(L"34", true);
		}
		else if (4000 <= mScore <= 4999)
		{
			mAnimator->Play(L"44", true);
		}
		else if (5000 <= mScore <= 5999)
		{
			mAnimator->Play(L"54", true);
		}
		else if (6000 <= mScore <= 6999)
		{
			mAnimator->Play(L"64", true);
		}
		else if (7000 <= mScore <= 7999)
		{
			mAnimator->Play(L"74", true);
		}
		else if (8000 <= mScore <= 8999)
		{
			mAnimator->Play(L"84", true);
		}
		else if (9000 <= mScore <= 9999)
		{
			mAnimator->Play(L"94", true);
		}

		if (mImage == nullptr)
			return;

		if (mTarget == nullptr)
			return;

	}
	void ScoreNumber4::OnClear()
	{
	}
}

