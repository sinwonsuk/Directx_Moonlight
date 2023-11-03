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



	if (ObjectCollision(_Delta, _GetWorldTransform, _Name, _distance_fixation) ==true)
	{
		float4 Speed = Player::this_Player->Transform.GetWorldPosition() - _GetWorldTransform;
		Speed = Speed.NormalizeReturn() * _Delta * 80.0f;
		return Speed;
	}
	
	else if (ObjectCollision(_Delta, _GetWorldTransform, _Name, _distance_fixation) ==false)
	{
		PathPos = TileMap::Map->GetPath(_GetWorldTransform- _distance_fixation, Player::this_Player->Transform.GetWorldPosition()- _distance_fixation, _Name);
		MoveCheck = true;
	}

	if (PathPos.size() == 0)
	{
		MoveCheck = false;
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


			


			if (Brick_Size.Y == 20 && Brick_Size.X == 20)
			{
				if (thisPos.Y + 20 <= _GetWorldTransform.Y && thisPos.X + 20 <= _GetWorldTransform.X)
				{
					thisPos = _GetWorldTransform;
					PathPos.pop_front();
					return Speed;
				}
			}

			else if (Brick_Size.Y == -20 && Brick_Size.X == -20)
			{
				if (thisPos.Y - 20 >= _GetWorldTransform.Y && thisPos.X - 20 >= _GetWorldTransform.X)
				{
					thisPos = _GetWorldTransform;
					PathPos.pop_front();
					return Speed;
				}
			}

			else if (Brick_Size.Y == -20 && Brick_Size.X == 20)
			{
				if (thisPos.Y - 20 >= _GetWorldTransform.Y && thisPos.X + 20 <= _GetWorldTransform.X)
				{
					thisPos = _GetWorldTransform;
					PathPos.pop_front();
					return Speed;
				}
			}

			else if (Brick_Size.Y == 20 && Brick_Size.X == -20)
			{
				if (thisPos.Y + 20 <= _GetWorldTransform.Y && thisPos.X - 20 >= _GetWorldTransform.X)
				{
					thisPos = _GetWorldTransform;
					PathPos.pop_front();
					return Speed;
				}
			}


			else if (Brick_Size.Y == 20)
			{
				if (thisPos.Y + 20 <= _GetWorldTransform.Y)
				{
					thisPos = _GetWorldTransform;
					PathPos.pop_front();
					return Speed;
				}
			}
			else if (Brick_Size.Y == -20)
			{
				if (thisPos.Y - 20 >= _GetWorldTransform.Y)
				{
					thisPos = _GetWorldTransform;
					PathPos.pop_front();
					return Speed;
				}
			}

			else if (Brick_Size.X == 20)
			{
				if (thisPos.X + 20 <= _GetWorldTransform.X)
				{
					thisPos = _GetWorldTransform;
					PathPos.pop_front();
					return Speed;
				}
			}
			else if (Brick_Size.X == -20)
			{
				if (thisPos.X - 20 >= _GetWorldTransform.X)
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


bool Monster_Manager::ObjectCollision(float _Delta, float4 _GetWorldTransform, std::string_view _Name, float4 _distance_fixation)
{

	float4 Left_Player_Pos = { _GetWorldTransform.X - 20.0f,_GetWorldTransform.Y };
	float4 Right_Player_Pos = { _GetWorldTransform.X + 20.0f,_GetWorldTransform.Y };
	float4 Up_Player_Pos = { _GetWorldTransform.X,_GetWorldTransform.Y + 20.0f };
	float4 Down_Player_Pos = { _GetWorldTransform.X ,_GetWorldTransform.Y - 20.0f };

	float4 Ad = { 0,0 };


	if (GameEngineColor::MAGENTA == GetColor({ (Left_Player_Pos - _distance_fixation + Ad) / 20 }, { 255,0,0,255 }, _Name))
	{
		return false;
	}

	else if (GameEngineColor::BLUE == GetColor({ (Left_Player_Pos - _distance_fixation + Ad) / 20 }, { 255,0,0,255 }, _Name))
	{
		return false;
	}

	else
	{
		return true;
	}


	if (GameEngineColor::MAGENTA == GetColor({ (Right_Player_Pos - _distance_fixation + Ad) / 20 }, { 255,0,0,255 }, _Name))
	{
		return false;
	}

	else if (GameEngineColor::BLUE == GetColor({ (Right_Player_Pos - _distance_fixation + Ad) / 20 }, { 255,0,0,255 }, _Name))
	{
		return false;
	}
	else
	{
		return true;
	}





	if (GameEngineColor::MAGENTA == GetColor({ (Up_Player_Pos - _distance_fixation + Ad) / 20 }, { 255, 0, 0, 255 }, _Name))
	{
		return false;
	}

	else if (GameEngineColor::BLUE == GetColor({ (Up_Player_Pos - _distance_fixation + Ad) / 20 }, { 255, 0, 0, 255 }, _Name))
	{
		return false;
	}
	else
	{
		return true;
	}



	if (GameEngineColor::MAGENTA == GetColor({ (Down_Player_Pos - _distance_fixation + Ad) / 20 }, { 255, 0, 0, 255 }, _Name))
	{
		return false;
	}

	else if (GameEngineColor::BLUE == GetColor({ (Down_Player_Pos - _distance_fixation + Ad) / 20 }, { 255, 0, 0, 255 }, _Name))
	{
	return false;
	}

	else
	{
	
	}



	/*if (GameEngineColor::GREEN == GetColor({ Right_Player_Pos - _Transform + AD }, { 255,0,0,255 }, _Name))
	{
		Player::this_Player->RightMove = false;
	}
	else
	{
		Player::this_Player->RightMove = true;
	}*/




	if (GameEngineColor::GREEN == GetColor({ (Left_Player_Pos - _distance_fixation + Ad) / 20 }, { 0,0,255,255 }, _Name))
	{
		
	}
	else if (GameEngineColor::GREEN == GetColor({ (Right_Player_Pos - _distance_fixation + Ad) / 20 }, { 0,0,255,255 }, _Name))
	{
		
	}
	else if (GameEngineColor::GREEN == GetColor({ (Up_Player_Pos - _distance_fixation + Ad) / 20 }, { 0, 0, 255, 255 }, _Name))
	{
		
	}
	else if (GameEngineColor::GREEN == GetColor({ (Down_Player_Pos - _distance_fixation + Ad) / 20 }, { 0, 0, 255, 255 }, _Name))
	{
		
	}
	else
	{
		Player::this_Player->Roll_Speed = 400.0f;
		Player::this_Player->Speed = 300.0f;
	}


}

GameEngineColor Monster_Manager::GetColor(float4 _Pos, GameEngineColor _DefaultColor, std::string_view _Name)
{
	_Pos.Y *= -1.0f;

	std::shared_ptr<GameEngineTexture> Tex = GameEngineTexture::Find(_Name);

	return Tex->GetColor(_Pos, _DefaultColor);
}
