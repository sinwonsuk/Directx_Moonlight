#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Monster_Manager.h"
enum class BabySlime_State
{
	Walk,
	LeftAttack,
	RightAttack,
	DownAttack,
	UpAttack, 

};

class BabySlime : public GameEngineActor , public Monster_Manager
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
	float Speed = 300.0f;
	float Hp = 100.0f;
	float DeltaTime = 0;
	float PushTime_Check = 0.0f;
	float PushSpeed = 300.0f;
	bool Weapon_Collision_Check = false;
	GameEngineRandom Random;
	BabySlime_State StateValue = BabySlime_State::Walk;
	float4 GrivityForce = { 0.0f, 0.0f, 0.0f, 1.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> Monster_BaseBar;
	std::shared_ptr<class GameEngineSpriteRenderer> Monster_HpBar;

	std::shared_ptr<class GameEngineSpriteRenderer> babySlime; 
	std::shared_ptr<GameEngineCollision> Col;
};

