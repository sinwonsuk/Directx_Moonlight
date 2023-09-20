#include "PreCompile.h"
#include "golem_Wizard.h"



void golem_Wizard::ChangeState(golem_Wizard_State _State)
{
	golem_Wizard_State NextState = _State;
	golem_Wizard_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case golem_Wizard_State::LeftWalk:
		AnimationCheck("golem_Wizard_Left_Move");
		break;
	case golem_Wizard_State::RightWalk:
		AnimationCheck("golem_Wizard_Right_Move");
		break;
	case golem_Wizard_State::UpWalk:
		AnimationCheck("golem_Wizard_Up_Move");
		break;
	case golem_Wizard_State::DownWalk:
		AnimationCheck("golem_Wizard_Down_Move");
		break;
	case golem_Wizard_State::LeftAttack:
		AnimationCheck("golem_Wizard_Left_Attack");
		break;
	case golem_Wizard_State::RightAttack:
		AnimationCheck("golem_Wizard_Right_Attack");
		break;
	case golem_Wizard_State::UpAttack:
		AnimationCheck("golem_Wizard_Up_Attack");
		break;
	case golem_Wizard_State::DownAttack:
		AnimationCheck("golem_Wizard_Down_Attack");
		break;

	}

}

void golem_Wizard::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case golem_Wizard_State::LeftWalk:
		LeftMoveUpdate(_Time);
		break;
	case golem_Wizard_State::RightWalk:
		RightMoveUpdate(_Time);
		break;
	case golem_Wizard_State::UpWalk:
		UpMoveUpdate(_Time);
		break;
	case golem_Wizard_State::DownWalk:
		DownMoveUpdate(_Time);
		break;
	case golem_Wizard_State::LeftAttack:
		LeftAttackUpdate(_Time);
		break;
	case golem_Wizard_State::RightAttack:
		RightAttackUpdate(_Time);
		break;
	case golem_Wizard_State::UpAttack:
		UpAttackUpdate(_Time);
		break;
	case golem_Wizard_State::DownAttack:
		DownAttackUpdate(_Time);
		break;

	default:
		break;
	}
}

void golem_Wizard::LeftMoveUpdate(float _Time)
{


}

void golem_Wizard::RightMoveUpdate(float _Time)
{


}

void golem_Wizard::UpMoveUpdate(float _Time)
{


}

void golem_Wizard::DownMoveUpdate(float _Time)
{


}

void golem_Wizard::LeftAttackUpdate(float _Time)
{


}

void golem_Wizard::RightAttackUpdate(float _Time)
{


}

void golem_Wizard::UpAttackUpdate(float _Time)
{


}

void golem_Wizard::DownAttackUpdate(float _Time)
{


}
