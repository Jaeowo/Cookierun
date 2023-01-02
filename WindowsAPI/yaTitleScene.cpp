#include "yaTitleScene.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaBgImageObject.h"
#include "yaObject.h"
#include "yaLobbieCookie.h"
#include "yaUIManager.h"
#include "yaGameStart.h"

namespace ya
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		BgImageObject* bg = new BgImageObject();
		bg->SetImage(L"Lobbie", L"Lobbie.bmp");
		bg->Initialize();

		AddGameObject(bg, eColliderLayer::BackGround);

		ya::object::Instantiate<LobbieCookie>(eColliderLayer::Player);

		//UIManager::Push(eUIType::INVENTORY);
		
	}
	void TitleScene::Tick()
	{
		Scene::Tick();

		if (KEY_DOWN(eKeyCode::N))
		{
			SceneManager::ChangeScene(eSceneType::Play);
		}
	}
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	
	}
	void TitleScene::Enter()
	{
		UIManager::Push(eUIType::OPTION);
	}
	void TitleScene::Exit()
	{
		UIManager::Pop(eUIType::OPTION);
	}
}
