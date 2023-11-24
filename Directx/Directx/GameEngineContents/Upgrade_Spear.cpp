#include "PreCompile.h"
#include "Upgrade_Spear.h"
#include "Player.h"


UpGrade_Spear::UpGrade_Spear()
{
}

UpGrade_Spear::~UpGrade_Spear()
{
}

void UpGrade_Spear::Start()
{
	spear = CreateComponent<GameEngineSpriteRenderer>(99);

	spear->CreateAnimation("Upgrade_Spear_Down_01", "Upgrade_Spear_Down_01", 0.1f, -1, -1, false);
	spear->CreateAnimation("Upgrade_Spear_Down_02", "Upgrade_Spear_Down_02", 0.1f, -1, -1, false);
	spear->CreateAnimation("Upgrade_Spear_Down_03", "Upgrade_Spear_Down_03", 0.1f, -1, -1, false);

	spear->CreateAnimation("Upgrade_Spear_Left_01", "Upgrade_Spear_Left_01", 0.1f, -1, -1, false);
	spear->CreateAnimation("Upgrade_Spear_Left_02", "Upgrade_Spear_Left_02", 0.1f, -1, -1, false);
	spear->CreateAnimation("Upgrade_Spear_Left_03", "Upgrade_Spear_Left_03", 0.1f, -1, -1, false);

	spear->CreateAnimation("Upgrade_Spear_Right_01", "Upgrade_Spear_Right_01", 0.1f, -1, -1, false);
	spear->CreateAnimation("Upgrade_Spear_Right_02", "Upgrade_Spear_Right_02", 0.1f, -1, -1, false);
	spear->CreateAnimation("Upgrade_Spear_Right_03", "Upgrade_Spear_Right_03", 0.1f, -1, -1, false);

	spear->CreateAnimation("Upgrade_Spear_Up_01", "Upgrade_Spear_Up_01", 0.1f, -1, -1, false);
	spear->CreateAnimation("Upgrade_Spear_Up_02", "Upgrade_Spear_Up_02", 0.1f, -1, -1, false);
	spear->CreateAnimation("Upgrade_Spear_Up_03", "Upgrade_Spear_Up_03", 0.1f, -1, -1, false);

	spear->AutoSpriteSizeOn();
	spear->SetAutoScaleRatio(2.0f);
	spear->ChangeAnimation("Upgrade_Spear_Down_01");

	//Sword->SetFrameEvent("BigSword_Down_01", 8, std::bind(&Big_Sword::TestEvent, this, std::placeholders::_1));


	{
		Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Spear);
		Col->Transform.SetWorldScale({ 100.0f,20.0f });
	}

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X + 100000.0f, -HalfWindowScale.Y, -500.0f });

}

void UpGrade_Spear::Update(float _Delta)
{
	Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X , Player::this_Player->Transform.GetWorldPosition().Y });


	UpdateState(_Delta);
}
void UpGrade_Spear::AnimationCheck(const std::string_view& _AnimationName)
{
	spear->ChangeAnimation(_AnimationName);
}

