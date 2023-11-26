#include "PreCompile.h"
#include "Shop_House.h"
#include "Player.h"
#include "Black_Out.h"
#include "NPC.h"
#include "Shop_UI.h"
#include "Shop_Item.h"
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

void Shop_House::Start()
{
	GameEngineInput::AddInputObject(this);

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
		Shop_02 = CreateComponent<GameEngineSpriteRenderer>(-47);
		Shop_02->SetSprite("Shop", 0);
		Shop_02->AutoSpriteSizeOn();
		Shop_02->SetAutoScaleRatio(2.0f);
		Shop_02->Off(); 
		///Shop->Transform.AddLocalPosition({ 0.0f,0.0f,-150 });
	}
	

	/*{
		Shop_02 = CreateComponent<GameEngineSpriteRenderer>(-52);
		Shop_02->SetSprite("Shop", 0);
		Shop_02->AutoSpriteSizeOn();
		Shop_02->SetAutoScaleRatio(2.0f);
		Shop_02->Off();
		///Shop->Transform.AddLocalPosition({ 0.0f,0.0f,-150 });
	}
	*/
	
	{
	Pixel = CreateComponent<GameEngineSpriteRenderer>(-49);
	Pixel->SetSprite("Shop_Pixel", 0);
	Pixel->Off();

	
	///Shop->Transform.AddLocalPosition({ 0.01f,0.0f,-150 });
	}
	{
		Shop_Table = CreateComponent<GameEngineSpriteRenderer>(-49);
		Shop_Table->SetSprite("Shop_Table", 0);
		Shop_Table->AutoSpriteSizeOn();
		Shop_Table->SetAutoScaleRatio(1.0f);
		Shop_Table->Transform.SetLocalPosition({ -130.0f,-167.0f});


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Shop_Table->GetCurSprite().Texture->GetScale() * 1.0f });
		Col->Transform.SetWorldPosition(Shop_Table->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);

		

		///Shop->Transform.AddLocalPosition({ 0.01f,0.0f,-150 });
	}
	

	{
		Shop_Counter = CreateComponent<GameEngineSpriteRenderer>(-49);
		Shop_Counter->SetSprite("Shop_Counter", 0);
		Shop_Counter->AutoSpriteSizeOn();
		Shop_Counter->SetAutoScaleRatio(1.0f);
		Shop_Counter->Transform.SetLocalPosition({ 100.0f,-143.0f });
		///Shop->Transform.AddLocalPosition({ 0.01f,0.0f,-150 });


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Shop_Counter->GetCurSprite().Texture->GetScale() * 1.0f });
		Col->Transform.SetWorldPosition(Shop_Counter->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);

	}

	{
		Shop_Carpet = CreateComponent<GameEngineSpriteRenderer>(-49);
		Shop_Carpet->SetSprite("Shop_Carpet", 0);
		Shop_Carpet->AutoSpriteSizeOn();
		Shop_Carpet->SetAutoScaleRatio(1.0f);
		Shop_Carpet->Transform.SetLocalPosition({ 50.0f,-283.0f });


		///Shop->Transform.AddLocalPosition({ 0.01f,0.0f,-150 });
	}

	{
		Shop_Stove = CreateComponent<GameEngineSpriteRenderer>(-49);
		Shop_Stove->SetSprite("Shop_Stove", 0);
		Shop_Stove->AutoSpriteSizeOn();
		Shop_Stove->SetAutoScaleRatio(2.0f);
		Shop_Stove->Transform.SetLocalPosition({ -109.0f,-11.0f });


	/*	std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Shop_Stove->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Shop_Stove->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);*/
		///Shop->Transform.AddLocalPosition({ 0.01f,0.0f,-150 });
	}

	{
		shop_Box = CreateComponent<GameEngineSpriteRenderer>(-49);
		shop_Box->SetSprite("Shop_Box", 0);
		shop_Box->AutoSpriteSizeOn();
		shop_Box->SetAutoScaleRatio(1.0f);
		shop_Box->Transform.SetLocalPosition({ -14.0f,301.0f });

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ shop_Box->GetCurSprite().Texture->GetScale() * 1.0f });
		Col->Transform.SetWorldPosition(shop_Box->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);


		///Shop->Transform.AddLocalPosition({ 0.01f,0.0f,-150 });
	}

	{
		shop_Desk = CreateComponent<GameEngineSpriteRenderer>(-49);
		shop_Desk->SetSprite("Shop_Desk", 0);
		shop_Desk->AutoSpriteSizeOn();
		shop_Desk->SetAutoScaleRatio(1.0f);
		shop_Desk->Transform.SetLocalPosition({ -62.0f,211.0f });

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ shop_Desk->GetCurSprite().Texture->GetScale() * 1.0f });
		Col->Transform.SetWorldPosition(shop_Desk->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);


		///Shop->Transform.AddLocalPosition({ 0.01f,0.0f,-150 });
	}
	{
		shop_Bed = CreateComponent<GameEngineSpriteRenderer>(-49);
		shop_Bed->SetSprite("Shop_Bed", 0);
		shop_Bed->AutoSpriteSizeOn();
		shop_Bed->SetAutoScaleRatio(3.0f);
		shop_Bed->Transform.SetLocalPosition({ 149.0f,216.0f });

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ shop_Bed->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(shop_Bed->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);


		///Shop->Transform.AddLocalPosition({ 0.01f,0.0f,-150 });
	}

	{
		bed_carpet = CreateComponent<GameEngineSpriteRenderer>(-49);
		bed_carpet->SetSprite("bed_carpet", 0);
		bed_carpet->AutoSpriteSizeOn();
		bed_carpet->SetAutoScaleRatio(2.0f);
		bed_carpet->Transform.SetLocalPosition({ 143,208.0f });
		///Shop->Transform.AddLocalPosition({ 0.01f,0.0f,1-150 });
	}
	{
		Room_Stove = CreateComponent<GameEngineSpriteRenderer>(-49);
		Room_Stove->SetSprite("Room_Stove", 0);
		Room_Stove->AutoSpriteSizeOn();
		Room_Stove->SetAutoScaleRatio(2.0f);
		Room_Stove->Transform.SetLocalPosition({ 200,127.0f });

		/*std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Room_Stove->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Room_Stove->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);*/


		///Shop->Transform.AddLocalPosition({ 0.01f,0.0f,1-150 });
	}

	{
		Shop_door = CreateComponent<GameEngineSpriteRenderer>(-49);
		Shop_door->CreateAnimation("Shop_door", "Shop_door", 0.1f, -1, -1, false);
		Shop_door->CreateAnimation("Shop_door_Closed", "Shop_door_Closed", 0.1f, -1, -1, false);
		Shop_door->AutoSpriteSizeOn();
		Shop_door->SetAutoScaleRatio(2.0f);
		Shop_door->Transform.SetLocalPosition({ 62,-331.0f });
		Shop_door->ChangeAnimation("Shop_door");
		Shop_door->AnimationPauseOn(); 
		Shop_door->DownFlip();
	}

	/*{
		Shop_door_Closed = CreateComponent<GameEngineSpriteRenderer>(-49);
		Shop_door_Closed->CreateAnimation("Shop_door_Closed", "Shop_door_Closed", 1.0f, -1, -1, false);
		Shop_door_Closed->AutoSpriteSizeOn();
		Shop_door_Closed->SetAutoScaleRatio(2.0f);
		Shop_door_Closed->Transform.SetLocalPosition({ 92,-311.0f });
		Shop_door_Closed->ChangeAnimation("Shop_door_Closed");
		Shop_door_Closed->Off(); 
	}*/

	{
		Room_Stove_Fire = CreateComponent<GameEngineSpriteRenderer>(-49);
		Room_Stove_Fire->CreateAnimation("Room_Stove_Fire", "Room_Stove_Fire", 0.1f, -1, -1, true);
		Room_Stove_Fire->AutoSpriteSizeOn();
		Room_Stove_Fire->SetAutoScaleRatio(2.0f);
		Room_Stove_Fire->ChangeAnimation("Room_Stove_Fire");
		Room_Stove_Fire->Transform.SetLocalPosition({ 197,132.0f });


		///Shop->Transform.AddLocalPosition({ 0.01f,0.0f,-150 });
	}

	{
		shop_stove_Fire = CreateComponent<GameEngineSpriteRenderer>(-49);
		shop_stove_Fire->CreateAnimation("shop_stove_Fire", "shop_stove_Fire", 0.1f, -1, -1, true);
		shop_stove_Fire->AutoSpriteSizeOn();
		shop_stove_Fire->SetAutoScaleRatio(2.0f);
		shop_stove_Fire->ChangeAnimation("shop_stove_Fire");
		shop_stove_Fire->Transform.SetLocalPosition({ -109.0f,-13.0f });


		///Shop->Transform.AddLocalPosition({ 0.01f,0.0f,-150 });
	}
	{
		shop_cauldron = CreateComponent<GameEngineSpriteRenderer>(-49);
		shop_cauldron->CreateAnimation("shop_cauldron", "shop_cauldron", 0.1f, -1, -1, true);
		shop_cauldron->AutoSpriteSizeOn();
		shop_cauldron->SetAutoScaleRatio(2.0f);
		shop_cauldron->ChangeAnimation("shop_cauldron");
		shop_cauldron->Transform.SetLocalPosition({ -134.0f,-65.0f });

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ shop_cauldron->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(shop_cauldron->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);

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
 
	Change_Town = CreateComponent<GameEngineCollision>(ContentsCollisionType::Town);
	Change_Town->Transform.SetLocalScale({ 50.0f,50.0f });
	Change_Town->Transform.SetLocalPosition({ 54.0f,-286.0f });
	Change_Town->SetCollisionType(ColType::AABBBOX2D);



	Open_Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Open_Col);
	Open_Col->Transform.SetLocalScale({ 50.0f,50.0f });
	Open_Col->Transform.SetLocalPosition({ 54.0f,-286.0f });
	Open_Col->SetCollisionType(ColType::AABBBOX2D);

	
	

	Down_Event.Enter = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
			if (Up_CameraMove == true)
			{
				CameraMove = false;
			}
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
			Up_CameraMove = false;
	};


	Up_Event.Enter = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
			if (CameraMove == true)
			{
				Up_CameraMove = false;
			}
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
			CameraMove = false;
	};

	


}

void Shop_House::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown('4',this) && test == true)
	{
		Pixel->Off();
		test = false;
	}

	else if (GameEngineInput::IsDown('4', this) && test == false)
	{
		Pixel->On();
		test = true;
	}

	
	Change_Town->CollisionEvent(ContentsCollisionType::Player, Event);

	PixelCollision(_DeltaTime);


	
	if (Col->Collision(ContentsCollisionType::ShopDoor))
	{
		if (GameEngineInput::IsDown(VK_RETURN, this) && Black_Check == false)
		{
			black_Out = GetLevel()->CreateActor<Black_Out>();
			Black_Check = true;
		}
	}

	if (Open_Col->Collision(ContentsCollisionType::Player))
	{
		if (GameEngineInput::IsDown('E', this) && Open_Col_Check ==false)
		{		
			Shop_door->AnimationPauseOff(); 
			Open_Col_Check = true; 
		}

		else if (GameEngineInput::IsDown('E', this) && Open_Col_Check == true)
		{
			Shop_door->AnimationPauseOff();
			Open_Col_Check = false;
		}
	}



	if (Open_Col_Check == true)
	{
		if (Shop_door->GetCurIndex() > 0)
		{
			if (Shop_door->GetCurIndex() < 4)
			{
				Shop_door->Transform.SetLocalPosition({ 92,-311.0f });
			}
		}	
	}
	
	if (Shop_door->IsCurAnimationEnd() && Open_Col_Check == false)
	{
		Shop_door->ChangeAnimation("Shop_door_Closed"); 
				
		Close_Col_Check = true;	
	}

	if (Close_Col_Check == true)
	{
		if (Shop_door->GetCurIndex() > 1)
		{


			if (Shop_door->GetCurIndex() == 2)
			{
				Shop_door->Transform.SetLocalPosition({ 72,-321.0f });
			}
			else if (Shop_door->GetCurIndex() < 4)
			{
				Shop_door->Transform.SetLocalPosition({ 62,-331.0f });
			}

		}
		if (Shop_door->IsCurAnimationEnd())
		{
			Shop_door->ChangeAnimation("Shop_door");
			Shop_door->On();
			Shop_door->AnimationPauseOn();
			Close_Col_Check = false;
		}

	}
	


	if (Black_Check == true)
	{
		if (black_Out->GetCheck() == true)
		{
			GameEngineCore::ChangeLevel("WorldLevel");
		}
	}

	if (Open_Col_Check == true)
	{
		Time += _DeltaTime; 

		int Npc_Number = random.RandomInt(0, 3);

		if (Time > 2)
		{
			if (Shop_UI::this_Shop_UI->Shop_Item_01->IsUpdate() == true && Shop_Item_01 == false)
			{
				std::shared_ptr<Npc> Object = GetLevel()->CreateActor<Npc>();
				Object->Set_Npc_name(static_cast<Npc_Name>(Npc_Number));
				Object->Transform.SetWorldPosition({ 687,-635 });
				Object->ChangeState(Npc_State::LeftMove);
				Object->Set_MoveValue(Npc_Move::Up_Left);
				Shop_Item_01 = true;
				Time = 0;
				
			}

			else if (Shop_UI::this_Shop_UI->Shop_Item_02->IsUpdate() == true && Shop_Item_02 == false)
			{
				std::shared_ptr<Npc> Object = GetLevel()->CreateActor<Npc>();
				Object->Set_Npc_name(static_cast<Npc_Name>(Npc_Number));
				Object->Transform.SetWorldPosition({ 687,-635 });
				Object->ChangeState(Npc_State::LeftMove);
				Object->Set_MoveValue(Npc_Move::Up_Right);
				Shop_Item_02 = true;
				Time = 0;
			
			}

			else if (Shop_UI::this_Shop_UI->Shop_Item_03->IsUpdate() == true && Shop_Item_03 == false)
			{
				std::shared_ptr<Npc> Object = GetLevel()->CreateActor<Npc>();
				Object->Set_Npc_name(static_cast<Npc_Name>(Npc_Number));
				Object->Transform.SetWorldPosition({ 687,-635 });
				Object->ChangeState(Npc_State::LeftMove);
				Object->Set_MoveValue(Npc_Move::Down_Left);
				Shop_Item_03 = true;
				Time = 0;
			
			}

			else if (Shop_UI::this_Shop_UI->Shop_Item_04->IsUpdate() == true && Shop_Item_04 == false)
			{
				std::shared_ptr<Npc> Object = GetLevel()->CreateActor<Npc>();
				Object->Set_Npc_name(static_cast<Npc_Name>(Npc_Number));
				Object->Transform.SetWorldPosition({ 687,-635 });
				Object->ChangeState(Npc_State::LeftMove);
				Object->Set_MoveValue(Npc_Move::Down_Right);
				Shop_Item_04 = true;
				Time = 0;
			
			}
		}

		if (Shop_UI::this_Shop_UI->Shop_Item_01->IsUpdate() == false)
		{
			Shop_Item_01 = false;
		}
		if (Shop_UI::this_Shop_UI->Shop_Item_02->IsUpdate() == false)
		{
			Shop_Item_02 = false;
		}
		if (Shop_UI::this_Shop_UI->Shop_Item_03->IsUpdate() == false)
		{
			Shop_Item_03 = false;
		}
		if (Shop_UI::this_Shop_UI->Shop_Item_04->IsUpdate() == false)
		{
			Shop_Item_04 = false;
		}


	}



	float4 Camera_Move = float4::LerpClamp(0, 600, _DeltaTime);

	

	Down_Col->CollisionEvent(ContentsCollisionType::Player, Down_Event);
	Up_Col->CollisionEvent(ContentsCollisionType::Player, Up_Event);


	
	/*if (Camera_Check == true)
	{
		CameraMove = true;
	}*/

	

	if (CameraMove == true && GetLevel()->GetMainCamera()->Transform.GetWorldPosition().Y < -118 )
	{
	     GetLevel()->GetMainCamera()->Transform.AddLocalPosition({ 0.0f,Camera_Move.X });
	}
	/*else
	{
		CameraMove = false;
	}*/


	if (Up_CameraMove == true && GetLevel()->GetMainCamera()->Transform.GetWorldPosition().Y > -500 )
	{
		GetLevel()->GetMainCamera()->Transform.AddLocalPosition({ 0.0f,-Camera_Move.X });
	}
	/*else
	{
		Up_CameraMove = false;
	}*/
	/*if (GetLevel()->GetMainCamera()->Transform.GetWorldPosition().Y < -500)
	{
		Up_CameraMove = false;
	}*/



	


	//if (GameEngineInput::IsDown('1') && check == false)
	//{
	//	check = true;
	//}
	//else if (GameEngineInput::IsDown('1') && check == true)
	//{
	//	check = false;
	//}


	//if (check == true)
	//{
	//	if (GameEngineInput::IsPress('A'))
	//	{
	//		GetLevel()->GetMainCamera()->Transform.AddWorldPosition({ 5.0f,0.0f });
	//	}

	//	if (GameEngineInput::IsPress('D'))
	//	{
	//		GetLevel()->GetMainCamera()->Transform.AddWorldPosition({ -5.0f,0.0f });
	//		return;
	//	}

	//	if (GameEngineInput::IsPress('W'))
	//	{
	//		GetLevel()->GetMainCamera()->Transform.AddWorldPosition(float4::UP *5);
	//		return;
	//	}

	//	if (GameEngineInput::IsPress('S'))
	//	{
	//		GetLevel()->GetMainCamera()->Transform.AddWorldPosition(float4::DOWN* 5);
	//		return;
	//	}
	//}
	//if (check == false)
	//{


	//	if (GameEngineInput::IsPress('A'))
	//	{
	//		AD->Transform.AddWorldPosition({ 1.0f,0.0f });
	//	}

	//	if (GameEngineInput::IsPress('D'))
	//	{
	//		AD->Transform.AddWorldPosition({ -1.0f,0.0f });
	//		return;
	//	}

	//	if (GameEngineInput::IsPress('W'))
	//	{
	//		AD->Transform.AddWorldPosition(float4::UP);
	//		return;
	//	}

	//	if (GameEngineInput::IsPress('S'))
	//	{
	//		AD->Transform.AddWorldPosition(float4::DOWN);
	//		return;
	//	}
	//}

	//if (GameEngineInput::IsPress('Q'))
	//{
	//	AD->Transform.AddWorldRotation({0.0f,1.0f* _DeltaTime,0.0f});
	//	return;
	//}
	//if (GameEngineInput::IsPress('E'))
	//{
	//	AD->Transform.AddWorldRotation({ 0.0f,-1.0f* _DeltaTime,0.0f });
	//	return;
	//}
	////-4946.0f, -5275.0f


	//TransformData date = AD->Transform.GetConstTransformDataRef();

	////date.LocalPosition;

	////float4 WorldMousePos;

	//float4 WorldMousePos = { date.LocalPosition.X,date.LocalPosition.Y };
	//OutputDebugStringA(WorldMousePos.ToString("\n").c_str());
	//
	//
	
}
