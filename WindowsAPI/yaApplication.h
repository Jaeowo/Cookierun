#pragma once
#include "Common.h"

namespace ya
{
	// 메인 프로그램이 될 녀석
	class Application
	{
	public:
		static Application& GetInstance()
		{
			static Application mInstance;
			return mInstance;
		}

		void Initialize(WindowData data);
		void initializeAtlasWindow(WindowData data);
		void initializeJellyAtlasWindow(WindowData data);
		void Tick();

		void SetMenuBar(bool power);

		WindowData GetWindowData() { return mWindowData; }
		WindowData GetAtlasWindowData() { return mAtlasWindowData; }
		WindowData GetJellyAtlasWindowData() { return mJellyAtlasWindowData; }
		HDC GetHdc() { return mWindowData.hdc; }
		HPEN GetPen(ePenColor color) { return mPens[(UINT)color]; }
		HBRUSH GetBrush(eBrushColor color) { return mBrushes[(UINT)color]; }
		eSceneType GetPlaySceneType();


	private:
		Application();
		~Application();

		void initializeWindow(WindowData data);


	private:
		WindowData mWindowData;
		WindowData mAtlasWindowData;
		WindowData mJellyAtlasWindowData;

		HPEN mPens[(UINT)ePenColor::End];
		HBRUSH mBrushes[(UINT)eBrushColor::End];

		HMENU mMenu;
	};
}
