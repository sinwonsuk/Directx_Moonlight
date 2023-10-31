#include "PreCompile.h"
#include "Dungeon_Map_10.h"
#include "Player.h"

Dungeon_Map_10::Dungeon_Map_10()
{
}

Dungeon_Map_10::~Dungeon_Map_10()
{
}



void Dungeon_Map_10::Start()
{
	/*{
		std::shared_ptr<Object_jar> Object = GetLevel()->CreateActor<Object_jar>();
	}*/

	GameEngineInput::AddInputObject(this);



	/*{
		BackGround = CreateComponent<GameEngineSpriteRenderer>(100);
		BackGround->SetSprite("BackGround", 1);
		BackGround->SetImageScale({ 1380.0f,740.0f });
		BackGround->Transform.AddLocalPosition({ 0.0f,0.0f });
	}*/


	{

		Map_floor_01 = CreateComponent<GameEngineSpriteRenderer>(-100);
		Map_floor_01->SetSprite("Floor_01", 10);

	}


	{
		Pixel = CreateComponent<GameEngineSpriteRenderer>(-100);
		Pixel->SetSprite("Pixel_Floor", 2);
	}

	/*{

		LeftDoor = CreateComponent<GameEngineSpriteRenderer>(-100);
		LeftDoor->Transform.AddLocalRotation({ 0.0f,0.0f,90.0f });
		LeftDoor->Transform.AddLocalPosition({ -550.0f,20.0f,0.0f });
		LeftDoor->SetAutoScaleRatio(1.5f);
		LeftDoor->SetSprite("Door", 1);

	}
	{

		RightDoor = CreateComponent<GameEngineSpriteRenderer>(-100);
		RightDoor->Transform.AddLocalRotation({ 0.0f,0.0f,-90.0f });
		RightDoor->Transform.AddLocalPosition({ 550.0f,20.0f,0.0f });
		RightDoor->SetAutoScaleRatio(1.5f);
		RightDoor->SetSprite("Door", 0);
	}*/


	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y });



	Right_Collision_Door = CreateComponent<GameEngineCollision>(ContentsCollisionType::Door);
	Right_Collision_Door->Transform.AddLocalPosition({ 550.0f,20.0f,0.0f });
	Right_Collision_Door->Transform.SetLocalScale({ 90.0f,120.0f,0.0f });




}

void Dungeon_Map_10::Update(float _Delta)
{
	if (GameEngineInput::IsDown('2', this) && check == false)
	{
		Pixel->On();
		check = true;
	}
	else if (GameEngineInput::IsDown('2', this) && check == true)
	{
		Pixel->Off();
		check = false;
	}

}
