#include "PreCompile.h"
#include "Boss_Rock.h"
#include "Rock_Particle.h"
#include "Player.h"
Boss_Rock::Boss_Rock()
{
}

Boss_Rock::~Boss_Rock()
{
}

void Boss_Rock::Start()
{
	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, 800 });

	Rock = CreateComponent<GameEngineSpriteRenderer>(-50);
	Rock->SetSprite("Boos1_Rock", 0);
	Rock->AutoSpriteSizeOn(); 
	Rock->SetAutoScaleRatio(2.0f); 

	Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Rock);
	Col->Transform.SetWorldScale({ 70.0f,70.0f });
	Col->SetCollisionType(ColType::AABBBOX2D);

	Rock_Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
	Rock_Col->Transform.SetWorldScale({ 70.0f,70.0f });
	Rock_Col->SetCollisionType(ColType::AABBBOX2D);
	Rock_Col->Off();

	Event.Enter = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		Check = true; 
		Time2 = 0; 
	};

	Event.Stay = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		/*Pos = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
		GetLevel()->GetMainCamera()->Transform.AddLocalPosition({ Pos.NormalizeReturn() * tet * Speed });
		Player::this_Player->Transform.AddLocalPosition({ Pos.NormalizeReturn() * tet * Speed });*/
	};


	Event.Exit = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{


	};

}

void Boss_Rock::Update(float _Delta)
{
	tet = _Delta; 
	Time += _Delta; 
	
	
	int A = Random.RandomInt(0, 5);

	if (RockCheck == false)
	{
		switch (A)
		{
		case 0:
		{
			Rock->SetSprite("Boos1_Rock", A);
		}
		break;

		case 1:
		{
			Rock->SetSprite("Boos1_Rock", A);
		}
		break;
		case 2:
		{
			Rock->SetSprite("Boos1_Rock", A);
		}
		break;
		case 3:
		{
			Rock->SetSprite("Boos1_Rock", A);
		}
		break;
		case 4:
		{
			Rock->SetSprite("Boos1_Rock", A);
		}
		break;
		case 5:
		{
			Rock->SetSprite("Boos1_Rock", A);
		}
		break;

		default:
			break;
		}
		RockCheck = true; 
	}

	
	

	if (Check == true )
	{
		
		if (Time2 < 0.2)
		{
			Pos = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
			GetLevel()->GetMainCamera()->Transform.AddLocalPosition({ Pos.NormalizeReturn() * tet * Speed });
			Player::this_Player->Transform.AddLocalPosition({ Pos.NormalizeReturn() * tet * Speed });
		}

	}

	if (Time2 > 0.2)
	{
		Col->Off();
		Rock_Col->On();
	}


	float4 AD = float4::LerpClamp(0, -3000, 0.01);
	
	if (Transform.GetWorldPosition().Y >= BossPos.Y-800.0f )
	{
		
		Transform.AddWorldPosition({0.0f,AD.X});
		
	}
	else
	{
		Col->CollisionEvent(ContentsCollisionType::Rock_Check_Col, Event);
		Time2 += _Delta; 
	}

	if (Time > 5)
	{
		
		{
			std::shared_ptr<Rock_Particle> Object = GetLevel()->CreateActor<Rock_Particle>();
			Object->Transform.SetWorldPosition({ Transform.GetWorldPosition().X -20,Transform.GetWorldPosition().Y + 20 });
			Object->Set_Rock_Pos({ Transform.GetWorldPosition().X - 20,Transform.GetWorldPosition().Y + 20 });
			Object->Random.SetSeed(++Seed);
		}
		{
			std::shared_ptr<Rock_Particle> Object = GetLevel()->CreateActor<Rock_Particle>();
			Object->Transform.SetWorldPosition({ Transform.GetWorldPosition().X + 20,Transform.GetWorldPosition().Y + 20 });
			Object->Set_Rock_Pos({ Transform.GetWorldPosition().X + 20,Transform.GetWorldPosition().Y + 20 });
			Object->Random.SetSeed(++Seed);
		}
		{
			std::shared_ptr<Rock_Particle> Object = GetLevel()->CreateActor<Rock_Particle>();
			Object->Transform.SetWorldPosition({ Transform.GetWorldPosition().X - 20,Transform.GetWorldPosition().Y });
			Object->Set_Rock_Pos({ Transform.GetWorldPosition().X - 20,Transform.GetWorldPosition().Y });
			Object->Random.SetSeed(++Seed);
		}
		{
			std::shared_ptr<Rock_Particle> Object = GetLevel()->CreateActor<Rock_Particle>();
			Object->Transform.SetWorldPosition({ Transform.GetWorldPosition().X + 20,Transform.GetWorldPosition().Y });
			Object->Set_Rock_Pos({ Transform.GetWorldPosition().X + 20,Transform.GetWorldPosition().Y});
			Object->Random.SetSeed(++Seed);
		}
		

		{
			std::shared_ptr<Rock_Particle> Object = GetLevel()->CreateActor<Rock_Particle>();
			Object->Transform.SetWorldPosition({ Transform.GetWorldPosition().X - 20,Transform.GetWorldPosition().Y - 20 });
			Object->Set_Rock_Pos({ Transform.GetWorldPosition().X - 20,Transform.GetWorldPosition().Y - 20 });
			Object->Random.SetSeed(++Seed);
		}
		{
			std::shared_ptr<Rock_Particle> Object = GetLevel()->CreateActor<Rock_Particle>();
			Object->Transform.SetWorldPosition({ Transform.GetWorldPosition().X + 20,Transform.GetWorldPosition().Y - 20 });
			Object->Set_Rock_Pos({ Transform.GetWorldPosition().X + 20,Transform.GetWorldPosition().Y - 20 });
			Object->Random.SetSeed(++Seed);
		}


		this->Death(); 
	}


}
