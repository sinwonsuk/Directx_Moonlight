#include "PreCompile.h"
#include "NPC.h"



void Npc::UpdateState_03(float _Time)
{

	switch (StateValue)
	{
	case Npc_State::Start:
		StartUpdate_03(_Time);
		break;
	case Npc_State::RightIdle:
		RightIdleUpdate_03(_Time);
		break;
	case Npc_State::LeftIdle:
		LeftIdleUpdate_03(_Time);
		break;
	case Npc_State::UpIdle:
		UpIdleUpdate_03(_Time);
		break;
	case Npc_State::DownIdle:
		DownIdleUpdate_03(_Time);
		break;
	case Npc_State::LeftMove:
		LeftMoveUpdate_03(_Time);
		break;
	case Npc_State::RightMove:
		RightMoveUpdate_03(_Time);
		break;
	case Npc_State::DownMove:
		DownMoveUpdate_03(_Time);
		break;
	case Npc_State::UpMove:
		UpMoveUpdate_03(_Time);
		break;
	default:
		break;
	}
}


void Npc::StartUpdate_03(float _Time)
{
	float4 Dir = { 695.000000,-640 };
	float4 Dir2 = { 580.5,-538 };

	float4 Dir3 = Dir - Dir2;
	Dir3.Normalize();

	Transform.AddLocalPosition({ Dir3 * _Time * Speed });

}

void Npc::RightIdleUpdate_03(float _Time)
{


}

void Npc::LeftIdleUpdate_03(float _Time)
{
	Time += _Time;

	if (Time > 1)
	{


		Time = 0;
		ChangeState(Npc_State::RightMove);
		return;
	}

}

void Npc::DownIdleUpdate_03(float _Time)
{


}

void Npc::UpIdleUpdate_03(float _Time)
{
	Time += _Time;

	if (Time > 1)
	{
		Time = 0;
		ChangeState(Npc_State::DownMove);
		return;
	}

}

void Npc::RightMoveUpdate_03(float _Time)
{

	float4 Dir = { 585.9,-485 };
	float4 Dir2 = { 624,-561 };
	float4 Dir3 = Dir2 - Dir;
	Dir3.Normalize();

	if (Transform.GetWorldPosition().X < 615)
	{
		Transform.AddLocalPosition({ Dir3 * _Time * Speed });
	}


	if (Transform.GetWorldPosition().X > 615)
	{
		Transform.AddLocalPosition({ float4::RIGHT * _Time * Speed });
	}

	if (Transform.GetWorldPosition().X > 684)
	{
		ChangeState(Npc_State::UpIdle);
		return; 
	}
	
}

void Npc::LeftMoveUpdate_03(float _Time)
{
	float4 Dir = { 695,-640 };
	float4 Dir2 = { 580.5,-538 };
	float4 Dir3 = Dir2 - Dir;
	Dir3.Normalize();

	Transform.AddLocalPosition({ Dir3 * _Time * Speed });

	if (Transform.GetWorldPosition().X < 582)
	{
		ChangeState(Npc_State::UpMove);
		return;
	}
}

void Npc::DownMoveUpdate_03(float _Time)
{
	Transform.AddLocalPosition({ float4::DOWN * _Time * Speed });

	if (Transform.GetWorldPosition().Y < -640)
	{
		ChangeState(Npc_State::DownIdle);
		return;
	}

}

void Npc::UpMoveUpdate_03(float _Time)
{
	

	Transform.AddLocalPosition({ float4::UP * _Time * Speed });

	if (Transform.GetWorldPosition().Y > -487)
	{
		ChangeState(Npc_State::LeftIdle);
		return;
	}
}