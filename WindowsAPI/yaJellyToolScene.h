#pragma once
#include "yaScene.h"
#include "yaTilePalette.h"

namespace ya
{
	struct JellyData
	{
		Vector2 pos;
		UINT type;
	};

	enum class eJellyType
	{
		BigBear,
		IceBear,
		PinkBear,
		YellowBear,
		RainbowBear,
		GoldCoin,
		SilverCoin,
		Jelly,

		Max,
	};

	class Image;
	class JellyToolScene : public Scene
	{
	public:




		JellyToolScene();
		~JellyToolScene();

		void Initialize() override;
		void Tick() override;
		void Render(HDC hdc) override;

		virtual void Enter();
		virtual void Exit();

		void Save();
		void Load();
		void Create();

		void Load(const std::wstring& path);

	private:
		eJellyType mJellyType;

		Image* mBGImage;
		GameObject* mCurrentJelly;

		std::vector<GameObject*> mJellies;
		std::vector<JellyData> mJellyDatas;
	};
}