#include "PreCompile.h"
#include "Boss_Arm.h"
#include "Player.h"


void Boss_Arm::ChangeState(Boss_Arm_State _State)
{
	Boss_Arm_State NextState = _State;
	Boss_Arm_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case Boss_Arm_State::Start:
		break;
	case Boss_Arm_State::DownPrev:
		break;
	case Boss_Arm_State::Down:
		AnimationCheck("Boss1_Punch_1");
		break;
	case Boss_Arm_State::Up:
		AnimationCheck("Boss1_Punchup");
		break;
	case Boss_Arm_State::Mask:
		AnimationCheck("Idle");
		break;


	}

}

void Boss_Arm::StartUpdate(float _Time)
{
	Shadow->On(); 

	if (Shadow->ArmScale >= 1.5f)
	{
		Transform.SetWorldPosition({Player::this_Player->Transform.GetWorldPosition().X, Player::this_Player->Transform.GetWorldPosition().Y+400.0f});
		ChangeState(Boss_Arm_State::DownPrev);
		return; 
	}
}

void Boss_Arm::Down_Prev_Update(float _Time)
{
	Boss_arm_Texture->On();

	if (Player::this_Player->Transform.GetWorldPosition().Y <= Transform.GetWorldPosition().Y)
	{
		Transform.AddLocalPosition(float4::DOWN * _Time * Speed);
	}
}
	
void Boss_Arm::DownUpdate(float _Time)
{

	

}

void Boss_Arm::UpUpdate(float _Time)
{
}

void Boss_Arm::MaskUpdate(float _Time)
{
}



void Boss_Arm::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case Boss_Arm_State::Start:
		StartUpdate(_Time);
		break;

	case Boss_Arm_State::Down:
		DownUpdate(_Time);
		break;
	case Boss_Arm_State::Up:
		UpUpdate(_Time);
		break;
	case Boss_Arm_State::Mask:
		MaskUpdate(_Time);
		break;
	

	default:
		break;
	}
}