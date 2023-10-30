#include "PreCompile.h"
#include "Boss_Monster.h"
#include "Player.h"
#include "Boss_Arm.h"


void Boss_Monster::ChangeState(Boss_Monster_State _State)
{
	Boss_Monster_State NextState = _State;
	Boss_Monster_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case Boss_Monster_State::Start:
		break;

	case Boss_Monster_State::WakeUp:
		AnimationCheck("Wake_Up");
		break;
	case Boss_Monster_State::Start2:
		AnimationCheck("Idle");
		break;
	case Boss_Monster_State::Idle:
		AnimationCheck("Idle");
		break;
	case Boss_Monster_State::LaunchArm:
		AnimationCheck("Boss1_LaunchArm");
		break;
	case Boss_Monster_State::IdleNoArm:
		AnimationCheck("Boss1_IdleNoArm");
		break;
	}
	
}



void Boss_Monster::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case Boss_Monster_State::Start:
		StartUpdate(_Time);
		break;

	case Boss_Monster_State::WakeUp:
		Wake_Up_Update(_Time);
		break;
	case Boss_Monster_State::Start2:
		Start2Update(_Time);
		break;
	case Boss_Monster_State::Idle:
		IdleUpdate(_Time);
		break;
	case Boss_Monster_State::LaunchArm:
		LaunchArm_Update(_Time);
		break;
	case Boss_Monster_State::IdleNoArm:
		LaunchArm_Update(_Time);
		break;
	default:
		break;
	}
}

void Boss_Monster::IdleUpdate(float _Time)
{
	if (Time > 0 && Boss->IsCurAnimationEnd())
	{
		ChangeState(Boss_Monster_State::LaunchArm);
		return;
	}

}


void Boss_Monster::StartUpdate(float _Time)
{
	if ( CameraCheck == true)
	{
		Player::this_Player->Not_Move = false;
		float4 AD = Transform.GetWorldPosition()- Player::this_Player->Transform.GetWorldPosition();
		AD.Normalize();
		GetLevel()->GetMainCamera()->Transform.AddLocalPosition({ AD * Time * Speed });
	}

	if (GetLevel()->GetMainCamera()->Transform.GetWorldPosition().Y >= Transform.GetWorldPosition().Y)
	{
		ChangeState(Boss_Monster_State::WakeUp);
		return;
	}


}

void Boss_Monster::Start2Update(float _Time)
{
	if (CameraCheck == true)
	{
		Player::this_Player->Not_Move = false;
		float4 AD = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
		AD.Normalize();
		GetLevel()->GetMainCamera()->Transform.AddLocalPosition({ AD * Time * Speed });
	}

	if (GetLevel()->GetMainCamera()->Transform.GetWorldPosition().Y <= Player::this_Player->Transform.GetWorldPosition().Y+100.0f)
	{
		Player::this_Player->Not_Move = true;
		ChangeState(Boss_Monster_State::Idle);
		return;
	}
}


void Boss_Monster::Wake_Up_Update(float _Time)
{
	Boss->AnimationPauseOff();

	if (Boss->IsCurAnimationEnd())
	{
		ChangeState(Boss_Monster_State::Start2);
		return;
	}
}

void Boss_Monster::LaunchArm_Update(float _Time)
{
	
	
	if (Boss->IsCurAnimationEnd())
	{

		
		std::shared_ptr<Boss_Arm> object = GetLevel()->CreateActor<Boss_Arm>();
		

		ChangeState(Boss_Monster_State::IdleNoArm);
		return; 
	}

}

void Boss_Monster::Idle_NoArm_Update(float _Time)
{



}
