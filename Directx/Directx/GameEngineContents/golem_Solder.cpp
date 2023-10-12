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

	{
		Monster_BaseBar = CreateComponent<GameEngineSpriteRenderer>(101);
		Monster_BaseBar->SetSprite("MonsterUI", 0);
		Monster_BaseBar->SetPivotType(PivotType::Left);
		Monster_BaseBar->Transform.AddLocalPosition({ -30.0f,60.0f });
		Monster_BaseBar->Off(); 
	}

	{
		Monster_HpBar = CreateComponent<GameEngineSpriteRenderer>(101);
		Monster_HpBar->SetSprite("MonsterUI", 1);
		Monster_HpBar->SetPivotType(PivotType::Left);
		Monster_HpBar->Transform.AddLocalPosition({ -30.0f,60.0f });
		Monster_HpBar->Off();
	}



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
	

		if( Weapon_Collision_Check ==false)
		{
			std::shared_ptr<Spear_Effect> Object = GetLevel()->CreateActor<Spear_Effect>();
			Object->Transform.SetLocalPosition(Transform.GetWorldPosition());
			Monster_HpBar->Transform.AddLocalScale({ -0.1f,0.0f });
			Weapon_Collision_Check = true;
			Hp -= 10.0f;
		}

		Monster_BaseBar->On();
		Monster_HpBar->On();

		//Hp -= 10.0f;
		
		


		/*GameEngineActor* Actor = col->GetActor();
		Spear* ptr = dynamic_cast<Spear*>(Actor);
		ptr->Col->Off();*/
	};

	Event.Stay = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		
		

	};


	Event.Exit = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		/*Monster_BaseBar->Off();
		Monster_HpBar->Off();*/
	};


}

void golem_Solder::Update(float _Delta)
{

	if (Hp <= 0)
	{
		this->Off();
		return;
	}

	Time += _Delta;

	MonsterDir(); 
	


	MonsterPushUpdate(_Delta);
	UpdateState(_Delta);

	Col->CollisionEvent(ContentsCollisionType::Spear, Event);
}


void golem_Solder::MonsterDir()
{
	float4 Player = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
	float4 Monster = { -1,0,0 };
	float Dot = float4::DotProduct3D(Player.NormalizeReturn(), Monster);
	float radian = atan2(Player.Y, Player.X) - atan2(Monster.Y, Monster.X);
	degree = abs(radian * (180.0 / 3.141592));
}



void golem_Solder::MonsterPushUpdate(float _Delta)
{
	if (Weapon_Collision_Check == true)
	{
		PushTime_Check += _Delta;
	}


	if (Weapon_Collision_Check == true && PushTime_Check <= 0.15)
	{


		if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Down_Attack_01)
		{
			Transform.AddLocalPosition({ float4::DOWN * PushSpeed * _Delta });
		}
		else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Down_Attack_02)
		{
			Transform.AddLocalPosition({ float4::DOWN * PushSpeed * _Delta });
		}
		else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Down_Attack_03)
		{
			Transform.AddLocalPosition({ float4::DOWN * PushSpeed * _Delta });
		}

		else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Left_Attack_01)
		{
			Transform.AddLocalPosition({ float4::LEFT * PushSpeed * _Delta });
		}
		else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Left_Attack_02)
		{
			Transform.AddLocalPosition({ float4::LEFT * PushSpeed * _Delta });
		}
		else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Left_Attack_03)
		{
			Transform.AddLocalPosition({ float4::LEFT * PushSpeed * _Delta });
		}


		else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Up_Attack_01)
		{
			Transform.AddLocalPosition({ float4::UP * PushSpeed * _Delta });
		}
		else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Up_Attack_02)
		{
			Transform.AddLocalPosition({ float4::UP * PushSpeed * _Delta });
		}
		else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Up_Attack_03)
		{
			Transform.AddLocalPosition({ float4::UP * PushSpeed * _Delta });
		}

		else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Right_Attack_01)
		{
			Transform.AddLocalPosition({ float4::RIGHT * PushSpeed * _Delta });
		}
		else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Right_Attack_02)
		{
			Transform.AddLocalPosition({ float4::RIGHT * PushSpeed * _Delta });
		}
		else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Right_Attack_03)
		{
			Transform.AddLocalPosition({ float4::RIGHT * PushSpeed * _Delta });
		}



	}

	if (PushTime_Check > 0.55)
	{
		PushTime_Check = 0;
		Weapon_Collision_Check = false;
	}

}
void golem_Solder::AnimationCheck(const std::string_view& _AnimationName)
{
	Solder->ChangeAnimation(_AnimationName);
}
