#include "PreCompile.h"
#include "TutorialMap_04.h"
#include "golemturret.h"
#include <GameEngineCore/GameEngineLevel.h>
TutorialMap_04::TutorialMap_04()
{
}

TutorialMap_04::~TutorialMap_04()
{
}

void TutorialMap_04::Start()
{
	Map_Number = 3;

	{
		BackGround = CreateComponent<GameEngineSpriteRenderer>(0);
		BackGround->SetSprite("Tutorial_BackGround", 1);
		BackGround->SetImageScale({ 1380.0f,750.0f });

	}

	{
		Map_floor_01 = CreateComponent<GameEngineSpriteRenderer>(0);
		Map_floor_01->SetSprite("Tutorial_Floor_04", 0);
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


	{
		std::shared_ptr<golemturret> object = GetLevel()->CreateActor<golemturret>();
		object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X - 280.0f,Transform.GetWorldPosition().Y - 230.0f });
		object->ChangeState(golemturret_State::UpAttack);
	}

	{
		std::shared_ptr<golemturret> object = GetLevel()->CreateActor<golemturret>();
		object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X + 280.0f,Transform.GetWorldPosition().Y - 230.0f });
		object->ChangeState(golemturret_State::UpAttack);
	}

	{
		std::shared_ptr<golemturret> object = GetLevel()->CreateActor<golemturret>();
		object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X -280.0f,Transform.GetWorldPosition().Y + 250.0f });
		object->ChangeState(golemturret_State::DownAttack);
	}

	{
		std::shared_ptr<golemturret> object = GetLevel()->CreateActor<golemturret>();
		object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X + 280.0f,Transform.GetWorldPosition().Y + 250.0f });
		object->ChangeState(golemturret_State::DownAttack);
	}

	


	Collision_Door = CreateComponent<GameEngineCollision>(ContentsCollisionType::Door);
	Collision_Door->Transform.AddLocalPosition({ 550.0f,20.0f,0.0f });
	Collision_Door->Transform.SetLocalScale({ 90.0f,120.0f,0.0f });
}

void TutorialMap_04::Update(float _Delta)
{
	if (GetLevel()->GetMainCamera()->Transform.GetWorldPosition().X > 1280 * (1.5 + Map_Number))
	{
		return;
	}
	DoorCollision(_Delta, Map_Number);
}
