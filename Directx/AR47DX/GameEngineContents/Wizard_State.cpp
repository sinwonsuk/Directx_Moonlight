#include "PreCompile.h"
#include "golem_Wizard.h"
#include "Player.h"


void golem_Wizard::ChangeState(golem_Wizard_State _State)
{
	golem_Wizard_State NextState = _State;
	golem_Wizard_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case golem_Wizard_State::Start:
		
		break;
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
	case golem_Wizard_State::Start:
		DirCheckUpdate(_Time);
		break;
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

void golem_Wizard::DirCheckUpdate(float _Time)
{
	if (degree >= 0)
	{
		if (degree <= 45)
		{
			ChangeState(golem_Wizard_State::LeftWalk);
			return; 
		}
	}
	 if (degree < 360)
	{
		if (degree >= 315)
		{
			ChangeState(golem_Wizard_State::LeftWalk);
			return;
		}
	}
	if (degree <= 135)
	{
		if (degree > 45 )
		{
			ChangeState(golem_Wizard_State::UpWalk);
			return;
		}
	}
	 if (degree <= 225)
	{
		if (degree > 135)
		{
			ChangeState(golem_Wizard_State::RightWalk);
			return;
		}
	}
	 if (degree <= 315)
	{
		if (degree > 225)
		{
			ChangeState(golem_Wizard_State::DownWalk);
			return;
		}
	}





}

void golem_Wizard::Dir_Attack_Check_Update(float _Time)
{
	if (degree >= 0)
	{
		if (degree <= 45)
		{
			ChangeState(golem_Wizard_State::LeftAttack);
			return;
		}
	}
	if (degree < 360)
	{
		if (degree >= 315)
		{
			ChangeState(golem_Wizard_State::LeftAttack);
			return;
		}
	}
	if (degree <= 135)
	{
		if (degree > 45)
		{
			ChangeState(golem_Wizard_State::UpAttack);
			return;
		}
	}
	if (degree <= 225)
	{
		if (degree > 135)
		{
			ChangeState(golem_Wizard_State::RightAttack);
			return;
		}
	}
	if (degree <= 315)
	{
		if (degree > 225)
		{
			ChangeState(golem_Wizard_State::DownAttack);
			return;
		}
	}

}

void golem_Wizard::LeftMoveUpdate(float _Time)
{


	DirCheckUpdate(_Time);


	float4 Move = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
	Move.Normalize(); 

	if (Time > 1.0f)
	{
		Transform.AddLocalPosition(Move * Speed * _Time);




		if (200.0f > abs(Player::this_Player->Transform.GetWorldPosition().X - Transform.GetWorldPosition().X))
		{
			ChangeState(golem_Wizard_State::LeftAttack);
			return;
		}
	}
}

void golem_Wizard::RightMoveUpdate(float _Time)
{
	DirCheckUpdate(_Time);


	float4 Move = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
	Move.Normalize();


	if (Time > 1.0f)
	{
		Transform.AddLocalPosition(Move * Speed * _Time);




		if (200.0f > abs(Player::this_Player->Transform.GetWorldPosition().X - Transform.GetWorldPosition().X))
		{
			ChangeState(golem_Wizard_State::RightAttack);
			return;
		}
	}
}

void golem_Wizard::UpMoveUpdate(float _Time)
{

	DirCheckUpdate(_Time);


	float4 Move = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
	Move.Normalize();


	if (Time > 1.0f)
	{
		Transform.AddLocalPosition(Move * Speed * _Time);




		if (200.0f > abs(Player::this_Player->Transform.GetWorldPosition().X - Transform.GetWorldPosition().X))
		{
			ChangeState(golem_Wizard_State::UpAttack);
			return;
		}
	}
}

void golem_Wizard::DownMoveUpdate(float _Time)
{
	DirCheckUpdate(_Time);


	float4 Move = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
	Move.Normalize();


	if (Time > 1.0f)
	{
		Transform.AddLocalPosition(Move * Speed * _Time);




		if (200.0f > abs(Player::this_Player->Transform.GetWorldPosition().X - Transform.GetWorldPosition().X))
		{
			ChangeState(golem_Wizard_State::DownAttack);
			return;
		}
	}

}

void golem_Wizard::LeftAttackUpdate(float _Time)
{
	

	if (Wizard->IsCurAnimationEnd())
	{
		Time = 0.0f;
	
		DirCheckUpdate(_Time);
		return; 

		
	
	}

}

void golem_Wizard::RightAttackUpdate(float _Time)
{
	if (Wizard->IsCurAnimationEnd() )
	{
		Time = 0.0f;


			DirCheckUpdate(_Time);
			return;
		

	}

}

void golem_Wizard::UpAttackUpdate(float _Time)
{
	if (Wizard->IsCurAnimationEnd() )
	{


		Time = 0.0f;


		
			DirCheckUpdate(_Time);
			return;
	
	
	}

}

void golem_Wizard::DownAttackUpdate(float _Time)
{
	if (Wizard->IsCurAnimationEnd() )
	{
		Time = 0.0f;

		
			DirCheckUpdate(_Time);
			return;
		


	}

}

