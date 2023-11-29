#include "PreCompile.h"
#include "SlimeHermit.h"
#include "Player.h"
	


void SlimeHermit::ChangeState(SlimeHermit_State _State)
{
	SlimeHermit_State NextState = _State;
	SlimeHermit_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case SlimeHermit_State::Start:

		break;
	case SlimeHermit_State::LeftWalk:
		AnimationCheck("SlimeHermit_Move_Left");
		break;
	case SlimeHermit_State::RightWalk:
		AnimationCheck("SlimeHermit_Move_Left");
		break;
	case SlimeHermit_State::UpWalk:
		AnimationCheck("SlimeHermit_Move_Up");
		break;
	case SlimeHermit_State::DownWalk:
		AnimationCheck("SlimeHermit_Move_Down");
		break;
	case SlimeHermit_State::LeftAttack:
		AnimationCheck("SlimeHermit_Attack_Left");
		break;
	case SlimeHermit_State::RightAttack:
		AnimationCheck("SlimeHermit_Attack_Left");
		break;
	case SlimeHermit_State::UpAttack:
		AnimationCheck("SlimeHermit_Attack_Up");
		break;
	case SlimeHermit_State::DownAttack:
		AnimationCheck("SlimeHermit_Attack_Down");
		break;
	case SlimeHermit_State::AttackCheck:
		
		break;
	}

}

void SlimeHermit::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case SlimeHermit_State::Start:
		DirCheckUpdate(_Time);
		break;
	case SlimeHermit_State::LeftWalk:
		LeftMoveUpdate(_Time);
		break;
	case SlimeHermit_State::RightWalk:
		RightMoveUpdate(_Time);
		break;
	case SlimeHermit_State::UpWalk:
		UpMoveUpdate(_Time);
		break;
	case SlimeHermit_State::DownWalk:
		DownMoveUpdate(_Time);
		break;
	case SlimeHermit_State::LeftAttack:
		LeftAttackUpdate(_Time);
		break;
	case SlimeHermit_State::RightAttack:
		RightAttackUpdate(_Time);
		break;
	case SlimeHermit_State::UpAttack:
		UpAttackUpdate(_Time);
		break;
	case SlimeHermit_State::DownAttack:
		DownAttackUpdate(_Time);
		break;
	case SlimeHermit_State::AttackCheck:
		Dir_Attack_Check_Update(_Time);
		break;
	default:
		break;
	}
}

void SlimeHermit::DirCheckUpdate(float _Time)
{

	


	

	if (degree >= 0)
	{
		if (degree <= 45)
		{
			Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f });
			ChangeState(SlimeHermit_State::LeftWalk);
			return;
		}
	}
	if (degree < 360)
	{
		if (degree >= 315)
		{
			Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f });
			ChangeState(SlimeHermit_State::LeftWalk);
			return;
		}
	}
	if (degree <= 135)
	{
		if (degree > 45)
		{
			Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f });
			ChangeState(SlimeHermit_State::UpWalk);
			return;
		}
	}
	if (degree <= 225)
	{
		if (degree > 135)
		{
			Slime_Hermit->Transform.SetLocalRotation({ 0.0f,180.0f });
			ChangeState(SlimeHermit_State::RightWalk);
			return;
		}
	}
	if (degree <= 315)
	{
		if (degree > 225)
		{
			ChangeState(SlimeHermit_State::DownWalk);
			return;
		}
	}





}

void SlimeHermit::Dir_Attack_Check_Update(float _Time)
{
	if (degree >= 0)
	{
		if (degree <= 45)
		{
			Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f });
			ChangeState(SlimeHermit_State::LeftWalk);
			return;
		}
	}
	if (degree < 360)
	{
		if (degree >= 315)
		{
			Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f });
			ChangeState(SlimeHermit_State::LeftWalk);
			return;
		}
	}
	if (degree <= 135)
	{
		if (degree > 45)
		{
			Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f });
			ChangeState(SlimeHermit_State::UpWalk);
			return;
		}
	}
	if (degree <= 225)
	{
		if (degree > 135)
		{
			Slime_Hermit->Transform.SetLocalRotation({ 0.0f,180.0f });
			ChangeState(SlimeHermit_State::RightWalk);
			return;
		}
	}
	if (degree <= 315)
	{
		if (degree > 225)
		{

			ChangeState(SlimeHermit_State::DownWalk);
			return;
		}
	}


}



void SlimeHermit::LeftMoveUpdate(float _Time)
{
	Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f });

	


	
	if (Time > 1.0f)
	{
		if (degree >= 0)
		{
			if (degree <= 45)
			{
				Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f });
				ChangeState(SlimeHermit_State::LeftWalk);
			
			}
		}
		if (degree < 360)
		{
			if (degree >= 315)
			{
				Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f });
				ChangeState(SlimeHermit_State::LeftWalk);
			
			}
		}
		if (degree <= 135)
		{
			if (degree > 45)
			{
				Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f });
				ChangeState(SlimeHermit_State::UpWalk);
			
			}
		}
		if (degree <= 225)
		{
			if (degree > 135)
			{
				Slime_Hermit->Transform.SetLocalRotation({ 0.0f,180.0f });
				ChangeState(SlimeHermit_State::RightWalk);
			
			}
		}
		if (degree <= 315)
		{
			if (degree > 225)
			{
				Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f });
				ChangeState(SlimeHermit_State::DownWalk);
		
			}
		}
		
		if (Weapon_Collision_Check == false)
		{
			Transform.AddLocalPosition(Manager_Speed);
		}
		


		if (Col->Collision(ContentsCollisionType::Player))
		{
			Monster_Weapon->Transform.AddLocalPosition({ -120.0f,0.0f });
			ChangeState(SlimeHermit_State::LeftAttack);
			return;
		}
	}
}

void SlimeHermit::RightMoveUpdate(float _Time)
{
	
	Slime_Hermit->Transform.SetLocalRotation({ 0.0f,180.0f });

	MoveDir = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
	MoveDir.Normalize();


	if (Time > 1.0f)
	{
		if (degree >= 0)
		{
			if (degree <= 45)
			{
				Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f });
				ChangeState(SlimeHermit_State::LeftWalk);

			}
		}
		if (degree < 360)
		{
			if (degree >= 315)
			{
				Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f });
				ChangeState(SlimeHermit_State::LeftWalk);

			}
		}
		if (degree <= 135)
		{
			if (degree > 45)
			{
				Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f });
				ChangeState(SlimeHermit_State::UpWalk);

			}
		}
		if (degree <= 225)
		{
			if (degree > 135)
			{
				Slime_Hermit->Transform.SetLocalRotation({ 0.0f,180.0f });
				ChangeState(SlimeHermit_State::RightWalk);

			}
		}
		if (degree <= 315)
		{
			if (degree > 225)
			{
				Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f });
				ChangeState(SlimeHermit_State::DownWalk);

			}
		}
		if (Weapon_Collision_Check == false)
		{
			Transform.AddLocalPosition(Manager_Speed);
		}


		if (Col->Collision(ContentsCollisionType::Player))
		{
			Monster_Weapon->Transform.AddLocalPosition({ 120.0f,0.0f });
			ChangeState(SlimeHermit_State::RightAttack);
			return;
		}
	}
}

void SlimeHermit::UpMoveUpdate(float _Time)
{

	
	MoveDir = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
	MoveDir.Normalize();


	if (Time > 1.0f)
	{

		if (degree >= 0)
		{
			if (degree <= 45)
			{
				Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f });
				ChangeState(SlimeHermit_State::LeftWalk);

			}
		}
		if (degree < 360)
		{
			if (degree >= 315)
			{
				Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f });
				ChangeState(SlimeHermit_State::LeftWalk);

			}
		}
		if (degree <= 135)
		{
			if (degree > 45)
			{
				Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f });
				ChangeState(SlimeHermit_State::UpWalk);

			}
		}
		if (degree <= 225)
		{
			if (degree > 135)
			{
				Slime_Hermit->Transform.SetLocalRotation({ 0.0f,180.0f });
				ChangeState(SlimeHermit_State::RightWalk);

			}
		}
		if (degree <= 315)
		{
			if (degree > 225)
			{
				Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f });
				ChangeState(SlimeHermit_State::DownWalk);

			}
		}

		if (Weapon_Collision_Check == false)
		{
			Transform.AddLocalPosition(Manager_Speed);
		}




		if (Col->Collision(ContentsCollisionType::Player))
		{
			Monster_Weapon->Transform.AddLocalPosition({ 0.0f,120.0f });
			ChangeState(SlimeHermit_State::UpAttack);
			return;
		}
	}
}

void SlimeHermit::DownMoveUpdate(float _Time)
{
	


	MoveDir = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
	MoveDir.Normalize();


	if (Time > 1.0f)
	{
		if (degree >= 0)
		{
			if (degree <= 45)
			{
				Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f });
				ChangeState(SlimeHermit_State::LeftWalk);

			}
		}
		if (degree < 360)
		{
			if (degree >= 315)
			{
				Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f });
				ChangeState(SlimeHermit_State::LeftWalk);

			}
		}
		if (degree <= 135)
		{
			if (degree > 45)
			{
				Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f });
				ChangeState(SlimeHermit_State::UpWalk);

			}
		}
		if (degree <= 225)
		{
			if (degree > 135)
			{
				Slime_Hermit->Transform.SetLocalRotation({ 0.0f,180.0f });
				ChangeState(SlimeHermit_State::RightWalk);

			}
		}
		if (degree <= 315)
		{
			if (degree > 225)
			{
				Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f });
				ChangeState(SlimeHermit_State::DownWalk);

			}
		}

		if (Weapon_Collision_Check == false)
		{
			Transform.AddLocalPosition(Manager_Speed);
		}




		if (Col->Collision(ContentsCollisionType::Player))
		{
			Monster_Weapon->Transform.AddLocalPosition({ 0.0f,-120.0f });
			ChangeState(SlimeHermit_State::DownAttack);
			return;
		}
	}

}

void SlimeHermit::LeftAttackUpdate(float _Time)
{
	if (Slime_Hermit->GetCurIndex() > 5)
	{
		if (Slime_Hermit->GetCurIndex() < 9)
		{
			if (Attack_Sound_Check == false)
			{
				Attack_Sound = GameEngineSound::SoundPlay("bigslime_land.wav"); 
				Attack_Sound_Check = true; 
			}


			Monster_Weapon->On();
		}
	}

	else
	{
		Monster_Weapon->Off();
	}


	Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f });


	if (Slime_Hermit->IsCurAnimationEnd())
	{
		Attack_Sound_Check = false;
		Time = 0.0f;
		Monster_Weapon->Off();
		Monster_Weapon->Transform.AddLocalPosition({ 120.0f,0.0f });
		Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f });
		ChangeState(SlimeHermit_State::AttackCheck);
		return;
	}

}

void SlimeHermit::RightAttackUpdate(float _Time)
{
	if (Slime_Hermit->GetCurIndex() > 5)
	{
		if (Slime_Hermit->GetCurIndex() < 9)
		{
			if (Attack_Sound_Check == false)
			{
				Attack_Sound = GameEngineSound::SoundPlay("bigslime_land.wav");
				Attack_Sound_Check = true;
			}


			Monster_Weapon->On();
		}
	}

	else
	{
		Monster_Weapon->Off();
	}


	Slime_Hermit->Transform.SetLocalRotation({ 0.0f,180.0f });

	if (Slime_Hermit->IsCurAnimationEnd())
	{
		Attack_Sound_Check = false;
		Time = 0.0f;
		Monster_Weapon->Off();
		Monster_Weapon->Transform.AddLocalPosition({ -120.0f,0.0f });
		Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f });
		ChangeState(SlimeHermit_State::AttackCheck);
		return;


	}

}

void SlimeHermit::UpAttackUpdate(float _Time)
{

	if (Slime_Hermit->GetCurIndex() > 5)
	{
		if (Slime_Hermit->GetCurIndex() < 9)
		{
			if (Attack_Sound_Check == false)
			{
				Attack_Sound = GameEngineSound::SoundPlay("bigslime_land.wav");
				Attack_Sound_Check = true;
			}

			Monster_Weapon->On();
		}
	}

	else
	{
		Monster_Weapon->Off();
	}


	Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f });
	if (Slime_Hermit->IsCurAnimationEnd())
	{

		Attack_Sound_Check = false;
		Time = 0.0f;
		Monster_Weapon->Transform.AddLocalPosition({ 0.0f,-120.0f });
		Monster_Weapon->Off();
		Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f });
		ChangeState(SlimeHermit_State::AttackCheck);
		return;


	}

}

void SlimeHermit::DownAttackUpdate(float _Time)
{

	if (Slime_Hermit->GetCurIndex() > 5)
	{
		if (Slime_Hermit->GetCurIndex() < 9)
		{
			if (Attack_Sound_Check == false)
			{
				Attack_Sound = GameEngineSound::SoundPlay("bigslime_land.wav");
				Attack_Sound_Check = true;
			}

			Monster_Weapon->On();
		}
	}
	else
	{
		Monster_Weapon->Off();
	}
	

	Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f,0.0f });

	if (Slime_Hermit->IsCurAnimationEnd())
	{
		Time = 0.0f;
		Attack_Sound_Check = false;
		Monster_Weapon->Transform.AddLocalPosition({ 0.0f,120.0f });
		Monster_Weapon->Off();
		Slime_Hermit->Transform.SetLocalRotation({ 0.0f,0.0f });
		ChangeState(SlimeHermit_State::AttackCheck);
		return;



	}

}
