#pragma once

enum class Big_Sword_State
{
	Big_Sword_Down_01,
	Big_Sword_Down_02,
	Big_Sword_Down_03,

	Big_Sword_Left_01,
	Big_Sword_Left_02,
	Big_Sword_Left_03,

	Big_Sword_Right_01,
	Big_Sword_Right_02,
	Big_Sword_Right_03,

	Big_Sword_Up_01,
	Big_Sword_Up_02,
	Big_Sword_Up_03,

};
// Ό³Έν :
class Big_Sword : public GameEngineActor
{
public:

	Big_Sword();
	~Big_Sword();

	// delete Function
	Big_Sword(const Big_Sword& _Other) = delete;
	Big_Sword(Big_Sword&& _Other) noexcept = delete;
	Big_Sword& operator=(const Big_Sword& _Other) = delete;
	Big_Sword& operator=(Big_Sword&& _Other) noexcept = delete;

	

	void ChangeState(Big_Sword_State _State);
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


	std::shared_ptr<class GameEngineSpriteRenderer> Sword;
	std::shared_ptr<GameEngineCollision> Col;

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> ad;
	float StartSpeed = 10.0f;
	float Speed = 300.0f;
	float Roll_Speed = 300.0f;

	Big_Sword_State StateValue = Big_Sword_State::Big_Sword_Down_01;
	float Time = 0;

	float4 GrivityForce = { 0.0f, 0.0f, 0.0f, 1.0f };

	//std::shared_ptr<GameEngineCollision> Col;
};

