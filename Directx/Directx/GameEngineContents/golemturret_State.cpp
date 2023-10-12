#include "PreCompile.h"
#include "golemturret.h"
#include "golemturret_missile.h"
#include <GameEngineCore/GameEngineLevel.h>
void golemturret::ChangeState(golemturret_State _State)
{
	golemturret_State NextState = _State;
	golemturret_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case golemturret_State::UpAttack:
		AnimationCheck("GolemTurretBroken_shot_up");
		break;
	case golemturret_State::DownAttack:
		AnimationCheck("GolemTurretBroken_shot_down");
		break;

	default:
		break;
	}

}

void golemturret::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case golemturret_State::UpAttack:
		UpAttackUpdate(_Time);
		break;
	case golemturret_State::DownAttack:
		DownAttackUpdate(_Time);
		break;

	default:
		break;
	}
}

void golemturret::DownAttackUpdate(float _Time)
{
	if (turret->IsCurAnimationEnd())
	{
		std::shared_ptr<golemturret_missile> object = GetLevel()->CreateActor<golemturret_missile>();
		object->Transform.SetLocalPosition(Transform.GetWorldPosition());
		object->dir = Dir::Down;
	}
}

void golemturret::UpAttackUpdate(float _Time)
{
	if (turret->IsCurAnimationEnd())
	{	
		std::shared_ptr<golemturret_missile> object = GetLevel()->CreateActor<golemturret_missile>();
		object->Transform.SetLocalPosition(Transform.GetWorldPosition());
		object->Transform.SetLocalRotation({ 0.0f,0.0f,180.0f }); 

		object->dir = Dir::Up;
	}
}
