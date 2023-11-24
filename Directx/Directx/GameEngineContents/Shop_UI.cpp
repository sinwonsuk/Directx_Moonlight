#include "PreCompile.h"
#include "Shop_UI.h"
#include "Inventory.h"
#include "Shop_Item.h"
#include "Npc.h"
Shop_UI* Shop_UI::this_Shop_UI;
Shop_UI::Shop_UI()
{
}

Shop_UI::~Shop_UI()
{
}

void Shop_UI::Start()
{
	this_Shop_UI = this;

	GameEngineInput::AddInputObject(this);


	for (size_t x = 0; x < 7; x++)
	{

		Inventroy_informations.reserve(7);
		Inventroy_informations.push_back(Inventroy_information);


		for (size_t y = 0; y < 4; y++)
		{
			std::shared_ptr<Inventory_Move> AD = std::make_shared<Inventory_Move>();
			Inventroy_informations[x].reserve(7);
			Inventroy_informations[x].push_back(AD);
		}
	}

	for (size_t x = 0; x < 5; x++)
	{



		if (x > 0)
		{
			Plus_Pos_X += 71;
		}

		for (size_t y = 0; y < 4; y++)
		{
			if (y == 1)
			{
				Plus_Pos_Y -= 84;
			}
			else if (y > 0)
			{
				Plus_Pos_Y -= 74;
			}

			Inventroy_informations[x][y]->Move = { Plus_Pos_X, Plus_Pos_Y };
		}

		Plus_Pos_Y = 163.0f;
	}




	Inventroy_informations[5][0]->Move = { 144, 171 };
	Inventroy_informations[6][0]->Move = { 388, 171 };

	Inventroy_informations[5][1]->Move = { 145,  82 };
	Inventroy_informations[6][1]->Move = { 387,  82 };

	Inventroy_informations[5][2]->Move = { 144, -55 };
	Inventroy_informations[6][2]->Move = { 386, -55 };
	
	Inventroy_informations[5][3]->Move = { 145, -145 };
	Inventroy_informations[6][3]->Move = { 387, -145 };


	/*Inventroy_informations[5][2]->Move = { 144, -55 };
	Inventroy_informations[6][2]->Move = { 386, -55 };

	Inventroy_informations[5][3]->Move = { 144, -55 };
	Inventroy_informations[6][3]->Move = { 386, -55 };*/

	Item_Renders.reserve(30);
	Font_Renders.reserve(30);


	Font_Renders.resize(30);
	Item_Renders.resize(30);


	Shop_Font_Renders.resize(4);
	Shop_Item_Renders.resize(4);
			



			//Item_Start = true;
			//start = false;
	




	

	if (GetLevel()->GetName() == "ShopLevel")
	{
		Inventroy_Screen = CreateComponent<GameEngineUIRenderer>();
		Inventroy_Screen->SetSprite("ShopUI", 0);
		Inventroy_Screen->AutoSpriteSizeOn();
		Inventroy_Screen->SetAutoScaleRatio(2.0f);
		Inventroy_Screen->Off();

	
		Shop_UI_01 = CreateComponent<GameEngineUIRenderer>();
		Shop_UI_01->SetSprite("ShopUI", 1);
		Shop_UI_01->AutoSpriteSizeOn();
		Shop_UI_01->Transform.AddLocalPosition({ 143 ,108 });
		Shop_UI_01->SetAutoScaleRatio(2.0f);
		Shop_UI_01->Off();


		Shop_UI_02 = CreateComponent<GameEngineUIRenderer>();
		Shop_UI_02->SetSprite("ShopUI", 1);
		Shop_UI_02->AutoSpriteSizeOn();
		Shop_UI_02->Transform.AddLocalPosition({ 387,108 });
		Shop_UI_02->SetAutoScaleRatio(2.0f);
		Shop_UI_02->Off();

	
		Shop_UI_03 = CreateComponent<GameEngineUIRenderer>();
		Shop_UI_03->SetSprite("ShopUI", 1);
		Shop_UI_03->AutoSpriteSizeOn();
		Shop_UI_03->Transform.AddLocalPosition({ 143,-119 });
		Shop_UI_03->SetAutoScaleRatio(2.0f);
		Shop_UI_03->Off();

		Shop_UI_04 = CreateComponent<GameEngineUIRenderer>();
		Shop_UI_04->SetSprite("ShopUI", 1);
		Shop_UI_04->AutoSpriteSizeOn();
		Shop_UI_04->Transform.AddLocalPosition({ 387,-119 });
		Shop_UI_04->SetAutoScaleRatio(2.0f);
		Shop_UI_04->Off();

		Inventroy_Select = CreateComponent<GameEngineUIRenderer>();
		Inventroy_Select->SetSprite("Inventory", 1);
		Inventroy_Select->AutoSpriteSizeOn();
		Inventroy_Select->SetAutoScaleRatio(2.3f);
		//Inventroy_Select->Transform.SetWorldScale({ 6.8,3.4});
		Inventroy_Select->Off();
		Inventroy_Select->Transform.SetWorldPosition({ -395,163 });

		

		std::string numberStr = std::to_string(0);

		Money_Font_01 = CreateComponent<GameEngineUIRenderer>(101);
		Money_Font_01->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		Money_Font_01->Transform.SetWorldPosition({211,107});
		Money_Font_01->Off(); 

		Money_Font_02 = CreateComponent<GameEngineUIRenderer>(101);
		Money_Font_02->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		Money_Font_02->Transform.SetWorldPosition({ 459,107 });
		Money_Font_02->Off();

		Money_Font_03 = CreateComponent<GameEngineUIRenderer>(101);
		Money_Font_03->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		Money_Font_03->Transform.SetWorldPosition({ 211,-122 });
		Money_Font_03->Off();

		Money_Font_04 = CreateComponent<GameEngineUIRenderer>(101);
		Money_Font_04->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		Money_Font_04->Transform.SetWorldPosition({ 459,-122 });
		Money_Font_04->Off();
	
	



		Money_Font_bout_01 = CreateComponent<GameEngineUIRenderer>(101);
		Money_Font_bout_01->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		Money_Font_bout_01->Transform.SetWorldPosition({ 211,60 });
		Money_Font_bout_01->Off();

		Money_Font_bout_02 = CreateComponent<GameEngineUIRenderer>(101);
		Money_Font_bout_02->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		Money_Font_bout_02->Transform.SetWorldPosition({ 459,60 });
		Money_Font_bout_02->Off();

		Money_Font_bout_03 = CreateComponent<GameEngineUIRenderer>(101);
		Money_Font_bout_03->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		Money_Font_bout_03->Transform.SetWorldPosition({ 211,-169 });
		Money_Font_bout_03->Off();

		Money_Font_bout_04 = CreateComponent<GameEngineUIRenderer>(101);
		Money_Font_bout_04->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		Money_Font_bout_04->Transform.SetWorldPosition({ 459,-169 });
		Money_Font_bout_04->Off();







		Shop_Item_01 = GetLevel()->CreateActor<Shop_Item>();
		Shop_Item_01->Transform.SetWorldPosition({ -152 ,-129 }); 
		Shop_Item_01->Off(); 

		Shop_Item_02 = GetLevel()->CreateActor<Shop_Item>();
		Shop_Item_02->Transform.SetWorldPosition({ -107 ,-129});
		Shop_Item_02->Off(); 

		Shop_Item_03 = GetLevel()->CreateActor<Shop_Item>();
		Shop_Item_03->Transform.SetWorldPosition({ -152 ,-175 });
		Shop_Item_03->Off();

		Shop_Item_04 = GetLevel()->CreateActor<Shop_Item>();
		Shop_Item_04->Transform.SetWorldPosition({ -107 ,-175 });
		Shop_Item_04->Off(); 


		

		UI_Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Table_UI);
		UI_Col->Transform.SetLocalScale({ 148, 165 });
		UI_Col->Transform.SetWorldPosition({ 510,-527 });
		UI_Col->SetCollisionType(ColType::AABBBOX2D);



	}

}

void Shop_UI::Update(float _DeltaTime)
{
	if (Inven_sync == false)
	{
		for (size_t i = 0; i < Inventory::This_Inventory->Item_Renders.size()-10; i++)
		{
			if (Inventory::This_Inventory->Item_Renders[i] != nullptr)
			{
				std::shared_ptr<Item_InforMation> InforMation = std::make_shared<Item_InforMation>();


				{
					InforMation->item = CreateComponent<GameEngineUIRenderer>(100);
					InforMation->item->SetSprite("Items", Inventory::This_Inventory->Item_Renders[i]->Item_Select - 1);
					InforMation->item->AutoSpriteSizeOn();
					InforMation->item->SetAutoScaleRatio(2.0f);
					InforMation->item->Transform.AddLocalPosition(Inventory::This_Inventory->Item_Renders[i]->Move);
					InforMation->item->Off();
					InforMation->Item_Select = { Inventory::This_Inventory->Item_Renders[i]->Item_Select };
					InforMation->Move = { Inventory::This_Inventory->Item_Renders[i]->Move };
					//Item_Renders[i]->Item_Select = 5;
					Item_Renders[i] = InforMation;
				}
			}

		}

		for (size_t i = 0; i < Inventory::This_Inventory->Font_Renders.size()-10; i++)
		{

			if (Inventory::This_Inventory->Font_Renders[i] != nullptr)
			{
				std::shared_ptr<Font_InforMation> Font_inforMation = std::make_shared<Font_InforMation>();

				std::string numberStr = std::to_string(Inventory::This_Inventory->Font_Renders[i]->FontNumber);

				Font_inforMation->Font = CreateComponent<GameEngineUIRenderer>(101);
				Font_inforMation->Font->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
				Font_inforMation->Font->Transform.SetWorldPosition({ Inventory::This_Inventory->Font_Renders[i]->Move.X + 20,Inventory::This_Inventory->Font_Renders[i]->Move.Y - 5 });
				Font_inforMation->Move = { Inventory::This_Inventory->Font_Renders[i]->Move };
				Font_inforMation->Font->Off();
				Font_inforMation->FontNumber = Inventory::This_Inventory->Font_Renders[i]->FontNumber;
				Font_Renders[i] = Font_inforMation;
			}
		}
		Inven_sync = true; 
	}




	if (UI_Col->Collision(ContentsCollisionType::Player))
	{
		if (GameEngineInput::IsDown('E', this) && Inventory_Start == false)
		{
			for (size_t i = 0; i < Item_Renders.size(); i++)
			{
				if (Item_Renders[i] != nullptr)
				{
					Item_Renders[i]->item->On();
				}

			}

			for (size_t i = 0; i < Font_Renders.size(); i++)
			{
				if (Font_Renders[i] != nullptr)
				{
					Font_Renders[i]->Font->On();
				}

			}


			for (size_t i = 0; i < Shop_Item_Renders.size(); i++)
			{
				if (Shop_Item_Renders[i] != nullptr)
				{
					Shop_Item_Renders[i]->item->On();
				}
			}

			for (size_t i = 0; i < Shop_Font_Renders.size(); i++)
			{
				if (Shop_Font_Renders[i] != nullptr)
				{
					Shop_Font_Renders[i]->Font->On();
				}

			}
			Shop_UI_02->On();
			Shop_UI_01->On();
			Shop_UI_03->On();
			Shop_UI_04->On();


			Inventroy_Screen->On();
			Inventroy_Select->On();
			Inventory_Start = true;
			GameEngineCore::MainTime.SetAllTimeScale(0);
		}

		else if (GameEngineInput::IsDown('E', this) && Inventory_Start == true)
		{
			for (size_t i = 0; i < Item_Renders.size(); i++)
			{
				if (Item_Renders[i] != nullptr)
				{
					Item_Renders[i]->item->Off();
				}
			}

			for (size_t i = 0; i < Font_Renders.size(); i++)
			{
				if (Font_Renders[i] != nullptr)
				{
					Font_Renders[i]->Font->Off();
				}
			}


			for (size_t i = 0; i < Shop_Item_Renders.size(); i++)
			{
				if (Shop_Item_Renders[i] != nullptr)
				{
					Shop_Item_Renders[i]->item->Off();
				}
			}

			for (size_t i = 0; i < Shop_Font_Renders.size(); i++)
			{
				if (Shop_Font_Renders[i] != nullptr)
				{
					Shop_Font_Renders[i]->Font->Off();
				}
			}

			Shop_UI_02->Off();
			Shop_UI_01->Off();
			Shop_UI_03->Off();
			Shop_UI_04->Off();

			Money_Font_01->Off();
			Money_Font_bout_01->Off();


			Money_Font_02->Off();
			Money_Font_bout_02->Off();
			Money_Font_03->Off();
			Money_Font_bout_03->Off();
			Money_Font_04->Off();
			Money_Font_bout_04->Off();

			Inventroy_Screen->Off();
			Inventroy_Select->Off();

			Inventory_Start = false;
			GameEngineCore::MainTime.SetAllTimeScale(1);
		}
	}


	

	


	if (GameEngineInput::IsDown('D', this) && Inventory_Start == true && Select_Stop ==false)
	{
		Inventory_pos_X += 1;

		if (Inventory_pos_X > 6)
		{
			Inventory_pos_X = 6;
		}

		if (Inventory_pos_Y > 1)
		{
			Inventory_pos_Y = 0;
		}

	}

	if (GameEngineInput::IsDown('A', this) && Inventory_Start == true && Select_Stop == false)
	{
		Inventory_pos_X -= 1;

		if (Inventory_pos_X < 0)
		{
			Inventory_pos_X = 0;
		}
	}


	if (GameEngineInput::IsDown('W', this) && Inventory_Start == true && Select_Stop == false)
	{
		Inventory_pos_Y -= 1;

		if (Item_Move == true)
		{
			if (Inventory_pos_X == 5 && Inventory_pos_Y == 1)
			{
				Inventory_pos_Y -= 1;
			}
			else if (Inventory_pos_X == 6 && Inventory_pos_Y == 1)
			{
				Inventory_pos_Y -= 1;
			}
			
		}







		if (Inventory_pos_Y < 0)
		{
			Inventory_pos_Y = 0;
		}
	}


	if (GameEngineInput::IsDown('S', this) && Inventory_Start == true && Select_Stop == false)
	{
		Inventory_pos_Y += 1;

		if (Item_Move == true)
		{
			if (Inventory_pos_X == 5 && Inventory_pos_Y == 1)
			{
				Inventory_pos_Y += 1;
			}
			else if (Inventory_pos_X == 6 && Inventory_pos_Y == 1)
			{
				Inventory_pos_Y += 1;
			}
			else if (Inventory_pos_X == 5 && Inventory_pos_Y == 3)
			{
				Inventory_pos_Y = 2;
			}
			else if (Inventory_pos_X == 6 && Inventory_pos_Y == 3)
			{
				Inventory_pos_Y = 2;
			}
		}


		if (Inventory_pos_Y > 3)
		{
			Inventory_pos_Y = 3;
		}
	}

	if (Inventory_pos_X == 5 && Inventory_pos_Y == 1)
	{
		Inventroy_Select->Transform.SetWorldScale({ 3.0,1.45});
	}
	else if (Inventory_pos_X == 6 && Inventory_pos_Y == 1)
	{
		Inventroy_Select->Transform.SetWorldScale({ 3.0,1.45 });
	}
	else if (Inventory_pos_X == 5 && Inventory_pos_Y == 3)
	{
		Inventroy_Select->Transform.SetWorldScale({ 3.0,1.45 });
	}
	else if (Inventory_pos_X == 6 && Inventory_pos_Y == 3)
	{
		Inventroy_Select->Transform.SetWorldScale({ 3.0,1.45 });
	}
	else
	{
		Inventroy_Select->Transform.SetWorldScale({ 1,1 });
	}

	if (Select_Stop == false)
	{
		Inventroy_Select->Transform.SetWorldPosition({ Inventroy_informations[Inventory_pos_X][Inventory_pos_Y]->Move });
	}
	





	if (GameEngineInput::IsDown('J', this) && Inventory_Start == true && Item_Move == false)
	{
		Item_Move = true;

		for (size_t i = 0; i < Item_Renders.size(); i++)
		{
			if (Item_Renders[i] != nullptr)
			{
				if (Item_Renders[i]->Move == Inventroy_informations[Inventory_pos_X][Inventory_pos_Y]->Move)
				{
					Item_Renders_Order = i;
					break;
				}
			}
		}




	}

	else if (GameEngineInput::IsDown('J', this) && Inventory_Start == true && Item_Move == true)
	{
		Item_Move = false;

		if (Inventory_pos_X <= 4)
		{
			Transform_2_1 = Inventory_pos_Y * 5 + Inventory_pos_X;
		}
		

		


		if (Inventory_pos_X > 4)
		{
			if (Inventory_pos_Y <= 0)
			{
				test = 0;
			}
			if (Inventory_pos_Y > 0)
			{
				test = 1;
			}
			if (Inventory_pos_X == 5)
			{
				test_02 = 1;
			}
			if (Inventory_pos_X == 6)
			{
				test_02 = 2;
			}
			Transform_2_1 = 20 + (test_02)+(test) * 2;
		}

		if (Transform_2_1 == 21)
		{
			Shop_Item_Renders_Order = 0;
		}
		if (Transform_2_1 == 22)
		{
			Shop_Item_Renders_Order = 1;
		}
		if (Transform_2_1 == 23)
		{
			Shop_Item_Renders_Order = 2;
		}
		if (Transform_2_1 == 24)
		{
			Shop_Item_Renders_Order = 3;
		}

		if (Item_Renders[Item_Renders_Order] != nullptr && Item_Renders[Transform_2_1] != nullptr)
		{
			//Item_Renders_Death_Check = true;
			Death_Check = true;
			ADADADA = true;
			if (Item_Renders[Item_Renders_Order]->Move == Item_Renders[Transform_2_1]->Move)
			{
				if (Item_Renders[Item_Renders_Order]->Item_Select == Item_Renders[Transform_2_1]->Item_Select)
				{
					Font_Renders[Transform_2_1]->FontNumber += Font_Renders[Item_Renders_Order]->FontNumber;

					std::string numberStr = std::to_string(Font_Renders[Transform_2_1]->FontNumber);

					Font_Renders[Transform_2_1]->Font->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);


		

					Item_Renders[Item_Renders_Order]->item->Death();
					Item_Renders[Item_Renders_Order] = nullptr;

					Font_Renders[Item_Renders_Order]->Font->Death();
					Font_Renders[Item_Renders_Order] = nullptr;


					Inventory::This_Inventory->Item_Renders[Item_Renders_Order]->item->Death();
					Inventory::This_Inventory->Item_Renders[Item_Renders_Order] = nullptr;



					Inventory::This_Inventory->Font_Renders[Item_Renders_Order]->Font->Death();
					Inventory::This_Inventory->Font_Renders[Item_Renders_Order] = nullptr;



				}






				else
				{
					Item_Move = true;
					return;
				}


			}

		}

		else if (Item_Renders[Transform_2_1] != nullptr && Item_Renders[Item_Renders_Order] != nullptr)
		{
			Item_Renders_Death_Check = true;

			if (Item_Renders[Item_Renders_Order]->Move == Item_Renders[Transform_2_1]->Move)
			{
				if (Item_Renders[Item_Renders_Order]->Item_Select == Item_Renders[Transform_2_1]->Item_Select)
				{
					Font_Renders[Transform_2_1]->FontNumber += Font_Renders[Item_Renders_Order]->FontNumber;

					std::string numberStr = std::to_string(Font_Renders[Transform_2_1]->FontNumber);

					Font_Renders[Transform_2_1]->Font->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);

					//Item_Renders[Item_Renders_Order]->item->Death();
					Item_Renders[Item_Renders_Order] = nullptr;
				


					//Font_Renders[Item_Renders_Order]->Font->Death();
					Font_Renders[Item_Renders_Order] = nullptr;




					Inventory::This_Inventory->Font_Renders[Transform_2_1]->FontNumber += Inventory::This_Inventory->Font_Renders[Item_Renders_Order]->FontNumber;

					std::string InvenTory_numberStr = std::to_string(Font_Renders[Transform_2_1]->FontNumber);

					Inventory::This_Inventory->Font_Renders[Transform_2_1]->Font->SetText("µ¸¿ò", InvenTory_numberStr, 20.0f, float4::WHITE, FW1_CENTER);

					//Inventory::This_Inventory->Item_Renders[Item_Renders_Order]->item->Death();
					Inventory::This_Inventory->Item_Renders[Item_Renders_Order] = nullptr;



					//Inventory::This_Inventory->Font_Renders[Item_Renders_Order]->Font->Death();
					Inventory::This_Inventory->Font_Renders[Item_Renders_Order] = nullptr;






				}


				
					
				

				else
				{
					Item_Move = true;
					return;
				}


			}

		}


		else if (Item_Renders[Item_Renders_Order] != nullptr && Transform_2_1 > 20)
		{
			Item_Renders_Death_Check = true;

			//Shop_Item_Renders[Shop_Item_Renders_Order]

			Font_Renders[Transform_2_1] = Font_Renders[Item_Renders_Order];
			Item_Renders[Transform_2_1] = Item_Renders[Item_Renders_Order];


			//Item_Renders[Item_Renders_Order]->item->Death();
			Item_Renders[Item_Renders_Order] = nullptr;
			Font_Renders[Item_Renders_Order]->Font->On();
			//Font_Renders[Item_Renders_Order]->Font->Death();
			Font_Renders[Item_Renders_Order] = nullptr;



			Inventory::This_Inventory->Font_Renders[Transform_2_1] = Inventory::This_Inventory->Font_Renders[Item_Renders_Order];
			Inventory::This_Inventory->Item_Renders[Transform_2_1] = Inventory::This_Inventory->Item_Renders[Item_Renders_Order];

			Inventory::This_Inventory->Item_overlap.erase(Inventory::This_Inventory->Item_type[Item_Renders_Order]->Item_Oreder);

			if (Item_Renders_Order <= 20 && Inventory::This_Inventory->Item_Renders[Item_Renders_Order] != nullptr)
			{
				Inventory::This_Inventory->Item_Renders[Item_Renders_Order] = nullptr;
				Inventory::This_Inventory->Font_Renders[Item_Renders_Order]->Font->On();

				Inventory::This_Inventory->Font_Renders[Item_Renders_Order] = nullptr;
			}
			

			Death_Check = true;
		}

		else if (Item_Renders[Item_Renders_Order] != nullptr)
		{
			Item_Renders_Death_Check = true;

			Font_Renders[Transform_2_1] = Font_Renders[Item_Renders_Order];
			Item_Renders[Transform_2_1] = Item_Renders[Item_Renders_Order];


			//Item_Renders[Item_Renders_Order]->item->Death();
			Item_Renders[Item_Renders_Order] = nullptr;
			Font_Renders[Item_Renders_Order]->Font->On();
			//Font_Renders[Item_Renders_Order]->Font->Death();
			Font_Renders[Item_Renders_Order] = nullptr;

			
		
			Inventory::This_Inventory->Font_Renders[Transform_2_1] = Font_Renders[Transform_2_1];
			Inventory::This_Inventory->Item_Renders[Transform_2_1] = Item_Renders[Transform_2_1];

			Inventory::This_Inventory->Item_overlap.erase(Inventory::This_Inventory->Item_type[Item_Renders_Order]->Item_Oreder);
			if (Item_Renders_Order <= 20 && Inventory::This_Inventory->Font_Renders[Item_Renders_Order] != nullptr)
			{
				Inventory::This_Inventory->Item_Renders[Item_Renders_Order] = nullptr;
				Inventory::This_Inventory->Font_Renders[Item_Renders_Order]->Font->On();

				Inventory::This_Inventory->Font_Renders[Item_Renders_Order] = nullptr;
			}

		}


		if (Item_Renders_Death_Check == true)
		{
			if (Transform_2_1 <= 20 && Inventory::This_Inventory->Item_Renders[Transform_2_1] != nullptr)
			{
				Inventory::This_Inventory->Item_type[Transform_2_1]->Item_Oreder = Inventory::This_Inventory->Item_Renders[Transform_2_1]->Item_Select;
				Inventory::This_Inventory->Item_type[Transform_2_1]->Move = Inventory::This_Inventory->Item_Renders[Transform_2_1]->Move;
			}
		
			Inventory::This_Inventory->remove_Order.push_back(Item_Renders_Order);


			std::sort(Inventory::This_Inventory->remove_Order.begin(), Inventory::This_Inventory->remove_Order.end());


			Inventory::This_Inventory->Item_type[Item_Renders_Order]->Item_Oreder = 0;
			Inventory::This_Inventory->Item_type[Item_Renders_Order]->Move = float4::ZERO;

			Item_Renders_Death_Check = false;
			

		}

		if (Transform_2_1 > 20 && Death_Check ==true)
		{
			if (Inventory::This_Inventory->Item_Renders[Transform_2_1] != nullptr)
			{
				Inventory::This_Inventory->Item_type[Transform_2_1]->Item_Oreder = 0;
				Inventory::This_Inventory->Item_type[Transform_2_1]->Move = {};
				Inventory::This_Inventory->Font_Renders[Transform_2_1]->Font->Death();

				Font_Renders[Transform_2_1]->Font->On(); 

				Inventory::This_Inventory->Font_Renders[Transform_2_1] = nullptr;
				Inventory::This_Inventory->Item_Renders[Transform_2_1]->item->Death();
				Inventory::This_Inventory->Item_Renders[Transform_2_1] = nullptr;


				Item_Renders[Transform_2_1]->item->On();

			}
		}
		Death_Check = false;

		ADADADA = false;
		//Shop_Item_Renders_Order = 100;
	}

	if (Item_Move == true)
	{
		if (Item_Renders[Item_Renders_Order] != nullptr)
		{




			Item_Renders[Item_Renders_Order]->item->Transform.SetWorldPosition(Inventroy_informations[Inventory_pos_X][Inventory_pos_Y]->Move);
			Item_Renders[Item_Renders_Order]->Move = { Inventroy_informations[Inventory_pos_X][Inventory_pos_Y]->Move };
			





			if (Item_Renders_Order < 21 && Inventory::This_Inventory->Item_Renders[Item_Renders_Order] != nullptr)
			{
				Inventory::This_Inventory->Item_Renders[Item_Renders_Order]->item->Transform.SetWorldPosition(Inventroy_informations[Inventory_pos_X][Inventory_pos_Y]->Move);
				Inventory::This_Inventory->Item_Renders[Item_Renders_Order]->Move = { Inventroy_informations[Inventory_pos_X][Inventory_pos_Y]->Move };
			}
				
		}
		
		if (Font_Renders[Item_Renders_Order] != nullptr)
		{




			Font_Renders[Item_Renders_Order]->Font->Off();
			Font_Renders[Item_Renders_Order]->Font->Transform.SetWorldPosition({ Inventroy_informations[Inventory_pos_X][Inventory_pos_Y]->Move.X + 20,Inventroy_informations[Inventory_pos_X][Inventory_pos_Y]->Move.Y - 5 });
			Font_Renders[Item_Renders_Order]->Move = { Inventroy_informations[Inventory_pos_X][Inventory_pos_Y]->Move.X,Inventroy_informations[Inventory_pos_X][Inventory_pos_Y]->Move.Y };






			if (Item_Renders_Order < 21 && Inventory::This_Inventory->Item_Renders[Item_Renders_Order] != nullptr)
			{		
				Inventory::This_Inventory->Font_Renders[Item_Renders_Order]->Font->Off();
				Inventory::This_Inventory->Font_Renders[Item_Renders_Order]->Font->Transform.SetWorldPosition({ Inventroy_informations[Inventory_pos_X][Inventory_pos_Y]->Move.X + 20,Inventroy_informations[Inventory_pos_X][Inventory_pos_Y]->Move.Y - 5 });
				Inventory::This_Inventory->Font_Renders[Item_Renders_Order]->Move = { Inventroy_informations[Inventory_pos_X][Inventory_pos_Y]->Move.X,Inventroy_informations[Inventory_pos_X][Inventory_pos_Y]->Move.Y };
			}

		}


	}


	if (Item_Renders[21] != nullptr)
	{
		
		if (GameEngineInput::IsDown('J', this) && Select_Stop ==false)
		{
			if (Inventory_pos_X == 5 && Inventory_pos_Y == 0)
			{
				Money_Font_01->On();
				Money_Font_bout_01->On();
				Shop_Item_01->Off(); 
				test_03++;
			}
			
			else if (Inventory_pos_X == 5 && Inventory_pos_Y == 1)
			{
				Money_Font_01->On();
				Money_Font_bout_01->On();
				Select_Stop = true;
			}

			if (test_03 == 1)
			{
				


			}

			if (test_03 == 2)
			{
			
				
				Money_01 = 0;
				test_03 = 0;

				std::string Money = std::to_string(Money_01);

				Money_Font_01->SetText("µ¸¿ò", Money, 20.0f, float4::WHITE, FW1_CENTER);
				Money_Font_01->Off();

				Money_Font_bout_01->SetText("µ¸¿ò", Money, 20.0f, float4::WHITE, FW1_CENTER);
				Money_Font_bout_01->Off(); 

			

			}

			
		}
		else if (GameEngineInput::IsDown('J', this) && Select_Stop == true)
		{
			if (Inventory_pos_X == 5 && Inventory_pos_Y == 1)
			{
			
				Shop_Item_01->On();
				Shop_Item_01->Set_item_Select(static_cast<Shop_Items>(Item_Renders[21]->Item_Select - 1));
				Shop_Item_01->Set_Prev_Pos({ -152 ,-129 });
				Shop_Item_01->Set_Money(Money_01* Font_Renders[21]->FontNumber);

				Select_Stop = false;
				
			}
			
		}

		if (GameEngineInput::IsDown('W', this) && Select_Stop == true)
		{
			if (Inventory_pos_X == 5 && Inventory_pos_Y == 1)
			{
				Money_01 += 10;

				std::string Money = std::to_string(Money_01);
				std::string Money_Bout = std::to_string(Money_01 * Font_Renders[21]->FontNumber);

				Money_Font_01->SetText("µ¸¿ò", Money, 20.0f, float4::WHITE, FW1_CENTER);

				Money_Font_bout_01->SetText("µ¸¿ò", Money_Bout, 20.0f, float4::WHITE, FW1_CENTER);
			}
		}

		if (GameEngineInput::IsDown('S', this) && Select_Stop == true)
		{
			if (Inventory_pos_X == 5 && Inventory_pos_Y == 1)
			{
				Money_01 -= 10;

				if (Money_01 <= 0)
				{
					Money_01 = 0;
				}
				std::string Money = std::to_string(Money_01);

				std::string Money_Bout = std::to_string(Money_01 * Font_Renders[21]->FontNumber);

				Money_Font_01->SetText("µ¸¿ò", Money, 20.0f, float4::WHITE, FW1_CENTER);

				Money_Font_bout_01->SetText("µ¸¿ò", Money_Bout, 20.0f, float4::WHITE, FW1_CENTER);
			}
		}


	}
	

	if (Item_Renders[22] != nullptr)
	{

		if (GameEngineInput::IsDown('J', this) && Select_Stop == false)
		{
			if (Inventory_pos_X == 6 && Inventory_pos_Y == 0)
			{
				Money_Font_02->On();
				Money_Font_bout_02->On();
				Shop_Item_02->Off();
				test_04++;
			}

			else if (Inventory_pos_X == 6 && Inventory_pos_Y == 1)
			{
				Select_Stop = true;
			}

			if (test_04 == 1)
			{



			}

			if (test_04 == 2)
			{


				Money_02 = 0;
				test_04 = 0;

				std::string Money = std::to_string(Money_02);

				Money_Font_02->SetText("µ¸¿ò", Money, 20.0f, float4::WHITE, FW1_CENTER);
				Money_Font_02->Off();

				Money_Font_bout_02->SetText("µ¸¿ò", Money, 20.0f, float4::WHITE, FW1_CENTER);
				Money_Font_bout_02->Off();



			}


		}
		else if (GameEngineInput::IsDown('J', this) && Select_Stop == true)
		{
			if (Inventory_pos_X == 6 && Inventory_pos_Y == 1)
			{

				Shop_Item_02->On();
				Shop_Item_02->Set_item_Select(static_cast<Shop_Items>(Item_Renders[22]->Item_Select - 1));
				Shop_Item_02->Set_Money(Money_02 * Font_Renders[22]->FontNumber);
				Shop_Item_02->Set_Prev_Pos({ -107 ,-129 });
				Select_Stop = false;

			}

		}

		if (GameEngineInput::IsDown('W', this) && Select_Stop == true)
		{
			if (Inventory_pos_X == 6 && Inventory_pos_Y == 1)
			{
				Money_02 += 10;

				std::string Money = std::to_string(Money_02);
				std::string Money_Bout = std::to_string(Money_02 * Font_Renders[22]->FontNumber);

				Money_Font_02->SetText("µ¸¿ò", Money, 20.0f, float4::WHITE, FW1_CENTER);

				Money_Font_bout_02->SetText("µ¸¿ò", Money_Bout, 20.0f, float4::WHITE, FW1_CENTER);
			}
		}

		if (GameEngineInput::IsDown('S', this) && Select_Stop == true)
		{
			if (Inventory_pos_X == 6 && Inventory_pos_Y == 1)
			{
				Money_02 -= 10;

				if (Money_02 <= 0)
				{
					Money_02 = 0;
				}
				std::string Money = std::to_string(Money_02);

				std::string Money_Bout = std::to_string(Money_02 * Font_Renders[22]->FontNumber);

				Money_Font_02->SetText("µ¸¿ò", Money, 20.0f, float4::WHITE, FW1_CENTER);

				Money_Font_bout_02->SetText("µ¸¿ò", Money_Bout, 20.0f, float4::WHITE, FW1_CENTER);
			}
		}
	}

	if (Item_Renders[23] != nullptr)
	{

		if (GameEngineInput::IsDown('J', this) && Select_Stop == false)
		{
			if (Inventory_pos_X == 5 && Inventory_pos_Y == 2)
			{
				Money_Font_03->On();
				Money_Font_bout_03->On();
				Shop_Item_03->Off();
				test_05++;
			}

			else if (Inventory_pos_X == 5 && Inventory_pos_Y == 3)
			{
				Select_Stop = true;
			}

			if (test_05 == 1)
			{



			}

			if (test_05 == 2)
			{


				Money_03 = 0;
				test_05 = 0;

				std::string Money = std::to_string(Money_03);

				Money_Font_03->SetText("µ¸¿ò", Money, 20.0f, float4::WHITE, FW1_CENTER);
				Money_Font_03->Off();

				Money_Font_bout_03->SetText("µ¸¿ò", Money, 20.0f, float4::WHITE, FW1_CENTER);
				Money_Font_bout_03->Off();
			}
		}

		else if (GameEngineInput::IsDown('J', this) && Select_Stop == true)
		{
			if (Inventory_pos_X == 5 && Inventory_pos_Y == 3)
			{

				Shop_Item_03->On();
				Shop_Item_03->Set_item_Select(static_cast<Shop_Items>(Item_Renders[23]->Item_Select - 1));
				Shop_Item_03->Set_Money(Money_03 * Font_Renders[23]->FontNumber);
				Shop_Item_03->Set_Prev_Pos({ -152 ,-175 });
				Select_Stop = false;

			}

		}

		if (GameEngineInput::IsDown('W', this) && Select_Stop == true)
		{
			if (Inventory_pos_X == 5 && Inventory_pos_Y == 3)
			{
				Money_03 += 10;

				std::string Money = std::to_string(Money_03);
				std::string Money_Bout = std::to_string(Money_03 * Font_Renders[23]->FontNumber);

				Money_Font_03->SetText("µ¸¿ò", Money, 20.0f, float4::WHITE, FW1_CENTER);

				Money_Font_bout_03->SetText("µ¸¿ò", Money_Bout, 20.0f, float4::WHITE, FW1_CENTER);
			}
		}

		if (GameEngineInput::IsDown('S', this) && Select_Stop == true)
		{
			if (Inventory_pos_X == 5 && Inventory_pos_Y == 3)
			{
				Money_03 -= 10;

				if (Money_03 <= 0)
				{
					Money_03 = 0;
				}
				std::string Money = std::to_string(Money_03);

				std::string Money_Bout = std::to_string(Money_03 * Font_Renders[23]->FontNumber);

				Money_Font_03->SetText("µ¸¿ò", Money, 20.0f, float4::WHITE, FW1_CENTER);

				Money_Font_bout_03->SetText("µ¸¿ò", Money_Bout, 20.0f, float4::WHITE, FW1_CENTER);
			}
		}
	}

	if (Item_Renders[24] != nullptr)
	{

		if (GameEngineInput::IsDown('J', this) && Select_Stop == false)
		{
			if (Inventory_pos_X == 6 && Inventory_pos_Y == 2)
			{
				Money_Font_04->On();
				Money_Font_bout_04->On();
				Shop_Item_04->Off();
				test_06++;
			}

			else if (Inventory_pos_X == 6 && Inventory_pos_Y == 3)
			{
				Select_Stop = true;
			}

			if (test_06 == 1)
			{



			}

			if (test_06 == 2)
			{


				Money_04 = 0;
				test_06 = 0;

				std::string Money = std::to_string(Money_04);

				Money_Font_04->SetText("µ¸¿ò", Money, 20.0f, float4::WHITE, FW1_CENTER);
				Money_Font_04->Off();

				Money_Font_bout_04->SetText("µ¸¿ò", Money, 20.0f, float4::WHITE, FW1_CENTER);
				Money_Font_bout_04->Off();
			}
		}

		else if (GameEngineInput::IsDown('J', this) && Select_Stop == true)
		{
			if (Inventory_pos_X == 6 && Inventory_pos_Y == 3)
			{

				Shop_Item_04->On();
				Shop_Item_04->Set_item_Select(static_cast<Shop_Items>(Item_Renders[24]->Item_Select - 1));
				Shop_Item_04->Set_Money(Money_04 * Font_Renders[24]->FontNumber);
				Shop_Item_04->Set_Prev_Pos({ -107 ,-175 });
				Select_Stop = false;
			}

		}

		if (GameEngineInput::IsDown('W', this) && Select_Stop == true)
		{
			if (Inventory_pos_X == 6 && Inventory_pos_Y == 3)
			{
				Money_04 += 10;

				std::string Money = std::to_string(Money_04);
				std::string Money_Bout = std::to_string(Money_04 * Font_Renders[24]->FontNumber);

				Money_Font_04->SetText("µ¸¿ò", Money, 20.0f, float4::WHITE, FW1_CENTER);

				Money_Font_bout_04->SetText("µ¸¿ò", Money_Bout, 20.0f, float4::WHITE, FW1_CENTER);
			}
		}

		if (GameEngineInput::IsDown('S', this) && Select_Stop == true)
		{
			if (Inventory_pos_X == 6 && Inventory_pos_Y == 3)
			{
				Money_04 -= 10;

				if (Money_04 <= 0)
				{
					Money_04 = 0;
				}
				std::string Money = std::to_string(Money_04);

				std::string Money_Bout = std::to_string(Money_04 * Font_Renders[24]->FontNumber);

				Money_Font_04->SetText("µ¸¿ò", Money, 20.0f, float4::WHITE, FW1_CENTER);

				Money_Font_bout_04->SetText("µ¸¿ò", Money_Bout, 20.0f, float4::WHITE, FW1_CENTER);
			}
		}
	}



	//std::shared_ptr<class Shop_Item> AD = Shop_Item_01;



	//if (GameEngineInput::IsDown('1', this) && check == false)
	//{
	//	check = true;
	//}
	//else if (GameEngineInput::IsDown('1', this) && check == true)
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
	//		GetLevel()->GetMainCamera()->Transform.AddWorldPosition(float4::UP * 5);
	//		return;
	//	}

	//	if (GameEngineInput::IsPress('S', this))
	//	{
	//		GetLevel()->GetMainCamera()->Transform.AddWorldPosition(float4::DOWN * 5);
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
	//	AD->Transform.AddWorldRotation({ 0.0f,1.0f * _DeltaTime,0.0f });
	//	return;
	//}
	//if (GameEngineInput::IsPress('E', this))
	//{
	//	AD->Transform.AddWorldRotation({ 0.0f,-1.0f * _DeltaTime,0.0f });
	//	return;
	//}
	////-4946.0f, -5275.0f


	//TransformData date = AD->Transform.GetConstTransformDataRef();

	////date.LocalPosition;

	////float4 WorldMousePos;

	//float4 WorldMousePos = { date.LocalPosition.X,date.LocalPosition.Y };
	//OutputDebugStringA(WorldMousePos.ToString("\n").c_str());


}
