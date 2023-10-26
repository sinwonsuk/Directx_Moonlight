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
	GameEngineColor GetColor(float4 _Pos, GameEngineColor _DefaultColor = { 255, 255, 255, 255 }, std::string_view _Name = {});
	bool ObjectCollision(std::string_view _Name, float4 _Transform);

	int Random_A = 0;
	int Random_B = 0;
	int Random_C = 0;
	std::string Name = {};
protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	bool test = false;
	float4 Monster_Pos = {};
	float Map_Number = 0.0f;
	int Random_number = 0;
	int Random_Monster = 0;
	GameEngineRandom Random;
	GameEngineRandom Random2;
	GameEngineRandom Random3;

};