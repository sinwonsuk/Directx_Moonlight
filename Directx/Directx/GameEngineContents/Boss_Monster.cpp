#include "PreCompile.h"
#include "Boss_Monster.h"

Boss_Monster::Boss_Monster()
{
}

Boss_Monster::~Boss_Monster()
{
}

void Boss_Monster::Start()
{
	Boss = CreateComponent<GameEngineSpriteRenderer>(100);
	Boss->CreateAnimation("Wake_Up", "Wake_Up", 0.1f, -1, -1, false);
	Boss->CreateAnimation("Idle", "Idle", 0.1f, -1, -1, true);





	Boss->CreateAnimation("Death", "Death", 0.1f, -1, -1, true);	
	Boss->AutoSpriteSizeOn();
	Boss->SetAutoScaleRatio(2.0f);
	Boss->ChangeAnimation("Wake_Up");
	Boss->AnimationPauseOn(); 


}

void Boss_Monster::Update(float _Delta)
{

}

void Boss_Monster::AnimationCheck(const std::string_view& _AnimationName)
{
	Boss->ChangeAnimation(_AnimationName);
}
