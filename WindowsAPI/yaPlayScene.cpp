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
#include "yaUIManager.h"
#include "yaJellyToolScene.h"
#include "yaStage01.h"
#include "yaStage02.h"

namespace ya
{
	PlayScene::PlayScene()
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		//배경
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
	

		

		//mImage = Resources::Load<Image>(L"Jelly", L"..\\Resources\\Image\\Jelly\\NormalJelly.bmp");
		//캐릭터
		Player* player = ya::object::Instantiate<Player>(eColliderLayer::Player);

		//땅
		Ground* ground = ya::object::Instantiate<Ground>(eColliderLayer::Ground);
		ground->SetPos(Vector2(1000.0f, 750.0f));
		ground->SetColPos(Vector2(8000.0f, 100.0f));
		
		//펫
		Squirrel* mSquirrel = ya::object::Instantiate<Squirrel>(eColliderLayer::Pet);

		//장애물
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

		//타일하나여서 툴 말고 그냥 출력되도록 변경... 
		GroundTile* groundtile = ya::object::Instantiate<GroundTile>(eColliderLayer::Tile);
		groundtile->SetPos(Vector2{ 0.0f,700.0f });
		groundtile->SetCount(15);

		//아이템
		//Biggest* biggest = ya::object::Instantiate<Biggest>(eColliderLayer::Jelly);
		//Run* run = ya::object::Instantiate<Run>(eColliderLayer::Jelly);
		//BigHp* bighp = ya::object::Instantiate<BigHp>(eColliderLayer::Jelly);
		//SmallHp* smallhp = ya::object::Instantiate<SmallHp>(eColliderLayer::Jelly);
		//ChangeBear* changebear = ya::object::Instantiate<ChangeBear>(eColliderLayer::Jelly);
		//ChangeCoin* changecoin = ya::object::Instantiate<ChangeCoin>(eColliderLayer::Jelly);
		//GoBonusTime* gobonustime = ya::object::Instantiate<GoBonusTime>(eColliderLayer::Jelly);
		//Magnet* magnet = ya::object::Instantiate<Magnet>(eColliderLayer::Jelly);
		
		//젤리
		//Jelly* jelly = ya::object::Instantiate<Jelly>(eColliderLayer::Jelly);
		//PinkBear* pinkbear = ya::object::Instantiate<PinkBear>(eColliderLayer::Jelly);
		//IceBear* icebear = ya::object::Instantiate<IceBear>(eColliderLayer::Jelly);
		//YellowBear* yellowbear = ya::object::Instantiate<YellowBear>(eColliderLayer::Jelly);
		//RainbowBear* rainbowbear = ya::object::Instantiate<RainbowBear>(eColliderLayer::Jelly);
		//SilverCoin* silvercoin = ya::object::Instantiate<SilverCoin>(eColliderLayer::Jelly);
		//GoldCoin* goldcoin = ya::object::Instantiate<GoldCoin>(eColliderLayer::Jelly);
		//BigBear* bigbear = ya::object::Instantiate<BigBear>(eColliderLayer::Jelly);

		//UI
		UIManager::Push(eUIType::HP);

		HpBar* hpbar = UIManager::GetUiInstant<HpBar>(eUIType::HP);
		hpbar->SetTarget(player);



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
		
		if (KEY_DOWN(eKeyCode::N))
		{
			SceneManager::ChangeScene(eSceneType::Skill);
		}

	}

	void PlayScene::Render(HDC hdc)
	{

		Scene::Render(hdc);
		wchar_t szFloat[50] = {};
		swprintf_s(szFloat, 50, L"Play Scene");
		int strLen = wcsnlen_s(szFloat, 50);
		TextOut(hdc, 10, 30, szFloat, strLen);

	}

	void PlayScene::Enter()
	{
		CollisionManager::SetLayer(eColliderLayer::Obstruction, eColliderLayer::Player, true);
		CollisionManager::SetLayer(eColliderLayer::Ground, eColliderLayer::Player, true);
		CollisionManager::SetLayer(eColliderLayer::Jelly, eColliderLayer::Player, true);



	}

	void PlayScene::Exit()
	{

	}
}
