#pragma once
#include <GameEngineCore/GameEngineActor.h>

class Black_Out : public GameEngineActor
{
public:
	// constrcuter destructer
	Black_Out();
	~Black_Out();

	// delete Function
	Black_Out(const Black_Out& _Other) = delete;
	Black_Out(Black_Out&& _Other) noexcept = delete;
	Black_Out& operator=(const Black_Out& _Other) = delete;
	Black_Out& operator=(Black_Out&& _Other) noexcept = delete;

	bool GetCheck()
	{
		return Check; 
	}


protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	bool Check = false;
	float Number = -1.0f;

	std::shared_ptr<class GameEngineUIRenderer> black;

};
