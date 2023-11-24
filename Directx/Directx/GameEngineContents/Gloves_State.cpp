#include "PreCompile.h"
#include "Gloves.h"
#include "Player.h"


void Gloves::ChangeState(Gloves_State _State)
{
	Gloves_State NextState = _State;
	Gloves_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case Gloves_State::Gloves_Down_01:
		AnimationCheck("Gloves_Down_01");
		break;
	case Gloves_State::Gloves_Down_02:
		AnimationCheck("Gloves_Down_02");
		break;
	case Gloves_State::Gloves_Down_03:
		AnimationCheck("Gloves_Down_03");
		break;
	case Gloves_State::Gloves_Left_01:
		AnimationCheck("Gloves_Left_01");
		break;
	case Gloves_State::Gloves_Left_02:
		AnimationCheck("Gloves_Left_02");
		break;
	case Gloves_State::Gloves_Left_03:
		AnimationCheck("Gloves_Left_03");
		break;
	case Gloves_State::Gloves_Right_01:
		AnimationCheck("Gloves_Right_01");
		break;
	case Gloves_State::Gloves_Right_02:
		AnimationCheck("Gloves_Right_02");
		break;
	case Gloves_State::Gloves_Right_03:
		AnimationCheck("Gloves_Right_03");
		break;
	case Gloves_State::Gloves_Up_01:
		AnimationCheck("Gloves_Up_01");
		break;
	case Gloves_State::Gloves_Up_02:
		AnimationCheck("Gloves_Up_02");
		break;
	case Gloves_State::Gloves_Up_03:
		AnimationCheck("Gloves_Up_03");
		break;


	}
}

void Gloves::UpdateState(float _Time)
{
	switch (StateValue)
	{
	case Gloves_State::Gloves_Down_01:
		Down_Attack_Update_01(_Time);
		break;
	case Gloves_State::Gloves_Down_02:
		Down_Attack_Update_02(_Time);
		break;
	case Gloves_State::Gloves_Down_03:
		Down_Attack_Update_03(_Time);
		break;
	case Gloves_State::Gloves_Left_01:
		Left_Attack_Update_01(_Time);
		break;
	case Gloves_State::Gloves_Left_02:
		Left_Attack_Update_02(_Time);
		break;
	case Gloves_State::Gloves_Left_03:
		Left_Attack_Update_03(_Time);
		break;
	case Gloves_State::Gloves_Right_01:
		Right_Attack_Update_01(_Time);
		break;
	case Gloves_State::Gloves_Right_02:
		Right_Attack_Update_02(_Time);
		break;
	case Gloves_State::Gloves_Right_03:
		Right_Attack_Update_03(_Time);
		break;
	case Gloves_State::Gloves_Up_01:
		Up_Attack_Update_01(_Time);
		break;
	case Gloves_State::Gloves_Up_02:
		Up_Attack_Update_02(_Time);
		break;
	case Gloves_State::Gloves_Up_03:
		Up_Attack_Update_03(_Time);
		break;
	default:
		break;
	}

}

void Gloves::Down_Attack_Update_01(float _Time)
{
	if (Glove->GetCurIndex() <=  1)
	{
		Col->Off();
	}

	if (Glove->GetCurIndex() >  1)
	{
		Col->On();

		
		Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X, Transform.GetWorldPosition().Y - 40.0f });
		
	}

	if (Glove->IsCurAnimationEnd())
	{
		Glove->Off();
		Col->Off();
	}
}

void Gloves::Down_Attack_Update_02(float _Time)
{
	if (Glove->GetCurIndex() <= 0)
	{
		Col->Off();
	}

	if (Glove->GetCurIndex() > 1)
	{
		Col->On();


		Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X, Transform.GetWorldPosition().Y - 40.0f });

	}

	if (Glove->IsCurAnimationEnd())
	{
		Glove->Off();
		Col->Off();
	}



}

void Gloves::Down_Attack_Update_03(float _Time)
{
	if (Glove->GetCurIndex() <= 0)
	{
		Col->Off();
	}

	if (Glove->GetCurIndex() >= 1)
	{
		Col->On();

		if (Glove->GetCurIndex() <= 4)
		{
			Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X, Transform.GetWorldPosition().Y - 40.0f });
		}
	}

	if (Glove->GetCurIndex() > 4)
	{
		Col->Off();
	}

	if (Glove->IsCurAnimationEnd())
	{
		Glove->Off();
		Col->Off();
	}

}

void Gloves::Left_Attack_Update_01(float _Time)
{
	if (Glove->GetCurIndex() <= 1)
	{
		Col->Off();
	}

	if (Glove->GetCurIndex() > 1)
	{
		Col->On();


		Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X-40.0f, Transform.GetWorldPosition().Y });

	}

	if (Glove->IsCurAnimationEnd())
	{
		Glove->Off();
		Col->Off();
	}
}

void Gloves::Left_Attack_Update_02(float _Time)
{
	if (Glove->GetCurIndex() <= 0)
	{
		Col->Off();
	}

	if (Glove->GetCurIndex() > 1)
	{
		Col->On();


		Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X - 40.0f, Transform.GetWorldPosition().Y });

	}

	if (Glove->IsCurAnimationEnd())
	{
		Glove->Off();
		Col->Off();
	}


}

void Gloves::Left_Attack_Update_03(float _Time)
{
	if (Glove->GetCurIndex() <= 0)
	{
		Col->Off();
	}

	if (Glove->GetCurIndex() >= 1)
	{
		Col->On();

		if (Glove->GetCurIndex() <= 4)
		{
			Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X - 40.0f, Transform.GetWorldPosition().Y });
		}
	}

	if (Glove->GetCurIndex() > 4)
	{
		Col->Off();
	}

	if (Glove->IsCurAnimationEnd())
	{
		Glove->Off();
		Col->Off();
	}
}

void Gloves::Right_Attack_Update_01(float _Time)
{
	if (Glove->GetCurIndex() <= 1)
	{
		Col->Off();
	}

	if (Glove->GetCurIndex() > 1)
	{
		Col->On();


		Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X+40.0f, Transform.GetWorldPosition().Y });

	}

	if (Glove->IsCurAnimationEnd())
	{
		Glove->Off();
		Col->Off();
	}
}

void Gloves::Right_Attack_Update_02(float _Time)
{
	if (Glove->GetCurIndex() <= 0)
	{
		Col->Off();
	}

	if (Glove->GetCurIndex() > 1)
	{
		Col->On();


		Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X+40.0f, Transform.GetWorldPosition().Y  });

	}

	if (Glove->IsCurAnimationEnd())
	{
		Glove->Off();
		Col->Off();
	}
}

void Gloves::Right_Attack_Update_03(float _Time)
{
	if (Glove->GetCurIndex() <= 0)
	{
		Col->Off();
	}

	if (Glove->GetCurIndex() >= 1)
	{
		Col->On();

		if (Glove->GetCurIndex() <= 4)
		{
			Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X+40.0f, Transform.GetWorldPosition().Y  });
		}
	}

	if (Glove->GetCurIndex() > 4)
	{
		Col->Off();
	}

	if (Glove->IsCurAnimationEnd())
	{
		Glove->Off();
		Col->Off();
	}
}

void Gloves::Up_Attack_Update_01(float _Time)
{
	if (Glove->GetCurIndex() <= 1)
	{
		Col->Off();
	}

	if (Glove->GetCurIndex() > 1)
	{
		Col->On();


		Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X, Transform.GetWorldPosition().Y + 40.0f });

	}

	if (Glove->IsCurAnimationEnd())
	{
		Glove->Off();
		Col->Off();
	}
}

void Gloves::Up_Attack_Update_02(float _Time)
{
	if (Glove->GetCurIndex() <= 0)
	{
		Col->Off();
	}

	if (Glove->GetCurIndex() > 1)
	{
		Col->On();


		Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X, Transform.GetWorldPosition().Y + 40.0f });

	}

	if (Glove->IsCurAnimationEnd())
	{
		Glove->Off();
		Col->Off();
	}
}

void Gloves::Up_Attack_Update_03(float _Time)
{
	if (Glove->GetCurIndex() <= 0)
	{
		Col->Off();
	}

	if (Glove->GetCurIndex() >= 1)
	{
		Col->On();

		if (Glove->GetCurIndex() <= 4)
		{
			Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X, Transform.GetWorldPosition().Y + 40.0f });
		}
	}

	if (Glove->GetCurIndex() > 4)
	{
		Col->Off();
	}

	if (Glove->IsCurAnimationEnd())
	{
		Glove->Off();
		Col->Off();
	}
}