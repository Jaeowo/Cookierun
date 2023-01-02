#include "yaLogoScene.h"
#include "yaPlayer.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaBgImageObject.h"
#include "yaCollisionManager.h"
#include "yaObject.h"
#include "yaApplication.h"
#include "yaToolScene.h"
//#include "yaUIManager.h"

namespace ya
{
	LogoScene::LogoScene()
	{
	}

	LogoScene::~LogoScene()
	{
	}

	void LogoScene::Initialize()
	{

		BgImageObject* bg = new BgImageObject();
		bg->SetImage(L"Logo", L"Logo.bmp");
		bg->Initialize();

		AddGameObject(bg, eColliderLayer::BackGround);
		//UIManager::Pop(eUIType::HP);
	}

	void LogoScene::Tick()
	{
		// 오브젝트 tick 을 호출한다.
		Scene::Tick();
		
		//ya::object::Destroy(mons[0], 3.0f);
		if (KEY_DOWN(eKeyCode::N))
		{
			SceneManager::ChangeScene(eSceneType::Title);
		}
	}

	void LogoScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

	}

	void LogoScene::Enter()
	{
		/*UIManager::Pop(eUIType::HP);
		UIManager::Pop(eUIType::OPTION);*/
	}

	void LogoScene::Exit()
	{

	}
}