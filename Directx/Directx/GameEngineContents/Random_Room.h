#pragma once
#pragma once
#include <GameEngineCore/GameEngineActor.h>

#include "Dungeon_Map_01.h"
#include "Dungeon_Map_02.h"
#include "Dungeon_Map_03.h"
#include "Dungeon_Map_04.h"
#include "Dungeon_Map_05.h"
#include "Dungeon_Map_06.h"
#include "Dungeon_Map_07.h"
#include "Dungeon_Map_08.h"
#include "Dungeon_Map_09.h"
#include "Dungeon_Map_10.h"
enum class RandomDir
{
	Left,
	Right,
	Top,
	Bottom, 
};

enum class RandomMap
{
	Map,
	Map_01,
	Map_02,
	Map_03,
	Map_04,
	Map_05,
	Map_06,
	Map_07,
	Map_08,
	Map_09,
	Map_10
};

class Room_State
{
public:
	bool RoomCheck = false;
	bool Null_Check = false;


	Room_State* Arr[4] = {}; 
	float4 Pos = {640,-360,0.0f,1.0f};
};


class Random_Room : public GameEngineActor
{
public:
	// constrcuter destructer
	Random_Room();
	~Random_Room();

	// delete Function
	Random_Room(const Random_Room& _Other) = delete;
	Random_Room(Random_Room&& _Other) noexcept = delete;
	Random_Room& operator=(const Random_Room& _Other) = delete;
	Random_Room& operator=(Random_Room&& _Other) noexcept = delete;
	RandomDir Dir;

	//Random_Room* Arr[4] = {}; 

	RandomMap Map; 
	std::vector<std::vector<Room_State>> Rooms;

	std::vector<Room_State> Room_state;
protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class Dungeon_Map_02> Map_02;
	std::shared_ptr<class Dungeon_Map_03> Map_03;
	std::shared_ptr<class Dungeon_Map_04> Map_04;
	std::shared_ptr<class Dungeon_Map_05> Map_05;
	std::shared_ptr<class Dungeon_Map_06> Map_06;
	std::shared_ptr<class Dungeon_Map_07> Map_07;
	std::shared_ptr<class Dungeon_Map_08> Map_08;
	std::shared_ptr<class Dungeon_Map_09> Map_09;
	std::shared_ptr<class Dungeon_Map_10> Map_10;
	std::shared_ptr<class Dungeon_Map_01> Map_01;
	std::shared_ptr<class Dungeon_Map_01> base_Map;

	float Map_Number = 0.0f;
	
	int Random_Map_Arr[10] = {0}; 
	int Map_Order = 0;
	int RandomCheck = 0; 
	float4 int_Check[30] = {0};

	bool check = false;

};
