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
	//Arm_shadow->Transform.AddLocalPosition({ 0.0f,-20.0f });

}

void Arm_Shadow::Update(float _Delta)
{
	switch (size)
	{
	case Shadow_Size::Big:
	{
		if (ArmScale >= 2.0f)
		{
			return;
		}

		if (ArmScale < 1.5f)
		{
			Transform.SetWorldPosition({ Player::this_Player->Transform.GetWorldPosition().X, Player::this_Player->Transform.GetWorldPosition().Y - 30.0f });

			Prev_Pos = Player::this_Player->Transform.GetWorldPosition().X, Player::this_Player->Transform.GetWorldPosition().Y - 30.0f; 
		}

		ArmScale += _Delta * 1.0f;

		Arm_shadow->SetAutoScaleRatio(ArmScale);

	}
		break;
	case Shadow_Size::Small:
	{
		Transform.SetWorldPosition({ Prev_Pos });

		if (ArmScale <= 0.1f)
		{
			this->Death();
			return;
		}

		if (ArmScale < 1.5f)
		{
			Transform.SetWorldPosition({ Prev_Pos });
		}

		ArmScale -= _Delta * 1.0f;

		Arm_shadow->SetAutoScaleRatio(ArmScale);

	}

		break;
	default:
		break;
	}
	

	


}
