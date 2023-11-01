#pragma once
enum class DirCheck
{
	LeftUp,
	RightUp,
	LeftDown,
	RightDown,
	Left,
	Right,
	Up,
	Down, 

};

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

	std::list<float4> PathPos;
	float4 thisPos = {};
	float PathTime = 0.0f;


};
