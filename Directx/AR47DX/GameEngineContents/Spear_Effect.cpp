#include "PreCompile.h"
#include "Spear_Effect.h"

Spear_Effect::Spear_Effect()
{
}

Spear_Effect::~Spear_Effect()
{
}

void Spear_Effect::Start()
{
	Efffet = CreateComponent<GameEngineSpriteRenderer>(101);
	Efffet->CreateAnimation("spearHitEffect_3", "spearHitEffect_3.png", 0.1f, -1, -1, false);
	Efffet->AutoSpriteSizeOn();
	Efffet->SetAutoScaleRatio(1.5f);
	Efffet->ChangeAnimation("spearHitEffect_3");


}

void Spear_Effect::Update(float _Delta)
{
	if (Efffet->IsCurAnimationEnd())
	{
		this->Death(); 
	}
}
