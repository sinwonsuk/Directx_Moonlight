#include "PreCompile.h"
#include "golemturret_missile.h"

golemturret_missile::golemturret_missile()
{
}

golemturret_missile::~golemturret_missile()
{
}

void golemturret_missile::Start()
{
	Missile = CreateComponent<GameEngineSpriteRenderer>(100);
	Missile->CreateAnimation("golemturret_Attack", "golemturret_Attack", 0.1f, -1, -1, true);
	Missile->CreateAnimation("golemturret_Attack_Finish", "golemturret_Attack_Finish", 0.1f, -1, -1, true);

	Missile->AutoSpriteSizeOn();
	Missile->SetAutoScaleRatio(2.0f);
	Missile->ChangeAnimation("golemturret_Attack");

	{
		Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Monster_Weapon);
		Col->Transform.SetLocalScale({ 20.0f,20.0f });

	}

}

void golemturret_missile::AnimationCheck(const std::string_view& _AnimationName)
{
	Missile->ChangeAnimation(_AnimationName);
}


void golemturret_missile::Update(float _Delta)
{
	UpdateState(_Delta);
}
