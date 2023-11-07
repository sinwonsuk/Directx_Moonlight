#include "PreCompile.h"
#include "ShopLevel.h"
#include "Shop_House.h"
#include "Player.h"
#include "Black.h"
#include "Black_Out.h"
ShopLevel::ShopLevel()
{
}

ShopLevel::~ShopLevel()
{
}

void ShopLevel::Start()
{
	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();

	GetMainCamera()->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

	


}

void ShopLevel::Update(float _Delta)
{
	/*float4 awdd = GetMainCamera()->Transform.GetLocalPosition();


	OutputDebugStringA(awdd.ToString("\n").c_str());*/

}

void ShopLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	GetMainCamera()->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

	
	std::shared_ptr<Black> Object = CreateActor<Black>(ContentsObjectType::Player);
	


	if (Player::LevelType == Leveltype::Dungeon_Death)
	{
		std::shared_ptr<Player> Object = CreateActor<Player>(ContentsObjectType::Player);
		Object->ChangeState(PlayerState::Bed);
		Object->Transform.SetWorldPosition({ 795.0f,-140.0f });
		GetMainCamera()->Transform.AddWorldPosition({ 0.0f,300.0f }); 
	}
	else
	{
		
		std::shared_ptr<Player> Object = CreateActor<Player>(ContentsObjectType::Player);
		Object->Transform.AddLocalPosition({ 55.0f,-200.0f });		
	}

	{
		House = CreateActor<Shop_House>();
	}

	
	//Object->Transform.AddLocalPosition({ 55.0f,-200.0f });
	//Player::this_Player->CameraCheck = true;
}

void ShopLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	House->black_Out->Death(); 
	House->Death(); 

	Player::LevelType = Leveltype::Town;
	Player::this_Player->Death();
	Player::this_Player = nullptr;

}
