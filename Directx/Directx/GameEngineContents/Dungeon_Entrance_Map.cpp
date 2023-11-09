#include "PreCompile.h"
#include "Dungeon_Entrance_Map.h"
#include "Player.h"
#include "Black_Out.h"
Dungeon_Entrance_Map::Dungeon_Entrance_Map()
{
}

Dungeon_Entrance_Map::~Dungeon_Entrance_Map()
{
}

GameEngineColor Dungeon_Entrance_Map::GetColor(float4 _Pos, GameEngineColor _DefaultColor)
{
	_Pos.Y *= -1.0f;

	std::shared_ptr<GameEngineTexture> Tex = GameEngineTexture::Find("Dungeon_Entrance_Pixel.png");
	return Tex->GetColor(_Pos, _DefaultColor);

}

void Dungeon_Entrance_Map::PixelCollision(float _Delta)
{
	float4 Left_Player_Pos = { Player::this_Player->Transform.GetWorldPosition().X - 20.0f,Player::this_Player->Transform.GetWorldPosition().Y };
	float4 Right_Player_Pos = { Player::this_Player->Transform.GetWorldPosition().X + 20.0f,Player::this_Player->Transform.GetWorldPosition().Y };
	float4 Up_Player_Pos = { Player::this_Player->Transform.GetWorldPosition().X,Player::this_Player->Transform.GetWorldPosition().Y + 20.0f };
	float4 Down_Player_Pos = { Player::this_Player->Transform.GetWorldPosition().X ,Player::this_Player->Transform.GetWorldPosition().Y - 20.0f };

	if (GameEngineColor::MAGENTA == GetColor({ Left_Player_Pos }, { 255,0,0,255 }))
	{
		Player::this_Player->LeftMove = false;
	}

	else
	{
		Player::this_Player->LeftMove = true;
	}



	if (GameEngineColor::MAGENTA == GetColor({ Right_Player_Pos }, { 255,0,0,255 }))
	{
		Player::this_Player->RightMove = false;
	}
	else
	{
		Player::this_Player->RightMove = true;
	}


	if (GameEngineColor::MAGENTA == GetColor({ Up_Player_Pos }, { 255, 0, 0, 255 }))
	{
		Player::this_Player->UpMove = false;
	}
	else
	{
		Player::this_Player->UpMove = true;
	}



	if (GameEngineColor::MAGENTA == GetColor({ Down_Player_Pos }, { 255, 0, 0, 255 }))
	{
		Player::this_Player->DownMove = false;
	}
	else
	{
		Player::this_Player->DownMove = true;
	}

	/*else
	{
		Player::this_Player->RightMove = true;
		Player::this_Player->UpMove = true;
		Player::this_Player->LeftMove = true;
		Player::this_Player->DownMove = true;
	}*/











}
void Dungeon_Entrance_Map::Start()
{

	GameEngineInput::AddInputObject(this);

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ 1204, -1028 });

	{
		BackGround = CreateComponent<GameEngineSpriteRenderer>(-100);
		BackGround->SetSprite("DungeonsEntrance_Base", 0);
		BackGround->AutoSpriteSizeOn();
		BackGround->SetAutoScaleRatio(2.0f);
		//BackGround->Transform.AddLocalPosition({ 0.0f,0.0f,100.0f });
	}


	{
		DungeonsEntrance_Top = CreateComponent<GameEngineSpriteRenderer>(-40);
		DungeonsEntrance_Top->SetSprite("DungeonsEntrance_Top", 0);
		DungeonsEntrance_Top->AutoSpriteSizeOn();
		DungeonsEntrance_Top->SetAutoScaleRatio(2.0f);
		DungeonsEntrance_Top->Transform.SetWorldPosition({ 1216.0f,-1102.0f });
		//DungeonsEntrance_Top->Transform.SetWorldPosition({ 624.0f,-1262.0f });
	}
	{
		Dungeon_Door = CreateComponent<GameEngineSpriteRenderer>(-40);
		Dungeon_Door->SetSprite("Dungeon1_Door", 0);
		Dungeon_Door->AutoSpriteSizeOn();
		Dungeon_Door->SetAutoScaleRatio(2.0f);
		Dungeon_Door->Transform.SetWorldPosition({ 699.0f,-892.0f });	
	}
	{
		Dungeon_Door_02 = CreateComponent<GameEngineSpriteRenderer>(-40);
		Dungeon_Door_02->SetSprite("Dungeon_Door", 0);
		Dungeon_Door_02->AutoSpriteSizeOn();
		Dungeon_Door_02->SetAutoScaleRatio(2.0f);
		Dungeon_Door_02->Transform.SetWorldPosition({ 1711,-907.0f });
	}

	{
		Dungeon_Door_03 = CreateComponent<GameEngineSpriteRenderer>(-40);
		Dungeon_Door_03->SetSprite("Dungeon_Door", 0);
		Dungeon_Door_03->AutoSpriteSizeOn();
		Dungeon_Door_03->SetAutoScaleRatio(2.0f);
		Dungeon_Door_03->Transform.SetWorldPosition({ 1481.0f,-624.0f });
	}

	{
		Dungeon_Door_04 = CreateComponent<GameEngineSpriteRenderer>(-40);
		Dungeon_Door_04->SetSprite("Dungeon_Door", 0);
		Dungeon_Door_04->AutoSpriteSizeOn();
		Dungeon_Door_04->SetAutoScaleRatio(2.0f);
		Dungeon_Door_04->Transform.SetWorldPosition({ 942.0f,-624.0f });
	}

	{
		Dungeon_Open = CreateComponent<GameEngineSpriteRenderer>(-60);
		Dungeon_Open->CreateAnimation("Dungeon_Open", "Dungeon_Open", 0.1f, -1, -1, false);
		Dungeon_Open->CreateAnimation("Dungeon_Close", "Dungeon_Close", 0.1f, -1, -1, false);
		Dungeon_Open->Off(); 


		Dungeon_Open->AutoSpriteSizeOn();
		Dungeon_Open->SetAutoScaleRatio(2.0f);
		Dungeon_Open->Transform.SetWorldPosition({ 699.0f,-892.0f });
		Dungeon_Open->ChangeAnimation("Dungeon_Open");

	}
	



	/*{
		

		Dungeon_Entrance_Pixel = CreateComponent<GameEngineSpriteRenderer>(-100);
		Dungeon_Entrance_Pixel->SetSprite("Dungeon_Entrance_Pixel", 0);
		Dungeon_Entrance_Pixel->AutoSpriteSizeOn();
		Dungeon_Entrance_Pixel->SetAutoScaleRatio(1.0f);
	}*/

	Change_Town = CreateComponent<GameEngineCollision>(ContentsCollisionType::Dungeon_Entrance);
	Change_Town->Transform.SetLocalScale({ 100.0f,10.0f });
	Change_Town->Transform.SetWorldPosition({ 1211,-1954 });
	Change_Town->SetCollisionType(ColType::AABBBOX2D);


	Dungeon_Near = CreateComponent<GameEngineCollision>(ContentsCollisionType::Dungeon_Near);
	Dungeon_Near->Transform.SetLocalScale({ 250.0f,220.0f });
	Dungeon_Near->Transform.SetWorldPosition({ 733.0f,-1037.0f });
	Dungeon_Near->SetCollisionType(ColType::AABBBOX2D);


	Dungeon_Door_Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Dungeon_Door);
	Dungeon_Door_Col->Transform.SetLocalScale({ 200.0f,200.0f });
	Dungeon_Door_Col->Transform.SetWorldPosition({ 699.0f,-892.0f });
	Dungeon_Door_Col->SetCollisionType(ColType::AABBBOX2D);


	black_Out = GetLevel()->CreateActor<Black_Out>();
	black_Out->Off();

	black_Out_02 = GetLevel()->CreateActor<Black_Out>();
	black_Out_02->Off();

}





void Dungeon_Entrance_Map::Update(float _DeltaTime)
{
	if (Dungeon_Near->Collision(ContentsCollisionType::Player))
	{

		CollisionCheck = true; 
		Dungeon_Open->On(); 
		Dungeon_Door->Off(); 
	}

	if (Dungeon_Near->Collision(ContentsCollisionType::Player) ==false && CollisionCheck ==true)
	{
		Dungeon_Open->ChangeAnimation("Dungeon_Close"); 
	
		if (Dungeon_Open->IsCurAnimationEnd())
		{
			Dungeon_Door->On(); 
			Dungeon_Open->ChangeAnimation("Dungeon_Open");
			Dungeon_Open->Off();
			CollisionCheck = false;
		}

	}

	
	PixelCollision(_DeltaTime);
	

	

	if (Change_Town->Collision(ContentsCollisionType::Player))
	{
		int a = 0;

		
		Black_Check_02 = true;
		black_Out_02->On();
		black_Out_02->On();
		Player::this_Player->Not_Move = false;
	}


	if (Black_Check_02 == true)
	{
		if (black_Out_02->GetCheck() == true)
		{
			Player::LevelType = Leveltype::Dungeon_Entrance;
			GameEngineCore::ChangeLevel("WorldLevel");
			return;
		}


	}



	if (Dungeon_Door_Col->Collision(ContentsCollisionType::Player))
	{
		if (GameEngineInput::IsDown(VK_RETURN, this))
		{
			Black_Check = true;
			black_Out->On();
			Player::this_Player->Not_Move = false;
		}
	}

	if (Black_Check == true)
	{
		if (black_Out->GetCheck() == true)
		{
			Player::LevelType = Leveltype::None;
			GameEngineCore::ChangeLevel("PlayLevel");
			return;
		}

	}
	
}
