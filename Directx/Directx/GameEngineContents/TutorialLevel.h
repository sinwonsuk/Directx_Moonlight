#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include "TileMap.h"
// Ό³Έν :
class TutorialLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	TutorialLevel();
	~TutorialLevel();

	// delete Function
	TutorialLevel(const TutorialLevel& _Other) = delete;
	TutorialLevel(TutorialLevel&& _Other) noexcept = delete;
	TutorialLevel& operator=(const TutorialLevel& _Other) = delete;
	TutorialLevel& operator=(TutorialLevel&& _Other) noexcept = delete;
	std::vector<GameEngineActor*> Maps; 

	GameEngineColor GetColor(float4 _Pos, GameEngineColor _DefaultColor = { 255, 255, 255, 255 }, std::string_view _Name = {});

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

