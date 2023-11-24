#include "PreCompile.h"
#include "SlimeHermit.h"
#include "Player.h"
#include <GameEngineCore/GameEngineLevel.h>
#include "Spear_Effect.h"
#include "Inventory.h"
SlimeHermit::SlimeHermit()
{

}

SlimeHermit::~SlimeHermit()
{

}


void SlimeHermit::Start()
{
	Transform.AddLocalPosition({ 0.0f,50.0f }); 
	Slime_Hermit = CreateComponent<GameEngineSpriteRenderer>(100);
	Slime_Hermit->CreateAnimation("SlimeHermit_Attack_Down", "SlimeHermit_Attack_Down", 0.1f, -1, -1, false);
	Slime_Hermit->CreateAnimation("SlimeHermit_Move_Down", "SlimeHermit_Move_Down", 0.1f, -1, -1, true);
	Slime_Hermit->CreateAnimation("SlimeHermit_Attack_Left", "SlimeHermit_Attack_Left", 0.1f, -1, -1, false);
	Slime_Hermit->CreateAnimation("SlimeHermit_Move_Left", "SlimeHermit_Move_Left", 0.1f, -1, -1, true);
	Slime_Hermit->CreateAnimation("SlimeHermit_Attack_Right", "SlimeHermit_Attack_Right", 0.1f, -1, -1, false);
	Slime_Hermit->CreateAnimation("SlimeHermit_Move_Right", "SlimeHermit_Move_Right", 0.1f, -1, -1, true);
	Slime_Hermit->CreateAnimation("SlimeHermit_Attack_Up", "SlimeHermit_Attack_Up", 0.1f, -1, -1, false);
	Slime_Hermit->CreateAnimation("SlimeHermit_Move_Up", "SlimeHermit_Move_Up", 0.1f, -1, -1, true);


	//Slime_Hermit->SetPivotType(PivotType::RightBottom);
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



	Slime_Hermit->AutoSpriteSizeOn();
	Slime_Hermit->SetAutoScaleRatio(2.0f);
	Slime_Hermit->ChangeAnimation("SlimeHermit_Move_Down");




	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();

	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y });

	{
		Monster_Weapon = CreateComponent<GameEngineCollision>(ContentsCollisionType::Monster_Weapon);
		Monster_Weapon->Transform.SetLocalScale({ 100.0f,100.0f });
		Monster_Weapon->SetCollisionType(ColType::AABBBOX2D);
		Monster_Weapon->On();
	}

	{
		Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Monster);
		Col->Transform.SetLocalScale({ 100.0f,100.0f }); 
		Col->SetCollisionType(ColType::AABBBOX2D);
	}
	
	
	Event.Enter = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
	

		if (Weapon_Collision_Check == false)
		{
			std::shared_ptr<Spear_Effect> Object = GetLevel()->CreateActor<Spear_Effect>();
			Object->Transform.SetLocalPosition(Transform.GetWorldPosition());

			if (Inventory::This_Inventory->Item_Renders[26]->Item_Select == 6)
			{
				Monster_HpBar->Transform.AddLocalScale({ -0.3f,0.0f });
				Hp -= 30.0f;
			}
			else if (Inventory::This_Inventory->Item_Renders[26]->Item_Select == 7)
			{
				Monster_HpBar->Transform.AddLocalScale({ -0.4f,0.0f });
				Hp -= 40.0f;
			}
			else if (Inventory::This_Inventory->Item_Renders[26]->Item_Select == 8)
			{
				Monster_HpBar->Transform.AddLocalScale({ -0.2f,0.0f });
				Hp -= 20.0f;
			}

			Weapon_Collision_Check = true;
			ColorCheck = true;
		}

		Monster_BaseBar->On();
		Monster_HpBar->On();
		
	};

	Event.Stay = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		
		

	};


	Event.Exit = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		
	};


	{
		Mini_Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Monster);
		Mini_Col->Transform.SetLocalScale({ 20.0f,20.0f });
		Mini_Col->SetCollisionType(ColType::AABBBOX2D);
	}
	
}

void SlimeHermit::Update(float _Delta)
{

	if (Player::this_Player->MonsterDeath == true)
	{
		this->Death();
	}

	if (Hp <= 0)
	{
		Monster_HpBar->Transform.SetLocalScale({ 0.0f,0.0f });

		Monster_Weapon->Off();
		Number -= _Delta * 1;
		Slime_Hermit->GetColorData().MulColor = { 1,1,1,Number };
		Monster_BaseBar->GetColorData().MulColor = { 1,1,1,Number };
		if (Number < 0.1)
		{
			this->Off();
		}


		return;
	}

	Monster_Damage(Slime_Hermit, _Delta);
	

	if (Col->Collision(ContentsCollisionType::CameraCollision))
	{
		Time += _Delta;

		MonsterDir();

		Manager_Speed = Monster_Move(_Delta, Transform.GetWorldPosition(), MapName, Dir);

		MonsterPushUpdate(_Delta);
		UpdateState(_Delta);

		Col->CollisionEvent(ContentsCollisionType::Spear, Event);
	}


	Monster_Collsision(_Delta);

	if (Number < -0.5)
	{
		this->Death();
	}

}


void SlimeHermit::MonsterDir()
{
	float4 Player = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
	float4 Monster = { -1,0,0 };
	float Dot = float4::DotProduct3D(Player.NormalizeReturn(), Monster);
	float radian = atan2(Player.Y, Player.X) - atan2(Monster.Y, Monster.X);
	degree = float(abs(radian * (180.0 / 3.141592)));
}



void SlimeHermit::MonsterPushUpdate(float _Delta)
{
	if (Inventory::This_Inventory->Item_Renders[26] != nullptr)
	{
		if (Inventory::This_Inventory->Item_Renders[26]->Item_Select == 6)
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
		else if (Inventory::This_Inventory->Item_Renders[26]->Item_Select == 7)
		{
			if (Weapon_Collision_Check == true)
			{
				PushTime_Check += _Delta;
			}


			if (Weapon_Collision_Check == true && PushTime_Check <= 0.15 && ObjectCollision(_Delta, Transform.GetWorldPosition(), MapName, Dir) == true)
			{
				if (Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Down_Attack_01)
				{
					Transform.AddLocalPosition({ float4::DOWN * PushSpeed * _Delta });
				}
				else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Down_Attack_02)
				{
					Transform.AddLocalPosition({ float4::DOWN * PushSpeed * _Delta });
				}
				else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Down_Attack_03)
				{
					Transform.AddLocalPosition({ float4::DOWN * PushSpeed * _Delta });
				}

				else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Left_Attack_01)
				{
					Transform.AddLocalPosition({ float4::LEFT * PushSpeed * _Delta });
				}
				else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Left_Attack_02)
				{
					Transform.AddLocalPosition({ float4::LEFT * PushSpeed * _Delta });
				}
				else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Left_Attack_03)
				{
					Transform.AddLocalPosition({ float4::LEFT * PushSpeed * _Delta });
				}


				else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Up_Attack_01)
				{
					Transform.AddLocalPosition({ float4::UP * PushSpeed * _Delta });
				}
				else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Up_Attack_02)
				{
					Transform.AddLocalPosition({ float4::UP * PushSpeed * _Delta });
				}
				else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Up_Attack_03)
				{
					Transform.AddLocalPosition({ float4::UP * PushSpeed * _Delta });
				}

				else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Right_Attack_01)
				{
					Transform.AddLocalPosition({ float4::RIGHT * PushSpeed * _Delta });
				}
				else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Right_Attack_02)
				{
					Transform.AddLocalPosition({ float4::RIGHT * PushSpeed * _Delta });
				}
				else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Right_Attack_03)
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
		else if (Inventory::This_Inventory->Item_Renders[26]->Item_Select == 8)
		{
			if (Weapon_Collision_Check == true)
			{
				PushTime_Check += _Delta;
			}


			if (Weapon_Collision_Check == true && PushTime_Check <= 0.15 && ObjectCollision(_Delta, Transform.GetWorldPosition(), MapName, Dir) == true)
			{
				if (Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Down_Attack_01)
				{
					Transform.AddLocalPosition({ float4::DOWN * PushSpeed * _Delta });
				}
				else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Down_Attack_02)
				{
					Transform.AddLocalPosition({ float4::DOWN * PushSpeed * _Delta });
				}
				else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Down_Attack_03)
				{
					Transform.AddLocalPosition({ float4::DOWN * PushSpeed * _Delta });
				}

				else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Left_Attack_01)
				{
					Transform.AddLocalPosition({ float4::LEFT * PushSpeed * _Delta });
				}
				else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Left_Attack_02)
				{
					Transform.AddLocalPosition({ float4::LEFT * PushSpeed * _Delta });
				}
				else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Left_Attack_03)
				{
					Transform.AddLocalPosition({ float4::LEFT * PushSpeed * _Delta });
				}


				else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Up_Attack_01)
				{
					Transform.AddLocalPosition({ float4::UP * PushSpeed * _Delta });
				}
				else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Up_Attack_02)
				{
					Transform.AddLocalPosition({ float4::UP * PushSpeed * _Delta });
				}
				else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Up_Attack_03)
				{
					Transform.AddLocalPosition({ float4::UP * PushSpeed * _Delta });
				}

				else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Right_Attack_01)
				{
					Transform.AddLocalPosition({ float4::RIGHT * PushSpeed * _Delta });
				}
				else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Right_Attack_02)
				{
					Transform.AddLocalPosition({ float4::RIGHT * PushSpeed * _Delta });
				}
				else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Right_Attack_03)
				{
					Transform.AddLocalPosition({ float4::RIGHT * PushSpeed * _Delta });
				}
			}

			if (PushTime_Check > 0.3)
			{
				PushTime_Check = 0;
				Weapon_Collision_Check = false;
			}
		}
	}

}
void SlimeHermit::AnimationCheck(const std::string_view& _AnimationName)
{
	Slime_Hermit->ChangeAnimation(_AnimationName);
}
