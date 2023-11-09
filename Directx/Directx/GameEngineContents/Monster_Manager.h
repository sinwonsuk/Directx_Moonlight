#pragma once
#include <GameEngineCore/GameEngineLevel.h>

class Monster_Manager
{
public:
	// constrcuter destructer
	Monster_Manager();
	~Monster_Manager();

	Monster_Manager(const Monster_Manager& _Other) = delete;
	Monster_Manager(Monster_Manager&& _Other) noexcept = delete;
	Monster_Manager& operator=(const Monster_Manager& _Other) = delete;
	Monster_Manager& operator=(Monster_Manager&& _Other) noexcept = delete;


	float4 Monster_Move(float _Delta, float4 _GetWorldTransform, std::string_view _Name, float4 _distance_fixation);
	static int Map_Check;
	bool ObjectCollision(float _Delta, float4 _GetWorldTransform, std::string_view _Name, float4 _distance_fixation);

	GameEngineColor GetColor(float4 _Pos, GameEngineColor _DefaultColor = { 255, 255, 255, 255 }, std::string_view _Name = {});
	void Set_MapName(std::string_view _Name)
	{
		MapName = _Name; 
	}
	void Set_Dir(const float4& _Dir)
	{
		Dir = _Dir;
	}
	void MonsterDeath(std::shared_ptr<GameEngineActor> _Object);
	void Monster_Collsision(float4 _Delta);
	void Monster_Damage(std::shared_ptr<GameEngineSpriteRenderer> _Object, float _Delta);

protected:
	float PathTime = 0.0f;
	//std::shared_ptr<class GameEngineCollision> Monster;
	float4 thisPos = {};
	float4 Brick_Size = 0.0f;
	std::string_view MapName = "Tutorial_Map_Pixel.png";
	std::list<float4> PathPos;
	int test = 0;
	float4 Dir = {};
	bool ColorCheck = false;
	float Number = 1.0f;
	int UICheck = 0;
	float Hp_Bar_reduce = 0.0f;
	float Color_Time = 0.0f;
	float4 Manager_Speed = {};
	float4 distance_fixation = {};
	bool MoveCheck = false;
	std::shared_ptr<GameEngineCollision> Mini_Col;
	std::shared_ptr<GameEngineCollision> Monster_Weapon;
private:
	bool Door_Collison_Check = false;


};