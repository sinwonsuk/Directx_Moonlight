#pragma once
#include <GameEngineCore/GameEngineActor.h>



class Player_UI : public GameEngineActor
{
public:

	Player_UI();
	~Player_UI();

	// delete Function
	Player_UI(const Player_UI& _Other) = delete;
	Player_UI(Player_UI&& _Other) noexcept = delete;
	Player_UI& operator=(const Player_UI& _Other) = delete;
	Player_UI& operator=(Player_UI&& _Other) noexcept = delete;

	//void TestEvent(GameEngineRenderer* _Renderer);


	//void Move(float _Delta);

	std::shared_ptr<class GameEngineUIRenderer> Hp_Bar;
protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	bool CollisionCheck = false;
	float StartSpeed = 20.0f;
	float Speed = 300.0f;
	float Time = 0.0f;
	//BabySlime_State StateValue = BabySlime_State::Walk;
	float4 GrivityForce = { 0.0f, 0.0f, 0.0f, 1.0f };
	
	std::shared_ptr<class GameEngineUIRenderer> Button_J;
	std::shared_ptr<class GameEngineUIRenderer> Button_E;
	std::shared_ptr<class GameEngineUIRenderer> Button_I;
	std::shared_ptr<class GameEngineUIRenderer> Button_K;
	std::shared_ptr<class GameEngineUIRenderer> Button_Z;
	std::shared_ptr<class GameEngineUIRenderer> Button_Space;
	std::shared_ptr<class GameEngineUIRenderer> HealthBar_Base;
	std::shared_ptr<class GameEngineUIRenderer> Bag_Circle;
	std::shared_ptr<class GameEngineUIRenderer> Weapon_Circle;
	std::shared_ptr<class GameEngineUIRenderer> Weapon_Spear;

	std::shared_ptr<class GameEngineUIRenderer> Mini_Will;
	std::shared_ptr<class GameEngineUIRenderer> Heart;
	
	std::shared_ptr<class GameEngineUIRenderer> Bag;
	std::shared_ptr<class GameEngineUIRenderer> Pocket;


};