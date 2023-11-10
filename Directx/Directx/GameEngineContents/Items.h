#pragma once
#include <GameEngineCore/GameEngineActor.h>
enum class Item
{
	BrokenSword,
	Ancient_Pot,
	FireJelly,
	crystal,
	Red_crystal,
};
// Ό³Έν :
class Items : public GameEngineActor
{
public:
	// constrcuter destructer
	Items();
	~Items();

	// delete Function
	Items(const Items& _Other) = delete;
	Items(Items&& _Other) noexcept = delete;
	Items& operator=(const Items& _Other) = delete;
	Items& operator=(Items&& _Other) noexcept = delete;

	void Set_item_Select(Item _item_Select)
	{
		item_Select = _item_Select;
	}
	void Set_Monster_Pos(const float4& _Monster_Pos)
	{
		Monster_Pos = _Monster_Pos;
	}
	
	float4 Dir = {};
protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> item;
	std::shared_ptr<GameEngineCollision> Col;
	//std::shared_ptr<GameEngineCollision> Bag_Col;
	EventParameter Event;
	EventParameter Event_Item;
	Item item_Select = Item::BrokenSword;
	bool gravity = true;

	GameEngineRandom Random;
	

	float Pos_X = 0;
	float Pos_Y = 0;
	float Height = 0;
	bool Item_Check = false;
	float Speed = 700.0f;
	float4 Gravity_Power = {};
	float4 Monster_Pos = {};
	float4 Custom_Pos = {};
	float Number = 1;
	float Time = 0.0f;
	float4 PrevPos = {};
	bool Item_Move = false;

};
