#pragma once

#define KEY_PREESE(KEY) ya::Input::GetKeyState(KEY) == ya::eKeyState::PRESSED
#define KEY_DOWN(KEY) ya::Input::GetKeyState(KEY) == ya::eKeyState::DOWN
#define KEY_UP(KEY) ya::Input::GetKeyState(KEY) == ya::eKeyState::UP

enum class eSceneType
{
	Logo,
	Title,
	Play,
	End,
	MapTool,
	JellyTool,
	Skill,
	Max,
};

enum class ePenColor
{
	Red,
	Green,
	Blue,
	End,
};

enum class eBrushColor
{
	Transparent, //≈ı∏Ì
	Blakc,
	Gray, //167 0 67
	White,
	End,
};

enum class eComponentType
{
	Rigidbody,
	Collider,
	Aimator,
	Sound,
	End,
};

#define _COLLIDER_LAYER 16
enum class eColliderLayer
{
	Default,

	//GameObject
	BackGround,
	Tile,
	Obstruction,
	Effect,
	Jelly,
	Player,
	Pet,
	Player_Projecttile,
	Monster,
	Monster_Projecttile,
	Ground,

	//UI
	BackPack,
	UI = _COLLIDER_LAYER - 1,
	End = _COLLIDER_LAYER,
};

enum class eCameraEffect
{
	FadeIn,
	FadeOut,
	None,
};

enum class eUIType
{
	N1,
	N2,
	N3,
	HP,
	MP,
	SHOP,
	INVENTORY,
	OPTION,
	SKILLBAR1,
	SKILLBAR2,

	END,
};

union ColliderID
{
	struct
	{
		UINT32 left;
		UINT32 right;
	};

	UINT64 ID;
};
typedef ColliderID TileID;

#define TILE_SIZE 50
#define TILE_SIZE_X 50
#define TILE_SIZE_Y 50
#define TILE_SCALE 1

#define TILE_LINE_X 1
#define TILE_LINE_Y 1

#define GREED_SIZE 48


