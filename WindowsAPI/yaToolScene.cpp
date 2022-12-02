#include "framework.h"
#include "WindowsAPI.h"
#include "yaToolScene.h"
#include "yaApplication.h"
#include "yaSceneManager.h"
#include "yaScene.h"
#include "yaTilePalette.h"
#include "yaImage.h"
#include "yaInput.h"
#include "yaCamera.h"


//#include "framework.h"
//#include "WindowsAPI.h"

namespace ya
{

	ToolScene::ToolScene()
        : mTileIndex(0)
	{
		mTilePalette = new TilePalette();
	}

	ToolScene::~ToolScene()
	{
		delete mTilePalette;
	}

	void ToolScene::Initialize()
	{
	}

	void ToolScene::Tick()
	{
        if (mTilePalette)
            mTilePalette->Tick();
	}

	void ToolScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		WindowData mainWidnow = Application::GetInstance().GetWindowData();

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(0, 125, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		
		int maxRow = mainWidnow.height / TILE_SIZE_Y * TILE_SCALE + 1;

		for (size_t i = 0; i < maxRow; i++)
        {
            Vector2 LinePos;
            LinePos.x = 0;
            LinePos.y = TILE_SIZE_Y * i * TILE_SCALE;

            LinePos = Camera::CalculatePos(LinePos);

            MoveToEx(hdc, LinePos.x, LinePos.y, nullptr); //���DC , ���� X , ���� Y
			LineTo(hdc, mainWidnow.width, LinePos.y); //��� DC, �� X, �� Y
		}

		int maxColumn = mainWidnow.width / TILE_SIZE_X * TILE_SCALE + 1;
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

	void ToolScene::Enter()
	{
		Application::GetInstance().SetMenuBar(true);
	}

	void ToolScene::Exit()
	{
	}
    void ToolScene::SaveTilePalette()
    {
        mTilePalette->Save();
    }
    void ToolScene::LoadTilePalette()
    {
        mTilePalette->Load();
    }
    void ToolScene::LoadTilePalette(const std::wstring& path)
    {
        mTilePalette->Load(path);
    }
}


LRESULT CALLBACK AtlasWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
    {
        WindowData windowData
            = ya::Application::GetInstance().GetWindowData();

        WindowData atlasWindowData
            = ya::Application::GetInstance().GetAtlasWindowData();

        ya::Scene* scene = ya::SceneManager::GetPlayScene();
        ya::ToolScene* toolScene = dynamic_cast<ya::ToolScene*>(scene);

        ya::Image* atlas = toolScene->GetAtalasImage();

        RECT rect = { 0, 0, atlas->GetWidth() * TILE_SCALE, atlas->GetHeight() * TILE_SCALE };
        AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
        // ������ ũ�� ����
        SetWindowPos(hWnd,
            nullptr, windowData.width, 0
            , rect.right - rect.left
            , rect.bottom - rect.top
            , 0
        );

        ShowWindow(hWnd, true);
        UpdateWindow(hWnd);

    }
    break;
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // �޴� ������ ���� �м��մϴ�:
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

            int y = mousePos.y / (TILE_SIZE_Y * TILE_SCALE);
            int x = mousePos.x / (TILE_SIZE_X * TILE_SCALE);

            int index = (y * TILE_LINE_X) + (x % TILE_LINE_X);
            ya::Scene* scene = ya::SceneManager::GetPlayScene();
            ya::ToolScene* toolScene = dynamic_cast<ya::ToolScene*>(scene);
            toolScene->SetTileIndex(index);
        }
    }
    break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        WindowData atlasWindowData
            = ya::Application::GetInstance().GetAtlasWindowData();

        ya::Scene* scene = ya::SceneManager::GetPlayScene();
        ya::ToolScene* toolScene = dynamic_cast<ya::ToolScene*>(scene);

        ya::Image* atlas = toolScene->GetAtalasImage();
        ya::Vector2 pos(ya::Vector2::Zero);

        TransparentBlt(hdc, pos.x, pos.y
            , atlas->GetWidth() * TILE_SCALE, atlas->GetHeight() * TILE_SCALE
            , atlas->GetDC(), 0, 0, atlas->GetWidth(), atlas->GetHeight()
            , RGB(255, 0, 255));

        EndPaint(hWnd, &ps);
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