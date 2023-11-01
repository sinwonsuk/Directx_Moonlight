#include "PreCompile.h"
#include "TileMap.h"
#include "Player.h"


































TileMap* TileMap::Map;

TileMap::TileMap()
{

}

TileMap::~TileMap()
{

}

void TileMap::Start()
{

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y,0.0f });

     Map = this;

	


	size_t TileX = 32;
	size_t TileY = 18;


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
			if (GameEngineColor::MAGENTA == GetColor({ float(x),float(y) }, { 255,0,0,255 }, "Mini_Dungeon_Map_Pixel_010.png"))
			{
				Tile_Maps[int(x)][int(y)] = false;
			}
			if (GameEngineColor::GREEN == GetColor({ float(x),float(y) }, { 255,0,0,255 }, "Mini_Dungeon_Map_Pixel_010.png"))
			{
				Tile_Maps[int(x)][int(y)] = false;
			}

			if (GameEngineColor::BLUE == GetColor({ float(x),float(y) }, { 255,0,0,255 }, "Mini_Dungeon_Map_Pixel_010.png"))
			{
				Tile_Maps[int(x)][int(y)] = false;
			}
		}
	}
}

void TileMap::Update(float _Delta)
{
	float4 Player_Pos = { Player::this_Player->Transform.GetWorldPosition()};
	
	if(IsBlock(Player_Pos) == true)
	{
		int a = 0; 
	}

	if (IsBlock(Player_Pos)==false)
	{
		int a = 0;
	}




	
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

float4 TileMap::ConvertWorldPosToTilePoint(float4 _Pos)
{
	_Pos.Y *= -1.f;
	float4 Index = _Pos / 40;
	return Index;
}

float4 TileMap::ConvertTilePointToWorldPos(PathPoint _Point)
{
	// 타일 절반 크기를 + 해줘
	float4 WorldPos = float4{ _Point.X * 40.0f, _Point.Y * 40.0f};
	return WorldPos;
}

bool TileMap::IsBlock(float4 _Pos)
{
	float4 Index = ConvertWorldPosToTilePoint(_Pos);

	return IsBlock(Index.iX(), Index.iY());
}

bool TileMap::test(int X, int Y)
{
	size_t TileX = 32;
	size_t TileY = 18;

	Y *= -1;

	if (X < 32)
	{
		if (X >= 0)
		{
			if (Y < 18)
			{
				if (Y >= 0)
				{
					return true;
				}
			}
		}
	}


	return false;
}

bool TileMap::IsBlock(int X, int Y)
{
	float4 Index;
	Index.X = X;
	Index.Y = Y;


	if (Y < 0)
	{
		Y *= -1;
	}

	if (GameEngineColor::MAGENTA == Player_GetColor(Index, { 255,0,0,255 }, "Mini_Dungeon_Map_Pixel_010.png"))
	{
		return true;
	}


	if (GameEngineColor::GREEN == Player_GetColor(Index, { 255,0,0,255 }, "Mini_Dungeon_Map_Pixel_010.png"))
	{
		
		return true;
	}
	if (GameEngineColor::BLUE == Player_GetColor(Index, { 255,0,0,255 }, "Mini_Dungeon_Map_Pixel_010.png"))
	{
		

		return true;
	}
	return false;
}

std::list<float4> TileMap::GetPath(const float4& Start, const float4& End)
{
	float4 StartIndex = ConvertWorldPosToTilePoint(Start);
	StartIndex.Y *= -1;
	float4 EndIndex = ConvertWorldPosToTilePoint(End);
	EndIndex.Y *= -1;

	return GetPath(StartIndex.iX(), StartIndex.iY(), EndIndex.iX(), EndIndex.iY());
}

std::list<float4> TileMap::GetPath(int _StartX, int _StartY, int _EndX, int _EndY)
{
	PathFind.IsBlockCallBack = [=](PathPoint _Point)
		{
			return IsBlock(_Point.X, _Point.Y);
		};

	PathFind.SizeOver = [=](PathPoint _Point)
		{
			return test(_Point.X, _Point.Y);
		};






	// 스타트 포인트와 앤드 포인트가 블록이면 

	std::list<PathPoint> Points = PathFind.PathFind({ _StartX, _StartY }, { _EndX, _EndY });

	std::list<float4> Result;

	for (PathPoint& Point : Points)
	{
		Result.push_back(ConvertTilePointToWorldPos(Point));
	}

	return Result;
}