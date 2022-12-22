#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Image;
	class Animator;
	class Colollider;

	class LeafFlower :
		public GameObject
	{
	public:
		enum class eState
		{
			Wait,
			Bloom,
		};

	public:
		void SetState(eState state) { mState = state; }
		eState GetState() { return mState; }
		void Bloom();

	public:
		LeafFlower();
		~LeafFlower();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;

		void SetColPos(Vector2 ColPos) { mColPos = ColPos; }
		Vector2 GetColPos() { return mColPos; }


	private:
		Image* mImage;
		Animator* mAnimator;
		float mSpeed;
		eState mState;
		int mCount;
		Collider* mCollider;
		Vector2 mColPos;
	};
}