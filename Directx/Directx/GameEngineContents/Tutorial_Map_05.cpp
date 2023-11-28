#include "PreCompile.h"
#include "Tutorial_Map_05.h"
#include "BabySlime.h"
#include <GameEngineCore/GameEngineLevel.h>
#include "Player.h"
TutorialMap_05::TutorialMap_05()
{
}

TutorialMap_05::~TutorialMap_05()
{
}

void TutorialMap_05::Start()
{
	Map_Number = 4;

	{

		BackGround = CreateComponent<GameEngineSpriteRenderer>(-100);
		BackGround->SetSprite("Tutorial_BackGround", 1);
		BackGround->SetImageScale({ 1380.0f,750.0f });

	}

	{
		Map_floor_01 = CreateComponent<GameEngineSpriteRenderer>(-100);
		Map_floor_01->SetSprite("Tutorial_Floor_01", 0);
		Map_floor_01->SetImageScale({ 1050.0f,552.0f });
	}

	{
		LeftDoor = CreateComponent<GameEngineSpriteRenderer>(-100);
		LeftDoor->Transform.AddLocalRotation({ 0.0f,0.0f,90.0f });
		LeftDoor->Transform.AddLocalPosition({ -550.0f,20.0f,0.0f });
		LeftDoor->SetAutoScaleRatio(1.5f);
		LeftDoor->SetSprite("Door", 1);
	}
	{
		RightDoor = CreateComponent<GameEngineSpriteRenderer>(-100);
		RightDoor->Transform.AddLocalRotation({ 0.0f,0.0f,-90.0f });
		RightDoor->Transform.AddLocalPosition({ 550.0f,20.0f,0.0f });
		RightDoor->SetAutoScaleRatio(1.5f);
		RightDoor->SetSprite("Door", 0);
		RightDoor->On(); 
	}

	{
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
	}


	
	{
		Scroll_Attack = CreateComponent<GameEngineSpriteRenderer>(-100);
		Scroll_Attack->SetSprite("Attack_Roll_Scroll.png");
		Scroll_Attack->Transform.AddLocalPosition({ -200.0f,320.0f });
	}
	
	{
		Scroll_Portion = CreateComponent<GameEngineSpriteRenderer>(-100);
		Scroll_Portion->SetSprite("Portion_Roll_Scroll.png");
		Scroll_Portion->Transform.AddLocalPosition({ 200.0f,320.0f });
	}

	

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y });
	Transform.AddLocalPosition({ 1280 * Map_Number ,0.0f });

	//sd.X - 640 + Monster_Pos.X * 40, sd.Y + 360 - Monster_Pos.Y * 40

	{
		
		std::shared_ptr<BabySlime> Object = GetLevel()->CreateActor<BabySlime>();
		Object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X+300.0f,Transform.GetWorldPosition().Y+100.0f});	
		Object->Set_MapName("Tutirial_Pixel_Map_01.png"); 
		Object->Set_Dir({ 1280 * Map_Number,0.0f });
		Slimes.push_back(Object);
	}

	{
		std::shared_ptr<BabySlime> Object = GetLevel()->CreateActor<BabySlime>();
		Object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X + 250.0f,Transform.GetWorldPosition().Y + 70.0f });
		Object->Set_MapName("Tutirial_Pixel_Map_01.png");
		Object->Set_Dir({ 1280 * Map_Number,0.0f });
		Slimes.push_back(Object);
	}

	{
		std::shared_ptr<BabySlime> Object = GetLevel()->CreateActor<BabySlime>();
		Object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X + 320.0f,Transform.GetWorldPosition().Y -30.0f });
		Object->Set_MapName("Tutirial_Pixel_Map_01.png");
		Object->Set_Dir({ 1280 * Map_Number,0.0f });
		Slimes.push_back(Object);
	}

	{
		std::shared_ptr<BabySlime> Object = GetLevel()->CreateActor<BabySlime>();
		Object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X + 280.0f,Transform.GetWorldPosition().Y +200.0f });
		Object->Set_MapName("Tutirial_Pixel_Map_01.png");
		Object->Set_Dir({ 1280 * Map_Number,0.0f });
		Slimes.push_back(Object);
	}

	{
		std::shared_ptr<BabySlime> Object = GetLevel()->CreateActor<BabySlime>();
		Object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X + 320.0f,Transform.GetWorldPosition().Y - 100.0f });
		Object->Set_MapName("Tutirial_Pixel_Map_01.png");
		Object->Set_Dir({ 1280 * Map_Number,0.0f });
		Slimes.push_back(Object);
	}

	{
		std::shared_ptr<BabySlime> Object = GetLevel()->CreateActor<BabySlime>();
		Object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X + 300.0f,Transform.GetWorldPosition().Y - 70.0f });
		Object->Set_MapName("Tutirial_Pixel_Map_01.png");
		Object->Set_Dir({ 1280 * Map_Number,0.0f });
		Slimes.push_back(Object);
	
	}


	{
		std::shared_ptr<BabySlime> Object = GetLevel()->CreateActor<BabySlime>();
		Object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X + 340.0f,Transform.GetWorldPosition().Y - 200.0f });
		Object->Set_MapName("Tutirial_Pixel_Map_01.png");
		Object->Set_Dir({ 1280 * Map_Number,0.0f });
		Slimes.push_back(Object);
	}










	Collision_Door = CreateComponent<GameEngineCollision>(ContentsCollisionType::Door);
	Collision_Door->Transform.AddLocalPosition({ 550.0f,20.0f,0.0f });
	Collision_Door->Transform.SetLocalScale({ 90.0f,120.0f,0.0f });
	Collision_Door->Off(); 
}

void TutorialMap_05::Update(float _Delta)
{

	if (Player::this_Player->Transform.GetWorldPosition().X > 5550 )
	{
		if (Close_Sound_Check == false)
		{
			Close_Sound = GameEngineSound::SoundPlay("golem_dungeon_normal_door_closing.wav");
			Close_Sound_Check = true; 
		}
		CloseDoor->On(); 
	}
	for (size_t i = 0; i < Slimes.size(); i++)
	{
		if (Slimes[i]->GetHp() <= 0)
		{
			++Slime_Check; 
		}
	}

	if (Slime_Check == 7)
	{
		OpenDoor->On();
		CloseDoor->Off(); 
		Collision_Door->On(); 


		if (Open_Sound_Check == false)
		{
			Close_Sound = GameEngineSound::SoundPlay("golem_dungeon_normal_door_opening.wav");
			Open_Sound_Check = true;
		}

	}

	Slime_Check = 0; 


	if (GetLevel()->GetMainCamera()->Transform.GetWorldPosition().X > 1280 * (1.5 + Map_Number))
	{
		return;
	}

	if (Map_Check == 4)
	{
		ObjectCollision(_Delta, "Tutirial_Pixel_Map_01.png");
	}
	

	DoorCollision(_Delta, Map_Number);
}
