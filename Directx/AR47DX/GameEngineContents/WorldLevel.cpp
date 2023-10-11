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

	GetMainCamera()->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f});
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

	//{
	//	std::shared_ptr<TownMap> Object = CreateActor<TownMap>(ContentsObjectType::BackGround);
	//}

	{
		std::shared_ptr<Shop_House> Object = CreateActor<Shop_House>(ContentsObjectType::BackGround);
		Object->Transform.SetLocalPosition({ -5000,-5000 });

	}


}

void WorldLevel::Update(float _Delta)
{
	
}

void WorldLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	{
		std::shared_ptr<Player> Object = CreateActor<Player>(ContentsObjectType::Player);
		Object->Transform.SetLocalPosition({ -4950,-5268 });
		GetMainCamera()->Transform.SetLocalPosition({ -4950,-5268 });
	}

	Player::this_Player->CameraCheck = true;
	//Player::this_Player->Transform.AddLocalPosition({ 400.0f,400.0f });

	//GetMainCamera()->Transform.AddLocalPosition({ 400.0f,400.0f });
	int a = 0;
}

void WorldLevel::LevelEnd(GameEngineLevel* _NextLevel)
{

	int a = 0;
}
