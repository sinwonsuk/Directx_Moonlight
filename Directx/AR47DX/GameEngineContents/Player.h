#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Spear.h"
enum class PlayerState
{
	Start,
	Start_Stop,
	LeftIdle,
	RightIdle,
	UpIdle,
	DownIdle, 
	LeftMove,
	RightMove,
	UpMove,
	DownMove,
	RollRight,
	RollLeft,
	RollUp,
	RollDown, 

	Spear_Down_Attack_01,
	Spear_Down_Attack_02,
	Spear_Down_Attack_03,

	Spear_Up_Attack_01,
	Spear_Up_Attack_02,
	Spear_Up_Attack_03,

	Spear_Left_Attack_01,
	Spear_Left_Attack_02,
	Spear_Left_Attack_03,

	Spear_Right_Attack_01,
	Spear_Right_Attack_02,
	Spear_Right_Attack_03,

	

};
// Ό³Έν :
class Player : public GameEngineActor
{
public:
	// constrcuter destructer

	static Player* this_Player;
	Player();
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

	void TestEvent(GameEngineRenderer* _Renderer);
	



	void ChangeState(PlayerState _State);
	void UpdateState(float _Time);
	void AnimationCheck(const std::string_view& _AnimationName);
	void StopUpdate(float _Time);
	void StartUpdate(float _Time);

	void RightIdleUpdate(float _Time);
	void LeftIdleUpdate(float _Time);
	void DownIdleUpdate(float _Time);
	void UpIdleUpdate(float _Time);

	void RightMoveUpdate(float _Time);
	void LeftMoveUpdate(float _Time);
	void DownMoveUpdate(float _Time);
	void UpMoveUpdate(float _Time);

	void Roll_RightUpdate(float _Time);
	void Roll_LeftUpdate(float _Time);
	void Roll_DownUpdate(float _Time);
	void Roll_UpUpdate(float _Time);

	void Spear_Down_AttackUpdate_01(float _Time);
	void Spear_Down_AttackUpdate_02(float _Time);
	void Spear_Down_AttackUpdate_03(float _Time);

	void Spear_Left_AttackUpdate_01(float _Time);
	void Spear_Left_AttackUpdate_02(float _Time);
	void Spear_Left_AttackUpdate_03(float _Time);

	void Spear_Right_AttackUpdate_01(float _Time);
	void Spear_Right_AttackUpdate_02(float _Time);
	void Spear_Right_AttackUpdate_03(float _Time);

	void Spear_Up_AttackUpdate_01(float _Time);
	void Spear_Up_AttackUpdate_02(float _Time);
	void Spear_Up_AttackUpdate_03(float _Time);

	void WeaponManager(Spear_State _SpearState, PlayerState state, PlayerState _playstate);


	PlayerState GetPlayerStateValue()
	{
		return StateValue;
	}

	void Move(float _Delta);




	bool MoveCheck = false;

	std::shared_ptr<GameEngineCollision> Col;
protected:
	void Start() override;
	void Update(float _Delta) override;

private:

	bool AttackCheck = false;

	float StartSpeed = 10.0f;
	float Speed = 300.0f;
	float Roll_Speed = 400.0f;
	PlayerState StateValue = PlayerState::RightIdle;
	std::shared_ptr<Spear> spear;
	std::shared_ptr<class GameEngineSpriteRenderer> player;
	float4 GrivityForce = {0.0f, 0.0f, 0.0f, 1.0f};

	//std::shared_ptr<GameEngineCollision> Col;
};

