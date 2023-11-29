#include "PreCompile.h"
#include "golemkamikaze.h"
#include "Player.h"

void golemkamikaze::ChangeState(golemkamikaze_State _State)
{
	golemkamikaze_State NextState = _State;
	golemkamikaze_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case golemkamikaze_State::Walk:
		AnimationCheck("golemkamikaze_walk");
		break;
	case golemkamikaze_State::Stop:
		AnimationCheck("golemkamikaze_wake");
		break;
	case golemkamikaze_State::Jump:
		AnimationCheck("golemkamikaze_jump");
		break;
	}

}

void golemkamikaze::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case golemkamikaze_State::Walk:
		WalkUpdate(_Time);
		break;
	case golemkamikaze_State::Stop:
		StopUpdate(_Time);
		break;
	case golemkamikaze_State::Jump:
		JumpUpdate(_Time);
		break;
	default:
		break;
	}
}

void golemkamikaze::WalkUpdate(float _Time)
{





	Transform.AddLocalPosition({ Manager_Speed });

	if (Range_Col->Collision(ContentsCollisionType::Player))
	{
		ChangeState(golemkamikaze_State::Stop);
		return; 
	}

}

void golemkamikaze::StopUpdate(float _Time)
{
	if (Monster->IsCurAnimationEnd())
	{
		MoveDir = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
		Player_Pos = Player::this_Player->Transform.GetWorldPosition();
		MoveDir.Normalize();


		if (Player_Pos.X < Transform.GetWorldPosition().X)
		{
			Monster_Pos = false;
		}

		else if (Player_Pos.X > Transform.GetWorldPosition().X)
		{
			Monster_Pos = true;
		}


		ChangeState(golemkamikaze_State::Jump);
		return;
	}
}

void golemkamikaze::JumpUpdate(float _Time)
{
	
	if (Monster->GetCurIndex() > 17)
	{
		Col->Off();
		Hp = 0;
		this->Off();
	}

	if (Monster->GetCurIndex() > 8)
	{
		if (Monster->GetCurIndex() < 17)
		{
			
			if (Attack_Sound_Check == false)
			{
				Attack_Sound = GameEngineSound::SoundPlay("golem_dungeon_kamikaze_explosion.wav");
				Attack_Sound.SetVolume(2.0f);
				Attack_Sound_Check = true;
			}
			Col->On();
		}
	}



	
	


	

	if (Monster_Pos == false)
	{
		if (Player_Pos.X < Transform.GetWorldPosition().X)
		{
			Transform.AddWorldPosition({ MoveDir * _Time * Speed });
		}


	}
	else if (Monster_Pos == true)
	{
		if (Player_Pos.X > Transform.GetWorldPosition().X)
		{
			Transform.AddWorldPosition({ MoveDir * _Time * Speed });
		}
	}
	
	

}
