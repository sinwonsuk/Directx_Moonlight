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

	{
		Village_Down_Rival_Fence = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Down_Rival_Fence->SetSprite("Village_Fance", 1);
		Village_Down_Rival_Fence->AutoSpriteSizeOn();
		Village_Down_Rival_Fence->SetAutoScaleRatio(2.0f);
		Village_Down_Rival_Fence->Transform.SetWorldPosition({ 1380,214 });
	}
	{
		Village_Up_Rival_Fence = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Up_Rival_Fence->SetSprite("Village_Fance", 3);
		Village_Up_Rival_Fence->AutoSpriteSizeOn();
		Village_Up_Rival_Fence->SetAutoScaleRatio(2.0f);	
		Village_Up_Rival_Fence->Transform.SetWorldPosition({ 1380,407 });
	}

	{
		Village_Left_Rival_Fence = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Left_Rival_Fence->SetSprite("Village_Fance", 2);
		Village_Left_Rival_Fence->AutoSpriteSizeOn();
		Village_Left_Rival_Fence->SetAutoScaleRatio(2.0f);
		Village_Left_Rival_Fence->Transform.SetWorldPosition({ 1215,299 });
	}

	{
		Village_Right_Rival_Fence = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Right_Rival_Fence->SetSprite("Village_Fance", 2);
		Village_Right_Rival_Fence->AutoSpriteSizeOn();
		Village_Right_Rival_Fence->SetAutoScaleRatio(2.0f);
		Village_Right_Rival_Fence->Transform.SetWorldPosition({ 1538,299 });
	}

	{
		Village_Right_Rival_Fence = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Right_Rival_Fence->SetSprite("Village_Fance", 2);
		Village_Right_Rival_Fence->AutoSpriteSizeOn();
		Village_Right_Rival_Fence->SetAutoScaleRatio(2.0f);
		Village_Right_Rival_Fence->Transform.SetWorldPosition({ 1538,299 });
	}

	
	{
		Will_House_Big_Tree = CreateComponent<GameEngineSpriteRenderer>(0);
		Will_House_Big_Tree->CreateAnimation("Village_BigTree_animation", "Village_BigTree_animation", 0.1f, -1, -1, true);
		Will_House_Big_Tree->AutoSpriteSizeOn();
		Will_House_Big_Tree->SetAutoScaleRatio(2.0f);
		Will_House_Big_Tree->Transform.SetWorldPosition({ 1670,396 });
		Will_House_Big_Tree->ChangeAnimation("Village_BigTree_animation");
	}


	{
		Will_House_Tree = CreateComponent<GameEngineSpriteRenderer>(0);
		Will_House_Tree->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Will_House_Tree->AutoSpriteSizeOn();
		Will_House_Tree->SetAutoScaleRatio(2.0f);
		Will_House_Tree->Transform.SetWorldPosition({ 1845,322 });
		Will_House_Tree->ChangeAnimation("Village_Tree_animation");
	}

	{
		Will_House_Tree_02 = CreateComponent<GameEngineSpriteRenderer>(0);
		Will_House_Tree_02->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Will_House_Tree_02->AutoSpriteSizeOn();
		Will_House_Tree_02->SetAutoScaleRatio(2.0f);
		Will_House_Tree_02->Transform.SetWorldPosition({ 1156,624 });
		Will_House_Tree_02->ChangeAnimation("Village_Tree_animation");
	}
	{
		Dungeon = CreateComponent<GameEngineSpriteRenderer>(0);
		Dungeon->CreateAnimation("Sign", "Sign", 0.1f, -1, -1, true);
		Dungeon->AutoSpriteSizeOn();
		Dungeon->SetAutoScaleRatio(2.0f);
		Dungeon->Transform.SetWorldPosition({ 1541,142 });
		Dungeon->ChangeAnimation("Sign");
	}
	{
		tree_stump = CreateComponent<GameEngineSpriteRenderer>(0);
		tree_stump->SetSprite("tree_stump", 0);
		tree_stump->AutoSpriteSizeOn();
		tree_stump->SetAutoScaleRatio(1.0f);
		tree_stump->Transform.SetWorldPosition({ 1647,133 });
	}

	{
		Wood_Box_Strong = CreateComponent<GameEngineSpriteRenderer>(0);
		Wood_Box_Strong->SetSprite("Village_Object", 3);
		Wood_Box_Strong->AutoSpriteSizeOn();
		Wood_Box_Strong->SetAutoScaleRatio(2.0f);
		Wood_Box_Strong->Transform.SetWorldPosition({ 647,235 });
	}

	{
		House_04 = CreateComponent<GameEngineSpriteRenderer>(0);
		House_04->SetSprite("House_04", 0);
		House_04->AutoSpriteSizeOn();
		House_04->SetAutoScaleRatio(1.0f);
		House_04->Transform.SetWorldPosition({ 437,335 });
	}

	{
		House_04_Tent = CreateComponent<GameEngineSpriteRenderer>(0);
		House_04_Tent->SetSprite("House_04", 1);
		House_04_Tent->AutoSpriteSizeOn();
		House_04_Tent->SetAutoScaleRatio(1.0f);
		House_04_Tent->Transform.SetWorldPosition({ 227,293 });
	}

	{
		Park_Right_Up_Tree = CreateComponent<GameEngineSpriteRenderer>(0);
		Park_Right_Up_Tree->CreateAnimation("Village_Tree_02_animation", "Village_Tree_02_animation", 0.1f, -1, -1, true);
		Park_Right_Up_Tree->AutoSpriteSizeOn();
		Park_Right_Up_Tree->SetAutoScaleRatio(2.0f);
		Park_Right_Up_Tree->Transform.SetWorldPosition({ 1144,-19 });
		Park_Right_Up_Tree->ChangeAnimation("Village_Tree_02_animation");
	}


	{
		Park_Middle_Up_Bench = CreateComponent<GameEngineSpriteRenderer>(0);
		Park_Middle_Up_Bench->SetSprite("Village_Bench", 0);
		Park_Middle_Up_Bench->AutoSpriteSizeOn();
		Park_Middle_Up_Bench->SetAutoScaleRatio(2.0f);
		Park_Middle_Up_Bench->Transform.SetWorldPosition({ 405,-84 });
	}



	{
		Park_Middle_Up_Tree = CreateComponent<GameEngineSpriteRenderer>(0);
		Park_Middle_Up_Tree->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Park_Middle_Up_Tree->AutoSpriteSizeOn();
		Park_Middle_Up_Tree->SetAutoScaleRatio(2.0f);
		Park_Middle_Up_Tree->Transform.SetWorldPosition({ 539,-30 });
		Park_Middle_Up_Tree->ChangeAnimation("Village_Tree_animation");
	}

	{
		Park_Middle_Up_OilLamp = CreateComponent<GameEngineSpriteRenderer>(0);
		Park_Middle_Up_OilLamp->SetSprite("Village_OilLamps", 0);
		Park_Middle_Up_OilLamp->AutoSpriteSizeOn();
		Park_Middle_Up_OilLamp->SetAutoScaleRatio(2.0f);
		Park_Middle_Up_OilLamp->Transform.SetLocalRotation({ 0.0f,180.0f,0.0f });
		Park_Middle_Up_OilLamp->Transform.SetWorldPosition({ 319,-50 });
	}


	{
		Park_Left_Up_Bench = CreateComponent<GameEngineSpriteRenderer>(0);
		Park_Left_Up_Bench->SetSprite("Village_Bench", 1);
		Park_Left_Up_Bench->AutoSpriteSizeOn();
		Park_Left_Up_Bench->SetAutoScaleRatio(2.0f);
		Park_Left_Up_Bench->Transform.SetLocalRotation({ 0.0f,180.0f,0.0f });
		Park_Left_Up_Bench->Transform.SetWorldPosition({ 228,-147 });
	}

	{
		Park_Left_Middle_Tree = CreateComponent<GameEngineSpriteRenderer>(0);
		Park_Left_Middle_Tree->CreateAnimation("Village_Tree_02_animation", "Village_Tree_02_animation", 0.1f, -1, -1, true);
		Park_Left_Middle_Tree->AutoSpriteSizeOn();
		Park_Left_Middle_Tree->SetAutoScaleRatio(2.0f);
		Park_Left_Middle_Tree->Transform.SetWorldPosition({ 228,-170 });
		Park_Left_Middle_Tree->ChangeAnimation("Village_Tree_02_animation");
	}

	{
		Park_Left_Bottom_Tree = CreateComponent<GameEngineSpriteRenderer>(0);
		Park_Left_Bottom_Tree->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Park_Left_Bottom_Tree->AutoSpriteSizeOn();
		Park_Left_Bottom_Tree->SetAutoScaleRatio(2.0f);
		Park_Left_Bottom_Tree->Transform.SetWorldPosition({ 228,-357 });
		Park_Left_Bottom_Tree->ChangeAnimation("Village_Tree_animation");
	}
	{
		Park_Middle_Left_Bench = CreateComponent<GameEngineSpriteRenderer>(0);
		Park_Middle_Left_Bench->SetSprite("Village_Bench", 1);
		Park_Middle_Left_Bench->AutoSpriteSizeOn();
		Park_Middle_Left_Bench->SetAutoScaleRatio(2.0f);
		Park_Middle_Left_Bench->Transform.SetWorldPosition({ 253,-476 });
	}

	{
		Park_Left_Bottom_OilLamp = CreateComponent<GameEngineSpriteRenderer>(0);
		Park_Left_Bottom_OilLamp->SetSprite("Village_OilLamps", 0);
		Park_Left_Bottom_OilLamp->AutoSpriteSizeOn();
		Park_Left_Bottom_OilLamp->SetAutoScaleRatio(2.0f);
		Park_Left_Bottom_OilLamp->Transform.SetLocalRotation({ 0.0f,180.0f,0.0f });
		Park_Left_Bottom_OilLamp->Transform.SetWorldPosition({ 319,-483 });
	}

	{
		Park_Left_Bottom_Bench = CreateComponent<GameEngineSpriteRenderer>(0);
		Park_Left_Bottom_Bench->SetSprite("Village_Bench", 0);
		Park_Left_Bottom_Bench->AutoSpriteSizeOn();
		Park_Left_Bottom_Bench->SetAutoScaleRatio(2.0f);
		Park_Left_Bottom_Bench->Transform.SetWorldPosition({ 405,-549 });
	}

	{
		Park_Middle_Bottom_Tree = CreateComponent<GameEngineSpriteRenderer>(0);
		Park_Middle_Bottom_Tree->CreateAnimation("Village_Tree_02_animation", "Village_Tree_02_animation", 0.1f, -1, -1, true);
		Park_Middle_Bottom_Tree->AutoSpriteSizeOn();
		Park_Middle_Bottom_Tree->SetAutoScaleRatio(2.0f);
		Park_Middle_Bottom_Tree->Transform.SetWorldPosition({ 546,-486 });
		Park_Middle_Bottom_Tree->ChangeAnimation("Village_Tree_02_animation");
	}

	{
		Park_Right_Bottom_Tree = CreateComponent<GameEngineSpriteRenderer>(0);
		Park_Right_Bottom_Tree->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Park_Right_Bottom_Tree->AutoSpriteSizeOn();
		Park_Right_Bottom_Tree->SetAutoScaleRatio(2.0f);
		Park_Right_Bottom_Tree->Transform.SetWorldPosition({ 1144,-494 });
		Park_Right_Bottom_Tree->ChangeAnimation("Village_Tree_animation");
	}


	{
		Park_Barrel = CreateComponent<GameEngineSpriteRenderer>(0);
		Park_Barrel->SetSprite("Village_Object", 0);
		Park_Barrel->AutoSpriteSizeOn();
		Park_Barrel->SetAutoScaleRatio(2.0f);
		Park_Barrel->Transform.SetWorldPosition({ 154,-83 });
	}
	{
		Village_Board = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Board->SetSprite("Village_Board", 0);
		Village_Board->AutoSpriteSizeOn();
		Village_Board->SetAutoScaleRatio(2.0f);
		Village_Board->Transform.SetWorldPosition({ 154,-83 });
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
	std::shared_ptr<class GameEngineSpriteRenderer> AD  = Village_Board;

	
	if (GameEngineInput::IsDown('1') && check == false)
	{
		check = true;
	}
	else if (GameEngineInput::IsDown('1') && check == true)
	{
		check = false;
	}


	if (check == true)
	{


		if (GameEngineInput::IsPress('A'))
		{
			GetLevel()->GetMainCamera()->Transform.AddWorldPosition({ 1.0f,0.0f });
		}

		if (GameEngineInput::IsPress('D'))
		{
			GetLevel()->GetMainCamera()->Transform.AddWorldPosition({ -1.0f,0.0f });
			return;
		}

		if (GameEngineInput::IsPress('W'))
		{
			GetLevel()->GetMainCamera()->Transform.AddWorldPosition(float4::UP);
			return;
		}

		if (GameEngineInput::IsPress('S'))
		{
			GetLevel()->GetMainCamera()->Transform.AddWorldPosition(float4::DOWN);
			return;
		}
	}
	if (check == false)
	{


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
	}

	//if (GameEngineInput::IsPress('Q'))
	//{
	//	AD->Transform.AddWorldRotation({0.0f,1.0f* _DeltaTime,0.0f});
	//	return;
	//}
	//if (GameEngineInput::IsPress('E'))
	//{
	//	AD->Transform.AddWorldRotation({ 0.0f,-1.0f* _DeltaTime,0.0f });
	//	return;
	//}

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


