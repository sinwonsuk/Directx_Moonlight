
#include "PreCompile.h"
#include "Black_Smith.h"
#include "Inventory.h"
#include "Player.h"
#include "Player_UI.h"
#include "Black_Smith_Effect.h"
void Black_Smith::Black_Smith_Open_Close()
{
	if (GameEngineInput::IsDown('E', this) && Black_Smith_Start == false && Col->Collision(ContentsCollisionType::Player))
	{
		BrokenSword_Item_Number = 0;
		AncientPot_Item_Number = 0;
		EmpoweredCrystal_Item_Number = 0;
		FireJelly_Item_Number = 0;
		crystals4elect_Item_Number = 0; 
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

		Open = GameEngineSound::SoundPlay("blacksmith_open_gui.wav"); 



		Money->On();
		blacksmith_OX_Enough_01->On();
		blacksmith_OX_Enough_02->On();
		blacksmith_OX_Enough_03->On();
		crystals4elect->On();
		black->On();
		blacksmith_figure->On();
		blacksmith_workbench->On();
		Item_Sort->On();
		Store_name->On();
		Item_Information->On();
		Item_Select->On();
		Item_Window_01->On();
		Item_Window_02->On();
		Item_Window_03->On();
		Item_Window_04->On();

		Item_Weapon_01->On();
		Item_Weapon_02->On();
		Item_Weapon_03->On();

		Enought_Item_Number_01->On();
		Enought_Item_Number_02->On();
		Enought_Item_Number_03->On();

		Item_Number_01->On();
		Item_Number_02->On();
		Item_Number_03->On();
		Black_Smith_Start = true;
		GameEngineCore::MainTime.SetTimeScale(1, 0);
		//GameEngineCore::MainTime.SetAllTimeScale(0);
	}
	else if (GameEngineInput::IsDown('E', this) && Black_Smith_Start == true)
	{
		Money->Off();
		blacksmith_OX_Enough_01->Off();
		blacksmith_OX_Enough_02->Off();
		blacksmith_OX_Enough_03->Off();
		crystals4elect->Off();
		BrokenSword->Off();
		AncientPot->Off();
		EmpoweredCrystal->Off();
		Item_Select->Off();
		black->Off();
		blacksmith_figure->Off();
		blacksmith_workbench->Off();
		Item_Sort->Off();
		Store_name->Off();
		Item_Information->Off();
		Item_Window_01->Off();
		Item_Window_02->Off();
		Item_Window_03->Off();
		Item_Window_04->Off();
		FireJelly->Off();
		Item_Weapon_01->Off();
		Item_Weapon_02->Off();
		Item_Weapon_03->Off();
		Item_Number_01->Off();
		Item_Number_02->Off();
		Item_Number_03->Off();

		Enought_Item_Number_01->Off();
		Enought_Item_Number_02->Off();
		Enought_Item_Number_03->Off();
		Black_Smith_Start = false;

		GameEngineCore::MainTime.SetTimeScale(1, 1);
		//GameEngineCore::MainTime.SetAllTimeScale(1);
	}

}

void Black_Smith::Black_Smith_Move()
{
	if (GameEngineInput::IsDown('A', this) && Black_Smith_Start == true)
	{
		if (Item_Select->Transform.GetWorldPosition().X == -121)
		{
			return;
		}

		Select_Sound = GameEngineSound::SoundPlay("gui_selector_movement.wav"); 
		Item_Select->Transform.AddWorldPosition({ -109.0f,0.0f });
	}

	if (GameEngineInput::IsDown('D', this) && Black_Smith_Start == true)
	{
		if (Item_Select->Transform.GetWorldPosition().X == 206)
		{
			return;
		}
		Select_Sound = GameEngineSound::SoundPlay("gui_selector_movement.wav");
		Item_Select->Transform.AddWorldPosition({ 109.0f,0.0f });
	}

}

void Black_Smith::Item_InforMation_01()
{
	if (Item_Select->Transform.GetWorldPosition().X == -121 && Black_Smith_Start == true)
	{
		//sadadadasd
		{
			Itme_Money = 200;
			std::string numberStr = std::to_string(Itme_Money);
			Money->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		}

		BrokenSword->On();
		crystals4elect->On();
		EmpoweredCrystal->On();
		FireJelly->Off();
		AncientPot->Off();


		BrokenSword->Transform.SetWorldPosition({ 333.0f,-92.0f });
		crystals4elect->Transform.SetWorldPosition({ 333.0f,-160.0f });
		EmpoweredCrystal->Transform.SetWorldPosition({ 333.0f,-231.0f });

		{
			Enough_Item_01 = 1;
			std::string numberStr = std::to_string(Enough_Item_01);

			Enought_Item_Number_01->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		}

		{
			Enough_Item_02 = 2;
			std::string numberStr = std::to_string(Enough_Item_02);
			Enought_Item_Number_02->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		}

		{
			Enough_Item_03 = 3;
			std::string numberStr = std::to_string(Enough_Item_03);
			Enought_Item_Number_03->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		}

		if (Enough_Item_01 <= BrokenSword_Item_Number)
		{
			blacksmith_OX_Enough_01->SetSprite("blacksmith_OX", 1);
		}
		else
		{
			blacksmith_OX_Enough_01->SetSprite("blacksmith_OX", 0);
		}

		if (Enough_Item_02 <= crystals4elect_Item_Number)
		{
			blacksmith_OX_Enough_02->SetSprite("blacksmith_OX", 1);
		}
		else
		{
			blacksmith_OX_Enough_02->SetSprite("blacksmith_OX", 0);
		}

		if (Enough_Item_03 <= EmpoweredCrystal_Item_Number)
		{
			blacksmith_OX_Enough_03->SetSprite("blacksmith_OX", 1);
		}
		else
		{
			blacksmith_OX_Enough_03->SetSprite("blacksmith_OX", 0);
		}


		{
			std::string numberStr = std::to_string(BrokenSword_Item_Number);
			Item_Number_01->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		}

		{
			std::string numberStr = std::to_string(crystals4elect_Item_Number);
			Item_Number_02->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		}

		{
			std::string numberStr = std::to_string(EmpoweredCrystal_Item_Number);
			Item_Number_03->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		}

	}
}

void Black_Smith::Item_Buy_01()
{
	if (GameEngineInput::IsDown('J', this)&& Black_Smith_Start == true)
	{
		if (Item_Select->Transform.GetWorldPosition().X == -121)
		{
			if (Enough_Item_01 <= BrokenSword_Item_Number)
			{
				++Check;
			}

			if (Enough_Item_02 <= crystals4elect_Item_Number)
			{
				++Check;
			}

			if (Enough_Item_03 <= EmpoweredCrystal_Item_Number)
			{
				++Check;
			}



			if (Player_UI::gold >= Itme_Money)
			{
				++Check;

			}

			if (Check == 4)
			{
				



				for (size_t i = 0; i < Inventory::This_Inventory->Item_Renders.size(); i++)
				{
					if (Inventory::This_Inventory->Font_Renders[i] != nullptr)
					{
						if (Inventory::This_Inventory->Item_Renders[i]->Item_Select == 1)
						{
							if (Inventory::This_Inventory->Font_Renders[i]->FontNumber == Enough_Item_01)
							{
								Inventory::This_Inventory->Font_Renders[i]->Font->Death();
								Inventory::This_Inventory->Font_Renders[i]->FontNumber = 0;
								Inventory::This_Inventory->Font_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_Renders[i]->item->Death();
								Inventory::This_Inventory->Item_Renders[i] = nullptr;
								
								break;
							}
							else if (Inventory::This_Inventory->Font_Renders[i]->FontNumber <= Enough_Item_01)
							{
								BrokenSword_Item_Number -= Inventory::This_Inventory->Font_Renders[i]->FontNumber;

								Inventory::This_Inventory->Font_Renders[i]->Font->Death();
								Inventory::This_Inventory->Font_Renders[i]->FontNumber = 0;
								Inventory::This_Inventory->Font_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_Renders[i]->item->Death();
								Inventory::This_Inventory->Item_Renders[i] = nullptr;

							
								continue;
							}

							else
							{
								Inventory::This_Inventory->Font_Renders[i]->FontNumber -= Enough_Item_01;
								std::string numberStr = std::to_string(Inventory::This_Inventory->Font_Renders[i]->FontNumber);
								Inventory::This_Inventory->Font_Renders[i]->Font->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
								break;
							}
						}
					}
				}


				for (size_t i = 0; i < Inventory::This_Inventory->Item_Renders.size(); i++)
				{
					if (Inventory::This_Inventory->Font_Renders[i] != nullptr)
					{

						if (Inventory::This_Inventory->Item_Renders[i]->Item_Select == 3)
						{

							if (Inventory::This_Inventory->Font_Renders[i]->FontNumber == Enough_Item_03)
							{
								Inventory::This_Inventory->Font_Renders[i]->Font->Death();
								Inventory::This_Inventory->Font_Renders[i]->FontNumber = 0;
								Inventory::This_Inventory->Font_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_Renders[i]->item->Death();
								Inventory::This_Inventory->Item_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_type[i]->Item_Oreder = 0;
								Inventory::This_Inventory->Item_type[i]->Move = float4::ZERO;
								
								//Inventory::This_Inventory->
								break;
							}

							else if (Inventory::This_Inventory->Font_Renders[i]->FontNumber <= Enough_Item_03)
							{
								EmpoweredCrystal_Item_Number -= Inventory::This_Inventory->Font_Renders[i]->FontNumber;

								Inventory::This_Inventory->Font_Renders[i]->Font->Death();
								Inventory::This_Inventory->Font_Renders[i]->FontNumber = 0;
								Inventory::This_Inventory->Font_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_Renders[i]->item->Death();
								Inventory::This_Inventory->Item_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_type[i]->Item_Oreder = 0; 
								Inventory::This_Inventory->Item_type[i]->Move = float4::ZERO;
								continue;
							}

							else
							{
								Inventory::This_Inventory->Font_Renders[i]->FontNumber -= Enough_Item_03;

								std::string numberStr = std::to_string(Inventory::This_Inventory->Font_Renders[i]->FontNumber);
								Inventory::This_Inventory->Font_Renders[i]->Font->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
								break;
							}
						}
					}
				}
				for (size_t i = 0; i < Inventory::This_Inventory->Item_Renders.size(); i++)
				{
					if (Inventory::This_Inventory->Font_Renders[i] != nullptr)
					{
						if (Inventory::This_Inventory->Item_Renders[i]->Item_Select == 5)
						{
							if (Inventory::This_Inventory->Font_Renders[i]->FontNumber == Enough_Item_02)
							{
								Inventory::This_Inventory->Font_Renders[i]->Font->Death();
								Inventory::This_Inventory->Font_Renders[i]->FontNumber = 0;
								Inventory::This_Inventory->Font_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_Renders[i]->item->Death();
								Inventory::This_Inventory->Item_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_type[i]->Item_Oreder = 0;
								Inventory::This_Inventory->Item_type[i]->Move = float4::ZERO;
								
								break;
							}

							else if (Inventory::This_Inventory->Font_Renders[i]->FontNumber <= Enough_Item_02)
							{
								crystals4elect_Item_Number -= Inventory::This_Inventory->Font_Renders[i]->FontNumber;

								Inventory::This_Inventory->Font_Renders[i]->Font->Death();
								Inventory::This_Inventory->Font_Renders[i]->FontNumber = 0;
								Inventory::This_Inventory->Font_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_Renders[i]->item->Death();
								Inventory::This_Inventory->Item_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_type[i]->Item_Oreder = 0;
								Inventory::This_Inventory->Item_type[i]->Move = float4::ZERO;

								continue;
							}

							else
							{
								Inventory::This_Inventory->Font_Renders[i]->FontNumber -= Enough_Item_02;
								std::string numberStr = std::to_string(Inventory::This_Inventory->Font_Renders[i]->FontNumber);
								Inventory::This_Inventory->Font_Renders[i]->Font->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
								break;
							}

						}
					}

				}
				

				if (GameEngineInput::IsDown('J', this))
				{

					for (size_t i = 0; i < Inventory::This_Inventory->Item_Renders.size(); i++)
					{
						if (Inventory::This_Inventory->Item_Renders[i] == nullptr)
						{
							std::shared_ptr<Item_InforMation> InforMation = std::make_shared<Item_InforMation>();


							if (i > 4)
							{
								Move_Y = 1;
								Move_X = i - 5;
							}

							if (i < 5)
							{
								Move_X = i;
								Move_Y = 0;
							}

							InforMation->item = CreateComponent<GameEngineUIRenderer>(100);
							InforMation->item->SetSprite("Items",8);
							InforMation->item->AutoSpriteSizeOn();
							InforMation->item->SetAutoScaleRatio(2.0f);
							InforMation->item->Transform.AddLocalPosition(Inventory::This_Inventory->Inventroy_informations[Move_X][Move_Y]->Move);
							InforMation->Item_Select = 9;
							InforMation->Move = Inventory::This_Inventory->Inventroy_informations[Move_X][Move_Y]->Move;
							InforMation->item->Off();


							Inventory::This_Inventory->Item_type[i]->Item_Oreder = 8;
							Inventory::This_Inventory->Item_type[i]->Move = Inventory::This_Inventory->Inventroy_informations[Move_X][Move_Y]->Move;

							Inventory::This_Inventory->Item_Renders[i] = InforMation;
							BrokenSword_Item_Number -= Enough_Item_01;
							crystals4elect_Item_Number -= Enough_Item_02;
							EmpoweredCrystal_Item_Number -= Enough_Item_03;
							Player_UI::gold -= Itme_Money;
							Black_Smith_effect(InforMation->Item_Select - 1);
							break;
						}
					}
				}
				Check = 0;
			}
			Check = 0;
		}
	}

}

void Black_Smith::Item_InforMation_02()
{
	if (Item_Select->Transform.GetWorldPosition().X == -12 && Black_Smith_Start == true)
	{
		{
			Itme_Money = 300;
			std::string numberStr = std::to_string(Itme_Money);
			Money->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		}

		FireJelly->Off();
		crystals4elect->Off(); 



		AncientPot->On();
		BrokenSword->On();
		EmpoweredCrystal->On();

		AncientPot->Transform.SetWorldPosition({ 333.0f,-92.0f });
		BrokenSword->Transform.SetWorldPosition({ 333.0f,-160.0f });
		EmpoweredCrystal->Transform.SetWorldPosition({ 333.0f,-231.0f });


		{
			Enough_Item_01 = 4;
			std::string numberStr = std::to_string(Enough_Item_01);
			Enought_Item_Number_01->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		}

		{
			Enough_Item_02 = 2;
			std::string numberStr = std::to_string(Enough_Item_02);
			Enought_Item_Number_02->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);

		}

		{
			Enough_Item_03 = 1;
			std::string numberStr = std::to_string(Enough_Item_03);	
			Enought_Item_Number_03->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		}

		

		if (Enough_Item_01 <= AncientPot_Item_Number)
		{
			blacksmith_OX_Enough_01->SetSprite("blacksmith_OX", 1);
		}
		else
		{
			blacksmith_OX_Enough_01->SetSprite("blacksmith_OX", 0);
		}

		if (Enough_Item_02 <= BrokenSword_Item_Number)
		{
			blacksmith_OX_Enough_02->SetSprite("blacksmith_OX", 1);
		}
		else
		{
			blacksmith_OX_Enough_02->SetSprite("blacksmith_OX", 0);
		}

		if (Enough_Item_03 <= EmpoweredCrystal_Item_Number)
		{
			blacksmith_OX_Enough_03->SetSprite("blacksmith_OX", 1);
		}
		else
		{
			blacksmith_OX_Enough_03->SetSprite("blacksmith_OX", 0);
		}


		{
			std::string numberStr = std::to_string(AncientPot_Item_Number);
			Item_Number_01->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		}

		{
			std::string numberStr = std::to_string(BrokenSword_Item_Number);
			Item_Number_02->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		}

		{
			std::string numberStr = std::to_string(EmpoweredCrystal_Item_Number);
			Item_Number_03->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		}


	}

}

void Black_Smith::Item_Buy_02()
{

	if (GameEngineInput::IsDown('J', this) && Black_Smith_Start == true)
	{
		if (Item_Select->Transform.GetWorldPosition().X == -12)
		{
			if (Enough_Item_01 <= AncientPot_Item_Number)
			{
				++Check;
			}

			if (Enough_Item_02 <= BrokenSword_Item_Number)
			{
				++Check;
			}

			if (Enough_Item_03 <= EmpoweredCrystal_Item_Number)
			{
				++Check;
			}



			if (Player_UI::gold >= Itme_Money)
			{
				++Check;

			}

			if (Check == 4)
			{
				



				for (size_t i = 0; i < Inventory::This_Inventory->Item_Renders.size(); i++)
				{
					if (Inventory::This_Inventory->Font_Renders[i] != nullptr)
					{
						if (Inventory::This_Inventory->Item_Renders[i]->Item_Select == 2)
						{
							if (Inventory::This_Inventory->Font_Renders[i]->FontNumber == Enough_Item_01)
							{
								Inventory::This_Inventory->Font_Renders[i]->Font->Death();
								Inventory::This_Inventory->Font_Renders[i]->FontNumber = 0;
								Inventory::This_Inventory->Font_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_Renders[i]->item->Death();
								Inventory::This_Inventory->Item_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_type[i]->Item_Oreder = 0;
								Inventory::This_Inventory->Item_type[i]->Move = float4::ZERO;
								break;
							}
							else if (Inventory::This_Inventory->Font_Renders[i]->FontNumber <= Enough_Item_01)
							{
								AncientPot_Item_Number -= Inventory::This_Inventory->Font_Renders[i]->FontNumber;

								Inventory::This_Inventory->Font_Renders[i]->Font->Death();
								Inventory::This_Inventory->Font_Renders[i]->FontNumber = 0;
								Inventory::This_Inventory->Font_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_Renders[i]->item->Death();
								Inventory::This_Inventory->Item_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_type[i]->Item_Oreder = 0;
								Inventory::This_Inventory->Item_type[i]->Move = float4::ZERO;
								continue;
							}

							else
							{
								Inventory::This_Inventory->Font_Renders[i]->FontNumber -= Enough_Item_01;
								std::string numberStr = std::to_string(Inventory::This_Inventory->Font_Renders[i]->FontNumber);
								Inventory::This_Inventory->Font_Renders[i]->Font->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
								break;
							}
						}
					}
				}
				for (size_t i = 0; i < Inventory::This_Inventory->Item_Renders.size(); i++)
				{
					if (Inventory::This_Inventory->Font_Renders[i] != nullptr)
					{

						if (Inventory::This_Inventory->Item_Renders[i]->Item_Select == 1)
						{
							if (Inventory::This_Inventory->Font_Renders[i]->FontNumber == Enough_Item_02)
							{
								Inventory::This_Inventory->Font_Renders[i]->Font->Death();
								Inventory::This_Inventory->Font_Renders[i]->FontNumber = 0;
								Inventory::This_Inventory->Font_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_Renders[i]->item->Death();
								Inventory::This_Inventory->Item_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_type[i]->Item_Oreder = 0;
								Inventory::This_Inventory->Item_type[i]->Move = float4::ZERO;
								break;

							}

							else if (Inventory::This_Inventory->Font_Renders[i]->FontNumber <= Enough_Item_02)
							{
								BrokenSword_Item_Number -= Inventory::This_Inventory->Font_Renders[i]->FontNumber;

								Inventory::This_Inventory->Font_Renders[i]->Font->Death();
								Inventory::This_Inventory->Font_Renders[i]->FontNumber = 0;
								Inventory::This_Inventory->Font_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_Renders[i]->item->Death();
								Inventory::This_Inventory->Item_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_type[i]->Item_Oreder = 0;
								Inventory::This_Inventory->Item_type[i]->Move = float4::ZERO;
								continue;
							}

							else
							{
								Inventory::This_Inventory->Font_Renders[i]->FontNumber -= Enough_Item_02;
								std::string numberStr = std::to_string(Inventory::This_Inventory->Font_Renders[i]->FontNumber);
								Inventory::This_Inventory->Font_Renders[i]->Font->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
								break;
							}
						}
					}
				}
				for (size_t i = 0; i < Inventory::This_Inventory->Item_Renders.size(); i++)
				{
					if (Inventory::This_Inventory->Font_Renders[i] != nullptr)
					{
						if (Inventory::This_Inventory->Item_Renders[i]->Item_Select == 3)
						{
							if (Inventory::This_Inventory->Font_Renders[i]->FontNumber == Enough_Item_03)
							{
								Inventory::This_Inventory->Font_Renders[i]->Font->Death();
								Inventory::This_Inventory->Font_Renders[i]->FontNumber = 0;
								Inventory::This_Inventory->Font_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_Renders[i]->item->Death();
								Inventory::This_Inventory->Item_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_type[i]->Item_Oreder = 0;
								Inventory::This_Inventory->Item_type[i]->Move = float4::ZERO;
								break;
							}

							else if (Inventory::This_Inventory->Font_Renders[i]->FontNumber <= Enough_Item_03)
							{
								EmpoweredCrystal_Item_Number -= Inventory::This_Inventory->Font_Renders[i]->FontNumber;

								Inventory::This_Inventory->Font_Renders[i]->Font->Death();
								Inventory::This_Inventory->Font_Renders[i]->FontNumber = 0;
								Inventory::This_Inventory->Font_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_Renders[i]->item->Death();
								Inventory::This_Inventory->Item_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_type[i]->Item_Oreder = 0;
								Inventory::This_Inventory->Item_type[i]->Move = float4::ZERO;

								continue;
							}

							else
							{
								Inventory::This_Inventory->Font_Renders[i]->FontNumber -= Enough_Item_03;
								std::string numberStr = std::to_string(Inventory::This_Inventory->Font_Renders[i]->FontNumber);
								Inventory::This_Inventory->Font_Renders[i]->Font->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
								break;
							}

						}


					}
				}

				if (GameEngineInput::IsDown('J', this))
				{

					for (size_t i = 0; i < Inventory::This_Inventory->Item_Renders.size(); i++)
					{
						if (Inventory::This_Inventory->Item_Renders[i] == nullptr)
						{
							std::shared_ptr<Item_InforMation> InforMation = std::make_shared<Item_InforMation>();


							if (i > 4)
							{
								Move_Y = 1;
								Move_X = i - 5;
							}

							if (i < 5)
							{
								Move_X = i;
								Move_Y = 0;
							}

							InforMation->item = CreateComponent<GameEngineUIRenderer>(100);
							InforMation->item->SetSprite("Items",6);
							InforMation->item->AutoSpriteSizeOn();
							InforMation->item->SetAutoScaleRatio(2.0f);
							InforMation->item->Transform.AddLocalPosition(Inventory::This_Inventory->Inventroy_informations[Move_X][Move_Y]->Move);
							InforMation->Item_Select = 7;
							InforMation->Move = Inventory::This_Inventory->Inventroy_informations[Move_X][Move_Y]->Move;
							InforMation->item->Off();
							Inventory::This_Inventory->Item_Renders[i] = InforMation;


							Inventory::This_Inventory->Item_type[i]->Item_Oreder = 7;
							Inventory::This_Inventory->Item_type[i]->Move = Inventory::This_Inventory->Inventroy_informations[Move_X][Move_Y]->Move;

							AncientPot_Item_Number -= Enough_Item_01;
							BrokenSword_Item_Number -= Enough_Item_02;
							EmpoweredCrystal_Item_Number -= Enough_Item_03;
							Player_UI::gold -= Itme_Money;
							Black_Smith_effect(InforMation->Item_Select - 1);
							break;
						}
					}
				}
				Check = 0;
			}
			Check = 0;
		}
	}
}

void Black_Smith::Item_InforMation_03()
{
	if (Item_Select->Transform.GetWorldPosition().X == 97 && Black_Smith_Start == true)
	{
		{
			Itme_Money = 400;
			std::string numberStr = std::to_string(Itme_Money);
			Money->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		}

		FireJelly->On();
		crystals4elect->On();
		EmpoweredCrystal->On();


		AncientPot->Off();
		BrokenSword->Off();
	

		FireJelly->Transform.SetWorldPosition({ 333.0f,-92.0f });
		crystals4elect->Transform.SetWorldPosition({ 333.0f,-160.0f });
		EmpoweredCrystal->Transform.SetWorldPosition({ 333.0f,-231.0f });


		{
			Enough_Item_01 = 3;
			std::string numberStr = std::to_string(Enough_Item_01);
			Enought_Item_Number_01->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		}

		{
			Enough_Item_02 = 2;
			std::string numberStr = std::to_string(Enough_Item_02);
			Enought_Item_Number_02->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);

		}

		{
			Enough_Item_03 = 1;
			std::string numberStr = std::to_string(Enough_Item_03);
			Enought_Item_Number_03->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		}



		if (Enough_Item_01 <= FireJelly_Item_Number)
		{
			blacksmith_OX_Enough_01->SetSprite("blacksmith_OX", 1);
		}
		else
		{
			blacksmith_OX_Enough_01->SetSprite("blacksmith_OX", 0);
		}

		if (Enough_Item_02 <= crystals4elect_Item_Number)
		{
			blacksmith_OX_Enough_02->SetSprite("blacksmith_OX", 1);
		}
		else
		{
			blacksmith_OX_Enough_02->SetSprite("blacksmith_OX", 0);
		}

		if (Enough_Item_03 <= EmpoweredCrystal_Item_Number)
		{
			blacksmith_OX_Enough_03->SetSprite("blacksmith_OX", 1);
		}
		else
		{
			blacksmith_OX_Enough_03->SetSprite("blacksmith_OX", 0);
		}


		{
			std::string numberStr = std::to_string(FireJelly_Item_Number);
			Item_Number_01->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		}

		{
			std::string numberStr = std::to_string(crystals4elect_Item_Number);
			Item_Number_02->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		}

		{
			std::string numberStr = std::to_string(EmpoweredCrystal_Item_Number);
			Item_Number_03->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		}


	}
}

void Black_Smith::Item_Buy_03()
{
	if (GameEngineInput::IsDown('J', this) && Black_Smith_Start == true)
	{
		if (Item_Select->Transform.GetWorldPosition().X == 97)
		{
			if (Enough_Item_01 <= BrokenSword_Item_Number)
			{
				++Check;
			}

			if (Enough_Item_02 <= crystals4elect_Item_Number)
			{
				++Check;
			}

			if (Enough_Item_03 <= EmpoweredCrystal_Item_Number)
			{
				++Check;
			}



			if (Player_UI::gold >= Itme_Money)
			{
				++Check;

			}

			if (Check == 4)
			{




				for (size_t i = 0; i < Inventory::This_Inventory->Item_Renders.size(); i++)
				{
					if (Inventory::This_Inventory->Font_Renders[i] != nullptr)
					{
						if (Inventory::This_Inventory->Item_Renders[i]->Item_Select == 4)
						{
							if (Inventory::This_Inventory->Font_Renders[i]->FontNumber == Enough_Item_01)
							{
								Inventory::This_Inventory->Font_Renders[i]->Font->Death();
								Inventory::This_Inventory->Font_Renders[i]->FontNumber = 0;
								Inventory::This_Inventory->Font_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_Renders[i]->item->Death();
								Inventory::This_Inventory->Item_Renders[i] = nullptr;

								break;
							}
							else if (Inventory::This_Inventory->Font_Renders[i]->FontNumber <= Enough_Item_01)
							{
								BrokenSword_Item_Number -= Inventory::This_Inventory->Font_Renders[i]->FontNumber;

								Inventory::This_Inventory->Font_Renders[i]->Font->Death();
								Inventory::This_Inventory->Font_Renders[i]->FontNumber = 0;
								Inventory::This_Inventory->Font_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_Renders[i]->item->Death();
								Inventory::This_Inventory->Item_Renders[i] = nullptr;


								continue;
							}

							else
							{
								Inventory::This_Inventory->Font_Renders[i]->FontNumber -= Enough_Item_01;
								std::string numberStr = std::to_string(Inventory::This_Inventory->Font_Renders[i]->FontNumber);
								Inventory::This_Inventory->Font_Renders[i]->Font->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
								break;
							}
						}
					}
				}


				for (size_t i = 0; i < Inventory::This_Inventory->Item_Renders.size(); i++)
				{
					if (Inventory::This_Inventory->Font_Renders[i] != nullptr)
					{

						if (Inventory::This_Inventory->Item_Renders[i]->Item_Select == 5)
						{

							if (Inventory::This_Inventory->Font_Renders[i]->FontNumber == Enough_Item_02)
							{
								Inventory::This_Inventory->Font_Renders[i]->Font->Death();
								Inventory::This_Inventory->Font_Renders[i]->FontNumber = 0;
								Inventory::This_Inventory->Font_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_Renders[i]->item->Death();
								Inventory::This_Inventory->Item_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_type[i]->Item_Oreder = 0;
								Inventory::This_Inventory->Item_type[i]->Move = float4::ZERO;

								//Inventory::This_Inventory->
								break;
							}

							else if (Inventory::This_Inventory->Font_Renders[i]->FontNumber <= Enough_Item_02)
							{
								EmpoweredCrystal_Item_Number -= Inventory::This_Inventory->Font_Renders[i]->FontNumber;

								Inventory::This_Inventory->Font_Renders[i]->Font->Death();
								Inventory::This_Inventory->Font_Renders[i]->FontNumber = 0;
								Inventory::This_Inventory->Font_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_Renders[i]->item->Death();
								Inventory::This_Inventory->Item_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_type[i]->Item_Oreder = 0;
								Inventory::This_Inventory->Item_type[i]->Move = float4::ZERO;
								continue;
							}

							else
							{
								Inventory::This_Inventory->Font_Renders[i]->FontNumber -= Enough_Item_02;

								std::string numberStr = std::to_string(Inventory::This_Inventory->Font_Renders[i]->FontNumber);
								Inventory::This_Inventory->Font_Renders[i]->Font->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
								break;
							}
						}
					}
				}
				for (size_t i = 0; i < Inventory::This_Inventory->Item_Renders.size(); i++)
				{
					if (Inventory::This_Inventory->Font_Renders[i] != nullptr)
					{
						if (Inventory::This_Inventory->Item_Renders[i]->Item_Select == 3)
						{
							if (Inventory::This_Inventory->Font_Renders[i]->FontNumber == Enough_Item_03)
							{
								Inventory::This_Inventory->Font_Renders[i]->Font->Death();
								Inventory::This_Inventory->Font_Renders[i]->FontNumber = 0;
								Inventory::This_Inventory->Font_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_Renders[i]->item->Death();
								Inventory::This_Inventory->Item_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_type[i]->Item_Oreder = 0;
								Inventory::This_Inventory->Item_type[i]->Move = float4::ZERO;

								break;
							}

							else if (Inventory::This_Inventory->Font_Renders[i]->FontNumber <= Enough_Item_03)
							{
								crystals4elect_Item_Number -= Inventory::This_Inventory->Font_Renders[i]->FontNumber;

								Inventory::This_Inventory->Font_Renders[i]->Font->Death();
								Inventory::This_Inventory->Font_Renders[i]->FontNumber = 0;
								Inventory::This_Inventory->Font_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_Renders[i]->item->Death();
								Inventory::This_Inventory->Item_Renders[i] = nullptr;

								Inventory::This_Inventory->Item_type[i]->Item_Oreder = 0;
								Inventory::This_Inventory->Item_type[i]->Move = float4::ZERO;

								continue;
							}

							else
							{
								Inventory::This_Inventory->Font_Renders[i]->FontNumber -= Enough_Item_03;
								std::string numberStr = std::to_string(Inventory::This_Inventory->Font_Renders[i]->FontNumber);
								Inventory::This_Inventory->Font_Renders[i]->Font->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
								break;
							}

						}
					}

				}


				if (GameEngineInput::IsDown('J', this))
				{

					for (size_t i = 0; i < Inventory::This_Inventory->Item_Renders.size(); i++)
					{
						if (Inventory::This_Inventory->Item_Renders[i] == nullptr)
						{
							std::shared_ptr<Item_InforMation> InforMation = std::make_shared<Item_InforMation>();


							if (i > 4)
							{
								Move_Y = 1;
								Move_X = i - 5;
							}

							if (i < 5)
							{
								Move_X = i;
								Move_Y = 0;
							}

							InforMation->item = CreateComponent<GameEngineUIRenderer>(100);
							InforMation->item->SetSprite("Items",7);
							InforMation->item->AutoSpriteSizeOn();
							InforMation->item->SetAutoScaleRatio(2.0f);
							InforMation->item->Transform.AddLocalPosition(Inventory::This_Inventory->Inventroy_informations[Move_X][Move_Y]->Move);
							InforMation->Item_Select = 8;
							InforMation->Move = Inventory::This_Inventory->Inventroy_informations[Move_X][Move_Y]->Move;
							InforMation->item->Off();


							Inventory::This_Inventory->Item_type[i]->Item_Oreder = 8;
							Inventory::This_Inventory->Item_type[i]->Move = Inventory::This_Inventory->Inventroy_informations[Move_X][Move_Y]->Move;

							Inventory::This_Inventory->Item_Renders[i] = InforMation;
							FireJelly_Item_Number -= Enough_Item_01;
							crystals4elect_Item_Number -= Enough_Item_02;
							EmpoweredCrystal_Item_Number -= Enough_Item_03;
							Player_UI::gold -= Itme_Money;
							Black_Smith_effect(InforMation->Item_Select-1);
							break;
						}
					}
				}
				Check = 0;
			}
			Check = 0;
		}
	}
}

