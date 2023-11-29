#include "PreCompile.h"
#include "Boss_Arm.h"
#include "Player.h"
#include "Boss_Brick.h"

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
		Transform.SetWorldPosition({Player::this_Player->Transform.GetWorldPosition().X, Player::this_Player->Transform.GetWorldPosition().Y+500.0f});
		Prev_Player_Pos = Shadow->Transform.GetWorldPosition(); 
		ChangeState(Boss_Arm_State::DownPrev);
		return; 
	}
}

void Boss_Arm::Down_Prev_Update(float _Time)
{
	Boss_arm_Texture->On();

	if (Prev_Player_Pos.Y <= Transform.GetWorldPosition().Y-20.0f)
	{
		Transform.AddLocalPosition(float4::DOWN * _Time * Speed);
	}
	else if (Prev_Player_Pos.Y >= Transform.GetWorldPosition().Y -20.0f)
	{
		Boss_arm_Texture->Off(); 
		Boss_arm->On();
		Crash_Sound = GameEngineSound::SoundPlay("golem_dungeon_king_golem_handcrash.wav"); 
		ChangeState(Boss_Arm_State::Down);
		return; 
	}



}
	
void Boss_Arm::DownUpdate(float _Time)
{
	if (Boss_arm->IsCurAnimationEnd())
	{
		std::shared_ptr<Boss_Brick> object = GetLevel()->CreateActor<Boss_Brick>();
		object->Transform.SetWorldPosition({ Transform.GetWorldPosition().X, Transform.GetWorldPosition().Y});
		ChangeState(Boss_Arm_State::Up);
		return;
	}
	
}

void Boss_Arm::UpUpdate(float _Time)
{
	Shadow->size = Shadow_Size::Small;
	//Shadow->Transform.SetWorldPosition(Prev_Player_Pos);
	Transform.AddLocalPosition(float4::UP * _Time * Speed);

	if (Player::this_Player->Transform.GetWorldPosition().Y <= Transform.GetWorldPosition().Y - 600)
	{
		FinishCheck = true; 
	}



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
	case Boss_Arm_State::DownPrev:
		Down_Prev_Update(_Time);
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