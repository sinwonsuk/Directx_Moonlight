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

	/*{
		std::shared_ptr<Player> Object = CreateActor<Player>();
	}*/

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

	{
		std::shared_ptr<Player_UI> Object = CreateActor<Player_UI>();
	}

	{
		//Tile = CreateActor<TileMap>(ContentsObjectType::BackGround);

		/*size_t TileX = 192;
		size_t TileY = 18;*/


		size_t TileX = 768;
		size_t TileY = 72;




		/*Tile->TileRenderer->CreateTileMap({ TileX, TileY, {10, 10}, "Button_E.png" });

		for (size_t x = 0; x < TileX; x++)
		{
			for (size_t y = 0; y < TileY; y++)
			{
				Tile->TileRenderer->SetTileIndex({ x, y });
			}
		}*/
		test.reserve(5000);
		for (size_t x = 0; x < TileX; x++)
		{
			test.push_back(testbool);
			for (size_t y = 0; y < TileY; y++)
			{
				bool a = true;
				test[x].push_back(a); 
			}
		}
		
		for (size_t x = 0; x < TileX; x++)
		{
			for (size_t y = 0; y < TileY; y++)
			{
				if (GameEngineColor::MAGENTA == GetColor({ float(x),float(y) }, { 255,0,0,255 }, "Tutorial_Map_Pixel_05.png"))
				{
					test[x][y] = false;
				}
			}
		}
		int a = 0;
	}





	//
	
}

void TutorialLevel::Update(float _Delta)
{
	if (GameEngineInput::IsPress('1', this))
	{
		GameEngineCore::ChangeLevel("WorldLevel");
	}

	if (GameEngineInput::IsPress('E', this))
	{
		Tile->TileRenderer->Transform.AddLocalPosition({ 0.0f,0.0f,1.0f });
		
	}

	if (GameEngineInput::IsPress('Q', this))
	{
		Tile->TileRenderer->Transform.AddLocalPosition({ 0.0f,0.0f,-1.0f });
		
	}
	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();

	size_t TileX = 192;
	size_t TileY = 18;
	


	/*if (GameEngineInput::IsPress('A'))
	{
		GetCamera(0)->Transform.AddLocalPosition(float4::LEFT * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('D'))
	{
		GetCamera(0)->Transform.AddLocalPosition(float4::RIGHT * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('W'))
	{
		GetCamera(0)->Transform.AddLocalPosition(float4::UP * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('S'))
	{
		GetCamera(0)->Transform.AddLocalPosition(float4::DOWN * _Delta * Speed);
	}*/

}

void TutorialLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	{
		std::shared_ptr<Player> Object = CreateActor<Player>();
	}
}

void TutorialLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	Player::this_Player->Death();
	Player::this_Player = nullptr;
	
}
GameEngineColor TutorialLevel::GetColor(float4 _Pos, GameEngineColor _DefaultColor, std::string_view _Name)
{
	//_Pos.Y *= -1.0f;

	std::shared_ptr<GameEngineTexture> Tex = GameEngineTexture::Find(_Name);

	return Tex->GetColor(_Pos, _DefaultColor);
}