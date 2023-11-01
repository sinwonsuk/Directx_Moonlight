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
	GameEngineInput::AddInputObject(this); 
	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y });

	Monster = CreateComponent<GameEngineSpriteRenderer>(); 
	Monster->SetSprite("Boss1_Punch_1", 0);
	Monster->Transform.AddLocalPosition({ 20.0f,30.0f });
	

}

void MonsterTest::Update(float _Delta)
{
	PathPos = TileMap::Map->GetPath(Transform.GetWorldPosition(), Player::this_Player->Transform.GetWorldPosition());

	if (GameEngineInput::IsDown('8', this))
	{
		PathPos = TileMap::Map->GetPath(Transform.GetWorldPosition(), Player::this_Player->Transform.GetWorldPosition());
		thisPos = Transform.GetWorldPosition();
	}
	// 이건 내가 플레이어를 향해서 길을 가다가 막혔을때 

	// 플레이어의 타일 인덱스가 바뀌었을때

	// 일정시간마다 
	/*if (0 == PathPos.size())
	{
		PathPos = TileMap::Map->GetPath(Transform.GetWorldPosition(), Player::this_Player->Transform.GetWorldPosition());
		thisPos = Transform.GetWorldPosition();
	}*/ 
	
		
	 if( PathPos.size() > 0)
	{
		std::list<float4>::iterator begin_iter = PathPos.begin(); 
		std::list<float4>::iterator end_iter = PathPos.end(); 


	
		
		

		

		
		
		*begin_iter++;

		if (begin_iter != end_iter)
		{
			float4 Pos = PathPos.front();
			

			float4 Pos2 = *begin_iter;


			Brick_Size = Pos2 - Pos;

			float4 Speed = Brick_Size.NormalizeReturn() * _Delta * 100.0f;


			Transform.AddWorldPosition(Speed);


			if (Brick_Size.Y == 40 && Brick_Size.X == 40)
			{
				if (thisPos.Y + 40 <= Transform.GetWorldPosition().Y && thisPos.X + 40 <= Transform.GetWorldPosition().X)
				{
					thisPos = Transform.GetWorldPosition();
					PathPos.pop_front();
					return;
				}
			}

			else if (Brick_Size.Y == -40 && Brick_Size.X == -40)
			{
				if (thisPos.Y - 40 >= Transform.GetWorldPosition().Y && thisPos.X - 40 >= Transform.GetWorldPosition().X)
				{
					thisPos = Transform.GetWorldPosition();
					PathPos.pop_front();
					return;
				}
			}

			else if (Brick_Size.Y == -40 && Brick_Size.X == 40)
			{
				if (thisPos.Y - 40 >= Transform.GetWorldPosition().Y && thisPos.X + 40 <= Transform.GetWorldPosition().X)
				{
					thisPos = Transform.GetWorldPosition();
					PathPos.pop_front();
					return;
				}
			}

			else if (Brick_Size.Y == 40 && Brick_Size.X == -40)
			{
				if (thisPos.Y + 40 <= Transform.GetWorldPosition().Y && thisPos.X - 40 >= Transform.GetWorldPosition().X)
				{
					thisPos = Transform.GetWorldPosition();
					PathPos.pop_front();
					return;
				}
			}


			else if (Brick_Size.Y == 40)
			{
				if (thisPos.Y + 40 <= Transform.GetWorldPosition().Y)
				{
					thisPos = Transform.GetWorldPosition();
					PathPos.pop_front();
					return;
				}
			}
			else if (Brick_Size.Y == -40)
			{
				if (thisPos.Y - 40 >= Transform.GetWorldPosition().Y)
				{
					thisPos = Transform.GetWorldPosition();
					PathPos.pop_front();
					return;
				}
			}

			else if (Brick_Size.X == 40)
			{
				if (thisPos.X + 40 <= Transform.GetWorldPosition().X)
				{
					thisPos = Transform.GetWorldPosition();
					PathPos.pop_front();
					return;
				}
			}
			else if (Brick_Size.X == -40)
			{
				if (thisPos.X - 40 >= Transform.GetWorldPosition().X)
				{
					thisPos = Transform.GetWorldPosition();
					PathPos.pop_front();
					return;
				}
			}






			//if (AD.Y > 0)
			//{
			//	if (AD.X > 0)
			//	{
			//		if (Pos2.Y < Transform.GetWorldPosition().Y)
			//		{
			//			if (Pos2.X < Transform.GetWorldPosition().X)
			//			{
			//				thisPos = Transform.GetWorldPosition();
			//				PathPos.pop_front();
			//				return;
			//			}
			//		}

			//	}
			//}

			//if (AD.Y > 0)
			//{
			//	if (AD.X < 0)
			//	{
			//		if (Pos2.Y < Transform.GetWorldPosition().Y)
			//		{
			//			if (Pos2.X > Transform.GetWorldPosition().X)
			//			{
			//				thisPos = Transform.GetWorldPosition();
			//				PathPos.pop_front();
			//				return;
			//			}
			//		}

			//	}
			//}

			//if (AD.Y < 0)
			//{
			//	if (AD.X < 0)
			//	{
			//		if (Pos2.Y > Transform.GetWorldPosition().Y)
			//		{
			//			if (Pos2.X > Transform.GetWorldPosition().X)
			//			{
			//				thisPos = Transform.GetWorldPosition();
			//				PathPos.pop_front();
			//				return;
			//			}
			//		}

			//	}
			//}


			//if (AD.Y < 0)
			//{
			//	if (AD.X > 0)
			//	{
			//		if (Pos2.Y > Transform.GetWorldPosition().Y)
			//		{
			//			if (Pos2.X < Transform.GetWorldPosition().X)
			//			{
			//				thisPos = Transform.GetWorldPosition();
			//				PathPos.pop_front();
			//				return;
			//			}
			//		}

			//	}
			//}


			//if (AD.X > 0)
			//{
			//	if (Pos2.X < Transform.GetWorldPosition().X)
			//	{

			//		PathPos.pop_front();
			//		return;
			//	}
			//}

			//else if (AD.X < 0)
			//{
			//	if (Pos2.X > Transform.GetWorldPosition().X)
			//	{

			//		PathPos.pop_front();
			//		return;
			//	}
			//}
			//else if (AD.Y > 0)
			//{
			//	if (Pos2.Y < Transform.GetWorldPosition().Y)
			//	{

			//		PathPos.pop_front();
			//		return;
			//	}
			//}

			//else if (AD.Y < 0)
			//{

			//	if (Pos2.Y > Transform.GetWorldPosition().Y)
			//	{

			//		PathPos.pop_front();
			//		return;
			//	}
			//}

		}

			

             /*  PathTime -= _Delta; 

              if (PathTime <= 0.0f)
              {
              	float4 Pos = PathPos.front();
              	Transform.SetLocalPosition(Pos);
              	PathPos.pop_front();
              	PathTime = 0.5f;
              }*/
 
		

		}



		

		

	

	//float4 Move = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
	//Transform.AddLocalPosition({ Move.NormalizeReturn() * 150.0f * _Delta });
	


}
