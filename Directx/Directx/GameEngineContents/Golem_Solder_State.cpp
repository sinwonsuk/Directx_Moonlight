#include "PreCompile.h"
#include "golem_Solder.h"
#include "Player.h"
	


void golem_Solder::ChangeState(golem_Solder_State _State)
{
	golem_Solder_State NextState = _State;
	golem_Solder_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case golem_Solder_State::Start:

		break;
	case golem_Solder_State::LeftWalk:
		AnimationCheck("GolemSoldier_Move_Left");
		break;
	case golem_Solder_State::RightWalk:
		AnimationCheck("GolemSoldier_Move_Right");
		break;
	case golem_Solder_State::UpWalk:
		AnimationCheck("GolemSoldier_Move_Up");
		break;
	case golem_Solder_State::DownWalk:
		AnimationCheck("GolemSoldier_Move_Down");
		break;
	case golem_Solder_State::LeftAttack:
		AnimationCheck("GolemSolder_Attack_Left");
		break;
	case golem_Solder_State::RightAttack:
		AnimationCheck("GolemSolder_Attack_Right");
		break;
	case golem_Solder_State::UpAttack:
		AnimationCheck("GolemSolder_Attack_Up");
		break;
	case golem_Solder_State::DownAttack:
		AnimationCheck("GolemSolder_Attack_Down");
		break;
	case golem_Solder_State::AttackCheck:
		
		break;
	}

}

void golem_Solder::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case golem_Solder_State::Start:
		DirCheckUpdate(_Time);
		break;
	case golem_Solder_State::LeftWalk:
		LeftMoveUpdate(_Time);
		break;
	case golem_Solder_State::RightWalk:
		RightMoveUpdate(_Time);
		break;
	case golem_Solder_State::UpWalk:
		UpMoveUpdate(_Time);
		break;
	case golem_Solder_State::DownWalk:
		DownMoveUpdate(_Time);
		break;
	case golem_Solder_State::LeftAttack:
		LeftAttackUpdate(_Time);
		break;
	case golem_Solder_State::RightAttack:
		RightAttackUpdate(_Time);
		break;
	case golem_Solder_State::UpAttack:
		UpAttackUpdate(_Time);
		break;
	case golem_Solder_State::DownAttack:
		DownAttackUpdate(_Time);
		break;
	case golem_Solder_State::AttackCheck:
		Dir_Attack_Check_Update(_Time);
		break;
	default:
		break;
	}
}

void golem_Solder::DirCheckUpdate(float _Time)
{
	if (degree >= 0)
	{
		if (degree <= 45)
		{
			ChangeState(golem_Solder_State::LeftWalk);
			return;
		}
	}
	if (degree < 360)
	{
		if (degree >= 315)
		{
			ChangeState(golem_Solder_State::LeftWalk);
			return;
		}
	}
	if (degree <= 135)
	{
		if (degree > 45)
		{

			ChangeState(golem_Solder_State::UpWalk);
			return;
		}
	}
	if (degree <= 225)
	{
		if (degree > 135)
		{
			ChangeState(golem_Solder_State::RightWalk);
			return;
		}
	}
	if (degree <= 315)
	{
		if (degree > 225)
		{
			ChangeState(golem_Solder_State::DownWalk);
			return;
		}
	}





}

void golem_Solder::Dir_Attack_Check_Update(float _Time)
{
	if (degree >= 0)
	{
		if (degree <= 45)
		{
			ChangeState(golem_Solder_State::LeftWalk);
			return;
		}
	}
	if (degree < 360)
	{
		if (degree >= 315)
		{
			ChangeState(golem_Solder_State::LeftWalk);
			return;
		}
	}
	if (degree <= 135)
	{
		if (degree > 45)
		{

			ChangeState(golem_Solder_State::UpWalk);
			return;
		}
	}
	if (degree <= 225)
	{
		if (degree > 135)
		{
			ChangeState(golem_Solder_State::RightWalk);
			return;
		}
	}
	if (degree <= 315)
	{
		if (degree > 225)
		{
			ChangeState(golem_Solder_State::DownWalk);
			return;
		}
	}


}



void golem_Solder::LeftMoveUpdate(float _Time)
{
	
	


	MoveDir = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
	MoveDir.Normalize();

	if (Weapon_Collision_Check == false && Mini_Col->Collision(ContentsCollisionType::MiniCol) == false)
	{
		Transform.AddLocalPosition(MoveDir * Speed * _Time);
	}

	if (Mini_Col->Collision(ContentsCollisionType::MiniCol))
	{
		Transform.AddLocalPosition({ -MoveDir * Speed * _Time });
	}



	if (Col->Collision(ContentsCollisionType::Player))
	{

		ChangeState(golem_Solder_State::LeftAttack);
		return;
	}

	if (Time > 1.0f)
	{
		if (degree >= 0)
		{
			if (degree <= 45)
			{
				ChangeState(golem_Solder_State::LeftWalk);
				return;
			}
		}
		if (degree < 360)
		{
			if (degree >= 315)
			{
				ChangeState(golem_Solder_State::LeftWalk);
				return;
			}
		}
		if (degree <= 135)
		{
			if (degree > 45)
			{

				ChangeState(golem_Solder_State::UpWalk);
				return;
			}
		}
		if (degree <= 225)
		{
			if (degree > 135)
			{
				ChangeState(golem_Solder_State::RightWalk);
				return;
			}
		}
		if (degree <= 315)
		{
			if (degree > 225)
			{
				ChangeState(golem_Solder_State::DownWalk);
				return;
			}
		}
		
		
	}
}

void golem_Solder::RightMoveUpdate(float _Time)
{
	


	MoveDir = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
	MoveDir.Normalize();

	if (Weapon_Collision_Check == false)
	{
		Transform.AddLocalPosition(MoveDir * Speed * _Time);
	}
	if (Mini_Col->Collision(ContentsCollisionType::MiniCol))
	{
		Transform.AddLocalPosition({ -MoveDir * Speed * _Time });
	}


	if (Col->Collision(ContentsCollisionType::Player))
	{
		ChangeState(golem_Solder_State::RightAttack);
		return;
	}

	if (Time > 1.0f)
	{
		if (degree >= 0)
		{
			if (degree <= 45)
			{
				ChangeState(golem_Solder_State::LeftWalk);
				return;
			}
		}
		if (degree < 360)
		{
			if (degree >= 315)
			{
				ChangeState(golem_Solder_State::LeftWalk);
				return;
			}
		}
		if (degree <= 135)
		{
			if (degree > 45)
			{

				ChangeState(golem_Solder_State::UpWalk);
				return;
			}
		}
		if (degree <= 225)
		{
			if (degree > 135)
			{
				ChangeState(golem_Solder_State::RightWalk);
				return;
			}
		}
		if (degree <= 315)
		{
			if (degree > 225)
			{
				ChangeState(golem_Solder_State::DownWalk);
				return;
			}
		}
		
	}
}

void golem_Solder::UpMoveUpdate(float _Time)
{
	
	
	MoveDir = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
	MoveDir.Normalize();

	if (Weapon_Collision_Check == false)
	{
		Transform.AddLocalPosition(MoveDir * Speed * _Time);
	}

	if (Mini_Col->Collision(ContentsCollisionType::MiniCol))
	{
		Transform.AddLocalPosition({ -MoveDir * Speed * _Time });
	}

	if (Col->Collision(ContentsCollisionType::Player))
	{
		ChangeState(golem_Solder_State::UpAttack);
		return;
	}


	if (Time > 1.0f)
	{

		if (degree >= 0)
		{
			if (degree <= 45)
			{
				ChangeState(golem_Solder_State::LeftWalk);
				return;
			}
		}
		if (degree < 360)
		{
			if (degree >= 315)
			{
				ChangeState(golem_Solder_State::LeftWalk);
				return;
			}
		}
		if (degree <= 135)
		{
			if (degree > 45)
			{

				ChangeState(golem_Solder_State::UpWalk);
				return;
			}
		}
		if (degree <= 225)
		{
			if (degree > 135)
			{
				ChangeState(golem_Solder_State::RightWalk);
				return;
			}
		}
		if (degree <= 315)
		{
			if (degree > 225)
			{
				ChangeState(golem_Solder_State::DownWalk);
				return;
			}
		}

		
	}
}

void golem_Solder::DownMoveUpdate(float _Time)
{
	


	MoveDir = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
	MoveDir.Normalize();


	if (Weapon_Collision_Check == false)
	{
		Transform.AddLocalPosition(MoveDir * Speed * _Time);
	}
	if (Mini_Col->Collision(ContentsCollisionType::MiniCol))
	{
		Transform.AddLocalPosition({ -MoveDir * Speed * _Time });
	}



	if (Time > 1.0f)
	{
		if (degree >= 0)
		{
			if (degree <= 45)
			{
				ChangeState(golem_Solder_State::LeftWalk);
				return;
			}
		}
		if (degree < 360)
		{
			if (degree >= 315)
			{
				ChangeState(golem_Solder_State::LeftWalk);
				return;
			}
		}
		if (degree <= 135)
		{
			if (degree > 45)
			{

				ChangeState(golem_Solder_State::UpWalk);
				return;
			}
		}
		if (degree <= 225)
		{
			if (degree > 135)
			{
				ChangeState(golem_Solder_State::RightWalk);
				return;
			}
		}
		if (degree <= 315)
		{
			if (degree > 225)
			{
				ChangeState(golem_Solder_State::DownWalk);
				return;
			}
		}



		if (Col->Collision(ContentsCollisionType::Player))
		{
			
			ChangeState(golem_Solder_State::DownAttack);
			return;
		}
	}

}

void golem_Solder::LeftAttackUpdate(float _Time)
{
	


	if (Solder->IsCurAnimationEnd())
	{
		Time = 0.0f;
	
		ChangeState(golem_Solder_State::AttackCheck);
		return;
	}

}

void golem_Solder::RightAttackUpdate(float _Time)
{
	if (Solder->IsCurAnimationEnd())
	{
		Time = 0.0f;
	
		ChangeState(golem_Solder_State::AttackCheck);
		return;


	}

}

void golem_Solder::UpAttackUpdate(float _Time)
{
	if (Solder->IsCurAnimationEnd())
	{


		Time = 0.0f;


		ChangeState(golem_Solder_State::AttackCheck);
		return;


	}

}

void golem_Solder::DownAttackUpdate(float _Time)
{
	if (Solder->IsCurAnimationEnd())
	{
		Time = 0.0f;

		ChangeState(golem_Solder_State::AttackCheck);
		return;



	}

}
