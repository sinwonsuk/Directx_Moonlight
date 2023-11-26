#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Monster_Manager.h"

enum class golem_Stone_State
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
	LeftCollision, 
	RightCollision,
	UpCollision,
	DownCollision,
};

class golem_Stone : public GameEngineActor , public Monster_Manager
{
public:
	// constrcuter destructer


	golem_Stone();
	~golem_Stone();

	// delete Function
	golem_Stone(const golem_Stone& _Other) = delete;
	golem_Stone(golem_Stone&& _Other) noexcept = delete;
	golem_Stone& operator=(const golem_Stone& _Other) = delete;
	golem_Stone& operator=(golem_Stone&& _Other) noexcept = delete;

	//void TestEvent(GameEngineRenderer* _Renderer);


	float Angle(float4 a, float4 b);

	void ChangeState(golem_Stone_State _State);
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

	void LeftCollisionUpdate(float _Time);
	void RightCollisionUpdate(float _Time);
	void DownCollisionUpdate(float _Time);
	void UpCollisionUpdate(float _Time);

	void CollisionStop(float _Delta, std::string_view _Name = { "Tutorial_Map_Pixel.png" }, float4 _Transform = {});
	GameEngineColor GetColor(float4 _Pos, GameEngineColor _DefaultColor = { 255, 255, 255, 255 }, std::string_view _Name = {});
	//void Move(float _Delta);
	void MonsterPushUpdate(float _Delta);
	void MonsterDir();



	void SetName(std::string_view _Name)
	{
		Name = _Name;
	}
	

protected:

	void Start() override;
	void Update(float _Delta) override;

private:
	GameEngineRandom Random;
	float4 Pos = {};
	float4 MoveDir = {};
	std::string Name = { "Tutorial_Map_Pixel.png" };
	bool PlayerCheck = false;
	float Speed = 500.0f;
	float Time = 1.0f;
	float degree = 0.0f;


	float PushSpeed = 300.0f;
	float PushTime_Check = 0.0f;
	float Hp = 100.0f;
	bool Weapon_Collision_Check = false;



	
	golem_Stone_State StateValue = golem_Stone_State::LeftWalk;
	float4 GrivityForce = { 0.0f, 0.0f, 0.0f, 1.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> Stone;
	std::shared_ptr<class GameEngineSpriteRenderer> Monster_BaseBar;
	std::shared_ptr<class GameEngineSpriteRenderer> Monster_HpBar;

	std::shared_ptr<GameEngineCollision> Col;
	EventParameter Event;

	std::shared_ptr<GameEngineCollision> Mini_Col;
};



