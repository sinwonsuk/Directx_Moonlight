#include "PreCompile.h"
#include "Shop_House.h"
#include "Player.h"
Shop_House::Shop_House()
{
}

Shop_House::~Shop_House()
{
}

GameEngineColor Shop_House::GetColor(float4 _Pos, GameEngineColor _DefaultColor)
{
	_Pos.Y *= -1.0f;

	std::shared_ptr<GameEngineTexture> Tex = GameEngineTexture::Find("Shop_Pixel.png");
	return Tex->GetColor(_Pos, _DefaultColor);

}

void Shop_House::PixelCollision(float _Delta)
{
	float4 Left_Player_Pos = { Player::this_Player->Transform.GetWorldPosition().X - 20.0f,Player::this_Player->Transform.GetWorldPosition().Y };
	float4 Right_Player_Pos = { Player::this_Player->Transform.GetWorldPosition().X + 20.0f,Player::this_Player->Transform.GetWorldPosition().Y };
	float4 Up_Player_Pos = { Player::this_Player->Transform.GetWorldPosition().X,Player::this_Player->Transform.GetWorldPosition().Y + 20.0f };
	float4 Down_Player_Pos = { Player::this_Player->Transform.GetWorldPosition().X ,Player::this_Player->Transform.GetWorldPosition().Y - 20.0f };

	if (GameEngineColor::AC == GetColor({ Left_Player_Pos }, { 255,0,0,255 }))
	{
		Player::this_Player->Roll_Speed = 0.0f;
		Player::this_Player->Speed = 0.0f;
		Player::this_Player->Transform.AddLocalPosition(float4::RIGHT * 20.0f * _Delta);
	}
	else if (GameEngineColor::AC == GetColor({ Right_Player_Pos }, { 255,0,0,255 }))
	{
		Player::this_Player->Roll_Speed = 0.0f;
		Player::this_Player->Speed = 0.0f;
		Player::this_Player->Transform.AddLocalPosition(float4::LEFT * 20.0f * _Delta);
	}
	else if (GameEngineColor::AC == GetColor({ Up_Player_Pos }, { 255, 0, 0, 255 }))
	{
		Player::this_Player->Roll_Speed = 0.0f;
		Player::this_Player->Speed = 0.0f;
		Player::this_Player->Transform.AddLocalPosition(float4::DOWN * 20.0f * _Delta);

	}
	else if (GameEngineColor::AC == GetColor({ Down_Player_Pos }, { 255, 0, 0, 255 }))
	{
		Player::this_Player->Roll_Speed = 0.0f;
		Player::this_Player->Speed = 0.0f;
		Player::this_Player->Transform.AddLocalPosition(float4::UP * 20.0f * _Delta);
	}


	else
	{
		Player::this_Player->Roll_Speed = 400.0f;
		Player::this_Player->Speed = 300.0f;
	}











}

void Shop_House::Start()
{
	

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y });

	
	{
		Black = CreateComponent<GameEngineSpriteRenderer>(-101);
		Black->SetSprite("Black", 0);
		Black->AutoSpriteSizeOn();
		Black->SetAutoScaleRatio(2.0f);
		Black->Transform.AddLocalPosition({ 0.0f,0.0f,-200 });
	}

	{
		Shop = CreateComponent<GameEngineSpriteRenderer>(-80);
		Shop->SetSprite("Shop", 0);
		Shop->AutoSpriteSizeOn();
		Shop->SetAutoScaleRatio(2.0f);
		///Shop->Transform.AddLocalPosition({ 0.0f,0.0f,-150 });
	}
	{
		Shop_02 = CreateComponent<GameEngineSpriteRenderer>(-52);
		Shop_02->SetSprite("Shop", 0);
		Shop_02->AutoSpriteSizeOn();
		Shop_02->SetAutoScaleRatio(2.0f);
		Shop_02->Off(); 
		///Shop->Transform.AddLocalPosition({ 0.0f,0.0f,-150 });
	}


	{
		Shop_02 = CreateComponent<GameEngineSpriteRenderer>(-52);
		Shop_02->SetSprite("Shop", 0);
		Shop_02->AutoSpriteSizeOn();
		Shop_02->SetAutoScaleRatio(2.0f);
		Shop_02->Off();
		///Shop->Transform.AddLocalPosition({ 0.0f,0.0f,-150 });
	}
	
	
	{
	sdsdsds = CreateComponent<GameEngineSpriteRenderer>(-52);
	sdsdsds->SetSprite("Shop_Pixel", 0);

	
	///Shop->Transform.AddLocalPosition({ 0.01f,0.0f,-150 });
	}
	{
		Shop_Table = CreateComponent<GameEngineSpriteRenderer>(-52);
		Shop_Table->SetSprite("Shop_Table", 0);
		Shop_Table->AutoSpriteSizeOn();
		Shop_Table->SetAutoScaleRatio(1.0f);
		Shop_Table->Transform.SetLocalPosition({ -130.0f,-167.0f});
		///Shop->Transform.AddLocalPosition({ 0.01f,0.0f,-150 });
	}
	

	{
		Shop_Counter = CreateComponent<GameEngineSpriteRenderer>(-52);
		Shop_Counter->SetSprite("Shop_Counter", 0);
		Shop_Counter->AutoSpriteSizeOn();
		Shop_Counter->SetAutoScaleRatio(1.0f);
		Shop_Counter->Transform.SetLocalPosition({ 100.0f,-143.0f });
		///Shop->Transform.AddLocalPosition({ 0.01f,0.0f,-150 });
	}

	{
		Shop_Carpet = CreateComponent<GameEngineSpriteRenderer>(-52);
		Shop_Carpet->SetSprite("Shop_Carpet", 0);
		Shop_Carpet->AutoSpriteSizeOn();
		Shop_Carpet->SetAutoScaleRatio(1.0f);
		Shop_Carpet->Transform.SetLocalPosition({ 50.0f,-283.0f });
		///Shop->Transform.AddLocalPosition({ 0.01f,0.0f,-150 });
	}

	{
		Shop_Stove = CreateComponent<GameEngineSpriteRenderer>(-52);
		Shop_Stove->SetSprite("Shop_Stove", 0);
		Shop_Stove->AutoSpriteSizeOn();
		Shop_Stove->SetAutoScaleRatio(2.0f);
		Shop_Stove->Transform.SetLocalPosition({ -109.0f,-11.0f });
		///Shop->Transform.AddLocalPosition({ 0.01f,0.0f,-150 });
	}

	{
		shop_stove_Fire = CreateComponent<GameEngineSpriteRenderer>(-52);
		shop_stove_Fire->CreateAnimation("shop_stove_Fire", "shop_stove_Fire", 0.1f, -1, -1, true);
		shop_stove_Fire->AutoSpriteSizeOn();
		shop_stove_Fire->SetAutoScaleRatio(2.0f);
		shop_stove_Fire->ChangeAnimation("shop_stove_Fire");
		shop_stove_Fire->Transform.SetLocalPosition({ -109.0f,-13.0f });


		///Shop->Transform.AddLocalPosition({ 0.01f,0.0f,-150 });
	}
	{
		shop_cauldron = CreateComponent<GameEngineSpriteRenderer>(-52);
		shop_cauldron->CreateAnimation("shop_cauldron", "shop_cauldron", 0.1f, -1, -1, true);
		shop_cauldron->AutoSpriteSizeOn();
		shop_cauldron->SetAutoScaleRatio(2.0f);
		shop_cauldron->ChangeAnimation("shop_cauldron");
		shop_cauldron->Transform.SetLocalPosition({ -134.0f,-65.0f });


		///Shop->Transform.AddLocalPosition({ 0.01f,0.0f,-150 });
	}

	
	/*{
		BackGround = CreateComponent<GameEngineSpriteRenderer>(-99);
		BackGround->SetSprite("Shop", 0);
		BackGround->AutoSpriteSizeOn();
		BackGround->SetAutoScaleRatio(2.0f);
	}*/


	Down_Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::ShopDoor);
	Down_Col->Transform.SetLocalScale({ 50.0f,10.0f });
	Down_Col->Transform.SetLocalPosition({55.0f,-25.0f});
	Down_Col->SetCollisionType(ColType::AABBBOX2D);

	Up_Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::ShopDoor);
	Up_Col->Transform.SetLocalScale({ 50.0f,10.0f });
	Up_Col->Transform.SetLocalPosition({ 55.0f,75.0f });
	Up_Col->SetCollisionType(ColType::AABBBOX2D);

	
	Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::ShopDoor);
	Col->Transform.SetLocalScale({ 50.0f,130.0f });
	Col->Transform.SetLocalPosition({ 55.0f,30.0f });
	Col->SetCollisionType(ColType::AABBBOX2D);
 

	Down_Event.Enter = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		if (Up_CameraMove == false)
		{
			CameraMove = true;
		}
		
	};

	Down_Event.Stay = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		
	};

	Down_Event.Exit = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		
	};


	Up_Event.Enter = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		if (CameraMove == false)
		{
			Up_CameraMove = true;
		}
	};

	Up_Event.Stay = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		
	};

	Up_Event.Exit = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		
	};



}

void Shop_House::Update(float _DeltaTime)
{


	PixelCollision(_DeltaTime);


	//std::shared_ptr<class GameEngineSpriteRenderer> AD = shop_cauldron;

	//TransformData Camera = GetLevel()->GetMainCamera()->Transform.GetConstTransformDataRef();

	//TransformData Shphs = Shop->Transform.GetConstTransformDataRef();

	//
	//if (Col->Collision(ContentsCollisionType::Player))
	//{
	//	Shop_02->On();
	//	Shop->Off(); 
	//}

	//if (Col->Collision(ContentsCollisionType::Player) == false)
	//{
	//	Shop_02->Off();
	//	Shop->On();
	//}



	//float4 Camera_Move = float4::LerpClamp(0, 300, _DeltaTime);

	////

	//Down_Col->CollisionEvent(ContentsCollisionType::Player, Down_Event);
	//Up_Col->CollisionEvent(ContentsCollisionType::Player, Up_Event);


	///*if (Down_Col->Collision(ContentsCollisionType::Player) && GetLevel()->GetMainCamera()->Transform.GetWorldPosition().Y > -5150)
	//{
	//	CameraMove = true; 
	//	Down_CameraMove = false;
	//}

	//if (Up_Col->Collision(ContentsCollisionType::Player) && GetLevel()->GetMainCamera()->Transform.GetWorldPosition().Y > -4793)
	//{
	//	Down_CameraMove = true;
	//	CameraMove = false;
	//}*/

	//

	//

	//if (CameraMove == true && GetLevel()->GetMainCamera()->Transform.GetWorldPosition().Y < -118 && Up_CameraMove ==false)
	//{
	//     GetLevel()->GetMainCamera()->Transform.AddLocalPosition({ 0.0f,Camera_Move.X });
	//}
	//if (GetLevel()->GetMainCamera()->Transform.GetWorldPosition().Y > -118)
	//{
	//	CameraMove = false;
	//}


	//if (Up_CameraMove == true && GetLevel()->GetMainCamera()->Transform.GetWorldPosition().Y > -500 )
	//{
	//	GetLevel()->GetMainCamera()->Transform.AddLocalPosition({ 0.0f,-Camera_Move.X });
	//}

	//if (GetLevel()->GetMainCamera()->Transform.GetWorldPosition().Y < -500)
	//{
	//	Up_CameraMove = false;
	//}



	


	/*if (GameEngineInput::IsDown('1') && check == false)
	{
		check = true;
	}
	else if (GameEngineInput::IsDown('1') && check == true)
	{
		check = false;
	}


	if (check == true)
	{
		if (GameEngineInput::IsPress('A'))
		{
			GetLevel()->GetMainCamera()->Transform.AddWorldPosition({ 5.0f,0.0f });
		}

		if (GameEngineInput::IsPress('D'))
		{
			GetLevel()->GetMainCamera()->Transform.AddWorldPosition({ -5.0f,0.0f });
			return;
		}

		if (GameEngineInput::IsPress('W'))
		{
			GetLevel()->GetMainCamera()->Transform.AddWorldPosition(float4::UP *5);
			return;
		}

		if (GameEngineInput::IsPress('S'))
		{
			GetLevel()->GetMainCamera()->Transform.AddWorldPosition(float4::DOWN* 5);
			return;
		}
	}
	if (check == false)
	{


		if (GameEngineInput::IsPress('A'))
		{
			AD->Transform.AddWorldPosition({ 1.0f,0.0f });
		}

		if (GameEngineInput::IsPress('D'))
		{
			AD->Transform.AddWorldPosition({ -1.0f,0.0f });
			return;
		}

		if (GameEngineInput::IsPress('W'))
		{
			AD->Transform.AddWorldPosition(float4::UP);
			return;
		}

		if (GameEngineInput::IsPress('S'))
		{
			AD->Transform.AddWorldPosition(float4::DOWN);
			return;
		}
	}

	if (GameEngineInput::IsPress('Q'))
	{
		AD->Transform.AddWorldRotation({0.0f,1.0f* _DeltaTime,0.0f});
		return;
	}
	if (GameEngineInput::IsPress('E'))
	{
		AD->Transform.AddWorldRotation({ 0.0f,-1.0f* _DeltaTime,0.0f });
		return;
	}*/
	//-4946.0f, -5275.0f


	//TransformData date = AD->Transform.GetConstTransformDataRef();

	////date.LocalPosition;

	////float4 WorldMousePos;

	//float4 WorldMousePos = { date.WorldPosition.X+5000,date.WorldPosition.Y+5000 };
	//OutputDebugStringA(WorldMousePos.ToString("\n").c_str());
	
	
	
}
