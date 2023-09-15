#include "PreCompile.h"
#include "Tutorial_Map_Manager.h"
#include "Player.h"
#include <GameEngineCore/GameEngineCollisionGroup.h>
int Tutorial_Map_Manager::Map_Check = 0; 
Tutorial_Map_Manager::Tutorial_Map_Manager()
{
}

Tutorial_Map_Manager::~Tutorial_Map_Manager()
{
}

GameEngineColor Tutorial_Map_Manager::GetColor(float4 _Pos, GameEngineColor _DefaultColor, std::string_view _Name)
{
	_Pos.Y *= -1.0f;

	std::shared_ptr<GameEngineTexture> Tex = GameEngineTexture::Find(_Name);

	return Tex->GetColor(_Pos, _DefaultColor);
}

void Tutorial_Map_Manager::ObjectCollision(float _Delta, std::string_view _Name)
{
	float4 Left_Player_Pos = { Player::this_Player->Transform.GetWorldPosition().X + 20.0f,Player::this_Player->Transform.GetWorldPosition().Y };
	float4 Right_Player_Pos = { Player::this_Player->Transform.GetWorldPosition().X - 20.0f,Player::this_Player->Transform.GetWorldPosition().Y };
	float4 Up_Player_Pos = { Player::this_Player->Transform.GetWorldPosition().X,Player::this_Player->Transform.GetWorldPosition().Y +20.0f };
	float4 Down_Player_Pos = { Player::this_Player->Transform.GetWorldPosition().X ,Player::this_Player->Transform.GetWorldPosition().Y - 20.0f };


	if (GameEngineColor::RED != GetColor({ Left_Player_Pos }, { 255,0,0,255 }, _Name))
	{
		Player::this_Player->MoveCheck = true;

		Player::this_Player->Transform.AddLocalPosition(float4::LEFT * 20.0f * _Delta);
	}
	else if (GameEngineColor::RED != GetColor({ Right_Player_Pos }, { 255,0,0,255 }, _Name))
	{
		Player::this_Player->MoveCheck = true;
		Player::this_Player->Transform.AddLocalPosition(float4::RIGHT * 20.0f * _Delta);
	}
	else if (GameEngineColor::RED != GetColor({ Up_Player_Pos }, { 255, 0, 0, 255 }, _Name))
	{
		Player::this_Player->MoveCheck = true;
		Player::this_Player->Transform.AddLocalPosition(float4::DOWN * 20.0f * _Delta);
	}
	else if (GameEngineColor::RED != GetColor({ Down_Player_Pos }, { 255, 0, 0, 255 }, _Name))
	{
		Player::this_Player->MoveCheck = true;
		Player::this_Player->Transform.AddLocalPosition(float4::UP * 20.0f * _Delta);
	}

	else
	{
		Player::this_Player->MoveCheck = false;
	}
}

void Tutorial_Map_Manager::DoorCollision(float _Delta, float _MapNumber)
{
	


	if(Player::this_Player->Col->Collision(ContentsCollisionType::Door))
	{
		Door_Collison_Check = true;
		Player::this_Player->Transform.AddLocalPosition(300.0f);
				
	}
	
	
	float4 Camera_Move = float4::LerpClamp(0, 1280, _Delta); 

	if (Player::this_Player->GetLevel()->GetCamera(0)->Transform.GetWorldPosition().X < 1280*(1.5 + _MapNumber) && Door_Collison_Check ==true)
	{
		Player::this_Player->GetLevel()->GetCamera(0)->Transform.AddLocalPosition(Camera_Move);
	}

}


