#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Monster_Manager.h"
enum class golemkamikaze_State
{
	Walk,
	Stop,
	Jump,

};

class golemkamikaze : public GameEngineActor, public Monster_Manager
{
public:
	// constrcuter destructer


	golemkamikaze();
	~golemkamikaze();

	// delete Function
	golemkamikaze(const golemkamikaze& _Other) = delete;
	golemkamikaze(golemkamikaze&& _Other) noexcept = delete;
	golemkamikaze& operator=(const golemkamikaze& _Other) = delete;
	golemkamikaze& operator=(golemkamikaze&& _Other) noexcept = delete;

	//void TestEvent(GameEngineRenderer* _Renderer);




	void ChangeState(golemkamikaze_State _State);
	void UpdateState(float _Time);
	void WalkUpdate(float _Time);
	void StopUpdate(float _Time);
	void JumpUpdate(float _Time);

	void AnimationCheck(const std::string_view& _AnimationName);


	golemkamikaze_State GetPlayerStateValue()
	{
		return StateValue;
	}

	float GetHp()
	{
		return Hp;
	}

	//void Move(float _Delta);

	void MonsterPushUpdate(float _Delta);

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	EventParameter Event;
	EventParameter Mini_Event;
	bool CollisionCheck = false;
	float Speed = 400.0f;
	float Hp = 100.0f;
	float DeltaTime = 0;
	float PushTime_Check = 0.0f;
	float PushSpeed = 300.0f;
	bool Weapon_Collision_Check = false;
	bool Monster_Pos = false;
	GameEngineRandom Random;
	golemkamikaze_State StateValue = golemkamikaze_State::Walk;
	float4 GrivityForce = { 0.0f, 0.0f, 0.0f, 1.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> Monster_BaseBar;
	std::shared_ptr<class GameEngineSpriteRenderer> Monster_HpBar;
	float4 Player_Pos = {}; 
	std::shared_ptr<class GameEngineSpriteRenderer> Monster;
	std::shared_ptr<GameEngineCollision> Col;
	std::shared_ptr<GameEngineCollision> Boom_Col;
	std::shared_ptr<GameEngineCollision> Range_Col;
	float4 MoveDir = {}; 
};

