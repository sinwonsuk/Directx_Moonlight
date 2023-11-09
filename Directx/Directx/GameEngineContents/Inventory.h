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



// Ό³Έν :
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
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	bool Inventory_Start = false;
	float Plus_Pos_X = -395.0f;
	float Plus_Pos_Y = 163.0f;

	int Inventory_pos_X = 0;
	int Inventory_pos_Y = 0;

	int Item_pos_X = 0;
	int Item_pos_Y = 0;

	std::shared_ptr<Item_InforMation> InforMation = std::make_shared<Item_InforMation>();

	bool check = false;
	std::vector<int> Item_type;
	std::vector<std::vector<std::shared_ptr<Inventory_Move>>> Inventroy_informations;
	std::vector<std::shared_ptr<Inventory_Move>> Inventroy_information; 


	std::vector<std::shared_ptr<class GameEngineUIRenderer>> Item_Renders;

	int Item_Check = 0;
	int Item_Sort = 0;

	std::shared_ptr<class GameEngineUIRenderer> Inventroy_Screen;
	std::shared_ptr<class GameEngineUIRenderer> Inventroy_Select;

	std::shared_ptr<GameEngineCollision> Col;
	


	std::shared_ptr<class GameEngineUIRenderer> item;
	
};
