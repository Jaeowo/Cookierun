#include "yaSkillScene.h"
#include "yaBgImageObject.h"
#include "yaCollisionManager.h"
#include "yaSkillTile.h"
#include "yaObject.h"
#include "yaGround.h"
#include "yaLeftLeaf.h"
#include "yaRightLeaf.h"
#include "yastem.h"
#include "yaFlower1.h"
#include "yaFlower2.h"
#include "yaFlower3.h"
#include "yaFlower4.h"
#include "yaLeafFlower.h"
#include "yaGameObjectManager.h"
#include "yaSquirrel.h"
#include "yaPlayer.h"
#include "yaGameObject.h"
#include "yaBackPlayScene.h"
#include "yaInput.h"
#include "yaCamera.h"

#include "yaUIManager.h"
#include "yaHpBar.h"
#include "yaSound.h"
#include "yaTime.h"

namespace ya
{
	SkillScene::SkillScene()
	{
	
	}
	SkillScene::~SkillScene()
	{
	}
	void SkillScene::Initialize()
	{

		//Camera::SetCameraEffect(eCameraEffect::FadeIn);

		//¹è°æ
		BgImageObject* Bg3 = new BgImageObject();
		Bg3->SetImage(L"SkillBg1", L"SkillBg1.bmp");
		Bg3->Initialize();
		AddGameObject(Bg3, eColliderLayer::BackGround);
		Bg3->SetSpeed(-15.0f);

		BgImageObject* Bg4 = new BgImageObject();
		Bg4->SetImage(L"SkillBg2", L"SkillBg2.bmp");
		Bg4->Initialize();
		AddGameObject(Bg4, eColliderLayer::BackGround);
		Bg4->SetSpeed(-20.0f);

		BgImageObject* Bg5 = new BgImageObject();
		Bg5->SetImage(L"SkillBg3", L"SkillBg3.bmp");
		Bg5->Initialize();
		AddGameObject(Bg5, eColliderLayer::BackGround);
		Bg5->SetSpeed(-25.0f);

		SkillTile* skilltile = ya::object::Instantiate<SkillTile>(eColliderLayer::Tile);
		skilltile->SetPos(Vector2{ 0.0f,700.0f });

		SkillTile* skilltile2 = ya::object::Instantiate<SkillTile>(eColliderLayer::Tile);
		skilltile2->SetPos(Vector2{ 1860.0f,700.0f });

		SkillTile* skilltile3 = ya::object::Instantiate<SkillTile>(eColliderLayer::Tile);
		skilltile3->SetPos(Vector2{ 3720.0f,700.0f });

		SkillTile* skilltile4 = ya::object::Instantiate<SkillTile>(eColliderLayer::Tile);
		skilltile4->SetPos(Vector2{ 5580.0f,700.0f });

		//mPlayer = GameObjectManager::GetPlayer();
		mPlayer = ya::object::Instantiate<Player>(eColliderLayer::Player);
		GameObjectManager::SetPlayer(mPlayer);
	
	



		Squirrel* mSquirrel = ya::object::Instantiate<Squirrel>(eColliderLayer::Pet);

		Ground* ground = ya::object::Instantiate<Ground>(eColliderLayer::Ground);
		ground->SetPos(Vector2(1000.0f, 750.0f));
		ground->SetColPos(Vector2(8000.0f, 100.0f));

	

		Flower1* flower11 = ya::object::Instantiate<Flower1>(Vector2(1500.0f, 570.0f), eColliderLayer::Obstruction);
		flower11->SetPos(Vector2(1500.0f, 570.0f));

		Flower2* flower21 = ya::object::Instantiate<Flower2>(Vector2(1700.0f, 560.0f),eColliderLayer::Obstruction);
		flower21->SetPos(Vector2(1700.0f, 560.0f));

		Flower3* flower31 = ya::object::Instantiate<Flower3>(Vector2(1900.0f, 550.0f),eColliderLayer::Obstruction);
		flower31->SetPos(Vector2(1900.0f, 550.0f));

		Flower4* flower41 = ya::object::Instantiate<Flower4>(Vector2(2100.0f, 560.0f),eColliderLayer::Obstruction);
		flower41->SetPos(Vector2(2100.0f, 560.0f));


		Flower3* flower32 = ya::object::Instantiate<Flower3>(Vector2(2300.0f, 550.0f), eColliderLayer::Obstruction);
		flower32->SetPos(Vector2(2300.0f, 550.0f));

		Flower3* flower33 = ya::object::Instantiate<Flower3>(Vector2(3600.0f, 550.0f), eColliderLayer::Obstruction);
		flower33->SetPos(Vector2(3800.0f, 550.0f));

		Flower3* flower34 = ya::object::Instantiate<Flower3>(Vector2(3700.0f, 550.0f), eColliderLayer::Obstruction);
		flower34->SetPos(Vector2(3700.0f, 550.0f));

		Flower4* flower42 = ya::object::Instantiate<Flower4>(Vector2(3650.0f, 560.0f), eColliderLayer::Obstruction);
		flower42->SetPos(Vector2(3650.0f, 560.0f));

		Flower1* flower12 = ya::object::Instantiate<Flower1>(Vector2(3700.0f, 570.0f), eColliderLayer::Obstruction);
		flower12->SetPos(Vector2(3800.0f, 570.0f));

		Flower2* flower22 = ya::object::Instantiate<Flower2>(Vector2(3800.0f, 560.0f), eColliderLayer::Obstruction);
		flower22->SetPos(Vector2(3900.0f, 560.0f));

		Flower4* flower43 = ya::object::Instantiate<Flower4>(Vector2(4000.0f, 560.0f), eColliderLayer::Obstruction);
		flower43->SetPos(Vector2(4000.0f, 560.0f));

		Flower1* flower13 = ya::object::Instantiate<Flower1>(Vector2(4100.0f, 570.0f), eColliderLayer::Obstruction);
		flower13->SetPos(Vector2(4100.0f, 570.0f));

		Flower3* flower35 = ya::object::Instantiate<Flower3>(Vector2(4200.0f, 550.0f), eColliderLayer::Obstruction);
		flower35->SetPos(Vector2(4200.0f, 550.0f));

		Flower2* flower23 = ya::object::Instantiate<Flower2>(Vector2(3800.0f, 560.0f), eColliderLayer::Obstruction);
		flower23->SetPos(Vector2(4300.0f, 560.0f));

		Flower1* flower14 = ya::object::Instantiate<Flower1>(Vector2(3700.0f, 570.0f), eColliderLayer::Obstruction);
		flower14->SetPos(Vector2(4400.0f, 570.0f));

		Flower4* flower44 = ya::object::Instantiate<Flower4>(Vector2(4000.0f, 560.0f), eColliderLayer::Obstruction);
		flower44->SetPos(Vector2(4500.0f, 560.0f));

		Stem* stem = ya::object::Instantiate<Stem>(eColliderLayer::Obstruction);
		stem->SetPos(Vector2(3000.0f, 450.0f));

		LeftLeaf* leftleaf1 = ya::object::Instantiate<LeftLeaf>(eColliderLayer::Obstruction);
		leftleaf1->SetPos(Vector2(2850.0f, 600.0f));


		Stem* stem1 = ya::object::Instantiate<Stem>(eColliderLayer::Obstruction);
		stem1->SetPos(Vector2(3100.0f, 450.0f));

		LeafFlower* leafflower2 = ya::object::Instantiate<LeafFlower>(Vector2(3390.0f, 380.0f),eColliderLayer::Obstruction);
		leafflower2->SetPos(Vector2(3390.0f, 380.0f));
		leafflower2->SetColPos(Vector2(-140.0f, 20.0f));

		LeafFlower* leafflower1 = ya::object::Instantiate<LeafFlower>(Vector2(3290.0f, 370.0f), eColliderLayer::Obstruction);
		leafflower1->SetPos(Vector2(3290.0f, 370.0f));
		leafflower1->SetColPos(Vector2(-440.0f, 235.0f));

		RightLeaf* rightleaf1 = ya::object::Instantiate<RightLeaf>(Vector2(3230.0f, 400.0f),eColliderLayer::Obstruction);
		rightleaf1->SetPos(Vector2(3230.0f, 400.0f));

	/*	BackPlayScene* backplayscene = ya::object::Instantiate<BackPlayScene>(Vector2(4900.0f, 560.0f), eColliderLayer::Obstruction);
		backplayscene->SetPos(Vector2(4900.0f, 560.0f));*/

		Ground* ground1 = ya::object::Instantiate<Ground>(eColliderLayer::Ground);
		ground1->SetPos(Vector2(2850.0f, 600.0f));
		ground1->SetColPos(Vector2(170.0f, 100.0f));

		Ground* ground2 = ya::object::Instantiate<Ground>(eColliderLayer::Ground);
		ground2->SetPos(Vector2(3230.0f, 400.0f));
		ground2->SetColPos(Vector2(170.0f, 100.0f));

		

	}
	void SkillScene::Tick()
	{

		mExitCount += Time::DeltaTime();
		if (mExitCount >= 13.5f)
		{
			SceneManager::ChangeScene(eSceneType::Play);
		}
		/*if (mPlayer->GetChange() == true)
		{
			mPlayer->SetChange(false);
			SceneManager::ChangeScene(eSceneType::Play);
		}*/
		if (KEY_DOWN(eKeyCode::N))
		{
			SceneManager::ChangeScene(eSceneType::Play);
		}
		Vector2 PlayerPos = GameObjectManager::GetPlayer()->GetPos();
		GameObjectManager::GetPlayer()->SetPos(mPlayer->GetPos());

		//
		//GameObjectManager::GetPlayer()->SetScore(mPlayer->GetScore());
		Scene::Tick();
		mPlayer->SetHp(GameObjectManager::GetPlayer()->GetHp());
		
	}
	void SkillScene::Render(HDC hdc)
	{
	
		Scene::Render(hdc);

		WCHAR word[1024];
		int num = mPlayer->GetScore();
		wsprintfW(word, L"Score : %d", num);
		//TextOutW(hdc, 100, 100, word, lstrlen(word));

		WCHAR word2[1024];
		int num2 = GameObjectManager::GetPlayer()->GetCoin();
		wsprintfW(word2, L"Coin : %d", num2);
		//TextOutW(hdc, 100, 120, word2, lstrlen(word2));

		PAINTSTRUCT ps;
		HFONT font, oldfont;

		font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, L"CookieRun Bold");
		SetTextColor(hdc, RGB(255, 255, 255));
		SetBkMode(hdc, TRANSPARENT);
		oldfont = (HFONT)SelectObject(hdc, font);

		TextOutW(hdc, 100, 100, word, lstrlen(word));

		TextOutW(hdc, 100, 150, word2, lstrlen(word2));

		SelectObject(hdc, oldfont);

		DeleteObject(font);
	}
	void SkillScene::Enter()
	{
		

		UIManager::Push(eUIType::HP);
		UIManager::Push(eUIType::N1);
		UIManager::Push(eUIType::N2);

		HpBar* hpbar = UIManager::GetUiInstant<HpBar>(eUIType::HP);
		hpbar->SetTarget(GameObjectManager::GetPlayer());

		GameObjectManager::GetPlayer()->SetSkill2Time(0.0f);

		CollisionManager::SetLayer(eColliderLayer::Obstruction, eColliderLayer::Player, true);
		CollisionManager::SetLayer(eColliderLayer::Ground, eColliderLayer::Player, true);
		CollisionManager::SetLayer(eColliderLayer::Jelly, eColliderLayer::Player, true);

		mSound = ya::object::Instantiate<Sound>(eColliderLayer::BGM);
		mSound->Load(L"..\\Resources\\Sound\\LilySkill.wav");
		mSound->Play(true);
		mExitCount = 0.0f;
		mPlayer->SetScore(GameObjectManager::GetPlayer()->GetScore());
	}
	void SkillScene::Exit()
	{
		mPlayer->SetChange(false);
		//SceneManager::DetroyGameObject();
		mSound->Stop(true);

		GameObjectManager::GetPlayer()->SetScore(mPlayer->GetScore());
		
		//
	}
}
