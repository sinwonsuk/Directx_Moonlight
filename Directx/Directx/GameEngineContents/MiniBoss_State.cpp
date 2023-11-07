#include "PreCompile.h"
#include "MiniBoss.h"
#include "Player.h"
	


void MiniBoss::ChangeState(MiniBoss_State _State)
{
	MiniBoss_State NextState = _State;
	MiniBoss_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case MiniBoss_State::Start:

		break;
	case MiniBoss_State::LeftWalk:
		AnimationCheck("Mini_Boss_Move_Left");
		break;
	case MiniBoss_State::RightWalk:
		AnimationCheck("Mini_Boss_Move_Right");
		break;
	case MiniBoss_State::UpWalk:
		AnimationCheck("Mini_Boss_Move_Up");
		break;
	case MiniBoss_State::DownWalk:
		AnimationCheck("Mini_Boss_Move_Down");
		break;
	case MiniBoss_State::LeftAttack:
		AnimationCheck("Mini_Boss_Attack_Left");
		break;
	case MiniBoss_State::RightAttack:
		AnimationCheck("Mini_Boss_Attack_Right");
		break;
	case MiniBoss_State::UpAttack:
		AnimationCheck("Mini_Boss_Attack_Up");
		break;
	case MiniBoss_State::DownAttack:
		AnimationCheck("Mini_Boss_Attack_Down");
		break;
	case MiniBoss_State::AttackCheck:
		
		break;
	}

}

void MiniBoss::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case MiniBoss_State::Start:
		DirCheckUpdate(_Time);
		break;
	case MiniBoss_State::LeftWalk:
		LeftMoveUpdate(_Time);
		break;
	case MiniBoss_State::RightWalk:
		RightMoveUpdate(_Time);
		break;
	case MiniBoss_State::UpWalk:
		UpMoveUpdate(_Time);
		break;
	case MiniBoss_State::DownWalk:
		DownMoveUpdate(_Time);
		break;
	case MiniBoss_State::LeftAttack:
		LeftAttackUpdate(_Time);
		break;
	case MiniBoss_State::RightAttack:
		RightAttackUpdate(_Time);
		break;
	case MiniBoss_State::UpAttack:
		UpAttackUpdate(_Time);
		break;
	case MiniBoss_State::DownAttack:
		DownAttackUpdate(_Time);
		break;
	case MiniBoss_State::AttackCheck:
		Dir_Attack_Check_Update(_Time);
		break;
	default:
		break;
	}
}

void MiniBoss::DirCheckUpdate(float _Time)
{

	


	

	if (degree >= 0)
	{
		if (degree <= 45)
		{
			ChangeState(MiniBoss_State::LeftWalk);
			return;
		}
	}
	if (degree < 360)
	{
		if (degree >= 315)
		{
			ChangeState(MiniBoss_State::LeftWalk);
			return;
		}
	}
	if (degree <= 135)
	{
		if (degree > 45)
		{

			ChangeState(MiniBoss_State::UpWalk);
			return;
		}
	}
	if (degree <= 225)
	{
		if (degree > 135)
		{
			ChangeState(MiniBoss_State::RightWalk);
			return;
		}
	}
	if (degree <= 315)
	{
		if (degree > 225)
		{
			ChangeState(MiniBoss_State::DownWalk);
			return;
		}
	}





}

void MiniBoss::Dir_Attack_Check_Update(float _Time)
{
	if (degree >= 0)
	{
		if (degree <= 45)
		{
			ChangeState(MiniBoss_State::LeftWalk);
			return;
		}
	}
	if (degree < 360)
	{
		if (degree >= 315)
		{
			ChangeState(MiniBoss_State::LeftWalk);
			return;
		}
	}
	if (degree <= 135)
	{
		if (degree > 45)
		{

			ChangeState(MiniBoss_State::UpWalk);
			return;
		}
	}
	if (degree <= 225)
	{
		if (degree > 135)
		{
			ChangeState(MiniBoss_State::RightWalk);
			return;
		}
	}
	if (degree <= 315)
	{
		if (degree > 225)
		{
			ChangeState(MiniBoss_State::DownWalk);
			return;
		}
	}


}



void MiniBoss::LeftMoveUpdate(float _Time)
{
	if (Time > 1.0f)
	{
		if (degree >= 0)
		{
			if (degree <= 45)
			{
				ChangeState(MiniBoss_State::LeftWalk);
			
			}
		}
		if (degree < 360)
		{
			if (degree >= 315)
			{
				ChangeState(MiniBoss_State::LeftWalk);
			
			}
		}
		if (degree <= 135)
		{
			if (degree > 45)
			{

				ChangeState(MiniBoss_State::UpWalk);
			
			}
		}
		if (degree <= 225)
		{
			if (degree > 135)
			{
				ChangeState(MiniBoss_State::RightWalk);
			
			}
		}
		if (degree <= 315)
		{
			if (degree > 225)
			{
				ChangeState(MiniBoss_State::DownWalk);
		
			}
		}
		
		if (Weapon_Collision_Check == false)
		{
			Transform.AddLocalPosition(Manager_Speed);
		}
		


		if (Col->Collision(ContentsCollisionType::Player))
		{
			Monster_Weapon->Transform.AddLocalPosition({ -100.0f,0.0f });
			ChangeState(MiniBoss_State::LeftAttack);
			return;
		}
	}
}

void MiniBoss::RightMoveUpdate(float _Time)
{
	
	if (Time > 1.0f)
	{
		if (degree >= 0)
		{
			if (degree <= 45)
			{
				ChangeState(MiniBoss_State::LeftWalk);

			}
		}
		if (degree < 360)
		{
			if (degree >= 315)
			{
				ChangeState(MiniBoss_State::LeftWalk);

			}
		}
		if (degree <= 135)
		{
			if (degree > 45)
			{

				ChangeState(MiniBoss_State::UpWalk);

			}
		}
		if (degree <= 225)
		{
			if (degree > 135)
			{
				ChangeState(MiniBoss_State::RightWalk);

			}
		}
		if (degree <= 315)
		{
			if (degree > 225)
			{
				ChangeState(MiniBoss_State::DownWalk);

			}
		}
		if (Weapon_Collision_Check == false)
		{
			Transform.AddLocalPosition(Manager_Speed);
		}


		if (Col->Collision(ContentsCollisionType::Player))
		{
			Monster_Weapon->Transform.AddLocalPosition({ 100.0f,0.0f });
			ChangeState(MiniBoss_State::RightAttack);
			return;
		}
	}
}

void MiniBoss::UpMoveUpdate(float _Time)
{
	if (Time > 1.0f)
	{

		if (degree >= 0)
		{
			if (degree <= 45)
			{
				ChangeState(MiniBoss_State::LeftWalk);

			}
		}
		if (degree < 360)
		{
			if (degree >= 315)
			{
				ChangeState(MiniBoss_State::LeftWalk);

			}
		}
		if (degree <= 135)
		{
			if (degree > 45)
			{

				ChangeState(MiniBoss_State::UpWalk);

			}
		}
		if (degree <= 225)
		{
			if (degree > 135)
			{
				ChangeState(MiniBoss_State::RightWalk);

			}
		}
		if (degree <= 315)
		{
			if (degree > 225)
			{
				ChangeState(MiniBoss_State::DownWalk);

			}
		}

		if (Weapon_Collision_Check == false)
		{
			Transform.AddLocalPosition(Manager_Speed);
		}




		if (Col->Collision(ContentsCollisionType::Player))
		{
			Monster_Weapon->Transform.AddLocalPosition({ 0.0f,100.0f });
			ChangeState(MiniBoss_State::UpAttack);
			return;
		}
	}
}

void MiniBoss::DownMoveUpdate(float _Time)
{
	if (Time > 1.0f)
	{
		if (degree >= 0)
		{
			if (degree <= 45)
			{
				ChangeState(MiniBoss_State::LeftWalk);

			}
		}
		if (degree < 360)
		{
			if (degree >= 315)
			{
				ChangeState(MiniBoss_State::LeftWalk);

			}
		}
		if (degree <= 135)
		{
			if (degree > 45)
			{

				ChangeState(MiniBoss_State::UpWalk);

			}
		}
		if (degree <= 225)
		{
			if (degree > 135)
			{
				ChangeState(MiniBoss_State::RightWalk);

			}
		}
		if (degree <= 315)
		{
			if (degree > 225)
			{
				ChangeState(MiniBoss_State::DownWalk);

			}
		}

		if (Weapon_Collision_Check == false)
		{
			Transform.AddLocalPosition(Manager_Speed);
		}




		if (Col->Collision(ContentsCollisionType::Player))
		{
			Monster_Weapon->Transform.AddLocalPosition({ 0.0f,-100.0f });
			ChangeState(MiniBoss_State::DownAttack);
			return;
		}
	}

}

void MiniBoss::LeftAttackUpdate(float _Time)
{
	if (Mini_Boss->GetCurIndex() > 4)
	{
		if (Mini_Boss->GetCurIndex() < 8)
		{
			Monster_Weapon->On();
		}
	}
	else
	{
		Monster_Weapon->Off();
	}
	

	if (Mini_Boss->IsCurAnimationEnd())
	{
		Time = 0.0f;
		Monster_Weapon->Off();
		Monster_Weapon->Transform.AddLocalPosition({ 100.0f,0.0f });
		ChangeState(MiniBoss_State::AttackCheck);
		return;
	}

}

void MiniBoss::RightAttackUpdate(float _Time)
{
	
	if (Mini_Boss->GetCurIndex() > 4)
	{
		if (Mini_Boss->GetCurIndex() < 8)
		{
			Monster_Weapon->On();
		}
	}

	else
	{
		Monster_Weapon->Off();
	}

	if (Mini_Boss->IsCurAnimationEnd())
	{
		Time = 0.0f;
		Monster_Weapon->Off();
		Monster_Weapon->Transform.AddLocalPosition({ -100.0f,0.0f });
		ChangeState(MiniBoss_State::AttackCheck);
		return;
	}

}

void MiniBoss::UpAttackUpdate(float _Time)
{
	
	if (Mini_Boss->GetCurIndex() > 4)
	{
		if (Mini_Boss->GetCurIndex() < 8)
		{
			Monster_Weapon->On();
		}
	}
	else
	{
		Monster_Weapon->Off();
	}

	if (Mini_Boss->IsCurAnimationEnd())
	{
		Time = 0.0f;
		Monster_Weapon->Transform.AddLocalPosition({ 0.0f,-100.0f });
		Monster_Weapon->Off();
		ChangeState(MiniBoss_State::AttackCheck);
		return;
	}

}

void MiniBoss::DownAttackUpdate(float _Time)
{
	
	if (Mini_Boss->GetCurIndex() > 4)
	{
		if (Mini_Boss->GetCurIndex() < 8)
		{
			Monster_Weapon->On();
		}
	}
	else
	{
		Monster_Weapon->Off();
	}

	if (Mini_Boss->IsCurAnimationEnd())
	{
		Time = 0.0f;
		Monster_Weapon->Transform.AddLocalPosition({ 0.0f,100.0f });
		Monster_Weapon->Off();
		ChangeState(MiniBoss_State::AttackCheck);
		return;
	}

}
