#include "PreCompile.h"
#include "Big_Sword.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include "Player.h"
Big_Sword::Big_Sword()
{
}

Big_Sword::~Big_Sword()
{
}

void Big_Sword::Start()
{
	{
		// 줄줄이 사탕 식으로 만들려고.
		Sword = CreateComponent<GameEngineSpriteRenderer>(99);

		//player->SetImageScale({ 100.0f, 100.0f });

		Sword->CreateAnimation("BigSword_Down_01", "BigSword_Down_01", 0.1f, -1, -1, false);
		Sword->CreateAnimation("BigSword_Down_02", "BigSword_Down_02", 0.1f, -1, -1, false);
		Sword->CreateAnimation("BigSword_Down_03", "BigSword_Down_03", 0.1f, -1, -1, false);

		/*Sword->CreateAnimation("DownIdle", "DownIdle", 0.1f, -1, -1, true);
		Sword->CreateAnimation("RightIdle", "RightIdle", 0.1f, -1, -1, true);
		Sword->CreateAnimation("UpMove", "UpMove", 0.1f, -1, -1, true);
		Sword->CreateAnimation("LeftMove", "LeftMove", 0.1f, -1, -1, true);
		Sword->CreateAnimation("DownMove", "DownMove", 0.1f, -1, -1, true);
		Sword->CreateAnimation("RightMove", "RightMove", 0.1f, -1, -1, true);*/

		


		Sword->AutoSpriteSizeOn();
		Sword->SetAutoScaleRatio(1.5f);
		Sword->ChangeAnimation("BigSword_Down_01");
		
		//Sword->SetFrameEvent("BigSword_Down_01", 8, std::bind(&Big_Sword::TestEvent, this, std::placeholders::_1));
	}
	

	{
		Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Player);
		Col->Transform.SetLocalScale({ -100.0f, 100.0f, 1.0f });
	}

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });
}


void Big_Sword::Update(float _Delta)
{
	
	
	/*if (Player::this_Player->GetPlayerStateValue() == PlayerState::Down_Attack_01)
	{

	}*/

	UpdateState(_Delta);
	
	

	//UpdateState(_Delta);
}

void Big_Sword::AnimationCheck(const std::string_view& _AnimationName)
{
	Sword->ChangeAnimation(_AnimationName);
}



