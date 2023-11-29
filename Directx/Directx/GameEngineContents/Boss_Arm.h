#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Arm_Shadow.h"

enum class Boss_Arm_State
{
	Start,
	Down,
	Up,
	Mask,
	DownPrev,
};

class Boss_Arm : public GameEngineActor
{
public:
	// constrcuter destructer


	Boss_Arm();
	~Boss_Arm();

	// delete Function
	Boss_Arm(const Boss_Arm& _Other) = delete;
	Boss_Arm(Boss_Arm&& _Other) noexcept = delete;
	Boss_Arm& operator=(const Boss_Arm& _Other) = delete;
	Boss_Arm& operator=(Boss_Arm&& _Other) noexcept = delete;

	//void TestEvent(GameEngineRenderer* _Renderer);




	void ChangeState(Boss_Arm_State _State);
	void StartUpdate(float _Time);
	void Down_Prev_Update(float _Time);
	void DownUpdate(float _Time);
	void UpUpdate(float _Time);
	void MaskUpdate(float _Time);
	void UpdateState(float _Time);
	
	void AnimationCheck(const std::string_view& _AnimationName);


	Boss_Arm_State GetBossStateValue()
	{
		return StateValue;
	}

	float GetHp()
	{
		return Hp;
	}

	bool GetFinishCheck()
	{
		return FinishCheck;
	}


protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	EventParameter Event;
	bool CameraCheck = false;
	bool FinishCheck = false;
	float Hp = 20.0f;

	float Time = 0.0f;
	float Speed = 1000.0f;
	float ArmScale = 0.0f;
	float4 Prev_Player_Pos = {};
	GameEngineSoundPlayer Crash_Sound;

	Boss_Arm_State StateValue = Boss_Arm_State::Start;

	std::shared_ptr<class GameEngineSpriteRenderer> Boss_arm;
	std::shared_ptr<class GameEngineSpriteRenderer> Boss_arm_Texture;
	std::shared_ptr<class GameEngineSpriteRenderer> Monster_HpBar;

	std::shared_ptr<Arm_Shadow> Shadow;
	std::shared_ptr<GameEngineCollision> Col;

};

