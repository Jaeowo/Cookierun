#include "yaUIManager.h"
#include "yaHUD.h"
#include "yaButton.h"
#include "yaPanel.h"
#include "yaHpBar.h"
#include "yaGameStart.h"
#include "yaEditor.h"
#include "yaBack.h"

namespace ya
{
	std::unordered_map<eUIType, UiBase*> UIManager::mUIs;
	std::queue<eUIType> UIManager::mRequestUIQueue;
	std::stack<UiBase*> UIManager::mUIBases;
	UiBase* UIManager::mCurrentData = nullptr;

	void UIManager::Initialize()
	{
		HpBar* hpbar = new HpBar(eUIType::HP);
		mUIs.insert(std::make_pair(eUIType::HP, hpbar));
		hpbar->SetPos(Vector2(400.0f, 30.0f));
		hpbar->ImageLoad(L"HpBar", L"..\\Resources\\Image\\UI\\HpBar.bmp");

		Button* hpbar2 = new Button(eUIType::N1);
		hpbar2->SetAlphaValue(155);
		mUIs.insert(std::make_pair(eUIType::N1, hpbar2));
		hpbar2->SetPos(Vector2(400.0f, 30.0f));
		hpbar2->ImageLoad(L"HpBar2", L"..\\Resources\\Image\\UI\\HpBar2.bmp");
	

		Button* hpleft = new Button(eUIType::N2);
		mUIs.insert(std::make_pair(eUIType::N2, hpleft));
		hpleft->SetPos(Vector2(355.0f, 30.0f));
		hpleft->ImageLoad(L"HpLeft", L"..\\Resources\\Image\\UI\\HpLeft.bmp");

		GameStart* gamestart = new GameStart(eUIType::OPTION);
		mUIs.insert(std::make_pair(eUIType::OPTION, gamestart));
		gamestart->SetPos(Vector2(1000.0f, 650.0f));
		gamestart->ImageLoad(L"GameStart", L"..\\Resources\\Image\\UI\\Play.bmp");

		Editor* editor = new Editor(eUIType::EDITOR);
		mUIs.insert(std::make_pair(eUIType::EDITOR, editor));
		editor->SetPos(Vector2(50.0f, 650.0f));
		editor->ImageLoad(L"Editor", L"..\\Resources\\Image\\UI\\editor.bmp");

		Back* back = new Back(eUIType::BACK);
		mUIs.insert(std::make_pair(eUIType::BACK, back));
		back->SetPos(Vector2(1400.0f, 30.0f));
		back->ImageLoad(L"Back", L"..\\Resources\\Image\\UI\\L_Button.bmp");

	
		
	}

	void UIManager::OnLoad(eUIType type)
	{
		std::unordered_map<eUIType, UiBase*>::iterator iter = mUIs.find(type);
		if (iter == mUIs.end())
		{
			OnFail();
			return;
		}

		OnComplete(iter->second);
	}

	void UIManager::Tick()
	{
		std::stack<UiBase*> uiBases = mUIBases;
		while (!uiBases.empty())
		{
			UiBase* uiBase = uiBases.top();
			if (uiBase != nullptr)
			{
				uiBase->Tick();
			}
			uiBases.pop();
		}

		if (mRequestUIQueue.size() > 0)
		{
			//UI 로드 해줘
			eUIType requestUI = mRequestUIQueue.front();
			mRequestUIQueue.pop();

			OnLoad(requestUI);
		}
	}


	void UIManager::Render(HDC hdc)
	{
		std::stack<UiBase*> uiBases = mUIBases;
		while (!uiBases.empty())
		{
			UiBase* uiBase = uiBases.top();
			if (uiBase != nullptr)
			{
				uiBase->Render(hdc);
			}
			uiBases.pop();
		}
	}

	void UIManager::OnComplete(UiBase* addUI)
	{
		if (addUI == nullptr)
			return;

		addUI->Initialize();
		addUI->Active();
		addUI->Tick();

		if (addUI->GetIsFullScreen())
		{
			std::stack<UiBase*> uiBases = mUIBases;
			while (!uiBases.empty())
			{
				UiBase* uiBase = uiBases.top();
				uiBases.pop();

				if (uiBase->GetIsFullScreen())
				{
					uiBase->InActive();
				}
			}
		}

		mUIBases.push(addUI);
	}

	void UIManager::OnFail()
	{
		mCurrentData = nullptr;
	}

	void UIManager::Release()
	{
		for (auto ui : mUIs)
		{
			delete ui.second;
			ui.second = nullptr;
		}
	}

	void UIManager::Push(eUIType type)
	{
		mRequestUIQueue.push(type);
	}

	void UIManager::Pop(eUIType type)
	{
		if (mUIBases.size() <= 0)
			return;

		std::stack<UiBase*> tempStack;

		UiBase* uiBase = nullptr;
		while (mUIBases.size() > 0)
		{
			uiBase = mUIBases.top();
			mUIBases.pop();
			// pop하는 ui가 전체화면 일경우에,
			// 남은 ui중에 전체화면인 가장 상단의 ui 를 활성화 해주어야한다.
			if (uiBase->GetType() == type)
			{
				if (uiBase->GetIsFullScreen())
				{
					std::stack<UiBase*> uiBases = mUIBases;
					while (!uiBases.empty())
					{
						UiBase* uiBase = uiBases.top();
						uiBases.pop();

						if (uiBase->GetIsFullScreen())
						{
							uiBase->Active();
							break;
						}
					}
				}
				uiBase->InActive();
				uiBase->UIClear();
			}
			else
			{
				tempStack.push(uiBase);
			}
		}

		while (tempStack.size())
		{
			uiBase = tempStack.top();
			tempStack.pop();
			mUIBases.push(uiBase);
		}

	}

}