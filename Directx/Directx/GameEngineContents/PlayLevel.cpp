#include "PreCompile.h"
#include "PlayLevel.h"
#include "Player.h"
#include "TownMap.h"
#include "Monster.h"
#include "Random_Room.h"
#include "Dungeon_Map_01.h"
#include "SlimeHermit.h"
#include "MiniBoss.h"
#include "Player_UI.h"
#include "Monster_place.h"
#include "CameraCollision.h"
PlayLevel::PlayLevel() 
{
}

PlayLevel::~PlayLevel() 
{
}

void PlayLevel::Start()
{
	//GameEngineLevel::IsDebug = false;
	//GameEngineCore::GetBackBufferRenderTarget()->SetClearColor({ 0, 0, 0, 1 });
	

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();

	
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);


	{
		std::shared_ptr<CameraCollision> Object = CreateActor<CameraCollision>();
	}


	


	{
		//std::shared_ptr<SlimeHermit> Object = CreateActor<SlimeHermit>(ContentsObjectType::Player);
	}
	{
		//std::shared_ptr<MiniBoss> Object = CreateActor<MiniBoss>(ContentsObjectType::Player);
	}


	//std::shared_ptr<Monster_Place> Object = CreateActor<Monster_Place>();
	{
		std::shared_ptr<Player_UI> Object = CreateActor<Player_UI>(ContentsObjectType::Player);
	}
	

	

}

void PlayLevel::Update(float _Delta)
{
	//Player::this_Player->CameraCheck = true;
	//static float Time = 0.0f;
	//Time += _Delta;

	//if (nullptr != Map && 3.0f <= Time)
	//{
	//	Map->Death();
	//	Map = nullptr;
	//	// Map = nullptr;
	//}
}

void PlayLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	{
		player = CreateActor<Player>(ContentsObjectType::Player);
	}
	
	{
		Map = CreateActor<Random_Room>();
	}


	int a = 0;
}

void PlayLevel::LevelEnd(GameEngineLevel* _NextLevel)
{

	player->Death(); 

	for (size_t i = 0; i < Map->Maps.size(); i++)
	{
		Map->Maps[i]->Death();
	}


	Map->Rooms.clear();

	Map->Maps.clear(); 



	Map->Death(); 
	Player::this_Player->Death();
	Player::this_Player = nullptr;

}
