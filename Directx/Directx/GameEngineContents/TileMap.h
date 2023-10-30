#pragma once

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
     bool IsBlock(float4 _Pos);
protected:
	void Start() override;
	void Update(float _Delta) override;
private:
	
	std::shared_ptr<class GameEngineSpriteRenderer> Pixel;
	std::vector<std::vector<bool>> Tile_Maps;
	std::vector<bool> Tile_Map;

};