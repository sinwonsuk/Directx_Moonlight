#pragma once
#pragma once
#include <GameEngineCore/GameEngineActor.h>
enum class RandomDir
{
	Left,
	Right,
	Top,
	Bottom, 
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




	std::vector<std::vector<Room_State>> Rooms;

	std::vector<Room_State> Room_state;
protected:
	void Start() override;
	void Update(float _Delta) override;

private:

	std::shared_ptr<class Dungeon_Map_01> Map;

	int Number = 0;
	float Map_Number = 0.0f;

	int Random_Map_Arr[10] = {}; 
	int Map_Order = 0;
	int RandomCheck = 0; 
	float4 int_Check[30] = {};

	bool check = false;

};
