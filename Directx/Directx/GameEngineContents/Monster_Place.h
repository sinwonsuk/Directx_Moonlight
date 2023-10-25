#pragma once
#include <GameEngineCore/GameEngineActor.h>


class Monster_Place : public GameEngineActor
{
public:
	// constrcuter destructer
	Monster_Place();
	~Monster_Place();

	// delete Function
	Monster_Place(const Monster_Place& _Other) = delete;
	Monster_Place(Monster_Place&& _Other) noexcept = delete;
	Monster_Place& operator=(const Monster_Place& _Other) = delete;
	Monster_Place& operator=(Monster_Place&& _Other) noexcept = delete;

	void Monsters(float4 _Pos); 

	float4 sd = {};
protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	bool test = false;
	int Random_A = 0;
	float Map_Number = 0.0f;
	int Random_number = 0;
	int Random_Monster = 0;
};