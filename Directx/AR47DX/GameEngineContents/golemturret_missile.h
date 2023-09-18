#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class golemturret_missile_State
{
	Missile,
	Finish,
};

enum class Dir
{
	Left,
	Right,
	Up,
	Down, 
};

class golemturret_missile : public GameEngineActor
{
public:
	// constrcuter destructer


	golemturret_missile();
	~golemturret_missile();

	// delete Function
	golemturret_missile(const golemturret_missile& _Other) = delete;
	golemturret_missile(golemturret_missile&& _Other) noexcept = delete;
	golemturret_missile& operator=(const golemturret_missile& _Other) = delete;
	golemturret_missile& operator=(golemturret_missile&& _Other) noexcept = delete;

	//void TestEvent(GameEngineRenderer* _Renderer);




	void ChangeState(golemturret_missile_State _State);
	void UpdateState(float _Time);
	void AttackUpdate(float _Time);
	void FinishUpdate(float _Time);
	void AnimationCheck(const std::string_view& _AnimationName);


	golemturret_missile_State GetPlayerStateValue()
	{
		return StateValue;
	}

	//void Move(float _Delta);
	Dir dir;

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	float StartSpeed = 20.0f;
	float Speed = 300.0f;
	float Roll_Speed = 400.0f;
	
	golemturret_missile_State StateValue = golemturret_missile_State::Missile;
	float4 GrivityForce = { 0.0f, 0.0f, 0.0f, 1.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> Missile;
	std::shared_ptr<GameEngineCollision> Col;
};
