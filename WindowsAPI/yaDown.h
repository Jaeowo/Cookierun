#pragma once
#include "yaGameObject.h"

namespace ya
{
	

	class Animator;
	class Image;
	class Down
		: public GameObject
	{
	public:
		Down();
		~Down();

		enum class eState
		{
			Run,
			Down
		};

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;

		int GetLength() { return mLength; }

	private:
		eState mState;
		Image* mImage;
		Animator* mAnimator;
		int mLength;
		float mSpeed;


	};
}

