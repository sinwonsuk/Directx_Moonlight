#include "PreCompile.h"
#include "Upgrade_Spear.h"
#include "Player.h"

void UpGrade_Spear::ChangeState(UpGrade_Spear_State _State)
{
	UpGrade_Spear_State NextState = _State;
	UpGrade_Spear_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case UpGrade_Spear_State::Spear_Down_01:
		AnimationCheck("Upgrade_Spear_Down_01");
		break;
	case UpGrade_Spear_State::Spear_Down_02:
		AnimationCheck("Upgrade_Spear_Down_02");
		break;
	case UpGrade_Spear_State::Spear_Down_03:
		AnimationCheck("Upgrade_Spear_Down_03");
		break;
	case UpGrade_Spear_State::Spear_Left_01:
		AnimationCheck("Upgrade_Spear_Left_01");
		break;
	case UpGrade_Spear_State::Spear_Left_02:
		AnimationCheck("Upgrade_Spear_Left_02");
		break;
	case UpGrade_Spear_State::Spear_Left_03:
		AnimationCheck("Upgrade_Spear_Left_03");
		break;
	case UpGrade_Spear_State::Spear_Right_01:
		AnimationCheck("Upgrade_Spear_Right_01");
		break;
	case UpGrade_Spear_State::Spear_Right_02:
		AnimationCheck("Upgrade_Spear_Right_02");
		break;
	case UpGrade_Spear_State::Spear_Right_03:
		AnimationCheck("Upgrade_Spear_Right_03");
		break;
	case UpGrade_Spear_State::Spear_Up_01:
		AnimationCheck("Upgrade_Spear_Up_01");
		break;
	case UpGrade_Spear_State::Spear_Up_02:
		AnimationCheck("Upgrade_Spear_Up_02");
		break;
	case UpGrade_Spear_State::Spear_Up_03:
		AnimationCheck("Upgrade_Spear_Up_03");
		break;


	}

}

void UpGrade_Spear::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case UpGrade_Spear_State::Spear_Down_01:
		Down_Attack_Update_01(_Time);
		break;
	case UpGrade_Spear_State::Spear_Down_02:
		Down_Attack_Update_02(_Time);
		break;
	case UpGrade_Spear_State::Spear_Down_03:
		Down_Attack_Update_03(_Time);
		break;
	case UpGrade_Spear_State::Spear_Left_01:
		Left_Attack_Update_01(_Time);
		break;
	case UpGrade_Spear_State::Spear_Left_02:
		Left_Attack_Update_02(_Time);
		break;
	case UpGrade_Spear_State::Spear_Left_03:
		Left_Attack_Update_03(_Time);
		break;
	case UpGrade_Spear_State::Spear_Right_01:
		Right_Attack_Update_01(_Time);
		break;
	case UpGrade_Spear_State::Spear_Right_02:
		Right_Attack_Update_02(_Time);
		break;
	case UpGrade_Spear_State::Spear_Right_03:
		Right_Attack_Update_03(_Time);
		break;
	case UpGrade_Spear_State::Spear_Up_01:
		Up_Attack_Update_01(_Time);
		break;
	case UpGrade_Spear_State::Spear_Up_02:
		Up_Attack_Update_02(_Time);
		break;
	case UpGrade_Spear_State::Spear_Up_03:
		Up_Attack_Update_03(_Time);
		break;



	default:
		break;
	}
}

void UpGrade_Spear::Down_Attack_Update_01(float _Time)
{
	if (Attack_Sound_Check == false)
	{
		Attack_Sound = GameEngineSound::SoundPlay("spear_main_attack_swing.wav"); 
		Attack_Sound_Check = true;
	}


	Col->Transform.SetLocalRotation({ 0.0f,0.0f,180.0f });



	if (spear->GetCurIndex() <= 1)
	{
		Col->Off();
	}

	if (spear->GetCurIndex() >= 2)
	{
		if (spear->GetCurIndex() <= 4)
		{
			Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X, Transform.GetWorldPosition().Y - 70.0f });
			Col->On();
		}
	}
	

	if (spear->GetCurIndex() >= 5)
	{
		Col->Off();
	}
	





	if (spear->IsCurAnimationEnd())
	{
		tests = true;
		spear->Off();
		Col->Off();
	}

	




}

void UpGrade_Spear::Down_Attack_Update_02(float _Time)
{
	Col->Transform.SetLocalRotation({ 0.0f,0.0f,180.0f });

	if (Attack_Sound_Check == false)
	{
		Attack_Sound = GameEngineSound::SoundPlay("spear_main_attack_swing2.wav");
		Attack_Sound_Check = true;
	}

	if (spear->GetCurIndex() <= 1)
	{
		Col->Off();
	}

	if (spear->GetCurIndex() >= 2)
	{
		if (spear->GetCurIndex() <= 4)
		{
			Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X, Transform.GetWorldPosition().Y - 70.0f });
			Col->On();
		}
	}


	if (spear->GetCurIndex() >= 5)
	{
		Col->Off();
	}




	if (spear->IsCurAnimationEnd())
	{
		tests = true;
		spear->Off();
		Col->Off();
	}


}

void UpGrade_Spear::Down_Attack_Update_03(float _Time)
{
	Col->Transform.SetLocalRotation({ 0.0f,0.0f,180.0f });

	if (Attack_Sound_Check == false)
	{
		Attack_Sound = GameEngineSound::SoundPlay("spear_main_attack_swing3.wav");
		Attack_Sound_Check = true;

	}
	if (spear->GetCurIndex() <= 2)
	{
		Col->Off();
	}

	if (spear->GetCurIndex() >= 3)
	{
		if (spear->GetCurIndex() <= 5)
		{
			Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X, Transform.GetWorldPosition().Y-70.0f });
			Col->On();
		}
	}
	if (spear->GetCurIndex() > 5)
	{

		{
			Col->Off();
		}
	}



	if (spear->IsCurAnimationEnd())
	{
		tests = true;
		spear->Off();
		Col->Off();
	}



	

}

void UpGrade_Spear::Left_Attack_Update_01(float _Time)
{

	if (Attack_Sound_Check == false)
	{
		Attack_Sound = GameEngineSound::SoundPlay("spear_main_attack_swing.wav");
		Attack_Sound_Check = true;
	}

	if (spear->GetCurIndex() <= 1)
	{
		Col->Off();
	}

	if (spear->GetCurIndex() >= 2)
	{
		if (spear->GetCurIndex() <= 4)
		{
			Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X-70.0f, Transform.GetWorldPosition().Y});
			Col->On();
		}
	}


	if (spear->GetCurIndex() >= 5)
	{
		Col->Off();
	}
	if (spear->IsCurAnimationEnd())
	{
		tests = true;
		spear->Off();
		Col->Off();
	}



}

void UpGrade_Spear::Left_Attack_Update_02(float _Time)
{
	if (spear->GetCurIndex() <= 1)
	{
		Col->Off();
	}

	if (Attack_Sound_Check == false)
	{
		Attack_Sound = GameEngineSound::SoundPlay("spear_main_attack_swing2.wav");
		Attack_Sound_Check = true;
	}

	if (spear->GetCurIndex() >= 2)
	{
		if (spear->GetCurIndex() <= 4)
		{
			Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X - 70.0f, Transform.GetWorldPosition().Y });
			Col->On();
		}
	}


	if (spear->GetCurIndex() >= 5)
	{
		Col->Off();
	}
	if (spear->IsCurAnimationEnd())
	{
		tests = true;
		spear->Off();
		Col->Off();
	}




}

void UpGrade_Spear::Left_Attack_Update_03(float _Time)
{

	if (Attack_Sound_Check == false)
	{
		Attack_Sound = GameEngineSound::SoundPlay("spear_main_attack_swing3.wav");
		Attack_Sound_Check = true;

	}
	if (spear->GetCurIndex() <= 2)
	{
		Col->Off();
	}

	if (spear->GetCurIndex() >= 3)
	{
		if (spear->GetCurIndex() <= 5)
		{
			Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X - 70.0f, Transform.GetWorldPosition().Y });
			Col->On();
		}
	}
	if (spear->GetCurIndex() > 5)
	{

		{
			Col->Off();
		}
	}


	if (spear->IsCurAnimationEnd())
	{
		tests = true;
		spear->Off();
		Col->Off();
	}


	

}

void UpGrade_Spear::Right_Attack_Update_01(float _Time)
{

	if (Attack_Sound_Check == false)
	{
		Attack_Sound = GameEngineSound::SoundPlay("spear_main_attack_swing.wav");
		Attack_Sound_Check = true;
	}

	if (spear->GetCurIndex() <= 1)
	{
		Col->Off();
	}

	if (spear->GetCurIndex() >= 2)
	{
		if (spear->GetCurIndex() <= 4)
		{
			Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X + 70.0f, Transform.GetWorldPosition().Y });
			Col->On();
		}
	}


	if (spear->GetCurIndex() >= 5)
	{
		Col->Off();
	}

	if (spear->IsCurAnimationEnd())
	{
		tests = true;
		spear->Off();
		Col->Off();
	}

	


}

void UpGrade_Spear::Right_Attack_Update_02(float _Time)
{
	if (Attack_Sound_Check == false)
	{
		Attack_Sound = GameEngineSound::SoundPlay("spear_main_attack_swing2.wav");
		Attack_Sound_Check = true;
	}

	if (spear->GetCurIndex() <= 1)
	{
		Col->Off();
	}

	if (spear->GetCurIndex() >= 2)
	{
		if (spear->GetCurIndex() <= 4)
		{
			Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X + 70.0f, Transform.GetWorldPosition().Y });
			Col->On();
		}
	}


	if (spear->GetCurIndex() >= 5)
	{
		Col->Off();
	}


	if (spear->IsCurAnimationEnd())
	{
		tests = true;
		spear->Off();
		Col->Off();
	}

}

void UpGrade_Spear::Right_Attack_Update_03(float _Time)
{
	if (Attack_Sound_Check == false)
	{
		Attack_Sound = GameEngineSound::SoundPlay("spear_main_attack_swing3.wav");
		Attack_Sound_Check = true;
	}

	if (spear->GetCurIndex() <= 2)
	{
		Col->Off();
	}

	if (spear->GetCurIndex() >= 3)
	{
		if (spear->GetCurIndex() <= 5)
		{
			Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X + 70.0f, Transform.GetWorldPosition().Y });
			Col->On();
		}
	}
	if (spear->GetCurIndex() > 5)
	{

		{
			Col->Off();
		}
	}


	if (spear->IsCurAnimationEnd())
	{
		tests = true;
		spear->Off();
		Col->Off();
	}


	
}

void UpGrade_Spear::Up_Attack_Update_01(float _Time)
{
	if (Attack_Sound_Check == false)
	{
		Attack_Sound = GameEngineSound::SoundPlay("spear_main_attack_swing.wav");
		Attack_Sound_Check = true;

	}
	if (spear->GetCurIndex() <= 1)
	{
		Col->Off();
	}

	if (spear->GetCurIndex() >= 2)
	{
		if (spear->GetCurIndex() <= 4)
		{
			Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X , Transform.GetWorldPosition().Y+70.0f });
			Col->On();
		}
	}


	if (spear->GetCurIndex() >= 5)
	{
		Col->Off();
	}

	if (spear->IsCurAnimationEnd())
	{
		tests = true;
		spear->Off();
		Col->Off();
	}




}

void UpGrade_Spear::Up_Attack_Update_02(float _Time)
{
	if (Attack_Sound_Check == false)
	{
		Attack_Sound = GameEngineSound::SoundPlay("spear_main_attack_swing2.wav");
		Attack_Sound_Check = true;
	}
	if (spear->GetCurIndex() <= 1)
	{
		Col->Off();
	}

	if (spear->GetCurIndex() >= 2)
	{
		if (spear->GetCurIndex() <= 4)
		{
			Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X , Transform.GetWorldPosition().Y + 70.0f });
			Col->On();
		}
	}


	if (spear->GetCurIndex() >= 5)
	{
		Col->Off();
	}

	if (spear->IsCurAnimationEnd())
	{
		tests = true;
		spear->Off();
		Col->Off();
	}

	


}

void UpGrade_Spear::Up_Attack_Update_03(float _Time)
{
	if (Attack_Sound_Check == false)
	{
		Attack_Sound = GameEngineSound::SoundPlay("spear_main_attack_swing3.wav");
		Attack_Sound_Check = true;

	}
	if (spear->GetCurIndex() <= 2)
	{
		Col->Off();
	}

	if (spear->GetCurIndex() >= 3)
	{
		if (spear->GetCurIndex() <= 5)
		{
			Col->Transform.SetWorldPosition({ Transform.GetWorldPosition().X, Transform.GetWorldPosition().Y+70.0f });
			Col->On();
		}
	}
	if (spear->GetCurIndex() > 5)
	{

		{
			Col->Off();
		}
	}

	if (spear->IsCurAnimationEnd())
	{
		tests = true;
		spear->Off();
		Col->Off();
	}

	
	

}
