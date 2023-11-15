#pragma once




class Shop_UI : public GameEngineActor
{
public:

public:
	
	// constrcuter destructer
	Shop_UI();
	~Shop_UI();

	// delete Function
	Shop_UI(const Shop_UI& _Other) = delete;
	Shop_UI(Shop_UI&& _Other) noexcept = delete;
	Shop_UI& operator=(const Shop_UI& _Other) = delete;
	Shop_UI& operator=(Shop_UI&& _Other) noexcept = delete;



	


	


protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	bool Inventory_Start = false;
	std::shared_ptr<class GameEngineUIRenderer> Inventroy_Screen;
	std::shared_ptr<class GameEngineUIRenderer> Inventroy_Select;

	std::shared_ptr<class GameEngineUIRenderer> item;
	std::shared_ptr<class GameEngineUIRenderer> Font;


	std::vector<std::shared_ptr<class Item_InforMation>> Item_Renders;
	std::vector<std::shared_ptr<class Font_InforMation>> Font_Renders;

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
	float Plus_Pos_X = -395.0f;
	float Plus_Pos_Y = 163.0f;
	int Shop_Item_Renders_Order = 0;
	bool Item_Move = false;
	bool check = false;
	bool Death_Check = false;
	bool ADADADA = false;
	int test = 0;
	bool Item_Renders_Death_Check = false;
	//	int FontNumber_05 = 1;
};
