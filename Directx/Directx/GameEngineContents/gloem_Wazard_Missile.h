#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class golem_Wazard_missile_State
{
	Missile,
	Finish,
};

enum class Dir
{
	Left,
	Right,
	Up,
	Down,
};

class gloem_Wazard_Missile : public GameEngineActor
{
public:
	// constrcuter destructer


	gloem_Wazard_Missile();
	~gloem_Wazard_Missile();

	// delete Function
	gloem_Wazard_Missile(const gloem_Wazard_Missile& _Other) = delete;
	gloem_Wazard_Missile(gloem_Wazard_Missile&& _Other) noexcept = delete;
	gloem_Wazard_Missile& operator=(const gloem_Wazard_Missile& _Other) = delete;
	gloem_Wazard_Missile& operator=(gloem_Wazard_Missile&& _Other) noexcept = delete;

	//void TestEvent(GameEngineRenderer* _Renderer);




	void ChangeState(golem_Wazard_missile_State _State);
	void UpdateState(float _Time);
	void AttackUpdate(float _Time);
	void FinishUpdate(float _Time);
	void AnimationCheck(const std::string_view& _AnimationName);


	golem_Wazard_missile_State GetPlayerStateValue()
	{
		return StateValue;
	}

	//void Move(float _Delta);


	float4 AttackDir = { 0.0f, 0.0f, 0.0f, 1.0f };
	GameEngineColor GetColor(float4 _Pos, GameEngineColor _DefaultColor = { 255, 255, 255, 255 }, std::string_view _Name = {});
protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	bool AttackCheck = false;
	float StartSpeed = 20.0f;
	float Speed = 400.0f;
	float Roll_Speed = 400.0f;

	golem_Wazard_missile_State StateValue = golem_Wazard_missile_State::Missile;
	
	std::shared_ptr<class GameEngineSpriteRenderer> Missile;
	std::shared_ptr<GameEngineCollision> Col;
};

