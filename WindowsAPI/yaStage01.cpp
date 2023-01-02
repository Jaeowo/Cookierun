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
#include "yaGround.h"
#include "yaSmallHp.h"
#include "yaBigHp.h"
#include "yaBiggest.h"

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

		//땅
		Ground* ground = ya::object::Instantiate<Ground>(Vector2(2790.0f, 100.0f), eColliderLayer::Ground);
		ground->SetPos(Vector2(2790.0f, 750.0f));
		ground->SetColPos(Vector2(5580.0f, 100.0f));
		Ground* ground2 = ya::object::Instantiate<Ground>(Vector2(3720.0f, 100.0f), eColliderLayer::Ground);
		ground2->SetPos(Vector2(7740.0f, 750.0f));
		ground2->SetColPos(Vector2(3720.0f, 100.0f));

		//땅타일
		//한번에 for문돌려서 찍으려했는데 움직일때 이상해서 일단 하드코딩 ㅜㅜ
		GroundTile* groundtile = ya::object::Instantiate<GroundTile>(eColliderLayer::Tile);
		groundtile->SetPos(Vector2{ 0.0f,700.0f });
		GroundTile* groundtile2 = ya::object::Instantiate<GroundTile>(eColliderLayer::Tile);
		groundtile2->SetPos(Vector2{ 1860.0f,700.0f });
		GroundTile* groundtile3 = ya::object::Instantiate<GroundTile>(eColliderLayer::Tile);
		groundtile3->SetPos(Vector2{ 3720.0f,700.0f });

		GroundTile* groundtile4 = ya::object::Instantiate<GroundTile>(eColliderLayer::Tile);
		groundtile4->SetPos(Vector2{ 5880.0f,700.0f });
		GroundTile* groundtile5 = ya::object::Instantiate<GroundTile>(eColliderLayer::Tile);
		groundtile5->SetPos(Vector2{ 7740.0f,700.0f });


	


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

		BigHp* bighp = ya::object::Instantiate<BigHp>(Vector2(6200.0f, 605.0f), eColliderLayer::Jelly);
		bighp->SetPos(Vector2(6400.0f, 605.0f));

		Biggest* biggest = ya::object::Instantiate<Biggest>(Vector2(6200.0f, 605.0f), eColliderLayer::Jelly);
		biggest->SetPos(Vector2(6900.0f, 405.0f));

		Rope02* rope021 = ya::object::Instantiate<Rope02>(Vector2(3700.0f, 160.0f), eColliderLayer::Obstruction);
		rope021->SetPos(Vector2(7200.0f, 160.0f));

		Down* down = ya::object::Instantiate<Down>(Vector2(7400.0f, 605.0f),eColliderLayer::Obstruction);
		down->SetPos(Vector2(7400.0f, 605.0f));

		Rope02* rope022 = ya::object::Instantiate<Rope02>(Vector2(3700.0f, 160.0f), eColliderLayer::Obstruction);
		rope022->SetPos(Vector2(7600.0f, 160.0f));

		Down* down2 = ya::object::Instantiate<Down>(Vector2(7400.0f, 605.0f), eColliderLayer::Obstruction);
		down2->SetPos(Vector2(7800.0f, 605.0f));

		Rope02* rope023 = ya::object::Instantiate<Rope02>(Vector2(3700.0f, 160.0f), eColliderLayer::Obstruction);
		rope023->SetPos(Vector2(8000.0f, 160.0f));

		Down* down3 = ya::object::Instantiate<Down>(Vector2(7400.0f, 605.0f), eColliderLayer::Obstruction);
		down3->SetPos(Vector2(8200.0f, 605.0f));

		Rope02* rope024 = ya::object::Instantiate<Rope02>(Vector2(3700.0f, 160.0f), eColliderLayer::Obstruction);
		rope024->SetPos(Vector2(8400.0f, 160.0f));
	/*	Down* down = ya::object::Instantiate<Down>(eColliderLayer::Obstruction);
		Rolling* rolling = ya::object::Instantiate<Rolling>(eColliderLayer::Obstruction);
		Rope01* rope01 = ya::object::Instantiate<Rope01>(eColliderLayer::Obstruction);
		Rope02* rope02 = ya::object::Instantiate<Rope02>(eColliderLayer::Obstruction);*/
	}

}
