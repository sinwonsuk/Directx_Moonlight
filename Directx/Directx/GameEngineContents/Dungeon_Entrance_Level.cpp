#include "PreCompile.h"
#include "Dungeon_Entrance_Level.h"
#include "Player.h"
#include "Dungeon_Entrance_Map.h"
Dungeon_Entrance_Level::Dungeon_Entrance_Level()
{


}

Dungeon_Entrance_Level::~Dungeon_Entrance_Level()
{


}

void Dungeon_Entrance_Level::Start()
{
	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();

	GetMainCamera()->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

	{
		std::shared_ptr<Dungeon_Entrance_Map> Object = CreateActor<Dungeon_Entrance_Map>();
	}
}

void Dungeon_Entrance_Level::Update(float _Delta)
{


}

void Dungeon_Entrance_Level::LevelStart(GameEngineLevel* _PrevLevel)
{



	{
		std::shared_ptr<Player> Object = CreateActor<Player>(ContentsObjectType::Player);
		//Object->Transform.AddLocalPosition({ 55.0f,-200.0f });
	}

	Player::this_Player->Camera = CameraType::Dungeon_Entrance;


	Player::this_Player->Transform.SetWorldPosition({1228.0f,-1796 });

	GetMainCamera()->Transform.SetWorldPosition({ 1228.0f,-1599 });
}

void Dungeon_Entrance_Level::LevelEnd(GameEngineLevel* _NextLevel)
{
	Player::LevelType = Leveltype::Dungeon_Entrance;
	Player::this_Player->Death();
	Player::this_Player = nullptr;
}
