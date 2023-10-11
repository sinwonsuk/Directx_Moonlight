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
	return GameEngineColor();
}

void Shop_House::Start()
{
	/*float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y });*/
	
	
	
	/*{
		Black = CreateComponent<GameEngineSpriteRenderer>(0);
		Black->SetSprite("Black", 0);
		Black->AutoSpriteSizeOn();
		Black->SetAutoScaleRatio(2.0f);
		Black->Transform.AddLocalPosition({ 0.0f,0.0f,-200 });
	}*/

	{
		Shop = CreateComponent<GameEngineSpriteRenderer>(0);
		Shop->SetSprite("Shop", 0);
		Shop->AutoSpriteSizeOn();
		Shop->SetAutoScaleRatio(2.0f);
		///Shop->Transform.AddLocalPosition({ 0.0f,0.0f,-150 });
	}



	/*{
		BackGround = CreateComponent<GameEngineSpriteRenderer>(-99);
		BackGround->SetSprite("Shop", 0);
		BackGround->AutoSpriteSizeOn();
		BackGround->SetAutoScaleRatio(2.0f);
	}*/


	/*Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::ShopDoor);
	Col->Transform.SetLocalScale({ 50.0f,50.0f });
	Col->Transform.SetLocalPosition({55.0f,-25.0f});
	Col->SetCollisionType(ColType::AABBBOX2D);





	

	Event.Enter = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
	
	};

	Event.Stay = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
		
	};

	Event.Exit = [this](GameEngineCollision* Col, GameEngineCollision* col)
	{
	
	};*/






}

void Shop_House::Update(float _DeltaTime)
{
	TransformData Camera = GetLevel()->GetMainCamera()->Transform.GetConstTransformDataRef();

	TransformData Shphs = Shop->Transform.GetConstTransformDataRef();

	////TransformData Players = Player::this_Player->Transform.GetConstTransformDataRef();
	//TransformData Blacks = Black->Transform.GetConstTransformDataRef();






	//float4 Camera_Move = float4::LerpClamp(0, 300, _DeltaTime);

	//

	//if (Col->Collision(ContentsCollisionType::Player))
	//{
	//	CameraMove = true; 
	//}

	//if (CameraMove == true && GetLevel()->GetMainCamera()->Transform.GetWorldPosition().Y < -4793)
	//{
	//	GetLevel()->GetMainCamera()->Transform.AddLocalPosition({ 0.0f,Camera_Move.X });
	//}


}
