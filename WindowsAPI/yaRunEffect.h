#pragma once
#include "yaGameObject.h"

namespace ya
{
	class RunEffect :
		public GameObject
	{
	public:
		RunEffect();
		~RunEffect();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;

	private:
		Image* mImage;
		float mSpeed;

	};
}


