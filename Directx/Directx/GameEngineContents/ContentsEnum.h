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
	Dungeon_Entrance,
	BossMap, 
};

enum class Leveltype
{
	None,
	Town,
	Dungeon_Entrance,
	Dungeon_Death,
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
	CameraCollision,
	MiniCol,
	BossDoor,
	Boss_Wave, 
	Boss_Distance,
	Rock,
	Rock_Check_Col,
	Monster_Weapon,
	Boss_Monster,
};
