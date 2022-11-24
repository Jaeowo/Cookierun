#pragma once
#include "yaGameObject.h"


namespace ya
{
	class Image;
	class BgImageObject : public GameObject
	{
	public:
		BgImageObject();
		~BgImageObject();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		void SetImage(const std::wstring& key ,const std::wstring& fileName);

		/*void BgMoveX(int XMove);
		int GetXMove(){ return mXMove; }
		void SetXMove(int XMove) { mXMove = XMove; }*/

	private:
		Image* mImage;
		Image* mPixelImage;
		/*int mXMove;*/
	};
}
