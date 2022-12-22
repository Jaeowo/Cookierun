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
		skilltile->SetCount(15);

		Ground* ground = ya::object::Instantiate<Ground>(eColliderLayer::Ground);
		ground->SetPos(Vector2(1000.0f, 750.0f));
		ground->SetColPos(Vector2(8000.0f, 100.0f));

		Player* player = ya::object::Instantiate<Player>(eColliderLayer::Player);

		Flower1* flower11 = ya::object::Instantiate<Flower1>(eColliderLayer::Obstruction);
		flower11->SetPos(Vector2(1500.0f, 570.0f));

		Flower2* flower21 = ya::object::Instantiate<Flower2>(eColliderLayer::Obstruction);
		flower21->SetPos(Vector2(1700.0f, 560.0f));

		Flower3* flower31 = ya::object::Instantiate<Flower3>(eColliderLayer::Obstruction);
		flower31->SetPos(Vector2(1900.0f, 550.0f));

		Flower4* flower41 = ya::object::Instantiate<Flower4>(eColliderLayer::Obstruction);
		flower41->SetPos(Vector2(2100.0f, 560.0f));


		Stem* stem = ya::object::Instantiate<Stem>(eColliderLayer::Obstruction);
		stem->SetPos(Vector2(3000.0f, 450.0f));

		LeftLeaf* leftleaf1 = ya::object::Instantiate<LeftLeaf>(eColliderLayer::Obstruction);
		leftleaf1->SetPos(Vector2(2850.0f, 600.0f));


		Stem* stem1 = ya::object::Instantiate<Stem>(eColliderLayer::Obstruction);
		stem1->SetPos(Vector2(3100.0f, 450.0f));

		/*LeafFlower* leafflower2 = ya::object::Instantiate<LeafFlower>(eColliderLayer::Obstruction);
		leafflower2->SetPos(Vector2(3390.0f, 380.0f));*/

		LeafFlower* leafflower1 = ya::object::Instantiate<LeafFlower>(eColliderLayer::Obstruction);
		leafflower1->SetPos(Vector2(3290.0f, 370.0f));
		leafflower1->SetColPos(Vector2(-440.0f, 235.0f));

		RightLeaf* rightleaf1 = ya::object::Instantiate<RightLeaf>(eColliderLayer::Obstruction);
		rightleaf1->SetPos(Vector2(3230.0f, 400.0f));

		Ground* ground1 = ya::object::Instantiate<Ground>(eColliderLayer::Ground);
		ground1->SetPos(Vector2(2850.0f, 600.0f));
		ground1->SetColPos(Vector2(170.0f, 100.0f));

		Ground* ground2 = ya::object::Instantiate<Ground>(eColliderLayer::Ground);
		ground2->SetPos(Vector2(3230.0f, 400.0f));
		ground2->SetColPos(Vector2(170.0f, 100.0f));
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
