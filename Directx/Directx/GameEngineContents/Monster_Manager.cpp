#include "PreCompile.h"
#include "Monster_Manager.h"
#include "TileMap.h"
#include "Player.h"
Monster_Manager::Monster_Manager()
{


}

Monster_Manager::~Monster_Manager()
{


}

void Monster_Manager::MonsterCollision(float _Delta, std::string_view _Name)
{

}

float4 Monster_Manager::Monster_Move(float _Delta,float4 _GetWorldTransform, std::string_view _Name ,float4 _distance_fixation)
{
	


	if (test == 30)
	{
		PathPos = TileMap::Map->GetPath(_GetWorldTransform- _distance_fixation, Player::this_Player->Transform.GetWorldPosition()- _distance_fixation, _Name);
		test = 0;
	}
		
	
	test++;

	if (GameEngineInput::IsDown('8', this))
	{
		PathPos = TileMap::Map->GetPath(_GetWorldTransform, Player::this_Player->Transform.GetWorldPosition(), _Name);
		thisPos = _GetWorldTransform;
	}


	if (PathPos.size() > 0)
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


			


			if (Brick_Size.Y == 32 && Brick_Size.X == 40)
			{
				if (thisPos.Y + 32 <= _GetWorldTransform.Y && thisPos.X + 40 <= _GetWorldTransform.X)
				{
					thisPos = _GetWorldTransform;
					PathPos.pop_front();
					return Speed;
				}
			}

			else if (Brick_Size.Y == -32 && Brick_Size.X == -40)
			{
				if (thisPos.Y - 32 >= _GetWorldTransform.Y && thisPos.X - 40 >= _GetWorldTransform.X)
				{
					thisPos = _GetWorldTransform;
					PathPos.pop_front();
					return Speed;
				}
			}

			else if (Brick_Size.Y == -32 && Brick_Size.X == 40)
			{
				if (thisPos.Y - 32 >= _GetWorldTransform.Y && thisPos.X + 40 <= _GetWorldTransform.X)
				{
					thisPos = _GetWorldTransform;
					PathPos.pop_front();
					return Speed;
				}
			}

			else if (Brick_Size.Y == 32 && Brick_Size.X == -40)
			{
				if (thisPos.Y + 32 <= _GetWorldTransform.Y && thisPos.X - 40 >= _GetWorldTransform.X)
				{
					thisPos = _GetWorldTransform;
					PathPos.pop_front();
					return Speed;
				}
			}


			else if (Brick_Size.Y == 32)
			{
				if (thisPos.Y + 32 <= _GetWorldTransform.Y)
				{
					thisPos = _GetWorldTransform;
					PathPos.pop_front();
					return Speed;
				}
			}
			else if (Brick_Size.Y == -32)
			{
				if (thisPos.Y - 32 >= _GetWorldTransform.Y)
				{
					thisPos = _GetWorldTransform;
					PathPos.pop_front();
					return Speed;
				}
			}

			else if (Brick_Size.X == 40)
			{
				if (thisPos.X + 40 <= _GetWorldTransform.X)
				{
					thisPos = _GetWorldTransform;
					PathPos.pop_front();
					return Speed;
				}
			}
			else if (Brick_Size.X == -40)
			{
				if (thisPos.X - 40 >= _GetWorldTransform.X)
				{
					thisPos = _GetWorldTransform;
					PathPos.pop_front();
					return Speed;
				}
			}

			return Speed;
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
	return {0,0,0,1};
}
