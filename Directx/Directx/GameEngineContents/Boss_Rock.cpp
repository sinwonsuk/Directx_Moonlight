#include "PreCompile.h"
#include "Boss_Rock.h"

Boss_Rock::Boss_Rock()
{
}

Boss_Rock::~Boss_Rock()
{
}

void Boss_Rock::Start()
{
	Rock = CreateComponent<GameEngineSpriteRenderer>();
	Rock->SetSprite("Boos1_Rock", 0);
	Rock->AutoSpriteSizeOn(); 
	Rock->SetAutoScaleRatio(2.0f); 

	
}

void Boss_Rock::Update(float _Delta)
{

}
