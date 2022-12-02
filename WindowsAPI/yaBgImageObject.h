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

		void SetSpeed(float Speed) { mSpeed = Speed; }
		float GetSpeed() { return mSpeed; }

	private:
		Image* mImage;
		Image* mPixelImage;
		
		float mSpeed;
	};
}
