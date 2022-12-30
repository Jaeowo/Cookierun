#pragma once
#include "yaGameObject.h"
namespace ya
{
	class Stage01
		: public GameObject
	{
	public:
		Stage01();

		void ObstructionSetting();


		bool Isit;

	private:
		int mCount;
	};
}

