#include "PreCompile.h"
#include "Shop_Item.h"

Shop_Item::Shop_Item()
{


}

Shop_Item::~Shop_Item()
{


}

void Shop_Item::Start()
{
	item = CreateComponent<GameEngineSpriteRenderer>(200);
	item->SetSprite("Items", 0);
	item->AutoSpriteSizeOn();
	item->SetAutoScaleRatio(2.0f);

	item_border = CreateComponent<GameEngineSpriteRenderer>(200);
	item_border->SetSprite("Card1_Price_Tag", 0);
	item_border->AutoSpriteSizeOn();
	item_border->SetAutoScaleRatio(1.5f);
	item_border->Transform.AddLocalPosition({ 0.0f,25.0f }); 
	std::string numberStr = std::to_string(0);

	Font = CreateComponent<GameEngineSpriteRenderer>(200);
	Font->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
	Font->Transform.AddLocalPosition({ 0.0f,40.0f });
	

}


void Shop_Item::Update(float _Delta)
{
	GetLevel()->GetMainCamera()->SetYSort(-1); 

	
		
		switch (item_Select)
		{
		case Shop_Items::BrokenSword:
		{
			item->SetSprite("Items", 0);
		}
		break;
		case Shop_Items::Ancient_Pot:
		{
			item->SetSprite("Items", 1);
		}
		break;
		case Shop_Items::FireJelly:
		{
			item->SetSprite("Items", 2);
		}
		break;
		case Shop_Items::crystal:
		{
			item->SetSprite("Items", 3);
		}
		break;
		case Shop_Items::Red_crystal:
		{
			item->SetSprite("Items", 4);
		}
		break;
		default:
			break;
		}
		Item_Check = true;


	
	std::string numberStr = std::to_string(Money);
	Font->SetText("µ¸¿ò", numberStr, 17.0f, float4::WHITE, FW1_CENTER);

	if (Prev_Pos.Y > Transform.GetWorldPosition().Y + 4)
	{
		gravity = false;		
	}
	if (Prev_Pos.Y < Transform.GetWorldPosition().Y - 4)
	{
		gravity = true;
	}

	if (gravity == false)
	{
		Transform.AddLocalPosition(float4::UP * Speed * _Delta);
	}
	if (gravity == true)
	{
		Transform.AddLocalPosition(float4::DOWN * Speed * _Delta);
	}


}
