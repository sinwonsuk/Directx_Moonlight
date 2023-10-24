#include "PreCompile.h"
#include "Dungeon_Map_01.h"
#include "Player.h"
#include "Random_Room.h"
Dungeon_Map_01::Dungeon_Map_01()
{
}

Dungeon_Map_01::~Dungeon_Map_01()
{
}



void Dungeon_Map_01::Start()
{
	/*{
		std::shared_ptr<Object_jar> Object = GetLevel()->CreateActor<Object_jar>();
	}*/

	

	

    {
		BackGround = CreateComponent<GameEngineSpriteRenderer>(100);
		BackGround->SetSprite("BackGround", 1);
		BackGround->SetImageScale({ 1380.0f,740.0f });
		BackGround->Transform.AddLocalPosition({ 0.0f,0.0f });
	}

	{
		Map_floor = CreateComponent<GameEngineSpriteRenderer>(-100);
		Map_floor->SetSprite("Floor_01", 0);

	}

	/*{
		Pixel = CreateComponent<GameEngineSpriteRenderer>(100);
		Pixel->SetSprite("Pixel_Floor", 0);

	}*/

	{
		LeftDoor = CreateComponent<GameEngineSpriteRenderer>(100);
		LeftDoor->Transform.AddLocalRotation({ 0.0f,0.0f,90.0f });
		LeftDoor->Transform.AddLocalPosition({ -550.0f,20.0f,0.0f });
		LeftDoor->SetAutoScaleRatio(1.5f);
		LeftDoor->SetSprite("Door", 1);
		LeftDoor->Off(); 
	}

	{
		RightDoor = CreateComponent<GameEngineSpriteRenderer>(100);
		RightDoor->Transform.AddLocalRotation({ 0.0f,0.0f,-90.0f });
		RightDoor->Transform.AddLocalPosition({ 550.0f,20.0f,0.0f });
		RightDoor->SetAutoScaleRatio(1.5f);
		RightDoor->SetSprite("Door", 0);
		RightDoor->Off();
	}
	{
		UpDoor = CreateComponent<GameEngineSpriteRenderer>(100);
		UpDoor->Transform.AddLocalPosition({ 0.0f,300.0f,0.0f });
		UpDoor->SetAutoScaleRatio(1.5f);
		UpDoor->SetSprite("Door", 0);
		UpDoor->Off();
	}

	{
		DownDoor = CreateComponent<GameEngineSpriteRenderer>(100);
		DownDoor->Transform.AddLocalRotation({ 0.0f,0.0f,180.0f });
		DownDoor->Transform.AddLocalPosition({ 0.0f,-300.0f,0.0f });
		DownDoor->SetAutoScaleRatio(1.5f);
		DownDoor->SetSprite("Door", 0);
		DownDoor->Off();
	}




	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y });
	


	Right_Collision_Door = CreateComponent<GameEngineCollision>(ContentsCollisionType::RightDoor);
	Right_Collision_Door->Transform.AddLocalPosition({ 550.0f,20.0f,0.0f });
	Right_Collision_Door->Transform.SetLocalScale({ 50.0f,120.0f,0.0f });
	Right_Collision_Door->Off(); 


	Left_Collision_Door = CreateComponent<GameEngineCollision>(ContentsCollisionType::LeftDoor);
	Left_Collision_Door->Transform.AddLocalPosition({ -550.0f,20.0f,0.0f });
	Left_Collision_Door->Transform.SetLocalScale({ 50.0f,120.0f,0.0f });
	Left_Collision_Door->Off(); 

	Top_Collision_Door = CreateComponent<GameEngineCollision>(ContentsCollisionType::TopDoor);
	Top_Collision_Door->Transform.AddLocalPosition({ 0.0f,300.0f,0.0f });
	Top_Collision_Door->Transform.SetLocalScale({ 50.0f,120.0f,0.0f });
	Top_Collision_Door->Off(); 

	Bottom_Collision_Door = CreateComponent<GameEngineCollision>(ContentsCollisionType::BottomDoor);
	Bottom_Collision_Door->Transform.AddLocalPosition({ 0.0f,-300.0f,0.0f });
	Bottom_Collision_Door->Transform.SetLocalScale({ 50.0f,120.0f,0.0f });
	Bottom_Collision_Door->Off(); 



}

void Dungeon_Map_01::Update(float _Delta)
{
	

	if (Check == false)
	{

		if (Arr.X >= 1) // 배열 벗어나지 않기 위한 조건문 
		{
			if (Random_Room::Rooms[Arr.X - 1][Arr.Y].RoomCheck == true)
			{
				LeftDoor->On();
				Left_Collision_Door->On(); 
			}
		}
		if (Arr.X <= 7) // 배열 벗어나지 않기 위한 조건문 
		{
			if (Random_Room::Rooms[Arr.X + 1][Arr.Y].RoomCheck == true)
			{
				RightDoor->On();
				Right_Collision_Door->On();
			}
		}
		if (Arr.Y >= 1) // 배열 벗어나지 않기 위한 조건문 
		{
			if (Random_Room::Rooms[Arr.X][Arr.Y-1].RoomCheck == true)
			{
				UpDoor->On();
				Top_Collision_Door->On();
			}
		}
		if (Arr.Y <= 7) // 배열 벗어나지 않기 위한 조건문 
		{
			if (Random_Room::Rooms[Arr.X ][Arr.Y+1].RoomCheck == true)
			{
				DownDoor->On();
				Bottom_Collision_Door->On();
			}
		}

		Check = true;
		return;
	}


	if (ReturnCheck == true)
	{
		return;
	}

	if (ReturnCheck == false)
	{
		DoorCollision(_Delta, GetLevel()->GetMainCamera()->Transform.GetLocalPosition());
		ObjectCollision(_Delta, Pixel_Name.c_str(), Random_Room::Rooms[Arr.X][Arr.Y].Pos);
	}


	
		
	

	
	

}
