#pragma once

#include <GameEngineCore/GameEngineActor.h>
enum class Spear_State
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
class Spear : public GameEngineActor
{
public:
	
	Spear();
	~Spear();

	// delete Function
	Spear(const Spear& _Other) = delete;
	Spear(Spear&& _Other) noexcept = delete;
	Spear& operator=(const Spear& _Other) = delete;
	Spear& operator=(Spear&& _Other) noexcept = delete;

	void TestEvent(GameEngineRenderer* _Renderer);

	void ChangeState(Spear_State _State);
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

	Spear_State GetStateValue()
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
	Spear_State StateValue = Spear_State::Spear_Down_01;
	float Time = 0;

	float4 GrivityForce = { 0.0f, 0.0f, 0.0f, 1.0f };

	//std::shared_ptr<GameEngineCollision> Col;
};

