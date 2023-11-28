#include "PreCompile.h"
#include "TutorialMap.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineTileMap.h>
#include "TutorialLevel.h"
#include "Player.h"
#include "Object_jar.h"
#include "BabySlime.h"
#include "golem_Wizard.h"
#include "golem_Solder.h"
#include "golem_Stone.h"
TutorialMap::TutorialMap()
{
}

TutorialMap::~TutorialMap()
{
}



void TutorialMap::Start()
{
	GameEngineInput::AddInputObject(this);

	/*{
		std::shared_ptr<Object_jar> Object = GetLevel()->CreateActor<Object_jar>();
	}*/

	//Transform.SetLocalPosition({ 0.0f,0.0f,-5.0f });

	{

		Scroll = CreateComponent<GameEngineSpriteRenderer>(100);
		Scroll->CreateAnimation("Tutorial Scroll", "Tutorial Scroll", 0.1f, -1, -1, false);

		Scroll->AutoSpriteSizeOn();
		Scroll->SetAutoScaleRatio(2.0f);
		Scroll->ChangeAnimation("Tutorial Scroll");

		Scroll->AnimationPauseOn(); 
		Scroll->Transform.AddLocalPosition({ 0.0f,320.0f });
	}
	
	{

	    BackGround = CreateComponent<GameEngineSpriteRenderer>(-100);
	    BackGround->SetSprite("BackGround", 1);
	    BackGround->SetImageScale({ 1380.0f,740.0f });

	}

	{

		Map_floor_01 = CreateComponent<GameEngineSpriteRenderer>(-100);
		Map_floor_01->SetSprite("Tutorial_Floor_01", 0);
	//	Map_floor_01->SetImageScale({ 1050.0f,552.0f });

	}

	{

		Pixel = CreateComponent<GameEngineSpriteRenderer>(-100);
		Pixel->SetSprite("Pixel", 0);

		Pixel->Off(); 
	}
	{

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
	}


	

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y});
	
	/*{
		std::shared_ptr<golem_Wizard> Object = GetLevel()->CreateActor<golem_Wizard>();
		Object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X,Transform.GetWorldPosition().Y });
		Object->Set_MapName("Tutirial_Pixel_Map_01.png");
	}
	*/
	/*{
		std::shared_ptr<golem_Stone> Object = GetLevel()->CreateActor<golem_Stone>();
		Object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X,Transform.GetWorldPosition().Y });
		Object->Set_MapName("Tutirial_Pixel_Map_01.png");
	}*/
	

   /* {
		std::shared_ptr<golem_Solder> Object = GetLevel()->CreateActor<golem_Solder>();
		Object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X-200.0f,Transform.GetWorldPosition().Y });
		Object->Set_MapName("Tutirial_Pixel_Map_01.png");
	}*/

	/*{
		std::shared_ptr<golem_Solder> Object = GetLevel()->CreateActor<golem_Solder>();
		Object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X,Transform.GetWorldPosition().Y });
		Object->Set_MapName("Tutirial_Pixel_Map_01.png");
	}*/

	Collision_Door = CreateComponent<GameEngineCollision>(ContentsCollisionType::Door);
	Collision_Door->Transform.AddLocalPosition({ 550.0f,20.0f,0.0f });
	Collision_Door->Transform.SetLocalScale({90.0f,120.0f,0.0f });

	Map_Number = 0;
}

void TutorialMap::Update(float _Delta)
{
	if (Player::this_Player->MonsterDeath == true)
	{
		Bgm_Sound.Stop();
	}


	if (Player::this_Player->GetPlayerStateValue() != PlayerState::Start)
	{
		if (Sound_Check == false)
		{
			Scroll_Sound = GameEngineSound::SoundPlay("tutorial_scroll.wav");
			Bgm_Sound = GameEngineSound::SoundPlay("golem_dungeon_floor.wav");
			Bgm_Sound.SetVolume(0.5f);
			Sound_Check = true;
		}
		Scroll->AnimationPauseOff();
	}



	

	if (GetLevel()->GetMainCamera()->Transform.GetWorldPosition().X > 1280 * (1.5 + Map_Number))
	{
		return;
	}

	if (Map_Number == 0 && Map_Check == 0)
	{
		ObjectCollision(_Delta, "Tutirial_Pixel_Map_01.png");
		
	}

	DoorCollision(_Delta, Map_Number);
}
