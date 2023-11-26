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
	std::shared_ptr<class GameEngineUIRenderer> item;
	float4 Move = {}; 
};

class Font_InforMation
{
public:
	int FontNumber = 1;
	int Item_Select = 0;
	std::shared_ptr<class GameEngineUIRenderer> Font;
	float4 Move = {};
};

class ItemType
{
public:
	
	int Item_Oreder = 0;
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
	void ItemDebuge(); 

	void Set_Custom_Pos(const float4& _Custom_Pos)
	{
		Custom_Pos = _Custom_Pos;
	}
	static std::vector<std::vector<std::shared_ptr<Inventory_Move>>> Inventroy_informations;
	static std::vector<std::shared_ptr<class Item_InforMation>> Item_Renders;
	static std::vector<std::shared_ptr<class Font_InforMation>> Font_Renders;
	static std::map<int, float4> Item_overlap;
	static std::vector<std::shared_ptr<ItemType>> Item_type;
	static std::vector<int> remove_Order;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	static bool start;
	static bool Inventory_Start;
	static bool Item_Move;
	static bool check;
	static bool dasd;

	static bool Item_Renders_Death_Check;




	

	static float Plus_Pos_X;
	static float Plus_Pos_Y;
	

	static int Inventory_pos_X;
	static int Inventory_pos_Y;

	static int Item_pos_X;
	static int Item_pos_Y;

	static int Number;
	static int Item_Renders_Order;

	static int Item_Check;


	static int Font_Check;
	static int FontNumber;
	static int FontNumber_02;
	static int FontNumber_03;
	static int FontNumber_04;
	static int FontNumber_05;
	static int Item_Plus_X;
	static int Item_Plus_Y;
	static int Item_Type_Order;
	static int Order;
	static int Transform_2_1;

	static float4 Custom_Pos;
	

	// 아이템 타입 저장 


	// 인벤토리 구현 
	
	static std::vector<std::shared_ptr<Inventory_Move>> Inventroy_information;


	// 아이템 정렬 


	// 아이템 이미지 저장 


	

	// 인벤토리 이미지들 
	static std::shared_ptr<class GameEngineUIRenderer> Inventroy_Screen;
	static std::shared_ptr<class GameEngineUIRenderer> Inventroy_Select;


	// 아이템 UI 이미지
	//std::shared_ptr<class GameEngineUIRenderer> item;

	

	static std::shared_ptr<GameEngineCollision> Col;

	// 폰트 이미지 
	//std::shared_ptr<class GameEngineUIRenderer> Font;

	// 폰트 이미지 저장 
	
	
	

	std::shared_ptr<class GameEngineUIRenderer> Shop_UI_01;
	std::shared_ptr<class GameEngineUIRenderer> Shop_UI_02;
	std::shared_ptr<class GameEngineUIRenderer> Shop_UI_03;
	std::shared_ptr<class GameEngineUIRenderer> Shop_UI_04;
//	int FontNumber_05 = 1;
};
