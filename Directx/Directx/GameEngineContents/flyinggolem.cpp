#include "PreCompile.h"
#include "flyinggolem.h"
#include "Spear.h"
#include "Spear_Effect.h"
#include "Player.h"
#include "Inventory.h"
#include "Items.h"

flyinggolem::flyinggolem()
{
}

flyinggolem::~flyinggolem()
{
}

void flyinggolem::MonsterPushUpdate(float _Delta)
{
	if (Inventory::This_Inventory->Item_Renders[26] != nullptr)
	{
		if (Inventory::This_Inventory->Item_Renders[26]->Item_Select == 6 || Inventory::This_Inventory->Item_Renders[26]->Item_Select == 9)
		{
			if (Weapon_Collision_Check == true)
			{
				PushTime_Check += _Delta;
			}


			if (Weapon_Collision_Check == true && PushTime_Check <= 0.15 )
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

			if (PushTime_Check > 0.4)
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


			if (Weapon_Collision_Check == true && PushTime_Check <= 0.15)
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


			if (Weapon_Collision_Check == true && PushTime_Check <= 0.15)
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

void flyinggolem::Start()
{
	Monster = CreateComponent<GameEngineSpriteRenderer>(130);



	Monster->CreateAnimation("flyinggolem", "flyinggolem", 0.1f, -1, -1, true);

	Monster->AutoSpriteSizeOn();
	Monster->SetAutoScaleRatio(2.0f);
	Monster->ChangeAnimation("flyinggolem");


	{
		Monster_BaseBar = CreateComponent<GameEngineSpriteRenderer>(130);
		Monster_BaseBar->SetSprite("MonsterUI", 0);
		Monster_BaseBar->SetPivotType(PivotType::Left);
		Monster_BaseBar->Transform.AddLocalPosition({ -30.0f,60.0f });
		Monster_BaseBar->Off();
	}

	{
		Monster_HpBar = CreateComponent<GameEngineSpriteRenderer>(130);
		Monster_HpBar->SetSprite("MonsterUI", 1);
		Monster_HpBar->SetPivotType(PivotType::Left);
		Monster_HpBar->Transform.AddLocalPosition({ -30.0f,60.0f });
		Monster_HpBar->Off();
	}


	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y });

	{
		Mini_Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Monster);
		Mini_Col->Transform.SetLocalScale({ 30.0f,30.0f });
		Mini_Col->SetCollisionType(ColType::AABBBOX2D);
	}


	{
		Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Monster);
		Col->Transform.SetLocalScale({ 15.0f,15.0f });
	}

	{
		Monster_Weapon = CreateComponent<GameEngineCollision>(ContentsCollisionType::Monster_Weapon);
		Monster_Weapon->Transform.SetLocalScale({ 15.0f,15.0f });

	}
	Event.Enter = [this](GameEngineCollision* Col, GameEngineCollision* col)
		{

			if (Weapon_Collision_Check == false)
			{
				std::shared_ptr<Spear_Effect> Object = GetLevel()->CreateActor<Spear_Effect>();
				Object->Transform.SetLocalPosition(Transform.GetWorldPosition());

				Death_Sound = GameEngineSound::SoundPlay("golem_dungeon_golem_hit.wav");

				if (Inventory::This_Inventory->Item_Renders[26]->Item_Select == 6)
				{
					Monster_HpBar->Transform.AddLocalScale({ -0.5f,0.0f });
					Hp -= 50.0f;
				}
				else if (Inventory::This_Inventory->Item_Renders[26]->Item_Select == 7)
				{
					Monster_HpBar->Transform.AddLocalScale({ -1.0f,0.0f });
					Hp -= 100.0f;
				}

				else if (Inventory::This_Inventory->Item_Renders[26]->Item_Select == 8)
				{
					Monster_HpBar->Transform.AddLocalScale({ -0.6f,0.0f });
					Hp -= 60.0f;
				}
				else if (Inventory::This_Inventory->Item_Renders[26]->Item_Select == 9)
				{
					Monster_HpBar->Transform.AddLocalScale({ -0.8f,0.0f });
					Hp -= 80.0f;
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


	
}

void flyinggolem::Update(float _Delta)
{
	if (Player::this_Player->MonsterDeath == true)
	{
		this->Death();
	}

	Monster_Damage(Monster, _Delta);

	DeltaTime = _Delta;

	if (Hp <= 0)
	{

		if (Death_Sound_Check == false)
		{
			Death_Sound = GameEngineSound::SoundPlay("enemy_death.wav");
			Death_Sound.SetVolume(2.5f);
			Death_Sound_Check = true;
		}



		Monster_HpBar->Transform.SetLocalScale({ 0.0f,0.0f });

		Monster_Weapon->Off();
		Number -= _Delta * 1;
		Monster->GetColorData().MulColor = { 1,1,1,Number };
		Monster_BaseBar->GetColorData().MulColor = { 1,1,1,Number };


		if (Number < 0.1)
		{
			for (size_t i = 0; i < 4; i++)
			{

				int Itemss = Random.RandomInt(0, 4);
				Random.SetSeed(Player::RandomSeed++);

				std::shared_ptr<Items> Object = GetLevel()->CreateActor<Items>();
				Object->Transform.SetWorldPosition({ Transform.GetWorldPosition() });
				Object->Set_Monster_Pos({ Transform.GetWorldPosition() });
				Object->Dir = Dir;



				Object->Set_item_Select(static_cast<Item>(Itemss));


			}

			this->Off();
		}
		return;
	}


	if (Col->Collision(ContentsCollisionType::CameraCollision))
	{
		MonsterPushUpdate(_Delta);
		UpdateState(_Delta);
		Col->CollisionEvent(ContentsCollisionType::Spear, Event);
		Manager_Speed = Monster_Move(_Delta, Transform.GetWorldPosition(), MapName, Dir);
	}

	if (Number < -0.5)
	{
		this->Death();
	}
}
