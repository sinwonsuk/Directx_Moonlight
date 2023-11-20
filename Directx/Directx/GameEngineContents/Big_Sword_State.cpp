#include "PreCompile.h"
#include "Big_Sword.h"
#include "Player.h"

Big_Sword::Big_Sword()
{
}

Big_Sword::~Big_Sword()
{
}

void Big_Sword::ChangeState(Big_Sword_State _State)
{
	Big_Sword_State NextState = _State;
	Big_Sword_State PrevState = StateValue;

	StateValue = NextState;

switch (NextState)
{
case Big_Sword_State::Big_Sword_Down_01:
	AnimationCheck("Big_Sword_Down_01");
	break;
case Big_Sword_State::Big_Sword_Down_02:
	AnimationCheck("Big_Sword_Down_02");
	break;
case Big_Sword_State::Big_Sword_Down_03:
	AnimationCheck("Big_Sword_Down_03");
	break;
case Big_Sword_State::Big_Sword_Left_01:
	AnimationCheck("Big_Sword_Left_01");
	break;
case Big_Sword_State::Big_Sword_Left_02:
	AnimationCheck("Big_Sword_Left_02");
	break;
case Big_Sword_State::Big_Sword_Left_03:
	AnimationCheck("Big_Sword_Left_03");
	break;
case Big_Sword_State::Big_Sword_Right_01:
	AnimationCheck("Big_Sword_Right_01");
	break;
case Big_Sword_State::Big_Sword_Right_02:
	AnimationCheck("Big_Sword_Right_02");
	break;
case Big_Sword_State::Big_Sword_Right_03:
	AnimationCheck("Big_Sword_Right_03");
	break;
case Big_Sword_State::Big_Sword_Up_01:
	AnimationCheck("Big_Sword_Up_01");
	break;
case Big_Sword_State::Big_Sword_Up_02:
	AnimationCheck("Big_Sword_Up_02");
	break;
case Big_Sword_State::Big_Sword_Up_03:
	AnimationCheck("Big_Sword_Up_03");
	break;


}
}

void Big_Sword::UpdateState(float _Time)
{
	switch (StateValue)
	{
	case Big_Sword_State::Big_Sword_Down_01:
		Down_Attack_Update_01(_Time);
		break;
	case Big_Sword_State::Big_Sword_Down_02:
		Down_Attack_Update_02(_Time);
		break;
	case Big_Sword_State::Big_Sword_Down_03:
		Down_Attack_Update_03(_Time);
		break;
	case Big_Sword_State::Big_Sword_Left_01:
		Left_Attack_Update_01(_Time);
		break;
	case Big_Sword_State::Big_Sword_Left_02:
		Left_Attack_Update_02(_Time);
		break;
	case Big_Sword_State::Big_Sword_Left_03:
		Left_Attack_Update_03(_Time);
		break;
	case Big_Sword_State::Big_Sword_Right_01:
		Right_Attack_Update_01(_Time);
		break;
	case Big_Sword_State::Big_Sword_Right_02:
		Right_Attack_Update_02(_Time);
		break;
	case Big_Sword_State::Big_Sword_Right_03:
		Right_Attack_Update_03(_Time);
		break;
	case Big_Sword_State::Big_Sword_Up_01:
		Up_Attack_Update_01(_Time);
		break;
	case Big_Sword_State::Big_Sword_Up_02:
		Up_Attack_Update_02(_Time);
		break;
	case Big_Sword_State::Big_Sword_Up_03:
		Up_Attack_Update_03(_Time);
		break;



	default:
		break;
	}

}

void Big_Sword::Down_Attack_Update_01(float _Time)
{
	if (Sword->GetCurIndex() < 4)
	{
		Col->Off(); 
	}

	if (Sword->GetCurIndex() >= 4)
	{
		Col->On(); 

		if(Sword->GetCurIndex() <= 6)
		{
			Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X, Transform.GetWorldPosition().Y - 70.0f });
		}
	}

	if (Sword->GetCurIndex() > 6)
	{
		Col->Off();
	}



	if (Sword->IsCurAnimationEnd())
	{
		Sword->Off();
		Col->Off();
	}
}

void Big_Sword::Down_Attack_Update_02(float _Time)
{

	if (Sword->GetCurIndex() < 5)
	{
		Col->Off();
	}

	if (Sword->GetCurIndex() >= 5)
	{
		Col->On();

		if (Sword->GetCurIndex() <= 7)
		{
			Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X, Transform.GetWorldPosition().Y - 70.0f });
		}
	}

	if (Sword->GetCurIndex() > 7)
	{
		Col->Off();
	}



	if (Sword->IsCurAnimationEnd())
	{
		Sword->Off();
		Col->Off();
	}
}

void Big_Sword::Down_Attack_Update_03(float _Time)
{

	if (Sword->GetCurIndex() < 4)
	{
		Col->Off();
	}

	if (Sword->GetCurIndex() >= 4)
	{
		Col->On();

		if (Sword->GetCurIndex() <= 6)
		{
			Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X, Transform.GetWorldPosition().Y - 70.0f });
		}
	}

	if (Sword->GetCurIndex() > 6)
	{
		Col->Off();
	}

	if (Sword->IsCurAnimationEnd())
	{
		Sword->Off();
		Col->Off();
	}
}

void Big_Sword::Left_Attack_Update_01(float _Time)
{
	if (Sword->GetCurIndex() < 5)
	{
		Col->Off();
	}

	if (Sword->GetCurIndex() >= 5)
	{
		Col->On();

		if (Sword->GetCurIndex() <= 8)
		{
			Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X-70.0f, Transform.GetWorldPosition().Y });
		}
	}

	if (Sword->GetCurIndex() > 8)
	{
		Col->Off();
	}

	if (Sword->IsCurAnimationEnd())
	{
		Sword->Off();
		Col->Off();
	}

}

void Big_Sword::Left_Attack_Update_02(float _Time)
{
	if (Sword->GetCurIndex() < 5)
	{
		Col->Off();
	}

	if (Sword->GetCurIndex() >= 5)
	{
		Col->On();

		if (Sword->GetCurIndex() <= 7)
		{
			Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X - 70.0f, Transform.GetWorldPosition().Y });
		}
	}

	if (Sword->GetCurIndex() > 7)
	{
		Col->Off();
	}


	if (Sword->IsCurAnimationEnd())
	{
	
		Sword->Off();
		Col->Off();
	}
}

void Big_Sword::Left_Attack_Update_03(float _Time)
{
	if (Sword->GetCurIndex() < 4)
	{
		Col->Off();
	}

	if (Sword->GetCurIndex() >= 4)
	{
		Col->On();

		if (Sword->GetCurIndex() <= 6)
		{
			Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X - 70.0f, Transform.GetWorldPosition().Y });
		}
	}

	if (Sword->GetCurIndex() > 6)
	{
		Col->Off();
	}

	if (Sword->IsCurAnimationEnd())
	{
		Sword->Off();
		Col->Off();
	}

}

void Big_Sword::Right_Attack_Update_01(float _Time)
{
	if (Sword->GetCurIndex() < 5)
	{
		Col->Off();
	}

	if (Sword->GetCurIndex() >= 5)
	{
		Col->On();

		if (Sword->GetCurIndex() <= 8)
		{
			Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X + 70.0f, Transform.GetWorldPosition().Y });
		}
	}

	if (Sword->GetCurIndex() > 8)
	{
		Col->Off();
	}


	if (Sword->IsCurAnimationEnd())
	{
		Sword->Off();
		Col->Off();
	}
}

void Big_Sword::Right_Attack_Update_02(float _Time)
{
	if (Sword->GetCurIndex() < 5)
	{
		Col->Off();
	}

	if (Sword->GetCurIndex() >= 5)
	{
		Col->On();

		if (Sword->GetCurIndex() <= 7)
		{
			Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X + 70.0f, Transform.GetWorldPosition().Y });
		}
	}

	if (Sword->GetCurIndex() > 7)
	{
		Col->Off();
	}

	
	if (Sword->IsCurAnimationEnd())
	{
		Sword->Off();
		Col->Off();
	}
}

void Big_Sword::Right_Attack_Update_03(float _Time)
{

	if (Sword->GetCurIndex() < 4)
	{
		Col->Off();
	}

	if (Sword->GetCurIndex() >= 4)
	{
		Col->On();

		if (Sword->GetCurIndex() <= 6)
		{
			Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X + 70.0f, Transform.GetWorldPosition().Y });
		}
	}

	if (Sword->GetCurIndex() > 6)
	{
		Col->Off();
	}

	if (Sword->IsCurAnimationEnd())
	{
		Sword->Off();
		Col->Off();
	}
}

void Big_Sword::Up_Attack_Update_01(float _Time)
{

	if (Sword->GetCurIndex() < 4)
	{
		Col->Off();
	}

	if (Sword->GetCurIndex() >= 4)
	{
		Col->On();

		if (Sword->GetCurIndex() <= 6)
		{
			Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X, Transform.GetWorldPosition().Y + 70.0f });
		}
	}

	if (Sword->GetCurIndex() > 6)
	{
		Col->Off();
	}



	if (Sword->IsCurAnimationEnd())
	{
		Sword->Off();
		Col->Off();
	}
}

void Big_Sword::Up_Attack_Update_02(float _Time)
{

	if (Sword->GetCurIndex() < 5)
	{
		Col->Off();
	}

	if (Sword->GetCurIndex() >= 5)
	{
		Col->On();

		if (Sword->GetCurIndex() <= 7)
		{
			Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X, Transform.GetWorldPosition().Y + 70.0f });
		}
	}

	if (Sword->GetCurIndex() > 7)
	{
		Col->Off();
	}

	if (Sword->IsCurAnimationEnd())
	{
		Sword->Off();
		Col->Off();
	}
}

void Big_Sword::Up_Attack_Update_03(float _Time)
{

	if (Sword->GetCurIndex() < 4)
	{
		Col->Off();
	}

	if (Sword->GetCurIndex() >= 4)
	{
		Col->On();

		if (Sword->GetCurIndex() <= 6)
		{
			Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X, Transform.GetWorldPosition().Y + 70.0f });
		}
	}

	if (Sword->GetCurIndex() > 6)
	{
		Col->Off();
	}

	if (Sword->IsCurAnimationEnd())
	{
		Sword->Off();
		Col->Off();
	}
}