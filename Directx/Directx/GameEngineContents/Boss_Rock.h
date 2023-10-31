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
protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	int Number = 0; 

	


};
