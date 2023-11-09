#include "PreCompile.h"
#include "Spear.h"
#include "Player.h"
void Spear::TestEvent(GameEngineRenderer* _Renderer)
{

}
void Spear::ChangeState(Spear_State _State)
{
	Spear_State NextState = _State;
	Spear_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case Spear_State::Spear_Down_01:
		AnimationCheck("Spear_Down_01");
		break;
	case Spear_State::Spear_Down_02:
		AnimationCheck("Spear_Down_02");
		break;	
	case Spear_State::Spear_Down_03:
		AnimationCheck("Spear_Down_03");
		break;
	case Spear_State::Spear_Left_01:
		AnimationCheck("Spear_Left_01");
		break;
	case Spear_State::Spear_Left_02:
		AnimationCheck("Spear_Left_02");
		break;
	case Spear_State::Spear_Left_03:
		AnimationCheck("Spear_Left_03");
		break;
	case Spear_State::Spear_Right_01:
		AnimationCheck("Spear_Right_01");
		break;
	case Spear_State::Spear_Right_02:
		AnimationCheck("Spear_Right_02");
		break;
	case Spear_State::Spear_Right_03:
		AnimationCheck("Spear_Right_03");
		break;
	case Spear_State::Spear_Up_01:
		AnimationCheck("Spear_Up_01");
		break;
	case Spear_State::Spear_Up_02:
		AnimationCheck("Spear_Up_02");
		break;
	case Spear_State::Spear_Up_03:
		AnimationCheck("Spear_Up_03");
		break;


	}

}

void Spear::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case Spear_State::Spear_Down_01:
		Down_Attack_Update_01(_Time);
		break;
	case Spear_State::Spear_Down_02:
		Down_Attack_Update_02(_Time);
		break;
	case Spear_State::Spear_Down_03:
		Down_Attack_Update_03(_Time);
		break;
	case Spear_State::Spear_Left_01:
		Left_Attack_Update_01(_Time);
		break;
	case Spear_State::Spear_Left_02:
		Left_Attack_Update_02(_Time);
		break;
	case Spear_State::Spear_Left_03:
		Left_Attack_Update_03(_Time);
		break;
	case Spear_State::Spear_Right_01:
		Right_Attack_Update_01(_Time);
		break;
	case Spear_State::Spear_Right_02:
		Right_Attack_Update_02(_Time);
		break;
	case Spear_State::Spear_Right_03:
		Right_Attack_Update_03(_Time);
		break;
	case Spear_State::Spear_Up_01:
		Up_Attack_Update_01(_Time);
		break;
	case Spear_State::Spear_Up_02:
		Up_Attack_Update_02(_Time);
		break;
	case Spear_State::Spear_Up_03:
		Up_Attack_Update_03(_Time);
		break;



	default:
		break;
	}
}

void Spear::Down_Attack_Update_01(float _Time)
{
	Col->Transform.SetLocalRotation({ 0.0f,0.0f,180.0f });

	if (spear->IsCurAnimationEnd())
	{
		tests = true;
		spear->Off();
		Col->Off();
	}

	if (spear->GetCurIndex() <= 0)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X+2.0f, Player::this_Player->Transform.GetWorldPosition().Y-20.0f});
	}

	else if (spear->GetCurIndex() > 0)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X+2.0f, Player::this_Player->Transform.GetWorldPosition().Y - 60.0f });
	}

	

	
	
	
}

void Spear::Down_Attack_Update_02(float _Time)
{
	Col->Transform.SetLocalRotation({ 0.0f,0.0f,180.0f });

	if (spear->IsCurAnimationEnd())
	{
		tests = true;
		spear->Off();
		Col->Off();
	}


	if (spear->GetCurIndex() <= 1)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X + 2.0f, Player::this_Player->Transform.GetWorldPosition().Y-20.0f });
	}

	else if (spear->GetCurIndex() > 1)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X + 2.0f, Player::this_Player->Transform.GetWorldPosition().Y - 60.0f });
	}



}

void Spear::Down_Attack_Update_03(float _Time)
{
	Col->Transform.SetLocalRotation({ 0.0f,0.0f,180.0f });

	if (spear->IsCurAnimationEnd())
	{
		tests = true;
		spear->Off();
		Col->Off();
	}



	if (spear->GetCurIndex() <= 1)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X + 2.0f, Player::this_Player->Transform.GetWorldPosition().Y - 20.0f });
	}

	else if (spear->GetCurIndex() > 1)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X + 2.0f, Player::this_Player->Transform.GetWorldPosition().Y - 70.0f });
	}

	if (spear->GetCurIndex() > 4)
	{
		Col->Off();
		Col->Off();
	}
	
}

void Spear::Left_Attack_Update_01(float _Time)
{

	if (spear->IsCurAnimationEnd())
	{
		tests = true;
		spear->Off();
		Col->Off();
	}


	if (spear->GetCurIndex() <= 0)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X -20.0f, Player::this_Player->Transform.GetWorldPosition().Y });
	}

	else if (spear->GetCurIndex() > 0)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X - 60.0f, Player::this_Player->Transform.GetWorldPosition().Y });
	}

}

void Spear::Left_Attack_Update_02(float _Time)
{
	if (spear->IsCurAnimationEnd())
	{
		tests = true;
		spear->Off();
		Col->Off();
	}


	if (spear->GetCurIndex() <= 1)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X -20.0f, Player::this_Player->Transform.GetWorldPosition().Y });
	}

	else if (spear->GetCurIndex() > 1)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X -60.0f, Player::this_Player->Transform.GetWorldPosition().Y });
	}

	
}

void Spear::Left_Attack_Update_03(float _Time)
{


	if (spear->IsCurAnimationEnd())
	{
		tests = true;
		spear->Off();
		Col->Off();
	}


	if (spear->GetCurIndex() <= 1)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X -20.0f, Player::this_Player->Transform.GetWorldPosition().Y });
	}

	else if (spear->GetCurIndex() > 1)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X -70.0f, Player::this_Player->Transform.GetWorldPosition().Y  });
	}


	if (spear->GetCurIndex() > 4)
	{
		Col->Off();

	}

}

void Spear::Right_Attack_Update_01(float _Time)
{

	if (spear->IsCurAnimationEnd())
	{
		tests = true;
		spear->Off();
		Col->Off();
	}

	if (spear->GetCurIndex() <= 0)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X + 20.0f, Player::this_Player->Transform.GetWorldPosition().Y });
	}

	else if (spear->GetCurIndex() > 0)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X + 60.0f, Player::this_Player->Transform.GetWorldPosition().Y });
	}


}

void Spear::Right_Attack_Update_02(float _Time)
{
	if (spear->IsCurAnimationEnd())
	{
		tests = true;
		spear->Off();
		Col->Off();
	}


	if (spear->GetCurIndex() <= 1)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X + 20.0f, Player::this_Player->Transform.GetWorldPosition().Y });
	}

	else if (spear->GetCurIndex() > 1)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X + 60.0f, Player::this_Player->Transform.GetWorldPosition().Y });
	}


}

void Spear::Right_Attack_Update_03(float _Time)
{
	if (spear->IsCurAnimationEnd())
	{
		tests = true;
		spear->Off();
		Col->Off();
	}

	if (spear->GetCurIndex() <= 1)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X + 20.0f, Player::this_Player->Transform.GetWorldPosition().Y });
	}

	else if (spear->GetCurIndex() > 1)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X + 70.0f, Player::this_Player->Transform.GetWorldPosition().Y });
	}

	if (spear->GetCurIndex() > 4)
	{
		Col->Off();

	}
}

void Spear::Up_Attack_Update_01(float _Time)
{
	if (spear->IsCurAnimationEnd())
	{
		tests = true;
		spear->Off();
		Col->Off();
	}

	if (spear->GetCurIndex() <= 0)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X - 2.0f, Player::this_Player->Transform.GetWorldPosition().Y + 20.0f });
	}

	else if (spear->GetCurIndex() > 0)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X - 2.0f, Player::this_Player->Transform.GetWorldPosition().Y + 60.0f });
	}

	
}

void Spear::Up_Attack_Update_02(float _Time)
{
	if (spear->IsCurAnimationEnd())
	{
		tests = true;
		spear->Off();
		Col->Off();
	}

	if (spear->GetCurIndex() <= 1)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X - 2.0f, Player::this_Player->Transform.GetWorldPosition().Y + 20.0f });
	}

	else if (spear->GetCurIndex() > 1)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X - 2.0f, Player::this_Player->Transform.GetWorldPosition().Y + 60.0f });
	}


}

void Spear::Up_Attack_Update_03(float _Time)
{
	if (spear->IsCurAnimationEnd())
	{
		tests = true;
		spear->Off();
		Col->Off();
	}

	if (spear->GetCurIndex() <= 1)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X - 2.0f, Player::this_Player->Transform.GetWorldPosition().Y + 20.0f });
	}

	else if (spear->GetCurIndex() > 1)
	{
		Transform.SetLocalPosition({ Player::this_Player->Transform.GetWorldPosition().X - 2.0f, Player::this_Player->Transform.GetWorldPosition().Y + 70.0f });
	}
	
	if (spear->GetCurIndex() > 4)
	{
		Col->Off();
	}

}
