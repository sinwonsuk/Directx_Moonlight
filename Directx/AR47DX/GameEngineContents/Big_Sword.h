#pragma once
#pragma once
#include <GameEngineCore/GameEngineActor.h>
enum class Big_Sword_State
{
	BigSword_Down_01,
	BigSword_Down_02,
	BigSword_Down_03,


};
// Ό³Έν :
class Big_Sword : public GameEngineActor
{
public:
	// constrcuter destructer

	//static Big_Sword* this_Player;
	Big_Sword();
	~Big_Sword();

	// delete Function
	Big_Sword(const Big_Sword& _Other) = delete;
	Big_Sword(Big_Sword&& _Other) noexcept = delete;
	Big_Sword& operator=(const Big_Sword& _Other) = delete;
	Big_Sword& operator=(Big_Sword&& _Other) noexcept = delete;

	void TestEvent(GameEngineRenderer* _Renderer);

	void ChangeState(Big_Sword_State _State);
	void UpdateState(float _Time);
	void AnimationCheck(const std::string_view& _AnimationName);

	void Down_Attack_Update_01(float _Time);
	void Down_Attack_Update_02(float _Time);
	void Down_Attack_Update_03(float _Time);

	void SetStateValue(const Big_Sword_State& _StateValue)
	{
		StateValue = _StateValue;
	}




	bool tests = false;
	std::shared_ptr<GameEngineCollision> Col;
protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	float StartSpeed = 10.0f;
	float Speed = 300.0f;
	float Roll_Speed = 300.0f;
	Big_Sword_State StateValue = Big_Sword_State::BigSword_Down_01;
	std::shared_ptr<class GameEngineSpriteRenderer> Sword;
	float4 GrivityForce = { 0.0f, 0.0f, 0.0f, 1.0f };

	//std::shared_ptr<GameEngineCollision> Col;
};

