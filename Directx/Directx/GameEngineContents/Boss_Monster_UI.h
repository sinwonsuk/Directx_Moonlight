#pragma once
#include <GameEngineCore/GameEngineActor.h>



class Boss_Monster_UI : public GameEngineActor
{
public:

	Boss_Monster_UI();
	~Boss_Monster_UI();

	// delete Function
	Boss_Monster_UI(const Boss_Monster_UI& _Other) = delete;
	Boss_Monster_UI(Boss_Monster_UI&& _Other) noexcept = delete;
	Boss_Monster_UI& operator=(const Boss_Monster_UI& _Other) = delete;
	Boss_Monster_UI& operator=(Boss_Monster_UI&& _Other) noexcept = delete;

	//void TestEvent(GameEngineRenderer* _Renderer);


	//void Move(float _Delta);

	std::shared_ptr<class GameEngineSpriteRenderer> Monster_HpBar;
protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	float Number = 0; 
	std::shared_ptr<class GameEngineSpriteRenderer> Monster_BaseBar;
	bool AlphaCheck = false;

	


};