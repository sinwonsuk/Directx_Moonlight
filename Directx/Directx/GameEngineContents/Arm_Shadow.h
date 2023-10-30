#pragma once
#include <GameEngineCore/GameEngineActor.h>

class Arm_Shadow : public GameEngineActor
{
public:
	// constrcuter destructer


	Arm_Shadow();
	~Arm_Shadow();

	// delete Function
	Arm_Shadow(const Arm_Shadow& _Other) = delete;
	Arm_Shadow(Arm_Shadow&& _Other) noexcept = delete;
	Arm_Shadow& operator=(const Arm_Shadow& _Other) = delete;
	Arm_Shadow& operator=(Arm_Shadow&& _Other) noexcept = delete;

	float ArmScale = 0.0f;

protected:
	void Start() override;
	void Update(float _Delta) override;

private:

	bool CollisionCheck = false;




	

	std::shared_ptr<class GameEngineSpriteRenderer> Arm_shadow;


};
