#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class Boss_Monster_State
{
	WakeUp,
	Idle,
	LeftAttack,
	RightAttack,
	DownAttack,
	UpAttack,

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
	void UpdateState(float _Time);
	void Wake_Up_Update(float _Time);
	void AnimationCheck(const std::string_view& _AnimationName);


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
	
	
	float Hp = 20.0f;

	float Time = 0.0f;
	float Speed = 200.0f;
	//bool Weapon_Collision_Check = false;

	Boss_Monster_State StateValue = Boss_Monster_State::Idle;
	std::shared_ptr<class GameEngineSpriteRenderer> Boss;
	std::shared_ptr<class GameEngineSpriteRenderer> Monster_HpBar;

	
	std::shared_ptr<GameEngineCollision> Col;

};

