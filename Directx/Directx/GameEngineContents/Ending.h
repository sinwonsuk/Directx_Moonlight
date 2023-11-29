#pragma once
#include <GameEngineCore/GameEngineActor.h>
enum class End_State
{
	one,
	two,
	three,
	four,
	five,

};

// Ό³Έν :
class Ending : public GameEngineActor
{
public:
	// constrcuter destructer
	Ending();
	~Ending();

	// delete Function
	Ending(const Ending& _Other) = delete;
	Ending(Ending&& _Other) noexcept = delete;
	Ending& operator=(const Ending& _Other) = delete;
	Ending& operator=(Ending&& _Other) noexcept = delete;


	std::shared_ptr<class Black_Out> black_Out;
protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	End_State state = End_State::one;
	std::shared_ptr<class GameEngineSpriteRenderer> End;
	float Time = 0;
	GameEngineSoundPlayer Sound;
	bool Black_Check = false;

};
