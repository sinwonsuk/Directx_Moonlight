#include "PreCompile.h"
#include "Boss_Monster.h"
#include "Player.h"
#include "Boss_Arm.h"
#include "Boss_Rock_Shadow.h"

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
	case Boss_Monster_State::RecoveryArm:
		AnimationCheck("Boss1_RecoverArm");
		break;
	case Boss_Monster_State::Rocks_Spawn_Attack:
		AnimationCheck("Boss1_Rocks_Spawn_Attack");
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
		Idle_NoArm_Update(_Time);
		break;
	case Boss_Monster_State::RecoveryArm:
		RecoveryArmUpdate(_Time);
		break;
	case Boss_Monster_State::Rocks_Spawn_Attack:
		Rocks_Spawn_Attack_Update(_Time);
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
		ChangeState(Boss_Monster_State::WakeUp)
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
		Arm = GetLevel()->CreateActor<Boss_Arm>();
		ChangeState(Boss_Monster_State::IdleNoArm);
		return; 
	}

}

void Boss_Monster::Idle_NoArm_Update(float _Time)
{
	if (Arm->GetFinishCheck() == true)
	{
		Arm->Death();
		Arm = GetLevel()->CreateActor<Boss_Arm>();
		++ArmCheck;
	}
	if (ArmCheck == 3)
	{
		Arm->Death();
		ArmCheck = 0; 
		ChangeState(Boss_Monster_State::RecoveryArm);
		return;
	}

}

void Boss_Monster::RecoveryArmUpdate(float _Time)
{
	if (Boss->IsCurAnimationEnd())
	{
		ChangeState(Boss_Monster_State::Idle);
		return; 
	}

}

void Boss_Monster::Rocks_Spawn_Attack_Update(float _Time)
{
	if (Boss->IsCurAnimationEnd())
	{
		while (true)
		{
			std::shared_ptr<Boss_Rock_Shadow> Object = GetLevel()->CreateActor<Boss_Rock_Shadow>();
			Object->Transform.AddLocalPosition({ Transform.GetWorldPosition().X+600 - ssss,Transform.GetWorldPosition().Y-300});

			ssss -= 80;


			++ASSS;
			if (ASSS > 50)
			{
				break;
			}

		}


	}

}
