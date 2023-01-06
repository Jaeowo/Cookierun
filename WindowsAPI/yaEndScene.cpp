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
		//TextOutW(hdc, 700, 300, word, lstrlen(word));

		WCHAR word2[1024];
		int num2 = GameObjectManager::GetPlayer()->GetCoin();
		wsprintfW(word2, L" %d", num2);
		//TextOutW(hdc, 1100, 550, word2, lstrlen(word2));


		PAINTSTRUCT ps;
		HFONT font, oldfont;

		font = CreateFont(90, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
			VARIABLE_PITCH | FF_ROMAN, L"CookieRun Bold");
		SetTextColor(hdc, RGB(255, 255, 255));
		SetBkMode(hdc, TRANSPARENT);
		oldfont = (HFONT)SelectObject(hdc, font);

		TextOutW(hdc, 680, 270, word, lstrlen(word));

		TextOutW(hdc, 1050, 540, word2, lstrlen(word2));

		SelectObject(hdc, oldfont);

		DeleteObject(font);

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
