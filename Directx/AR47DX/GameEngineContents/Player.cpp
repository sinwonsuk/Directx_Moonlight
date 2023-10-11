#include "PreCompile.h"
#include "Player.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "TownMap.h"
#include "Monster.h"
#include "ContentsEnum.h"

Player* Player::this_Player; 

Player::Player() 
{
	
}

Player::~Player() 
{
}

void Player::AnimationCheck(const std::string_view& _AnimationName)
{
	player->ChangeAnimation(_AnimationName);
}

void Player::Start()
{
	this_Player = this;
	

	{
		// 줄줄이 사탕 식으로 만들려고.
		player = CreateComponent<GameEngineSpriteRenderer>();
	
		

		player->CreateAnimation("Start", "PlayStart", 0.15f, -1, -1, false);

		player->CreateAnimation("UpIdle", "UpIdle", 0.1f, -1, -1, true);
		player->CreateAnimation("LeftIdle", "LeftIdle", 0.1f, -1, -1, true);
		player->CreateAnimation("DownIdle", "DownIdle", 0.1f, -1, -1, true);
		player->CreateAnimation("RightIdle", "RightIdle", 0.1f, -1, -1, true);
	
		player->CreateAnimation("UpMove", "UpMove", 0.1f, -1, -1, true);
		player->CreateAnimation("LeftMove", "LeftMove", 0.1f, -1, -1, true);
		player->CreateAnimation("DownMove", "DownMove", 0.1f, -1, -1, true);
		player->CreateAnimation("RightMove", "RightMove", 0.1f, -1, -1, true);

		player->CreateAnimation("Roll_Down", "Roll_Down", 0.05f, -1, -1, true);
		player->CreateAnimation("Roll_Left", "Roll_Left", 0.05f, -1, -1, true);
		player->CreateAnimation("Roll_Right", "Roll_Right", 0.05f, -1, -1, true);
		player->CreateAnimation("Roll_Up", "Roll_Up", 0.05f, -1, -1, true);

		player->CreateAnimation("Spear_Down_Attack_01", "Spear_Down_Attack_01", 0.1f, -1, -1, false);
		player->CreateAnimation("Spear_Down_Attack_02", "Spear_Down_Attack_02", 0.1f, -1, -1, false);
		player->CreateAnimation("Spear_Down_Attack_03", "Spear_Down_Attack_03", 0.1f, -1, -1, false);

		player->CreateAnimation("Spear_Left_Attack_01", "Spear_Left_Attack_01", 0.1f, -1, -1, false);
		player->CreateAnimation("Spear_Left_Attack_02", "Spear_Left_Attack_02", 0.1f, -1, -1, false);
		player->CreateAnimation("Spear_Left_Attack_03", "Spear_Left_Attack_03", 0.1f, -1, -1, false);

		player->CreateAnimation("Spear_Right_Attack_01", "Spear_Right_Attack_01", 0.1f, -1, -1, false);
		player->CreateAnimation("Spear_Right_Attack_02", "Spear_Right_Attack_02", 0.1f, -1, -1, false);
		player->CreateAnimation("Spear_Right_Attack_03", "Spear_Right_Attack_03", 0.1f, -1, -1, false);

		player->CreateAnimation("Spear_Up_Attack_01", "Spear_Up_Attack_01", 0.1f, -1, -1, false);
		player->CreateAnimation("Spear_Up_Attack_02", "Spear_Up_Attack_02", 0.1f, -1, -1, false);
		player->CreateAnimation("Spear_Up_Attack_03", "Spear_Up_Attack_03", 0.1f, -1, -1, false);

		

		player->AutoSpriteSizeOn();
		player->SetAutoScaleRatio(2.0f);
		player->ChangeAnimation("Start");
		player->SetFrameEvent("Start", 34, std::bind(&Player::TestEvent, this, std::placeholders::_1));


		//player->Transform.SetLocalPosition({ 0.0f,0.0f,-500.0f });
		
	}

	
	{
		Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Player);
		Col->SetCollisionType(ColType::AABBBOX2D);
		Col->Transform.SetLocalScale({ 50.0f, 50.0f, 1.0f });
	}

	{
		Left_Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::ObjectCollision);
		Left_Col->SetCollisionType(ColType::AABBBOX2D);
		Left_Col->Transform.AddLocalPosition({ -20.0f,0.0f }); 
		Left_Col->Transform.SetLocalScale({ 5.0f, 30.0f, 1.0f });
	}

	{
		Right_Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::ObjectCollision);
		Right_Col->SetCollisionType(ColType::AABBBOX2D);
		Right_Col->Transform.AddLocalPosition({ 20.0f,0.0f });
		Right_Col->Transform.SetLocalScale({ 5.0f, 30.0f, 1.0f });
	}

	{
		Bottom_Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::ObjectCollision);
		Bottom_Col->SetCollisionType(ColType::AABBBOX2D);
		Bottom_Col->Transform.AddLocalPosition({ 0.0f,-20.0f });
		Bottom_Col->Transform.SetLocalScale({ 30.0f, 5.0f, 1.0f });
	}

	{
		Top_Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::ObjectCollision);
		Top_Col->SetCollisionType(ColType::AABBBOX2D);
		Top_Col->Transform.AddLocalPosition({ 0.0f,20.0f });
		Top_Col->Transform.SetLocalScale({ 30.0f, 5.0f, 1.0f });
	}




	/*float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });*/

	Left_Event.Enter = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{	
		LeftMove = false;
	};

	Left_Event.Stay = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		LeftMove = false;
	};

	Left_Event.Exit = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		LeftMove = true;
	};
	

	Right_Event.Enter = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		RightMove = false;
	};

	Right_Event.Stay = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		RightMove = false;
	};


	Right_Event.Exit = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		RightMove = true;
	};


	Bottom_Event.Enter = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		DownMove = false;
	};

	Bottom_Event.Stay = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		DownMove = false;
	};


	Bottom_Event.Exit = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		DownMove = true;
	};


	Top_Event.Enter = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		UpMove = false;
	};

	Top_Event.Stay = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		UpMove = false;
	};

	
	Top_Event.Exit = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		UpMove = true;
	};


}

void Player::TestEvent(GameEngineRenderer* _Renderer)
{
	ChangeState(PlayerState::Start_Stop);
}





void Player::Update(float _Delta)
{
	
	
	//MainSpriteRenderer->AddImageScale(float4{-10.0f, 0.0f, 0.0f} *_Delta);

	// 몬스터가 몬스터랑 충돌하고 싶으면?
	// 내 미래의 위치

	/*TransformData date = Transform.GetConstTransformDataRef();
	float4 asdads = Player::this_Player->Transform.GetLocalPosition();
	Col->Collision(ContentsCollisionType::Door, { 300.0f, 0.0f, 0.0f }, [](std::vector<std::shared_ptr<GameEngineCollision>>& _Collision){});*/

	//this_Player->Transform.AddLocalPosition({ 0.5,0.0f });
	//if (xxxx 상황이 되면)
	//{
	//	MainSpriteRenderer->Death();
	//	MainSpriteRenderer = nullptr;
	//}

	// 충돌했냐 안했냐만 보면

	//std::list<std::shared_ptr<Monster>> MonsterList = 
	//	GetLevel()->GetObjectGroupConvert<Monster>(ContentsObjectType::Monster);

	//for (std::shared_ptr<Monster> MonsterPtr : MonsterList)
	//{
	//	// 랜더러로 하는 이유 => 액터로도 할수있는데
	//	// 보통 액터는 위치와 기준을 잡아주는 용도로 사용됩니다.
	//	// MainSpriteRenderer->Transform.Collision(MonsterPtr->Renderer->Transform);

	//	GameEngineTransform& Left = TestCollision->Transform;
	//	GameEngineTransform& Right = MonsterPtr->Renderer->Transform;
	//	Right.AddLocalRotation({ 0.0f, 0.0f, 360.0f * _Delta });

	//	// 콜리전 파라미터를 사용한 이유가. 
	//	if (GameEngineTransform::Collision({ Left , Right, ColType::OBBBOX2D }))
	//	{
	//		MonsterPtr->Death();
	//		int a = 0;
	//		// 충돌했다.
	//	}
	//}


	float Speed = 100.0f;

	//GetLevel()->GetMainCamera()->Transform.SetLocalPosition(Transform.GetWorldPosition());


	float4 awdd = Transform.GetLocalPosition();

	
	OutputDebugStringA(awdd.ToString("\n").c_str());



	//GameEngineColor Color = PlayMap::MainMap->GetColor(Transform.GetWorldPosition(), GameEngineColor::RED);

	//if (GameEngineColor::RED != Color)
	//{
	//	GrivityForce.Y -= _Delta * 100.0f;
	//	Transform.AddLocalPosition(GrivityForce * _Delta);
	//}
	//else 
	//{
	//	GrivityForce = 0.0f;
	//}
	// 땅에 딱붙게하고 싶다면 while돌려서 올려주세요.


	// float4 Color = GetColor(Transform.GetWorldPosition());

	Left_Col->CollisionEvent(ContentsCollisionType::Object, Left_Event);
	Right_Col->CollisionEvent(ContentsCollisionType::Object, Right_Event);
	Bottom_Col->CollisionEvent(ContentsCollisionType::Object, Bottom_Event);
	Top_Col->CollisionEvent(ContentsCollisionType::Object, Top_Event);

	UpdateState(_Delta);

	

}