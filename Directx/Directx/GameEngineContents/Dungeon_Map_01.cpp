#include "PreCompile.h"
#include "Dungeon_Map_01.h"
#include "Player.h"
#include "Random_Room.h"
#include "CameraCollision.h"
#include "PlayLevel.h"
Dungeon_Map_01::Dungeon_Map_01()
{
}

Dungeon_Map_01::~Dungeon_Map_01()
{
}



void Dungeon_Map_01::Start()
{
	/*{
		std::shared_ptr<Object_jar> Object = GetLevel()->CreateActor<Object_jar>();
	}*/

	//Dungeon_Map_01* Object = (Dungeon_Map_01)(GetLevel());
	

    {
		BackGround = CreateComponent<GameEngineSpriteRenderer>(-99);
		BackGround->SetSprite("BackGround", 1);
		BackGround->SetImageScale({ 1380.0f,740.0f });
		BackGround->Transform.AddLocalPosition({ 0.0f,0.0f });
	}

	{
		Map_floor = CreateComponent<GameEngineSpriteRenderer>(-100);
		Map_floor->SetSprite("Floor_01", 0);
	}

	/*{
		Pixel = CreateComponent<GameEngineSpriteRenderer>(100);
		Pixel->SetSprite("Pixel_Floor", 0);

	}*/
	/*{
		CloseDoor = CreateComponent<GameEngineSpriteRenderer>(-100);
		CloseDoor->CreateAnimation("Close_Door", "Close_Door", 0.1f, -1, -1, false);
		CloseDoor->AutoSpriteSizeOn();
		CloseDoor->SetAutoScaleRatio(1.4f);
		CloseDoor->ChangeAnimation("Close_Door");
		CloseDoor->Transform.AddLocalRotation({ 0.0f,0.0f,-90.0f });
		CloseDoor->Transform.AddLocalPosition({ 535.0f,25.0f,0.0f });
		CloseDoor->Off();
	}

	{
		OpenDoor = CreateComponent<GameEngineSpriteRenderer>(-100);
		OpenDoor->CreateAnimation("Open_Door", "Open_Door", 0.1f, -1, -1, false);
		OpenDoor->AutoSpriteSizeOn();
		OpenDoor->SetAutoScaleRatio(1.4f);
		OpenDoor->ChangeAnimation("Open_Door");
		OpenDoor->Transform.AddLocalRotation({ 0.0f,0.0f,-90.0f });
		OpenDoor->Transform.AddLocalPosition({ 535.0f,25.0f,0.0f });
		OpenDoor->Off();
	}*/

	{
		LeftDoor = CreateComponent<GameEngineSpriteRenderer>();
		LeftDoor->CreateAnimation("Open_Door", "Open_Door", 0.1f, -1, -1, false);
		LeftDoor->CreateAnimation("Close_Door", "Close_Door", 0.1f, -1, -1, false);
		LeftDoor->AutoSpriteSizeOn();
		LeftDoor->SetAutoScaleRatio(1.4f);
		LeftDoor->ChangeAnimation("Open_Door");
		LeftDoor->Transform.AddLocalRotation({ 0.0f,0.0f,90.0f });
		LeftDoor->Transform.AddLocalPosition({ -550.0f,20.0f,0.0f });
		LeftDoor->Off();
	}

	{
		RightDoor = CreateComponent<GameEngineSpriteRenderer>();
		RightDoor->CreateAnimation("Open_Door", "Open_Door", 0.1f, -1, -1, false);
		RightDoor->CreateAnimation("Close_Door", "Close_Door", 0.1f, -1, -1, false);
		RightDoor->AutoSpriteSizeOn();
		RightDoor->SetAutoScaleRatio(1.4f);
		RightDoor->ChangeAnimation("Open_Door");
		RightDoor->Transform.AddLocalRotation({ 0.0f,0.0f,-90.0f });
		RightDoor->Transform.AddLocalPosition({ 550.0f,20.0f,0.0f });
		RightDoor->Off();

	}
	{

		UpDoor = CreateComponent<GameEngineSpriteRenderer>();
		UpDoor->CreateAnimation("Open_Door", "Open_Door", 0.1f, -1, -1, false);
		UpDoor->CreateAnimation("Close_Door", "Close_Door", 0.1f, -1, -1, false);
		UpDoor->AutoSpriteSizeOn();
		UpDoor->SetAutoScaleRatio(1.4f);
		UpDoor->ChangeAnimation("Open_Door");
		UpDoor->Transform.AddLocalPosition({ 0.0f,300.0f,0.0f });
		UpDoor->Off();
	}

	{
		DownDoor = CreateComponent<GameEngineSpriteRenderer>();
		DownDoor->CreateAnimation("Open_Door", "Open_Door", 0.1f, -1, -1, false);
		DownDoor->CreateAnimation("Close_Door", "Close_Door", 0.1f, -1, -1, false);
		DownDoor->AutoSpriteSizeOn();
		DownDoor->SetAutoScaleRatio(1.4f);
		DownDoor->ChangeAnimation("Open_Door");
		DownDoor->Transform.AddLocalRotation({ 0.0f,0.0f,180.0f });
		DownDoor->Transform.AddLocalPosition({ 0.0f,-300.0f,0.0f });
		DownDoor->Off();

	}
	{
		Boss_Door = CreateComponent<GameEngineSpriteRenderer>(10);
		Boss_Door->CreateAnimation("Boss_Door_Open", "Boss_Door_Open", 0.1f, -1, -1, false);
		Boss_Door->CreateAnimation("Boss_Door_Close", "Boss_Door_Close", 0.1f, -1, -1, false);
		Boss_Door->AutoSpriteSizeOn();
		Boss_Door->SetAutoScaleRatio(2.0f);
		Boss_Door->ChangeAnimation("Boss_Door_Close"); 
		Boss_Door->Off();
	}


	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y });
	


	Right_Collision_Door = CreateComponent<GameEngineCollision>(ContentsCollisionType::RightDoor);
	Right_Collision_Door->Transform.AddLocalPosition({ 550.0f,20.0f,0.0f });
	Right_Collision_Door->Transform.SetLocalScale({ 50.0f,120.0f,0.0f });
	Right_Collision_Door->Off(); 


	Left_Collision_Door = CreateComponent<GameEngineCollision>(ContentsCollisionType::LeftDoor);
	Left_Collision_Door->Transform.AddLocalPosition({ -550.0f,20.0f,0.0f });
	Left_Collision_Door->Transform.SetLocalScale({ 50.0f,120.0f,0.0f });
	Left_Collision_Door->Off(); 

	Top_Collision_Door = CreateComponent<GameEngineCollision>(ContentsCollisionType::TopDoor);
	Top_Collision_Door->Transform.AddLocalPosition({ 0.0f,300.0f,0.0f });
	Top_Collision_Door->Transform.SetLocalScale({ 50.0f,120.0f,0.0f });
	Top_Collision_Door->Off(); 

	Bottom_Collision_Door = CreateComponent<GameEngineCollision>(ContentsCollisionType::BottomDoor);
	Bottom_Collision_Door->Transform.AddLocalPosition({ 0.0f,-300.0f,0.0f });
	Bottom_Collision_Door->Transform.SetLocalScale({ 50.0f,120.0f,0.0f });
	Bottom_Collision_Door->Off(); 


	Boss_Collison_Door = CreateComponent<GameEngineCollision>(ContentsCollisionType::BossDoor);
	Boss_Collison_Door->Transform.SetLocalScale({ 200.0f,200.0f,0.0f });
	Boss_Collison_Door->On();

	

	Event.Enter = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
			Close_Door_Sound = GameEngineSound::SoundPlay("golem_dungeon_normal_door_closing.wav"); 
			Close_Door_Sound.SetVolume(0.2f); 
			DownDoor->ChangeAnimation("Close_Door");
			UpDoor->ChangeAnimation("Close_Door");
			RightDoor->ChangeAnimation("Close_Door");
			LeftDoor->ChangeAnimation("Close_Door");
			Boss_Door->ChangeAnimation("Boss_Door_Close");
		
		
	};

	Event.Stay = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		
			DownDoor->ChangeAnimation("Close_Door");
			UpDoor->ChangeAnimation("Close_Door");
			RightDoor->ChangeAnimation("Close_Door");
			LeftDoor->ChangeAnimation("Close_Door");
			Boss_Door->ChangeAnimation("Boss_Door_Close");
		
	};


	Event.Exit = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{

		

		
	};










}

void Dungeon_Map_01::Update(float _Delta)
{
	/*	GameEngineActor* Actor = col->GetActor();
		Spear* ptr = dynamic_cast<Spear*>(Actor);*/

	


	if (Check == false)
	{

		if (Arr.X >= 1) // 배열 벗어나지 않기 위한 조건문 
		{
			if (Random_Room::Rooms[static_cast<unsigned int>(Arr.X-1)][static_cast<unsigned int>(Arr.Y)].RoomCheck == true)
			{
				LeftDoor->On();
				Left_Collision_Door->On(); 
			}
		}
		if (Arr.X <= 7) // 배열 벗어나지 않기 위한 조건문 
		{
			if (Random_Room::Rooms[static_cast<unsigned int>(Arr.X+1)][static_cast<unsigned int>(Arr.Y)].RoomCheck == true)
			{
				RightDoor->On();
				Right_Collision_Door->On();
			}
		}
		if (Arr.Y >= 1) // 배열 벗어나지 않기 위한 조건문 
		{
			if (Random_Room::Rooms[static_cast<unsigned int>(Arr.X)][static_cast<unsigned int>(Arr.Y-1)].RoomCheck == true)
			{
				UpDoor->On();
				Top_Collision_Door->On();
			}
		}
		if (Arr.Y <= 7) // 배열 벗어나지 않기 위한 조건문 
		{
			if (Random_Room::Rooms[static_cast<unsigned int>(Arr.X)][static_cast<unsigned int>(Arr.Y+1)].RoomCheck == true)
			{
				DownDoor->On();
				Bottom_Collision_Door->On();
			}
		}


		for (size_t x = 0; x < 9; x++)
		{
			for (size_t y = 0; y < 9; y++)
			{
				if (Random_Room::Rooms[y][x].RoomCheck == true)
				{
					Boss_Door->Transform.SetWorldPosition({ Random_Room::Rooms[y][x].Pos.X, Random_Room::Rooms[y][x].Pos.Y + 300 });
					Boss_Collison_Door->Transform.SetWorldPosition({ Random_Room::Rooms[y][x].Pos.X, Random_Room::Rooms[y][x].Pos.Y + 300 });
					Boss_Door->On();
					Check = true;
					return;
				}
			}
		}
	}
	if (Player::this_Player->MonsterDeath == false)
	{
		CameraCollision::CameraCol->Col->CollisionEvent(ContentsCollisionType::Monster, Event);
	}

	if (ReturnCheck == true)
	{
		Boss_Door->Off();
		Boss_Collison_Door->Off();
		return;
	}

	if (ReturnCheck == false)
	{
		Boss_Door->On();
		Boss_Collison_Door->On();
		DoorCollision(_Delta, GetLevel()->GetMainCamera()->Transform.GetLocalPosition());
		ObjectCollision(_Delta, Pixel_Name.c_str(), Random_Room::Rooms[static_cast<unsigned int>(Arr.X)][static_cast<unsigned int>(Arr.Y)].Pos);
	}

	

	if(CameraCollision::CameraCol->Col->Collision(ContentsCollisionType::Monster) ==false && Boss_Door_Check ==false)
	{
		DownDoor->ChangeAnimation("Open_Door");
		UpDoor->ChangeAnimation("Open_Door");
		RightDoor->ChangeAnimation("Open_Door");
		LeftDoor->ChangeAnimation("Open_Door");
		Boss_Door->ChangeAnimation("Boss_Door_Open");


		if (Open_Door_Sound_Check == false)
		{
			Open_Door_Sound = GameEngineSound::SoundPlay("golem_dungeon_normal_door_opening.wav");
			Open_Door_Sound.SetVolume(0.2f);
;			Open_Door_Sound_Check = true;
		}


	}

	if (Boss_Collison_Door->Collision(ContentsCollisionType::Player) && Boss_Door_Check == false)
	{
		//Player::this_Player->Camera = CameraType::BossMap;
		CameraCollision::CameraCol->Col->Off(); 
		Player::this_Player->Transform.AddLocalPosition({ 0.0f, 300.0f });
		Boss_Door_Check = true;
		Boss_Door->ChangeAnimation("Boss_Door_Close");

		PlayLevel* Actor = dynamic_cast<PlayLevel*>(GetLevel());
		Actor->Bgm.Stop();

		Boss_Close_Door_Sound = GameEngineSound::SoundPlay("golem_dungeon_boss_door_closing.wav");


	}
	

	float4 Y_Camera_Move = float4::LerpClamp(0, 720, _Delta);

	if (Boss_Door_Check == true)
	{
		if (Boss_Door->IsCurAnimationEnd())
		{
			test = true; 
		}
	}

	if (Player::this_Player->GetLevel()->GetMainCamera()->Transform.GetLocalPosition().Y < Random_Room::Rooms[static_cast<unsigned int>(Arr.X)][static_cast<unsigned int>(Arr.Y)].Pos.Y + 720.0f && test==true)
	{
		CameraCollision::CameraCol->Col->Off();
		Player::this_Player->GetLevel()->GetMainCamera()->Transform.AddLocalPosition({ 0.0f,Y_Camera_Move.X });
	}


}
