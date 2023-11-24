#include "PreCompile.h"
#include "Spear_Effect.h"
#include "Player.h"
Spear_Effect::Spear_Effect()
{
}

Spear_Effect::~Spear_Effect()
{
}

void Spear_Effect::Start()
{
	Efffet = CreateComponent<GameEngineSpriteRenderer>(101);
	Efffet->CreateAnimation("spearHitEffect_3", "spearHitEffect_3.png", 0.1f, -1, -1, false);
	Efffet->AutoSpriteSizeOn();
	Efffet->SetAutoScaleRatio(1.5f);
	Efffet->ChangeAnimation("spearHitEffect_3");
	Efffet->Off(); 

}

void Spear_Effect::Update(float _Delta)
{
	switch (state)
	{
	case Effect_State::Monster:
	{
		if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Down_Attack_01 || Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Down_Attack_01 || Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Down_Attack_01)
		{
			Efffet->On();
			Transform.SetLocalRotation({ 0.0f,0.0f,270.0f });
		}
		else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Down_Attack_02 || Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Down_Attack_02 || Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Down_Attack_02)
		{
			Efffet->On();
			Transform.SetLocalRotation({ 0.0f,0.0f,270.0f });
		}
		else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Down_Attack_03 || Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Down_Attack_03 || Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Down_Attack_03)
		{
			Efffet->On();
			Transform.SetLocalRotation({ 0.0f,0.0f,270.0f });
		}
		else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Left_Attack_01 || Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Left_Attack_01 || Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Left_Attack_01)
		{
			Efffet->On();
			Transform.SetLocalRotation({ 0.0f,0.0f,180.0f });
		}
		else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Left_Attack_02 || Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Left_Attack_02 || Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Left_Attack_02)
		{
			Efffet->On();
			Transform.SetLocalRotation({ 0.0f,0.0f,180.0f });
		}
		else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Left_Attack_03 || Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Left_Attack_03 || Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Left_Attack_03)
		{
			Efffet->On();
			Transform.SetLocalRotation({ 0.0f,0.0f,180.0f });
		}

		else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Right_Attack_01 || Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Right_Attack_01 || Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Right_Attack_01)
		{
			Efffet->On();
			
		}
		else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Right_Attack_02 || Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Right_Attack_02 || Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Right_Attack_02)
		{
			Efffet->On();
			
		}
		else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Right_Attack_03 || Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Right_Attack_03 || Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Right_Attack_03)
		{
			Efffet->On();	
		}

		else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Up_Attack_01 || Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Up_Attack_01 || Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Up_Attack_01)
		{
			Efffet->On();
			Transform.SetLocalRotation({ 0.0f,0.0f,90.0f });
		}
		else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Up_Attack_02 || Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Up_Attack_02 || Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Up_Attack_02)
		{
			Efffet->On();
			Transform.SetLocalRotation({ 0.0f,0.0f,90.0f });
		}
		else if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Up_Attack_03 || Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Up_Attack_03 || Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Up_Attack_03)
		{
			Efffet->On();
			Transform.SetLocalRotation({ 0.0f,0.0f,90.0f });
		}
		break;
	}
	
	case Effect_State::Boss:
	{
		if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Down_Attack_01 || Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Down_Attack_01 || Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Down_Attack_01)
		{
			Efffet->On();
			Transform.SetLocalRotation({ 0.0f,0.0f,270.0f });
			Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X, Player::this_Player->Transform.GetWorldPosition().Y + 100.0f });
		}
		if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Down_Attack_02 || Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Down_Attack_02 || Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Down_Attack_02)
		{
			Efffet->On();
			Transform.SetLocalRotation({ 0.0f,0.0f,270.0f });
			Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X, Player::this_Player->Transform.GetWorldPosition().Y + 100.0f });
		}
		 if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Down_Attack_03 || Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Down_Attack_03 || Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Down_Attack_03)
		{
			Efffet->On();
			Transform.SetLocalRotation({ 0.0f,0.0f,270.0f });
			Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X, Player::this_Player->Transform.GetWorldPosition().Y + 100.0f });
		}



		 if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Left_Attack_01 || Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Left_Attack_01 || Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Left_Attack_01)
		{
			Efffet->On();
			Transform.SetLocalRotation({ 0.0f,0.0f,180.0f });
			Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X - 100, Player::this_Player->Transform.GetWorldPosition().Y });
		}
		 if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Left_Attack_02 || Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Left_Attack_02 || Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Left_Attack_02)
		{
			Efffet->On();
			Transform.SetLocalRotation({ 0.0f,0.0f,180.0f });
			Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X - 100, Player::this_Player->Transform.GetWorldPosition().Y });
		}
		if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Left_Attack_03 || Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Left_Attack_03 || Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Left_Attack_03)
		{
			Efffet->On();
			Transform.SetLocalRotation({ 0.0f,0.0f,180.0f });
			Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X - 100, Player::this_Player->Transform.GetWorldPosition().Y });
		}



		 if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Up_Attack_01 || Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Up_Attack_01 || Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Up_Attack_01)
		{
			Efffet->On();
			Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X, Player::this_Player->Transform.GetWorldPosition().Y + 100 });
			Transform.SetLocalRotation({ 0.0f,0.0f,90.0f });
		}
		 if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Up_Attack_02 || Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Up_Attack_02 || Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Up_Attack_02)
		{
			Efffet->On();
			Transform.SetLocalRotation({ 0.0f,0.0f,90.0f });
			Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X, Player::this_Player->Transform.GetWorldPosition().Y +100});
		}
		 if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Up_Attack_03 || Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Up_Attack_03 || Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Up_Attack_03)
		{
			Efffet->On();
			Transform.SetLocalRotation({ 0.0f,0.0f,90.0f });
			Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X, Player::this_Player->Transform.GetWorldPosition().Y +100});
		}




	    if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Right_Attack_01 || Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Right_Attack_01 || Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Right_Attack_01)
		{
			Efffet->On();
			Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X + 100, Player::this_Player->Transform.GetWorldPosition().Y });
		}
		if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Right_Attack_02 || Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Right_Attack_02 || Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Right_Attack_02)
		{
			Efffet->On();
			Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X +100, Player::this_Player->Transform.GetWorldPosition().Y });
		}
		if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Right_Attack_03 || Player::this_Player->GetPlayerStateValue() == PlayerState::Sword_Right_Attack_03 || Player::this_Player->GetPlayerStateValue() == PlayerState::Gloves_Right_Attack_03)
		{
			Efffet->On();
			Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X + 100, Player::this_Player->Transform.GetWorldPosition().Y });
		}
		break;
	}




		break;
	default:
		break;
	}




	


	if (Efffet->IsCurAnimationEnd())
	{
		this->Death(); 
	}
}
