#include "yaScoreNumber.h"
#include "yaImage.h"
#include "yaResources.h"
#include "yaPlayer.h"
#include "yaApplication.h"
#include "yaGameObjectManager.h"

namespace ya
{
	ScoreNumber::ScoreNumber(eUIType type)
		: UiBase(type)
		, mScoreX(45)
		, mScoreStartX(0)
	{
		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Score", L"..\\Resources\\Image\\UI\\Score.bmp");
		}

		/*	eSceneType stype = ya::Application::GetInstance().GetPlaySceneType();
			if (stype != eSceneType::Play)
			{
				return;
			}*/
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
	}
	void ScoreNumber::OnRender(HDC hdc)
	{
		//GameObjectManager::GetPlayer()->GetScore();
		//GameObjectManager::GetPlayer()->GestStringScore();

		Player* playerObj = dynamic_cast<Player*>(mTarget);
		playerObj->ScoreToString();
		std::string num = playerObj->GestStringScore();
		//mstr
		
		if (mImage == nullptr)
			return;

		if (mTarget == nullptr)
			return;

		while (true)
		{
			mstr = num.find("0");
			/*if(num.find("0") != std::string::mstr)*/
			break;

		}

	}
	void ScoreNumber::OnClear()
	{
	}
}
