#include "PreCompile.h"
#include "MonsterTest.h"
#include "Player.h"
MonsterTest::MonsterTest()
{


}

MonsterTest::~MonsterTest()
{


}

void MonsterTest::Start()
{

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y });

	Monster = CreateComponent<GameEngineSpriteRenderer>(); 
	Monster->SetSprite("Boss1_Punch_1", 0);



}

void MonsterTest::Update(float _Delta)
{

	float4 Move = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();



	Transform.AddLocalPosition({ Move.NormalizeReturn() * 150.0f * _Delta });
	


}
