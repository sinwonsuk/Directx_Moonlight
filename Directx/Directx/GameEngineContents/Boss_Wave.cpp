#include "PreCompile.h"
#include "Boss_Wave.h"
#include "Player.h"
Boss_Wave::Boss_Wave()
{
}

Boss_Wave::~Boss_Wave()
{
}

void Boss_Wave::Start()
{
	Wave = CreateComponent<GameEngineSpriteRenderer>(100);
	Wave->CreateAnimation("Boss_Wave", "Boss_Wave", 0.05f, -1, -1, false);
	Wave->AutoSpriteSizeOn();
	Wave->SetAutoScaleRatio(2.0f);
	Wave->ChangeAnimation("Boss_Wave");
	Wave->Transform.AddLocalPosition({ 0.0f,-50.0f });
	//Wave->AnimationPauseOn();

	Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Boss_Wave);
	Col->Transform.SetWorldScale({ 560.0f,410.0f });
	Col->SetCollisionType(ColType::AABBBOX2D);


	Event.Enter = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		Check = true;
		/*float4 AD = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
		AD.Normalize();
		GetLevel()->GetMainCamera()->Transform.AddLocalPosition({ AD * Time * Speed });*/
	};

	Event.Stay = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{

		/*float4 AD = Transform.GetWorldPosition() - Player::this_Player->Transform.GetWorldPosition();
		AD.Normalize();
		GetLevel()->GetMainCamera()->Transform.AddLocalPosition({ AD * Time * Speed });*/
	};


	Event.Exit = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{


	};

}

void Boss_Wave::Update(float _Delta)
{
	

	if (Check == true && Wave->GetCurIndex() > 9)
	{
		Time += _Delta;

		if (Time < 0.2 && Player::this_Player->LeftMove ==true && Player::this_Player->DownMove == true && Player::this_Player->RightMove == true && Player::this_Player->UpMove == true)
		{
			Pos = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
			GetLevel()->GetMainCamera()->Transform.AddLocalPosition({ Pos.NormalizeReturn() * _Delta * Speed });
			Player::this_Player->Transform.AddLocalPosition({ Pos.NormalizeReturn() * _Delta * Speed });
		}
	}


	Col->CollisionEvent(ContentsCollisionType::Player, Event);

	

	
	if (Wave->IsCurAnimationEnd())
	{
		this->Death(); 
	}
}
