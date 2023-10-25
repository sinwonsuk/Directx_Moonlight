#include "PreCompile.h"
#include "gloem_Wazard_Missile.h"

gloem_Wazard_Missile::gloem_Wazard_Missile()
{
}

gloem_Wazard_Missile::~gloem_Wazard_Missile()
{
}

void gloem_Wazard_Missile::Start()
{
	Missile = CreateComponent<GameEngineSpriteRenderer>(200);
	Missile->CreateAnimation("golemturret_Attack", "golemturret_Attack", 0.1f, -1, -1, true);
	Missile->CreateAnimation("golemturret_Attack_Finish", "golemturret_Attack_Finish", 0.1f, -1, -1, false);

	Missile->AutoSpriteSizeOn();
	Missile->SetAutoScaleRatio(3.5f);
	Missile->ChangeAnimation("golemturret_Attack");

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });

	{
		Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::GolemStone);
		Col->Transform.SetLocalScale({ 20.0f,20.0f });
	}
}

void gloem_Wazard_Missile::Update(float _Delta)
{
	
	UpdateState(_Delta);
}
void gloem_Wazard_Missile::AnimationCheck(const std::string_view& _AnimationName)
{
	Missile->ChangeAnimation(_AnimationName);
}
