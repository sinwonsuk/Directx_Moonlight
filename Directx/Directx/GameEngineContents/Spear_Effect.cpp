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


}

void Spear_Effect::Update(float _Delta)
{





	if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Down_Attack_01)
	{
		Transform.SetLocalRotation({ 0.0f,0.0f,270.0f }); 
	}
	if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Down_Attack_02)
	{
		Transform.SetLocalRotation({ 0.0f,0.0f,270.0f });
	}
	if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Down_Attack_03)
	{
		Transform.SetLocalRotation({ 0.0f,0.0f,270.0f });
	}



	if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Left_Attack_01)
	{
		Transform.SetLocalRotation({ 0.0f,0.0f,180.0f});
	}
	if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Left_Attack_02)
	{
		Transform.SetLocalRotation({ 0.0f,0.0f,180.0f });
	}
	if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Left_Attack_03)
	{
		Transform.SetLocalRotation({ 0.0f,0.0f,180.0f });
	}


	if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Up_Attack_01)
	{
		Transform.SetLocalRotation({ 0.0f,0.0f,90.0f });
	}
	if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Up_Attack_02)
	{
		Transform.SetLocalRotation({ 0.0f,0.0f,90.0f });
	}
	if (Player::this_Player->GetPlayerStateValue() == PlayerState::Spear_Up_Attack_03)
	{
		Transform.SetLocalRotation({ 0.0f,0.0f,90.0f });
	}






	if (Efffet->IsCurAnimationEnd())
	{
		this->Death(); 
	}
}
