#include "PreCompile.h"
#include "WorldLevel.h"
#include "Player.h"
#include "TownMap.h"
#include "Shop_House.h"

WorldLevel::WorldLevel()
{
}

WorldLevel::~WorldLevel()
{
}

void WorldLevel::Start()
{
	

	

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();

	GetMainCamera()->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, 0.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);







	{
		std::shared_ptr<TownMap> Object = CreateActor<TownMap>(ContentsObjectType::BackGround);
	}
	
	/*GetMainCamera()->Transform.SetLocalPosition({ 0.0f,0.0f, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);*/

	
	/*{
		std::shared_ptr<Shop_House> Object = CreateActor<Shop_House>();
		Object->Transform.SetLocalPosition({ 0.0f,0.0f,200.0f });
	}*/

	/*{
		std::shared_ptr<Player> Object = CreateActor<Player>();
		Object->Transform.SetLocalPosition({ 0.0f,0.0f,-200.0f });
	}*/

	


}

void WorldLevel::Update(float _Delta)
{
	
}

void WorldLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	{
		std::shared_ptr<Player> Object = CreateActor<Player>(ContentsObjectType::Player);
	
	}

	Player::this_Player->CameraCheck = true;
	Player::this_Player->Transform.AddLocalPosition({ 400.0f,400.0f });

	GetMainCamera()->Transform.AddLocalPosition({ 400.0f,400.0f });
	int a = 0;
}

void WorldLevel::LevelEnd(GameEngineLevel* _NextLevel)
{

	int a = 0;
}
