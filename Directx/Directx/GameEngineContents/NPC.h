#pragma once
#include "Npc_Manager.h"


enum class Npc_Move
{
	Up_Left,
	Up_Right,
	Down_Left,
	Down_Right,
};

enum class Npc_Name
{
	Npc_01,
	Npc_02,
	Npc_03,
	Npc_04,
};




enum class Npc_State
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

	

};

class Npc : public GameEngineActor , public Npc_Manager
{
public:
	// constrcuter destructer
	
	Npc();
	~Npc();

	// delete Function
	Npc(const Npc& _Other) = delete;
	Npc(Npc&& _Other) noexcept = delete;
	Npc& operator=(const Npc& _Other) = delete;
	Npc& operator=(Npc&& _Other) noexcept = delete;

	void ChangeState(Npc_State _State);

	void UpdateState(float _Time);
	void UpdateState_02(float _Time);
	void UpdateState_03(float _Time);
	void UpdateState_04(float _Time);


	void AnimationCheck(std::string _AnimationName);

	void StartUpdate_01(float _Time);
	void StartUpdate_02(float _Time);
	void StartUpdate_03(float _Time);
	void StartUpdate_04(float _Time);

	void RightIdleUpdate_01(float _Time);
	void LeftIdleUpdate_01(float _Time);
	void DownIdleUpdate_01(float _Time);
	void UpIdleUpdate_01(float _Time);

	void RightMoveUpdate_01(float _Time);
	void LeftMoveUpdate_01(float _Time);
	void DownMoveUpdate_01(float _Time);
	void UpMoveUpdate_01(float _Time);

	void RightIdleUpdate_02(float _Time);
	void LeftIdleUpdate_02(float _Time);
	void DownIdleUpdate_02(float _Time);
	void UpIdleUpdate_02(float _Time);

	void RightMoveUpdate_02(float _Time);
	void LeftMoveUpdate_02(float _Time);
	void DownMoveUpdate_02(float _Time);
	void UpMoveUpdate_02(float _Time);

	
	void RightIdleUpdate_03(float _Time);
	void LeftIdleUpdate_03(float _Time);
	void DownIdleUpdate_03(float _Time);
	void UpIdleUpdate_03(float _Time);

	void RightMoveUpdate_03(float _Time);
	void LeftMoveUpdate_03(float _Time);
	void DownMoveUpdate_03(float _Time);
	void UpMoveUpdate_03(float _Time);


	void RightIdleUpdate_04(float _Time);
	void LeftIdleUpdate_04(float _Time);
	void DownIdleUpdate_04(float _Time);
	void UpIdleUpdate_04(float _Time);

	void RightMoveUpdate_04(float _Time);
	void LeftMoveUpdate_04(float _Time);
	void DownMoveUpdate_04(float _Time);
	void UpMoveUpdate_04(float _Time);

	void Set_MoveValue(Npc_Move _MoveValue)
	{
		MoveValue = _MoveValue; 
	}
	void Set_Npc_name(Npc_Name _Npc_name)
	{
		Npc_name = _Npc_name; 
	}


	bool test = true;
protected:
	void Start() override;
	void Update(float _Delta) override;

private:

	std::string Name;

	float Speed = 50.0f;
	float Time = 0.0f;
	float Number = 1.0f; 
	int Check = 0;
	GameEngineSoundPlayer Sound;
	std::shared_ptr<GameEngineCollision> Col;
	std::shared_ptr<GameEngineCollision> Col_Deal;
	
	Npc_Name Npc_name = Npc_Name::Npc_01;


	Npc_State StateValue = Npc_State::LeftMove;
	Npc_Move MoveValue = Npc_Move::Down_Right;
	std::shared_ptr<class GameEngineSpriteRenderer> npc;

	
};

