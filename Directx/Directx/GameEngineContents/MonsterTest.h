#pragma once

class MonsterTest : public GameEngineActor
{
public:
	MonsterTest();
	~MonsterTest();

	// delete Function
	MonsterTest(const MonsterTest& _Other) = delete;
	MonsterTest(MonsterTest&& _Other) noexcept = delete;
	MonsterTest& operator=(const MonsterTest& _Other) = delete;
	MonsterTest& operator=(MonsterTest&& _Other) noexcept = delete;


protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	

	std::shared_ptr<class GameEngineSpriteRenderer> Monster;


};
