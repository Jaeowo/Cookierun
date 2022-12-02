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
#include "yaFire02.h"
#include "yaDown.h"
#include "yaRolling.h"
#include "yaBiggest.h"
#include "yaGroundTile.h"

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
		Bg1->SetSpeed(-1.5f);

		BgImageObject* Bg2 = new BgImageObject();
		Bg2->SetImage(L"Bg2", L"Bg3.bmp");
		Bg2->Initialize();
		AddGameObject(Bg2, eColliderLayer::BackGround);
		Bg2->SetSpeed(-4.5f);
	
		//캐릭터
		
		Player* player = ya::object::Instantiate<Player>(eColliderLayer::Player);

		Ground* ground = ya::object::Instantiate<Ground>(eColliderLayer::Ground);
		ground->SetPos(Vector2(1000.0f, 750.0f));
		
		//펫
		//펫이랑 캐릭터 멤버변수로 저장해서 tick에 넣어서 실시간으로 움직이게 만들기
		Vector2 PlayerPos = player->GetPos();
		Vector2 PetPos((PlayerPos.x - 100.0f), PlayerPos.y);
		Squirrel* mSquirrel = ya::object::Instantiate<Squirrel>(eColliderLayer::Pet);
		mSquirrel->SetPos(PetPos);

		//==
		Fire02* fire02 = ya::object::Instantiate<Fire02>(eColliderLayer::Obstruction);

		Down* down = ya::object::Instantiate<Down>(eColliderLayer::Obstruction);

		Rolling* rolling = ya::object::Instantiate<Rolling>(eColliderLayer::Obstruction);

		Biggest* biggest = ya::object::Instantiate<Biggest>(eColliderLayer::Jelly);

		GroundTile* groundtile = ya::object::Instantiate<GroundTile>(eColliderLayer::Tile);
		groundtile->SetPos(Vector2{ 100.0f,600.0f });
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

		wchar_t szFloat2[50] = {};
		swprintf_s(szFloat2, 50, L"Hp:");
		int strLen2 = wcsnlen_s(szFloat2, 50);
		TextOut(hdc, 10, 50, szFloat2, strLen2);

		/*ya::Scene* scene = ya::SceneManager::GetScene(eSceneType::Tool);
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
