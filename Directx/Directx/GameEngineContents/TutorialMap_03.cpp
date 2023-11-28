#include "PreCompile.h"
#include "TutorialMap_03.h"

TutorialMap_03::TutorialMap_03()
{
}

TutorialMap_03::~TutorialMap_03()
{
}

void TutorialMap_03::Start()
{
	Map_Number = 2;

	{
		BackGround = CreateComponent<GameEngineSpriteRenderer>(-100);
		BackGround->SetSprite("Tutorial_BackGround", 1);
		BackGround->SetImageScale({ 1380.0f,750.0f });
	}

	{
		Scroll = CreateComponent<GameEngineSpriteRenderer>(-100);
		Scroll->SetSprite("Cliff_Roll_Scroll.png");
		Scroll->Transform.AddLocalPosition({ 0.0f,320.0f });
	}


	{
		Map_floor_01 = CreateComponent<GameEngineSpriteRenderer>(-100);
		Map_floor_01->SetSprite("Tutorial_Floor_03", 0);
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
	}

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y });
	Transform.AddLocalPosition({ 1280* Map_Number ,0.0f });

	Collision_Door = CreateComponent<GameEngineCollision>(ContentsCollisionType::Door);
	Collision_Door->Transform.AddLocalPosition({ 550.0f,20.0f,0.0f });
	Collision_Door->Transform.SetLocalScale({ 90.0f,120.0f,0.0f });
}

void TutorialMap_03::Update(float _Delta)
{
	Sound_Time += _Delta; 



	if (GetLevel()->GetMainCamera()->Transform.GetWorldPosition().X > 1280 * (1.5 + Map_Number) + 50.0f)
	{
		Sound.Stop();
		return;
	}

	else if (GetLevel()->GetMainCamera()->Transform.GetWorldPosition().X > 1280 * (1.5 + Map_Number))
	{
		if (Sound_Time > 0.5)
		{
			Sound = GameEngineSound::SoundPlay("golem_dungeon_turret_shot.wav");
			Sound_Time = 0;
		}
		return;
	}




	if (Map_Check == 2)
	{
		ObjectCollision(_Delta, "Tutirial_Pixel_Map_03.png");
	}
	
	DoorCollision(_Delta, Map_Number);
}
