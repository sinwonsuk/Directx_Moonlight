#pragma once
#pragma once
#include <GameEngineCore/GameEngineActor.h>


class Boss_Brick : public GameEngineActor
{
public:
	// constrcuter destructer
	Boss_Brick();
	~Boss_Brick();

	// delete Function
	Boss_Brick(const Boss_Brick& _Other) = delete;
	Boss_Brick(Boss_Brick&& _Other) noexcept = delete;
	Boss_Brick& operator=(const Boss_Brick& _Other) = delete;
	Boss_Brick& operator=(Boss_Brick&& _Other) noexcept = delete;




protected:
	void Start() override;
	void Update(float _Delta) override;

private:


	float Map_Number = 0.0f;
	std::shared_ptr<class GameEngineSpriteRenderer> Brick;
	
};


