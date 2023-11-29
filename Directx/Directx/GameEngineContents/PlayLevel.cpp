#include "PreCompile.h"
#include "PlayLevel.h"
#include "Player.h"
#include "Random_Room.h"
#include "Dungeon_Map_01.h"
#include "CameraCollision.h"
#include "Boss_Monster.h"
#include "Boss_Map.h"
#include "Inventory.h"
#include <GameEngineCore/FadePostEffect.h>
#include "Black_Out.h"
#include "Dungeon_Scrol.h"
#include "Spear.h"
#include "Player_UI.h"

PlayLevel::PlayLevel() 
{

}

PlayLevel::~PlayLevel() 
{

}
void PlayLevel::Start()
{
	GameEngineLevel::IsDebug = false;
	GameEngineCore::GetBackBufferRenderTarget()->SetClearColor({ 0, 0, 0, 1 });
	

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();

	
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

	GetMainCamera()->SetYSort(130);
	
	
	{
		//std::shared_ptr<MiniBoss> Object = CreateActor<MiniBoss>(ContentsObjectType::Player);
	}
	
	{
		//std::shared_ptr<SlimeHermit> Object = CreateActor<SlimeHermit>(ContentsObjectType::Player);
	}

	

	//{
	//	std::shared_ptr<Boss_Map> Object = CreateActor<Boss_Map>(ContentsObjectType::Player);
	//	//Object->Transform.AddLocalPosition({ 0.0f,800.0f });
	//}


	//std::shared_ptr<Monster_Place> Object = CreateActor<Monster_Place>();
	/*{
		std::shared_ptr<Player_UI> Object = CreateActor<Player_UI>(ContentsObjectType::Player);
	}
	*/

	

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

	Bgm = GameEngineSound::SoundPlay("golem_dungeon_floor.wav", 100);
	Bgm.SetVolume(0.5f);



	{
		Camera = CreateActor<CameraCollision>();
	}



	{
		adad = CreateActor<Inventory>();
	}

	{
		player = CreateActor<Player>(ContentsObjectType::Player);
		player->ChangeState(PlayerState::UpIdle);
	}
	
	{
		Map = CreateActor<Random_Room>();
	}
	{
		std::shared_ptr<Dungeon_Scrol> Object = CreateActor<Dungeon_Scrol>();
	}

	int a = 0;
}

void PlayLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	
	Bgm.Stop(); 

	if (player->Black != nullptr)
	{
		player->Black->Death();
	}
	
	Map->Rooms.clear();
	
	Map->Map->Death(); 

	Map->Boss->Monster->Death(); 
	Map->Boss->Death(); 

	for (size_t i = 0; i < Map->Maps.size(); i++)
	{
		Map->Maps[i]->Death();
		Map->Maps[i] = nullptr;
	}

	Map->Maps.clear();


	Inventory::This_Inventory->Death();
	Inventory::This_Inventory = nullptr;

	adad->Death();


	Map->Death(); 
	Map = nullptr;

	//adad->Death();

	



	//Map->Death(); 

	

	Player::this_Player->spears.clear();
	Player::this_Player->player_UI->Death();
	Player::this_Player->Death();
	Player::this_Player = nullptr;


	Camera->Death();
	player->Death();
	



}
