#include "PreCompile.h"
#include "Big_Sword.h"
#include "Player.h"
void Big_Sword::TestEvent(GameEngineRenderer* _Renderer)
{

}
void Big_Sword::ChangeState(Big_Sword_State _State)
{
	Big_Sword_State NextState = _State;
	Big_Sword_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case Big_Sword_State::BigSword_Down_01:
		AnimationCheck("BigSword_Down_01");
		break;
	case Big_Sword_State::BigSword_Down_02:
		AnimationCheck("BigSword_Down_02");
		break;	
	case Big_Sword_State::BigSword_Down_03:
		AnimationCheck("BigSword_Down_03");
		break;


	}

}

void Big_Sword::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case Big_Sword_State::BigSword_Down_01:
		Down_Attack_Update_01(_Time);
		break;
	case Big_Sword_State::BigSword_Down_02:
		Down_Attack_Update_02(_Time);
		break;
	case Big_Sword_State::BigSword_Down_03:
		Down_Attack_Update_03(_Time);
		break;


	default:
		break;
	}
}

void Big_Sword::Down_Attack_Update_01(float _Time)
{

	if (Sword->IsCurAnimationEnd())
	{
		this->Death();
	}

	if (Sword->GetCurIndex() < 5)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X, Player::this_Player->Transform.GetWorldPosition().Y + 20.0f });
	}

	if (Sword->GetCurIndex() >= 8 )
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X + 28.0f,Player::this_Player->Transform.GetWorldPosition().Y - 35.0f });	
	}

	else if (Sword->GetCurIndex() >= 5 )
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X+8.0f, Player::this_Player->Transform.GetWorldPosition().Y - 38.0f });
	}

	
	
	
}

void Big_Sword::Down_Attack_Update_02(float _Time)
{
	if (Sword->GetCurIndex() < 4)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X+35.0f, Player::this_Player->Transform.GetWorldPosition().Y-22.0f  });
	}

	else if (Sword->GetCurIndex() >= 4)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X , Player::this_Player->Transform.GetWorldPosition().Y });
	}



	if (Sword->IsCurAnimationEnd())
	{
		this->Death(); 
	}
}

void Big_Sword::Down_Attack_Update_03(float _Time)
{
	/*if (Sword->GetCurIndex() < 4)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X + 35.0f, Player::this_Player->Transform.GetWorldPosition().Y - 22.0f });
	}

	else if (Sword->GetCurIndex() >= 4)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X , Player::this_Player->Transform.GetWorldPosition().Y });
	}*/

	if (Sword->IsCurAnimationEnd())
	{
		this->Death();
	}

	if (Sword->GetCurIndex() < 5)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X, Player::this_Player->Transform.GetWorldPosition().Y + 20.0f });
	}

	if (Sword->GetCurIndex() >= 8)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X + 28.0f,Player::this_Player->Transform.GetWorldPosition().Y - 35.0f });
	}

	else if (Sword->GetCurIndex() >= 5)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X + 8.0f, Player::this_Player->Transform.GetWorldPosition().Y - 38.0f });
	}


	



	
}