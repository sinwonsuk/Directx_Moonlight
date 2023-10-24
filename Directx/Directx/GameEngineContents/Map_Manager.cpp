#include "PreCompile.h"
#include "Map_Manager.h"
#include "Player.h"
#include <GameEngineCore/GameEngineLevel.h>
#include "Random_Room.h"
int Map_Manager::Map_Check = 1;
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


void Map_Manager::ObjectCollision(float _Delta, std::string_view _Name, float4 _Transform)
{
	










	float4 Left_Player_Pos = { Player::this_Player->Transform.GetWorldPosition().X - 20.0f,Player::this_Player->Transform.GetWorldPosition().Y };
	float4 Right_Player_Pos = { Player::this_Player->Transform.GetWorldPosition().X + 20.0f,Player::this_Player->Transform.GetWorldPosition().Y };
	float4 Up_Player_Pos = { Player::this_Player->Transform.GetWorldPosition().X,Player::this_Player->Transform.GetWorldPosition().Y + 20.0f };
	float4 Down_Player_Pos = { Player::this_Player->Transform.GetWorldPosition().X ,Player::this_Player->Transform.GetWorldPosition().Y - 20.0f };

	float4 Ad = { 640,-360 };


	if (GameEngineColor::MAGENTA == GetColor({ Left_Player_Pos - _Transform+ Ad }, { 255,0,0,255 }, _Name))
	{
		Player::this_Player->LeftMove = false;
	}
	
	else if (GameEngineColor::BLUE == GetColor({ Left_Player_Pos - _Transform + Ad }, { 255,0,0,255 }, _Name))
	{
		Player::this_Player->LeftMove = false;
	}

	else
	{
		Player::this_Player->LeftMove = true;
	}









	if (GameEngineColor::MAGENTA == GetColor({ Right_Player_Pos - _Transform+ Ad }, { 255,0,0,255 }, _Name))
	{
		Player::this_Player->RightMove = false;
	}
	
	else if (GameEngineColor::BLUE == GetColor({ Right_Player_Pos - _Transform + Ad }, { 255,0,0,255 }, _Name))
	{
		Player::this_Player->RightMove = false;
	}
	else
	{
		Player::this_Player->RightMove = true;
	}





	if (GameEngineColor::MAGENTA == GetColor({ Up_Player_Pos - _Transform + Ad }, { 255, 0, 0, 255 }, _Name))
	{
		Player::this_Player->UpMove = false;
	}
	
	else if (GameEngineColor::BLUE == GetColor({ Up_Player_Pos - _Transform + Ad }, { 255, 0, 0, 255 }, _Name))
	{
		Player::this_Player->UpMove = false;
	}
	else
	{
		Player::this_Player->UpMove = true;
	}



	if (GameEngineColor::MAGENTA == GetColor({ Down_Player_Pos - _Transform + Ad }, { 255, 0, 0, 255 }, _Name))
	{
		Player::this_Player->DownMove = false;
	}

	else if (GameEngineColor::BLUE == GetColor({ Down_Player_Pos - _Transform + Ad }, { 255, 0, 0, 255 }, _Name))
	{
		Player::this_Player->DownMove = false;
	}

	else
	{
		Player::this_Player->DownMove = true;
	}



	/*if (GameEngineColor::GREEN == GetColor({ Right_Player_Pos - _Transform + AD }, { 255,0,0,255 }, _Name))
	{
		Player::this_Player->RightMove = false;
	}
	else
	{
		Player::this_Player->RightMove = true;
	}*/




	if (GameEngineColor::GREEN == GetColor({ Left_Player_Pos - _Transform + Ad }, { 0,0,255,255 }, _Name))
	{
		Player::this_Player->Speed = 0.0f;
		Player::this_Player->Transform.AddLocalPosition(float4::RIGHT * 20.0f * _Delta);
	}
	else if (GameEngineColor::GREEN == GetColor({ Right_Player_Pos - _Transform + Ad }, { 0,0,255,255 }, _Name))
	{
		Player::this_Player->Speed = 0.0f;
		Player::this_Player->Transform.AddLocalPosition(float4::LEFT * 20.0f * _Delta);
	}
	else if (GameEngineColor::GREEN == GetColor({ Up_Player_Pos - _Transform + Ad }, { 0, 0, 255, 255 }, _Name))
	{
		Player::this_Player->Speed = 0.0f;
		Player::this_Player->Transform.AddLocalPosition(float4::DOWN * 20.0f * _Delta);
	}
	else if (GameEngineColor::GREEN == GetColor({ Down_Player_Pos - _Transform + Ad }, { 0, 0, 255, 255 }, _Name))
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

void Map_Manager::DoorCollision(float _Delta,float4 _PrevMainCamera)
{



	if (Player::this_Player->Col->Collision(ContentsCollisionType::RightDoor))
	{
		Map_Check += 1;
		Door_Right_Collison_Check = true;
		A = _PrevMainCamera.X;
		Player::this_Player->Transform.AddLocalPosition(300.0f);
	}


	else if (Player::this_Player->Col->Collision(ContentsCollisionType::LeftDoor))
	{
		Map_Check += 1;
		Door_Left_Collison_Check = true;
		A = _PrevMainCamera.X;
		Player::this_Player->Transform.AddLocalPosition(-300.0f);
	}

	else if (Player::this_Player->Col->Collision(ContentsCollisionType::TopDoor))
	{
		Map_Check += 1;
		Door_Top_Collison_Check = true;
		A = _PrevMainCamera.Y;
		Player::this_Player->Transform.AddLocalPosition({0.0f, 300.0f });
	}

	else if (Player::this_Player->Col->Collision(ContentsCollisionType::BottomDoor))
	{
		Map_Check += 1;
		Door_Bottom_Collison_Check = true;
		A = _PrevMainCamera.Y;
		Player::this_Player->Transform.AddLocalPosition({ 0.0f, -300.0f });
	}


	


	float4 X_Camera_Move = float4::LerpClamp(0, 1280, _Delta);

	 float4 Y_Camera_Move = float4::LerpClamp(0, 650, _Delta);

	 
	if (Player::this_Player->GetLevel()->GetMainCamera()->Transform.GetLocalPosition().X < A +1280  && Door_Right_Collison_Check == true)
	{
		Player::this_Player->GetLevel()->GetMainCamera()->Transform.AddLocalPosition(X_Camera_Move);
	}
	else if(Player::this_Player->GetLevel()->GetMainCamera()->Transform.GetLocalPosition().X >= A + 1280 && Door_Right_Collison_Check == true)
	{
		Door_Right_Collison_Check = false;
		ReturnCheck = true; 
	}



	if (Player::this_Player->GetLevel()->GetMainCamera()->Transform.GetLocalPosition().X > A - 1280 && Door_Left_Collison_Check == true)
	{
		Player::this_Player->GetLevel()->GetMainCamera()->Transform.AddLocalPosition(-X_Camera_Move);
	}
	else if(Player::this_Player->GetLevel()->GetMainCamera()->Transform.GetLocalPosition().X <= A - 1280 && Door_Left_Collison_Check == true)
	{
		Door_Left_Collison_Check = false;
		ReturnCheck = true;
	}

	if (Player::this_Player->GetLevel()->GetMainCamera()->Transform.GetLocalPosition().Y < A + 720 && Door_Top_Collison_Check == true)
	{
		Player::this_Player->GetLevel()->GetMainCamera()->Transform.AddLocalPosition({0.0f,Y_Camera_Move.X });
	}
	else if(Player::this_Player->GetLevel()->GetMainCamera()->Transform.GetLocalPosition().Y >= A + 720 && Door_Top_Collison_Check == true)
	{
		Door_Top_Collison_Check = false;
		ReturnCheck = true;
	}



	if (Player::this_Player->GetLevel()->GetMainCamera()->Transform.GetLocalPosition().Y > A - 720 && Door_Bottom_Collison_Check == true)
	{
		Player::this_Player->GetLevel()->GetMainCamera()->Transform.AddLocalPosition({ 0.0f,-Y_Camera_Move.X });
	}
	else if(Player::this_Player->GetLevel()->GetMainCamera()->Transform.GetLocalPosition().Y <= A - 720 && Door_Bottom_Collison_Check == true)
	{
		Door_Bottom_Collison_Check = false;
		ReturnCheck = true;
	}




}
