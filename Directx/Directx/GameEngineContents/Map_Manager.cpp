#include "PreCompile.h"
#include "Map_Manager.h"
#include "Player.h"
Map_Manager::Map_Manager()
{
}

Map_Manager::~Map_Manager()
{
}

GameEngineColor Map_Manager::GetColor(float4 _Pos, GameEngineColor _DefaultColor, std::string_view _Name)
{
	_Pos.Y *= -1.0f;

	std::shared_ptr<GameEngineTexture> Tex = GameEngineTexture::Find(_Name);

	return Tex->GetColor(_Pos, _DefaultColor);
}

void Map_Manager::ObjectCollision(float _Delta, std::string_view _Name)
{
	float4 Left_Player_Pos = { Player::this_Player->Transform.GetWorldPosition().X - 20.0f,Player::this_Player->Transform.GetWorldPosition().Y };
	float4 Right_Player_Pos = { Player::this_Player->Transform.GetWorldPosition().X + 20.0f,Player::this_Player->Transform.GetWorldPosition().Y };
	float4 Up_Player_Pos = { Player::this_Player->Transform.GetWorldPosition().X,Player::this_Player->Transform.GetWorldPosition().Y + 20.0f };
	float4 Down_Player_Pos = { Player::this_Player->Transform.GetWorldPosition().X ,Player::this_Player->Transform.GetWorldPosition().Y - 20.0f };
	float4 UpLeft_Player_Pos = { Player::this_Player->Transform.GetWorldPosition().X - 20.0f,Player::this_Player->Transform.GetWorldPosition().Y + 20.0f };
	float4 DownLeft_Player_Pos = { Player::this_Player->Transform.GetWorldPosition().X - 20.0f,Player::this_Player->Transform.GetWorldPosition().Y - 20.0f };
	float4 UpRight_Player_Pos = { Player::this_Player->Transform.GetWorldPosition().X + 20.0f,Player::this_Player->Transform.GetWorldPosition().Y + 20.0f };
	float4 DownRight_Player_Pos = { Player::this_Player->Transform.GetWorldPosition().X + 20.0f,Player::this_Player->Transform.GetWorldPosition().Y - 20.0f };




	if (GameEngineColor::MAGENTA == GetColor({ Left_Player_Pos }, { 255,0,0,255 }, _Name))
	{
		Player::this_Player->LeftMove = false;
	}
	else
	{
		Player::this_Player->LeftMove = true;
	}

	if (GameEngineColor::MAGENTA == GetColor({ Right_Player_Pos }, { 255,0,0,255 }, _Name))
	{
		Player::this_Player->RightMove = false;
	}
	else
	{
		Player::this_Player->RightMove = true;
	}


	if (GameEngineColor::BLUE == GetColor({ Up_Player_Pos }, { 255, 0, 0, 255 }, _Name))
	{
		Player::this_Player->UpMove = false;
	}
	else
	{
		Player::this_Player->UpMove = true;
	}

	if (GameEngineColor::BLUE == GetColor({ Down_Player_Pos }, { 255, 0, 0, 255 }, _Name))
	{
		Player::this_Player->DownMove = false;
	}

	else
	{
		Player::this_Player->DownMove = true;
	}

	if (GameEngineColor::BLUE == GetColor({ Left_Player_Pos }, { 255,0,0,255 }, _Name))
	{
		Player::this_Player->LeftMove = false;
	}
	else
	{
		Player::this_Player->LeftMove = true;
	}

	if (GameEngineColor::BLUE == GetColor({ Right_Player_Pos }, { 255,0,0,255 }, _Name))
	{
		Player::this_Player->RightMove = false;
	}
	else
	{
		Player::this_Player->RightMove = true;
	}


	if (GameEngineColor::BLUE == GetColor({ Up_Player_Pos }, { 255, 0, 0, 255 }, _Name))
	{
		Player::this_Player->UpMove = false;
	}
	else
	{
		Player::this_Player->UpMove = true;
	}

	if (GameEngineColor::BLUE == GetColor({ Down_Player_Pos }, { 255, 0, 0, 255 }, _Name))
	{
		Player::this_Player->DownMove = false;
	}

	else
	{
		Player::this_Player->DownMove = true;
	}



	if (GameEngineColor::GREEN == GetColor({ Right_Player_Pos }, { 255,0,0,255 }, _Name))
	{
		Player::this_Player->RightMove = false;
	}
	else
	{
		Player::this_Player->RightMove = true;
	}




	if (GameEngineColor::GREEN == GetColor({ Left_Player_Pos }, { 0,0,255,255 }, _Name))
	{
		Player::this_Player->Speed = 0.0f;
		Player::this_Player->Transform.AddLocalPosition(float4::RIGHT * 20.0f * _Delta);
	}
	else if (GameEngineColor::GREEN == GetColor({ Right_Player_Pos }, { 0,0,255,255 }, _Name))
	{
		Player::this_Player->Speed = 0.0f;
		Player::this_Player->Transform.AddLocalPosition(float4::LEFT * 20.0f * _Delta);
	}
	else if (GameEngineColor::GREEN == GetColor({ Up_Player_Pos }, { 0, 0, 255, 255 }, _Name))
	{
		Player::this_Player->Speed = 0.0f;
		Player::this_Player->Transform.AddLocalPosition(float4::DOWN * 20.0f * _Delta);
	}
	else if (GameEngineColor::GREEN == GetColor({ Down_Player_Pos }, { 0, 0, 255, 255 }, _Name))
	{
		Player::this_Player->Speed = 0.0f;
		Player::this_Player->Transform.AddLocalPosition(float4::UP * 20.0f * _Delta);
	}
	else
	{
		Player::this_Player->Roll_Speed = 400.0f;
		Player::this_Player->Speed = 300.0f;
	}











}

void Map_Manager::DoorCollision(float _Delta, float _MapNumber)
{



	/*if (Player::this_Player->Col->Collision(ContentsCollisionType::Door))
	{
		Door_Collison_Check = true;
		Player::this_Player->Transform.AddLocalPosition(300.0f);

	}


	float4 Camera_Move = float4::LerpClamp(0, 1280, _Delta);

	if (Player::this_Player->GetLevel()->GetMainCamera()->Transform.GetWorldPosition().X < 1280 * (1.5 + _MapNumber) && Door_Collison_Check == true)
	{
		Player::this_Player->GetLevel()->GetMainCamera()->Transform.AddLocalPosition(Camera_Move);
	}*/

}
