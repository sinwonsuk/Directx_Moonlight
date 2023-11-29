#pragma once

enum class Gloves_State
{
	Gloves_Down_01,
	Gloves_Down_02,
	Gloves_Down_03,

	Gloves_Left_01,
	Gloves_Left_02,
	Gloves_Left_03,

	Gloves_Right_01,
	Gloves_Right_02,
	Gloves_Right_03,

	Gloves_Up_01,
	Gloves_Up_02,
	Gloves_Up_03,

};
// Ό³Έν :
class Gloves : public GameEngineActor
{
public:

	Gloves();
	~Gloves();

	// delete Function
	Gloves(const Gloves& _Other) = delete;
	Gloves(Gloves&& _Other) noexcept = delete;
	Gloves& operator=(const Gloves& _Other) = delete;
	Gloves& operator=(Gloves&& _Other) noexcept = delete;



	void ChangeState(Gloves_State _State);
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


	std::shared_ptr<class GameEngineSpriteRenderer> Glove;
	std::shared_ptr<GameEngineCollision> Col;

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> ad;
	float StartSpeed = 10.0f;
	float Speed = 300.0f;
	float Roll_Speed = 300.0f;

	Gloves_State StateValue = Gloves_State::Gloves_Down_01;
	float Time = 0;

	float4 GrivityForce = { 0.0f, 0.0f, 0.0f, 1.0f };

	GameEngineSoundPlayer Attack_Sound; 

	bool Attack_Sound_Check = false;

};
