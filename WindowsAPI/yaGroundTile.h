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

	private:
		float mSpeed;
		Image* mImage;
	};

}

