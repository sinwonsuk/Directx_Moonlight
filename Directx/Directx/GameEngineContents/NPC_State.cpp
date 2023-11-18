#include "PreCompile.h"
#include "NPC.h"
#include "Emoticon.h"
#include "Shop_UI.h"
#include "Shop_Item.h"
void Npc::ChangeState(Npc_State _State)
{
	Npc_State NextState = _State;
	Npc_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case Npc_State::Start:
		AnimationCheck("Start");
		break;
	case Npc_State::Start_Stop:
		break;
	case Npc_State::RightIdle:
		AnimationCheck("Npc_Right_Idle");
		break;
	case Npc_State::LeftIdle:
		AnimationCheck("Npc_Left_Idle");
		break;
	case Npc_State::UpIdle:
		AnimationCheck("Npc_Up_Idle");
		break;
	case Npc_State::DownIdle:
		AnimationCheck("Npc_Down_Idle");
		break;
	case Npc_State::LeftMove:
		AnimationCheck("Npc_Left_Move");
		break;
	case Npc_State::RightMove:
		AnimationCheck("Npc_Right_Move");
		break;
	case Npc_State::DownMove:
		AnimationCheck("Npc_Down_Move");
		break;
	case Npc_State::UpMove:
		AnimationCheck("Npc_Up_Move");
		break;

	}

}

void Npc::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case Npc_State::Start:
		StartUpdate_01(_Time);
		break;
	case Npc_State::RightIdle:
		RightIdleUpdate_01(_Time);
		break;
	case Npc_State::LeftIdle:
		LeftIdleUpdate_01(_Time);
		break;
	case Npc_State::UpIdle:
		UpIdleUpdate_01(_Time);
		break;
	case Npc_State::DownIdle:
		DownIdleUpdate_01(_Time);
		break;
	case Npc_State::LeftMove:
		LeftMoveUpdate_01(_Time);
		break;
	case Npc_State::RightMove:
		RightMoveUpdate_01(_Time);
		break;
	case Npc_State::DownMove:
		DownMoveUpdate_01(_Time);
		break;
	case Npc_State::UpMove:
		UpMoveUpdate_01(_Time);
		break;	
	default:
		break;
	}
}


void Npc::StartUpdate_01(float _Time)
{
	float4 Dir = { 695.000000,-640 };
	float4 Dir2 = { 580.5,-538};

	float4 Dir3 = Dir - Dir2;
	Dir3.Normalize();

	Transform.AddLocalPosition({ Dir3 * _Time * Speed });

}

void Npc::RightIdleUpdate_01(float _Time)
{


}

void Npc::LeftIdleUpdate_01(float _Time)
{
	Time += _Time; 

	if (Time > 4.5)
	{
		

		Time = 0;
		ChangeState(Npc_State::RightMove);
		return; 
	}

}

void Npc::DownIdleUpdate_01(float _Time)
{


}

void Npc::UpIdleUpdate_01(float _Time)
{
	Time += _Time;

	if (Time > 1)
	{
		Time = 0;
		ChangeState(Npc_State::DownMove);
		return;
	}

}

void Npc::RightMoveUpdate_01(float _Time)
{
	
	Transform.AddLocalPosition({ float4::RIGHT * _Time * Speed });

	if (Transform.GetWorldPosition().X > 686)
	{
		ChangeState(Npc_State::UpIdle);
		return; 
	}

}

void Npc::LeftMoveUpdate_01(float _Time)
{
	float4 Dir = { 695.000000,-640 };
	float4 Dir2 = { 580.5,-538 };
	float4 Dir3 = Dir2 - Dir;
	Dir3.Normalize();

	Transform.AddLocalPosition({ Dir3 * _Time * Speed });

	if (Transform.GetWorldPosition().X < 582)
	{
		std::shared_ptr<Emoticon> Object = GetLevel()->CreateActor<Emoticon>();
		Object->Transform.SetWorldPosition({ Transform.GetWorldPosition().X + 30,Transform.GetWorldPosition().Y+40.0f });
		ChangeState(Npc_State::LeftIdle);
		return;
	}

}

void Npc::DownMoveUpdate_01(float _Time)
{
	Transform.AddLocalPosition({ float4::DOWN * _Time * Speed });

	if (Transform.GetWorldPosition().Y < -640)
	{
		ChangeState(Npc_State::DownIdle);
		return;
	}

}

void Npc::UpMoveUpdate_01(float _Time)
{
	
}