#pragma once
#include <GameEngineCore/GameEngineActor.h>
enum class Shadow_Size
{
	Big,
	Small,

};



class Arm_Shadow : public GameEngineActor
{
public:
	// constrcuter destructer


	Arm_Shadow();
	~Arm_Shadow();

	// delete Function
	Arm_Shadow(const Arm_Shadow& _Other) = delete;
	Arm_Shadow(Arm_Shadow&& _Other) noexcept = delete;
	Arm_Shadow& operator=(const Arm_Shadow& _Other) = delete;
	Arm_Shadow& operator=(Arm_Shadow&& _Other) noexcept = delete;
	Shadow_Size size = Shadow_Size::Big; 
	float ArmScale = 0.0f;

	

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	float Prev_Pos = false;
	bool CollisionCheck = false;
	



	

	std::shared_ptr<class GameEngineSpriteRenderer> Arm_shadow;


};
