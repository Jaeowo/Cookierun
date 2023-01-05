#pragma once
#include "yaScene.h"

namespace ya
{
	class Image;
	class Player;
	class Sound;

	class SkillScene : public Scene
	{
	public:
		SkillScene();
		~SkillScene();

		void Initialize() override;
		void Tick() override;
		void Render(HDC hdc) override;

		virtual void Enter();
		virtual void Exit();

	

	private:
		Sound* mSound;
		Image* mImage;
		Player* mPlayer;
		float mExitCount;
	};
}


