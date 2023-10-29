#pragma once
#include <GameEngineCore/GameEngineActor.h>


enum class golem_Solder_State
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

class golem_Solder : public GameEngineActor
{
public:
	// constrcuter destructer


	golem_Solder();
	~golem_Solder();

	// delete Function
	golem_Solder(const golem_Solder& _Other) = delete;
	golem_Solder(golem_Solder&& _Other) noexcept = delete;
	golem_Solder& operator=(const golem_Solder& _Other) = delete;
	golem_Solder& operator=(golem_Solder&& _Other) noexcept = delete;

	//void TestEvent(GameEngineRenderer* _Renderer);


	

	void ChangeState(golem_Solder_State _State);
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


	void Collision_Right_drop(); 
	void Collision_Left_drop();
	void Collision_Up_drop();
	void Collision_Down_drop();



protected:

	void Start() override;
	void Update(float _Delta) override;

private:
	bool Collision_Check = false;
	float Speed = 100.0f;
	float PushSpeed = 300.0f;

	float Time = 1.0f;
	float PushTime_Check = 0.0f;
	float degree = 0.0f;
	float Hp = 100.0f;
	float DeltaTime = 0;


	float4 MoveDir = {}; 
	float4 AD = {}; 
	bool Weapon_Collision_Check = false;
	



	golem_Solder_State StateValue = golem_Solder_State::LeftWalk;
	float4 GrivityForce = { 0.0f, 0.0f, 0.0f, 1.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> Solder;
	std::shared_ptr<class GameEngineSpriteRenderer> Monster_BaseBar;
	std::shared_ptr<class GameEngineSpriteRenderer> Monster_HpBar;
	EventParameter Event;
	EventParameter Mini_Event;
	std::shared_ptr<GameEngineCollision> Col;

	GameEngineRandom Random; 
};
