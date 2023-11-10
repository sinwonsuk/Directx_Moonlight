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
	
	
	Item_Renders.reserve(10);
	Item_type.reserve(10);
}

void Inventory::Update(float _DeltaTime)
{
	if (Item_Start == true)
	{

		item = CreateComponent<GameEngineUIRenderer>(100);
		item->SetSprite("Items", Item_Sprite_Number-1);
		item->AutoSpriteSizeOn();
		item->SetAutoScaleRatio(2.0f);
		//object->Transform.SetWorldPosition({ Inventroy_informations[0][0]->Move });
		item->Off();

 		Item_Renders.push_back(item);

		Item_type.push_back(Item_Sprite_Number);


		

			for (size_t i = 0; i < Item_type.size()-1; i++)
			{

				if (Item_type[i] == Item_Sprite_Number)
				{
					Item_Check++;
				}
			}

			if (Item_Check == 0)
			{
				{
					std::string numberStr = std::to_string(1);
					std::shared_ptr<GameEngineUIRenderer> FontRender = CreateComponent<GameEngineUIRenderer>(101);
					FontRender->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
					FontRender->Transform.SetWorldPosition({ Inventroy_informations[Item_pos_X][Item_pos_Y]->Move.X+20,Inventroy_informations[Item_pos_X][Item_pos_Y]->Move.Y -5});
					FontRender->Off(); 
					Font_Renders.insert(std::make_pair(Item_Sprite_Number, FontRender));
				}

				Item_overlap.insert(std::make_pair(Item_Sprite_Number, float4{ Inventroy_informations[Item_pos_X][Item_pos_Y]->Move }));
				item->Transform.SetWorldPosition({ Inventroy_informations[Item_pos_X++][Item_pos_Y]->Move });
				
				

			}
			else if (Item_Check != 0)
			{
				
				if (Item_overlap.end() != Item_overlap.find(Item_Sprite_Number))
				{
					

					if (Item_Sprite_Number == 1)
					{
						std::string numberStr = std::to_string(++FontNumber);
						Font_Renders[Item_Sprite_Number]->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
					}
					else if (Item_Sprite_Number == 2)
					{
						std::string numberStr = std::to_string(++FontNumber_02);
						Font_Renders[Item_Sprite_Number]->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
					}
					else if (Item_Sprite_Number == 3)
					{
						std::string numberStr = std::to_string(++FontNumber_03);
						Font_Renders[Item_Sprite_Number]->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
					}
					else if (Item_Sprite_Number == 4)
					{
						std::string numberStr = std::to_string(++FontNumber_04);
						Font_Renders[Item_Sprite_Number]->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
					}
					else if (Item_Sprite_Number == 5)
					{
						std::string numberStr = std::to_string(++FontNumber_05);
						Font_Renders[Item_Sprite_Number]->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
					}
					item->Death();
					

				}

				Item_type.pop_back();
				Item_Renders.pop_back();
				//float4 Ad = Item_overlap[Item_Sprite_Number];
				Item_Check = 0;
			}

			else
			{
				Item_Check = 0;
			}
		
			
		Item_Start = false;
	}

	
	if (GameEngineInput::IsDown('I', this) && Inventory_Start ==false)
	{
		for (size_t i = 0; i < Item_Renders.size(); i++)
		{
			Item_Renders[i]->On();
		}

		std::map<int, std::shared_ptr<class GameEngineUIRenderer>>::iterator Start = Font_Renders.begin();
		std::map<int, std::shared_ptr<class GameEngineUIRenderer>>::iterator End = Font_Renders.end();

		for (Start; Start != End; Start++)
		{
			Start->second->On(); 
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
			Item_Renders[i]->Off();
		}

		std::map<int, std::shared_ptr<class GameEngineUIRenderer>>::iterator Start = Font_Renders.begin();
		std::map<int, std::shared_ptr<class GameEngineUIRenderer>>::iterator End = Font_Renders.end();

		for (Start; Start != End; Start++)
		{
			Start->second->Off();
		}

		Inventroy_Screen->Off();
		Inventroy_Select->Off();
		Inventory_Start = false;
		GameEngineCore::MainTime.SetAllTimeScale(1);
	}





	if (GameEngineInput::IsDown('D', this)&& Inventory_Start == true)
	{
		Inventory_pos_X += 1;


		/*if (Inventory_pos_X > 6 && Inventory_pos_Y == 0)
		{
			Inventory_pos_X = 6;
		}*/


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

		/*if (Inventory_pos_X > 4)
		{
			Inventory_pos_Y -= 1;
		}*/


		if (Inventory_pos_Y > 3)
		{
			Inventory_pos_Y = 3;
		}
	}


	Inventroy_Select->Transform.SetWorldPosition({ Inventroy_informations[Inventory_pos_X][Inventory_pos_Y]->Move });








	//std::shared_ptr<class GameEngineUIRenderer> AD = item;



	//if (GameEngineInput::IsDown('1',this) && check == false)
	//{
	//	check = true;
	//}
	//else if (GameEngineInput::IsDown('1',this) && check == true)
	//{
	//	check = false;
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
