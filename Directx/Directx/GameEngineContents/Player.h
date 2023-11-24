#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Spear.h"
#include "Big_Sword.h"
#include "Gloves.h"
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

	Death,
	Bed,
	Scale,

	Sword_Left_Attack_01,
	Sword_Left_Attack_02,
	Sword_Left_Attack_03,

	Sword_Right_Attack_01,
	Sword_Right_Attack_02,
	Sword_Right_Attack_03,

	Sword_Down_Attack_01,
	Sword_Down_Attack_02,
	Sword_Down_Attack_03,

	Sword_Up_Attack_01,
	Sword_Up_Attack_02,
	Sword_Up_Attack_03,


	Gloves_Left_Attack_01,
	Gloves_Left_Attack_02,
	Gloves_Left_Attack_03,

	Gloves_Right_Attack_01,
	Gloves_Right_Attack_02,
	Gloves_Right_Attack_03,

	Gloves_Down_Attack_01,
	Gloves_Down_Attack_02,
	Gloves_Down_Attack_03,

	Gloves_Up_Attack_01,
	Gloves_Up_Attack_02,
	Gloves_Up_Attack_03,



};
// ¼³¸í :
class Player : public GameEngineActor
{
public:
	// constrcuter destructer
	static Leveltype LevelType;
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

	void DeathUpdate(float _Time);
	void BedUpdate(float _Time);
	void ScaleUpdate(float _Time);
	void WeaponManager(Spear_State _SpearState, PlayerState state, PlayerState _playstate);
	void Sword_Weapon_Manager(Big_Sword_State _SpearState, PlayerState state, PlayerState _playstate);
	void Gloves_Weapon_Manager(Gloves_State _SpearState, PlayerState state, PlayerState _playstate);

	void Attack(Spear_State Spear_Weapon , Big_Sword_State Sword_Weapon, Gloves_State Gloves_Weapon ,PlayerState Spearstate, PlayerState _Swordstate,PlayerState _Glovestate);


	void Sword_Left_AttackUpdate_01(float _Time);
	void Sword_Left_AttackUpdate_02(float _Time);
	void Sword_Left_AttackUpdate_03(float _Time);

	void Sword_Right_AttackUpdate_01(float _Time);
	void Sword_Right_AttackUpdate_02(float _Time);
	void Sword_Right_AttackUpdate_03(float _Time);

	void Sword_Up_AttackUpdate_01(float _Time);
	void Sword_Up_AttackUpdate_02(float _Time);
	void Sword_Up_AttackUpdate_03(float _Time);

	void Sword_Down_AttackUpdate_01(float _Time);
	void Sword_Down_AttackUpdate_02(float _Time);
	void Sword_Down_AttackUpdate_03(float _Time);
	

	void Gloves_Left_AttackUpdate_01(float _Time);
	void Gloves_Left_AttackUpdate_02(float _Time);
	void Gloves_Left_AttackUpdate_03(float _Time);

	void Gloves_Right_AttackUpdate_01(float _Time);
	void Gloves_Right_AttackUpdate_02(float _Time);
	void Gloves_Right_AttackUpdate_03(float _Time);

	void Gloves_Up_AttackUpdate_01(float _Time);
	void Gloves_Up_AttackUpdate_02(float _Time);
	void Gloves_Up_AttackUpdate_03(float _Time);

	void Gloves_Down_AttackUpdate_01(float _Time);
	void Gloves_Down_AttackUpdate_02(float _Time);
	void Gloves_Down_AttackUpdate_03(float _Time);

	PlayerState GetPlayerStateValue()
	{
		return StateValue;
	}

	void Move(float _Delta);
	void HitUpdate(float _Delta);

	// ¾ðÁ¨°£ ¹Ù²Û´Ù 
	float Speed = 300.0f;
	float Roll_Speed = 400.0f;
	std::shared_ptr<GameEngineCollision> Col;
	
	bool Not_Move = true; 
	bool LeftMove = true;
	bool RightMove = true;
	bool DownMove = true;
	bool UpMove = true;
	bool MonsterDeath = false;
	CameraType Camera = CameraType::None;
	static int RandomSeed;
	//Leveltype LevelType = Leveltype::None;
	float Hp = 1;
	float Scale_Time = 0.0f;
	float4 Test_Move = {};
	std::shared_ptr<class Black_Out> Black;
	std::shared_ptr<class Player_UI> player_UI;
	bool RolCheck = false;
	std::list<std::shared_ptr<Spear>> spears;
protected:
	void Start() override;
	void Update(float _Delta) override;

private:

	
	
	std::shared_ptr<GameEngineCollision> Mini_Col;

	EventParameter Left_Event;
	EventParameter Right_Event;
	EventParameter Bottom_Event;
	EventParameter Top_Event;
	EventParameter Event;
	std::shared_ptr<GameEngineCollision> Left_Col;
	std::shared_ptr<GameEngineCollision> Right_Col;
	std::shared_ptr<GameEngineCollision> Bottom_Col;
	std::shared_ptr<GameEngineCollision> Top_Col;
	
	
	bool AttackCheck = false;
	bool Monster_Attack_Check = false;
	bool afterimage_Check = false;
	bool DieCheck = false;

	float StartSpeed = 20.0f;
	float Color_Time = 0.0f;
	float afterimage_Time = 0.0f;
	int Hit_Check = 0;
	PlayerState StateValue = PlayerState::LeftIdle;
	//std::shared_ptr<Spear> spear;
	std::shared_ptr<class GameEngineSpriteRenderer> player;

	float4 GrivityForce = {0.0f, 0.0f, 0.0f, 1.0f};
	int UICheck = 0;
	
	float Hp_Bar_reduce = 0.0f;
	//std::shared_ptr<GameEngineCollision> Col;
};

