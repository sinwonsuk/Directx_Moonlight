#pragma once

class Map_Manager
{
public:
	// constrcuter destructer
	Map_Manager();
	~Map_Manager();

	Map_Manager(const Map_Manager& _Other) = delete;
	Map_Manager(Map_Manager&& _Other) noexcept = delete;
	Map_Manager& operator=(const Map_Manager& _Other) = delete;
	Map_Manager& operator=(Map_Manager&& _Other) noexcept = delete;

	GameEngineColor GetColor(float4 _Pos, GameEngineColor _DefaultColor = { 255, 255, 255, 255 }, std::string_view _Name = {});
	Map_Manager* Arr[4] = {};

	void ObjectCollision(float _Delta, std::string_view _Name);
	void DoorCollision(float _Delta, float _MapNumber);
	static int Map_Check;
protected:
	float Map_Number = 0.0f;

private:
	bool Door_Collison_Check = false;


};