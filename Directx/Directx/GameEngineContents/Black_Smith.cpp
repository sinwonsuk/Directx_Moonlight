#include "PreCompile.h"
#include "Black_Smith.h"
#include "Inventory.h"
#include "Player.h"
#include "Player_UI.h"
#include "Inventory.h"
Black_Smith::Black_Smith()
{

}


Black_Smith::~Black_Smith()
{


}




void Black_Smith::Start()
{
	GameEngineInput::AddInputObject(this); 

	{
		black = CreateComponent<GameEngineUIRenderer>(-100);
		black->SetSprite("Black", 0);
		black->SetImageScale({ 5000.0f,5000.0f });
		black->GetColorData().MulColor = { 1,1,1,0.5 };
	}
	{
		blacksmith_figure = CreateComponent<GameEngineUIRenderer>(-100);
		blacksmith_figure->SetSprite("Black_Smith", 0);
		blacksmith_figure->AutoSpriteSizeOn();
		blacksmith_figure->SetAutoScaleRatio(2.0f);
		blacksmith_figure->Transform.SetWorldPosition({ -385,-30 });


	}
	{
		blacksmith_workbench = CreateComponent<GameEngineUIRenderer>(-100);
		blacksmith_workbench->SetSprite("Black_Smith", 1);
		blacksmith_workbench->AutoSpriteSizeOn();
		blacksmith_workbench->SetAutoScaleRatio(2.0f);
		blacksmith_workbench->Transform.SetWorldPosition({ 23,-221 });
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
		Store_name->SetSprite("Black_Smith", 5);
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
		Item_Weapon_01 = CreateComponent<GameEngineUIRenderer>(101);
		Item_Weapon_01->SetSprite("Items", 5);
		Item_Weapon_01->AutoSpriteSizeOn();
		Item_Weapon_01->SetAutoScaleRatio(2.3f);
		Item_Weapon_01->Off();
		Item_Weapon_01->Transform.SetWorldPosition({ -121.0f,164.0f });
	}
	{
		Item_Weapon_02 = CreateComponent<GameEngineUIRenderer>(101);
		Item_Weapon_02->SetSprite("Items", 6);
		Item_Weapon_02->AutoSpriteSizeOn();
		Item_Weapon_02->SetAutoScaleRatio(2.3f);
		Item_Weapon_02->Off();
		Item_Weapon_02->Transform.SetWorldPosition({ -12.0f,164.0f });
	}

	{
		Item_Weapon_03 = CreateComponent<GameEngineUIRenderer>(101);
		Item_Weapon_03->SetSprite("Items", 7);
		Item_Weapon_03->AutoSpriteSizeOn();
		Item_Weapon_03->SetAutoScaleRatio(2.3f);
		Item_Weapon_03->Off();
		Item_Weapon_03->Transform.SetWorldPosition({ 97.0f,164.0f });
	}

	{
		blacksmith_OX_Enough_01 = CreateComponent<GameEngineUIRenderer>(101);
		blacksmith_OX_Enough_01->SetSprite("blacksmith_OX", 0);
		blacksmith_OX_Enough_01->AutoSpriteSizeOn();
		blacksmith_OX_Enough_01->SetAutoScaleRatio(2.0f);
		blacksmith_OX_Enough_01->Off();
		blacksmith_OX_Enough_01->Transform.SetWorldPosition({ 542,-97});
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
		blacksmith_OX_Enough_03->Transform.SetWorldPosition({ 542,-234});
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


	//Item_Number_01


	//Font->Transform.SetWorldPosition({ Font_Renders[i]->Move.X + 20,Font_Renders[i]->Move.Y - 5 });
	//Font_inforMation->Item_Select = Font_Renders[i]->Item_Select;
	//Font_inforMation->Move = { Font_Renders[i]->Move.X,Font_Renders[i]->Move.Y};
	//Font->Off();



	for (size_t i = 0; i < Inventory::This_Inventory->Item_Renders.size(); i++)
	{
		if (Inventory::This_Inventory->Item_Renders[i] != nullptr)
		{
			if (Inventory::This_Inventory->Item_Renders[i]->Item_Select == 1)
			{
				BrokenSword_Item_Number += Inventory::This_Inventory->Font_Renders[i]->FontNumber;
			}
			if (Inventory::This_Inventory->Item_Renders[i]->Item_Select == 2)
			{
				AncientPot_Item_Number += Inventory::This_Inventory->Font_Renders[i]->FontNumber;
			}
			if (Inventory::This_Inventory->Item_Renders[i]->Item_Select == 3)
			{
				EmpoweredCrystal_Item_Number += Inventory::This_Inventory->Font_Renders[i]->FontNumber;
			}
			if (Inventory::This_Inventory->Item_Renders[i]->Item_Select == 4)
			{
				FireJelly_Item_Number += Inventory::This_Inventory->Font_Renders[i]->FontNumber;
			}
			if (Inventory::This_Inventory->Item_Renders[i]->Item_Select == 5)
			{
				crystals4elect_Item_Number += Inventory::This_Inventory->Font_Renders[i]->FontNumber;
			}
		}
	}


	black->Off();
	blacksmith_figure->Off();
	blacksmith_workbench->Off();
	Item_Sort->Off();
	Store_name->Off();
	Item_Information->Off();


}

void Black_Smith::Update(float _Delta)
{
	Black_Smith_Open_Close();
	Black_Smith_Move();

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
	/*if (Item_Select->Transform.GetWorldPosition().X == -121)
	{
		Item_InforMation_01();
		Item_Buy_01();
	}*/



	

	//std::shared_ptr<class GameEngineUIRenderer> AD = blacksmith_OX_Enough_01;



	//if (GameEngineInput::IsDown('1',this) && check == false)
	//{
	//	check = true;
	//}
	//else if (GameEngineInput::IsDown('1',this) && check == true)
	//	check = false;
	//{
	//}


	//if (check == true)
	//{
	//	if (GameEngineInput::IsPress('A', this))
	//	{
	//		GetLevel()->GetMainCamera()->Transform.AddWorldPosition({ 5.0f,0.0f });
	//	}

	//	if (GameEngineInput::IsPress('D', this))
	//	{
	//		GetLevel()->GetMainCamera()->Transform.AddWorldPosition({ -5.0f,0.0f });
	//		return;
	//	}

	//	if (GameEngineInput::IsPress('W', this))
	//	{
	//		GetLevel()->GetMainCamera()->Transform.AddWorldPosition(float4::UP *5);
	//		return;
	//	}

	//	if (GameEngineInput::IsPress('S', this))
	//	{
	//		GetLevel()->GetMainCamera()->Transform.AddWorldPosition(float4::DOWN* 5);
	//		return;
	//	}
	//}
	//if (check == false)
	//{


	//	if (GameEngineInput::IsPress('A', this))
	//	{
	//		AD->Transform.AddWorldPosition({ 1.0f,0.0f });
	//	}

	//	if (GameEngineInput::IsPress('D', this))
	//	{
	//		AD->Transform.AddWorldPosition({ -1.0f,0.0f });
	//		return;
	//	}

	//	if (GameEngineInput::IsPress('W', this))
	//	{
	//		AD->Transform.AddWorldPosition(float4::UP);
	//		return;
	//	}

	//	if (GameEngineInput::IsPress('S', this))
	//	{
	//		AD->Transform.AddWorldPosition(float4::DOWN);
	//		return;
	//	}
	//}

	//if (GameEngineInput::IsPress('Q', this))
	//{
	//	AD->Transform.AddWorldRotation({0.0f,1.0f* _Delta,0.0f});
	//	return;
	//}
	//if (GameEngineInput::IsPress('E', this))
	//{
	//	AD->Transform.AddWorldRotation({ 0.0f,-1.0f* _Delta,0.0f });
	//	return;
	//}
	////-4946.0f, -5275.0f


	//TransformData date = AD->Transform.GetConstTransformDataRef();

	////date.LocalPosition;

	////float4 WorldMousePos;

	//float4 WorldMousePos = { date.LocalPosition.X,date.LocalPosition.Y };
	//OutputDebugStringA(WorldMousePos.ToString("\n").c_str());



}
