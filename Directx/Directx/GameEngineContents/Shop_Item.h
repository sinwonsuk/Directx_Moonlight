#pragma once

enum class Shop_Items
{
	BrokenSword,
	Ancient_Pot,
	FireJelly,
	crystal,
	Red_crystal,
};

class Shop_Item : public GameEngineActor
{
public:
	// constrcuter destructer
	Shop_Item();
	~Shop_Item();

	// delete Function
	Shop_Item(const Shop_Item& _Other) = delete;
	Shop_Item(Shop_Item&& _Other) noexcept = delete;
	Shop_Item& operator=(const Shop_Item& _Other) = delete;
	Shop_Item& operator=(Shop_Item&& _Other) noexcept = delete;

	void Set_item_Select(Shop_Items _item_Select)
	{
		item_Select = _item_Select;
	}

	void Set_Money(int _Money)
	{
		Money = _Money;
	}
	void Set_Prev_Pos(const float4& _Prev_Pos)
	{
		Prev_Pos = _Prev_Pos;
	}
	
	float4 Dir = {};
protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> item;
	std::shared_ptr<class GameEngineSpriteRenderer> item_border;
	std::shared_ptr<class GameEngineSpriteRenderer> Font;
	std::shared_ptr<GameEngineCollision> Col;
	EventParameter Event;
	EventParameter Event_Item;
	Shop_Items item_Select = Shop_Items::BrokenSword;

	float4 Prev_Pos = {};
	float Speed = 10.0f;
	bool gravity = true;
	
	int Money = 0;

	bool Item_Check = false;
	
	//bool 
};
