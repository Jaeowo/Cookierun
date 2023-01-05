#include "yaBack.h"
#include "yaImage.h"
#include "yaInput.h"
#include "yaApplication.h"
#include "yaSceneManager.h"
#include "yaSound.h"
#include "yaObject.h"
namespace ya
{
	Back::Back(eUIType type)
		: UiBase(type)
	{
		mOnClick = std::bind(&Back::Click, this);
	}
	Back::~Back()
	{

	}

	void Back::OnInit()
	{

	}

	void Back::OnActive()
	{

	}

	void Back::OnInActive()
	{
	}

	void Back::OnTick()
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

	void Back::OnRender(HDC hdc)
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

	void Back::OnClear()
	{

	}

	void Back::Click()
	{

		Sound* sound = ya::object::Instantiate<Sound>(eColliderLayer::BGM);
		sound->Load(L"..\\Resources\\Sound\\ui_1.wav");
		sound->Play(false);
		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();

		SceneManager::ChangeScene(eSceneType::Title);
	}
}