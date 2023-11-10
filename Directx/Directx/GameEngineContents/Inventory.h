#pragma once
#include <GameEngineCore/GameEngineActor.h>


class Inventory_Move
{
public:
	float4 Move = {395,163};

};
class Item_InforMation
{
public:

	int Item_Select = 0;
	float4 Move = {};

};



// 설명 :
class Inventory : public GameEngineActor
{
public:

public:
	static Inventory* This_Inventory;
	// constrcuter destructer
	Inventory();
	~Inventory();

	// delete Function
	Inventory(const Inventory& _Other) = delete;
	Inventory(Inventory&& _Other) noexcept = delete;
	Inventory& operator=(const Inventory& _Other) = delete;
	Inventory& operator=(Inventory&& _Other) noexcept = delete;

	bool Item_Start = false;
	
	int Item_Sprite_Number = 0;


	void Set_Custom_Pos(const float4& _Custom_Pos)
	{
		Custom_Pos = _Custom_Pos;
	}


protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	bool Inventory_Start = false;

	float Plus_Pos_X = -395.0f;
	float Plus_Pos_Y = 163.0f;
	float4 Custom_Pos = {};

	int Inventory_pos_X = 0;
	int Inventory_pos_Y = 0;

	int Item_pos_X = 0;
	int Item_pos_Y = 0;

	int Number = 0;


	std::shared_ptr<Item_InforMation> InforMation = std::make_shared<Item_InforMation>();

	bool check = false;

	// 아이템 타입 저장 
	std::vector<int> Item_type;

	// 인벤토리 구현 
	std::vector<std::vector<std::shared_ptr<Inventory_Move>>> Inventroy_informations;
	std::vector<std::shared_ptr<Inventory_Move>> Inventroy_information; 


	// 아이템 정렬 
	std::map<int, float4> Item_overlap;

	// 아이템 이미지 저장 
	std::vector<std::shared_ptr<class GameEngineUIRenderer>> Item_Renders;

	int Item_Check = 0;
	int Item_Sort = 0;

	// 인벤토리 이미지들 
	std::shared_ptr<class GameEngineUIRenderer> Inventroy_Screen;
	std::shared_ptr<class GameEngineUIRenderer> Inventroy_Select;

	// 아이템 UI 이미지
	std::shared_ptr<class GameEngineUIRenderer> item;



	std::shared_ptr<GameEngineCollision> Col;

	// 폰트 이미지 
	std::shared_ptr<class GameEngineUIRenderer> Font;

	// 폰트 이미지 저장 
	std::map<int ,std::shared_ptr<class GameEngineUIRenderer>> Font_Renders;

	int FontNumber = 1;
	int FontNumber_02 = 1;
	int FontNumber_03 = 1;
	int FontNumber_04 = 1;
	int FontNumber_05 = 1;
};
