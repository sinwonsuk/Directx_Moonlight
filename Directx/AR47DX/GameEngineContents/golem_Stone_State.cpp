#include "PreCompile.h"
#include "golem_Stone.h"
#include "Player.h"



void golem_Stone::ChangeState(golem_Stone_State _State)
{
	golem_Stone_State NextState = _State;
	golem_Stone_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case golem_Stone_State::Start:

		break;
	case golem_Stone_State::LeftWalk:
		AnimationCheck("golemhead_prepare_left");
		break;
	case golem_Stone_State::RightWalk:
		AnimationCheck("golemhead_prepare_right");
		break;
	case golem_Stone_State::UpWalk:
		AnimationCheck("golemhead_prepare_up");
		break;
	case golem_Stone_State::DownWalk:
		AnimationCheck("golemhead_prepare_down");
		break;
	case golem_Stone_State::LeftAttack:
		AnimationCheck("golemhead_cycle_left");
		break;
	case golem_Stone_State::RightAttack:
		AnimationCheck("golemhead_cycle_right");
		break;
	case golem_Stone_State::UpAttack:
		AnimationCheck("golemhead_cycle_up");
		break;
	case golem_Stone_State::DownAttack:
		AnimationCheck("golemhead_cycle_down");
		break;
	case golem_Stone_State::AttackCheck:
		
		break;
	case golem_Stone_State::LeftCollision:
		AnimationCheck("golemhead_stunned_left");
		break;
	case golem_Stone_State::RightCollision:
		AnimationCheck("golemhead_stunned_right");
		break;
	case golem_Stone_State::DownCollision:
		AnimationCheck("golemhead_stunned_down");
		break;
	case golem_Stone_State::UpCollision:
		AnimationCheck("golemhead_stunned_up");
		break;
	}

}

void golem_Stone::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case golem_Stone_State::Start:
		DirCheckUpdate(_Time);
		break;
	case golem_Stone_State::LeftWalk:
		LeftMoveUpdate(_Time);
		break;
	case golem_Stone_State::RightWalk:
		RightMoveUpdate(_Time);
		break;
	case golem_Stone_State::UpWalk:
		UpMoveUpdate(_Time);
		break;
	case golem_Stone_State::DownWalk:
		DownMoveUpdate(_Time);
		break;
	case golem_Stone_State::LeftAttack:
		LeftAttackUpdate(_Time);
		break;
	case golem_Stone_State::RightAttack:
		RightAttackUpdate(_Time);
		break;
	case golem_Stone_State::UpAttack:
		UpAttackUpdate(_Time);
		break;
	case golem_Stone_State::DownAttack:
		DownAttackUpdate(_Time);
		break;
	case golem_Stone_State::AttackCheck:
		Dir_Attack_Check_Update(_Time);
		break;
	case golem_Stone_State::LeftCollision:
		LeftCollisionUpdate(_Time);
		break;
	case golem_Stone_State::RightCollision:
		RightCollisionUpdate(_Time);
		break;
	case golem_Stone_State::DownCollision:
		DownCollisionUpdate(_Time);
		break;
	case golem_Stone_State::UpCollision:
		UpCollisionUpdate(_Time);
		break;
	default:
		break;
	}
}

void golem_Stone::DirCheckUpdate(float _Time)
{






	if (degree >= 0)
	{
		if (degree <= 45)
		{
			ChangeState(golem_Stone_State::LeftWalk);
			return;
		}
	}
	if (degree < 360)
	{
		if (degree >= 315)
		{
			ChangeState(golem_Stone_State::LeftWalk);
			return;
		}
	}
	if (degree <= 135)
	{
		if (degree > 45)
		{

			ChangeState(golem_Stone_State::UpWalk);
			return;
		}
	}
	if (degree <= 225)
	{
		if (degree > 135)
		{
			ChangeState(golem_Stone_State::RightWalk);
			return;
		}
	}
	if (degree <= 315)
	{
		if (degree > 225)
		{
			ChangeState(golem_Stone_State::DownWalk);
			return;
		}
	}





}

void golem_Stone::Dir_Attack_Check_Update(float _Time)
{
	if (degree >= 0)
	{
		if (degree <= 45)
		{
			ChangeState(golem_Stone_State::LeftWalk);
			return;
		}
	}
	if (degree < 360)
	{
		if (degree >= 315)
		{
			ChangeState(golem_Stone_State::LeftWalk);
			return;
		}
	}
	if (degree <= 135)
	{
		if (degree > 45)
		{

			ChangeState(golem_Stone_State::UpWalk);
			return;
		}
	}
	if (degree <= 225)
	{
		if (degree > 135)
		{
			ChangeState(golem_Stone_State::RightWalk);
			return;
		}
	}
	if (degree <= 315)
	{
		if (degree > 225)
		{
			ChangeState(golem_Stone_State::DownWalk);
			return;
		}
	}


}



void golem_Stone::LeftMoveUpdate(float _Time)
{



	if (Time > 1.0f)
	{
		if (Stone->IsCurAnimationEnd())
		{
			ChangeState(golem_Stone_State::LeftAttack);
			return;
		}
	}
}

void golem_Stone::RightMoveUpdate(float _Time)
{



	if (Time > 1.0f)
	{
		if (Stone->IsCurAnimationEnd())
		{
			ChangeState(golem_Stone_State::RightAttack);
			return;
		}
	}
}

void golem_Stone::UpMoveUpdate(float _Time)
{


	if (Time > 1.0f)
	{
		if (Stone->IsCurAnimationEnd())
		{
			ChangeState(golem_Stone_State::UpAttack);
			return;
		}
	}
}

void golem_Stone::DownMoveUpdate(float _Time)
{





	if (Time > 1.0f)
	{
		if (Stone->IsCurAnimationEnd())
		{
			ChangeState(golem_Stone_State::DownAttack);
			return;
		}
	}

}

void golem_Stone::LeftAttackUpdate(float _Time)
{
	if (PlayerCheck == false)
	{
		Dir = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
		Dir.Normalize();
		PlayerCheck = true;
	}

	Transform.AddLocalPosition({ Dir * _Time * Speed });

	if (Stone->IsCurAnimationEnd())
	{
		Time = 0.0f;
		PlayerCheck = false; 
		ChangeState(golem_Stone_State::AttackCheck);
		return;
	}

}

void golem_Stone::RightAttackUpdate(float _Time)
{

	if (PlayerCheck == false)
	{
		Dir = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
		Dir.Normalize();
		PlayerCheck = true;
	}

	Transform.AddLocalPosition({ Dir * _Time * Speed });


	if (Stone->IsCurAnimationEnd())
	{
		Time = 0.0f;
		PlayerCheck = false;
		ChangeState(golem_Stone_State::AttackCheck);
		return;
	}

}

void golem_Stone::UpAttackUpdate(float _Time)
{

	if (PlayerCheck == false)
	{
		Dir = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
		Dir.Normalize();
		PlayerCheck = true;
	}

	Transform.AddLocalPosition({ Dir * _Time * Speed });

	if (Stone->IsCurAnimationEnd())
	{
		PlayerCheck = false;
		Time = 0.0f;
		ChangeState(golem_Stone_State::AttackCheck);
		return;
	}

}

void golem_Stone::DownAttackUpdate(float _Time)
{

	if (PlayerCheck == false)
	{
		Dir = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
		Dir.Normalize();
		PlayerCheck = true;
	}

	Transform.AddLocalPosition({ Dir * _Time * Speed });



	if (Stone->IsCurAnimationEnd())
	{
		PlayerCheck = false;
		Time = 0.0f;
		ChangeState(golem_Stone_State::AttackCheck);
		return;
	}

}


void golem_Stone::LeftCollisionUpdate(float _Time)
{
	if (Stone->IsCurAnimationEnd())
	{
		PlayerCheck = false;
		Time = 0.0f;
		ChangeState(golem_Stone_State::AttackCheck);
		return;
	}


}

void golem_Stone::RightCollisionUpdate(float _Time)
{
	if (Stone->IsCurAnimationEnd())
	{
		PlayerCheck = false;
		Time = 0.0f;
		ChangeState(golem_Stone_State::AttackCheck);
		return;
	}
}

void golem_Stone::DownCollisionUpdate(float _Time)
{
	if (Stone->IsCurAnimationEnd())
	{
		PlayerCheck = false;
		Time = 0.0f;
		ChangeState(golem_Stone_State::AttackCheck);
		return;
	}
}

void golem_Stone::UpCollisionUpdate(float _Time)
{
	if (Stone->IsCurAnimationEnd())
	{
		PlayerCheck = false;
		Time = 0.0f;
		ChangeState(golem_Stone_State::AttackCheck);
		return;
	}

}
