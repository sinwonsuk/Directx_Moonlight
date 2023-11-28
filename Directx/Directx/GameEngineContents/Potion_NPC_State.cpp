#include "PreCompile.h"
#include "Potion_NPC.h"
#include "Inventory.h"
#include "Player.h"
#include "Player_UI.h"
#include "Potion_Effect.h"
void Potion_NPC::Potion_Open_Close()
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
		Open = GameEngineSound::SoundPlay("witch_open_gui.wav");
		Money->On();
		blacksmith_OX_Enough_01->On();
		blacksmith_OX_Enough_02->On();
		blacksmith_OX_Enough_03->On();
		crystals4elect->On();
		black->On();
		Witch_figure->On();
		Witch_Jar->On();
		Item_Sort->On();
		Store_name->On();
		Item_Information->On();
		Item_Select->On();
		Item_Window_01->On();
		Item_Window_02->On();
		Item_Window_03->On();
		Item_Window_04->On();

		Item_Potion_01->On();
		Item_Potion_02->On();
		Item_Potion_03->On();

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
		Witch_figure->Off();
		Witch_Jar->Off();
		Item_Sort->Off();
		Store_name->Off();
		Item_Information->Off();
		Item_Window_01->Off();
		Item_Window_02->Off();
		Item_Window_03->Off();
		Item_Window_04->Off();
		FireJelly->Off();
		Item_Potion_01->Off();
		Item_Potion_02->Off();
		Item_Potion_03->Off();
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

void Potion_NPC::Potion_Move()
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

void Potion_NPC::Item_InforMation_01()
{
	if (Item_Select->Transform.GetWorldPosition().X == -121 && Black_Smith_Start == true)
	{
	
		{
			Itme_Money = 0;
			std::string numberStr = std::to_string(Itme_Money);
			Money->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		}

		BrokenSword->Off();
		crystals4elect->Off();

		EmpoweredCrystal->On();
		FireJelly->On();
		AncientPot->On();


		FireJelly->Transform.SetWorldPosition({ 333.0f,-92.0f });
		AncientPot->Transform.SetWorldPosition({ 333.0f,-160.0f });
		EmpoweredCrystal->Transform.SetWorldPosition({ 333.0f,-231.0f });

		{
			Enough_Item_01 = 1;
			std::string numberStr = std::to_string(Enough_Item_01);

			Enought_Item_Number_01->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		}

		{
			Enough_Item_02 = 1;
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

		if (Enough_Item_02 <= AncientPot_Item_Number)
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
			std::string numberStr = std::to_string(AncientPot_Item_Number);
			Item_Number_02->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		}

		{
			std::string numberStr = std::to_string(EmpoweredCrystal_Item_Number);
			Item_Number_03->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		}

	}
}

void Potion_NPC::Item_Buy_01()
{
	if (GameEngineInput::IsDown('J', this) && Black_Smith_Start == true)
	{
		if (Item_Select->Transform.GetWorldPosition().X == -121)
		{
			if (Enough_Item_01 <= FireJelly_Item_Number)
			{
				++Check;
			}

			if (Enough_Item_02 <= AncientPot_Item_Number)
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

						if (Inventory::This_Inventory->Item_Renders[i]->Item_Select == 2)
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
							
							{
								InforMation->item = CreateComponent<GameEngineUIRenderer>(100);
								InforMation->item->SetSprite("Items", 9);
								InforMation->item->AutoSpriteSizeOn();
								InforMation->item->SetAutoScaleRatio(2.0f);
								InforMation->item->Transform.AddLocalPosition(Inventory::This_Inventory->Inventroy_informations[Move_X][Move_Y]->Move);
								InforMation->Item_Select = 10;
								InforMation->Move = Inventory::This_Inventory->Inventroy_informations[Move_X][Move_Y]->Move;
								InforMation->item->Off();
								Inventory::This_Inventory->Item_Renders[i] = InforMation;


								std::shared_ptr<Font_InforMation> Font_inforMation = std::make_shared<Font_InforMation>();
								Potion_Number_01 = 1;
								std::string numberStr = std::to_string(Potion_Number_01);
								Font_inforMation->Font = CreateComponent<GameEngineUIRenderer>(101);
								Font_inforMation->Font->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
								Font_inforMation->FontNumber = Potion_Number_01;
								Font_inforMation->Font->Transform.SetWorldPosition({ Inventory::This_Inventory->Item_Renders[i]->Move.X + 20,Inventory::This_Inventory->Item_Renders[i]->Move.Y - 5 });
								Font_inforMation->Font->Off();
								Inventory::This_Inventory->Font_Renders[i] = Font_inforMation;

								Inventory::This_Inventory->Item_type[i]->Item_Oreder = 10;
								Inventory::This_Inventory->Item_type[i]->Move = Inventory::This_Inventory->Inventroy_informations[Move_X][Move_Y]->Move;
								

							}				
							FireJelly_Item_Number -= Enough_Item_01;
							AncientPot_Item_Number -= Enough_Item_02;
							EmpoweredCrystal_Item_Number -= Enough_Item_03;
							Potion_Npc_effect(InforMation->Item_Select - 1);
							Player_UI::gold -= Itme_Money;
	
							break;
						}

						if (Inventory::This_Inventory->Item_Renders[i] != nullptr )
						{
							if (Inventory::This_Inventory->Item_Renders[i]->Item_Select == 10)
							{
								std::shared_ptr<Font_InforMation> Font_inforMation = std::make_shared<Font_InforMation>();
								Potion_Number_01 += 1;

								std::string numberStr = std::to_string(Potion_Number_01);

								Font_inforMation->Font = CreateComponent<GameEngineUIRenderer>(101);
								Font_inforMation->Font->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
								Font_inforMation->FontNumber = Potion_Number_01;
								Font_inforMation->Font->Transform.SetWorldPosition({ Inventory::This_Inventory->Item_Renders[i]->Move.X + 20,Inventory::This_Inventory->Item_Renders[i]->Move.Y - 5 });
								Font_inforMation->Font->Off();
								Inventory::This_Inventory->Font_Renders[i] = Font_inforMation;

								Inventory::This_Inventory->Item_type[i]->Item_Oreder = 10;
								Inventory::This_Inventory->Item_type[i]->Move = Inventory::This_Inventory->Item_Renders[i]->Move;


								FireJelly_Item_Number -= Enough_Item_01;
								AncientPot_Item_Number -= Enough_Item_02;
								EmpoweredCrystal_Item_Number -= Enough_Item_03;
								Player_UI::gold -= Itme_Money;
								Potion_Npc_effect(Inventory::This_Inventory->Item_Renders[i]->Item_Select - 1);
								break;
							}
						}
					}				
				}
				Check = 0;
			}
			Check = 0;
		}
	}

}

void Potion_NPC::Item_InforMation_02()
{
	if (Item_Select->Transform.GetWorldPosition().X == -12 && Black_Smith_Start == true)
	{
		{
			Itme_Money = 0;
			std::string numberStr = std::to_string(Itme_Money);
			Money->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		}

		FireJelly->On();
		AncientPot->On();
		crystals4elect->On();
	
		BrokenSword->Off();
		EmpoweredCrystal->Off();

		FireJelly->Transform.SetWorldPosition({ 333.0f,-92.0f });
		AncientPot->Transform.SetWorldPosition({ 333.0f,-160.0f });
		crystals4elect->Transform.SetWorldPosition({ 333.0f,-231.0f });


		{
			Enough_Item_01 = 2;
			std::string numberStr = std::to_string(Enough_Item_01);
			Enought_Item_Number_01->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		}

		{
			Enough_Item_02 = 1;
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

		if (Enough_Item_02 <= AncientPot_Item_Number)
		{
			blacksmith_OX_Enough_02->SetSprite("blacksmith_OX", 1);
		}
		else
		{
			blacksmith_OX_Enough_02->SetSprite("blacksmith_OX", 0);
		}

		if (Enough_Item_03 <= crystals4elect_Item_Number)
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
			std::string numberStr = std::to_string(AncientPot_Item_Number);
			Item_Number_02->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		}

		{
			std::string numberStr = std::to_string(crystals4elect_Item_Number);
			Item_Number_03->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		}


	}

}

void Potion_NPC::Item_Buy_02()
{

	if (GameEngineInput::IsDown('J', this) && Black_Smith_Start == true)
	{
		if (Item_Select->Transform.GetWorldPosition().X == -12)
		{
			if (Enough_Item_01 <= FireJelly_Item_Number)
			{
				++Check;
			}

			if (Enough_Item_02 <= AncientPot_Item_Number)
			{
				++Check;
			}

			if (Enough_Item_03 <= crystals4elect_Item_Number)
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

						if (Inventory::This_Inventory->Item_Renders[i]->Item_Select == 2)
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
						if (Inventory::This_Inventory->Item_Renders[i]->Item_Select == 5)
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

							{
								InforMation->item = CreateComponent<GameEngineUIRenderer>(100);
								InforMation->item->SetSprite("Items", 10);
								InforMation->item->AutoSpriteSizeOn();
								InforMation->item->SetAutoScaleRatio(2.0f);
								InforMation->item->Transform.AddLocalPosition(Inventory::This_Inventory->Inventroy_informations[Move_X][Move_Y]->Move);
								InforMation->Item_Select = 11;
								InforMation->Move = Inventory::This_Inventory->Inventroy_informations[Move_X][Move_Y]->Move;
								InforMation->item->Off();
								Inventory::This_Inventory->Item_Renders[i] = InforMation;


								std::shared_ptr<Font_InforMation> Font_inforMation = std::make_shared<Font_InforMation>();
								Potion_Number_02 = 1;
								std::string numberStr = std::to_string(Potion_Number_02);
								Font_inforMation->Font = CreateComponent<GameEngineUIRenderer>(101);
								Font_inforMation->Font->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
								Font_inforMation->FontNumber = Potion_Number_02;
								Font_inforMation->Font->Transform.SetWorldPosition({ Inventory::This_Inventory->Item_Renders[i]->Move.X + 20,Inventory::This_Inventory->Item_Renders[i]->Move.Y - 5 });
								Font_inforMation->Font->Off();
								Inventory::This_Inventory->Font_Renders[i] = Font_inforMation;

								Inventory::This_Inventory->Item_type[i]->Item_Oreder = 11;
								Inventory::This_Inventory->Item_type[i]->Move = Inventory::This_Inventory->Inventroy_informations[Move_X][Move_Y]->Move;


							}
							FireJelly_Item_Number -= Enough_Item_01;
							AncientPot_Item_Number -= Enough_Item_02;
							crystals4elect_Item_Number -= Enough_Item_03;
							Potion_Npc_effect(InforMation->Item_Select - 1);
							Player_UI::gold -= Itme_Money;

							break;
						}

						if (Inventory::This_Inventory->Item_Renders[i] != nullptr)
						{
							if (Inventory::This_Inventory->Item_Renders[i]->Item_Select == 11)
							{
								std::shared_ptr<Font_InforMation> Font_inforMation = std::make_shared<Font_InforMation>();
								Potion_Number_02 += 1;

								std::string numberStr = std::to_string(Potion_Number_02);

								Font_inforMation->Font = CreateComponent<GameEngineUIRenderer>(101);
								Font_inforMation->Font->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
								Font_inforMation->FontNumber = Potion_Number_02;
								Font_inforMation->Font->Transform.SetWorldPosition({ Inventory::This_Inventory->Item_Renders[i]->Move.X + 20,Inventory::This_Inventory->Item_Renders[i]->Move.Y - 5 });
								Font_inforMation->Font->Off();
								Inventory::This_Inventory->Font_Renders[i] = Font_inforMation;

								Inventory::This_Inventory->Item_type[i]->Item_Oreder = 11;
								Inventory::This_Inventory->Item_type[i]->Move = Inventory::This_Inventory->Item_Renders[i]->Move;


								FireJelly_Item_Number -= Enough_Item_01;
								AncientPot_Item_Number -= Enough_Item_02;
								crystals4elect_Item_Number -= Enough_Item_03;
								Player_UI::gold -= Itme_Money;
								Potion_Npc_effect(Inventory::This_Inventory->Item_Renders[i]->Item_Select - 1);
								break;
							}
						}
					}
				}
				Check = 0;
			}
			Check = 0;
		}
	}
}

void Potion_NPC::Item_InforMation_03()
{
	if (Item_Select->Transform.GetWorldPosition().X == 97 && Black_Smith_Start == true)
	{
		{
			Itme_Money = 0;
			std::string numberStr = std::to_string(Itme_Money);
			Money->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		}

		FireJelly->On();
		crystals4elect->On();
		AncientPot->On();

		EmpoweredCrystal->Off();
		BrokenSword->Off();


		FireJelly->Transform.SetWorldPosition({ 333.0f,-92.0f });
		crystals4elect->Transform.SetWorldPosition({ 333.0f,-160.0f });
		AncientPot->Transform.SetWorldPosition({ 333.0f,-231.0f });


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
			Enough_Item_03 = 2;
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

		if (Enough_Item_03 <= AncientPot_Item_Number)
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
			std::string numberStr = std::to_string(AncientPot_Item_Number);
			Item_Number_03->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		}


	}
}

void Potion_NPC::Item_Buy_03()
{
	if (GameEngineInput::IsDown('J', this) && Black_Smith_Start == true)
	{
		if (Item_Select->Transform.GetWorldPosition().X == 97)
		{
			if (Enough_Item_01 <= FireJelly_Item_Number)
			{
				++Check;
			}
			
			if (Enough_Item_02 <= crystals4elect_Item_Number)
			{
				++Check;
			}

			if (Enough_Item_03 <= AncientPot_Item_Number)
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
						if (Inventory::This_Inventory->Item_Renders[i]->Item_Select == 2)
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

							{
								InforMation->item = CreateComponent<GameEngineUIRenderer>(100);
								InforMation->item->SetSprite("Items", 11);
								InforMation->item->AutoSpriteSizeOn();
								InforMation->item->SetAutoScaleRatio(2.0f);
								InforMation->item->Transform.AddLocalPosition(Inventory::This_Inventory->Inventroy_informations[Move_X][Move_Y]->Move);
								InforMation->Item_Select = 12;
								InforMation->Move = Inventory::This_Inventory->Inventroy_informations[Move_X][Move_Y]->Move;
								InforMation->item->Off();
								Inventory::This_Inventory->Item_Renders[i] = InforMation;


								std::shared_ptr<Font_InforMation> Font_inforMation = std::make_shared<Font_InforMation>();
								Potion_Number_03 = 1;
								std::string numberStr = std::to_string(Potion_Number_03);
								Font_inforMation->Font = CreateComponent<GameEngineUIRenderer>(101);
								Font_inforMation->Font->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
								Font_inforMation->FontNumber = Potion_Number_03;
								Font_inforMation->Font->Transform.SetWorldPosition({ Inventory::This_Inventory->Item_Renders[i]->Move.X + 20,Inventory::This_Inventory->Item_Renders[i]->Move.Y - 5 });
								Font_inforMation->Font->Off();
								Inventory::This_Inventory->Font_Renders[i] = Font_inforMation;

								Inventory::This_Inventory->Item_type[i]->Item_Oreder = 12;
								Inventory::This_Inventory->Item_type[i]->Move = Inventory::This_Inventory->Inventroy_informations[Move_X][Move_Y]->Move;


							}
							FireJelly_Item_Number -= Enough_Item_01;
							crystals4elect_Item_Number -= Enough_Item_02;
							AncientPot_Item_Number -= Enough_Item_03;

							Player_UI::gold -= Itme_Money;
							Potion_Npc_effect(InforMation->Item_Select-1);
							break;
						}

						if (Inventory::This_Inventory->Item_Renders[i] != nullptr)
						{
							if (Inventory::This_Inventory->Item_Renders[i]->Item_Select == 12)
							{
								std::shared_ptr<Font_InforMation> Font_inforMation = std::make_shared<Font_InforMation>();
								Potion_Number_03 += 1;

								std::string numberStr = std::to_string(Potion_Number_03);

								Font_inforMation->Font = CreateComponent<GameEngineUIRenderer>(101);
								Font_inforMation->Font->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
								Font_inforMation->FontNumber = Potion_Number_03;
								Font_inforMation->Font->Transform.SetWorldPosition({ Inventory::This_Inventory->Item_Renders[i]->Move.X + 20,Inventory::This_Inventory->Item_Renders[i]->Move.Y - 5 });
								Font_inforMation->Font->Off();
								Inventory::This_Inventory->Font_Renders[i] = Font_inforMation;

								Inventory::This_Inventory->Item_type[i]->Item_Oreder = 12;
								Inventory::This_Inventory->Item_type[i]->Move = Inventory::This_Inventory->Item_Renders[i]->Move;


								FireJelly_Item_Number -= Enough_Item_01;
								crystals4elect_Item_Number -= Enough_Item_02;
								AncientPot_Item_Number -= Enough_Item_03;

								Player_UI::gold -= Itme_Money;
								Potion_Npc_effect(Inventory::This_Inventory->Item_Renders[i]->Item_Select - 1);
								break;
							}
						}
					}
				}
				Check = 0;
			}
			Check = 0;
		}
	}
}

