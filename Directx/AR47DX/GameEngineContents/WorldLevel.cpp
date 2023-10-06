#include "PreCompile.h"
#include "WorldLevel.h"
#include "Player.h"
#include "TownMap.h"


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

	{
		std::shared_ptr<TownMap> Object = CreateActor<TownMap>(ContentsObjectType::BackGround);
	}
	//{
	//	std::shared_ptr<Player> Object = CreateActor<Player>(ContentsObjectType::Player);
	//}
	/*{
		std::shared_ptr<PlayMap> Object = CreateActor<PlayMap>(ContentsObjectType::BackGround);
		Map = Object;
	}





	{
		std::shared_ptr<PlayMap> Object = CreateActor<PlayMap>(ContentsObjectType::BackGround);
		Map = Object;
	}*/

}

void WorldLevel::Update(float _Delta)
{
	
}

void WorldLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	Player::this_Player->CameraCheck = true;
	Player::this_Player->Transform.AddLocalPosition({ 400.0f,400.0f });
	GetMainCamera()->Transform.AddLocalPosition({ 400.0f,400.0f });
	int a = 0;
}

void WorldLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	int a = 0;
}
