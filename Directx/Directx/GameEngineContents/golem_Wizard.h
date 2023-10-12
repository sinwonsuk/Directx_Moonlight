#pragma once
#include <GameEngineCore/GameEngineActor.h>


enum class golem_Wizard_State
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

class golem_Wizard : public GameEngineActor
{
public:
	// constrcuter destructer


	golem_Wizard();
	~golem_Wizard();

	// delete Function
	golem_Wizard(const golem_Wizard& _Other) = delete;
	golem_Wizard(golem_Wizard&& _Other) noexcept = delete;
	golem_Wizard& operator=(const golem_Wizard& _Other) = delete;
	golem_Wizard& operator=(golem_Wizard&& _Other) noexcept = delete;

	//void TestEvent(GameEngineRenderer* _Renderer);


	float Angle(float4 a ,float4 b);

	void ChangeState(golem_Wizard_State _State);
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
	//void Move(float _Delta);

	void MonsterPushUpdate(float _Delta);
	void MonsterDir();
protected:

	void Start() override;
	void Update(float _Delta) override;

private:
	bool CollisionCheck = false;
	float Speed = 100.0f;
	float Time = 1.0f;
	float degree = 0.0f;
	float PushSpeed = 300.0f;

	float4 MoveDir = {};
	float PushTime_Check = 0.0f;
	float Hp = 100.0f;
	bool Weapon_Collision_Check = false;

	golem_Wizard_State StateValue = golem_Wizard_State::LeftWalk;
	float4 GrivityForce = { 0.0f, 0.0f, 0.0f, 1.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> Wizard;
	std::shared_ptr<class GameEngineSpriteRenderer> Monster_BaseBar;
	std::shared_ptr<class GameEngineSpriteRenderer> Monster_HpBar;

	std::shared_ptr<GameEngineCollision> Col;
	std::shared_ptr<GameEngineCollision> Body;
	EventParameter Event;
};

