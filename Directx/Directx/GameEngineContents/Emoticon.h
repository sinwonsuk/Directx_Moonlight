#pragma once


enum class Emoticon_State
{
	Base,
	Stop,
	Smile,

};

class Emoticon : public GameEngineActor
{
public:
	// constrcuter destructer

	Emoticon();
	~Emoticon();

	// delete Function
	Emoticon(const Emoticon& _Other) = delete;
	Emoticon(Emoticon&& _Other) noexcept = delete;
	Emoticon& operator=(const Emoticon& _Other) = delete;
	Emoticon& operator=(Emoticon&& _Other) noexcept = delete;

	void ChangeState(Emoticon_State _State);

	void UpdateState(float _Time);
	
	
	void BaseUpdate(float _Time);
	void StopUpdate(float _Time);
	void SmileUpdate(float _Time);



protected:
	void Start() override;
	void Update(float _Delta) override;

private:

	float Time = 0.0f;

	int Check = 0;

	GameEngineSoundPlayer Sound;

	

	Emoticon_State StateValue = Emoticon_State::Stop;

	std::shared_ptr<class GameEngineSpriteRenderer> Base;
	std::shared_ptr<class GameEngineSpriteRenderer> Stop;
	std::shared_ptr<class GameEngineSpriteRenderer> Smile;
};

