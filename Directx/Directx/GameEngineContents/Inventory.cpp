#include "PreCompile.h"
#include "Inventory.h"

Inventory::Inventory()
{


}

Inventory::~Inventory()
{


}

void Inventory::Start()
{
	GameEngineInput::AddInputObject(this); 
	Inventroy_Screen = CreateComponent<GameEngineUIRenderer>();
	Inventroy_Screen->SetSprite("Inventory", 0);
	Inventroy_Screen->AutoSpriteSizeOn();
	Inventroy_Screen->SetAutoScaleRatio(2.0f);
	Inventroy_Screen->Off(); 

	Inventroy_Select = CreateComponent<GameEngineUIRenderer>();
	Inventroy_Select->SetSprite("Inventory", 1);
	Inventroy_Select->AutoSpriteSizeOn();
	Inventroy_Select->SetAutoScaleRatio(2.0f);
	Inventroy_Select->Off();
	







}

void Inventory::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown('I', this) && Inventory_Start ==false)
	{
		Inventroy_Screen->On(); 
		Inventroy_Select->On();
		Inventory_Start = true;
		GameEngineCore::MainTime.SetAllTimeScale(0);
	}
	else if (GameEngineInput::IsDown('I', this) && Inventory_Start == true)
	{
		Inventroy_Screen->Off();
		Inventroy_Select->Off();
		Inventory_Start = false;
		GameEngineCore::MainTime.SetAllTimeScale(1);
	}

	std::shared_ptr<class GameEngineUIRenderer> AD = Inventroy_Select;



	if (GameEngineInput::IsDown('1',this) && check == false)
	{
		check = true;
	}
	else if (GameEngineInput::IsDown('1',this) && check == true)
	{
		check = false;
	}


	if (check == true)
	{
		if (GameEngineInput::IsPress('A', this))
		{
			GetLevel()->GetMainCamera()->Transform.AddWorldPosition({ 5.0f,0.0f });
		}

		if (GameEngineInput::IsPress('D', this))
		{
			GetLevel()->GetMainCamera()->Transform.AddWorldPosition({ -5.0f,0.0f });
			return;
		}

		if (GameEngineInput::IsPress('W', this))
		{
			GetLevel()->GetMainCamera()->Transform.AddWorldPosition(float4::UP *5);
			return;
		}

		if (GameEngineInput::IsPress('S', this))
		{
			GetLevel()->GetMainCamera()->Transform.AddWorldPosition(float4::DOWN* 5);
			return;
		}
	}
	if (check == false)
	{


		if (GameEngineInput::IsPress('A', this))
		{
			AD->Transform.AddWorldPosition({ 1.0f,0.0f });
		}

		if (GameEngineInput::IsPress('D', this))
		{
			AD->Transform.AddWorldPosition({ -1.0f,0.0f });
			return;
		}

		if (GameEngineInput::IsPress('W', this))
		{
			AD->Transform.AddWorldPosition(float4::UP);
			return;
		}

		if (GameEngineInput::IsPress('S', this))
		{
			AD->Transform.AddWorldPosition(float4::DOWN);
			return;
		}
	}

	if (GameEngineInput::IsPress('Q', this))
	{
		AD->Transform.AddWorldRotation({0.0f,1.0f* _DeltaTime,0.0f});
		return;
	}
	if (GameEngineInput::IsPress('E', this))
	{
		AD->Transform.AddWorldRotation({ 0.0f,-1.0f* _DeltaTime,0.0f });
		return;
	}
	//-4946.0f, -5275.0f


	TransformData date = AD->Transform.GetConstTransformDataRef();

	//date.LocalPosition;

	//float4 WorldMousePos;

	float4 WorldMousePos = { date.LocalPosition.X,date.LocalPosition.Y };
	OutputDebugStringA(WorldMousePos.ToString("\n").c_str());


}
