#pragma once

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


	void MonsterCollision(float _Delta, std::string_view _Name);
	float4 Monster_Move(float _Delta, float4 _GetWorldTransform, std::string_view _Name, float4 _distance_fixation);
	static int Map_Check;
	
	void Set_MapName(std::string_view _Name)
	{
		MapName = _Name; 
	}
	void Set_Dir(const float4& _Dir)
	{
		Dir = _Dir;
	}

protected:
	//std::shared_ptr<class GameEngineCollision> Monster;
	float4 thisPos = {};
	float4 Brick_Size = 0.0f;
	std::string_view MapName = {}; 
	std::list<float4> PathPos;
	int test = 0;
	float4 Dir = {};
	float4 Manager_Speed = {};
	float4 distance_fixation = {};
private:
	bool Door_Collison_Check = false;


};