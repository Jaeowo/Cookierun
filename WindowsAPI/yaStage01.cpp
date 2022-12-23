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


namespace ya
{
	//장애물이랑 젤리셋팅 여기로 맞춰서 PlayScene으로 옮겨주기
	void Stage01::ObstructionSetting()
	{
		

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

		Fire02* fire021 = ya::object::Instantiate<Fire02>(Vector2(4200.0f, 650.0f),eColliderLayer::Obstruction);
		fire021->SetPos(Vector2(4200.0f, 650.0f));
		Fire02* fire022 = ya::object::Instantiate<Fire02>(Vector2(4300.0f, 650.0f),eColliderLayer::Obstruction);
		fire022->SetPos(Vector2(4300.0f, 650.0f));
		Fire02* fire023 = ya::object::Instantiate<Fire02>(Vector2(4400.0f, 650.0f),eColliderLayer::Obstruction);
		fire023->SetPos(Vector2(4400.0f, 650.0f));

		ya::Scene* scene = ya::SceneManager::GetScene(eSceneType::JellyTool);
		ya::JellyToolScene* jellytoolScene = dynamic_cast<ya::JellyToolScene*>(scene);
		jellytoolScene->Load(L"..\\WindowsAPI\\AStage01");

	/*	Down* down = ya::object::Instantiate<Down>(eColliderLayer::Obstruction);
		Rolling* rolling = ya::object::Instantiate<Rolling>(eColliderLayer::Obstruction);
		Rope01* rope01 = ya::object::Instantiate<Rope01>(eColliderLayer::Obstruction);
		Rope02* rope02 = ya::object::Instantiate<Rope02>(eColliderLayer::Obstruction);*/
	}
}
