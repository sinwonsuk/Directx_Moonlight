#pragma once

class Boss_Rock_Shadow : public GameEngineActor
{
public:
	Boss_Rock_Shadow();
	~Boss_Rock_Shadow();

	// delete Function
	Boss_Rock_Shadow(const Boss_Rock_Shadow& _Other) = delete;
	Boss_Rock_Shadow(Boss_Rock_Shadow&& _Other) noexcept = delete;
	Boss_Rock_Shadow& operator=(const Boss_Rock_Shadow& _Other) = delete;
	Boss_Rock_Shadow& operator=(Boss_Rock_Shadow&& _Other) noexcept = delete;

	std::shared_ptr<class GameEngineSpriteRenderer> Shadow;
protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	int Number = 0;




};
