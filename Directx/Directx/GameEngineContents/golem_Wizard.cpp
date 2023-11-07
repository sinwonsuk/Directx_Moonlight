#include "PreCompile.h"
#include "golem_Wizard.h"
#include "Player.h"
#include "Spear_Effect.h"

golem_Wizard::golem_Wizard()
{
}

golem_Wizard::~golem_Wizard()
{
}

void golem_Wizard::Start()
{
	Wizard = CreateComponent<GameEngineSpriteRenderer>(100);
	Wizard->CreateAnimation("golem_Wizard_Down_Attack", "golem_Wizard_Down_Attack", 0.1f, -1, -1, true);
	Wizard->CreateAnimation("golem_Wizard_Down_Move", "golem_Wizard_Down_Move", 0.1f, -1, -1, true);
	Wizard->CreateAnimation("golem_Wizard_Left_Attack", "golem_Wizard_Left_Attack", 0.1f, -1, -1, true);
	Wizard->CreateAnimation("golem_Wizard_Left_Move", "golem_Wizard_Left_Move", 0.1f, -1, -1, true);
	Wizard->CreateAnimation("golem_Wizard_Right_Attack", "golem_Wizard_Right_Attack", 0.1f, -1, -1, true);
	Wizard->CreateAnimation("golem_Wizard_Right_Move", "golem_Wizard_Right_Move", 0.1f, -1, -1, true);
	Wizard->CreateAnimation("golem_Wizard_Up_Attack", "golem_Wizard_Up_Attack", 0.1f, -1, -1, true);
	Wizard->CreateAnimation("golem_Wizard_Up_Move", "golem_Wizard_Up_Move", 0.1f, -1, -1, true);

	//Wizard->SetPivotType(PivotType::Bottom);

	Wizard->AutoSpriteSizeOn();
	Wizard->SetAutoScaleRatio(2.0f);
	Wizard->ChangeAnimation("golem_Wizard_Up_Move");

	

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


	Event.Enter = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		/*	GameEngineActor* Actor = col->GetActor();
			Spear* ptr = dynamic_cast<Spear*>(Actor);*/

		if (Weapon_Collision_Check == false)
		{
			std::shared_ptr<Spear_Effect> Object = GetLevel()->CreateActor<Spear_Effect>();
			Object->Transform.SetLocalPosition(Transform.GetWorldPosition());
			Monster_HpBar->Transform.AddLocalScale({ -0.1f,0.0f });
			Weapon_Collision_Check = true;
			ColorCheck = true; 
			Hp -= 10.0f;
		}

		//Hp -= 10.0f;
		Monster_BaseBar->On(); 
		Monster_HpBar->On(); 


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


	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y });

	{
		Mini_Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Monster);
		Mini_Col->Transform.SetLocalScale({ 0.0f,0.0f });
		Mini_Col->SetCollisionType(ColType::AABBBOX2D);
	}
	{
		Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::GolemWazard);
		Col->Transform.SetLocalScale({ 300.0f,300.0f });
	}
	{
		Body = CreateComponent<GameEngineCollision>(ContentsCollisionType::Monster);
		Body->Transform.SetLocalScale({ 100.0f,100.0f });
	}

}

void golem_Wizard::Update(float _Delta)
{

	if (Player::this_Player->MonsterDeath == true)
	{
		this->Death();
	}

	if (Hp <= 0)
	{
		Number -= _Delta * 1;
		Wizard->GetColorData().MulColor = { 1,1,1,Number };
		Monster_BaseBar->GetColorData().MulColor = { 1,1,1,Number };
		if (Number < 0.1)
		{
			this->Death(); 
		}


		return; 
	}

	Monster_Damage(Wizard, _Delta);



	if (Col->Collision(ContentsCollisionType::CameraCollision))
	{
		Time += _Delta;

		MonsterDir();

		MonsterPushUpdate(_Delta);

		Manager_Speed = Monster_Move(_Delta, Transform.GetWorldPosition(), MapName, Dir);

		UpdateState(_Delta);

		Body->CollisionEvent(ContentsCollisionType::Spear, Event);
	}
	Monster_Collsision(_Delta);
}
void golem_Wizard::MonsterPushUpdate(float _Delta)
{
	if (Weapon_Collision_Check == true)
	{
		PushTime_Check += _Delta;
	}


	if (Weapon_Collision_Check == true && PushTime_Check <= 0.15 && ObjectCollision(_Delta, Transform.GetWorldPosition(), MapName, Dir) == true)
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

void golem_Wizard::MonsterDir()
{
	float4 Player = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
	float4 Monster = { -1,0,0 };
	float Dot = float4::DotProduct3D(Player.NormalizeReturn(), Monster);
	float radian = atan2(Player.Y, Player.X) - atan2(Monster.Y, Monster.X);
	degree = float(abs(radian * (180.0 / 3.141592)));

}
void golem_Wizard::AnimationCheck(const std::string_view& _AnimationName)
{
	Wizard->ChangeAnimation(_AnimationName);
}

