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
	
	{
		std::shared_ptr<GameEngineSpriteRenderer> FontRender = CreateComponent<GameEngineSpriteRenderer>(500);
		FontRender->SetText("����", "�ȳ��ϼ���", 50.0f, float4::BLUE, FW1_CENTER);
		//FontRender->Transform.SetLocalScale({ 400,400 });
	
	}
}

void MonsterTest::Update(float _Delta)
{
	std::string_view name = "Dungeon_Map_Pixel_013.png";
	//float4 AD = Monster_Move(_Delta,Transform.GetWorldPosition(), "Dungeon_Map_Pixel_013.png");



	//Transform.AddWorldPosition(AD);

	//PathPos = TileMap::Map->GetPath(Transform.GetWorldPosition(), Player::this_Player->Transform.GetWorldPosition());

	//if (GameEngineInput::IsDown('8', this))
	//{
	//	PathPos = TileMap::Map->GetPath(Transform.GetWorldPosition(), Player::this_Player->Transform.GetWorldPosition());
	//	thisPos = Transform.GetWorldPosition();
	//}

	//	
	// if( PathPos.size() > 0)
	// {
	//	std::list<float4>::iterator begin_iter = PathPos.begin(); 
	//	std::list<float4>::iterator end_iter = PathPos.end(); 
	//
	//	*begin_iter++;

	//	if (begin_iter != end_iter)
	//	{
	//		float4 Pos = PathPos.front();
	//		

	//		float4 Pos2 = *begin_iter;


	//		Brick_Size = Pos2 - Pos;

	//		float4 Speed = Brick_Size.NormalizeReturn() * _Delta * 100.0f;


	//		Transform.AddWorldPosition(Speed);


	//		if (Brick_Size.Y ==32 && Brick_Size.X == 40)
	//		{
	//			if (thisPos.Y + 32 <= Transform.GetWorldPosition().Y && thisPos.X + 40 <= Transform.GetWorldPosition().X)
	//			{
	//				thisPos = Transform.GetWorldPosition();
	//				PathPos.pop_front();
	//				return;
	//			}
	//		}

	//		else if (Brick_Size.Y == -32 && Brick_Size.X == -40)
	//		{
	//			if (thisPos.Y - 32 >= Transform.GetWorldPosition().Y && thisPos.X - 40 >= Transform.GetWorldPosition().X)
	//			{
	//				thisPos = Transform.GetWorldPosition();
	//				PathPos.pop_front();
	//				return;
	//			}
	//		}

	//		else if (Brick_Size.Y == -32 && Brick_Size.X == 40)
	//		{
	//			if (thisPos.Y - 32 >= Transform.GetWorldPosition().Y && thisPos.X + 40 <= Transform.GetWorldPosition().X)
	//			{
	//				thisPos = Transform.GetWorldPosition();
	//				PathPos.pop_front();
	//				return;
	//			}
	//		}

	//		else if (Brick_Size.Y == 32 && Brick_Size.X == -40)
	//		{
	//			if (thisPos.Y + 32 <= Transform.GetWorldPosition().Y && thisPos.X - 40 >= Transform.GetWorldPosition().X)
	//			{
	//				thisPos = Transform.GetWorldPosition();
	//				PathPos.pop_front();
	//				return;
	//			}
	//		}


	//		else if (Brick_Size.Y == 32)
	//		{
	//			if (thisPos.Y + 32 <= Transform.GetWorldPosition().Y)
	//			{
	//				thisPos = Transform.GetWorldPosition();
	//				PathPos.pop_front();
	//				return;
	//			}
	//		}
	//		else if (Brick_Size.Y == -32)
	//		{
	//			if (thisPos.Y - 32 >= Transform.GetWorldPosition().Y)
	//			{
	//				thisPos = Transform.GetWorldPosition();
	//				PathPos.pop_front();
	//				return;
	//			}
	//		}

	//		else if (Brick_Size.X == 40)
	//		{
	//			if (thisPos.X + 40 <= Transform.GetWorldPosition().X)
	//			{
	//				thisPos = Transform.GetWorldPosition();
	//				PathPos.pop_front();
	//				return;
	//			}
	//		}
	//		else if (Brick_Size.X == -40)
	//		{
	//			if (thisPos.X - 40 >= Transform.GetWorldPosition().X)
	//			{
	//				thisPos = Transform.GetWorldPosition();
	//				PathPos.pop_front();
	//				return;
	//			}
	//		}






	//		//if (AD.Y > 0)
	//		//{
	//		//	if (AD.X > 0)
	//		//	{
	//		//		if (Pos2.Y < Transform.GetWorldPosition().Y)
	//		//		{
	//		//			if (Pos2.X < Transform.GetWorldPosition().X)
	//		//			{
	//		//				thisPos = Transform.GetWorldPosition();
	//		//				PathPos.pop_front();
	//		//				return;
	//		//			}
	//		//		}

	//		//	}
	//		//}

	//		//if (AD.Y > 0)
	//		//{
	//		//	if (AD.X < 0)
	//		//	{
	//		//		if (Pos2.Y < Transform.GetWorldPosition().Y)
	//		//		{
	//		//			if (Pos2.X > Transform.GetWorldPosition().X)
	//		//			{
	//		//				thisPos = Transform.GetWorldPosition();
	//		//				PathPos.pop_front();
	//		//				return;
	//		//			}
	//		//		}

	//		//	}
	//		//}

	//		//if (AD.Y < 0)
	//		//{
	//		//	if (AD.X < 0)
	//		//	{
	//		//		if (Pos2.Y > Transform.GetWorldPosition().Y)
	//		//		{
	//		//			if (Pos2.X > Transform.GetWorldPosition().X)
	//		//			{
	//		//				thisPos = Transform.GetWorldPosition();
	//		//				PathPos.pop_front();
	//		//				return;
	//		//			}
	//		//		}

	//		//	}
	//		//}


	//		//if (AD.Y < 0)
	//		//{
	//		//	if (AD.X > 0)
	//		//	{
	//		//		if (Pos2.Y > Transform.GetWorldPosition().Y)
	//		//		{
	//		//			if (Pos2.X < Transform.GetWorldPosition().X)
	//		//			{
	//		//				thisPos = Transform.GetWorldPosition();
	//		//				PathPos.pop_front();
	//		//				return;
	//		//			}
	//		//		}

	//		//	}
	//		//}


	//		//if (AD.X > 0)
	//		//{
	//		//	if (Pos2.X < Transform.GetWorldPosition().X)
	//		//	{

	//		//		PathPos.pop_front();
	//		//		return;
	//		//	}
	//		//}

	//		//else if (AD.X < 0)
	//		//{
	//		//	if (Pos2.X > Transform.GetWorldPosition().X)
	//		//	{

	//		//		PathPos.pop_front();
	//		//		return;
	//		//	}
	//		//}
	//		//else if (AD.Y > 0)
	//		//{
	//		//	if (Pos2.Y < Transform.GetWorldPosition().Y)
	//		//	{

	//		//		PathPos.pop_front();
	//		//		return;
	//		//	}
	//		//}

	//		//else if (AD.Y < 0)
	//		//{

	//		//	if (Pos2.Y > Transform.GetWorldPosition().Y)
	//		//	{

	//		//		PathPos.pop_front();
	//		//		return;
	//		//	}
	//		//}

	//	}

	//		

 //            /*  PathTime -= _Delta; 

 //             if (PathTime <= 0.0f)
 //             {
 //             	float4 Pos = PathPos.front();
 //             	Transform.SetLocalPosition(Pos);
 //             	PathPos.pop_front();
 //             	PathTime = 0.5f;
 //             }*/
 //
	//	

	//	}



		

		

	

	//float4 Move = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
	//Transform.AddLocalPosition({ Move.NormalizeReturn() * 150.0f * _Delta });
	


}
