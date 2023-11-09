#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// Ό³Έν :
class Dungeon_Entrance_Level : public GameEngineLevel
{
public:
	// constrcuter destructer
	Dungeon_Entrance_Level();
	~Dungeon_Entrance_Level();

	// delete Function
	Dungeon_Entrance_Level(const Dungeon_Entrance_Level& _Other) = delete;
	Dungeon_Entrance_Level(Dungeon_Entrance_Level&& _Other) noexcept = delete;
	Dungeon_Entrance_Level& operator=(const Dungeon_Entrance_Level& _Other) = delete;
	Dungeon_Entrance_Level& operator=(Dungeon_Entrance_Level&& _Other) noexcept = delete;


protected:
	void Start() override;

	void Update(float _Delta) override;

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;
	bool check = false;
private:
	std::shared_ptr<class Dungeon_Entrance_Map> Entrance_Map; 
};

