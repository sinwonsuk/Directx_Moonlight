#pragma once
#include <GameEngineCore/AStartPathFinder.h>

// Ό³Έν :
class TileMap : public GameEngineActor
{
public:
	static TileMap* Map;
	// constrcuter destructer
	TileMap();
	~TileMap();

	// delete Function
	TileMap(const TileMap& _Other) = delete;
	TileMap(TileMap&& _Other) noexcept = delete;
	TileMap& operator=(const TileMap& _Other) = delete;
	TileMap& operator=(TileMap&& _Other) noexcept = delete;

	GameEngineColor GetColor(float4 _Pos, GameEngineColor _DefaultColor = { 255, 255, 255, 255 }, std::string_view _Name = {});
	GameEngineColor Player_GetColor(float4 _Pos, GameEngineColor _DefaultColor = { 255, 255, 255, 255 }, std::string_view _Name = {});

	float4 ConvertWorldPosToTilePoint(float4 _Pos);

     bool IsBlock(float4 _Pos);

	 bool IsBlock(int X, int Y);

	std::vector<float4> GetPath(const float4& Start, const float4& End);

	std::vector<float4> GetPath(int _StartX, int _StartY, int _EndX, int _EndY);

protected:
	void Start() override;
	void Update(float _Delta) override;
private:
	
	AStartPathFinder PathFind;

	std::shared_ptr<class GameEngineSpriteRenderer> Pixel;
	std::vector<std::vector<bool>> Tile_Maps;
	std::vector<bool> Tile_Map;

};