#pragma once
#include <GameEngineCore/GameEngineActor.h>
enum class Fade
{
	FideIn,
	FadeOut, 
};

class Black : public GameEngineActor
{
public:
	// constrcuter destructer
	Black();
	~Black();

	// delete Function
	Black(const Black& _Other) = delete;
	Black(Black&& _Other) noexcept = delete;
	Black& operator=(const Black& _Other) = delete;
	Black& operator=(Black&& _Other) noexcept = delete;




protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	Fade fade = Fade::FideIn;
	float Number = 1.0f; 

	std::shared_ptr<class GameEngineUIRenderer> black;

};
