#include "yaEditor.h"
#include "yaImage.h"
#include "yaInput.h"
#include "yaApplication.h"
#include "yaSceneManager.h"
#include "yaSound.h"
#include "yaObject.h"
namespace ya
{
	Editor::Editor(eUIType type)
		: UiBase(type)
	{
		mOnClick = std::bind(&Editor::Click, this);
	}
	Editor::~Editor()
	{

	}

	void Editor::OnInit()
	{

	}

	void Editor::OnActive()
	{

	}

	void Editor::OnInActive()
	{
	}

	void Editor::OnTick()
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

	void Editor::OnRender(HDC hdc)
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

	void Editor::OnClear()
	{

	}

	void Editor::Click()
	{

		Sound* sound = ya::object::Instantiate<Sound>(eColliderLayer::BGM);
		sound->Load(L"..\\Resources\\Sound\\ui_1.wav");
		sound->Play(false);
		eSceneType type = ya::Application::GetInstance().GetPlaySceneType();

		SceneManager::ChangeScene(eSceneType::JellyTool);
	}
}