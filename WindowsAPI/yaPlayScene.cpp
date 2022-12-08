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
#include "yaFire01.h"
#include "yaFire02.h"
#include "yaDown.h"
#include "yaRolling.h"
#include "yaBiggest.h"
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
	
		//캐릭터
		Player* player = ya::object::Instantiate<Player>(eColliderLayer::Player);

		//땅
		Ground* ground = ya::object::Instantiate<Ground>(eColliderLayer::Ground);
		ground->SetPos(Vector2(1000.0f, 750.0f));
		
		//펫
		Squirrel* mSquirrel = ya::object::Instantiate<Squirrel>(eColliderLayer::Pet);

		//장애물
		Fire01* fire01 = ya::object::Instantiate<Fire01>(eColliderLayer::Obstruction);
		//Fire02* fire02 = ya::object::Instantiate<Fire02>(eColliderLayer::Obstruction);
		Down* down = ya::object::Instantiate<Down>(eColliderLayer::Obstruction);
		Rolling* rolling = ya::object::Instantiate<Rolling>(eColliderLayer::Obstruction);
		Rope01* rope01 = ya::object::Instantiate<Rope01>(eColliderLayer::Obstruction);
		Rope02* rope02 = ya::object::Instantiate<Rope02>(eColliderLayer::Obstruction);

		//타일툴로 깔면 움직일때 이상하게 되서 한 번에 여러개 띄워주고 싶은데 잘 모르겠음
		GroundTile* groundtile = ya::object::Instantiate<GroundTile>(eColliderLayer::Tile);
		groundtile->SetPos(Vector2{ 0.0f,700.0f });
		groundtile->SetCount(10);

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
		YellowBear* yellowbear = ya::object::Instantiate<YellowBear>(eColliderLayer::Jelly);
		//RainbowBear* rainbowbear = ya::object::Instantiate<RainbowBear>(eColliderLayer::Jelly);
		//SilverCoin* silvercoin = ya::object::Instantiate<SilverCoin>(eColliderLayer::Jelly);
		//GoldCoin* goldcoin = ya::object::Instantiate<GoldCoin>(eColliderLayer::Jelly);
		//BigBear* bigbear = ya::object::Instantiate<BigBear>(eColliderLayer::Jelly);
	}

	void PlayScene::Tick()
	{
		Scene::Tick();
		
		if (KEY_DOWN(eKeyCode::N))
		{
			SceneManager::ChangeScene(eSceneType::End);
		}

	}

	void PlayScene::Render(HDC hdc)
	{


		Scene::Render(hdc);
		wchar_t szFloat[50] = {};
		swprintf_s(szFloat, 50, L"Play Scene");
		int strLen = wcsnlen_s(szFloat, 50);
		TextOut(hdc, 10, 30, szFloat, strLen);


	/*	ya::Scene* scene = ya::SceneManager::GetScene(eSceneType::Tool);
		ya::ToolScene* toolScene = dynamic_cast<ya::ToolScene*>(scene);
		toolScene->LoadTilePalette(L"..\\Resources\\TileSaveFiles\\Test2");*/
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
