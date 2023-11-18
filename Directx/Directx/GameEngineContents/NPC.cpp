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

	npc = CreateComponent<GameEngineSpriteRenderer>(-48);
	npc->Transform.AddLocalPosition({ 0.0f,0.0f,50.0f });
	npc->CreateAnimation("Npc_Up_Move", "Npc_Up_Move", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Down_Idle", "Npc_Down_Idle", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Down_Move", "Npc_Down_Move", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Left_Idle", "Npc_Left_Idle", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Left_Move", "Npc_Left_Move", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Right_Idle", "Npc_Right_Idle", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Right_Move", "Npc_Right_Move", 0.15f, -1, -1, true);
	npc->CreateAnimation("Npc_Up_Idle", "Npc_Up_Idle", 0.15f, -1, -1, true);
	npc->AutoSpriteSizeOn();
	npc->SetAutoScaleRatio(2.0f);
	npc->ChangeAnimation("Npc_Up_Move");





	ChangeState(Npc_State::LeftMove);
}

void Npc::Update(float _Delta)
{
	//Shop_UI::this_Shop_UI->Shop_Item_01->Transform.SetWorldPosition({ Transform.GetWorldPosition().X,Transform.GetWorldPosition().Y + 100.0f });

	switch (MoveValue)
	{
	case Npc_Move::Up_Left:
		UpdateState(_Delta);
		break;
	case Npc_Move::Up_Right:
		UpdateState_03(_Delta);
		break;
	case Npc_Move::Down_Left:
		UpdateState_02(_Delta);
		break;
	case Npc_Move::Down_Right:
		UpdateState_04(_Delta);
		break;
	default:
		break;
	}
	
	
	
}

void Npc::AnimationCheck(const std::string_view& _AnimationName)
{
	npc->ChangeAnimation(_AnimationName);
}



