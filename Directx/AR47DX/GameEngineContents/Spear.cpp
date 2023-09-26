#include "PreCompile.h"
#include "Spear.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include "Player.h"

Spear::Spear()
{
}

Spear::~Spear()
{
}

void Spear::Start()
{
	{
		// 줄줄이 사탕 식으로 만들려고.
		spear = CreateComponent<GameEngineSpriteRenderer>(99);

		//player->SetImageScale({ 100.0f, 100.0f });

		spear->CreateAnimation("Spear_Down_01", "Spear_Down_01", 0.1f, -1, -1, false);
		spear->CreateAnimation("Spear_Down_02", "Spear_Down_02", 0.1f, -1, -1, false);
		spear->CreateAnimation("Spear_Down_03", "Spear_Down_03", 0.1f, -1, -1, false);

		spear->CreateAnimation("Spear_Left_01", "Spear_Left_01", 0.1f, -1, -1, false);
		spear->CreateAnimation("Spear_Left_02", "Spear_Left_02", 0.1f, -1, -1, false);
		spear->CreateAnimation("Spear_Left_03", "Spear_Left_03", 0.1f, -1, -1, false);

		spear->CreateAnimation("Spear_Right_01", "Spear_Right_01", 0.1f, -1, -1, false);
		spear->CreateAnimation("Spear_Right_02", "Spear_Right_02", 0.1f, -1, -1, false);
		spear->CreateAnimation("Spear_Right_03", "Spear_Right_03", 0.1f, -1, -1, false);

		spear->CreateAnimation("Spear_Up_01", "Spear_Up_01", 0.1f, -1, -1, false);
		spear->CreateAnimation("Spear_Up_02", "Spear_Up_02", 0.1f, -1, -1, false);
		spear->CreateAnimation("Spear_Up_03", "Spear_Up_03", 0.1f, -1, -1, false);

		spear->AutoSpriteSizeOn();
		spear->SetAutoScaleRatio(2.0f);
		spear->ChangeAnimation("Spear_Down_01");
		
		//Sword->SetFrameEvent("BigSword_Down_01", 8, std::bind(&Big_Sword::TestEvent, this, std::placeholders::_1));
	}
	
	{
		Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Spear);
		Col->Transform.SetWorldScale({ 50.0f,20.0f });
	}

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });

	/*{
		ad = CreateComponent<GameEngineSpriteRenderer>(99);
		ad->SetSprite("collision.png");
		ad->AutoSpriteSizeOn();
	}*/


}


void Spear::Update(float _Delta)
{
	
	



	UpdateState(_Delta);
	
	

	
}

void Spear::AnimationCheck(const std::string_view& _AnimationName)
{
	spear->ChangeAnimation(_AnimationName);
}



