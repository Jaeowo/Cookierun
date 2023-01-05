#pragma once

namespace ya
{
	class Player;

	class GameObjectManager
	{
	public:
		static void SetPlayer(Player* player) { mPlayer = player; }
		static Player* GetPlayer() { return mPlayer; }
		
	private:
		static Player* mPlayer;
	};

}

