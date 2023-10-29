#include "PreCompile.h"
#include "Boss_Monster.h"
#include "Player.h"



void Boss_Monster::ChangeState(Boss_Monster_State _State)
{
	Boss_Monster_State NextState = _State;
	Boss_Monster_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case Boss_Monster_State::WakeUp:
		AnimationCheck("babyslime_walk");
		break;

	}

}

void Boss_Monster::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case Boss_Monster_State::WakeUp:
		Wake_Up_Update(_Time);
		break;
	default:
		break;
	}
}

void Boss_Monster::Wake_Up_Update(float _Time)
{


	if (Player::this_Player->Transform.GetLocalPosition().Y - 100 < Transform.GetLocalPosition().Y)
	{
		Boss->AnimationPauseOff(); 
	}
	
}
