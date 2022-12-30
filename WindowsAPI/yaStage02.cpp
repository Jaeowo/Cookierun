#include "yaStage02.h"
#include "yaFire01.h"
#include "yaFire02.h"
#include "yaDown.h"
#include "yaRolling.h"
#include "yaRope01.h"
#include "yaRope02.h"
#include "yaObject.h"
#include "yaPlayer.h"
#include "yaJellyToolScene.h"
#include "yaBiggest.h"
#include "yaRun.h"
#include "yaGroundTile.h"

namespace ya
{
	//장애물이랑 젤리셋팅 여기로 맞춰서 PlayScene으로 옮겨주기
	void Stage02::ObstructionSetting()
	{

		Biggest* biggest = ya::object::Instantiate<Biggest>(Vector2(1900.0f, 405.0f),eColliderLayer::Jelly);
		biggest->SetPos(Vector2(1900.0f, 405.0f));



		Fire01* fire01 = ya::object::Instantiate<Fire01>(Vector2(2000.0f, 650.0f),eColliderLayer::Obstruction);
		fire01->SetPos(Vector2(2000.0f, 650.0f));
		Fire02* fire02 = ya::object::Instantiate<Fire02>(Vector2(2100.0f, 650.0f),eColliderLayer::Obstruction);
		fire02->SetPos(Vector2(2100.0f, 650.0f));
		Fire01* fire011 = ya::object::Instantiate<Fire01>(Vector2(2200.0f, 650.0f),eColliderLayer::Obstruction);
		fire011->SetPos(Vector2(2200.0f, 650.0f));

		Run* run = ya::object::Instantiate<Run>(Vector2(2800.0f, 405.0f),eColliderLayer::Jelly);
		run->SetPos(Vector2(2800.0f, 405.0f));

		Run* run2 = ya::object::Instantiate<Run>(Vector2(3200.0f, 405.0f), eColliderLayer::Jelly);
		run2->SetPos(Vector2(3200.0f, 405.0f));


	/*	Down* down = ya::object::Instantiate<Down>(Vector2(3400.0f, 605.0f),eColliderLayer::Obstruction);
		down->SetPos(Vector2(3400.0f, 605.0f));

		Down* down1 = ya::object::Instantiate<Down>(Vector2(3900.0f, 605.0f),eColliderLayer::Obstruction);
		down1->SetPos(Vector2(3900.0f, 605.0f));

		Down* down2 = ya::object::Instantiate<Down>(Vector2(4400.0f, 605.0f),eColliderLayer::Obstruction);
		down2->SetPos(Vector2(4400.0f, 605.0f));*/


	}
}
