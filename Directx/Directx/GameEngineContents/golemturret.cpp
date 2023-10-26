#include "PreCompile.h"
#include "golemturret.h"

golemturret::golemturret()
{

}

golemturret::~golemturret()
{

}






void golemturret::AnimationCheck(const std::string_view& _AnimationName)
{
	turret->ChangeAnimation(_AnimationName);
}

void golemturret::Start()
{
	turret = CreateComponent<GameEngineSpriteRenderer>(100);
	turret->CreateAnimation("GolemTurretBroken_shot_down", "GolemTurretBroken_shot_down", 0.05f, -1, -1, true);
	turret->CreateAnimation("GolemTurretBroken_shot_up", "GolemTurretBroken_shot_up", 0.05f, -1, -1, true);

	turret->AutoSpriteSizeOn();
	turret->SetAutoScaleRatio(2.0f);
	turret->ChangeAnimation("GolemTurretBroken_shot_down");



	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y });



	/*{
		Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::BabySlime);
		Col->Transform.SetLocalScale({ 15.0f,15.0f });
	}*/


}

void golemturret::Update(float _Delta)
{
	
		UpdateState(_Delta);
	
}
