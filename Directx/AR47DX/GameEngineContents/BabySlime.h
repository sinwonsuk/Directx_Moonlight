#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class BabySlime_State
{
	Walk,
	LeftAttack,
	RightAttack,
	DownAttack,
	UpAttack, 

};

class BabySlime : public GameEngineActor
{
public:
	// constrcuter destructer

	
	BabySlime();
	~BabySlime();

	// delete Function
	BabySlime(const BabySlime& _Other) = delete;
	BabySlime(BabySlime&& _Other) noexcept = delete;
	BabySlime& operator=(const BabySlime& _Other) = delete;
	BabySlime& operator=(BabySlime&& _Other) noexcept = delete;

	//void TestEvent(GameEngineRenderer* _Renderer);




	void ChangeState(BabySlime_State _State);
	void UpdateState(float _Time);
	void WalkUpdate(float _Time);
	void AnimationCheck(const std::string_view& _AnimationName);
	

	BabySlime_State GetPlayerStateValue()
	{
		return StateValue;
	}

	//void Move(float _Delta);

	
protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	float StartSpeed = 20.0f;
	float Speed = 300.0f;
	float Roll_Speed = 400.0f;
	BabySlime_State StateValue = BabySlime_State::Walk;
	float4 GrivityForce = { 0.0f, 0.0f, 0.0f, 1.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> babySlime; 
	std::shared_ptr<GameEngineCollision> Col;
};

