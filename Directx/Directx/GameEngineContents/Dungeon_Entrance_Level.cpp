#include "PreCompile.h"
#include "Dungeon_Entrance_Level.h"
#include "Player.h"
#include "Dungeon_Entrance_Map.h"
#include "Black.h"
#include "Black_Out.h"
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

	



}

void Dungeon_Entrance_Level::Update(float _Delta)
{


}

void Dungeon_Entrance_Level::LevelStart(GameEngineLevel* _PrevLevel)
{
	std::shared_ptr<Black> Object = CreateActor<Black>(ContentsObjectType::Player);


	{
		std::shared_ptr<Player> Object = CreateActor<Player>(ContentsObjectType::Player);
		Player::this_Player->ChangeState(PlayerState::UpIdle);
	}

	Player::this_Player->Camera = CameraType::Dungeon_Entrance;


	Player::this_Player->Transform.SetWorldPosition({1228.0f,-1796 });

	GetMainCamera()->Transform.SetWorldPosition({ 1228.0f,-1599 });


	{
		Entrance_Map = CreateActor<Dungeon_Entrance_Map>();
	}
}

void Dungeon_Entrance_Level::LevelEnd(GameEngineLevel* _NextLevel)
{
	Entrance_Map->black_Out_02->Death(); 
	Entrance_Map->black_Out->Death();
	Entrance_Map->Death();
	
	Player::this_Player->Death();
	Player::this_Player = nullptr;
}
