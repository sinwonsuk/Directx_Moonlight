#include "PreCompile.h"
#include "Arm_Shadow.h"
#include "Player.h"


Arm_Shadow::Arm_Shadow()
{
}

Arm_Shadow::~Arm_Shadow()
{
}

void Arm_Shadow::Start()
{
   
	Arm_shadow = CreateComponent<GameEngineSpriteRenderer>(100);
	Arm_shadow->SetSprite("Boss1_Punch_Shadow", 0);
	Arm_shadow->AutoSpriteSizeOn();
	Arm_shadow->SetAutoScaleRatio(0.1f);


}

void Arm_Shadow::Update(float _Delta)
{
	if (ArmScale >= 2.0f)
	{
		return;
	}

	if (ArmScale < 1.5f)
	{
		Transform.SetWorldPosition(Player::this_Player->Transform.GetWorldPosition());
	}

	ArmScale += _Delta * 0.5f;

	Arm_shadow->SetAutoScaleRatio(ArmScale);


	


}
