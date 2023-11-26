#include "PreCompile.h"
#include "WorldLevel.h"
#include "Player.h"
#include "TownMap.h"
#include "Shop_House.h"
#include "Black.h"
#include "Black_Out.h"
#include "Inventory.h"
#include "Black_Smith.h"
#include "Potion_NPC.h"
#include "Player_UI.h"
WorldLevel::WorldLevel()
{
}

WorldLevel::~WorldLevel()
{
}

void WorldLevel::Start()
{
	

	

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();

	GetMainCamera()->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);






	
	
	
	
	

	


}

void WorldLevel::Update(float _Delta)
{
	TransformData Date = GetMainCamera()->Transform.GetConstTransformDataRef();
}

void WorldLevel::LevelStart(GameEngineLevel* _PrevLevel)
{


	std::shared_ptr<Black> Object = CreateActor<Black>(ContentsObjectType::Player);

	{
		inventory = CreateActor<Inventory>();
	}

	{
		std::shared_ptr<Player> Object = CreateActor<Player>(ContentsObjectType::Player);	
	}

	Player::this_Player->Camera = CameraType::Town;
	Player::this_Player->ChangeState(PlayerState::DownIdle); 



	if (Player::LevelType == Leveltype::Dungeon_Entrance)
	{
		Player::this_Player->Transform.SetWorldPosition({ 15,682 });
		GetMainCamera()->Transform.SetWorldPosition({ 15,310 });
	}
	
	else if (Player::LevelType == Leveltype::Town)
	{
		Player::this_Player->Transform.SetWorldPosition({ 1040.0f,40.0f,-100.0f });
		GetMainCamera()->Transform.SetWorldPosition({ 1040.0f,40.0f });
	}

	Map = CreateActor<TownMap>(ContentsObjectType::BackGround);
	
	

	Black_smith = CreateActor<Black_Smith>(ContentsObjectType::BackGround);

	Poition = CreateActor<Potion_NPC>(ContentsObjectType::BackGround);

	int a = 0;
}

void WorldLevel::LevelEnd(GameEngineLevel* _NextLevel)
{

	Poition->Death();
	Black_smith->Death(); 
	inventory->Death();
	Map->black_Out->Death(); 
	Map->black_Out_02->Death();
	Map->Death(); 
	Player::this_Player->player_UI->Death(); 
	Player::this_Player->Death();
	Player::this_Player = nullptr;
}
