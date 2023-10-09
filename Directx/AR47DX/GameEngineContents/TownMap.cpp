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
		BackGround = CreateComponent<GameEngineSpriteRenderer>(-100);
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
		Village_Board->Transform.SetWorldPosition({ 793,-280 });
	}

	{
		Boxs = CreateComponent<GameEngineSpriteRenderer>(0);
		Boxs->SetSprite("Village_Boxs", 0);
		Boxs->AutoSpriteSizeOn();
		Boxs->SetAutoScaleRatio(1.0f);
		Boxs->Transform.SetWorldPosition({ 502,653 });
	}

	{
		Up_Tree_01 = CreateComponent<GameEngineSpriteRenderer>(0);
		Up_Tree_01->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Up_Tree_01->AutoSpriteSizeOn();
		Up_Tree_01->SetAutoScaleRatio(2.0f);
		Up_Tree_01->Transform.SetWorldPosition({ 704,685 });
		Up_Tree_01->ChangeAnimation("Village_Tree_animation");
	}

	{
		Up_Tree_02 = CreateComponent<GameEngineSpriteRenderer>(0);
		Up_Tree_02->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Up_Tree_02->AutoSpriteSizeOn();
		Up_Tree_02->SetAutoScaleRatio(2.0f);
		Up_Tree_02->Transform.SetWorldPosition({ 906,680 });
		Up_Tree_02->ChangeAnimation("Village_Tree_animation");
	}

	{
		Road_Up_Object = CreateComponent<GameEngineSpriteRenderer>(0);
		Road_Up_Object->SetSprite("Village_Boxs", 1);
		Road_Up_Object->AutoSpriteSizeOn();
		Road_Up_Object->SetAutoScaleRatio(1.0f);
		Road_Up_Object->Transform.SetWorldPosition({ 130,605 });
	}

	{
		Up_Tree_03 = CreateComponent<GameEngineSpriteRenderer>(0);
		Up_Tree_03->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Up_Tree_03->AutoSpriteSizeOn();
		Up_Tree_03->SetAutoScaleRatio(2.0f);
		Up_Tree_03->Transform.SetWorldPosition({ 274,629 });
		Up_Tree_03->ChangeAnimation("Village_Tree_animation");
	}

	{
		Up_Tree_04 = CreateComponent<GameEngineSpriteRenderer>(0);
		Up_Tree_04->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Up_Tree_04->AutoSpriteSizeOn();
		Up_Tree_04->SetAutoScaleRatio(2.0f);
		Up_Tree_04->Transform.SetWorldPosition({ -139,581 });
		Up_Tree_04->ChangeAnimation("Village_Tree_animation");
	}

	{
		Village_Rival_House = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Rival_House->SetSprite("Village_Rival_House", 1);
		Village_Rival_House->AutoSpriteSizeOn();
		Village_Rival_House->SetAutoScaleRatio(2.0f);
		Village_Rival_House->Transform.SetWorldPosition({ -378,266 });
	}
	{
		Village_Rival_House_Roof = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Rival_House_Roof->SetSprite("Village_Rival_House", 2);
		Village_Rival_House_Roof->AutoSpriteSizeOn();
		Village_Rival_House_Roof->SetAutoScaleRatio(2.0f);
		Village_Rival_House_Roof->Transform.SetWorldPosition({ -252,330 });
	}

	{
		Big_Up_Tree_01 = CreateComponent<GameEngineSpriteRenderer>(0);
		Big_Up_Tree_01->CreateAnimation("Village_BigTree_animation", "Village_BigTree_animation", 0.1f, -1, -1, true);
		Big_Up_Tree_01->AutoSpriteSizeOn();
		Big_Up_Tree_01->SetAutoScaleRatio(2.0f);
		Big_Up_Tree_01->Transform.SetWorldPosition({ -327,549 });
		Big_Up_Tree_01->ChangeAnimation("Village_BigTree_animation");
	}
	{
		Village_Rival_Desk = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Rival_Desk->SetSprite("Village_Rival_House", 0);
		Village_Rival_Desk->AutoSpriteSizeOn();
		Village_Rival_Desk->SetAutoScaleRatio(2.0f);
		Village_Rival_Desk->Transform.SetWorldPosition({ -257,28 });
	}
	{
		Village_Rival_Flowerpot_01 = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Rival_Flowerpot_01->SetSprite("Village_Rival_Flowerpots", 0);
		Village_Rival_Flowerpot_01->AutoSpriteSizeOn();
		Village_Rival_Flowerpot_01->SetAutoScaleRatio(2.0f);
		Village_Rival_Flowerpot_01->Transform.SetWorldPosition({ -125,150 });
	}
	{
		Village_Rival_OilLamp = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Rival_OilLamp->SetSprite("Village_Object", 1);
		Village_Rival_OilLamp->AutoSpriteSizeOn();
		Village_Rival_OilLamp->SetAutoScaleRatio(2.0f);
		Village_Rival_OilLamp->Transform.SetWorldPosition({ -68,9 });
	}
	{
		Village_Rival_Flowerpot_02 = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Rival_Flowerpot_02->SetSprite("Village_Rival_Flowerpots", 1);
		Village_Rival_Flowerpot_02->AutoSpriteSizeOn();
		Village_Rival_Flowerpot_02->SetAutoScaleRatio(2.0f);
		Village_Rival_Flowerpot_02->Transform.SetWorldPosition({ -79,-67 });
	}

	{
		Village_Rival_Flowerpot_03 = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Rival_Flowerpot_03->SetSprite("Village_Rival_Flowerpots", 1);
		Village_Rival_Flowerpot_03->AutoSpriteSizeOn();
		Village_Rival_Flowerpot_03->SetAutoScaleRatio(2.0f);
		Village_Rival_Flowerpot_03->Transform.SetWorldPosition({ -79,-201 });
	}
	{
		Village_Rival_Fountain = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Rival_Fountain->CreateAnimation("Village_Rival_Fountain", "Village_Rival_Fountain", 0.1f, -1, -1, true);
		Village_Rival_Fountain->AutoSpriteSizeOn();
		Village_Rival_Fountain->SetAutoScaleRatio(2.0f);
		Village_Rival_Fountain->Transform.SetWorldPosition({ -256,-91 });
		Village_Rival_Fountain->ChangeAnimation("Village_Rival_Fountain");
	}


	{
		Middle_Tree_01 = CreateComponent<GameEngineSpriteRenderer>(0);
		Middle_Tree_01->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Middle_Tree_01->AutoSpriteSizeOn();
		Middle_Tree_01->SetAutoScaleRatio(2.0f);
		Middle_Tree_01->Transform.SetWorldPosition({ -469,-114 });
		Middle_Tree_01->ChangeAnimation("Village_Tree_animation");
	}

	{
		Middle_Tree_02 = CreateComponent<GameEngineSpriteRenderer>(0);
		Middle_Tree_02->CreateAnimation("Village_Tree_02_animation", "Village_Tree_02_animation", 0.1f, -1, -1, true);
		Middle_Tree_02->AutoSpriteSizeOn();
		Middle_Tree_02->SetAutoScaleRatio(2.0f);
		Middle_Tree_02->Transform.SetWorldPosition({ -550,59 });
		Middle_Tree_02->ChangeAnimation("Village_Tree_02_animation");
	}

	{
		Village_BigStone = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_BigStone->SetSprite("Village_BigStone", 0);
		Village_BigStone->AutoSpriteSizeOn();
		Village_BigStone->SetAutoScaleRatio(2.0f);
		Village_BigStone->Transform.SetWorldPosition({ -564,-251 });
	}

	{
		Middle_Box_01 = CreateComponent<GameEngineSpriteRenderer>(0);
		Middle_Box_01->SetSprite("Village_Object", 2);
		Middle_Box_01->AutoSpriteSizeOn();
		Middle_Box_01->SetAutoScaleRatio(2.0f);
		Middle_Box_01->Transform.SetWorldPosition({ -300,-331 });
	}

	{
		Middle_Box_02 = CreateComponent<GameEngineSpriteRenderer>(0);
		Middle_Box_02->SetSprite("Village_Object", 3);
		Middle_Box_02->AutoSpriteSizeOn();
		Middle_Box_02->SetAutoScaleRatio(2.0f);
		Middle_Box_02->Transform.SetWorldPosition({ -374,-438 });
	}

	{
		Middle_Box_03 = CreateComponent<GameEngineSpriteRenderer>(0);
		Middle_Box_03->SetSprite("Village_Object", 3);
		Middle_Box_03->AutoSpriteSizeOn();
		Middle_Box_03->SetAutoScaleRatio(2.0f);
		Middle_Box_03->Transform.SetWorldPosition({ -219,-467 });
	}


	
	{
		Big_Middle_Tree_01 = CreateComponent<GameEngineSpriteRenderer>(0);
		Big_Middle_Tree_01->CreateAnimation("Village_BigTree_animation", "Village_BigTree_animation", 0.1f, -1, -1, true);
		Big_Middle_Tree_01->AutoSpriteSizeOn();
		Big_Middle_Tree_01->SetAutoScaleRatio(2.0f);
		Big_Middle_Tree_01->Transform.SetWorldPosition({ -565,-614 });
		Big_Middle_Tree_01->ChangeAnimation("Village_BigTree_animation");
	}

	{
		Village_WitchHome = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_WitchHome->SetSprite("Village_WitchHome", 5);
		Village_WitchHome->AutoSpriteSizeOn();
		Village_WitchHome->SetAutoScaleRatio(1.0f);
		Village_WitchHome->Transform.SetWorldPosition({ -542,-801 });
	}


	
	{
		Village_Witch_Roof_old = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Witch_Roof_old->SetSprite("Village_WitchHome", 2);
		Village_Witch_Roof_old->AutoSpriteSizeOn();
		Village_Witch_Roof_old->SetAutoScaleRatio(2.0f);
		Village_Witch_Roof_old->Transform.SetWorldPosition({ -286,-668 });
	}
	{
		Village_Witch_House_old = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Witch_House_old->SetSprite("Village_WitchHome", 1);
		Village_Witch_House_old->AutoSpriteSizeOn();
		Village_Witch_House_old->SetAutoScaleRatio(2.0f);
		Village_Witch_House_old->Transform.SetWorldPosition({ -283,-808 });
	}

	{
		Village_Witch_Table_old = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Witch_Table_old->SetSprite("Village_WitchHome", 4);
		Village_Witch_Table_old->AutoSpriteSizeOn();
		Village_Witch_Table_old->SetAutoScaleRatio(2.0f);
		Village_Witch_Table_old->Transform.SetWorldPosition({ -283,-976 });
	}
	{
		Village_Witch_Storage_old = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Witch_Storage_old->SetSprite("Village_WitchHome", 3);
		Village_Witch_Storage_old->AutoSpriteSizeOn();
		Village_Witch_Storage_old->SetAutoScaleRatio(2.0f);
		Village_Witch_Storage_old->Transform.SetWorldPosition({ -544,-987 });
	}
	{
		Village_Witch_OilLamp = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Witch_OilLamp->SetSprite("Village_Object", 1);
		Village_Witch_OilLamp->AutoSpriteSizeOn();
		Village_Witch_OilLamp->SetAutoScaleRatio(2.0f);
		Village_Witch_OilLamp->Transform.SetWorldPosition({ -397,-1077 });
	}

	{
		Bottom_Box_01 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Box_01->SetSprite("Village_Object", 2);
		Bottom_Box_01->AutoSpriteSizeOn();
		Bottom_Box_01->SetAutoScaleRatio(2.0f);
		Bottom_Box_01->Transform.SetWorldPosition({ -589,-1121 });
	}
	
	{
		Bottom_Box_02 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Box_02->SetSprite("Village_Object", 2);
		Bottom_Box_02->AutoSpriteSizeOn();
		Bottom_Box_02->SetAutoScaleRatio(2.0f);
		Bottom_Box_02->Transform.SetWorldPosition({ -561,-1207 });
	}

	{
		Bottom_Box_03 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Box_03->SetSprite("Village_Object", 2);
		Bottom_Box_03->AutoSpriteSizeOn();
		Bottom_Box_03->SetAutoScaleRatio(2.0f);
		Bottom_Box_03->Transform.SetWorldPosition({ -495,-1138 });
	}


	{
		Bottom_Tree_01 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Tree_01->CreateAnimation("Village_Tree_02_animation", "Village_Tree_02_animation", 0.1f, -1, -1, true);
		Bottom_Tree_01->AutoSpriteSizeOn();
		Bottom_Tree_01->SetAutoScaleRatio(2.0f);
		Bottom_Tree_01->Transform.SetWorldPosition({ -404,-1222 });
		Bottom_Tree_01->ChangeAnimation("Village_Tree_02_animation");
	}
	{
		Bottom_Tree_02 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Tree_02->CreateAnimation("Village_Tree_02_animation", "Village_Tree_02_animation", 0.1f, -1, -1, true);
		Bottom_Tree_02->AutoSpriteSizeOn();
		Bottom_Tree_02->SetAutoScaleRatio(2.0f);
		Bottom_Tree_02->Transform.SetWorldPosition({ 23,-1311 });
		Bottom_Tree_02->ChangeAnimation("Village_Tree_02_animation");
	}
	{
		Bottom_Tree_03 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Tree_03->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Bottom_Tree_03->AutoSpriteSizeOn();
		Bottom_Tree_03->SetAutoScaleRatio(2.0f);
		Bottom_Tree_03->Transform.SetWorldPosition({ 151,-1248 });
		Bottom_Tree_03->ChangeAnimation("Village_Tree_animation");
	}

	{
		Bottom_Tree_04 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Tree_04->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Bottom_Tree_04->AutoSpriteSizeOn();
		Bottom_Tree_04->SetAutoScaleRatio(2.0f);
		Bottom_Tree_04->Transform.SetWorldPosition({ 305,-1169 });
		Bottom_Tree_04->ChangeAnimation("Village_Tree_animation");
	}

	{
		Bottom_Tree_05 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Tree_05->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Bottom_Tree_05->AutoSpriteSizeOn();
		Bottom_Tree_05->SetAutoScaleRatio(2.0f);
		Bottom_Tree_05->Transform.SetWorldPosition({ 446,-1243 });
		Bottom_Tree_05->ChangeAnimation("Village_Tree_animation");
	}

	{
		Village_House_05 = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_House_05->CreateAnimation("Village_House_05_animation", "Village_House_05_animation", 0.1f, -1, -1, true);
		Village_House_05->AutoSpriteSizeOn();
		Village_House_05->SetAutoScaleRatio(2.0f);
		Village_House_05->Transform.SetWorldPosition({ 177,-892 });
		Village_House_05->ChangeAnimation("Village_House_05_animation");
	}

	{
		Village_BigStone_02 = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_BigStone_02->SetSprite("Village_BigStone", 0);
		Village_BigStone_02->AutoSpriteSizeOn();
		Village_BigStone_02->SetAutoScaleRatio(2.0f);
		Village_BigStone_02->Transform.SetWorldPosition({ -15,-796 });
	}

	{
		Village_House_06 = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_House_06->SetSprite("Village_House_06", 0);
		Village_House_06->AutoSpriteSizeOn();
		Village_House_06->SetAutoScaleRatio(2.0f);
		Village_House_06->Transform.SetWorldPosition({ 983,-804 });
	}
	{
		Village_House_06_OilLamp = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_House_06_OilLamp->SetSprite("Village_Object", 1);
		Village_House_06_OilLamp->AutoSpriteSizeOn();
		Village_House_06_OilLamp->SetAutoScaleRatio(2.0f);
		Village_House_06_OilLamp->Transform.SetWorldPosition({ 1265,-933 });
	}
	




	{
		Bottom_Box_04 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Box_04->SetSprite("Village_Object", 2);
		Bottom_Box_04->AutoSpriteSizeOn();
		Bottom_Box_04->SetAutoScaleRatio(2.0f);
		Bottom_Box_04->Transform.SetWorldPosition({ 817,-833 });
	}

	{
		Bottom_Box_05 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Box_05->SetSprite("Village_Object", 2);
		Bottom_Box_05->AutoSpriteSizeOn();
		Bottom_Box_05->SetAutoScaleRatio(2.0f);
		Bottom_Box_05->Transform.SetWorldPosition({ 826,-988 });
	}

	{
		Bottom_Box_06 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Box_06->SetSprite("Village_Object", 2);
		Bottom_Box_06->AutoSpriteSizeOn();
		Bottom_Box_06->SetAutoScaleRatio(2.0f);
		Bottom_Box_06->Transform.SetWorldPosition({ 1163,-847 });
	}

	{
		Bottom_Tree_06 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Tree_06->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Bottom_Tree_06->AutoSpriteSizeOn();
		Bottom_Tree_06->SetAutoScaleRatio(2.0f);
		Bottom_Tree_06->Transform.SetWorldPosition({ 1310,-778 });
		Bottom_Tree_06->ChangeAnimation("Village_Tree_animation");
	}

	{
		Bottom_Tree_07 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Tree_07->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Bottom_Tree_07->AutoSpriteSizeOn();
		Bottom_Tree_07->SetAutoScaleRatio(2.0f);
		Bottom_Tree_07->Transform.SetWorldPosition({ 1388,-1276 });
		Bottom_Tree_07->ChangeAnimation("Village_Tree_animation");
	}

	{
		Bottom_Tree_08 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Tree_08->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Bottom_Tree_08->AutoSpriteSizeOn();
		Bottom_Tree_08->SetAutoScaleRatio(2.0f);
		Bottom_Tree_08->Transform.SetWorldPosition({ 878,-1188 });
		Bottom_Tree_08->ChangeAnimation("Village_Tree_animation");
	}

	{
		Village_Well_animation = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Well_animation->CreateAnimation("Village_Well_animation", "Village_Well_animation", 0.1f, -1, -1, true);
		Village_Well_animation->AutoSpriteSizeOn();
		Village_Well_animation->SetAutoScaleRatio(2.0f);
		Village_Well_animation->Transform.SetWorldPosition({ 1463,-1067 });
		Village_Well_animation->ChangeAnimation("Village_Well_animation");
	}

	{
		Bottom_Tree_09 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Tree_09->CreateAnimation("Village_Tree_02_animation", "Village_Tree_02_animation", 0.1f, -1, -1, true);
		Bottom_Tree_09->AutoSpriteSizeOn();
		Bottom_Tree_09->SetAutoScaleRatio(2.0f);
		Bottom_Tree_09->Transform.SetWorldPosition({ 1656,-1155 });
		Bottom_Tree_09->ChangeAnimation("Village_Tree_02_animation");
	}

	{
		Village_House_04 = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_House_04->SetSprite("Village_House_04", 0);
		Village_House_04->AutoSpriteSizeOn();
		Village_House_04->SetAutoScaleRatio(2.0f);
		Village_House_04->Transform.SetWorldPosition({ 1596,-753});
	}

	{
		Bottom_Tree_10 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Tree_10->CreateAnimation("Village_Tree_02_animation", "Village_Tree_02_animation", 0.1f, -1, -1, true);
		Bottom_Tree_10->AutoSpriteSizeOn();
		Bottom_Tree_10->SetAutoScaleRatio(2.0f);
		Bottom_Tree_10->Transform.SetWorldPosition({ 1897,-482 });
		Bottom_Tree_10->ChangeAnimation("Village_Tree_02_animation");
	}
	{
		Village_Blacksmith_Fence = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Blacksmith_Fence->SetSprite("Village_Blacksmith", 0);
		Village_Blacksmith_Fence->AutoSpriteSizeOn();
		Village_Blacksmith_Fence->SetAutoScaleRatio(2.0f);
		Village_Blacksmith_Fence->Transform.SetWorldPosition({ 1470,-105 });		
	}
	{
		Village_Blacksmith_Stand2_old = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Blacksmith_Stand2_old->SetSprite("Village_Blacksmith", 4);
		Village_Blacksmith_Stand2_old->AutoSpriteSizeOn();
		Village_Blacksmith_Stand2_old->SetAutoScaleRatio(2.0f);
		Village_Blacksmith_Stand2_old->Transform.SetWorldPosition({ 1390,-181 });
	}
	
	{
		Village_Blacksmith_Stand1_old = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Blacksmith_Stand1_old->SetSprite("Village_Blacksmith", 3);
		Village_Blacksmith_Stand1_old->AutoSpriteSizeOn();
		Village_Blacksmith_Stand1_old->SetAutoScaleRatio(2.0f);
		Village_Blacksmith_Stand1_old->Transform.SetWorldPosition({ 1477,-269 });
	}

	{
		Village_Blacksmith_House = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Blacksmith_House->SetSprite("Village_Blacksmith", 1);
		Village_Blacksmith_House->AutoSpriteSizeOn();
		Village_Blacksmith_House->SetAutoScaleRatio(2.0f);
		Village_Blacksmith_House->Transform.SetWorldPosition({ 1741,-313 });
	}


	{
		Village_Blacksmith_Roof_old = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Blacksmith_Roof_old->SetSprite("Village_Blacksmith", 2);
		Village_Blacksmith_Roof_old->AutoSpriteSizeOn();
		Village_Blacksmith_Roof_old->SetAutoScaleRatio(2.0f);
		Village_Blacksmith_Roof_old->Transform.SetWorldPosition({ 1717,-154 });
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



	{
		Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Player);
		Col->Transform.SetLocalScale({ 100.0f, 100.0f, 1.0f });
	}


}

void TownMap::Update(float _DeltaTime)
{
	std::shared_ptr<class GameEngineSpriteRenderer> AD  = Village_Blacksmith_Roof_old;

	
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
			GetLevel()->GetMainCamera()->Transform.AddWorldPosition({ 5.0f,0.0f });
		}

		if (GameEngineInput::IsPress('D'))
		{
			GetLevel()->GetMainCamera()->Transform.AddWorldPosition({ -5.0f,0.0f });
			return;
		}

		if (GameEngineInput::IsPress('W'))
		{
			GetLevel()->GetMainCamera()->Transform.AddWorldPosition(float4::UP *5);
			return;
		}

		if (GameEngineInput::IsPress('S'))
		{
			GetLevel()->GetMainCamera()->Transform.AddWorldPosition(float4::DOWN* 5);
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


