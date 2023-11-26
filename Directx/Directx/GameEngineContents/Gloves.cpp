#include "PreCompile.h"
#include "Gloves.h"
#include "Player.h"

Gloves::Gloves()
{
}

Gloves::~Gloves()
{
}



void Gloves::Start()
{
	{
		// 줄줄이 사탕 식으로 만들려고.
		Glove = CreateComponent<GameEngineSpriteRenderer>(99);

		//player->SetImageScale({ 100.0f, 100.0f });

		Glove->CreateAnimation("Gloves_Right_01", "Gloves_Right_01", 0.08f, -1, -1, false);
		Glove->CreateAnimation("Gloves_Right_02", "Gloves_Right_02", 0.08f, -1, -1, false);
		Glove->CreateAnimation("Gloves_Right_03", "Gloves_Right_03", 0.08f, -1, -1, false);

		Glove->CreateAnimation("Gloves_Left_01", "Gloves_Left_01", 0.08f, -1, -1, false);
		Glove->CreateAnimation("Gloves_Left_02", "Gloves_Left_02", 0.08f, -1, -1, false);
		Glove->CreateAnimation("Gloves_Left_03", "Gloves_Left_03", 0.08f, -1, -1, false);

		Glove->CreateAnimation("Gloves_Up_01", "Gloves_Up_01", 0.08f, -1, -1, false);
		Glove->CreateAnimation("Gloves_Up_02", "Gloves_Up_02", 0.08f, -1, -1, false);
		Glove->CreateAnimation("Gloves_Up_03", "Gloves_Up_03", 0.08f, -1, -1, false);

		Glove->CreateAnimation("Gloves_Down_01", "Gloves_Down_01", 0.08f, -1, -1, false);
		Glove->CreateAnimation("Gloves_Down_02", "Gloves_Down_02", 0.08f, -1, -1, false);
		Glove->CreateAnimation("Gloves_Down_03", "Gloves_Down_03", 0.08f, -1, -1, false);

		Glove->AutoSpriteSizeOn();
		Glove->SetAutoScaleRatio(2.0f);
		Glove->ChangeAnimation("Gloves_Left_01");

		//Sword->SetFrameEvent("BigSword_Down_01", 8, std::bind(&Big_Sword::TestEvent, this, std::placeholders::_1));
	}

	{
		Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Spear);
		Col->Transform.SetWorldScale({ 70.0f,70.0f });
	}

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X + 10000.0f, -HalfWindowScale.Y, -500.0f });
}

void Gloves::Update(float _Delta)
{
	Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X , Player::this_Player->Transform.GetWorldPosition().Y });


	UpdateState(_Delta);

}
void Gloves::AnimationCheck(const std::string_view& _AnimationName)
{
	Glove->ChangeAnimation(_AnimationName);
}


