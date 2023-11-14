#include "PreCompile.h"
#include "TutorialLevel.h"
#include "TutorialMap.h"
#include "TutorialMap_02.h"
#include "TutorialMap_03.h"
#include "TutorialMap_04.h"
#include "Tutorial_Map_05.h"
#include "Tutorial_Map_06.h"
#include "Player.h"
#include "Player_UI.h"
#include "TileMap.h"
#include "CameraCollision.h"
TutorialLevel::TutorialLevel()
{

}

TutorialLevel::~TutorialLevel()
{

}

void TutorialLevel::Start()
{
	GameEngineInput::AddInputObject(this);


	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();

	GetMainCamera()->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

	{
		std::shared_ptr<CameraCollision> object = CreateActor<CameraCollision>();
	}
	

	{
		std::shared_ptr<TutorialMap> Object = CreateActor<TutorialMap>();

	}

	{
		std::shared_ptr<TutorialMap_02> Object = CreateActor<TutorialMap_02>();
	}
	{
		std::shared_ptr<TutorialMap_03> Object = CreateActor<TutorialMap_03>();
	}
	{
		std::shared_ptr<TutorialMap_04> Object = CreateActor<TutorialMap_04>();
	}
	{
		std::shared_ptr<TutorialMap_05> Object = CreateActor<TutorialMap_05>();
	}
	{
		std::shared_ptr<TutorialMap_06> Object = CreateActor<TutorialMap_06>();
	}

	/*{
		std::shared_ptr<Player_UI> Object = CreateActor<Player_UI>();
	}*/
	/*{
		std::shared_ptr<TileMap> Object = CreateActor<TileMap>();
	}*/




}

void TutorialLevel::Update(float _Delta)
{
	/*if (GameEngineInput::IsPress('1', this))
	{
		GameEngineCore::ChangeLevel("WorldLevel");
	}

	*/
	

	



	

}

void TutorialLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	{
		std::shared_ptr<Player> Object = CreateActor<Player>();
		Object->ChangeState(PlayerState::Start);
	}
}

void TutorialLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	Player::this_Player->player_UI->Death(); 
	Player::this_Player->Death();
	Player::this_Player = nullptr;
	
}
GameEngineColor TutorialLevel::GetColor(float4 _Pos, GameEngineColor _DefaultColor, std::string_view _Name)
{
	//_Pos.Y *= -1.0f;

	std::shared_ptr<GameEngineTexture> Tex = GameEngineTexture::Find(_Name);

	return Tex->GetColor(_Pos, _DefaultColor);
}


GameEngineColor TutorialLevel::Player_GetColor(float4 _Pos, GameEngineColor _DefaultColor, std::string_view _Name)
{
	_Pos.Y *= -1.0f;

	std::shared_ptr<GameEngineTexture> Tex = GameEngineTexture::Find(_Name);

	return Tex->GetColor(_Pos, _DefaultColor);
}