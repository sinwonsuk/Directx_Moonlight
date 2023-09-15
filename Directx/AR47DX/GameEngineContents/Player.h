#pragma once
#include <GameEngineCore/GameEngineActor.h>
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



	void Move(float _Delta);




	bool MoveCheck = false;
	GameEngineColor GetColor(float4 _Pos, GameEngineColor _DefaultColor = { 255, 255, 255, 255 });
	std::shared_ptr<GameEngineCollision> Col;
protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	float StartSpeed = 10.0f;
	float Speed = 300.0f;
	float Roll_Speed = 300.0f;
	PlayerState StateValue = PlayerState::Start;
	std::shared_ptr<class GameEngineSpriteRenderer> player;
	float4 GrivityForce = {0.0f, 0.0f, 0.0f, 1.0f};

	//std::shared_ptr<GameEngineCollision> Col;
};

