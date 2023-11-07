#pragma once

class Boss_Rock : public GameEngineActor
{
public:
	Boss_Rock();
	~Boss_Rock();

	// delete Function
	Boss_Rock(const Boss_Rock& _Other) = delete;
	Boss_Rock(Boss_Rock&& _Other) noexcept = delete;
	Boss_Rock& operator=(const Boss_Rock& _Other) = delete;
	Boss_Rock& operator=(Boss_Rock&& _Other) noexcept = delete;

	std::shared_ptr<class GameEngineSpriteRenderer> Rock;
	void Set_BossPos(const float4& _Pos)
	{
		BossPos = _Pos;
	}
	void Set_Seed(const int _Pos)
	{
		Seed = _Pos;
	}

	GameEngineRandom Random;



protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	EventParameter Event;
	float Time = 0.0f;
	float Time2 = 0.0f;
	bool Check = false;
	bool RockCheck = false;
	std::shared_ptr<GameEngineCollision> Col;
	std::shared_ptr<GameEngineCollision> Rock_Col;
	int Seed = 0; 
	float4 BossPos = {};
	int Particle = 0;
	float Particle_X = 0; 
	float Particle_Y = 10;
	float Speed = 200;
	float tet = 0;
	float4 Pos = {}; 
};
