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
	Rock_Down, 
	StickyArm_Start,
	StickyArm_End,
	StickyArm, 
	StickyArm_Aim2Cycle,

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
	void Rock_positioning(float _width, float _hight);
	void Rock_Down_Update(float _Time);
	void StickyArm_Start_Update(float _Time);
	void StickyArm_End_Update(float _Time); 
	void StickyArm_Aim2Cycle_Update(float _Time);

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
	EventParameter BodyEvent;
	bool CameraCheck = false;
	bool BossUI = false;


	int Shadow_Pos_Left = 0;
	int Shadow_Pos_Down = 0;
	int Shadow_Pos_Up = 0;
	bool AD = true;
	bool Weapon_Collision_Check = false;
	float Hp = 20.0f;
	float Rocks_Number = 0.0f;
	float Rocks_Check = 0.0f;
	float Rock_Width = 350.0f;
	float Rock_Hight = 300.0f;
	float Rock_Seed = 0;
	float Rock_Shadow_Pos = {}; 
	float Time = 0.0f;
	float Wave_Time = 0.0f;
	float Speed = 600.0f;
	float Rock_Degree = 0.0f;
	
	float Rock_Degree_control = 10.0f;

	bool test = false;
	//bool Weapon_Collision_Check = false;
	float TimeTest = 0.0f;
	int ArmCheck = 0; 
	GameEngineRandom Random;
	Boss_Monster_State StateValue = Boss_Monster_State::Start;
	std::shared_ptr<class Boss_Arm> Arm;
	std::shared_ptr<class Boss_Wirst> Bosswirst;
	std::shared_ptr<class GameEngineSpriteRenderer> Boss;
	
	std::shared_ptr<class Boss_Monster_UI> UI;
	GameEngineRandom random;
	std::shared_ptr<GameEngineCollision> Col;
	std::shared_ptr<GameEngineCollision> BodyCol;
	std::shared_ptr<GameEngineCollision> MoveCol;
};

