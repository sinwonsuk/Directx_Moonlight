#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Big_Sword.h"
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
	Down_Attack_01,
	Down_Attack_02,
	Down_Attack_03,

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
	void BigSword_Down_Start(GameEngineRenderer* _Renderer);



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

	void DownAttackUpdate_01(float _Time);
	void DownAttackUpdate_02(float _Time);
	void DownAttackUpdate_03(float _Time);

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
	float Roll_Speed = 300.0f;
	PlayerState StateValue = PlayerState::RightIdle;
	std::shared_ptr<Big_Sword> Sword;
	std::shared_ptr<class GameEngineSpriteRenderer> player;
	float4 GrivityForce = {0.0f, 0.0f, 0.0f, 1.0f};

	//std::shared_ptr<GameEngineCollision> Col;
};

