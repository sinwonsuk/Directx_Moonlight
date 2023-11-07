#include "PreCompile.h"
#include "Boss_Map.h"
#include "Boss_Monster.h"
Boss_Map::Boss_Map()
{

}

Boss_Map::~Boss_Map()
{

}

void Boss_Map::Start()
{

	{
		BackGround = CreateComponent<GameEngineSpriteRenderer>(-50);
		BackGround->SetSprite("background_boss room", 0);
		BackGround->AutoSpriteSizeOn();
		BackGround->SetAutoScaleRatio(2.0f);
	}

	
	

}

void Boss_Map::Update(float _Delta)
{
	if(BossCheck ==false)
	{
		Monster = GetLevel()->CreateActor<Boss_Monster>(3);
		Monster->Transform.SetLocalPosition({ Transform.GetLocalPosition().X,Transform.GetLocalPosition().Y + 300.0f });
		BossCheck = true;
	}
}
