#include "PreCompile.h"
#include "Potion_NPC.h"
#include "Potion_Effect.h"
Potion_NPC::Potion_NPC()
{


}

Potion_NPC::~Potion_NPC()
{


}

void Potion_NPC::Start()
{
	GameEngineInput::AddInputObject(this);

	

	{
		black = CreateComponent<GameEngineUIRenderer>(-100);
		black->SetSprite("Black", 0);
		black->SetImageScale({ 5000.0f,5000.0f });
		black->GetColorData().MulColor = { 1,1,1,0.5 };
	}
	{
		Witch_figure = CreateComponent<GameEngineUIRenderer>(-100);
		Witch_figure->SetSprite("Witch", 0);
		Witch_figure->AutoSpriteSizeOn();
		Witch_figure->SetAutoScaleRatio(2.0f);
		Witch_figure->Transform.SetWorldPosition({ -385,-30 });

	}

	{
		Witch_Jar = CreateComponent<GameEngineUIRenderer>(-100);
		Witch_Jar->SetSprite("Witch", 1);
		Witch_Jar->AutoSpriteSizeOn();
		Witch_Jar->SetAutoScaleRatio(2.0f);
		Witch_Jar->Transform.SetWorldPosition({ 23,-181 });
	}

	{
		Item_Sort = CreateComponent<GameEngineUIRenderer>(-100);
		Item_Sort->SetSprite("Black_Smith", 3);
		Item_Sort->AutoSpriteSizeOn();
		Item_Sort->SetAutoScaleRatio(1.2f);
		Item_Sort->Transform.SetWorldPosition({ 27,98 });
	}
	{
		Store_name = CreateComponent<GameEngineUIRenderer>(-100);
		Store_name->SetSprite("Witch", 2);
		Store_name->AutoSpriteSizeOn();
		Store_name->Transform.SetWorldPosition({ 31,310 });
	}

	{
		Item_Information = CreateComponent<GameEngineUIRenderer>(101);
		Item_Information->SetSprite("Black_Smith", 2);
		Item_Information->AutoSpriteSizeOn();
		Item_Information->SetAutoScaleRatio(1.0f);
		Item_Information->Transform.SetWorldPosition({ 443.0f,-23.0f });
	}

	{
		Item_Window_01 = CreateComponent<GameEngineUIRenderer>(101);
		Item_Window_01->SetSprite("Black_Smith", 4);
		Item_Window_01->AutoSpriteSizeOn();
		Item_Window_01->SetAutoScaleRatio(1.0f);
		Item_Window_01->Transform.SetWorldPosition({ -121.0f,164.0f });
		Item_Window_01->Off();
	}

	{
		Item_Window_02 = CreateComponent<GameEngineUIRenderer>(101);
		Item_Window_02->SetSprite("Black_Smith", 4);
		Item_Window_02->AutoSpriteSizeOn();
		Item_Window_02->SetAutoScaleRatio(1.0f);
		Item_Window_02->Transform.SetWorldPosition({ -12.0f,164.0f });
		Item_Window_02->Off();
	}

	{
		Item_Window_03 = CreateComponent<GameEngineUIRenderer>(101);
		Item_Window_03->SetSprite("Black_Smith", 4);
		Item_Window_03->AutoSpriteSizeOn();
		Item_Window_03->SetAutoScaleRatio(1.0f);
		Item_Window_03->Transform.SetWorldPosition({ 97.0f,164.0f });
		Item_Window_03->Off();
	}

	{
		Item_Window_04 = CreateComponent<GameEngineUIRenderer>(101);
		Item_Window_04->SetSprite("Black_Smith", 4);
		Item_Window_04->AutoSpriteSizeOn();
		Item_Window_04->SetAutoScaleRatio(1.0f);
		Item_Window_04->Transform.SetWorldPosition({ 206.0f,164.0f });
		Item_Window_04->Off();
	}
	{
		Item_Select = CreateComponent<GameEngineUIRenderer>(101);
		Item_Select->SetSprite("Inventory", 1);
		Item_Select->AutoSpriteSizeOn();
		Item_Select->SetAutoScaleRatio(2.3f);
		Item_Select->Off();
		Item_Select->Transform.SetWorldPosition({ -121.0f,164.0f });
	}




	{
		BrokenSword = CreateComponent<GameEngineUIRenderer>(101);
		BrokenSword->SetSprite("Items", 0);
		BrokenSword->AutoSpriteSizeOn();
		BrokenSword->SetAutoScaleRatio(2.3f);
		BrokenSword->Off();
		BrokenSword->Transform.SetWorldPosition({ 333.0f,-92.0f });

	}

	{
		AncientPot = CreateComponent<GameEngineUIRenderer>(101);
		AncientPot->SetSprite("Items", 1);
		AncientPot->AutoSpriteSizeOn();
		AncientPot->SetAutoScaleRatio(2.3f);
		AncientPot->Off();
		AncientPot->Transform.SetWorldPosition({ 333.0f,-160.0f });
	}

	{
		EmpoweredCrystal = CreateComponent<GameEngineUIRenderer>(101);
		EmpoweredCrystal->SetSprite("Items", 2);
		EmpoweredCrystal->AutoSpriteSizeOn();
		EmpoweredCrystal->SetAutoScaleRatio(2.3f);
		EmpoweredCrystal->Off();
		EmpoweredCrystal->Transform.SetWorldPosition({ 333.0f,-231.0f });
	}

	{
		FireJelly = CreateComponent<GameEngineUIRenderer>(101);
		FireJelly->SetSprite("Items", 3);
		FireJelly->AutoSpriteSizeOn();
		FireJelly->SetAutoScaleRatio(2.3f);
		FireJelly->Off();
		FireJelly->Transform.SetWorldPosition({ -121.0f,164.0f });
	}

	{
		crystals4elect = CreateComponent<GameEngineUIRenderer>(101);
		crystals4elect->SetSprite("Items", 4);
		crystals4elect->AutoSpriteSizeOn();
		crystals4elect->SetAutoScaleRatio(2.3f);
		crystals4elect->Off();
		crystals4elect->Transform.SetWorldPosition({ 333.0f,-160.0f });
	}

	{
		Item_Sword = CreateComponent<GameEngineUIRenderer>(101);
		Item_Sword->SetSprite("Items", 4);
		Item_Sword->AutoSpriteSizeOn();
		Item_Sword->SetAutoScaleRatio(2.3f);
		Item_Sword->Off();
		Item_Sword->Transform.SetWorldPosition({ 333.0f,-160.0f });
	}

	{
		Item_Potion_01 = CreateComponent<GameEngineUIRenderer>(101);
		Item_Potion_01->SetSprite("Items", 9);
		Item_Potion_01->AutoSpriteSizeOn();
		Item_Potion_01->SetAutoScaleRatio(2.3f);
		Item_Potion_01->Off();
		Item_Potion_01->Transform.SetWorldPosition({ -121.0f,164.0f });
	}
	{
		Item_Potion_02 = CreateComponent<GameEngineUIRenderer>(101);
		Item_Potion_02->SetSprite("Items", 10);
		Item_Potion_02->AutoSpriteSizeOn();
		Item_Potion_02->SetAutoScaleRatio(2.3f);
		Item_Potion_02->Off();
		Item_Potion_02->Transform.SetWorldPosition({ -12.0f,164.0f });
	}

	{
		Item_Potion_03 = CreateComponent<GameEngineUIRenderer>(101);
		Item_Potion_03->SetSprite("Items", 11);
		Item_Potion_03->AutoSpriteSizeOn();
		Item_Potion_03->SetAutoScaleRatio(2.3f);
		Item_Potion_03->Off();
		Item_Potion_03->Transform.SetWorldPosition({ 97.0f,164.0f });
	}

	{
		blacksmith_OX_Enough_01 = CreateComponent<GameEngineUIRenderer>(101);
		blacksmith_OX_Enough_01->SetSprite("blacksmith_OX", 0);
		blacksmith_OX_Enough_01->AutoSpriteSizeOn();
		blacksmith_OX_Enough_01->SetAutoScaleRatio(2.0f);
		blacksmith_OX_Enough_01->Off();
		blacksmith_OX_Enough_01->Transform.SetWorldPosition({ 542,-97 });
	}

	{
		blacksmith_OX_Enough_02 = CreateComponent<GameEngineUIRenderer>(101);
		blacksmith_OX_Enough_02->SetSprite("blacksmith_OX", 1);
		blacksmith_OX_Enough_02->AutoSpriteSizeOn();
		blacksmith_OX_Enough_02->SetAutoScaleRatio(2.0f);
		blacksmith_OX_Enough_02->Off();
		blacksmith_OX_Enough_02->Transform.SetWorldPosition({ 542,-165 });
	}
	{
		blacksmith_OX_Enough_03 = CreateComponent<GameEngineUIRenderer>(101);
		blacksmith_OX_Enough_03->SetSprite("blacksmith_OX", 1);
		blacksmith_OX_Enough_03->AutoSpriteSizeOn();
		blacksmith_OX_Enough_03->SetAutoScaleRatio(2.0f);
		blacksmith_OX_Enough_03->Off();
		blacksmith_OX_Enough_03->Transform.SetWorldPosition({ 542,-234 });
	}

	{
		Npc = CreateComponent<GameEngineSpriteRenderer>(101);
		Npc->CreateAnimation("Witch_Npc", "Witch_Npc", 0.1f, -1, -1, true);
		Npc->AutoSpriteSizeOn();
		Npc->SetAutoScaleRatio(2.0f);
		Npc->On();
		Npc->Transform.SetWorldPosition({ -320,-980 });
		Npc->ChangeAnimation("Witch_Npc");
	}


	{
		std::string numberStr = std::to_string(0);
		Enought_Item_Number_01 = CreateComponent<GameEngineUIRenderer>(101);
		Enought_Item_Number_01->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		Enought_Item_Number_01->Transform.SetWorldPosition({ 475 ,-68 });
		Enought_Item_Number_01->Off();
	}

	{
		std::string numberStr = std::to_string(0);
		Enought_Item_Number_02 = CreateComponent<GameEngineUIRenderer>(101);
		Enought_Item_Number_02->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		Enought_Item_Number_02->Transform.SetWorldPosition({ 475 ,-137 });
		Enought_Item_Number_02->Off();
	}
	{
		std::string numberStr = std::to_string(0);
		Enought_Item_Number_03 = CreateComponent<GameEngineUIRenderer>(101);
		Enought_Item_Number_03->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		Enought_Item_Number_03->Transform.SetWorldPosition({ 475 ,-205 });
		Enought_Item_Number_03->Off();
	}
	{
		std::string numberStr = std::to_string(0);
		Item_Number_01 = CreateComponent<GameEngineUIRenderer>(101);
		Item_Number_01->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		Item_Number_01->Transform.SetWorldPosition({ 475 ,-94 });
		Item_Number_01->Off();
	}
	{
		std::string numberStr = std::to_string(0);
		Item_Number_02 = CreateComponent<GameEngineUIRenderer>(101);
		Item_Number_02->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		Item_Number_02->Transform.SetWorldPosition({ 475 ,-163 });
		Item_Number_02->Off();
	}

	{
		std::string numberStr = std::to_string(0);
		Item_Number_03 = CreateComponent<GameEngineUIRenderer>(101);
		Item_Number_03->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		Item_Number_03->Transform.SetWorldPosition({ 475 ,-233 });
		Item_Number_03->Off();
	}

	{
		std::string numberStr = std::to_string(0);
		Money = CreateComponent<GameEngineUIRenderer>(101);
		Money->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		Money->Transform.SetWorldPosition({ 517 ,11 });
		Money->Off();
	}





	black->Off();
	Witch_figure->Off();
	Witch_Jar->Off();
	Item_Sort->Off();
	Store_name->Off();
	Item_Information->Off();

	{
		Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Black_Smith);
		Col->SetCollisionType(ColType::AABBBOX2D);
		Col->Transform.SetWorldPosition({ -320,-1040 });
		Col->Transform.SetLocalScale({ 100.0f, 200.0f });
	}



}

void Potion_NPC::Update(float _Delta)
{
	Potion_Open_Close();
	Potion_Move();

	if (Item_Select->Transform.GetWorldPosition().X == -121)
	{
		Item_InforMation_01();
		Item_Buy_01();
	}

	if (Item_Select->Transform.GetWorldPosition().X == -12)
	{
		Item_InforMation_02();
		Item_Buy_02();
	}
	if (Item_Select->Transform.GetWorldPosition().X == 97)
	{
		Item_InforMation_03();
		Item_Buy_03();
	}


	
}

void Potion_NPC::Potion_Npc_effect(int _Sprite)
{
	std::shared_ptr<Potion_Effect> Object = GetLevel()->CreateActor<Potion_Effect>();
	Object->Set_Prev_Pos({ 23, -151 });
	Object->Transform.SetWorldPosition({ 23,-151 });
	Object->Set_Sprite(_Sprite);

}
