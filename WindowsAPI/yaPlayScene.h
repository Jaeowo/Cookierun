#pragma once
#include "yaScene.h"

namespace ya
{

	class Image;
	class Player;

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

		void Load();
		void Create();

	private:
		Image* mImage;
		Player* mPlayer;
		
		float mCount;
		std::vector<GameObject*> mJellies;
		std::vector<JellyData> mJellyDatas;
	};

}
