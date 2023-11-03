#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Monster_Manager.h"

enum class SlimeHermit_State
{
	Start,
	LeftWalk,
	RightWalk,
	DownWalk,
	UpWalk,
	DownAttack,
	RightAttack,
	UpAttack,
	LeftAttack,
	AttackCheck, 

};

class SlimeHermit : public GameEngineActor , public Monster_Manager
{
public:
	// constrcuter destructer


	SlimeHermit();
	~SlimeHermit();

	// delete Function
	SlimeHermit(const SlimeHermit& _Other) = delete;
	SlimeHermit(SlimeHermit&& _Other) noexcept = delete;
	SlimeHermit& operator=(const SlimeHermit& _Other) = delete;
	SlimeHermit& operator=(SlimeHermit&& _Other) noexcept = delete;

	//void TestEvent(GameEngineRenderer* _Renderer);


	

	void ChangeState(SlimeHermit_State _State);
	void UpdateState(float _Time);
	void AnimationCheck(const std::string_view& _AnimationName);

	void LeftMoveUpdate(float _Time);
	void RightMoveUpdate(float _Time);
	void UpMoveUpdate(float _Time);
	void DownMoveUpdate(float _Time);

	void LeftAttackUpdate(float _Time);
	void RightAttackUpdate(float _Time);
	void UpAttackUpdate(float _Time);
	void DownAttackUpdate(float _Time);

	void DirCheckUpdate(float _Time);

	void Dir_Attack_Check_Update(float _Time);

	void MonsterPushUpdate(float _Delta);

	float GetHp()
	{
		return Hp;
	}
	
	void MonsterDir();

protected:

	void Start() override;
	void Update(float _Delta) override;

private:
	bool Collision_Check = false;
	float Speed = 200.0f;
	float PushSpeed = 300.0f;

	float Time = 1.0f;
	float PushTime_Check = 0.0f;
	float degree = 0.0f;
	float Hp = 100.0f;
	float4 MoveDir = {}; 

	bool Weapon_Collision_Check = false;
	
	SlimeHermit_State StateValue = SlimeHermit_State::LeftWalk;
	float4 GrivityForce = { 0.0f, 0.0f, 0.0f, 1.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> Slime_Hermit;
	std::shared_ptr<class GameEngineSpriteRenderer> Monster_BaseBar;
	std::shared_ptr<class GameEngineSpriteRenderer> Monster_HpBar;
	EventParameter Event;
	std::shared_ptr<GameEngineCollision> Col;
	
};
