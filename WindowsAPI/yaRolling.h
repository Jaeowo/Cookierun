#pragma once
#include "yaGameObject.h"

namespace ya
{

	class Animator;
	class Image;

    class Rolling :
        public GameObject
    {
	public:
		Rolling(Vector2 pos);
		Rolling();
		~Rolling();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;

		enum class eState
		{
			None,
			Away,
		};


	private:
		Image* mImage;
		Animator* mAnimator;
		float mSpeed;
		int mLength;
		Vector2 RollingPos;
		eState mState;
	
    };

}


