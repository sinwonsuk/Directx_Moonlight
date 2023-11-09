#include "PreCompile.h"
#include "Player.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "TownMap.h"
#include "Monster.h"
#include "ContentsEnum.h"
#include "Player_UI.h"
Player* Player::this_Player; 
Leveltype Player::LevelType = Leveltype::Town;
int Player::RandomSeed = 0;

Player::Player() 
{
	
}

Player::~Player() 
{
}

void Player::AnimationCheck(const std::string_view& _AnimationName)
{
	player->ChangeAnimation(_AnimationName);
}

void Player::Start()
{
	Boss_UI = GetLevel()->CreateActor<Player_UI>(ContentsObjectType::Player);

	this_Player = this;
	GameEngineInput::AddInputObject(this);

	{
		// 줄줄이 사탕 식으로 만들려고.
		player = CreateComponent<GameEngineSpriteRenderer>(-48);
		player->Transform.AddLocalPosition({ 0.0f,0.0f,50.0f });
		

		player->CreateAnimation("Start", "PlayStart", 0.15f, -1, -1, false);

		player->CreateAnimation("UpIdle", "UpIdle", 0.1f, -1, -1, true);
		player->CreateAnimation("LeftIdle", "LeftIdle", 0.1f, -1, -1, true);
		player->CreateAnimation("DownIdle", "DownIdle", 0.1f, -1, -1, true);
		player->CreateAnimation("RightIdle", "RightIdle", 0.1f, -1, -1, true);
	
		player->CreateAnimation("UpMove", "UpMove", 0.1f, -1, -1, true);
		player->CreateAnimation("LeftMove", "LeftMove", 0.1f, -1, -1, true);
		player->CreateAnimation("DownMove", "DownMove", 0.1f, -1, -1, true);
		player->CreateAnimation("RightMove", "RightMove", 0.1f, -1, -1, true);

		player->CreateAnimation("Roll_Down", "Roll_Down", 0.05f, -1, -1, true);
		player->CreateAnimation("Roll_Left", "Roll_Left", 0.05f, -1, -1, true);
		player->CreateAnimation("Roll_Right", "Roll_Right", 0.05f, -1, -1, true);
		player->CreateAnimation("Roll_Up", "Roll_Up", 0.05f, -1, -1, true);

		player->CreateAnimation("Spear_Down_Attack_01", "Spear_Down_Attack_01", 0.1f, -1, -1, false);
		player->CreateAnimation("Spear_Down_Attack_02", "Spear_Down_Attack_02", 0.1f, -1, -1, false);
		player->CreateAnimation("Spear_Down_Attack_03", "Spear_Down_Attack_03", 0.1f, -1, -1, false);

		player->CreateAnimation("Spear_Left_Attack_01", "Spear_Left_Attack_01", 0.1f, -1, -1, false);
		player->CreateAnimation("Spear_Left_Attack_02", "Spear_Left_Attack_02", 0.1f, -1, -1, false);
		player->CreateAnimation("Spear_Left_Attack_03", "Spear_Left_Attack_03", 0.1f, -1, -1, false);

		player->CreateAnimation("Spear_Right_Attack_01", "Spear_Right_Attack_01", 0.1f, -1, -1, false);
		player->CreateAnimation("Spear_Right_Attack_02", "Spear_Right_Attack_02", 0.1f, -1, -1, false);
		player->CreateAnimation("Spear_Right_Attack_03", "Spear_Right_Attack_03", 0.1f, -1, -1, false);

		player->CreateAnimation("Spear_Up_Attack_01", "Spear_Up_Attack_01", 0.1f, -1, -1, false);
		player->CreateAnimation("Spear_Up_Attack_02", "Spear_Up_Attack_02", 0.1f, -1, -1, false);
		player->CreateAnimation("Spear_Up_Attack_03", "Spear_Up_Attack_03", 0.1f, -1, -1, false);
		player->CreateAnimation("Player_Death", "Player_Death", 0.1f, -1, -1, false);
		player->CreateAnimation("Bed", "Bed", 0.1f, -1, -1, false);

		player->AutoSpriteSizeOn();
		player->SetAutoScaleRatio(2.0f);
		player->ChangeAnimation("Start");
		player->SetFrameEvent("Start", 34, std::bind(&Player::TestEvent, this, std::placeholders::_1));


		//player->Transform.SetLocalPosition({ 0.0f,0.0f,-500.0f });
		
	}

	
	{
		Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Player);
		Col->SetCollisionType(ColType::AABBBOX2D);
		//Col->Transform.SetLocalPosition({ 0.0f,0.0f,1.0f });
		Col->Transform.SetLocalScale({ 50.0f, 50.0f });
	}

	{
		Left_Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::ObjectCollision);
		Left_Col->SetCollisionType(ColType::AABBBOX2D);
		Left_Col->Transform.SetLocalPosition({ -20.0f,0.0f,10.0f });
		Left_Col->Transform.SetLocalScale({ 5.0f, 30.0f, 1.0f });
	}

	{
		Right_Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::ObjectCollision);
		Right_Col->SetCollisionType(ColType::AABBBOX2D);
		Right_Col->Transform.SetLocalPosition({ 20.0f,0.0f,10.0f });
		Right_Col->Transform.SetLocalScale({ 5.0f, 30.0f, 1.0f });
	}

	{
		Bottom_Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::ObjectCollision);
		Bottom_Col->SetCollisionType(ColType::AABBBOX2D);
		Bottom_Col->Transform.SetLocalPosition({ 0.0f,-20.0f,10.0f });
		Bottom_Col->Transform.SetLocalScale({ 30.0f, 5.0f, 1.0f });
	}

	{
		Top_Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::ObjectCollision);
		Top_Col->SetCollisionType(ColType::AABBBOX2D);
		Top_Col->Transform.SetLocalPosition({ 0.0f,20.0f,10.0f });
		Top_Col->Transform.SetLocalScale({ 30.0f, 5.0f, 1.0f });
	}

	{
		Mini_Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Rock_Check_Col);
		Mini_Col->SetCollisionType(ColType::AABBBOX2D);
		
		Mini_Col->Transform.SetLocalScale({ 10.0f, 10.0f, 1.0f });
	}


	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y,0.0f });

	Left_Event.Enter = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{	
		RolCheck = false;
		LeftMove = false;
	};

	Left_Event.Stay = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		LeftMove = false;
	};

	Left_Event.Exit = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		LeftMove = true;
	};
	

	Right_Event.Enter = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		RightMove = false;
	};

	Right_Event.Stay = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		RightMove = false;
	};


	Right_Event.Exit = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		RightMove = true;
	};


	Bottom_Event.Enter = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		DownMove = false;
	};

	Bottom_Event.Stay = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		DownMove = false;
	};


	Bottom_Event.Exit = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		DownMove = true;
	};


	Top_Event.Enter = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		UpMove = false;
	};

	Top_Event.Stay = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		UpMove = false;
	};

	
	Top_Event.Exit = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		UpMove = true;
	};



	Event.Enter = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		if (Monster_Attack_Check == false)
		{
			Monster_Attack_Check = true;
			UICheck++;
		}
	};

	Event.Stay = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
			
			
			
	};


	Event.Exit = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
			
	};


	Test_Move = Transform.GetWorldPosition(); 
}

void Player::TestEvent(GameEngineRenderer* _Renderer)
{
	ChangeState(PlayerState::Start_Stop);
}


void Player::HitUpdate(float _Delta)
{
	if (Monster_Attack_Check == true)
	{
		Color_Time += _Delta;


		if (Color_Time < 0.05)
		{
			player->GetColorData().PlusColor = { 0.0f,-1.0f,-1.0f,0.0f };
		}

		if (Color_Time <= 0.1)
		{
			if (Color_Time > 0.05)
			{
				player->GetColorData().PlusColor = { 1.0f,1.0f,1.0f,0.0f };
			}
		}


		if (Color_Time > 0.1)
		{
			player->GetColorData().PlusColor = { 0.0f,0.0f,0.0f,0.0f };
			Color_Time = 0;
			//Monster_Attack_Check = false;
			afterimage_Check = true;
		}
	}

	 if (afterimage_Check == true)
	{
		afterimage_Time += _Delta;

		if (afterimage_Time < 0.15)
		{
			player->GetColorData().PlusColor = { 0.0f,0.0f,0.0f,-1.0f };
		}

		if (afterimage_Time > 0.15)
		{
			player->GetColorData().PlusColor = { 0.0f,0.0f,0.0f,0.0f };
			afterimage_Time = 0;
			++Hit_Check;
		}

	}

	if (Hit_Check >= 5)
	{
		player->GetColorData().PlusColor = { 0.0f,0.0f,0.0f,0.0f };
		afterimage_Check = false;
		Monster_Attack_Check = false;
		Hit_Check = 0;
		afterimage_Time = 0;
		Hp -= Hp_Bar_reduce;
		Hp_Bar_reduce = 0;

		
	}
}



void Player::Update(float _Delta)
{

	if (GameEngineInput::IsDown('1', this))
	{
		Hp = 0;
	}

	if (GameEngineInput::IsDown('2', this))
	{
		Hp = 100;
	}
	//float4 awdd = Transform.GetWorldPosition();


	//OutputDebugStringA(awdd.ToString("\n").c_str());
	
	

	if (Hp <= 0.05 && DieCheck ==false)
	{
		ChangeState(PlayerState::Death);
		DieCheck = true;
	
	}

	if (Hp > 0.05)
	{
		

		Col->CollisionEvent(ContentsCollisionType::Monster_Weapon, Event);


		HitUpdate(_Delta);


		if (Monster_Attack_Check == true)
		{
			if (Hp_Bar_reduce < 0.05)
			{
				Hp_Bar_reduce += _Delta / 3;
				Boss_UI->Hp_Bar->Transform.AddLocalScale({ -_Delta / 3,0.0f });
				Boss_UI->Hp_Bar->GetColorData().PlusColor = { 1.0f,1.0f,1.0f,0.0f };

			}
		}

		if (Monster_Attack_Check == false)
		{
			Boss_UI->Hp_Bar->GetColorData().PlusColor = { 0.0f,0.0f,0.0f,0.0f };
		}

	}
	
	

	




	Left_Col->CollisionEvent(ContentsCollisionType::Object, Left_Event);
	Right_Col->CollisionEvent(ContentsCollisionType::Object, Right_Event);
	Bottom_Col->CollisionEvent(ContentsCollisionType::Object, Bottom_Event);
	Top_Col->CollisionEvent(ContentsCollisionType::Object, Top_Event);

	
	UpdateState(_Delta);
	
	if (Col->Collision(ContentsCollisionType::ShopDoor))
	{
		player->Off();
	}

	else if (Col->Collision(ContentsCollisionType::Player) == false)
	{
		player->On();
	}
}