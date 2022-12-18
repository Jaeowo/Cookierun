#include "yaTilePalette.h"
#include "yaImage.h"
#include "yaResources.h"
#include "yaObject.h"
#include "yaToolScene.h"
#include "yaInput.h"
#include "yaCamera.h"
#include <commdlg.h>
#include "yaApplication.h"

namespace ya
{
	TilePalette::TilePalette()
	{
		mImage
			= Resources::Load<Image>(L"Tile", L"..\\Resources\\Image\\Tile1.bmp");
	}

	TilePalette::~TilePalette()
	{
	}

	void TilePalette::Tick()
	{
		if (KEY_PREESE(eKeyCode::LBTN))
		{
			if (GetFocus())
			{
				eSceneType type = ya::Application::GetInstance().GetPlaySceneType();
				if (type == eSceneType::MapTool)
				{
					ya::Vector2  mousePos = ya::Input::GetMousePos();
					ya::Vector2  cameraPos = ya::Camera::GetLookPos();

					int y = (mousePos.y + cameraPos.y) / (TILE_SIZE_Y * TILE_SCALE);
					int x = (mousePos.x + cameraPos.x) / (TILE_SIZE_X * TILE_SCALE);

					ya::Scene* scene = ya::SceneManager::GetPlayScene();
					ya::ToolScene* toolScene = dynamic_cast<ya::ToolScene*>(scene);
					UINT index = toolScene->GetTileIndex();

					CrateTile(index, Vector2(x, y));
				}
				else if (type == eSceneType::JellyTool)
				{
					int a = 0;
				}
			}
		}
	}

	void TilePalette::Render(HDC hdc)
	{

	}

	void TilePalette::CrateTile(UINT index, Vector2 indexPos)
	{
		TileID key;
		key.left = indexPos.x;
		key.right = indexPos.y;

		std::unordered_map<UINT64, Tile*>::iterator iter = mTiles.find(key.ID);
		if (iter != mTiles.end())
		{
			iter->second->SetIndex(index);
		}

		//이부분때문에 자꾸 이상하게 출력된다.
		Vector2 objectPos;

		objectPos.x = indexPos.x * (TILE_SIZE_X * TILE_SCALE);
		objectPos.y = indexPos.y * (TILE_SIZE_Y * TILE_SCALE);

		Tile* tile = object::Instantiate<Tile>(objectPos, eColliderLayer::Tile);
		tile->Initiailize(mImage, index);

		mTiles.insert(std::make_pair(key.ID, tile));
	}

	void TilePalette::Save()
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
		ofn.lpstrFilter = L"Tile\0*.tile\0";
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

		std::unordered_map<UINT64, Tile*>::iterator iter = mTiles.begin();
		for (; iter != mTiles.end(); ++iter)
		{
			int tileIndex = (*iter).second->GetIndex();
			fwrite(&tileIndex, sizeof(int), 1, pFile);

			TileID id;
			id.ID = (*iter).first;
			fwrite(&id.ID, sizeof(UINT64), 1, pFile);
		}

		fclose(pFile);
	}

	void TilePalette::Load()
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
			int tileIndex = 0;
			TileID id;

			if (fread(&tileIndex, sizeof(int), 1, pFile) == NULL)
				break;

			if (fread(&id.ID, sizeof(UINT64), 1, pFile) == NULL)
				break;

			CrateTile(tileIndex, Vector2(id.left, id.right));
		}

		fclose(pFile);
	}

	void TilePalette::Load(const std::wstring& path)
	{
		FILE* pFile = nullptr;
		_wfopen_s(&pFile, path.c_str(), L"rb");
		if (pFile == nullptr)
			return;

		while (true)
		{
			int tileIndex = 0;
			TileID id;

			if (fread(&tileIndex, sizeof(int), 1, pFile) == NULL)
				break;

			if (fread(&id.ID, sizeof(UINT64), 1, pFile) == NULL)
				break;

			CrateTile(tileIndex, Vector2(id.left, id.right));
		}

		fclose(pFile);
	}
}
