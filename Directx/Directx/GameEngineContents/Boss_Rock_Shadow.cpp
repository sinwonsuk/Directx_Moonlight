#include "PreCompile.h"
#include "Boss_Rock_Shadow.h"

Boss_Rock_Shadow::Boss_Rock_Shadow()
{
}

Boss_Rock_Shadow::~Boss_Rock_Shadow()
{
}

void Boss_Rock_Shadow::Start()
{
	Shadow = CreateComponent<GameEngineSpriteRenderer>();
	Shadow->SetSprite("Boos1_Rock_Shadow", 0);
	Shadow->AutoSpriteSizeOn();
	Shadow->SetAutoScaleRatio(2.0f);

}
void Boss_Rock_Shadow::Update(float _Delta)
{


}
