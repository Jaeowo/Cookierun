#pragma once
#include "yaGameObject.h"

namespace ya
{

	class Collider;

	class Ground :
		public GameObject
	{
	public:
		Ground();
		~Ground();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;

		void SetColPos(Vector2 ColPos) { mColPos = ColPos; }
		Vector2 GetColPos() { return mColPos; }

	private:
		Collider* mCollider;
		float mSpeed;
		Vector2 mColPos;
	};
}


