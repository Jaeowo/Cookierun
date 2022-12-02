#pragma once
#include "yaScene.h"

namespace ya
{

	class Image;
	class Player;
	class Squirrel;

	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Tick() override;
		void Render(HDC hdc) override;

		virtual void Enter();
		virtual void Exit();

	private:
		Image* mImage;
		Player* mPlayer;
		Squirrel* mSquirrel;
	};

}
