#include "PreCompile.h"
#include "golem_Solder.h"
#include "Player.h"
#include <GameEngineCore/GameEngineLevel.h>
#include "Spear_Effect.h"
golem_Solder::golem_Solder()
{

}

golem_Solder::~golem_Solder()
{
}

void golem_Solder::Start()
{
	Solder = CreateComponent<GameEngineSpriteRenderer>(100);
	Solder->CreateAnimation("GolemSolder_Attack_Down", "GolemSolder_Attack_Down", 0.1f, -1, -1, false);
	Solder->CreateAnimation("GolemSoldier_Move_Down", "GolemSoldier_Move_Down", 0.1f, -1, -1, true);
	Solder->CreateAnimation("GolemSolder_Attack_Left", "GolemSolder_Attack_Left", 0.1f, -1, -1, false);
	Solder->CreateAnimation("GolemSoldier_Move_Left", "GolemSoldier_Move_Left", 0.1f, -1, -1, true);
	Solder->CreateAnimation("GolemSolder_Attack_Right", "GolemSolder_Attack_Right", 0.1f, -1, -1, false);
	Solder->CreateAnimation("GolemSoldier_Move_Right", "GolemSoldier_Move_Right", 0.1f, -1, -1, true);
	Solder->CreateAnimation("GolemSolder_Attack_Up", "GolemSolder_Attack_Up", 0.1f, -1, -1, false);
	Solder->CreateAnimation("GolemSoldier_Move_Up", "GolemSoldier_Move_Up", 0.1f, -1, -1, true);



	Solder->AutoSpriteSizeOn();
	Solder->SetAutoScaleRatio(2.0f);
	Solder->ChangeAnimation("GolemSoldier_Move_Down");

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y });

	{
		Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::GolemSolder);
		Col->Transform.SetLocalScale({ 100.0f,100.0f }); 

	}

	
	Event.Enter = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		test = true;

		GameEngineActor* Object = col->GetActor();
		Spear* ptr = dynamic_cast<Spear*>(Object);
		ptr->Col->Off();
		
		


	};

	Event.Stay = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		test = false;
	};


	Event.Exit = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		// 
		test = false;

	};




	

}

void golem_Solder::Update(float _Delta)
{
	Col->CollisionEvent(ContentsCollisionType::Spear, Event);
	
	if (test == true)
	{
		std::shared_ptr<Spear_Effect> Object = GetLevel()->CreateActor<Spear_Effect>();
		Object->Transform.SetLocalPosition(Transform.GetWorldPosition());
		test = false;
	}




	float4 Player = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
	float4 Monster = { -1,0,0 };
	float Dot = float4::DotProduct3D(Player.NormalizeReturn(), Monster);
	float radian = atan2(Player.Y, Player.X) - atan2(Monster.Y, Monster.X);
	degree = abs(radian * (180.0 / 3.141592));


	Time += _Delta;

	UpdateState(_Delta);
}

void golem_Solder::AnimationCheck(const std::string_view& _AnimationName)
{
	Solder->ChangeAnimation(_AnimationName);
}
