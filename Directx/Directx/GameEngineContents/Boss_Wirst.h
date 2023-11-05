#pragma once
enum class Boss_Wirst_State
{
	Start,
	Rotation,
	End,
};

class Boss_Wirst : public GameEngineActor
{
public:
	Boss_Wirst();
	~Boss_Wirst();

	// delete Function
	Boss_Wirst(const Boss_Wirst& _Other) = delete;
	Boss_Wirst(Boss_Wirst&& _Other) noexcept = delete;
	Boss_Wirst& operator=(const Boss_Wirst& _Other) = delete;
	Boss_Wirst& operator=(Boss_Wirst&& _Other) noexcept = delete;

	
	void Set_BossPos(const float4& _Pos)
	{
		BossPos = _Pos;
	}

	void ChangeState(Boss_Wirst_State _State);
	void UpdateState(float _Time);

	void Rotation_Update(float _Time);
	void Start_Update(float _Time);
	void End_Update(float _Time);

	bool GetFinsih()
	{
		return finish;
	}

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	Boss_Wirst_State StateValue = Boss_Wirst_State::Start;

	std::shared_ptr<class GameEngineSpriteRenderer> Wirst;
	std::shared_ptr<class GameEngineSpriteRenderer> Arm;
	float Time = 0.0f;
	float Rotation_Speed = 150.0f;
	float Speed = 1500.0f;
	float4 Wirst_Rotation = {}; 
	float4 BossPos = {};
	float Degree = 0;
	int Rotation_Number = 0;
	bool Check = false;
	
	bool finish = false;
};
