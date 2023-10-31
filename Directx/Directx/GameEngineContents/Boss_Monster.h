#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class Boss_Monster_State
{
	Start,
	WakeUp,
	Start2,
	Idle,
	LaunchArm,
	IdleNoArm,
	RecoveryArm, 
	Rocks_Spawn_Attack,

};

class Boss_Monster : public GameEngineActor
{
public:
	// constrcuter destructer


	Boss_Monster();
	~Boss_Monster();

	// delete Function
	Boss_Monster(const Boss_Monster& _Other) = delete;
	Boss_Monster(Boss_Monster&& _Other) noexcept = delete;
	Boss_Monster& operator=(const Boss_Monster& _Other) = delete;
	Boss_Monster& operator=(Boss_Monster&& _Other) noexcept = delete;

	//void TestEvent(GameEngineRenderer* _Renderer);




	void ChangeState(Boss_Monster_State _State);
	void StartUpdate(float _Time);
	void Start2Update(float _Time);
	void UpdateState(float _Time);
	void IdleUpdate(float _Time);
	void Wake_Up_Update(float _Time);
	void LaunchArm_Update(float _Time);
	void Idle_NoArm_Update(float _Time);
	void AnimationCheck(const std::string_view& _AnimationName);
	void RecoveryArmUpdate(float _Time);
	void Rocks_Spawn_Attack_Update(float _Time);

	//void RecoveryArmUpdate(float _Time);
	Boss_Monster_State GetBossStateValue()
	{
		return StateValue;
	}

	float GetHp()
	{
		return Hp;
	}



	
protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	EventParameter Event;
	bool CameraCheck = false;
	int ssss = 0;
	bool AD = false;
	float Hp = 20.0f;
	float ASSS = 0.0f;
	float Time = 0.0f;
	float Speed = 600.0f;
	//bool Weapon_Collision_Check = false;

	int ArmCheck = 0; 

	Boss_Monster_State StateValue = Boss_Monster_State::Start;
	std::shared_ptr<class Boss_Arm> Arm;
	std::shared_ptr<class GameEngineSpriteRenderer> Boss;
	std::shared_ptr<class GameEngineSpriteRenderer> Monster_HpBar;
	
	
	std::shared_ptr<GameEngineCollision> Col;

};

