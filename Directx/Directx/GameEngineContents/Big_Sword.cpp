#include "PreCompile.h"
#include "Big_Sword.h"
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

		Sword->CreateAnimation("Big_Sword_Right_01", "Big_Sword_Right_01", 0.1f, -1, -1, false);
		Sword->CreateAnimation("Big_Sword_Right_02", "Big_Sword_Right_02", 0.1f, -1, -1, false);
		Sword->CreateAnimation("Big_Sword_Right_03", "Big_Sword_Right_03", 0.1f, -1, -1, false);

		Sword->CreateAnimation("Big_Sword_Left_01", "Big_Sword_Left_01", 0.1f, -1, -1, false);
		Sword->CreateAnimation("Big_Sword_Left_02", "Big_Sword_Left_02", 0.1f, -1, -1, false);
		Sword->CreateAnimation("Big_Sword_Left_03", "Big_Sword_Left_03", 0.1f, -1, -1, false);

		Sword->CreateAnimation("Big_Sword_Up_01", "Big_Sword_Up_01", 0.1f, -1, -1, false);
		Sword->CreateAnimation("Big_Sword_Up_02", "Big_Sword_Up_02", 0.1f, -1, -1, false);
		Sword->CreateAnimation("Big_Sword_Up_03", "Big_Sword_Up_03", 0.1f, -1, -1, false);

		Sword->CreateAnimation("Big_Sword_Down_01", "Big_Sword_Down_01", 0.1f, -1, -1, false);
		Sword->CreateAnimation("Big_Sword_Down_02", "Big_Sword_Down_02", 0.1f, -1, -1, false);
		Sword->CreateAnimation("Big_Sword_Down_03", "Big_Sword_Down_03", 0.1f, -1, -1, false);

		Sword->AutoSpriteSizeOn();
		Sword->SetAutoScaleRatio(2.0f);
		Sword->ChangeAnimation("Big_Sword_Left_01");

		//Sword->SetFrameEvent("BigSword_Down_01", 8, std::bind(&Big_Sword::TestEvent, this, std::placeholders::_1));
	}

	{
		Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Spear);
		Col->Transform.SetWorldScale({ 110.0f,30.0f });
	}

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X + 10000.0f, -HalfWindowScale.Y, -500.0f });

}

void Big_Sword::Update(float _Delta)
{
	Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X , Player::this_Player->Transform.GetWorldPosition().Y });


	UpdateState(_Delta);

}

void Big_Sword::AnimationCheck(const std::string_view& _AnimationName)
{
	Sword->ChangeAnimation(_AnimationName);
}


