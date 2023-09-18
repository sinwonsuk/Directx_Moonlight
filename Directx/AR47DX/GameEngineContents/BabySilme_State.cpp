#include "PreCompile.h"
#include "BabySlime.h"
#include "Player.h"
void BabySlime::ChangeState(BabySlime_State _State)
{
	BabySlime_State NextState = _State;
	BabySlime_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case BabySlime_State::Walk:
		AnimationCheck("babyslime_walk");
		break;

	}

}

void BabySlime::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case BabySlime_State::Walk:
		WalkUpdate(_Time); 
		break;
	default:
		break;
	}
}

void BabySlime::WalkUpdate(float _Time)
{

	float4 Move = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
	//Move.NormalizeReturn();
	//float4 Move = -float4::LerpClamp(Transform.GetWorldPosition(), Player::this_Player->Transform.GetWorldPosition(),_Time);


	

	Transform.AddLocalPosition({ Move.NormalizeReturn() * 100.0f * _Time }); 


}
