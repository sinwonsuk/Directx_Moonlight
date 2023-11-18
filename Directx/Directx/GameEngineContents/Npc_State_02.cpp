#include "PreCompile.h"
#include "NPC.h"



void Npc::UpdateState_02(float _Time)
{

	switch (StateValue)
	{
	case Npc_State::Start:
		StartUpdate_02(_Time);
		break;
	case Npc_State::RightIdle:
		RightIdleUpdate_02(_Time);
		break;
	case Npc_State::LeftIdle:
		LeftIdleUpdate_02(_Time);
		break;
	case Npc_State::UpIdle:
		UpIdleUpdate_02(_Time);
		break;
	case Npc_State::DownIdle:
		DownIdleUpdate_02(_Time);
		break;
	case Npc_State::LeftMove:
		LeftMoveUpdate_02(_Time);
		break;
	case Npc_State::RightMove:
		RightMoveUpdate_02(_Time);
		break;
	case Npc_State::DownMove:
		DownMoveUpdate_02(_Time);
		break;
	case Npc_State::UpMove:
		UpMoveUpdate_02(_Time);
		break;
	default:
		break;
	}
}


void Npc::StartUpdate_02(float _Time)
{
	float4 Dir = { 695.000000,-640 };
	float4 Dir2 = { 580.5,-538 };

	float4 Dir3 = Dir - Dir2;
	Dir3.Normalize();

	Transform.AddLocalPosition({ Dir3 * _Time * Speed });

}

void Npc::RightIdleUpdate_02(float _Time)
{


}

void Npc::LeftIdleUpdate_02(float _Time)
{
	Time += _Time;

	if (Time > 1)
	{


		Time = 0;
		ChangeState(Npc_State::RightMove);
		return;
	}

}

void Npc::DownIdleUpdate_02(float _Time)
{


}

void Npc::UpIdleUpdate_02(float _Time)
{
	Time += _Time;

	if (Time > 1 && Check ==0 )
	{
		Check++;
		Time = 0;
		ChangeState(Npc_State::RightMove);
		return;
	}

	if (Time > 1 && Check == 1)
	{
		Time = 0;
		ChangeState(Npc_State::DownMove);
		return;

	}

}

void Npc::RightMoveUpdate_02(float _Time)
{

	Transform.AddLocalPosition({ float4::RIGHT * _Time * Speed });

	if (Transform.GetWorldPosition().X > 580)
	{
		ChangeState(Npc_State::UpMove);
		return;
	}

}

void Npc::LeftMoveUpdate_02(float _Time)
{
	float4 Dir = { 695.000000,-640 };
	float4 Dir2 = { 484,-603 };
	float4 Dir3 = Dir2 - Dir;
	Dir3.Normalize();

	Transform.AddLocalPosition({ Dir3 * _Time * Speed });

	if (Transform.GetWorldPosition().X < 484)
	{
		ChangeState(Npc_State::UpIdle);
		return;
	}

}

void Npc::DownMoveUpdate_02(float _Time)
{
	Transform.AddLocalPosition({ float4::DOWN * _Time * Speed });

	if (Transform.GetWorldPosition().Y < -640)
	{
		ChangeState(Npc_State::DownIdle);
		return;
	}

}

void Npc::UpMoveUpdate_02(float _Time)
{
	float4 Dir = { 678, -552 };
	float4 Dir2 = { 580,-610 };
	float4 Dir3 = Dir -Dir2;
	Dir3.Normalize();

	Transform.AddLocalPosition({ Dir3 * _Time * Speed });

	if (Transform.GetWorldPosition().X > 685)
	{
		ChangeState(Npc_State::UpIdle);
		return;
	}
}