#include "framework.h"
#include "WindowsAPI.h"
#include <commdlg.h>
#include "yaJellyToolScene.h"
#include "yaApplication.h"
#include "yaSceneManager.h"
#include "yaScene.h"
#include "yaTilePalette.h"
#include "yaImage.h"
#include "yaInput.h"
#include "yaCamera.h"
#include "yaBigBear.h"
#include "yaIceBear.h"
#include "yaPinkBear.h"
#include "yaYellowBear.h"
#include "yaRainbowBear.h"
#include "yaGoldCoin.h"
#include "yaSilverCoin.h"
#include "yaJelly.h"
#include "yaObject.h"

#include "yaStage01.h"
#include "yaStage02.h"

//#include "framework.h"
//#include "WindowsAPI.h"

namespace ya
{
	JellyToolScene::JellyToolScene()
	{
		//Stage01* stage01 = new Stage01();
		//stage01->ObstructionSetting();

		Stage02* stage02 = new Stage02();
		stage02->ObstructionSetting();
	}

	JellyToolScene::~JellyToolScene()
	{

	}

	void JellyToolScene::Initialize()
	{
		Camera::SetTarget(nullptr);

		/*mCurrentJelly
			= object::Instantiate<BigBear>(eColliderLayer::Jelly);
		mCurrentJelly->SetPos(Vector2(200, 200));*/




	}

	void JellyToolScene::Tick()
	{
		Scene::Tick();

		

		if (KEY_DOWN(eKeyCode::LBTN))
		{
			if (GetFocus())
			{
				Vector2 mousePos = Input::GetMousePos();
				Vector2 pos = Camera::CalculateToolPos(mousePos);
				GameObject* jelly = nullptr;
				switch (mJellyType)
				{
				case ya::JellyToolScene::eJellyType::BigBear:
				{
					jelly
						= object::Instantiate<BigBear>(eColliderLayer::Jelly);
					jelly->mJellyType = (UINT)eJellyType::BigBear;
				}
				break;
				case ya::JellyToolScene::eJellyType::IceBear:
				{
					jelly
						= object::Instantiate<IceBear>(eColliderLayer::Jelly);
					jelly->mJellyType = (UINT)eJellyType::IceBear;
				}
				break;
				case ya::JellyToolScene::eJellyType::PinkBear:
				{
					jelly
						= object::Instantiate<PinkBear>(eColliderLayer::Jelly);
					jelly->mJellyType = (UINT)eJellyType::PinkBear;
				}
				break;
				case ya::JellyToolScene::eJellyType::YellowBear:
				{
					jelly
						= object::Instantiate<YellowBear>(eColliderLayer::Jelly);
					jelly->mJellyType = (UINT)eJellyType::YellowBear;
				}
				break;
				case ya::JellyToolScene::eJellyType::RainbowBear:
				{
					jelly
						= object::Instantiate<RainbowBear>(eColliderLayer::Jelly);
					jelly->mJellyType = (UINT)eJellyType::RainbowBear;
				}
				break;
				case ya::JellyToolScene::eJellyType::GoldCoin:
				{
					jelly
						= object::Instantiate<GoldCoin>(eColliderLayer::Jelly);
					jelly->mJellyType = (UINT)eJellyType::GoldCoin;
				}
				break;
				case ya::JellyToolScene::eJellyType::SilverCoin:
				{
					jelly
						= object::Instantiate<SilverCoin>(eColliderLayer::Jelly);
					jelly->mJellyType = (UINT)eJellyType::SilverCoin;
				}
				break;
				case ya::JellyToolScene::eJellyType::Jelly:
				{
					jelly
						= object::Instantiate<Jelly>(eColliderLayer::Jelly);
					jelly->mJellyType = (UINT)eJellyType::Jelly;
				}
				break;
				case ya::JellyToolScene::eJellyType::Max:
					break;
				default:
					break;
				}
				jelly->SetPos(pos);
				mJellies.push_back(jelly);
			}
		}

		if (KEY_DOWN(eKeyCode::P))
		{
			UINT jellyType = ((UINT)mJellyType) + 1;
			if (jellyType == (UINT)eJellyType::Max)
			{
				mJellyType = eJellyType::BigBear;
			}
			else
			{
				mJellyType = (eJellyType)jellyType;
			}
		}

		if (KEY_DOWN(eKeyCode::N_1))
		{
			mJellyType = eJellyType::BigBear;
		}

		if (KEY_DOWN(eKeyCode::N_2))
		{
			mJellyType = eJellyType::IceBear;
		}

		if (KEY_DOWN(eKeyCode::N_3))
		{
			mJellyType = eJellyType::PinkBear;
		}

		if (KEY_DOWN(eKeyCode::N_4))
		{
			mJellyType = eJellyType::YellowBear;
		}

		if (KEY_DOWN(eKeyCode::N_5))
		{
			mJellyType = eJellyType::RainbowBear;
		}

		if (KEY_DOWN(eKeyCode::N_6))
		{
			mJellyType = eJellyType::GoldCoin;
		}

		if (KEY_DOWN(eKeyCode::N_7))
		{
			mJellyType = eJellyType::SilverCoin;
		}

		if (KEY_DOWN(eKeyCode::N_8))
		{
			mJellyType = eJellyType::Jelly;
		}



		if (KEY_DOWN(eKeyCode::S))
		{
			Save();
		}
		if (KEY_DOWN(eKeyCode::D))
		{
			Load();
			Create();
		}
	}

	void JellyToolScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	WindowData mainWidnow = Application::GetInstance().GetWindowData();

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(0, 125, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		
		int maxRow = mainWidnow.height / TILE_SIZE * TILE_SCALE + 1;
		for (size_t i = 0; i < maxRow; i++)
		{
			Vector2 LinePos;
			LinePos.x = 0;
			LinePos.y = TILE_SIZE_Y * i * TILE_SCALE;
			LinePos = Camera::CalculatePos(LinePos);

			MoveToEx(hdc, LinePos.x, LinePos.y, nullptr);
			LineTo(hdc, mainWidnow.width, LinePos.y);
		}

		int maxColumn = mainWidnow.width / TILE_SIZE * TILE_SCALE + 150;
		for (size_t i = 0; i < maxColumn; i++)
		{
			Vector2 LinePos;
			LinePos.x = TILE_SIZE_X * i * TILE_SCALE;
			LinePos.y = 0;
			LinePos = Camera::CalculatePos(LinePos);
			MoveToEx(hdc, LinePos.x, LinePos.y, nullptr);
			LineTo(hdc, LinePos.x, mainWidnow.height);
		}

		(HPEN)SelectObject(hdc, oldPen);
		DeleteObject(redPen);

	}

	void JellyToolScene::Enter()
	{
		Application::GetInstance().SetMenuBar(true);
	}

	void JellyToolScene::Exit()
	{
	}

	void JellyToolScene::Save()
	{
		// open a file name
		OPENFILENAME ofn = {};

		wchar_t szFilePath[256] = {};

		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[0] = '\0';
		ofn.nMaxFile = 256;
		ofn.lpstrFilter = L"Jelly\0*.jelly\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (false == GetSaveFileName(&ofn))
			return;

		FILE* pFile = nullptr;
		_wfopen_s(&pFile, szFilePath, L"wb");
		if (pFile == nullptr)
			return;

		for (GameObject* obj : mJellies)
		{
			UINT type = obj->mJellyType;
			fwrite(&type, sizeof(UINT), 1, pFile);
			Vector2 pos = obj->GetPos();
			fwrite(&pos.x, sizeof(int), 1, pFile);
			fwrite(&pos.y, sizeof(int), 1, pFile);
		}

		fclose(pFile);
	}

	void JellyToolScene::Load()
	{
		{
			OPENFILENAME ofn = {};

			wchar_t szFilePath[256] = {};

			ZeroMemory(&ofn, sizeof(ofn));
			ofn.lStructSize = sizeof(ofn);
			ofn.hwndOwner = NULL;
			ofn.lpstrFile = szFilePath;
			ofn.lpstrFile[0] = '\0';
			ofn.nMaxFile = 256;
			ofn.lpstrFilter = L"All\0*.*\0Text\0*.TXT\0";
			ofn.nFilterIndex = 1;
			ofn.lpstrFileTitle = NULL;
			ofn.nMaxFileTitle = 0;
			ofn.lpstrInitialDir = NULL;
			ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

			if (false == GetOpenFileName(&ofn))
				return;

			FILE* pFile = nullptr;
			_wfopen_s(&pFile, szFilePath, L"rb");
			if (pFile == nullptr)
				return;

			while (true)
			{
				JellyData data;
				if (fread(&data.type, sizeof(int), 1, pFile) == NULL)
					break;

				if (fread(&data.pos.x, sizeof(int), 1, pFile) == NULL)
					break;

				if (fread(&data.pos.y, sizeof(int), 1, pFile) == NULL)
					break;

				mJellyDatas.push_back(data);

			}
			fclose(pFile);
		}
	}
	void JellyToolScene::Create()
	{
		for (JellyData data : mJellyDatas)
		{

			GameObject* jelly = nullptr;
			switch ((eJellyType)data.type)
			{
			case ya::JellyToolScene::eJellyType::BigBear:
			{
				jelly
					= object::Instantiate<BigBear>(eColliderLayer::Jelly);
				jelly->mJellyType = (UINT)eJellyType::BigBear;
			}
			break;
			case ya::JellyToolScene::eJellyType::IceBear:
			{
				jelly
					= object::Instantiate<IceBear>(eColliderLayer::Jelly);
				jelly->mJellyType = (UINT)eJellyType::IceBear;
			}
			break;
			case ya::JellyToolScene::eJellyType::PinkBear:
			{
				jelly
					= object::Instantiate<PinkBear>(eColliderLayer::Jelly);
				jelly->mJellyType = (UINT)eJellyType::PinkBear;
			}
			break;
			case ya::JellyToolScene::eJellyType::YellowBear:
			{
				jelly
					= object::Instantiate<YellowBear>(eColliderLayer::Jelly);
				jelly->mJellyType = (UINT)eJellyType::YellowBear;
			}
			break;
			case ya::JellyToolScene::eJellyType::RainbowBear:
			{
				jelly
					= object::Instantiate<RainbowBear>(eColliderLayer::Jelly);
				jelly->mJellyType = (UINT)eJellyType::RainbowBear;
			}
			break;
			case ya::JellyToolScene::eJellyType::GoldCoin:
			{
				jelly
					= object::Instantiate<GoldCoin>(eColliderLayer::Jelly);
				jelly->mJellyType = (UINT)eJellyType::GoldCoin;
			}
			break;
			case ya::JellyToolScene::eJellyType::SilverCoin:
			{
				jelly
					= object::Instantiate<SilverCoin>(eColliderLayer::Jelly);
				jelly->mJellyType = (UINT)eJellyType::SilverCoin;
			}
			break;
			case ya::JellyToolScene::eJellyType::Jelly:
			{
				jelly
					= object::Instantiate<Jelly>(eColliderLayer::Jelly);
				jelly->mJellyType = (UINT)eJellyType::Jelly;
			}
			break;
			case ya::JellyToolScene::eJellyType::Max:
				break;
			default:
				break;
			}
			jelly->SetPos(data.pos);
			mJellies.push_back(jelly);
		}
	}
	void JellyToolScene::Load(const std::wstring& path)
	{
		FILE* pFile = nullptr;
		_wfopen_s(&pFile, path.c_str(), L"rb");
		if (pFile == nullptr)
			return;

		while (true)
		{
			JellyData data;
			if (fread(&data.type, sizeof(int), 1, pFile) == NULL)
				break;

			if (fread(&data.pos.x, sizeof(int), 1, pFile) == NULL)
				break;

			if (fread(&data.pos.y, sizeof(int), 1, pFile) == NULL)
				break;

			mJellyDatas.push_back(data);

		}
		fclose(pFile);
	}
}


LRESULT CALLBACK JellyAtlasWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
	{
		WindowData windowData
			= ya::Application::GetInstance().GetWindowData();

		WindowData atlasWindowData
			= ya::Application::GetInstance().GetJellyAtlasWindowData();

		ya::Scene* scene = ya::SceneManager::GetPlayScene();
		ya::JellyToolScene* toolScene = dynamic_cast<ya::JellyToolScene*>(scene);

		//ya::Image* atlas = toolScene->GetAtalasImage();

		//RECT rect = { 0, 0, atlas->GetWidth() * TILE_SCALE, atlas->GetHeight() * TILE_SCALE };
		//AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
		//// 윈도우 크기 변경
		//SetWindowPos(hWnd,
		//    nullptr, windowData.width, 0
		//    , rect.right - rect.left
		//    , rect.bottom - rect.top
		//    , 0
		//);

		ShowWindow(hWnd, true);
		UpdateWindow(hWnd);

	}
	break;
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// 메뉴 선택을 구문 분석합니다:
		switch (wmId)
		{
		case IDM_ABOUT:
			//DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
		{
			int a = 0;
		}
		break;

		case ID_TILE_SAVE:
			//DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
		{
			int a = 0;
		}
		break;

		case ID_TILE_LOAD:
			//DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
		{
			int a = 0;
		}
		break;
		//case IDM_EXIT:
		//    DestroyWindow(hWnd);
		//    break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;

	case WM_LBUTTONDOWN:
	{
		if (GetFocus())
		{
			ya::Vector2  mousePos = ya::Input::GetMousePos(hWnd);

			//int y = mousePos.y / (TILE_SIZE_Y * TILE_SCALE);
			//int x = mousePos.x / (TILE_SIZE_X * TILE_SCALE);

			//int index = (y * TILE_LINE_X) + (x % TILE_LINE_X);
			//ya::Scene* scene = ya::SceneManager::GetPlayScene();
			//ya::JellyToolScene* toolScene = dynamic_cast<ya::JellyToolScene*>(scene);
			//toolScene->SetTileIndex(index);
		}
	}
	break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		WindowData atlasWindowData
			= ya::Application::GetInstance().GetJellyAtlasWindowData();

		ya::Scene* scene = ya::SceneManager::GetPlayScene();
		ya::JellyToolScene* toolScene = dynamic_cast<ya::JellyToolScene*>(scene);

		//ya::Image* atlas = toolScene->GetAtalasImage();
		//ya::Vector2 pos(ya::Vector2::Zero);

		//TransparentBlt(hdc, pos.x, pos.y
		//    , atlas->GetWidth() * TILE_SCALE, atlas->GetHeight() * TILE_SCALE
		//    , atlas->GetDC(), 0, 0, atlas->GetWidth(), atlas->GetHeight()
		//    , RGB(255, 0, 255));

		//EndPaint(hWnd, &ps);
	}
	break;

	case WM_DESTROY:
	{
		PostQuitMessage(0);
		//KillTimer(hWnd, 0);
	}
	break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}