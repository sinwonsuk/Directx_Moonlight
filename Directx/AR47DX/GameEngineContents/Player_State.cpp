#include "PreCompile.h"
#include "Player.h"


void Player::ChangeState(PlayerState _State)
{
	PlayerState NextState = _State;
	PlayerState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case PlayerState::Start:
		AnimationCheck("Start");
		break;
	case PlayerState::Start_Stop:
		break;

	case PlayerState::RightIdle:
		AnimationCheck("RightIdle");
		break;
	case PlayerState::LeftIdle:
		AnimationCheck("LeftIdle");
		break;
	case PlayerState::UpIdle:
		AnimationCheck("UpIdle");
		break;
	case PlayerState::DownIdle:
		AnimationCheck("DownIdle");
		break;
	case PlayerState::LeftMove:
		AnimationCheck("LeftMove");
		break;
	case PlayerState::RightMove:
		AnimationCheck("RightMove");
		break;
	case PlayerState::DownMove:
		AnimationCheck("DownMove");
		break;
	case PlayerState::UpMove:
		AnimationCheck("UpMove");
		break;



	}

}

void Player::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case PlayerState::Start:
		StartUpdate(_Time);
		break;
	case PlayerState::Start_Stop:
		StopUpdate(_Time);
		break;
	case PlayerState::RightIdle:
		RightIdleUpdate(_Time);
		break;
	case PlayerState::LeftIdle:
		LeftIdleUpdate(_Time);
		break;
	case PlayerState::UpIdle:
		UpIdleUpdate(_Time);
		break;
	case PlayerState::DownIdle:
		DownIdleUpdate(_Time);
		break;
	case PlayerState::LeftMove:
		LeftMoveUpdate(_Time);
		break;
	case PlayerState::RightMove:
		RightMoveUpdate(_Time);
		break;
	case PlayerState::DownMove:
		DownMoveUpdate(_Time);
		break;
	case PlayerState::UpMove:
		UpMoveUpdate(_Time);
		break;




	default:
		break;
	}
}
void Player::StartUpdate(float _Time)
{

	Transform.AddLocalPosition(float4::RIGHT * _Time * StartSpeed);
}

void Player::RightIdleUpdate(float _Time)
{
	if (GameEngineInput::IsPress('A'))
	{
		ChangeState(PlayerState::LeftMove);
		return; 
	}

	if (GameEngineInput::IsPress('D'))
	{
		ChangeState(PlayerState::RightMove);
		return;
	}

	if (GameEngineInput::IsPress('W'))
	{
		ChangeState(PlayerState::UpMove);
		return;
	}

	if (GameEngineInput::IsPress('S'))
	{
		ChangeState(PlayerState::DownMove);
		return;
	}
}

void Player::LeftIdleUpdate(float _Time)
{
	if (GameEngineInput::IsPress('A'))
	{
		ChangeState(PlayerState::LeftMove);
		return;
	}

	if (GameEngineInput::IsPress('D'))
	{
		ChangeState(PlayerState::RightMove);
		return;
	}

	if (GameEngineInput::IsPress('W'))
	{
		ChangeState(PlayerState::UpMove);
		return;
	}

	if (GameEngineInput::IsPress('S'))
	{
		ChangeState(PlayerState::DownMove);
		return;
	}
}

void Player::DownIdleUpdate(float _Time)
{
	if (GameEngineInput::IsPress('A'))
	{
		ChangeState(PlayerState::LeftMove);
		return;
	}

	if (GameEngineInput::IsPress('D'))
	{
		ChangeState(PlayerState::RightMove);
		return;
	}

	if (GameEngineInput::IsPress('W'))
	{
		ChangeState(PlayerState::UpMove);
		return;
	}

	if (GameEngineInput::IsPress('S'))
	{
		ChangeState(PlayerState::DownMove);
		return;
	}
}

void Player::UpIdleUpdate(float _Time)
{
	if (GameEngineInput::IsPress('A'))
	{
		ChangeState(PlayerState::LeftMove);
		return;
	}

	if (GameEngineInput::IsPress('D'))
	{
		ChangeState(PlayerState::RightMove);
		return;
	}

	if (GameEngineInput::IsPress('W'))
	{
		ChangeState(PlayerState::UpMove);
		return;
	}

	if (GameEngineInput::IsPress('S'))
	{
		ChangeState(PlayerState::DownMove);
		return;
	}
}

void Player::RightMoveUpdate(float _Time)
{
	Move(_Time);





	if (GameEngineInput::IsUp('D'))
	{
		ChangeState(PlayerState::RightIdle);
		return; 
	}

	if (GameEngineInput::IsDown('W'))
	{
		ChangeState(PlayerState::UpMove);
		return;
	}
	if (GameEngineInput::IsDown('S'))
	{
		ChangeState(PlayerState::DownMove);
		return;
	}
	if (GameEngineInput::IsDown('A'))
	{
		ChangeState(PlayerState::LeftMove);
		return;
	}
}

void Player::LeftMoveUpdate(float _Time)
{


	Move(_Time);

	if (GameEngineInput::IsDown('D'))
	{
		ChangeState(PlayerState::RightMove);
		return;
	}
	if (GameEngineInput::IsDown('W'))
	{
		ChangeState(PlayerState::UpMove);
		return;
	}
	if (GameEngineInput::IsDown('S'))
	{
		ChangeState(PlayerState::DownMove);
		return;
	}
	if (GameEngineInput::IsUp('A'))
	{
		ChangeState(PlayerState::LeftIdle);
		return;
	}
}

void Player::DownMoveUpdate(float _Time)
{
	Move(_Time);

	if (GameEngineInput::IsDown('D'))
	{
		ChangeState(PlayerState::DownIdle);
		return;
	}
	if (GameEngineInput::IsDown('W'))
	{
		ChangeState(PlayerState::UpMove);
		return;
	}
	if (GameEngineInput::IsUp('S'))
	{
		ChangeState(PlayerState::DownMove);
		return;
	}
	if (GameEngineInput::IsDown('A'))
	{
		ChangeState(PlayerState::LeftMove);
		return;
	}
}

void Player::UpMoveUpdate(float _Time)
{
	Move(_Time); 

	if (GameEngineInput::IsDown('D'))
	{
		ChangeState(PlayerState::DownIdle);
		return;
	}
	if (GameEngineInput::IsUp('W'))
	{
		ChangeState(PlayerState::UpIdle);
		return;
	}
	if (GameEngineInput::IsDown('S'))
	{
		ChangeState(PlayerState::DownMove);
		return;
	}
	if (GameEngineInput::IsDown('A'))
	{
		ChangeState(PlayerState::LeftMove);
		return;
	}
}

void Player::Move(float _Delta)
{

	if (GameEngineInput::IsPress('A'))
	{
		Transform.AddLocalPosition(float4::LEFT * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('D'))
	{
		Transform.AddLocalPosition(float4::RIGHT * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('W'))
	{
		Transform.AddLocalPosition(float4::UP * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('S'))
	{
		Transform.AddLocalPosition(float4::DOWN * _Delta * Speed);
	}
}


void Player::StopUpdate(float _Time)
{
	if (player->IsCurAnimationEnd())
	{
		ChangeState(PlayerState::RightIdle);
		return; 
	}
}
