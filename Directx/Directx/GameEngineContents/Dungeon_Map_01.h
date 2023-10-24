#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Map_Manager.h"

class Dungeon_Map_01 : public GameEngineActor, public Map_Manager
{
public:
	// constrcuter destructer
	Dungeon_Map_01();
	~Dungeon_Map_01();

	// delete Function
	Dungeon_Map_01(const Dungeon_Map_01& _Other) = delete;
	Dungeon_Map_01(Dungeon_Map_01&& _Other) noexcept = delete;
	Dungeon_Map_01& operator=(const Dungeon_Map_01& _Other) = delete;
	Dungeon_Map_01& operator=(Dungeon_Map_01&& _Other) noexcept = delete;
	void SetArr(const float4& _Arr)
	{
		Arr = _Arr; 
	}
	float4 GetArr()
	{
		return Arr;
	}

	std::shared_ptr<class GameEngineSpriteRenderer> Map_floor;
	std::string_view Pixel_Name = {};
    float4 Pixel_Fasten;
	float Map_Number = 0.0f;
protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	bool Check = false;
	
	float4 Arr = {}; 
	
	std::shared_ptr<class GameEngineSpriteRenderer> BackGround;
	
	std::shared_ptr<class GameEngineSpriteRenderer> LeftDoor;
	std::shared_ptr<class GameEngineSpriteRenderer> RightDoor;
	std::shared_ptr<class GameEngineSpriteRenderer> UpDoor;
	std::shared_ptr<class GameEngineSpriteRenderer> DownDoor;


	std::shared_ptr<GameEngineCollision> Right_Collision_Door;
	std::shared_ptr<GameEngineCollision> Left_Collision_Door;
	std::shared_ptr<GameEngineCollision> Top_Collision_Door;
	std::shared_ptr<GameEngineCollision> Bottom_Collision_Door;
};
