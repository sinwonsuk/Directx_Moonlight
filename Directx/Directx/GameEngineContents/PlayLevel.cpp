#include "PreCompile.h"
#include "PlayLevel.h"
#include "Player.h"
#include "TownMap.h"
#include "Monster.h"
#include "Random_Room.h"
#include "Dungeon_Map_01.h"
#include "Dungeon_Map_02.h"
#include "Dungeon_Map_03.h"
#include "Dungeon_Map_04.h"
#include "Dungeon_Map_05.h"
#include "Dungeon_Map_06.h"
#include "Dungeon_Map_07.h"
#include "Dungeon_Map_08.h"
#include "Dungeon_Map_09.h"
#include "Dungeon_Map_10.h"

PlayLevel::PlayLevel() 
{
}

PlayLevel::~PlayLevel() 
{
}

void PlayLevel::Start()
{

	

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();

	
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

	{
		std::shared_ptr<Player> Object = CreateActor<Player>(ContentsObjectType::Player);
	}

	{
		std::shared_ptr<Random_Room> Object = CreateActor<Random_Room>();
	}

	

	

	
	
	//{
	//	std::shared_ptr<Dungeon_Map_02> Object = CreateActor<Dungeon_Map_02>(ContentsObjectType::Player);
	//}
	//{
	//	std::shared_ptr<Dungeon_Map_03> Object = CreateActor<Dungeon_Map_03>(ContentsObjectType::Player);
	//}
	//{
	//	std::shared_ptr<Dungeon_Map_04> Object = CreateActor<Dungeon_Map_04>(ContentsObjectType::Player);
	//}
	//{
	//	std::shared_ptr<Dungeon_Map_05> Object = CreateActor<Dungeon_Map_05>(ContentsObjectType::Player);
	//}
	//{
	//	std::shared_ptr<Dungeon_Map_06> Object = CreateActor<Dungeon_Map_06>(ContentsObjectType::Player);
	//}
	//{
	//	std::shared_ptr<Dungeon_Map_07> Object = CreateActor<Dungeon_Map_07>(ContentsObjectType::Player);
	//}
	//{
	//	std::shared_ptr<Dungeon_Map_08> Object = CreateActor<Dungeon_Map_08>(ContentsObjectType::Player);
	//}
	//{
	//	std::shared_ptr<Dungeon_Map_09> Object = CreateActor<Dungeon_Map_09>(ContentsObjectType::Player);
	//}
	//{
	//	std::shared_ptr<Dungeon_Map_10> Object = CreateActor<Dungeon_Map_10>(ContentsObjectType::Player);
	//}
















	{
		//GameEngineRandom NewRanadom;
		//for (size_t i = 0; i < 10; i++)
		//{
		//	std::shared_ptr<Monster> Object = CreateActor<Monster>(ContentsObjectType::Monster);
		//	Object->Transform.SetLocalPosition(NewRanadom.RandomVectorBox2D(0, 1280, 0, -720));
		//}

		//std::shared_ptr<PlayMap> Object0 = CreateActor<PlayMap>(ContentsObjectType::Monster);
		//std::shared_ptr<PlayMap> Object1 = CreateActor<PlayMap>(ContentsObjectType::Monster);
		//std::shared_ptr<PlayMap> Object2 = CreateActor<PlayMap>(ContentsObjectType::Monster);
		//std::shared_ptr<PlayMap> Object3 = CreateActor<PlayMap>(ContentsObjectType::Monster);
	}

	/*{
		std::shared_ptr<PlayMap> Object = CreateActor<PlayMap>(ContentsObjectType::BackGround);
		Map = Object;
	}*/

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
	

	int a = 0;
}

void PlayLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	int a = 0;
}
