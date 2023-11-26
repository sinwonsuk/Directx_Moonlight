#include "PreCompile.h"
#include "Items.h"
#include "Player.h"
#include "Inventory.h"

Items::Items()
{
}

Items::~Items()
{
}

void Items::Start()
{
	item = CreateComponent<GameEngineSpriteRenderer>(100);
	item->SetSprite("Items", 0);
	item->AutoSpriteSizeOn();
	item->SetAutoScaleRatio(2.0f);
	//item->Transform.SetLocalScale({ 50.0f,50.0f });

	{
		Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Item);
		Col->Transform.SetLocalScale({ 100.0f,100.0f });
		//Col->SetCollisionType(ColType::AABBBOX2D); 
	}

	


	Event.Enter = [this](GameEngineCollision* Col, GameEngineCollision* col)
		{
			Item_Move = true;
			PrevPos = Transform.GetWorldPosition();
		};

	Event.Stay = [this](GameEngineCollision* Col, GameEngineCollision* col)
		{



		};


	Event.Exit = [this](GameEngineCollision* Col, GameEngineCollision* col)
		{

		};


	Event_Item.Enter = [this](GameEngineCollision* Col, GameEngineCollision* col)

		{

			Inventory::This_Inventory->Item_Start = true;
			Inventory::This_Inventory->Item_Sprite_Number = static_cast<int>(item_Select)+1;
			Inventory::This_Inventory->Set_Custom_Pos(Custom_Pos);	
			this->Death();
		};

	Event_Item.Stay = [this](GameEngineCollision* Col, GameEngineCollision* col)
		{
		

		};


	Event_Item.Exit = [this](GameEngineCollision* Col, GameEngineCollision* col)
		{

		};

}

void Items::Update(float _Delta)
{
	


	
	Time += _Delta;


	Random.SetSeed(Player::RandomSeed++);



	if (Item_Check == false)
	{
		
		int A = Random.RandomInt(0, 3);

		Pos_X = Random.RandomFloat(-0.5f, 0.5f);
		Pos_Y = Random.RandomFloat(-1.0f, 1.0f);
		Height = 5.0f;

		switch (item_Select)
		{
		case Item::BrokenSword:
		{
			item->SetSprite("Items", 0);
		}
		break;
		case Item::Ancient_Pot:
		{
			item->SetSprite("Items", 1);
		}
		break;
		case Item::FireJelly:
		{
			item->SetSprite("Items", 2);
		}
		break;
		case Item::crystal:
		{
			item->SetSprite("Items", 3);
		}
		break;
		case Item::Red_crystal:
		{
			item->SetSprite("Items", 4);
		}
		break;
		default:
			break;
		}
		Item_Check = true; 
	}


	if (gravity == true)
	{
		Transform.AddWorldPosition(float4{ float(Pos_X),Pos_Y }*200.0f * _Delta);
	}


	Gravity_Power += { float4::DOWN* Height* _Delta };

	if (gravity == true)
	{
		Transform.AddWorldPosition({ Gravity_Power });
		Transform.AddWorldRotation({ 0.0f,0.0f,Gravity_Power.Y });

	}



	if (Transform.GetWorldPosition().Y <= Monster_Pos.Y - 20.0f)
	{
		gravity = false;
	}

	if (gravity == false)
	{
		Col->CollisionEvent(ContentsCollisionType::Player, Event);
	}

	

	if (Item_Move == true)
	{
		float4 AD = float4{ Dir.X + 600+640, Dir.Y + 160-360 } - Transform.GetWorldPosition();
		Custom_Pos = { Dir.X + 640 ,Dir.Y - 360 };
		Transform.AddWorldPosition({ AD.NormalizeReturn() * _Delta * Speed });

		//Bag_Col->Transform.SetWorldPosition({ Dir.X + 600 + 640, Dir.Y + 160 - 360 });
		
		Col->CollisionEvent(ContentsCollisionType::Bag,Event_Item);
		
	};
		
	float4 WorldMousePos = { Dir };
    OutputDebugStringA(WorldMousePos.ToString("\n").c_str());
}
