#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class Effect_State
{
  Monster,
  Boss
};


class Spear_Effect : public GameEngineActor
{
public:
	
	Spear_Effect();
	~Spear_Effect();

	// delete Function
	Spear_Effect(const Spear_Effect& _Other) = delete;
	Spear_Effect(Spear_Effect&& _Other) noexcept = delete;
	Spear_Effect& operator=(const Spear_Effect& _Other) = delete;
	Spear_Effect& operator=(Spear_Effect&& _Other) noexcept = delete;

	void Set_state(const Effect_State& _state)
	{
		state = _state; 
	}

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	Effect_State state = Effect_State::Monster; 
	bool CollisionCheck = false;


	
	std::shared_ptr<class GameEngineSpriteRenderer> Efffet;


};
