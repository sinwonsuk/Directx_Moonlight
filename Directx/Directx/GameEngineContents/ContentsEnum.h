#pragma once

enum class ContentsRenderType
{
	BackGround,
	Play,
};


enum class ContentsObjectType
{
	BackGround,
	Player,
	Monster,
	spear,
};

enum class TitleOrder
{
	Title,
};

enum class CameraType
{
	None,
	Town,
	Dungeon_Entrance
};

enum class Leveltype
{
	None,
	Town,
	Dungeon_Entrance,
};


enum class ContentsCollisionType
{
	Player,
	Monster,
	Door, 
	BabySlime,
	GolemStone,
	GolemSolder,
	GolemWazard, 
	GolemWazard_Body,
	Spear, 
	Object,
	ObjectCollision,
	ShopDoor, 
	House,
	Town,
	Dungeon_Entrance,
	Dungeon_Near, 

	LeftDoor,
	RightDoor,
	TopDoor,
	BottomDoor, 

};
