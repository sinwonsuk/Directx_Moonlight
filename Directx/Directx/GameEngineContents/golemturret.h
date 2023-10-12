#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class golemturret_State
{
	UpAttack, 
	DownAttack, 
};

class golemturret : public GameEngineActor
{
public:
	// constrcuter destructer


	golemturret();
	~golemturret();

	// delete Function
	golemturret(const golemturret& _Other) = delete;
	golemturret(golemturret&& _Other) noexcept = delete;
	golemturret& operator=(const golemturret& _Other) = delete;
	golemturret& operator=(golemturret&& _Other) noexcept = delete;

	//void TestEvent(GameEngineRenderer* _Renderer);




	void ChangeState(golemturret_State _State);
	void UpdateState(float _Time);
	void DownAttackUpdate(float _Time);
	void UpAttackUpdate(float _Time);
	void AnimationCheck(const std::string_view& _AnimationName);


	golemturret_State GetPlayerStateValue()
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
	golemturret_State StateValue = golemturret_State::DownAttack;
	float4 GrivityForce = { 0.0f, 0.0f, 0.0f, 1.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> turret;
	std::shared_ptr<GameEngineCollision> Col;
};