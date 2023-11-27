#pragma once




class Shop_UI : public GameEngineActor
{
public:

public:
	static Shop_UI* this_Shop_UI;
	// constrcuter destructer
	Shop_UI();
	~Shop_UI();

	// delete Function
	Shop_UI(const Shop_UI& _Other) = delete;
	Shop_UI(Shop_UI&& _Other) noexcept = delete;
	Shop_UI& operator=(const Shop_UI& _Other) = delete;
	Shop_UI& operator=(Shop_UI&& _Other) noexcept = delete;



	
	std::shared_ptr<class Shop_Item> Shop_Item_01;
	std::shared_ptr<class Shop_Item> Shop_Item_02;
	std::shared_ptr<class Shop_Item> Shop_Item_03;
	std::shared_ptr<class Shop_Item> Shop_Item_04;

	
	std::vector<std::shared_ptr<class Item_InforMation>> Item_Renders;
	std::vector<std::shared_ptr<class Font_InforMation>> Font_Renders;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	bool Inventory_Start = false;
	std::shared_ptr<class GameEngineUIRenderer> Inventroy_Screen;
	std::shared_ptr<class GameEngineUIRenderer> Inventroy_Select;
	std::shared_ptr<class GameEngineUIRenderer> Inventroy_Select_02;

	std::shared_ptr<class GameEngineUIRenderer> item;
	std::shared_ptr<class GameEngineUIRenderer> Font;

	std::shared_ptr<class GameEngineUIRenderer> Money_Font_bout_01;
	std::shared_ptr<class GameEngineUIRenderer> Money_Font_bout_02;
	std::shared_ptr<class GameEngineUIRenderer> Money_Font_bout_03;
	std::shared_ptr<class GameEngineUIRenderer> Money_Font_bout_04;

	std::shared_ptr<class GameEngineUIRenderer> Money_Font_01;
	std::shared_ptr<class GameEngineUIRenderer> Money_Font_02;
	std::shared_ptr<class GameEngineUIRenderer> Money_Font_03;
	std::shared_ptr<class GameEngineUIRenderer> Money_Font_04;

	
	std::shared_ptr<class GameEngineUIRenderer> Font_Price_01;
	std::shared_ptr<class GameEngineUIRenderer> Font_Price_02;
	std::shared_ptr<class GameEngineUIRenderer> Font_Price_03;
	std::shared_ptr<class GameEngineUIRenderer> Font_Price_04;

	std::shared_ptr<class GameEngineUIRenderer> Font_Price_total_01;
	std::shared_ptr<class GameEngineUIRenderer> Font_Price_total_02;
	std::shared_ptr<class GameEngineUIRenderer> Font_Price_total_03;
	std::shared_ptr<class GameEngineUIRenderer> Font_Price_total_04;


	std::shared_ptr<class GameEngineUIRenderer> Shop_UI_01;
	std::shared_ptr<class GameEngineUIRenderer> Shop_UI_02;
	std::shared_ptr<class GameEngineUIRenderer> Shop_UI_03;
	std::shared_ptr<class GameEngineUIRenderer> Shop_UI_04;

	int Inventory_pos_X = 0;

	int Inventory_pos_Y = 0;

	int Transform_2_1 = 0;
	int Item_Renders_Order = 0;
	std::vector<std::vector<std::shared_ptr<class Inventory_Move>>> Inventroy_informations;
	std::vector<std::shared_ptr<class Inventory_Move>> Inventroy_information;
	std::vector<std::shared_ptr<class Item_InforMation>> Shop_Item_Renders;
	std::vector<std::shared_ptr<class Font_InforMation>> Shop_Font_Renders;

	std::shared_ptr<GameEngineCollision> UI_Col;

	float Plus_Pos_X = -395.0f;
	float Plus_Pos_Y = 163.0f;
	int Shop_Item_Renders_Order = 0;
	bool Item_Move = false;
	bool check = false;
	bool Death_Check = false;
	bool ADADADA = false;
	int test = 0;
	int test_02 = 0;
	int test_03 = 0;
	int test_04 = 0;
	int test_05 = 0;
	int test_06 = 0;
	bool Item_Renders_Death_Check = false;
	//	int FontNumber_05 = 1;

	bool Inven_sync = false;

	bool Select_Stop = false;

	int Money_01 = 0; 
	int Money_02 = 0;
	int Money_03 = 0;
	int Money_04 = 0;

	int Money_01_bout = 0;

};
