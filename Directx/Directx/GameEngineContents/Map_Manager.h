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

	void ObjectCollision(float _Delta, std::string_view _Name, float4 _Transform);
	void DoorCollision(float _Delta, float4 _PrevMainCamera);
	float Map_Number = 0.0f;
	static int Map_Check;

	bool Door_Left_Collison_Check = false;
	bool Door_Right_Collison_Check = false;
	bool Door_Top_Collison_Check = false;
	bool Door_Bottom_Collison_Check = false;
	bool test = false;
	bool ReturnCheck = false;

protected:


private:
	
	float A = 0;

};