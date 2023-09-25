#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class Spear_Effect_State
{
	Effect

};

class Spear_Effect : public GameEngineActor
{
public:
	
	Spear_Effect();
	~Spear_Effect();

	// delete Function
	Spear_Effect(const Spear_Effect& _Other) = delete;
	Spear_Effect(Spear_Effect&& _Other) noexcept = delete;
	Spear_Effect& operator=(const Spear_Effect& _Other) = delete;
	Spear_Effect& operator=(Spear_Effect&& _Other) noexcept = delete;

	//void TestEvent(GameEngineRenderer* _Renderer);




	void ChangeState(Spear_Effect_State _State);
	void UpdateState(float _Time);
	void WalkUpdate(float _Time);
	void AnimationCheck(const std::string_view& _AnimationName);


	
	//void Move(float _Delta);


protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	bool CollisionCheck = false;
	float StartSpeed = 20.0f;
	float Speed = 300.0f;
	float Time = 0.0f;
	//BabySlime_State StateValue = BabySlime_State::Walk;
	float4 GrivityForce = { 0.0f, 0.0f, 0.0f, 1.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> babySlime;
	std::shared_ptr<class GameEngineSpriteRenderer> Efffet;
	std::shared_ptr<GameEngineCollision> Col;

};
