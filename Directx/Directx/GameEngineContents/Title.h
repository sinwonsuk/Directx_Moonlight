#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Title : public GameEngineActor
{
public:
	// constrcuter destructer
	Title();
	~Title();

	// delete Function
	Title(const Title& _Other) = delete;
	Title(Title&& _Other) noexcept = delete;
	Title& operator=(const Title& _Other) = delete;
	Title& operator=(Title&& _Other) noexcept = delete;

	

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> Title_BG_Back;
	std::shared_ptr<class GameEngineSpriteRenderer> Title_BG_Front;
	std::shared_ptr<class GameEngineSpriteRenderer> Title_Select_01;
	std::shared_ptr<class GameEngineSpriteRenderer> Title_Select_02;
	std::shared_ptr<class GameEngineSpriteRenderer> Title_Select_Effect_Left;
	std::shared_ptr<class GameEngineSpriteRenderer> Title_Select_Effect_Right;
	std::shared_ptr<class GameEngineSpriteRenderer> Title_Logo;


};
