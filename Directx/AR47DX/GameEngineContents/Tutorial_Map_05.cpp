#include "PreCompile.h"
#include "Tutorial_Map_05.h"
#include "BabySlime.h"
#include <GameEngineCore/GameEngineLevel.h>
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

		BackGround = CreateComponent<GameEngineSpriteRenderer>(0);
		BackGround->SetSprite("Tutorial_BackGround", 1);
		BackGround->SetImageScale({ 1380.0f,750.0f });

	}

	{
		Map_floor_01 = CreateComponent<GameEngineSpriteRenderer>(0);
		Map_floor_01->SetSprite("Tutorial_Floor_01", 0);
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

	

	
	/*{
		std::shared_ptr<BabySlime> Object = GetLevel()->CreateActor<BabySlime>();
	}

	{
		std::shared_ptr<BabySlime> Object = GetLevel()->CreateActor<BabySlime>();
	}

	{
		std::shared_ptr<BabySlime> Object = GetLevel()->CreateActor<BabySlime>();
	}

	{
		std::shared_ptr<BabySlime> Object = GetLevel()->CreateActor<BabySlime>();
	}*/


	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y });
	Transform.AddLocalPosition({ 1280 * Map_Number ,0.0f });

	

	{
		std::shared_ptr<BabySlime> Object = GetLevel()->CreateActor<BabySlime>();
		Object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X+300.0f,Transform.GetWorldPosition().Y+100.0f});
	
	}

	{
		std::shared_ptr<BabySlime> Object = GetLevel()->CreateActor<BabySlime>();
		Object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X + 250.0f,Transform.GetWorldPosition().Y + 70.0f });
		
	}

	{
		std::shared_ptr<BabySlime> Object = GetLevel()->CreateActor<BabySlime>();
		Object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X + 320.0f,Transform.GetWorldPosition().Y -30.0f });
	
	}

	{
		std::shared_ptr<BabySlime> Object = GetLevel()->CreateActor<BabySlime>();
		Object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X + 280.0f,Transform.GetWorldPosition().Y +200.0f });
		
	}

	{
		std::shared_ptr<BabySlime> Object = GetLevel()->CreateActor<BabySlime>();
		Object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X + 320.0f,Transform.GetWorldPosition().Y - 100.0f });
	
	}

	{
		std::shared_ptr<BabySlime> Object = GetLevel()->CreateActor<BabySlime>();
		Object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X + 300.0f,Transform.GetWorldPosition().Y - 70.0f });
	
	}


	{
		std::shared_ptr<BabySlime> Object = GetLevel()->CreateActor<BabySlime>();
		Object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X + 340.0f,Transform.GetWorldPosition().Y - 200.0f });
	}



	Collision_Door = CreateComponent<GameEngineCollision>(ContentsCollisionType::Door);
	Collision_Door->Transform.AddLocalPosition({ 550.0f,20.0f,0.0f });
	Collision_Door->Transform.SetLocalScale({ 90.0f,120.0f,0.0f });
}

void TutorialMap_05::Update(float _Delta)
{
	if (GetLevel()->GetMainCamera()->Transform.GetWorldPosition().X > 1280 * (1.5 + Map_Number))
	{
		return;
	}
	
	/*for (size_t i = 0; i < Slime.size(); i++)
	{
		Slime[i]->SetMove(true);
	}
*/

	DoorCollision(_Delta, Map_Number);
}
