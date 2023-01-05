#include "yaGameStart.h"
#include "yaImage.h"
#include "yaInput.h"
#include "yaApplication.h"
#include "yaSceneManager.h"
#include "yaSound.h"
#include "yaObject.h"
namespace ya
{
	GameStart::GameStart(eUIType type)
		: UiBase(type)
	{
		mOnClick = std::bind(&GameStart::Click, this);
	}
	GameStart::~GameStart()
	{

	}

	void GameStart::OnInit()
	{

	}

	void GameStart::OnActive()
	{

	}

	void GameStart::OnInActive()
	{
	}

	void GameStart::OnTick()
	{
		Vector2 mousePos = Input::GetMousePos();
		Vector2 size = GetSize();

		if (mScreenPos.x <= mousePos.x && mousePos.x < mScreenPos.x + size.x
			&& mScreenPos.y <= mousePos.y && mousePos.y < mScreenPos.y + size.y)
		{
			mbMouseOn = true;
		}
		else
		{
			mbMouseOn = false;
		}

		if (KEY_DOWN(eKeyCode::LBTN) && mbMouseOn)
		{
			mOnClick();
		}
	}

	void GameStart::OnRender(HDC hdc)
	{


		Vector2 pos = GetPos();
		Vector2 finalPos = pos;
		Vector2 rect;
		rect.x = mImage->GetWidth();
		rect.y = mImage->GetHeight();

		TransparentBlt(hdc, finalPos.x, finalPos.y, rect.x, rect.y
			, mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 0, 255));
	}

	void GameStart::OnClear()
	{

	}

	void GameStart::Click()
	{

		Sound* sound = ya::object::Instantiate<Sound>(eColliderLayer::BGM);
		sound->Load(L"..\\Resources\\Sound\\ui_1.wav");
		sound->Play(false);
		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();

		SceneManager::ChangeScene(eSceneType::Play);
	}
}