#include "yaEndScene.h"
#include "yaBgImageObject.h"
#include "yaCamera.h"
#include "yaSound.h"
#include "yaObject.h"
#include "yaGameObjectManager.h"
#include "yaPlayer.h"
namespace ya
{
	EndScene::EndScene()
	{
	}
	EndScene::~EndScene()
	{
	}
	void EndScene::Initialize()
	{
		BgImageObject* Bg1 = new BgImageObject();
		Bg1->SetImage(L"Result", L"Result.bmp");
		Bg1->Initialize();
		AddGameObject(Bg1, eColliderLayer::BackGround);
	}
	void EndScene::Tick()
	{
		Scene::Tick();
	}
	void EndScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		WCHAR word[1024];
		int num = GameObjectManager::GetPlayer()->GetScore();
		wsprintfW(word, L" %d", num);
		TextOutW(hdc, 700, 300, word, lstrlen(word));

		WCHAR word2[1024];
		int num2 = GameObjectManager::GetPlayer()->GetCoin();
		wsprintfW(word2, L" %d", num2);
		TextOutW(hdc, 1100, 550, word2, lstrlen(word2));

	}
	void EndScene::Enter()
	{
		
		Sound* sound = ya::object::Instantiate<Sound>(eColliderLayer::BGM);
		sound->Load(L"..\\Resources\\Sound\\r_score.wav");
		sound->Play(false);
	}
	void EndScene::Exit()
	{
	}
}
