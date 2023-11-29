#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// Ό³Έν :
class End_Level : public GameEngineLevel
{
public:
	// constrcuter destructer
	End_Level();
	~End_Level();

	// delete Function
	End_Level(const End_Level& _Other) = delete;
	End_Level(End_Level&& _Other) noexcept = delete;
	End_Level& operator=(const End_Level& _Other) = delete;
	End_Level& operator=(End_Level&& _Other) noexcept = delete;


protected:
	void Start() override;

	void Update(float _Delta) override;

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;
	bool check = false;
private:
	std::shared_ptr<class Ending> end;
};
