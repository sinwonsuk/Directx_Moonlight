#pragma once

#include <GameEngineCore/GameEngineActor.h>


enum class UpGrade_Spear_State
{
	Spear_Down_01,
	Spear_Down_02,
	Spear_Down_03,

	Spear_Left_01,
	Spear_Left_02,
	Spear_Left_03,

	Spear_Right_01,
	Spear_Right_02,
	Spear_Right_03,

	Spear_Up_01,
	Spear_Up_02,
	Spear_Up_03,
};
// Ό³Έν :
class UpGrade_Spear : public GameEngineActor
{
public:

	UpGrade_Spear();
	~UpGrade_Spear();

	// delete Function
	UpGrade_Spear(const UpGrade_Spear& _Other) = delete;
	UpGrade_Spear(UpGrade_Spear&& _Other) noexcept = delete;
	UpGrade_Spear& operator=(const UpGrade_Spear& _Other) = delete;
	UpGrade_Spear& operator=(UpGrade_Spear&& _Other) noexcept = delete;


	void ChangeState(UpGrade_Spear_State _State);
	void UpdateState(float _Time);
	void AnimationCheck(const std::string_view& _AnimationName);

	void Down_Attack_Update_01(float _Time);
	void Down_Attack_Update_02(float _Time);
	void Down_Attack_Update_03(float _Time);

	void Left_Attack_Update_01(float _Time);
	void Left_Attack_Update_02(float _Time);
	void Left_Attack_Update_03(float _Time);

	void Right_Attack_Update_01(float _Time);
	void Right_Attack_Update_02(float _Time);
	void Right_Attack_Update_03(float _Time);

	void Up_Attack_Update_01(float _Time);
	void Up_Attack_Update_02(float _Time);
	void Up_Attack_Update_03(float _Time);

	UpGrade_Spear_State GetStateValue()
	{
		return StateValue;
	}

	

	bool tests = false;
	std::shared_ptr<class GameEngineSpriteRenderer> spear;
	std::shared_ptr<GameEngineCollision> Col;
protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> ad;
	float StartSpeed = 10.0f;
	float Speed = 300.0f;
	float Roll_Speed = 300.0f;
	UpGrade_Spear_State StateValue = UpGrade_Spear_State::Spear_Down_01;
	float Time = 0;

	float4 GrivityForce = { 0.0f, 0.0f, 0.0f, 1.0f };

	GameEngineSoundPlayer Attack_Sound; 

	bool Attack_Sound_Check = false;
	//std::shared_ptr<GameEngineCollision> Col;
};
