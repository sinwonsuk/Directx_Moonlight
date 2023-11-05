#pragma once

class Rock_Particle : public GameEngineActor
{
public:
	Rock_Particle();
	~Rock_Particle();

	// delete Function
	Rock_Particle(const Rock_Particle& _Other) = delete;
	Rock_Particle(Rock_Particle&& _Other) noexcept = delete;
	Rock_Particle& operator=(const Rock_Particle& _Other) = delete;
	Rock_Particle& operator=(Rock_Particle&& _Other) noexcept = delete;

	std::shared_ptr<class GameEngineSpriteRenderer> Rock;
	void Set_Rock_Pos(const float4& _Pos)
	{
		BossPos = _Pos;
	}
	GameEngineRandom Random;
	GameEngineRandom Random_Hight;
	GameEngineRandom Random_X;
	GameEngineRandom Random_Y;
protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	float Time = 0.0f;

	bool RockCheck = false;
	bool gravity = true;
	float Number = 1;
	float4 BossPos = {};

	int Pos_X = 0;
	float Pos_Y = 0;
	float Height = 0;
	bool RotationCheck = false;
	float4 asd = {};
};
