#include "PreCompile.h"
#include "Boss_Monster.h"
#include "Player.h"
Boss_Monster::Boss_Monster()
{
}

Boss_Monster::~Boss_Monster()
{
}

void Boss_Monster::Start()
{
	Boss = CreateComponent<GameEngineSpriteRenderer>(100);
	Boss->CreateAnimation("Wake_Up", "Wake_Up", 0.1f, -1, -1, false);
	Boss->CreateAnimation("Idle", "Idle", 0.1f, -1, -1, true);
	Boss->CreateAnimation("Death", "Death", 0.1f, -1, -1, true);	
	Boss->AutoSpriteSizeOn();
	Boss->SetAutoScaleRatio(2.0f);
	Boss->ChangeAnimation("Wake_Up");
	Boss->AnimationPauseOn(); 


	Col = CreateComponent<GameEngineCollision>();
	Col->Transform.SetLocalScale({ 1000.0f,1000.0f });
	Col->SetCollisionType(ColType::AABBBOX2D); 

	Event.Enter = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		float4 AD = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
		AD.Normalize(); 

		GetLevel()->GetMainCamera()->Transform.AddLocalPosition({ AD * Time * Speed });
	};

	Event.Stay = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		float4 AD = Transform.GetWorldPosition() - Player::this_Player->Transform.GetWorldPosition();
		AD.Normalize();

		GetLevel()->GetMainCamera()->Transform.AddLocalPosition({ AD * Time * Speed });
	};


	Event.Exit = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{


	};
}

void Boss_Monster::Update(float _Delta)
{
	Time = _Delta; 
	Col->CollisionEvent(ContentsCollisionType::Player, Event);
}

void Boss_Monster::AnimationCheck(const std::string_view& _AnimationName)
{
	Boss->ChangeAnimation(_AnimationName);
}
