#include "PreCompile.h"
#include "Boss_Brick.h"

Boss_Brick::Boss_Brick()
{

}

Boss_Brick::~Boss_Brick()
{

}

void Boss_Brick::Start()
{
	Brick = CreateComponent<GameEngineSpriteRenderer>();
	Brick->SetSprite("Brick", 0); 
	Brick->AutoSpriteSizeOn();
	Brick->SetAutoScaleRatio(2.0f);
}

void Boss_Brick::Update(float _Delta)
{

}
