#include "PreCompile.h"
#include "TutorialMap_02.h"

TutorialMap_02::TutorialMap_02()
{
}

TutorialMap_02::~TutorialMap_02()
{
}

void TutorialMap_02::Start()
{
	{

		BackGround = CreateComponent<GameEngineSpriteRenderer>(-100);
		BackGround->SetSprite("Tutorial_BackGround", 1);
		BackGround->SetImageScale({ 1380.0f,750.0f });

	}

	{
		Scroll = CreateComponent<GameEngineSpriteRenderer>(-100);
		Scroll->SetSprite("Roll_Scroll.png");
		Scroll->Transform.AddLocalPosition({ 0.0f,320.0f }); 
	}

	{
		Map_floor_01 = CreateComponent<GameEngineSpriteRenderer>(-100);
		Map_floor_01->SetSprite("Tutorial_Floor_02", 0);
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
	Transform.AddLocalPosition({ 1280,0.0f }); 

	Collision_Door = CreateComponent<GameEngineCollision>(ContentsCollisionType::Door);
	Collision_Door->Transform.AddLocalPosition({ 550.0f,20.0f,0.0f });
	Collision_Door->Transform.SetLocalScale({ 90.0f,120.0f,0.0f });
	
	Map_Number = 1; 
}

void TutorialMap_02::Update(float _Delta)
{
	
	if (GetLevel()->GetMainCamera()->Transform.GetWorldPosition().X > 1280 * (1.5 + Map_Number))
	{
		return;
	}
	
	
	DoorCollision(_Delta, Map_Number);


	
	
}
