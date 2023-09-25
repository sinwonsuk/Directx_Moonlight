#include "PreCompile.h"
#include "TutorialMap.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "TutorialLevel.h"
#include "Player.h"
#include "Object_jar.h"
#include "BabySlime.h"
#include "golem_Wizard.h"
#include "golem_Solder.h"
#include "golem_Stone.h"
TutorialMap::TutorialMap()
{
}

TutorialMap::~TutorialMap()
{
}



void TutorialMap::Start()
{
	/*{
		std::shared_ptr<Object_jar> Object = GetLevel()->CreateActor<Object_jar>();
	}*/

	
	{

	    BackGround = CreateComponent<GameEngineSpriteRenderer>(0);
	    BackGround->SetSprite("Tutorial_BackGround", 1);
	    BackGround->SetImageScale({ 1380.0f,750.0f });

	}

	{

		Map_floor_01 = CreateComponent<GameEngineSpriteRenderer>(0);
		Map_floor_01->SetSprite("Tutorial_Floor_01", 0);
	//	Map_floor_01->SetImageScale({ 1050.0f,552.0f });

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
		

	}

	{
		std::shared_ptr<BabySlime> Object = GetLevel()->CreateActor<BabySlime>();
		Object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X + 250.0f,Transform.GetWorldPosition().Y + 70.0f });

	}

	{
		std::shared_ptr<BabySlime> Object = GetLevel()->CreateActor<BabySlime>();
		Object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X + 320.0f,Transform.GetWorldPosition().Y - 30.0f });

	}

	{
		std::shared_ptr<BabySlime> Object = GetLevel()->CreateActor<BabySlime>();
		Object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X + 280.0f,Transform.GetWorldPosition().Y + 200.0f });

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

	}*/

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y});
	/*{
		std::shared_ptr<golem_Solder> Object = GetLevel()->CreateActor<golem_Solder>();
		Object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X,Transform.GetWorldPosition().Y });
	}*/
	/*{
		std::shared_ptr<golem_Wizard> Object = GetLevel()->CreateActor<golem_Wizard>();
		Object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X,Transform.GetWorldPosition().Y });
	}*/
	
	{
		std::shared_ptr<golem_Stone> Object = GetLevel()->CreateActor<golem_Stone>();
		Object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X,Transform.GetWorldPosition().Y });
	}
	

	Collision_Door = CreateComponent<GameEngineCollision>(ContentsCollisionType::Door);
	Collision_Door->Transform.AddLocalPosition({ 550.0f,20.0f,0.0f });
	Collision_Door->Transform.SetLocalScale({90.0f,120.0f,0.0f });
}

void TutorialMap::Update(float _Delta)
{
	ObjectCollision(_Delta, "Tutorial_Map_Pixel.png");

	if (GetLevel()->GetCamera(0)->Transform.GetWorldPosition().X > 1280 * (1.5 + Map_Number))
	{
		return; 
	}


	DoorCollision(_Delta, Map_Number);
	
}
