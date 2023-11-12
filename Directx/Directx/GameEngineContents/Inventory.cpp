#include "PreCompile.h"
#include "Inventory.h"
#include "Items.h"
Inventory* Inventory::This_Inventory;
Inventory::Inventory()
{


}

Inventory::~Inventory()
{


}

void Inventory::Start()
{
	This_Inventory = this;
	GameEngineInput::AddInputObject(this); 
	Inventroy_Screen = CreateComponent<GameEngineUIRenderer>();
	Inventroy_Screen->SetSprite("Inventory", 0);
	Inventroy_Screen->AutoSpriteSizeOn();
	Inventroy_Screen->SetAutoScaleRatio(2.0f);
	Inventroy_Screen->Off(); 

	Inventroy_Select = CreateComponent<GameEngineUIRenderer>();
	Inventroy_Select->SetSprite("Inventory", 1);
	Inventroy_Select->AutoSpriteSizeOn();
	Inventroy_Select->SetAutoScaleRatio(2.3f);

	Inventroy_Select->Off();
	Inventroy_Select->Transform.SetWorldPosition({ -395,163 });

	
	//Inventroy_information.push_back(move);

	//Inventroy_informations.push_back(Inventroy_information);

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
			else if (y> 0)
			{
				Plus_Pos_Y -= 74;
			}
			
			Inventroy_informations[x][y]->Move = { Plus_Pos_X, Plus_Pos_Y };
		}

		Plus_Pos_Y = 163.0f;
	}
	
	


	Inventroy_informations[5][0]->Move = { 133, 167 };
	Inventroy_informations[6][0]->Move = { 306, 167 };
	Inventroy_informations[5][1]->Move = { 49, 77 };
	Inventroy_informations[6][1]->Move = { 49, 77 };
	Inventroy_informations[5][2]->Move = { 49, 6 };
	Inventroy_informations[6][2]->Move = { 120, 6 };
	Inventroy_informations[5][3]->Move = { 48, -65 };
	Inventroy_informations[6][3]->Move = { 48, -65 };

	/*item = CreateComponent<GameEngineUIRenderer>(100);
	item->SetSprite("Items", 0);
	item->AutoSpriteSizeOn();
	item->SetAutoScaleRatio(2.0f);*/
	
	
	Item_Renders.reserve(20);
	Item_type.reserve(20);
	//Item_type.resize(20);
	Font_Renders.reserve(20);
	
	Font_Renders.resize(20);
	Item_Renders.resize(20);

	for (size_t i = 0; i < 20; i++)
	{
		std::shared_ptr<ItemType> InforMation = std::make_shared<ItemType>();
		InforMation->Item_Oreder = 0;

		Item_type.push_back(InforMation);
	}

}

void Inventory::Update(float _DeltaTime)
{
	if (Item_Start == true)
	{
		// ¾Öµµ ³Ö´Â°Å Á¤ÇØÁà¾ß ÇÏ³× 

		std::shared_ptr<Item_InforMation> InforMation = std::make_shared<Item_InforMation>();

	
		{
			InforMation->item = CreateComponent<GameEngineUIRenderer>(100);
			InforMation->item->SetSprite("Items", Item_Sprite_Number - 1);
			InforMation->item->AutoSpriteSizeOn();
			InforMation->item->SetAutoScaleRatio(2.0f);
			InforMation->Item_Select = Item_Sprite_Number;

			InforMation->item->Off();

			
		}
		

		


		
		for (size_t i = 0; i < Item_type.size(); i++)
		{

		if (Item_type[i]->Item_Oreder == 0)
		 {
				Item_Check = 1;
				Font_Check = i;
				//Font_Check += test_02;

				break;
		}

			if (Item_type[i]->Item_Oreder == Item_Sprite_Number)
			{
				Font_Check = i;
				Item_Check = 100;
				//Font_Check += test_02;
				break;
			}
		}
		
			for (size_t i = 0; i < Item_type.size(); i++)
			{
				if (Item_type[i]->Item_Oreder == 0)
				{

					Item_type[i]->Item_Oreder = Item_Sprite_Number;
			
					Number = i;

					break;
				}
			}
		

		






			if (Item_Check == 1)
			{
				for (size_t i = 0; i < Item_type.size(); i++)
				{
					if (Item_type[i]->Item_Oreder == 0)
					{
						Item_Plus_X = Number;

						if (Item_Plus_X < 5)
						{
							Item_pos_Y = 0;
						}
				
						else if (Item_Plus_X >= 5)
						{
							Item_Plus_X = Number % 5;			
							Item_pos_Y =1;				
						}

				


						if (Item_Plus_X > 0)
						{
							InforMation->item->Transform.SetWorldPosition({ Inventroy_informations[Item_pos_X + Item_Plus_X][Item_pos_Y + Item_Plus_Y]->Move });
							InforMation->Move = { Inventroy_informations[Item_pos_X + Item_Plus_X][Item_pos_Y + Item_Plus_Y]->Move };
							Item_type[Number]->Move = { Inventroy_informations[Item_pos_X + Item_Plus_X][Item_pos_Y + Item_Plus_Y]->Move };

							if (remove_Order.size() == 0)
							{
								Item_Renders[Number] = InforMation;					
							}
							else if (remove_Order.size() > 0)
							{
								Item_Renders[Number] = InforMation;
							}

							break;
						}

						else
						{
							Item_Plus_X = 0;
							InforMation->item->Transform.SetWorldPosition({ Inventroy_informations[Item_pos_X][Item_pos_Y+ Item_Plus_Y]->Move });
							InforMation->Move = { Inventroy_informations[Item_pos_X][Item_pos_Y+ Item_Plus_Y]->Move };
							Item_type[Number]->Move = { Inventroy_informations[Item_pos_X + Item_Plus_X][Item_pos_Y + Item_Plus_Y]->Move };


							if (remove_Order.size() == 0)
							{
								Item_Renders[Number] = InforMation;
								
							}
							else if (remove_Order.size() > 0)
							{
								Item_Renders[Number] = InforMation;
							}

							break;
						}
					

						

					
					}
					//break;
				}

				{
					std::shared_ptr<Font_InforMation> Font_inforMation = std::make_shared<Font_InforMation>();

					std::string numberStr = std::to_string(1);




					
					{
						Font_inforMation->Font = CreateComponent<GameEngineUIRenderer>(101);
						Font_inforMation->Font->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
						Font_inforMation->Font->Transform.SetWorldPosition({ Inventroy_informations[Item_pos_X + Item_Plus_X][Item_pos_Y + Item_Plus_Y]->Move.X + 20,Inventroy_informations[Item_pos_X][Item_pos_Y + Item_Plus_Y]->Move.Y - 5 });
						Font_inforMation->Font->Off();
						Font_inforMation->Item_Select = Item_Sprite_Number;
						Font_inforMation->Move = { Inventroy_informations[Item_pos_X + Item_Plus_X][Item_pos_Y+ Item_Plus_Y]->Move };

						if (remove_Order.size() == 0)
						{
							Font_Renders[Number] = Font_inforMation; 
						
						}
						else if (remove_Order.size() > 0)
						{
							Font_Renders[Number] = Font_inforMation;
							
							//remove_Order.erase(remove_Order.begin());
						}
					}
					

					
				}
				
				Item_overlap.insert(std::make_pair(Item_Sprite_Number, float4{ Inventroy_informations[Item_pos_X + Item_Plus_X][Item_pos_Y+ Item_Plus_Y]->Move }));
				Item_Check = 0;

			}
			else if (Item_Check == 100)
			{
				

					if (Font_Renders[Font_Check]->Item_Select == 1)
					{
						std::string numberStr = std::to_string(Font_Renders[Font_Check]->FontNumber+=1);
						Font_Renders[Font_Check ]->Font->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
					}
					else if (Font_Renders[Font_Check ]->Item_Select == 2)
					{
						std::string numberStr = std::to_string(Font_Renders[Font_Check]->FontNumber += 1);
						Font_Renders[Font_Check ]->Font->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);

					}
					else if (Font_Renders[Font_Check]->Item_Select == 3)
					{
						std::string numberStr = std::to_string(Font_Renders[Font_Check]->FontNumber += 1);
						Font_Renders[Font_Check ]->Font->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);

					}
					else if (Font_Renders[Font_Check ]->Item_Select == 4)
					{
						std::string numberStr = std::to_string(Font_Renders[Font_Check]->FontNumber += 1);
						Font_Renders[Font_Check ]->Font->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
		
					}
					else if (Font_Renders[Font_Check ]->Item_Select == 5)
					{
						std::string numberStr = std::to_string(Font_Renders[Font_Check]->FontNumber += 1);
						Font_Renders[Font_Check ]->Font->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
			
					}

					for (size_t i = 0; i < Item_type.size(); i++)
					{
						
						if (Item_type[Number]->Item_Oreder == Item_type[i]->Item_Oreder)
						{
							Item_type[Number]->Item_Oreder = 0;
							Item_type[Number]->Move = float4::ZERO;
						}

					}

			

				//Item_type[Number] = 0; 
				//Item_Renders.pop_back();
				//Font_Renders.pop_back();

				Item_Check = 0;
			}

			dasd = false;
		//	remove_Order.clear();
		Font_Check = 0;
		Item_Start = false;
	}

	
	if (GameEngineInput::IsDown('I', this) && Inventory_Start ==false)
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

		

		Inventroy_Screen->On(); 
		Inventroy_Select->On();
		Inventory_Start = true;
		GameEngineCore::MainTime.SetAllTimeScale(0);
	}
	else if (GameEngineInput::IsDown('I', this) && Inventory_Start == true)
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

		Inventroy_Screen->Off();
		Inventroy_Select->Off();
		Inventory_Start = false;
		GameEngineCore::MainTime.SetAllTimeScale(1);
	}





	if (GameEngineInput::IsDown('D', this)&& Inventory_Start == true)
	{
		Inventory_pos_X += 1;


		


		if (Inventory_pos_X > 6 )
		{
			Inventory_pos_X = 6;
		}


	
	}

	if (GameEngineInput::IsDown('A', this) && Inventory_Start == true)
	{
		Inventory_pos_X -= 1;

		if (Inventory_pos_X < 0)
		{
			Inventory_pos_X = 0;
		}
	}


	if (GameEngineInput::IsDown('W', this) && Inventory_Start == true)
	{
		Inventory_pos_Y -= 1;

		if (Inventory_pos_Y < 0)
		{
			Inventory_pos_Y = 0;
		}
	}


	if (GameEngineInput::IsDown('S', this) && Inventory_Start == true)
	{
		Inventory_pos_Y += 1;

		


		if (Inventory_pos_Y > 3)
		{
			Inventory_pos_Y = 3;
		}
	}


	Inventroy_Select->Transform.SetWorldPosition({ Inventroy_informations[Inventory_pos_X][Inventory_pos_Y]->Move });






	if (GameEngineInput::IsDown('J', this) && Inventory_Start == true && Item_Move ==false)
	{
		Item_Move = true;

		for (size_t i = 0; i < Item_Renders.size(); i++)
		{
			if (Item_Renders[i] != nullptr)
			{
				if (Item_Renders[i]->Move == Inventroy_informations[Inventory_pos_X][Inventory_pos_Y]->Move)
				{




					Item_Renders_Order = i;




					/*Item_Renders[i]->item->Death();
					Item_Renders.erase(Item_Renders.begin() + i);
					Item_overlap.erase(Item_type[i]->Item_Oreder);
					Font_Renders[i]->Font->Death();
					Font_Renders.erase(Font_Renders.begin() + i);*/








					break;
				}
			}
		}

		


	}

	else if (GameEngineInput::IsDown('J', this) && Inventory_Start == true && Item_Move == true)
	{
		Item_Move = false;



		
		

		Transform_2_1 = Inventory_pos_Y * 5 + Inventory_pos_X;

		if (Item_Renders[Transform_2_1] != nullptr && Item_Renders[Item_Renders_Order] != nullptr)
		{
			Item_Renders_Death_Check = true; 
			if (Item_Renders[Item_Renders_Order]->Move == Item_Renders[Transform_2_1]->Move)
			{
				if (Item_Renders[Item_Renders_Order]->Item_Select == Item_Renders[Transform_2_1]->Item_Select)
				{
					Font_Renders[Transform_2_1]->FontNumber += Font_Renders[Item_Renders_Order]->FontNumber;

					std::string numberStr = std::to_string(Font_Renders[Transform_2_1]->FontNumber);

					Font_Renders[Transform_2_1]->Font->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);

					Item_Renders[Item_Renders_Order]->item->Death(); 
					Item_Renders[Item_Renders_Order] = nullptr;
					Item_overlap.erase(Item_type[Item_Renders_Order]->Item_Oreder);
					//Font_Renders[Item_Renders_Order]->Font->Death();

					Font_Renders[Item_Renders_Order]->Font->Death();
					Font_Renders[Item_Renders_Order] = nullptr;
				}
				else
				{
					Item_Move = true;
					return; 
				}


			}	
		
		}

		

		else if(Item_Renders[Item_Renders_Order] != nullptr)
		{
			Item_Renders_Death_Check = true;

			Font_Renders[Transform_2_1] = Font_Renders[Item_Renders_Order];
			Item_Renders[Transform_2_1] = Item_Renders[Item_Renders_Order];


			//Item_Renders[Item_Renders_Order]->item->Death();
			Item_Renders[Item_Renders_Order] = nullptr;
			Item_overlap.erase(Item_type[Item_Renders_Order]->Item_Oreder);
			Font_Renders[Item_Renders_Order]->Font->On(); 
			//Font_Renders[Item_Renders_Order]->Font->Death();
			Font_Renders[Item_Renders_Order] = nullptr;


		}
	



		
			
		/*if (Item_type[Item_Renders_Order]->Item_Oreder == 0 && Item_Renders[Transform_2_1] != nullptr)
		{

			Item_type[Transform_2_1]->Item_Oreder = Item_Renders[Transform_2_1]->Item_Select;
			Item_type[Transform_2_1]->Move = Item_Renders[Transform_2_1]->Move;

			remove_Order.push_back(Item_Renders_Order);


			sort(remove_Order.begin(), remove_Order.end());

			for (size_t i = 0; i < remove_Order.size() - 1; i++)
			{
				if (remove_Order[i] == remove_Order[i + 1])
				{
					remove_Order.erase(remove_Order.begin() + i);
				}
			}

			Item_type[Item_Renders_Order]->Item_Oreder = 0;
			Item_type[Item_Renders_Order]->Move = float4::ZERO;

		}*/
		//else if (Item_Renders[Transform_2_1] != nullptr)

		if(Item_Renders_Death_Check ==true)
		{
			Item_type[Transform_2_1]->Item_Oreder = Item_Renders[Transform_2_1]->Item_Select;
			Item_type[Transform_2_1]->Move = Item_Renders[Transform_2_1]->Move;

			remove_Order.push_back(Item_Renders_Order);


			sort(remove_Order.begin(), remove_Order.end());

			/*for (size_t i = 0; i < Item_type.size() - 1; i++)
			{
				if (Item_type[i] == nullptr)
				{
					Order = i;
					break;
				}
			}*/

			Item_type[Item_Renders_Order]->Item_Oreder = 0;
			Item_type[Item_Renders_Order]->Move = float4::ZERO;
			Item_Renders_Death_Check = false;
		}
				

		
			
		


	}

	if (Item_Move == true)
	{
		if (Item_Renders[Item_Renders_Order] != nullptr)
		{
			Item_Renders[Item_Renders_Order]->item->Transform.SetWorldPosition(Inventroy_informations[Inventory_pos_X][Inventory_pos_Y]->Move);
			Item_Renders[Item_Renders_Order]->Move = { Inventroy_informations[Inventory_pos_X][Inventory_pos_Y]->Move };

			Font_Renders[Item_Renders_Order]->Font->Off(); 
			Font_Renders[Item_Renders_Order]->Font->Transform.SetWorldPosition({ Inventroy_informations[Inventory_pos_X][Inventory_pos_Y]->Move.X + 20,Inventroy_informations[Inventory_pos_X][Inventory_pos_Y]->Move.Y - 5 });
			Font_Renders[Item_Renders_Order]->Move = { Inventroy_informations[Inventory_pos_X][Inventory_pos_Y]->Move.X + 20,Inventroy_informations[Inventory_pos_X][Inventory_pos_Y]->Move.Y - 5 };
		}

		


	}




	//std::shared_ptr<class GameEngineUIRenderer> AD = item;



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
	//	AD->Transform.AddWorldRotation({0.0f,1.0f* _DeltaTime,0.0f});
	//	return;
	//}
	//if (GameEngineInput::IsPress('E', this))
	//{
	//	AD->Transform.AddWorldRotation({ 0.0f,-1.0f* _DeltaTime,0.0f });
	//	return;
	//}
	////-4946.0f, -5275.0f


	//TransformData date = AD->Transform.GetConstTransformDataRef();

	////date.LocalPosition;

	////float4 WorldMousePos;

	//float4 WorldMousePos = { date.LocalPosition.X,date.LocalPosition.Y };
	//OutputDebugStringA(WorldMousePos.ToString("\n").c_str());


}
