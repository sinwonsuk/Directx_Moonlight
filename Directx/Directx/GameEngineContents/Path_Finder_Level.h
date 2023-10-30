#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include "TileMap.h"
// Ό³Έν :
class Path_Finder_Level : public GameEngineLevel
{
public:
	// constrcuter destructer
	Path_Finder_Level();
	~Path_Finder_Level();

	// delete Function
	Path_Finder_Level(const Path_Finder_Level& _Other) = delete;
	Path_Finder_Level(Path_Finder_Level&& _Other) noexcept = delete;
	Path_Finder_Level& operator=(const Path_Finder_Level& _Other) = delete;
	Path_Finder_Level& operator=(Path_Finder_Level&& _Other) noexcept = delete;
	std::vector<GameEngineActor*> Maps;

	
protected:
	void Start() override;
	void Update(float _Delta) override;

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

private:
	std::shared_ptr<TileMap> Tile;
	float Speed = 500.0f;
	std::vector<std::vector<bool>> test;
	std::vector<bool> testbool;
};