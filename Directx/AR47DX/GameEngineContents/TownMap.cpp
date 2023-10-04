#include "PreCompile.h"
#include "TownMap.h"



TownMap::TownMap()
{
	
}

TownMap::~TownMap()
{
}

void TownMap::Start()
{
	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y });

	{
		BackGround = CreateComponent<GameEngineSpriteRenderer>(0);
		BackGround->SetSprite("Village",0);
		BackGround->AutoSpriteSizeOn();

		BackGround->SetAutoScaleRatio(2.0f);
	}


	{
		Will_House = CreateComponent<GameEngineSpriteRenderer>(0);
		Will_House->SetSprite("Village", 1);
		Will_House->AutoSpriteSizeOn();
		Will_House->SetAutoScaleRatio(2.0f);
		Will_House->Transform.SetWorldPosition({ 951,352 });
	}

	{
		Will_House_animation = CreateComponent<GameEngineSpriteRenderer>(0);
		Will_House_animation->CreateAnimation("Village_WillsHome_animation", "Village_WillsHome_animation", 0.1f, -1, -1, true);
		Will_House_animation->AutoSpriteSizeOn();
		Will_House_animation->SetAutoScaleRatio(2.0f);
		Will_House_animation->Transform.SetWorldPosition({ 1316,240 });
		Will_House_animation->ChangeAnimation("Village_WillsHome_animation");
	}
	
	{
		Will_House_Object = CreateComponent<GameEngineSpriteRenderer>(0);
		Will_House_Object->SetSprite("Village_Will_House_Object", 0);
		Will_House_Object->AutoSpriteSizeOn();
		Will_House_Object->SetAutoScaleRatio(1.0f);
		Will_House_Object->Transform.SetWorldPosition({ 792,145 });
	}
	{
		Will_House_OilLamp = CreateComponent<GameEngineSpriteRenderer>(0);
		Will_House_OilLamp->SetSprite("Village_Object", 1);
		Will_House_OilLamp->AutoSpriteSizeOn();
		Will_House_OilLamp->SetAutoScaleRatio(2.0f);
		Will_House_OilLamp->Transform.SetWorldPosition({ 930,158 });
	}

	{
		Will_House_OilLamp = CreateComponent<GameEngineSpriteRenderer>(0);
		Will_House_OilLamp->SetSprite("Village_Object", 1);
		Will_House_OilLamp->AutoSpriteSizeOn();
		Will_House_OilLamp->SetAutoScaleRatio(2.0f);
		Will_House_OilLamp->Transform.SetWorldPosition({ 930,158 });



	}
	{
		Will_House_sign = CreateComponent<GameEngineSpriteRenderer>(0);
		Will_House_sign->SetSprite("Village_Will_House_Object", 1);
		Will_House_sign->AutoSpriteSizeOn();
		Will_House_sign->SetAutoScaleRatio(1.0f);
		Will_House_sign->Transform.SetWorldPosition({ 1112,118 });
	}




	/*{
		Will_House_Barrel3 = CreateComponent<GameEngineSpriteRenderer>(0);
		Will_House_Barrel3->SetSprite("Village_Object", 0);
		Will_House_Barrel3->AutoSpriteSizeOn();
		Will_House_Barrel3->SetAutoScaleRatio(2.0f);
		Will_House_Barrel3->Transform.SetWorldPosition({ 951,352 });
	}

	{
		Will_House_Barrel2 = CreateComponent<GameEngineSpriteRenderer>(0);
		Will_House_Barrel2->SetSprite("Village_Object", 0);
		Will_House_Barrel2->AutoSpriteSizeOn();
		Will_House_Barrel2->SetAutoScaleRatio(2.0f);
		Will_House_Barrel2->Transform.SetWorldPosition({ 951,352 });
	}*/






}

void TownMap::Update(float _DeltaTime)
{
	std::shared_ptr<class GameEngineSpriteRenderer> AD  = Will_House_sign;




	if (GameEngineInput::IsPress('A'))
	{
		AD->Transform.AddWorldPosition({ 1.0f,0.0f });
	
	}

	if (GameEngineInput::IsPress('D'))
	{
		AD->Transform.AddWorldPosition({ -1.0f,0.0f });
		return;
	}

	if (GameEngineInput::IsPress('W'))
	{
		AD->Transform.AddWorldPosition(float4::UP);
		return;
	}

	if (GameEngineInput::IsPress('S'))
	{
		AD->Transform.AddWorldPosition(float4::DOWN);
		return;
	}

	TransformData date = AD->Transform.GetConstTransformDataRef();

	/*date.LocalPosition

	float4 WorldMousePos*/

	float4 WorldMousePos = date.WorldPosition;
	OutputDebugStringA(WorldMousePos.ToString("\n").c_str());



	//static float Time = 5.0f;
	//Time -= _DeltaTime;

	//if (nullptr != Renderer && Time <= 0.0f)
	//{
	//	Renderer->Death();
	//	Renderer = nullptr;
	//}
}


