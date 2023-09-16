#include "PreCompile.h"
#include "Tutorial_Map_06.h"

TutorialMap_06::TutorialMap_06()
{
}

TutorialMap_06::~TutorialMap_06()
{
}

void TutorialMap_06::Start()
{
	Map_Number = 5;

	{

		BackGround = CreateComponent<GameEngineSpriteRenderer>(0);
		BackGround->SetSprite("Tutorial_BackGround", 1);
		BackGround->SetImageScale({ 1380.0f,750.0f });

	}

	{
		Map_floor_01 = CreateComponent<GameEngineSpriteRenderer>(0);
		Map_floor_01->SetSprite("Tutorial_Floor_06", 0);
		Map_floor_01->SetImageScale({ 1050.0f,552.0f });
	}

	{
		LeftDoor = CreateComponent<GameEngineSpriteRenderer>(0);
		LeftDoor->Transform.AddLocalRotation({ 0.0f,0.0f,90.0f });
		LeftDoor->Transform.AddLocalPosition({ -550.0f,20.0f,0.0f });
		LeftDoor->SetAutoScaleRatio(1.5f);
		LeftDoor->SetSprite("Door", 1);
	}
	{
		RightDoor = CreateComponent<GameEngineSpriteRenderer>(0);
		RightDoor->Transform.AddLocalRotation({ 0.0f,0.0f,-90.0f });
		RightDoor->Transform.AddLocalPosition({ 550.0f,20.0f,0.0f });
		RightDoor->SetAutoScaleRatio(1.5f);
		RightDoor->SetSprite("Door", 0);
	}



	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y });
	Transform.AddLocalPosition({ 1280 * Map_Number ,0.0f });

	Collision_Door = CreateComponent<GameEngineCollision>(ContentsCollisionType::Door);
	Collision_Door->Transform.AddLocalPosition({ 550.0f,20.0f,0.0f });
	Collision_Door->Transform.SetLocalScale({ 90.0f,120.0f,0.0f });
}

void TutorialMap_06::Update(float _Delta)
{
	if (GetLevel()->GetCamera(0)->Transform.GetWorldPosition().X > 1280 * (1.5 + Map_Number))
	{
		return;
	}

	//DoorCollision(_Delta, Map_Number);
}
