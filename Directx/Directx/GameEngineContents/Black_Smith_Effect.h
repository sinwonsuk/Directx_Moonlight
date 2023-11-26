#pragma once
#include <GameEngineCore/GameEngineActor.h>

class Black_Smith_Effect : public GameEngineActor
{
public:
	// constrcuter destructer
	Black_Smith_Effect();
	~Black_Smith_Effect();

	// delete Function
	Black_Smith_Effect(const Black_Smith_Effect& _Other) = delete;
	Black_Smith_Effect(Black_Smith_Effect&& _Other) noexcept = delete;
	Black_Smith_Effect& operator=(const Black_Smith_Effect& _Other) = delete;
	Black_Smith_Effect& operator=(Black_Smith_Effect&& _Other) noexcept = delete;

	void Set_Prev_Pos(const float4& _Prev_Pos)
	{
		Prev_Pos = _Prev_Pos;
	}
	void Set_Sprite(int _SetSprite)
	{
		SetSprite = _SetSprite;
	}

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	bool Animation_Finish = false;
	int Check = 0;
	int SetSprite = 0; 
	float4 Speed = 50.0f;
	float Number = 1.0f;
	bool gravity = false;
	float4 Prev_Pos = {};
	std::shared_ptr<class GameEngineUIRenderer> Effect;
	std::shared_ptr<class GameEngineUIRenderer> Items;
};
