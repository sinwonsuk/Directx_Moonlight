#pragma once
#include <GameEngineCore/GameEngineActor.h>


class Boss_Map : public GameEngineActor
{
public:
	// constrcuter destructer
	Boss_Map();
	~Boss_Map();

	// delete Function
	Boss_Map(const Boss_Map& _Other) = delete;
	Boss_Map(Boss_Map&& _Other) noexcept = delete;
	Boss_Map& operator=(const Boss_Map& _Other) = delete;
	Boss_Map& operator=(Boss_Map&& _Other) noexcept = delete;


	std::shared_ptr<class Boss_Monster> Monster;

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	float Map_Number = 0.0f;
	
	std::shared_ptr<class GameEngineSpriteRenderer> BackGround;
	bool BossCheck = false;

};
