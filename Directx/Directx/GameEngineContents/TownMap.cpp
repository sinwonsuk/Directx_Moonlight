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
		
		//Col->Transform.SetLocalScale({ 100.0f, 100.0f, 1.0f });
	}

	{
		
		BackGround = CreateComponent<GameEngineSpriteRenderer>(-100);
		BackGround->SetSprite("Village",0);
		BackGround->AutoSpriteSizeOn();
		BackGround->SetAutoScaleRatio(2.0f);
	}


	{
		

		Will_House = CreateComponent<GameEngineSpriteRenderer>();
		Will_House->SetSprite("Village", 1);
		Will_House->AutoSpriteSizeOn();
		Will_House->SetAutoScaleRatio(2.0f);
		Will_House->Transform.SetWorldPosition({ 951,352 });


		Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Will_House->GetCurSprite().Texture->GetScale()*1.8f});
		Col->Transform.SetWorldPosition(Will_House->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);
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



		Col_02 = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col_02->Transform.SetLocalScale({ Will_House_Object->GetCurSprite().Texture->GetScale() * 0.8f });
		Col_02->Transform.SetWorldPosition(Will_House_Object->Transform.GetWorldPosition());
		Col_02->SetCollisionType(ColType::AABBBOX2D);
	}
	{

		Will_House_OilLamp = CreateComponent<GameEngineSpriteRenderer>(0);
		Will_House_OilLamp->SetSprite("Village_Object", 1);
		Will_House_OilLamp->AutoSpriteSizeOn();
		Will_House_OilLamp->SetAutoScaleRatio(2.0f);
		Will_House_OilLamp->Transform.SetWorldPosition({ 930,158 });




		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Will_House_OilLamp->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Will_House_OilLamp->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);


	}

	
	{
		Will_House_sign = CreateComponent<GameEngineSpriteRenderer>(0);
		Will_House_sign->SetSprite("Village_Will_House_Object", 1);
		Will_House_sign->AutoSpriteSizeOn();
		Will_House_sign->SetAutoScaleRatio(1.0f);
		Will_House_sign->Transform.SetWorldPosition({ 1112,118 });


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Will_House_sign->GetCurSprite().Texture->GetScale() * 1.0f });
		Col->Transform.SetWorldPosition(Will_House_sign->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);

	}

	{
		Village_Down_Rival_Fence = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Down_Rival_Fence->SetSprite("Village_Fance", 1);
		Village_Down_Rival_Fence->AutoSpriteSizeOn();
		Village_Down_Rival_Fence->SetAutoScaleRatio(2.0f);
		Village_Down_Rival_Fence->Transform.SetWorldPosition({ 1380,214 });

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Village_Down_Rival_Fence->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Village_Down_Rival_Fence->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);
	}
	{
		Village_Up_Rival_Fence = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Up_Rival_Fence->SetSprite("Village_Fance", 3);
		Village_Up_Rival_Fence->AutoSpriteSizeOn();
		Village_Up_Rival_Fence->SetAutoScaleRatio(2.0f);	
		Village_Up_Rival_Fence->Transform.SetWorldPosition({ 1380,407 });

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Village_Up_Rival_Fence->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Village_Up_Rival_Fence->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);


	}

	{
		Village_Left_Rival_Fence = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Left_Rival_Fence->SetSprite("Village_Fance", 2);
		Village_Left_Rival_Fence->AutoSpriteSizeOn();
		Village_Left_Rival_Fence->SetAutoScaleRatio(2.0f);
		Village_Left_Rival_Fence->Transform.SetWorldPosition({ 1215,299 });


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Village_Left_Rival_Fence->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Village_Left_Rival_Fence->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);

	}

	{
		Village_Right_Rival_Fence = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Right_Rival_Fence->SetSprite("Village_Fance", 2);
		Village_Right_Rival_Fence->AutoSpriteSizeOn();
		Village_Right_Rival_Fence->SetAutoScaleRatio(2.0f);
		Village_Right_Rival_Fence->Transform.SetWorldPosition({ 1538,299 });

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Village_Right_Rival_Fence->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Village_Right_Rival_Fence->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);


	}

	/*{
		Village_Right_Rival_Fence = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Right_Rival_Fence->SetSprite("Village_Fance", 2);
		Village_Right_Rival_Fence->AutoSpriteSizeOn();
		Village_Right_Rival_Fence->SetAutoScaleRatio(2.0f);
		Village_Right_Rival_Fence->Transform.SetWorldPosition({ 1538,299 });

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Village_Right_Rival_Fence->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Village_Right_Rival_Fence->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);


	}*/

	{
		Will_House_Big_Tree = CreateComponent<GameEngineSpriteRenderer>(0);
		Will_House_Big_Tree->CreateAnimation("Village_BigTree_animation", "Village_BigTree_animation", 0.1f, -1, -1, true);
		Will_House_Big_Tree->AutoSpriteSizeOn();
		Will_House_Big_Tree->SetAutoScaleRatio(2.0f);
		Will_House_Big_Tree->Transform.SetWorldPosition({ 1670,396 });
		Will_House_Big_Tree->ChangeAnimation("Village_BigTree_animation");


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Will_House_Big_Tree->GetCurSprite().Texture->GetScale() * 0.3f });
		Col->Transform.SetWorldPosition({ Will_House_Big_Tree->Transform.GetWorldPosition().X-30.0f,Will_House_Big_Tree->Transform.GetWorldPosition().Y-60.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);

	}
	
	

	//////////////////
	{
		Will_House_Tree = CreateComponent<GameEngineSpriteRenderer>(0);
		Will_House_Tree->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Will_House_Tree->AutoSpriteSizeOn();
		Will_House_Tree->SetAutoScaleRatio(2.0f);
		Will_House_Tree->Transform.SetWorldPosition({ 1845,322 });
		Will_House_Tree->ChangeAnimation("Village_Tree_animation");


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Will_House_Tree->GetCurSprite().Texture->GetScale() * 0.5f });
		Col->Transform.SetWorldPosition({ Will_House_Tree->Transform.GetWorldPosition().X - 30.0f,Will_House_Big_Tree->Transform.GetWorldPosition().Y - 130.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);


	}

	
	{
		Dungeon = CreateComponent<GameEngineSpriteRenderer>(0);
		Dungeon->CreateAnimation("Sign", "Sign", 0.1f, -1, -1, true);
		Dungeon->AutoSpriteSizeOn();
		Dungeon->SetAutoScaleRatio(2.0f);
		Dungeon->Transform.SetWorldPosition({ 1541,142 });
		Dungeon->ChangeAnimation("Sign");

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Dungeon->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Dungeon->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);


	}
	{
		tree_stump = CreateComponent<GameEngineSpriteRenderer>(0);
		tree_stump->SetSprite("tree_stump", 0);
		tree_stump->AutoSpriteSizeOn();
		tree_stump->SetAutoScaleRatio(1.0f);
		tree_stump->Transform.SetWorldPosition({ 1647,133 });


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ tree_stump->GetCurSprite().Texture->GetScale() * 1.0f });
		Col->Transform.SetWorldPosition(tree_stump->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);

	}

	{
		Wood_Box_Strong = CreateComponent<GameEngineSpriteRenderer>(0);
		Wood_Box_Strong->SetSprite("Village_Object", 3);
		Wood_Box_Strong->AutoSpriteSizeOn();
		Wood_Box_Strong->SetAutoScaleRatio(2.0f);
		Wood_Box_Strong->Transform.SetWorldPosition({ 647,235 });


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Wood_Box_Strong->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Wood_Box_Strong->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);


	}

	{
		House_04 = CreateComponent<GameEngineSpriteRenderer>(0);
		House_04->SetSprite("House_04", 0);
		House_04->AutoSpriteSizeOn();
		House_04->SetAutoScaleRatio(1.0f);
		House_04->Transform.SetWorldPosition({ 437,335 });



		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ House_04->GetCurSprite().Texture->GetScale() * 1.0f });
		Col->Transform.SetWorldPosition(House_04->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);


	}

	{
		House_04_Tent = CreateComponent<GameEngineSpriteRenderer>(0);
		House_04_Tent->SetSprite("House_04", 1);
		House_04_Tent->AutoSpriteSizeOn();
		House_04_Tent->SetAutoScaleRatio(1.0f);
		House_04_Tent->Transform.SetWorldPosition({ 227,293 });


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ House_04_Tent->GetCurSprite().Texture->GetScale() * 1.0f });
		Col->Transform.SetWorldPosition(House_04_Tent->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);
	}

	{
		Park_Right_Up_Tree = CreateComponent<GameEngineSpriteRenderer>(0);
		Park_Right_Up_Tree->CreateAnimation("Village_Tree_02_animation", "Village_Tree_02_animation", 0.1f, -1, -1, true);
		Park_Right_Up_Tree->AutoSpriteSizeOn();
		Park_Right_Up_Tree->SetAutoScaleRatio(2.0f);
		Park_Right_Up_Tree->Transform.SetWorldPosition({ 1144,-19 });
		Park_Right_Up_Tree->ChangeAnimation("Village_Tree_02_animation");


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Park_Right_Up_Tree->GetCurSprite().Texture->GetScale() * 0.5f });
		Col->Transform.SetWorldPosition({ Park_Right_Up_Tree->Transform.GetWorldPosition().X - 40.0f,Park_Right_Up_Tree->Transform.GetWorldPosition().Y - 60.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);

	}


	{
		Park_Middle_Up_Bench = CreateComponent<GameEngineSpriteRenderer>(0);
		Park_Middle_Up_Bench->SetSprite("Village_Bench", 0);
		Park_Middle_Up_Bench->AutoSpriteSizeOn();
		Park_Middle_Up_Bench->SetAutoScaleRatio(2.0f);
		Park_Middle_Up_Bench->Transform.SetWorldPosition({ 405,-84 });



		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Park_Middle_Up_Bench->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Park_Middle_Up_Bench->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);


	}



	{
		Park_Middle_Up_Tree = CreateComponent<GameEngineSpriteRenderer>(0);
		Park_Middle_Up_Tree->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Park_Middle_Up_Tree->AutoSpriteSizeOn();
		Park_Middle_Up_Tree->SetAutoScaleRatio(2.0f);
		Park_Middle_Up_Tree->Transform.SetWorldPosition({ 539,-30 });
		Park_Middle_Up_Tree->ChangeAnimation("Village_Tree_animation");


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Park_Middle_Up_Tree->GetCurSprite().Texture->GetScale() * 0.5f });
		Col->Transform.SetWorldPosition({ Park_Middle_Up_Tree->Transform.GetWorldPosition().X - 30.0f,Park_Middle_Up_Tree->Transform.GetWorldPosition().Y - 60.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);
	}

	{
		Park_Middle_Up_OilLamp = CreateComponent<GameEngineSpriteRenderer>(0);
		Park_Middle_Up_OilLamp->SetSprite("Village_OilLamps", 0);
		Park_Middle_Up_OilLamp->AutoSpriteSizeOn();
		Park_Middle_Up_OilLamp->SetAutoScaleRatio(2.0f);
		Park_Middle_Up_OilLamp->Transform.SetLocalRotation({ 0.0f,180.0f,0.0f });
		Park_Middle_Up_OilLamp->Transform.SetWorldPosition({ 319,-50 });


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Park_Middle_Up_OilLamp->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Park_Middle_Up_OilLamp->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);
	}


	{
		Park_Left_Up_Bench = CreateComponent<GameEngineSpriteRenderer>(0);
		Park_Left_Up_Bench->SetSprite("Village_Bench", 1);
		Park_Left_Up_Bench->AutoSpriteSizeOn();
		Park_Left_Up_Bench->SetAutoScaleRatio(2.0f);
		Park_Left_Up_Bench->Transform.SetLocalRotation({ 0.0f,180.0f,0.0f });
		Park_Left_Up_Bench->Transform.SetWorldPosition({ 228,-147 });


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalRotation({ 0.0f,0.0f,45.0f });
		Col->Transform.SetLocalScale({100.0f,40.0f});
		Col->Transform.SetWorldPosition(Park_Left_Up_Bench->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::OBBBOX2D);

	}

	{
		Park_Left_Middle_Tree = CreateComponent<GameEngineSpriteRenderer>(0);
		Park_Left_Middle_Tree->CreateAnimation("Village_Tree_02_animation", "Village_Tree_02_animation", 0.1f, -1, -1, true);
		Park_Left_Middle_Tree->AutoSpriteSizeOn();
		Park_Left_Middle_Tree->SetAutoScaleRatio(2.0f);
		Park_Left_Middle_Tree->Transform.SetWorldPosition({ 228,-170 });
		Park_Left_Middle_Tree->ChangeAnimation("Village_Tree_02_animation");


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Park_Left_Middle_Tree->GetCurSprite().Texture->GetScale() * 0.5f });
		Col->Transform.SetWorldPosition({ Park_Left_Middle_Tree->Transform.GetWorldPosition().X - 40.0f,Park_Left_Middle_Tree->Transform.GetWorldPosition().Y - 60.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);


	}

	{
		Park_Left_Bottom_Tree = CreateComponent<GameEngineSpriteRenderer>(0);
		Park_Left_Bottom_Tree->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Park_Left_Bottom_Tree->AutoSpriteSizeOn();
		Park_Left_Bottom_Tree->SetAutoScaleRatio(2.0f);
		Park_Left_Bottom_Tree->Transform.SetWorldPosition({ 228,-357 });
		Park_Left_Bottom_Tree->ChangeAnimation("Village_Tree_animation");


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Park_Left_Bottom_Tree->GetCurSprite().Texture->GetScale() * 0.5f });
		Col->Transform.SetWorldPosition({ Park_Left_Bottom_Tree->Transform.GetWorldPosition().X - 40.0f,Park_Left_Bottom_Tree->Transform.GetWorldPosition().Y - 60.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);



	}
	{
		Park_Middle_Left_Bench = CreateComponent<GameEngineSpriteRenderer>(0);
		Park_Middle_Left_Bench->SetSprite("Village_Bench", 1);
		Park_Middle_Left_Bench->AutoSpriteSizeOn();
		Park_Middle_Left_Bench->SetAutoScaleRatio(2.0f);
		Park_Middle_Left_Bench->Transform.SetWorldPosition({ 253,-476 });


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalRotation({ 0.0f,0.0f,-45.0f });
		Col->Transform.SetLocalScale({ 100.0f,40.0f });
		Col->Transform.SetWorldPosition(Park_Middle_Left_Bench->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::OBBBOX2D);

	}

	{
		Park_Left_Bottom_OilLamp = CreateComponent<GameEngineSpriteRenderer>(0);
		Park_Left_Bottom_OilLamp->SetSprite("Village_OilLamps", 0);
		Park_Left_Bottom_OilLamp->AutoSpriteSizeOn();
		Park_Left_Bottom_OilLamp->SetAutoScaleRatio(2.0f);
		Park_Left_Bottom_OilLamp->Transform.SetLocalRotation({ 0.0f,180.0f,0.0f });
		Park_Left_Bottom_OilLamp->Transform.SetWorldPosition({ 319,-483 });

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Park_Left_Bottom_OilLamp->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Park_Left_Bottom_OilLamp->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);

	}

	{
		Park_Left_Bottom_Bench = CreateComponent<GameEngineSpriteRenderer>(0);
		Park_Left_Bottom_Bench->SetSprite("Village_Bench", 0);
		Park_Left_Bottom_Bench->AutoSpriteSizeOn();
		Park_Left_Bottom_Bench->SetAutoScaleRatio(2.0f);
		Park_Left_Bottom_Bench->Transform.SetWorldPosition({ 405,-549 });


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Park_Left_Bottom_Bench->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Park_Left_Bottom_Bench->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);

	}

	{
		Park_Middle_Bottom_Tree = CreateComponent<GameEngineSpriteRenderer>(0);
		Park_Middle_Bottom_Tree->CreateAnimation("Village_Tree_02_animation", "Village_Tree_02_animation", 0.1f, -1, -1, true);
		Park_Middle_Bottom_Tree->AutoSpriteSizeOn();
		Park_Middle_Bottom_Tree->SetAutoScaleRatio(2.0f);
		Park_Middle_Bottom_Tree->Transform.SetWorldPosition({ 546,-486 });
		Park_Middle_Bottom_Tree->ChangeAnimation("Village_Tree_02_animation");


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Park_Middle_Bottom_Tree->GetCurSprite().Texture->GetScale() * 0.5f });
		Col->Transform.SetWorldPosition({ Park_Middle_Bottom_Tree->Transform.GetWorldPosition().X - 40.0f,Park_Middle_Bottom_Tree->Transform.GetWorldPosition().Y - 60.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);


	}

	{
		Park_Right_Bottom_Tree = CreateComponent<GameEngineSpriteRenderer>(0);
		Park_Right_Bottom_Tree->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Park_Right_Bottom_Tree->AutoSpriteSizeOn();
		Park_Right_Bottom_Tree->SetAutoScaleRatio(2.0f);
		Park_Right_Bottom_Tree->Transform.SetWorldPosition({ 1144,-494 });
		Park_Right_Bottom_Tree->ChangeAnimation("Village_Tree_animation");


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Park_Right_Bottom_Tree->GetCurSprite().Texture->GetScale() * 0.5f });
		Col->Transform.SetWorldPosition({ Park_Right_Bottom_Tree->Transform.GetWorldPosition().X - 40.0f,Park_Right_Bottom_Tree->Transform.GetWorldPosition().Y - 60.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);


	}


	{
		Park_Barrel = CreateComponent<GameEngineSpriteRenderer>(0);
		Park_Barrel->SetSprite("Village_Object", 0);
		Park_Barrel->AutoSpriteSizeOn();
		Park_Barrel->SetAutoScaleRatio(2.0f);
		Park_Barrel->Transform.SetWorldPosition({ 154,-83 });


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Park_Barrel->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Park_Barrel->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);

	}
	{
		Village_Board = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Board->SetSprite("Village_Board", 0);
		Village_Board->AutoSpriteSizeOn();
		Village_Board->SetAutoScaleRatio(2.0f);
		Village_Board->Transform.SetWorldPosition({ 793,-280 });



		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Village_Board->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Village_Board->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);

	}

	{
		Boxs = CreateComponent<GameEngineSpriteRenderer>(0);
		Boxs->SetSprite("Village_Boxs", 0);
		Boxs->AutoSpriteSizeOn();
		Boxs->SetAutoScaleRatio(1.0f);
		Boxs->Transform.SetWorldPosition({ 502,653 });


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Boxs->GetCurSprite().Texture->GetScale() * 1.0f });
		Col->Transform.SetWorldPosition(Boxs->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);

	}

	{
		Up_Tree_01 = CreateComponent<GameEngineSpriteRenderer>(0);
		Up_Tree_01->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Up_Tree_01->AutoSpriteSizeOn();
		Up_Tree_01->SetAutoScaleRatio(2.0f);
		Up_Tree_01->Transform.SetWorldPosition({ 704,685 });
		Up_Tree_01->ChangeAnimation("Village_Tree_animation");


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Up_Tree_01->GetCurSprite().Texture->GetScale() * 0.5f });
		Col->Transform.SetWorldPosition({ Up_Tree_01->Transform.GetWorldPosition().X - 35.0f,Up_Tree_01->Transform.GetWorldPosition().Y - 60.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);

	}

	{
		Up_Tree_02 = CreateComponent<GameEngineSpriteRenderer>(0);
		Up_Tree_02->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Up_Tree_02->AutoSpriteSizeOn();
		Up_Tree_02->SetAutoScaleRatio(2.0f);
		Up_Tree_02->Transform.SetWorldPosition({ 906,680 });
		Up_Tree_02->ChangeAnimation("Village_Tree_animation");

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Up_Tree_02->GetCurSprite().Texture->GetScale() * 0.5f });
		Col->Transform.SetWorldPosition({ Up_Tree_02->Transform.GetWorldPosition().X - 35.0f,Up_Tree_02->Transform.GetWorldPosition().Y - 60.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);


	}

	{
		Road_Up_Object = CreateComponent<GameEngineSpriteRenderer>(0);
		Road_Up_Object->SetSprite("Village_Boxs", 1);
		Road_Up_Object->AutoSpriteSizeOn();
		Road_Up_Object->SetAutoScaleRatio(1.0f);
		Road_Up_Object->Transform.SetWorldPosition({ 130,605 });


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Road_Up_Object->GetCurSprite().Texture->GetScale() * 1.0f });
		Col->Transform.SetWorldPosition(Road_Up_Object->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);

	}

	{
		Up_Tree_03 = CreateComponent<GameEngineSpriteRenderer>(0);
		Up_Tree_03->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Up_Tree_03->AutoSpriteSizeOn();
		Up_Tree_03->SetAutoScaleRatio(2.0f);
		Up_Tree_03->Transform.SetWorldPosition({ 274,629 });
		Up_Tree_03->ChangeAnimation("Village_Tree_animation");

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Up_Tree_03->GetCurSprite().Texture->GetScale() * 0.5f });
		Col->Transform.SetWorldPosition({ Up_Tree_03->Transform.GetWorldPosition().X - 35.0f,Up_Tree_03->Transform.GetWorldPosition().Y - 60.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);
	}

	{
		Up_Tree_04 = CreateComponent<GameEngineSpriteRenderer>(0);
		Up_Tree_04->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Up_Tree_04->AutoSpriteSizeOn();
		Up_Tree_04->SetAutoScaleRatio(2.0f);
		Up_Tree_04->Transform.SetWorldPosition({ -139,581 });
		Up_Tree_04->ChangeAnimation("Village_Tree_animation");


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Up_Tree_04->GetCurSprite().Texture->GetScale() * 0.5f });
		Col->Transform.SetWorldPosition({ Up_Tree_04->Transform.GetWorldPosition().X - 35.0f,Up_Tree_04->Transform.GetWorldPosition().Y - 60.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);

	}

	{
		Village_Rival_House = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Rival_House->SetSprite("Village_Rival_House", 1);
		Village_Rival_House->AutoSpriteSizeOn();
		Village_Rival_House->SetAutoScaleRatio(2.0f);
		Village_Rival_House->Transform.SetWorldPosition({ -378,266 });


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ 300.0f,320.0f });
		Col->Transform.SetWorldPosition({ Village_Rival_House->Transform.GetWorldPosition().X+100.0f, Village_Rival_House->Transform.GetWorldPosition().Y+30.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);

	}
	{
		Village_Rival_House_Roof = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Rival_House_Roof->SetSprite("Village_Rival_House", 2);
		Village_Rival_House_Roof->AutoSpriteSizeOn();
		Village_Rival_House_Roof->SetAutoScaleRatio(2.0f);
		Village_Rival_House_Roof->Transform.SetWorldPosition({ -252,330 });

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ 300.0f,250.0f });
		Col->Transform.SetWorldPosition({ Village_Rival_House->Transform.GetWorldPosition().X - 180.0f, Village_Rival_House->Transform.GetWorldPosition().Y + 30.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);

	}

	{
		Big_Up_Tree_01 = CreateComponent<GameEngineSpriteRenderer>(0);
		Big_Up_Tree_01->CreateAnimation("Village_BigTree_animation", "Village_BigTree_animation", 0.1f, -1, -1, true);
		Big_Up_Tree_01->AutoSpriteSizeOn();
		Big_Up_Tree_01->SetAutoScaleRatio(2.0f);
		Big_Up_Tree_01->Transform.SetWorldPosition({ -327,549 });
		Big_Up_Tree_01->ChangeAnimation("Village_BigTree_animation");


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Big_Up_Tree_01->GetCurSprite().Texture->GetScale() * 0.3f });
		Col->Transform.SetWorldPosition({ Big_Up_Tree_01->Transform.GetWorldPosition().X - 30.0f,Big_Up_Tree_01->Transform.GetWorldPosition().Y - 60.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);



	}
	{
		Village_Rival_Desk = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Rival_Desk->SetSprite("Village_Rival_House", 0);
		Village_Rival_Desk->AutoSpriteSizeOn();
		Village_Rival_Desk->SetAutoScaleRatio(2.0f);
		Village_Rival_Desk->Transform.SetWorldPosition({ -257,28 });


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ 250.0f,70.0f });
		Col->Transform.SetWorldPosition(Village_Rival_Desk->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);



	}
	{
		Village_Rival_Flowerpot_01 = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Rival_Flowerpot_01->SetSprite("Village_Rival_Flowerpots", 0);
		Village_Rival_Flowerpot_01->AutoSpriteSizeOn();
		Village_Rival_Flowerpot_01->SetAutoScaleRatio(2.0f);
		Village_Rival_Flowerpot_01->Transform.SetWorldPosition({ -125,150 });

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Village_Rival_Flowerpot_01->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Village_Rival_Flowerpot_01->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);


	}
	{
		Village_Rival_OilLamp = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Rival_OilLamp->SetSprite("Village_Object", 1);
		Village_Rival_OilLamp->AutoSpriteSizeOn();
		Village_Rival_OilLamp->SetAutoScaleRatio(2.0f);
		Village_Rival_OilLamp->Transform.SetWorldPosition({ -68,9 });


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Village_Rival_OilLamp->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Village_Rival_OilLamp->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);


	}
	{
		Village_Rival_Flowerpot_02 = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Rival_Flowerpot_02->SetSprite("Village_Rival_Flowerpots", 1);
		Village_Rival_Flowerpot_02->AutoSpriteSizeOn();
		Village_Rival_Flowerpot_02->SetAutoScaleRatio(2.0f);
		Village_Rival_Flowerpot_02->Transform.SetWorldPosition({ -79,-67 });


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Village_Rival_Flowerpot_02->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Village_Rival_Flowerpot_02->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);
	}

	{
		Village_Rival_Flowerpot_03 = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Rival_Flowerpot_03->SetSprite("Village_Rival_Flowerpots", 1);
		Village_Rival_Flowerpot_03->AutoSpriteSizeOn();
		Village_Rival_Flowerpot_03->SetAutoScaleRatio(2.0f);
		Village_Rival_Flowerpot_03->Transform.SetWorldPosition({ -79,-201 });



		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Village_Rival_Flowerpot_03->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Village_Rival_Flowerpot_03->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);

	}
	{
		Village_Rival_Fountain = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Rival_Fountain->CreateAnimation("Village_Rival_Fountain", "Village_Rival_Fountain", 0.1f, -1, -1, true);
		Village_Rival_Fountain->AutoSpriteSizeOn();
		Village_Rival_Fountain->SetAutoScaleRatio(2.0f);
		Village_Rival_Fountain->Transform.SetWorldPosition({ -256,-91 });
		Village_Rival_Fountain->ChangeAnimation("Village_Rival_Fountain");


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Village_Rival_Fountain->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Village_Rival_Fountain->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);

	}


	{
		Middle_Tree_01 = CreateComponent<GameEngineSpriteRenderer>(0);
		Middle_Tree_01->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Middle_Tree_01->AutoSpriteSizeOn();
		Middle_Tree_01->SetAutoScaleRatio(2.0f);
		Middle_Tree_01->Transform.SetWorldPosition({ -469,-114 });
		Middle_Tree_01->ChangeAnimation("Village_Tree_animation");


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Middle_Tree_01->GetCurSprite().Texture->GetScale() * 0.5f });
		Col->Transform.SetWorldPosition({ Middle_Tree_01->Transform.GetWorldPosition().X - 35.0f,Middle_Tree_01->Transform.GetWorldPosition().Y - 60.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);

	}

	{
		Middle_Tree_02 = CreateComponent<GameEngineSpriteRenderer>(0);
		Middle_Tree_02->CreateAnimation("Village_Tree_02_animation", "Village_Tree_02_animation", 0.1f, -1, -1, true);
		Middle_Tree_02->AutoSpriteSizeOn();
		Middle_Tree_02->SetAutoScaleRatio(2.0f);
		Middle_Tree_02->Transform.SetWorldPosition({ -550,59 });
		Middle_Tree_02->ChangeAnimation("Village_Tree_02_animation");


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Middle_Tree_02->GetCurSprite().Texture->GetScale() * 0.5f });
		Col->Transform.SetWorldPosition({ Middle_Tree_02->Transform.GetWorldPosition().X - 40.0f,Middle_Tree_02->Transform.GetWorldPosition().Y - 60.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);


	}

	{
		Village_BigStone = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_BigStone->SetSprite("Village_BigStone", 0);
		Village_BigStone->AutoSpriteSizeOn();
		Village_BigStone->SetAutoScaleRatio(2.0f);
		Village_BigStone->Transform.SetWorldPosition({ -564,-251 });



		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Village_BigStone->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Village_BigStone->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);

	}

	{
		Middle_Box_01 = CreateComponent<GameEngineSpriteRenderer>(0);
		Middle_Box_01->SetSprite("Village_Object", 2);
		Middle_Box_01->AutoSpriteSizeOn();
		Middle_Box_01->SetAutoScaleRatio(2.0f);
		Middle_Box_01->Transform.SetWorldPosition({ -300,-331 });

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Middle_Box_01->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Middle_Box_01->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);

	}

	{
		Middle_Box_02 = CreateComponent<GameEngineSpriteRenderer>(0);
		Middle_Box_02->SetSprite("Village_Object", 3);
		Middle_Box_02->AutoSpriteSizeOn();
		Middle_Box_02->SetAutoScaleRatio(2.0f);
		Middle_Box_02->Transform.SetWorldPosition({ -374,-438 });


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Middle_Box_02->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Middle_Box_02->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);

	}

	{
		Middle_Box_03 = CreateComponent<GameEngineSpriteRenderer>(0);
		Middle_Box_03->SetSprite("Village_Object", 3);
		Middle_Box_03->AutoSpriteSizeOn();
		Middle_Box_03->SetAutoScaleRatio(2.0f);
		Middle_Box_03->Transform.SetWorldPosition({ -219,-467 });

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Middle_Box_03->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Middle_Box_03->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);
	}


	
	{
		Big_Middle_Tree_01 = CreateComponent<GameEngineSpriteRenderer>(0);
		Big_Middle_Tree_01->CreateAnimation("Village_BigTree_animation", "Village_BigTree_animation", 0.1f, -1, -1, true);
		Big_Middle_Tree_01->AutoSpriteSizeOn();
		Big_Middle_Tree_01->SetAutoScaleRatio(2.0f);
		Big_Middle_Tree_01->Transform.SetWorldPosition({ -565,-614 });
		Big_Middle_Tree_01->ChangeAnimation("Village_BigTree_animation");

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Big_Middle_Tree_01->GetCurSprite().Texture->GetScale() * 0.3f });
		Col->Transform.SetWorldPosition({ Big_Middle_Tree_01->Transform.GetWorldPosition().X - 30.0f,Big_Middle_Tree_01->Transform.GetWorldPosition().Y - 60.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);



	}

	{
		Village_WitchHome = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_WitchHome->SetSprite("Village_WitchHome", 5);
		Village_WitchHome->AutoSpriteSizeOn();
		Village_WitchHome->SetAutoScaleRatio(1.0f);
		Village_WitchHome->Transform.SetWorldPosition({ -542,-801 });


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Village_WitchHome->GetCurSprite().Texture->GetScale() * 1.0f });
		Col->Transform.SetWorldPosition(Village_WitchHome->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);

	}


	
	{
		Village_Witch_Roof_old = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Witch_Roof_old->SetSprite("Village_WitchHome", 2);
		Village_Witch_Roof_old->AutoSpriteSizeOn();
		Village_Witch_Roof_old->SetAutoScaleRatio(2.0f);
		Village_Witch_Roof_old->Transform.SetWorldPosition({ -286,-668 });


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ 300,400.0f });
		Col->Transform.SetWorldPosition({ Village_Witch_Roof_old->Transform.GetWorldPosition().X,Village_Witch_Roof_old->Transform.GetWorldPosition().Y - 200.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);

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


		/*std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Village_WitchHome->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Village_WitchHome->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);*/

	}
	{
		Village_Witch_Storage_old = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Witch_Storage_old->SetSprite("Village_WitchHome", 3);
		Village_Witch_Storage_old->AutoSpriteSizeOn();
		Village_Witch_Storage_old->SetAutoScaleRatio(2.0f);
		Village_Witch_Storage_old->Transform.SetWorldPosition({ -544,-987 });

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Village_Witch_Storage_old->GetCurSprite().Texture->GetScale() * 1.0f });
		Col->Transform.SetWorldPosition(Village_Witch_Storage_old->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);
	}
	{
		Village_Witch_OilLamp = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Witch_OilLamp->SetSprite("Village_Object", 1);
		Village_Witch_OilLamp->AutoSpriteSizeOn();
		Village_Witch_OilLamp->SetAutoScaleRatio(2.0f);
		Village_Witch_OilLamp->Transform.SetWorldPosition({ -397,-1077 });


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Village_Witch_OilLamp->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Village_Witch_OilLamp->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);


	}

	{
		Bottom_Box_01 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Box_01->SetSprite("Village_Object", 2);
		Bottom_Box_01->AutoSpriteSizeOn();
		Bottom_Box_01->SetAutoScaleRatio(2.0f);
		Bottom_Box_01->Transform.SetWorldPosition({ -589,-1121 });

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Bottom_Box_01->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Bottom_Box_01->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);

	}
	
	{
		Bottom_Box_02 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Box_02->SetSprite("Village_Object", 2);
		Bottom_Box_02->AutoSpriteSizeOn();
		Bottom_Box_02->SetAutoScaleRatio(2.0f);
		Bottom_Box_02->Transform.SetWorldPosition({ -561,-1207 });

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Bottom_Box_02->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Bottom_Box_02->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);

	}

	{
		Bottom_Box_03 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Box_03->SetSprite("Village_Object", 2);
		Bottom_Box_03->AutoSpriteSizeOn();
		Bottom_Box_03->SetAutoScaleRatio(2.0f);
		Bottom_Box_03->Transform.SetWorldPosition({ -495,-1138 });

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Bottom_Box_03->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Bottom_Box_03->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);

	}


	{
		Bottom_Tree_01 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Tree_01->CreateAnimation("Village_Tree_02_animation", "Village_Tree_02_animation", 0.1f, -1, -1, true);
		Bottom_Tree_01->AutoSpriteSizeOn();
		Bottom_Tree_01->SetAutoScaleRatio(2.0f);
		Bottom_Tree_01->Transform.SetWorldPosition({ -404,-1222 });
		Bottom_Tree_01->ChangeAnimation("Village_Tree_02_animation");



		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Bottom_Tree_01->GetCurSprite().Texture->GetScale() * 0.5f });
		Col->Transform.SetWorldPosition({ Bottom_Tree_01->Transform.GetWorldPosition().X - 40.0f,Bottom_Tree_01->Transform.GetWorldPosition().Y - 60.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);

	}
	{
		Bottom_Tree_02 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Tree_02->CreateAnimation("Village_Tree_02_animation", "Village_Tree_02_animation", 0.1f, -1, -1, true);
		Bottom_Tree_02->AutoSpriteSizeOn();
		Bottom_Tree_02->SetAutoScaleRatio(2.0f);
		Bottom_Tree_02->Transform.SetWorldPosition({ 23,-1311 });
		Bottom_Tree_02->ChangeAnimation("Village_Tree_02_animation");

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Bottom_Tree_02->GetCurSprite().Texture->GetScale() * 0.5f });
		Col->Transform.SetWorldPosition({ Bottom_Tree_02->Transform.GetWorldPosition().X - 40.0f,Bottom_Tree_02->Transform.GetWorldPosition().Y - 60.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);



	}
	{
		Bottom_Tree_03 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Tree_03->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Bottom_Tree_03->AutoSpriteSizeOn();
		Bottom_Tree_03->SetAutoScaleRatio(2.0f);
		Bottom_Tree_03->Transform.SetWorldPosition({ 151,-1248 });
		Bottom_Tree_03->ChangeAnimation("Village_Tree_animation");

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Bottom_Tree_03->GetCurSprite().Texture->GetScale() * 0.5f });
		Col->Transform.SetWorldPosition({ Bottom_Tree_03->Transform.GetWorldPosition().X - 35.0f,Bottom_Tree_03->Transform.GetWorldPosition().Y - 60.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);


	}

	{
		Bottom_Tree_04 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Tree_04->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Bottom_Tree_04->AutoSpriteSizeOn();
		Bottom_Tree_04->SetAutoScaleRatio(2.0f);
		Bottom_Tree_04->Transform.SetWorldPosition({ 305,-1169 });
		Bottom_Tree_04->ChangeAnimation("Village_Tree_animation");

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Bottom_Tree_04->GetCurSprite().Texture->GetScale() * 0.5f });
		Col->Transform.SetWorldPosition({ Bottom_Tree_04->Transform.GetWorldPosition().X - 35.0f,Bottom_Tree_04->Transform.GetWorldPosition().Y - 60.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);
	}

	{
		Bottom_Tree_05 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Tree_05->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Bottom_Tree_05->AutoSpriteSizeOn();
		Bottom_Tree_05->SetAutoScaleRatio(2.0f);
		Bottom_Tree_05->Transform.SetWorldPosition({ 446,-1243 });
		Bottom_Tree_05->ChangeAnimation("Village_Tree_animation");

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Bottom_Tree_05->GetCurSprite().Texture->GetScale() * 0.5f });
		Col->Transform.SetWorldPosition({ Bottom_Tree_05->Transform.GetWorldPosition().X - 35.0f,Bottom_Tree_05->Transform.GetWorldPosition().Y - 60.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);

	}

	{
		Village_House_05 = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_House_05->CreateAnimation("Village_House_05_animation", "Village_House_05_animation", 0.1f, -1, -1, true);
		Village_House_05->AutoSpriteSizeOn();
		Village_House_05->SetAutoScaleRatio(2.0f);
		Village_House_05->Transform.SetWorldPosition({ 177,-892 });
		Village_House_05->ChangeAnimation("Village_House_05_animation");


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({300.0f,300.0f });
		Col->Transform.SetWorldPosition({ Village_House_05->Transform.GetWorldPosition().X + 60.0f,Village_House_05->Transform.GetWorldPosition().Y });
		Col->SetCollisionType(ColType::AABBBOX2D);


	}

	{
		Village_BigStone_02 = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_BigStone_02->SetSprite("Village_BigStone", 0);
		Village_BigStone_02->AutoSpriteSizeOn();
		Village_BigStone_02->SetAutoScaleRatio(2.0f);
		Village_BigStone_02->Transform.SetWorldPosition({ -15,-796 });

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Village_BigStone_02->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Village_BigStone_02->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);


	}

	{
		Village_House_06 = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_House_06->SetSprite("Village_House_06", 0);
		Village_House_06->AutoSpriteSizeOn();
		Village_House_06->SetAutoScaleRatio(2.0f);
		Village_House_06->Transform.SetWorldPosition({ 983,-804 });


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({300.0f,260.0f});
		Col->Transform.SetWorldPosition({ Village_House_06->Transform.GetWorldPosition().X, Village_House_06->Transform.GetWorldPosition().Y-30.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);

	}
	{
		Village_House_06_OilLamp = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_House_06_OilLamp->SetSprite("Village_Object", 1);
		Village_House_06_OilLamp->AutoSpriteSizeOn();
		Village_House_06_OilLamp->SetAutoScaleRatio(2.0f);
		Village_House_06_OilLamp->Transform.SetWorldPosition({ 1265,-933 });


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Village_House_06_OilLamp->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Village_House_06_OilLamp->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);


	}
	




	{
		Bottom_Box_04 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Box_04->SetSprite("Village_Object", 2);
		Bottom_Box_04->AutoSpriteSizeOn();
		Bottom_Box_04->SetAutoScaleRatio(2.0f);
		Bottom_Box_04->Transform.SetWorldPosition({ 817,-833 });


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Bottom_Box_04->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Bottom_Box_04->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);

	}

	{
		Bottom_Box_05 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Box_05->SetSprite("Village_Object", 2);
		Bottom_Box_05->AutoSpriteSizeOn();
		Bottom_Box_05->SetAutoScaleRatio(2.0f);
		Bottom_Box_05->Transform.SetWorldPosition({ 826,-988 });


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Bottom_Box_05->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Bottom_Box_05->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);
	}

	{
		Bottom_Box_06 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Box_06->SetSprite("Village_Object", 2);
		Bottom_Box_06->AutoSpriteSizeOn();
		Bottom_Box_06->SetAutoScaleRatio(2.0f);
		Bottom_Box_06->Transform.SetWorldPosition({ 1163,-847 });


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Bottom_Box_06->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Bottom_Box_06->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);

	}

	{
		Bottom_Tree_06 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Tree_06->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Bottom_Tree_06->AutoSpriteSizeOn();
		Bottom_Tree_06->SetAutoScaleRatio(2.0f);
		Bottom_Tree_06->Transform.SetWorldPosition({ 1310,-778 });
		Bottom_Tree_06->ChangeAnimation("Village_Tree_animation");


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Bottom_Tree_06->GetCurSprite().Texture->GetScale() * 0.5f });
		Col->Transform.SetWorldPosition({ Bottom_Tree_06->Transform.GetWorldPosition().X - 35.0f,Bottom_Tree_06->Transform.GetWorldPosition().Y - 60.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);

	}

	{
		Bottom_Tree_07 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Tree_07->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Bottom_Tree_07->AutoSpriteSizeOn();
		Bottom_Tree_07->SetAutoScaleRatio(2.0f);
		Bottom_Tree_07->Transform.SetWorldPosition({ 1388,-1276 });
		Bottom_Tree_07->ChangeAnimation("Village_Tree_animation");

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Bottom_Tree_07->GetCurSprite().Texture->GetScale() * 0.5f });
		Col->Transform.SetWorldPosition({ Bottom_Tree_07->Transform.GetWorldPosition().X - 35.0f,Bottom_Tree_07->Transform.GetWorldPosition().Y - 60.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);

	}

	{
		Bottom_Tree_08 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Tree_08->CreateAnimation("Village_Tree_animation", "Village_Tree_animation", 0.1f, -1, -1, true);
		Bottom_Tree_08->AutoSpriteSizeOn();
		Bottom_Tree_08->SetAutoScaleRatio(2.0f);
		Bottom_Tree_08->Transform.SetWorldPosition({ 878,-1188 });
		Bottom_Tree_08->ChangeAnimation("Village_Tree_animation");


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Bottom_Tree_08->GetCurSprite().Texture->GetScale() * 0.5f });
		Col->Transform.SetWorldPosition({ Bottom_Tree_08->Transform.GetWorldPosition().X - 35.0f,Bottom_Tree_08->Transform.GetWorldPosition().Y - 60.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);


	}

	{
		Village_Well_animation = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Well_animation->CreateAnimation("Village_Well_animation", "Village_Well_animation", 0.1f, -1, -1, true);
		Village_Well_animation->AutoSpriteSizeOn();
		Village_Well_animation->SetAutoScaleRatio(2.0f);
		Village_Well_animation->Transform.SetWorldPosition({ 1463,-1067 });
		Village_Well_animation->ChangeAnimation("Village_Well_animation");


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Village_Well_animation->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition({ Village_Well_animation->Transform.GetWorldPosition().X,Village_Well_animation->Transform.GetWorldPosition().Y+20.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);



	}

	{
		Bottom_Tree_09 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Tree_09->CreateAnimation("Village_Tree_02_animation", "Village_Tree_02_animation", 0.1f, -1, -1, true);
		Bottom_Tree_09->AutoSpriteSizeOn();
		Bottom_Tree_09->SetAutoScaleRatio(2.0f);
		Bottom_Tree_09->Transform.SetWorldPosition({ 1656,-1155 });
		Bottom_Tree_09->ChangeAnimation("Village_Tree_02_animation");




		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Bottom_Tree_09->GetCurSprite().Texture->GetScale() * 0.5f });
		Col->Transform.SetWorldPosition({ Bottom_Tree_09->Transform.GetWorldPosition().X - 40.0f,Bottom_Tree_09->Transform.GetWorldPosition().Y - 60.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);
	}

	{
		Village_House_04 = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_House_04->SetSprite("Village_House_04", 0);
		Village_House_04->AutoSpriteSizeOn();
		Village_House_04->SetAutoScaleRatio(2.0f);
		Village_House_04->Transform.SetWorldPosition({ 1596,-753});


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Village_House_04->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Village_House_04->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);


	}

	{
		Bottom_Tree_10 = CreateComponent<GameEngineSpriteRenderer>(0);
		Bottom_Tree_10->CreateAnimation("Village_Tree_02_animation", "Village_Tree_02_animation", 0.1f, -1, -1, true);
		Bottom_Tree_10->AutoSpriteSizeOn();
		Bottom_Tree_10->SetAutoScaleRatio(2.0f);
		Bottom_Tree_10->Transform.SetWorldPosition({ 1897,-482 });
		Bottom_Tree_10->ChangeAnimation("Village_Tree_02_animation");

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Bottom_Tree_10->GetCurSprite().Texture->GetScale() * 0.5f });
		Col->Transform.SetWorldPosition({ Bottom_Tree_10->Transform.GetWorldPosition().X - 40.0f,Bottom_Tree_10->Transform.GetWorldPosition().Y - 60.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);


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



	/*	std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Village_Blacksmith_Stand2_old->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Village_Blacksmith_Stand2_old->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D);*/


	}
	
	{
		Village_Blacksmith_Stand1_old = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Blacksmith_Stand1_old->SetSprite("Village_Blacksmith", 3);
		Village_Blacksmith_Stand1_old->AutoSpriteSizeOn();
		Village_Blacksmith_Stand1_old->SetAutoScaleRatio(2.0f);
		Village_Blacksmith_Stand1_old->Transform.SetWorldPosition({ 1477,-269 });

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Village_Blacksmith_Stand1_old->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition({ Village_Blacksmith_Stand1_old->Transform.GetWorldPosition().X, Village_Blacksmith_Stand1_old->Transform.GetWorldPosition().Y+90.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);

	}

	{
		Village_Blacksmith_House = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Blacksmith_House->SetSprite("Village_Blacksmith", 1);
		Village_Blacksmith_House->AutoSpriteSizeOn();
		Village_Blacksmith_House->SetAutoScaleRatio(2.0f);
		Village_Blacksmith_House->Transform.SetWorldPosition({ 1741,-313 });


		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Village_Blacksmith_House->GetCurSprite().Texture->GetScale() * 2.0f });
		Col->Transform.SetWorldPosition(Village_Blacksmith_House->Transform.GetWorldPosition());
		Col->SetCollisionType(ColType::AABBBOX2D); 

	}


	{
		Village_Blacksmith_Roof_old = CreateComponent<GameEngineSpriteRenderer>(0);
		Village_Blacksmith_Roof_old->SetSprite("Village_Blacksmith", 2);
		Village_Blacksmith_Roof_old->AutoSpriteSizeOn();
		Village_Blacksmith_Roof_old->SetAutoScaleRatio(2.0f);
		Village_Blacksmith_Roof_old->Transform.SetWorldPosition({ 1717,-154 });

		std::shared_ptr<GameEngineCollision> Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Object);
		Col->Transform.SetLocalScale({ Village_Blacksmith_Roof_old->GetCurSprite().Texture->GetScale() * 1.0f });
		Col->Transform.SetWorldPosition({ Village_Blacksmith_Roof_old->Transform.GetWorldPosition().X,Village_Blacksmith_Roof_old->Transform.GetWorldPosition().Y+10.0f});
		Col->SetCollisionType(ColType::AABBBOX2D);

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


	
	

	//Transform.AddLocalScale({ 0.1f,0.1f });



}

void TownMap::Update(float _DeltaTime)
{





	/*std::shared_ptr<class GameEngineSpriteRenderer> AD  = Village_Blacksmith_House;

	
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
	}*/

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

	//TransformData date = AD->Transform.GetConstTransformDataRef();

	///*date.LocalPosition

	//float4 WorldMousePos*/

	//float4 WorldMousePos = date.WorldPosition;
	//OutputDebugStringA(WorldMousePos.ToString("\n").c_str());



	//static float Time = 5.0f;
	//Time -= _DeltaTime;

	//if (nullptr != Renderer && Time <= 0.0f)
	//{
	//	Renderer->Death();
	//	Renderer = nullptr;
	//}
}


