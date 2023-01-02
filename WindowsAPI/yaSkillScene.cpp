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

#include "yaUIManager.h"
#include "yaHpBar.h"


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

		Player* player = ya::object::Instantiate<Player>(eColliderLayer::Player);
		GameObjectManager::SetPlayer(player);

		//���
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
		skilltile->SetCount(15);

		

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

		Ground* ground1 = ya::object::Instantiate<Ground>(eColliderLayer::Ground);
		ground1->SetPos(Vector2(2850.0f, 600.0f));
		ground1->SetColPos(Vector2(170.0f, 100.0f));

		Ground* ground2 = ya::object::Instantiate<Ground>(eColliderLayer::Ground);
		ground2->SetPos(Vector2(3230.0f, 400.0f));
		ground2->SetColPos(Vector2(170.0f, 100.0f));

		

		HpBar* hpbar = UIManager::GetUiInstant<HpBar>(eUIType::HP);
		hpbar->SetTarget(player);
	}
	void SkillScene::Tick()
	{
		Scene::Tick();
	}
	void SkillScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void SkillScene::Enter()
	{

		CollisionManager::SetLayer(eColliderLayer::Obstruction, eColliderLayer::Player, true);
		CollisionManager::SetLayer(eColliderLayer::Ground, eColliderLayer::Player, true);
		CollisionManager::SetLayer(eColliderLayer::Jelly, eColliderLayer::Player, true);
	}
	void SkillScene::Exit()
	{
	}
}
