#include "PreCompile.h"
#include "Boss_Monster.h"
#include "Player.h"
#include "Spear_Effect.h"
#include "Boss_Monster_UI.h"
#include "Boss_Wave.h"
#include "Boss_Wirst.h"
#include "Inventory.h"
Boss_Monster::Boss_Monster()
{
}

Boss_Monster::~Boss_Monster()
{
}

void Boss_Monster::Start()
{
	Boss_UI = GetLevel()->CreateActor<Boss_Monster_UI>();
	Boss_UI->Off(); 
	Boss = CreateComponent<GameEngineSpriteRenderer>(-49);
	Boss->CreateAnimation("Wake_Up", "Wake_Up", 0.1f, -1, -1, false);
	Boss->CreateAnimation("Idle", "Idle", 0.1f, -1, -1, true);
	Boss->CreateAnimation("Death", "Death", 0.1f, -1, -1, false);
	Boss->CreateAnimation("Boss1_LaunchArm", "Boss1_LaunchArm", 0.1f, -1, -1, false);
	Boss->CreateAnimation("Boss1_IdleNoArm", "Boss1_IdleNoArm", 0.1f, -1, -1, true);
	Boss->CreateAnimation("Boss1_RecoverArm", "Boss1_RecoverArm", 0.1f, -1, -1, false);
	Boss->CreateAnimation("Boss1_Rocks_Spawn_Attack", "Boss1_Rocks_Spawn_Attack", 0.1f, -1, -1, false);
	Boss->CreateAnimation("Boss1_StickyArm_Aim2Cycle", "Boss1_StickyArm_Aim2Cycle", 0.1f, -1, -1, true);
	Boss->CreateAnimation("Boss1_StickyArm_End", "Boss1_StickyArm_End", 0.1f, -1, -1, false);
	Boss->CreateAnimation("Boss1_StickyArm_Start", "Boss1_StickyArm_Start", 0.1f, -1, -1, false);
	
	//Boss->GetColorData().PlusColor = { -1.0f,-1.0f,-1.0f,0.0f };
	Boss->AutoSpriteSizeOn();
	Boss->SetAutoScaleRatio(2.0f);
	Boss->ChangeAnimation("Wake_Up");
	Boss->AnimationPauseOn();



	Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Boss_Distance);
	Col->Transform.SetLocalScale({ 1000.0f,1000.0f });
	Col->SetCollisionType(ColType::AABBBOX2D); 

	BodyCol = CreateComponent<GameEngineCollision>(ContentsCollisionType::Boss_Monster);
	BodyCol->Transform.SetLocalScale({ 450.0f,300.0f });
	BodyCol->SetCollisionType(ColType::AABBBOX2D);

	MoveCol = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
	MoveCol->Transform.SetLocalScale({ 480.0f,330.0f });
	MoveCol->SetCollisionType(ColType::AABBBOX2D);

	Event.Enter = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		CameraCheck = true;
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


	BodyEvent.Enter = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{

			std::shared_ptr<Spear_Effect> Object = GetLevel()->CreateActor<Spear_Effect>();
			Object->Transform.SetLocalPosition(Transform.GetWorldPosition());
			Object->Set_state(Effect_State::Boss);
			

			if (Inventory::This_Inventory->Item_Renders[26]->Item_Select == 6)
			{
				Damage = 0.01;
				++UICheck;
				ColorCheck = true;
			}
			else if (Inventory::This_Inventory->Item_Renders[26]->Item_Select == 7)
			{		
				Damage = 0.05;
				++UICheck;
				ColorCheck = true;
			}

			else if (Inventory::This_Inventory->Item_Renders[26]->Item_Select == 8)
			{
				Damage = 0.03;
				++UICheck;
				ColorCheck = true;
			}
			else if (Inventory::This_Inventory->Item_Renders[26]->Item_Select == 9)
			{
				Damage = 0.04;
				++UICheck;
				ColorCheck = true;
			}

	};

	BodyEvent.Stay = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
			
	};


	BodyEvent.Exit = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		//Weapon_Collision_Check = false;
	};

}

void Boss_Monster::Update(float _Delta)
{
	Time = _Delta; 







	if (WaveCheck == true)
	{
		if (Hp >= 1.0)
		{
			Boss->GetColorData().PlusColor = { 0.0f,0.0f,0.0f,0.0f };

			if (Bosswirst != nullptr)
			{
				Bosswirst->Death();		
			}
			Boss_UI->Death();
			ChangeState(Boss_Monster_State::Death);
			return;
		}
			


		Wave_Time += _Delta;

		if (UICheck <= 0)
		{
			Boss_UI->Monster_HpBar->GetColorData().PlusColor = { 0.0f,0.0f,0.0f,0.0f };
		}

	}

	if (ColorCheck == true)
	{
		Color_Time += _Delta;

		if (Color_Time < 0.05)
		{
			Boss->GetColorData().PlusColor = { 0.0f,-1.0f,-1.0f,0.0f };
		}

		if (Color_Time <= 0.1)
		{
			if (Color_Time > 0.05)
			{
				Boss->GetColorData().PlusColor = { 1.0f,1.0f,1.0f,0.0f };
			}
		}
		
		if (Color_Time > 0.1)
		{
			Boss->GetColorData().PlusColor = { 0.0f,0.0f,0.0f,0.0f };
			Color_Time = 0; 
			ColorCheck = false;
		}

	}

	if (UICheck > 0)
	{
		Hp_Bar_reduce += _Delta/3;
		Hp += _Delta / 3;
		Boss_UI->Monster_HpBar->Transform.AddLocalScale({ -_Delta/3,0.0f });
		Boss_UI->Monster_HpBar->GetColorData().PlusColor = { 1.0f,1.0f,1.0f,0.0f };
		if (Hp_Bar_reduce > Damage)
		{
			//Hp += Hp_Bar_reduce;
			Hp_Bar_reduce = 0;
			UICheck--;
		}
	}
	






	Col->CollisionEvent(ContentsCollisionType::Player, Event);

	if (CameraCheck == true)
	{
		BodyCol->CollisionEvent(ContentsCollisionType::Spear, BodyEvent);
	}
	
	UpdateState(_Delta);


	if (Wave_Time > 5 )
	{
		std::shared_ptr<Boss_Wave> Object = GetLevel()->CreateActor<Boss_Wave>();
		Object->Transform.SetWorldPosition({Transform.GetWorldPosition()});
		Wave_Time = 0; 
		
	}


}

void Boss_Monster::AnimationCheck(const std::string_view& _AnimationName)
{
	Boss->ChangeAnimation(_AnimationName);
}

