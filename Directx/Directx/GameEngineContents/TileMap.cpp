#include "PreCompile.h"
#include "TileMap.h"
#include "Player.h"
TileMap::TileMap()
{
}

TileMap::~TileMap()
{
}

void TileMap::Start()
{


	size_t TileX = 768;
	size_t TileY = 72;


	Tile_Maps.reserve(TileX* TileY);

	for (size_t x = 0; x < TileX; x++)
	{
		Tile_Maps.push_back(Tile_Map);
		for (size_t y = 0; y < TileY; y++)
		{
			bool a = true;
			Tile_Maps[x].push_back(a);
		}
	}

	for (size_t x = 0; x < TileX; x++)
	{
		for (size_t y = 0; y < TileY; y++)
		{
			if (GameEngineColor::MAGENTA == GetColor({ float(x),float(y) }, { 255,0,0,255 }, "Tutorial_Map_Pixel_05.png"))
			{
				Tile_Maps[x][y] = false;
			}
			if (GameEngineColor::GREEN == GetColor({ float(x),float(y) }, { 255,0,0,255 }, "Tutorial_Map_Pixel_05.png"))
			{
				Tile_Maps[x][y] = false;
			}

			if (GameEngineColor::BLUE == GetColor({ float(x),float(y) }, { 255,0,0,255 }, "Tutorial_Map_Pixel_05.png"))
			{
				Tile_Maps[x][y] = false;
			}
		}
	}
}

void TileMap::Update(float _Delta)
{
	float4 Player_Pos = { Player::this_Player->Transform.GetWorldPosition()};
	
	IsBlock(Player_Pos);
	
}

GameEngineColor TileMap::GetColor(float4 _Pos, GameEngineColor _DefaultColor, std::string_view _Name)
{
	//_Pos.Y *= -1.0f;

	std::shared_ptr<GameEngineTexture> Tex = GameEngineTexture::Find(_Name);

	return Tex->GetColor(_Pos, _DefaultColor);
}


GameEngineColor TileMap::Player_GetColor(float4 _Pos, GameEngineColor _DefaultColor, std::string_view _Name)
{
	_Pos.Y *= -1.0f;

	std::shared_ptr<GameEngineTexture> Tex = GameEngineTexture::Find(_Name);

	return Tex->GetColor(_Pos, _DefaultColor);
}

bool TileMap::IsBlock(float4 _Pos)
{
	

	if (GameEngineColor::MAGENTA == Player_GetColor({ _Pos / 10 }, { 255,0,0,255 }, "Tutorial_Map_Pixel_05.png"))
	{
		if (_Pos.Y < 0)
		{
			_Pos.Y *= -1; 
		}


		if (Tile_Maps[_Pos.X / 10][_Pos.Y / 10] != false)
		{
			return true;
		}

		else if (Tile_Maps[_Pos.X / 10][_Pos.Y / 10] == false)
		{
			return false;
		}
	}


	if (GameEngineColor::GREEN == Player_GetColor({ _Pos / 10 }, { 255,0,0,255 }, "Tutorial_Map_Pixel_05.png"))
	{
		if (_Pos.Y < 0)
		{
			_Pos.Y *= -1;
		}
		if (Tile_Maps[_Pos.X / 10][_Pos.Y / 10] != false)
		{
			return true;
		}

		else if (Tile_Maps[_Pos.X / 10][_Pos.Y / 10] == false)
		{
			return false;
		}
	}
	if (GameEngineColor::BLUE == Player_GetColor({ _Pos / 10 }, { 255,0,0,255 }, "Tutorial_Map_Pixel_05.png"))
	{
		if (_Pos.Y < 0)
		{
			_Pos.Y *= -1;
		}

		if (Tile_Maps[_Pos.X / 10][_Pos.Y / 10] != false)
		{
			return true;
		}

		else if (Tile_Maps[_Pos.X / 10][_Pos.Y / 10] == false)
		{
			return false;
		}
	}
}
