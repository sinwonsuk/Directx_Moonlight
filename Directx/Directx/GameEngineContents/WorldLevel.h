#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// Ό³Έν :
class WorldLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	WorldLevel();
	~WorldLevel();

	// delete Function
	WorldLevel(const WorldLevel& _Other) = delete;
	WorldLevel(WorldLevel&& _Other) noexcept = delete;
	WorldLevel& operator=(const WorldLevel& _Other) = delete;
	WorldLevel& operator=(WorldLevel&& _Other) noexcept = delete;


protected:
	void Start() override;

	void Update(float _Delta) override;

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;
	bool check = false;
private:
	std::shared_ptr<class TownMap> Map;
	std::shared_ptr<class Inventory> inventory;
	std::shared_ptr<class Black_Smith> Black_smith;
};

