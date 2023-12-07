#include "PreCompile.h"
#include "NPC.h"
#include "Shop_UI.h"
#include "Shop_Item.h"
Npc::Npc()
{
}

Npc::~Npc()
{
}

void Npc::Start()
{
	GameEngineInput::AddInputObject(this);

	npc = CreateComponent<GameEngineSpriteRenderer>(140);
	npc->Transform.AddLocalPosition({ 0.0f,0.0f,50.0f });
	npc->CreateAnimation("Npc_Up_Move", "Npc_Up_Move", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Down_Idle", "Npc_Down_Idle", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Down_Move", "Npc_Down_Move", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Left_Idle", "Npc_Left_Idle", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Left_Move", "Npc_Left_Move", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Right_Idle", "Npc_Right_Idle", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Right_Move", "Npc_Right_Move", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Up_Idle", "Npc_Up_Idle", 0.15f, -1, -1, true);

	npc->CreateAnimation("Npc_Up_Move_02", "Npc_Up_Move_02", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Down_Idle_02", "Npc_Down_Idle_02", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Down_Move_02", "Npc_Down_Move_02", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Left_Idle_02", "Npc_Left_Idle_02", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Left_Move_02", "Npc_Left_Move_02", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Right_Idle_02", "Npc_Right_Idle_02", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Right_Move_02", "Npc_Right_Move_02", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Up_Idle_02", "Npc_Up_Idle_02", 0.15f, -1, -1, true);

	npc->CreateAnimation("Npc_Up_Move_03", "Npc_Up_Move_03", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Down_Idle_03", "Npc_Down_Idle_03", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Down_Move_03", "Npc_Down_Move_03", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Left_Idle_03", "Npc_Left_Idle_03", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Left_Move_03", "Npc_Left_Move_03", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Right_Idle_03", "Npc_Right_Idle_03", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Right_Move_03", "Npc_Right_Move_03", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Up_Idle_03", "Npc_Up_Idle_03", 0.15f, -1, -1, true);

	npc->CreateAnimation("Npc_Up_Move_04", "Npc_Up_Move_04", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Down_Idle_04", "Npc_Down_Idle_04", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Down_Move_04", "Npc_Down_Move_04", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Left_Idle_04", "Npc_Left_Idle_04", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Left_Move_04", "Npc_Left_Move_04", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Right_Idle_04", "Npc_Right_Idle_04", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Right_Move_04", "Npc_Right_Move_04", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Up_Idle_04", "Npc_Up_Idle_04", 0.15f, -1, -1, true);


	npc->AutoSpriteSizeOn();
	npc->SetAutoScaleRatio(2.0f);
	npc->ChangeAnimation("Npc_Up_Move");


	Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::NPC);
	Col->Transform.SetLocalScale({ 50.0f,50.0f });
	Col->SetCollisionType(ColType::AABBBOX2D);


	Col_Deal = CreateComponent<GameEngineCollision>(ContentsCollisionType::NPC_Deal);
	Col_Deal->Transform.SetLocalScale({ 50.0f,100.0f });
	Col_Deal->Transform.AddLocalPosition({ 0.0f,50.0f }); 
	Col_Deal->SetCollisionType(ColType::AABBBOX2D);
	Col_Deal->Off();

	ChangeState(Npc_State::LeftMove);

}

void Npc::Update(float _Delta)
{
	

		switch (MoveValue)
		{
		case Npc_Move::Down_Right:
			UpdateState(_Delta);
			break;
		case Npc_Move::Up_Right:
			UpdateState_03(_Delta);
			break;
		case Npc_Move::Down_Left:
			UpdateState_02(_Delta);
			break;
		case Npc_Move::Up_Left:
			UpdateState_04(_Delta);
			break;
		default:
			break;
		}
	
	
	
	
}

void Npc::AnimationCheck(std::string _AnimationName)
{
	switch (Npc_name)
	{
	case Npc_Name::Npc_01:
	{
		Name = {};
	}
	break;

	case Npc_Name::Npc_02:
	{
		Name = "_02";
	}
	break;

	case Npc_Name::Npc_03:
	{
		Name = "_03";
	}
	break;

	case Npc_Name::Npc_04:
	{
		Name = "_04";
	}
	break;



	default:
		break;
	}

	npc->ChangeAnimation(_AnimationName+ Name);


}



