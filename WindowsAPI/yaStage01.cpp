#include "yaStage01.h"
#include "yaFire01.h"
#include "yaFire02.h"
#include "yaDown.h"
#include "yaRolling.h"
#include "yaRope01.h"
#include "yaRope02.h"
#include "yaObject.h"
#include "yaPlayer.h"
#include "yaJellyToolScene.h"
#include "yaRope2Trigger.h"
#include "yaGroundTile.h"
#include "yaChange02.h"

namespace ya
{
	Stage01::Stage01()
		:Isit(false)
		,mCount (15)
	{
	}
	//장애물이랑 젤리셋팅 여기로 맞춰서 PlayScene으로 옮겨주기
	void Stage01::ObstructionSetting()
	{
		Isit = true;

		//한번에 for문돌려서 찍으려했는데 움직일때 이상해서 일단 하드코딩 ㅜㅜ
		GroundTile* groundtile = ya::object::Instantiate<GroundTile>(eColliderLayer::Tile);
		groundtile->SetPos(Vector2{ 0.0f,700.0f });
		GroundTile* groundtile2 = ya::object::Instantiate<GroundTile>(eColliderLayer::Tile);
		groundtile2->SetPos(Vector2{ 124.0f,700.0f });
		GroundTile* groundtile3 = ya::object::Instantiate<GroundTile>(eColliderLayer::Tile);
		groundtile3->SetPos(Vector2{ 248.0f,700.0f });
		GroundTile* groundtile4 = ya::object::Instantiate<GroundTile>(eColliderLayer::Tile);
		groundtile4->SetPos(Vector2{ 372.0f,700.0f });
		GroundTile* groundtile5 = ya::object::Instantiate<GroundTile>(eColliderLayer::Tile);
		groundtile5->SetPos(Vector2{ 496.0f,700.0f });
		GroundTile* groundtile6 = ya::object::Instantiate<GroundTile>(eColliderLayer::Tile);
		groundtile6->SetPos(Vector2{ 620.0f,700.0f });
		GroundTile* groundtile7 = ya::object::Instantiate<GroundTile>(eColliderLayer::Tile);
		groundtile7->SetPos(Vector2{ 744.0f,700.0f });
		GroundTile* groundtile8 = ya::object::Instantiate<GroundTile>(eColliderLayer::Tile);
		groundtile8->SetPos(Vector2{ 868.0f,700.0f });
		GroundTile* groundtile9 = ya::object::Instantiate<GroundTile>(eColliderLayer::Tile);
		groundtile9->SetPos(Vector2{ 992.0f,700.0f });
		GroundTile* groundtile10 = ya::object::Instantiate<GroundTile>(eColliderLayer::Tile);
		groundtile10->SetPos(Vector2{ 1116.0f,700.0f });
		GroundTile* groundtile11 = ya::object::Instantiate<GroundTile>(eColliderLayer::Tile);
		groundtile11->SetPos(Vector2{ 1240.0f,700.0f });

	


		Fire01* fire01 = ya::object::Instantiate<Fire01>(Vector2(1900.0f, 650.0f),eColliderLayer::Obstruction);
		fire01->SetPos(Vector2(1900.0f, 650.0f));
		Fire01* fire011 = ya::object::Instantiate<Fire01>(Vector2(2400.0f, 650.0f),eColliderLayer::Obstruction);
		fire011->SetPos(Vector2(2400.0f, 650.0f));
		Fire02* fire02 = ya::object::Instantiate<Fire02>(Vector2(2900.0f, 650.0f),eColliderLayer::Obstruction);
		fire02->SetPos(Vector2(2900.0f, 650.0f));

		Rope01* rope01 = ya::object::Instantiate<Rope01>(Vector2(3500.0f, 270.0f),eColliderLayer::Obstruction);
		rope01->SetPos(Vector2(3500.0f, 270.0f));
		Rope02* rope02 = ya::object::Instantiate<Rope02>(Vector2(3700.0f, 160.0f),eColliderLayer::Obstruction);
		rope02->SetPos(Vector2(3700.0f, 160.0f));
		Rope2Trigger* ropet02 = ya::object::Instantiate<Rope2Trigger>(Vector2(3700.0f, 160.0f), eColliderLayer::Obstruction);
		ropet02->SetTarget(rope02);
		ropet02->SetPos(Vector2(3700.0f, 160.0f));



		Fire02* fire021 = ya::object::Instantiate<Fire02>(Vector2(4200.0f, 650.0f),eColliderLayer::Obstruction);
		fire021->SetPos(Vector2(4200.0f, 650.0f));
		Fire02* fire022 = ya::object::Instantiate<Fire02>(Vector2(4300.0f, 650.0f),eColliderLayer::Obstruction);
		fire022->SetPos(Vector2(4300.0f, 650.0f));
		Fire02* fire023 = ya::object::Instantiate<Fire02>(Vector2(4400.0f, 650.0f),eColliderLayer::Obstruction);
		fire023->SetPos(Vector2(4400.0f, 650.0f));

	/*	Down* down = ya::object::Instantiate<Down>(eColliderLayer::Obstruction);
		Rolling* rolling = ya::object::Instantiate<Rolling>(eColliderLayer::Obstruction);
		Rope01* rope01 = ya::object::Instantiate<Rope01>(eColliderLayer::Obstruction);
		Rope02* rope02 = ya::object::Instantiate<Rope02>(eColliderLayer::Obstruction);*/
	}

}
