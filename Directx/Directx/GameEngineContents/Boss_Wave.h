class Boss_Wave : public GameEngineActor
{
public:
	Boss_Wave();
	~Boss_Wave();

	// delete Function
	Boss_Wave(const Boss_Wave& _Other) = delete;
	Boss_Wave(Boss_Wave&& _Other) noexcept = delete;
	Boss_Wave& operator=(const Boss_Wave& _Other) = delete;
	Boss_Wave& operator=(Boss_Wave&& _Other) noexcept = delete;

	
	void Set_BossPos(const float4& _Pos)
	{
		BossPos = _Pos;
	}
	
	GameEngineRandom Random;



protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	EventParameter Event;
	std::shared_ptr<class GameEngineSpriteRenderer> Wave;
	std::shared_ptr<GameEngineCollision> Col;
	
	bool Check = false;
	float4 Pos = {};
	
	float4 BossPos = {};
	float Speed = 500.0f;
	float Time = 0.0f;
};