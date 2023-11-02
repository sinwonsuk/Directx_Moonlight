#pragma once
#include "Monster_Manager.h"
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

class MonsterTest : public GameEngineActor , public Monster_Manager
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
	
	float PathTime = 0.0f;

	
};
