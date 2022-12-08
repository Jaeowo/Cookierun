#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Image;
	class GroundTile :
		public GameObject
	{
	public:
		GroundTile();
		~GroundTile();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		void SetCount(int Count) { mCount = Count; }
		int GetCount() { return mCount; }
	

	private:
		float mSpeed;
		Image* mImage;
		int mCount;
	};

}

