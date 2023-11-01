#include "PreCompile.h"
#include "MonsterTest.h"
#include "Player.h"
#include "TileMap.h"

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

	// 이건 내가 플레이어를 향해서 길을 가다가 막혔을때 

	// 플레이어의 타일 인덱스가 바뀌었을때

	// 일정시간마다 
	if (0 == PathPos.size())
	{
		PathPos = TileMap::Map->GetPath(Transform.GetWorldPosition(), Player::this_Player->Transform.GetWorldPosition());
	} 
	else
	{
		PathTime -= _Delta;

		if (PathTime <= 0.0f)
		{
			float4 Pos = PathPos.front();
			Transform.SetLocalPosition(Pos);
			PathPos.pop_front();
			PathTime = 0.1f;
		}
	}

	

	//float4 Move = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
	//Transform.AddLocalPosition({ Move.NormalizeReturn() * 150.0f * _Delta });
	


}
