#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Animator;
	class Image;

	class LobbieCookie
		: public GameObject
	{
	public:
		LobbieCookie();
		~LobbieCookie();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

	private:
		Image* mImage;
		Animator* mAnimator;
	};
}

