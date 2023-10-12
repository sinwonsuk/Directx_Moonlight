#include "PreCompile.h"
#include "golemturret_missile.h"

void golemturret_missile::ChangeState(golemturret_missile_State _State)
{
	golemturret_missile_State NextState = _State;
	golemturret_missile_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case golemturret_missile_State::Missile:
		AnimationCheck("golemturret_Attack");
		break;
	case golemturret_missile_State::Finish:
		AnimationCheck("golemturret_Attack_Finish");
		break;
	}

}

void golemturret_missile::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case golemturret_missile_State::Missile:
		AttackUpdate(_Time);
		break;
	case golemturret_missile_State::Finish:
		FinishUpdate(_Time);
		break;
	default:
		break;
	}
}

void golemturret_missile::AttackUpdate(float _Time)
{
	switch (dir)
	{
	case Dir::Left:
		Transform.AddLocalPosition({ float4::LEFT * Speed * _Time });
		break;
	case Dir::Right:
		Transform.AddLocalPosition({ float4::RIGHT * Speed * _Time });
		break;
	case Dir::Up:
	{
		Transform.AddLocalPosition({ float4::UP * Speed * _Time });

		if (Transform.GetWorldPosition().Y > -100.0f)
		{
			ChangeState(golemturret_missile_State::Finish); 
			return;
		}
	}
	
		break;
	case Dir::Down:
	{
		Transform.AddLocalPosition({ float4::DOWN * Speed * _Time });

		if (Transform.GetWorldPosition().Y < -620.0f)
		{
			ChangeState(golemturret_missile_State::Finish);
			return;
		}
	}
		break;
	default:
		break;
	}
}

void golemturret_missile::FinishUpdate(float _Time)
{
	if (Missile->IsCurAnimationEnd())
	{
		this->Death(); 

	}
}


