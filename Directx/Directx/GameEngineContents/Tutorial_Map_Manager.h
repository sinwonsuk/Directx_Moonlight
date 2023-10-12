#pragma once

class Tutorial_Map_Manager
{
public:
	// constrcuter destructer
	Tutorial_Map_Manager();
	~Tutorial_Map_Manager();

	Tutorial_Map_Manager(const Tutorial_Map_Manager& _Other) = delete;
	Tutorial_Map_Manager(Tutorial_Map_Manager&& _Other) noexcept = delete;
	Tutorial_Map_Manager& operator=(const Tutorial_Map_Manager& _Other) = delete;
	Tutorial_Map_Manager& operator=(Tutorial_Map_Manager&& _Other) noexcept = delete;

	GameEngineColor GetColor(float4 _Pos, GameEngineColor _DefaultColor = { 255, 255, 255, 255 }, std::string_view _Name = {});

	void ObjectCollision(float _Delta, std::string_view _Name);
	void DoorCollision(float _Delta,float _MapNumber);
	static int Map_Check;
protected:
	float Map_Number = 0.0f;

private:
	bool Door_Collison_Check = false;
	

};

