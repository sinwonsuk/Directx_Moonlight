#pragma once

#include <GameEngineCore/GameEngineActor.h>

enum class Slime_Potal_State
{
	open, 
	Ing,

};
class Slime_Potal : public GameEngineActor
{
public:
	// constrcuter destructer


	Slime_Potal();
	~Slime_Potal();

	// delete Function
	Slime_Potal(const Slime_Potal& _Other) = delete;
	Slime_Potal(Slime_Potal&& _Other) noexcept = delete;
	Slime_Potal& operator=(const Slime_Potal& _Other) = delete;
	Slime_Potal& operator=(Slime_Potal&& _Other) noexcept = delete;

	//void TestEvent(GameEngineRenderer* _Renderer);


	void ChangeState(Slime_Potal_State _State);
	void UpdateState(float _Time);
	void AnimationCheck(const std::string_view& _AnimationName);
	void OpenUpdate(float _Time);
	void IngUpdate(float _Time); 
	


protected:
	void Start() override;
	void Update(float _Delta) override;

private:


	Slime_Potal_State StateValue = Slime_Potal_State::open;
	float4 GrivityForce = { 0.0f, 0.0f, 0.0f, 1.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> Potal_Open;
	

};
