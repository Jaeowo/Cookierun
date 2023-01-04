#include "yaPlayScene.h"
#include "yaPlayer.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaBgImageObject.h"
#include "yaObject.h"
#include "yaToolScene.h"
#include "yaGround.h"
#include "yaCollisionManager.h"
#include "yaSquirrel.h"
#include "yaTime.h"
#include "yaGroundTile.h"
#include "yaJelly.h"
#include "yaPinkBear.h"
#include "yaYellowBear.h"
#include "yaIceBear.h"
#include "yaBigBear.h"
#include "yaRope01.h"
#include "yaRope02.h"
#include "yaRun.h"
#include "yaSmallHp.h"
#include "yaBigHp.h"
#include "yaChangeBear.h"
#include "yaChangeCoin.h"
#include "yaMagnet.h"
#include "yaGoBonusTime.h"
#include "yaRainbowBear.h"
#include "yaSilverCoin.h"
#include "yaGoldCoin.h"
#include "yaBigBear.h"
#include "yaHpBar.h"
#include "yaHUD.h"
#include "yaUIManager.h"
#include "yaJellyToolScene.h"
#include "yaStage01.h"
#include "yaStage02.h"
#include "yaGameObjectManager.h"
#include "yaScoreNumber.h"
#include "yaScoreNumber2.h"
#include "yaScoreNumber3.h"
#include "yaScoreNumber4.h"
#include "yaScoreNumber5.h"
#include "yaScoreNumber6.h"
#include "yaScoreNumber7.h"


#include "yaCamera.h"
namespace ya
{
	PlayScene::PlayScene()
		:mCount(0.0f)
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{

		//���
		BgImageObject* Bg1 = new BgImageObject();
		Bg1->SetImage(L"Bg1", L"Bg1.bmp");
		Bg1->Initialize();
		AddGameObject(Bg1, eColliderLayer::BackGround);
		Bg1->SetSpeed(-2.5f);

		BgImageObject* Bg2 = new BgImageObject();
		Bg2->SetImage(L"Bg2", L"Bg3.bmp");
		Bg2->Initialize();
		AddGameObject(Bg2, eColliderLayer::BackGround);
		Bg2->SetSpeed(-9.0f);
	
		mPlayer = ya::object::Instantiate<Player>(eColliderLayer::Player);
		GameObjectManager::SetPlayer(mPlayer);
		//��
		Squirrel* mSquirrel = ya::object::Instantiate<Squirrel>(eColliderLayer::Pet);

		//��
	
		//��ֹ�
		//Fire01* fire01 = ya::object::Instantiate<Fire01>(eColliderLayer::Obstruction);
		//Fire02* fire02 = ya::object::Instantiate<Fire02>(eColliderLayer::Obstruction);
		//Down* down = ya::object::Instantiate<Down>(eColliderLayer::Obstruction);
		//Rolling* rolling = ya::object::Instantiate<Rolling>(eColliderLayer::Obstruction);
		//Rope01* rope01 = ya::object::Instantiate<Rope01>(eColliderLayer::Obstruction);
		//Rope02* rope02 = ya::object::Instantiate<Rope02>(eColliderLayer::Obstruction);
		
		Stage01* stage01 = new Stage01();
		stage01->ObstructionSetting();
		/*Stage02* stage02 = new Stage02();
		stage02->ObstructionSetting();*/

		

		//������
		//Biggest* biggest = ya::object::Instantiate<Biggest>(eColliderLayer::Jelly);
		//Run* run = ya::object::Instantiate<Run>(eColliderLayer::Jelly);
		//BigHp* bighp = ya::object::Instantiate<BigHp>(eColliderLayer::Jelly);
		//SmallHp* smallhp = ya::object::Instantiate<SmallHp>(eColliderLayer::Jelly);
		//ChangeBear* changebear = ya::object::Instantiate<ChangeBear>(eColliderLayer::Jelly);
		//ChangeCoin* changecoin = ya::object::Instantiate<ChangeCoin>(eColliderLayer::Jelly);
		//GoBonusTime* gobonustime = ya::object::Instantiate<GoBonusTime>(eColliderLayer::Jelly);
		//Magnet* magnet = ya::object::Instantiate<Magnet>(eColliderLayer::Jelly);
		
		//����
		//Jelly* jelly = ya::object::Instantiate<Jelly>(eColliderLayer::Jelly);
		//PinkBear* pinkbear = ya::object::Instantiate<PinkBear>(eColliderLayer::Jelly);
		//IceBear* icebear = ya::object::Instantiate<IceBear>(eColliderLayer::Jelly);
		//YellowBear* yellowbear = ya::object::Instantiate<YellowBear>(eColliderLayer::Jelly);
		//RainbowBear* rainbowbear = ya::object::Instantiate<RainbowBear>(eColliderLayer::Jelly);
		//SilverCoin* silvercoin = ya::object::Instantiate<SilverCoin>(eColliderLayer::Jelly);
		//GoldCoin* goldcoin = ya::object::Instantiate<GoldCoin>(eColliderLayer::Jelly);
		//BigBear* bigbear = ya::object::Instantiate<BigBear>(eColliderLayer::Jelly);

		//UI
	
		





		Load();
		Create();
	}

	void PlayScene::Load()
	{
		{
			wchar_t szFilePath[256] = {};/*= L"AStage01.jelly"*/;

			
			GetCurrentDirectoryW(256, szFilePath);
			lstrcatW(szFilePath,L"\\AStage01" );
			

			FILE* pFile = nullptr;
			_wfopen_s(&pFile, szFilePath, L"rb");
			if (pFile == nullptr)
				return;

			while (true)
			{
				JellyData data;
				if (fread(&data.type, sizeof(int), 1, pFile) == NULL)
					break;

				if (fread(&data.pos.x, sizeof(int), 1, pFile) == NULL)
					break;

				if (fread(&data.pos.y, sizeof(int), 1, pFile) == NULL)
					break;

				mJellyDatas.push_back(data);

			}
			fclose(pFile);
		}
	}

	void PlayScene::Create()
	{
		for (JellyData data : mJellyDatas)
		{

			GameObject* jelly = nullptr;
			switch ((eJellyType)data.type)
			{
			case ya::eJellyType::BigBear:
			{
				jelly
					= object::Instantiate<BigBear>(data.pos, eColliderLayer::Jelly);
				jelly->mJellyType = (UINT)eJellyType::BigBear;
			}
			break;
			case ya::eJellyType::IceBear:
			{
				jelly
					= object::Instantiate<IceBear>(data.pos, eColliderLayer::Jelly);
				jelly->mJellyType = (UINT)eJellyType::IceBear;
			}
			break;
			case ya::eJellyType::PinkBear:
			{
				jelly
					= object::Instantiate<PinkBear>(data.pos, eColliderLayer::Jelly);
				jelly->mJellyType = (UINT)eJellyType::PinkBear;
			}
			break;
			case ya::eJellyType::YellowBear:
			{
				jelly
					= object::Instantiate<YellowBear>(data.pos, eColliderLayer::Jelly);
				jelly->mJellyType = (UINT)eJellyType::YellowBear;
			}
			break;
			case ya::eJellyType::RainbowBear:
			{
				jelly
					= object::Instantiate<RainbowBear>(data.pos, eColliderLayer::Jelly);
				jelly->mJellyType = (UINT)eJellyType::RainbowBear;
			}
			break;
			case ya::eJellyType::GoldCoin:
			{
				jelly
					= object::Instantiate<GoldCoin>(eColliderLayer::Jelly);
				jelly->mJellyType = (UINT)eJellyType::GoldCoin;
			}
			break;
			case ya::eJellyType::SilverCoin:
			{
				jelly
					= object::Instantiate<SilverCoin>(eColliderLayer::Jelly);
				jelly->mJellyType = (UINT)eJellyType::SilverCoin;
			}
			break;
			case ya::eJellyType::Jelly:
			{
				jelly
					= object::Instantiate<Jelly>(data.pos, eColliderLayer::Jelly);
				jelly->mJellyType = (UINT)eJellyType::Jelly;
			}
			break;
			case ya::eJellyType::Max:
				break;
			default:
				break;
			}
			jelly->SetPos(data.pos);
			mJellies.push_back(jelly);
		}
	}

	void PlayScene::Tick()
	{
		Scene::Tick();
		
		
		if (GameObjectManager::GetPlayer()->GetState() == Player::eState::Skill2)
		{
			SceneManager::ChangeScene(eSceneType::Skill);
			
		}

		if (GameObjectManager::GetPlayer()->GetState() == Player::eState::Death)
		{
			mCount += Time::DeltaTime();
		
			if (mCount >= 3.0f)
			{
				SceneManager::ChangeScene(eSceneType::End);
			}
		
		}


		if (KEY_DOWN(eKeyCode::N))
		{
			SceneManager::ChangeScene(eSceneType::Skill);
		}

	}

	void PlayScene::Render(HDC hdc)
	{

		Scene::Render(hdc);
		
	}

	void PlayScene::Enter()
	{
		CollisionManager::SetLayer(eColliderLayer::Obstruction, eColliderLayer::Player, true);
		CollisionManager::SetLayer(eColliderLayer::Ground, eColliderLayer::Player, true);
		CollisionManager::SetLayer(eColliderLayer::Jelly, eColliderLayer::Player, true);
	
		UIManager::Push(eUIType::HP);
		UIManager::Push(eUIType::N1);
		UIManager::Push(eUIType::N2);
		UIManager::Push(eUIType::SCORE);
		
		HpBar* hpbar = UIManager::GetUiInstant<HpBar>(eUIType::HP);
		hpbar->SetTarget(mPlayer);

		ScoreNumber* scorenumber = UIManager::GetUiInstant<ScoreNumber>(eUIType::SCORE);
		scorenumber->SetTarget(mPlayer);

		/*ScoreNumber2* scorenumber2 = UIManager::GetUiInstant<ScoreNumber2>(eUIType::SCORE);
		scorenumber2->SetTarget(mPlayer);

		ScoreNumber3* scorenumber3 = UIManager::GetUiInstant<ScoreNumber3>(eUIType::SCORE);
		scorenumber3->SetTarget(mPlayer);

		ScoreNumber4* scorenumber4 = UIManager::GetUiInstant<ScoreNumber4>(eUIType::SCORE);
		scorenumber4->SetTarget(mPlayer);

		ScoreNumber5* scorenumber5 = UIManager::GetUiInstant<ScoreNumber5>(eUIType::SCORE);
		scorenumber5->SetTarget(mPlayer);

		ScoreNumber6* scorenumber6 = UIManager::GetUiInstant<ScoreNumber6>(eUIType::SCORE);
		scorenumber6->SetTarget(mPlayer);

		ScoreNumber7* scorenumber7 = UIManager::GetUiInstant<ScoreNumber7>(eUIType::SCORE);
		scorenumber7->SetTarget(mPlayer);*/
	}

	void PlayScene::Exit()
	{
		//UIManager::Pop(eUIType::HP);
		UIManager::Pop(eUIType::HP);
		UIManager::Pop(eUIType::N1);
		UIManager::Pop(eUIType::N2);
		UIManager::Pop(eUIType::SCORE);

		Camera::SetCameraEffect(eCameraEffect::FadeOut);
	}
}
