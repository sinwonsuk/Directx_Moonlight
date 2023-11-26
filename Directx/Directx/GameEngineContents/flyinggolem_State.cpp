#include "PreCompile.h"
#include "flyinggolem.h"
#include "Player.h"
void flyinggolem::ChangeState(flyinggolem_State _State)
{
	flyinggolem_State NextState = _State;
	flyinggolem_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case flyinggolem_State::Walk:
		AnimationCheck("babyslime_walk");
		break;

	}

}

void flyinggolem::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case flyinggolem_State::Walk:
		WalkUpdate(_Time);
		break;
	default:
		break;
	}
}

void flyinggolem::WalkUpdate(float _Time)
{

	Transform.AddLocalPosition({ Manager_Speed });

}

void flyinggolem::AnimationCheck(const std::string_view& _AnimationName)
{
	Monster->ChangeAnimation(_AnimationName);
}
