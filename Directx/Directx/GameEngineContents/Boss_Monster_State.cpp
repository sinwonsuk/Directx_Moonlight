#include "PreCompile.h"
#include "Boss_Monster.h"
#include "Player.h"
#include "Boss_Arm.h"
#include "Boss_Rock_Shadow.h"
#include "Boss_Rock.h"
#include "Boss_Wirst.h"
#include "Boss_Monster_UI.h"
#include "Dungeon_Scrol.h"
void Boss_Monster::ChangeState(Boss_Monster_State _State)
{
	Boss_Monster_State NextState = _State;
	Boss_Monster_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case Boss_Monster_State::Start:
		break;

	case Boss_Monster_State::WakeUp:
		AnimationCheck("Wake_Up");
		break;
	case Boss_Monster_State::Start2:
		AnimationCheck("Idle");
		break;
	case Boss_Monster_State::Idle:
		AnimationCheck("Idle");
		break;
	case Boss_Monster_State::LaunchArm:
		AnimationCheck("Boss1_LaunchArm");
		break;
	case Boss_Monster_State::IdleNoArm:
		AnimationCheck("Boss1_IdleNoArm");
		break;
	case Boss_Monster_State::RecoveryArm:
		AnimationCheck("Boss1_RecoverArm");
		break;
	case Boss_Monster_State::Rocks_Spawn_Attack:
		AnimationCheck("Boss1_Rocks_Spawn_Attack");
		break;
	case Boss_Monster_State::Rock_Down:
	
		break;
	case Boss_Monster_State::StickyArm_Aim2Cycle:
		AnimationCheck("Boss1_StickyArm_Aim2Cycle");
		break;
	case Boss_Monster_State::StickyArm_Start:
		AnimationCheck("Boss1_StickyArm_Start");
		break;
	case Boss_Monster_State::StickyArm_End:
		AnimationCheck("Boss1_StickyArm_End");
		break;
	case Boss_Monster_State::Death:
		AnimationCheck("Death");
		break;
	}
	
}



void Boss_Monster::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case Boss_Monster_State::Start:
	{
		StartUpdate(_Time);
	}		
		break;

	case Boss_Monster_State::WakeUp:
		Wake_Up_Update(_Time);
		break;
	case Boss_Monster_State::Start2:
		Start2Update(_Time);
		break;
	case Boss_Monster_State::Idle:
		IdleUpdate(_Time);
		break;
	case Boss_Monster_State::LaunchArm:
		LaunchArm_Update(_Time);
		break;
	case Boss_Monster_State::IdleNoArm:
		Idle_NoArm_Update(_Time);
		break;
	case Boss_Monster_State::RecoveryArm:
		RecoveryArmUpdate(_Time);
		break;
	case Boss_Monster_State::Rocks_Spawn_Attack:
		Rocks_Spawn_Attack_Update(_Time);
		break;
	case Boss_Monster_State::Rock_Down:
		Rock_Down_Update(_Time);
		break;
	case Boss_Monster_State::StickyArm_Aim2Cycle:
		StickyArm_Aim2Cycle_Update(_Time);
		break;
	case Boss_Monster_State::StickyArm_Start:
		StickyArm_Start_Update(_Time);
		break;
	case Boss_Monster_State::StickyArm_End:
		StickyArm_End_Update(_Time);
		break;
	case Boss_Monster_State::Death:
		DeathUpdate(_Time);
		break;

	default:
		break;
	}
}

void Boss_Monster::IdleUpdate(float _Time)
{
	if (Bgm_Sound_Check == false)
	{
		Bgm = GameEngineSound::SoundPlay("golem_boss_track.wav",100); 
		Bgm_Sound_Check = true;
	}



	WaveCheck = true; 

	 int AD = random.RandomInt(0, 1);

	if (Time > 0 && Boss->IsCurAnimationEnd())
	{
		if (AD == 0)
		{
			ChangeState(Boss_Monster_State::LaunchArm);
			return; 
		}

		if (AD == 1)
		{
			ChangeState(Boss_Monster_State::Rocks_Spawn_Attack);
			return;
		}

	}

}


void Boss_Monster::StartUpdate(float _Time)
{
	
	

	if ( CameraCheck == true)
	{
		if (BossUI == false)
		{
			
			Boss_UI->On(); 
			BossUI = true;
		}

		Player::this_Player->Not_Move = false;
		float4 AD = Transform.GetWorldPosition()- Player::this_Player->Transform.GetWorldPosition();
		AD.Normalize();
		GetLevel()->GetMainCamera()->Transform.AddLocalPosition({ AD * _Time * Speed });
	}

	if (GetLevel()->GetMainCamera()->Transform.GetWorldPosition().Y >= Transform.GetWorldPosition().Y)
	{
		
		std::shared_ptr<Dungeon_Scrol> Object =  GetLevel()->CreateActor<Dungeon_Scrol>();
		
		ChangeState(Boss_Monster_State::WakeUp);
		return;
	}


}

void Boss_Monster::Start2Update(float _Time)
{
	if (CameraCheck == true)
	{
		Player::this_Player->Not_Move = false;
		Player::this_Player->Camera = CameraType::BossMap;
		float4 AD = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
		AD.Normalize();
		GetLevel()->GetMainCamera()->Transform.AddLocalPosition({ AD * Time * Speed });
	}

	if (GetLevel()->GetMainCamera()->Transform.GetWorldPosition().Y <= Player::this_Player->Transform.GetWorldPosition().Y+100.0f)
	{
		Player::this_Player->Not_Move = true;
		ChangeState(Boss_Monster_State::Idle);
		return;
	}
}


void Boss_Monster::Wake_Up_Update(float _Time)
{
	Boss->AnimationPauseOff();

	if (Wake_Sound_Check == false)
	{
		Wake_Sound = GameEngineSound::SoundPlay("golem_dungeon_king_golem_awake.wav");
		Wake_Sound_Check = true;
	}






	if (Boss->IsCurAnimationEnd())
	{
		ChangeState(Boss_Monster_State::Start2);
		return;
	}
}

void Boss_Monster::LaunchArm_Update(float _Time)
{
	if (Boss->GetCurIndex() > 18)
	{
		if (ArmPre_Sound_Check == false)
		{
			GameEngineSound::SoundPlay("golem_dungeon_king_golem_handcrash_prepare.wav");
			ArmPre_Sound_Check = true; 
		}
	}

	
	if (Boss->IsCurAnimationEnd())
	{	
		ArmPre_Sound_Check = false;
		Arm = GetLevel()->CreateActor<Boss_Arm>();
		ChangeState(Boss_Monster_State::IdleNoArm);
		return; 
	}

}

void Boss_Monster::Idle_NoArm_Update(float _Time)
{
	if (Arm->GetFinishCheck() == true)
	{
		Arm->Death();
		Arm = GetLevel()->CreateActor<Boss_Arm>();
		++ArmCheck;
	}
	if (ArmCheck == 3)
	{
		Arm->Death();
		ArmCheck = 0; 
		ChangeState(Boss_Monster_State::RecoveryArm);
		return;
	}

}

void Boss_Monster::RecoveryArmUpdate(float _Time)
{
	if (Boss->IsCurAnimationEnd())
	{
		ChangeState(Boss_Monster_State::Idle);
		return; 
	}

}

void Boss_Monster::Rocks_Spawn_Attack_Update(float _Time)
{
	if (Boss->GetCurIndex() > 10)
	{
		if (Spawn_Sound_Check == false)
		{
			Spawn_Sound = GameEngineSound::SoundPlay("golem_dungeon_king_golem_avalanch_pre.wav");
			Spawn_Sound_Check = true;
		}
	}


	if (Boss->IsCurAnimationEnd())
	{
		

		while (AD)
		{
			Spawn_Sound_Check = false;
			Rock_positioning(Rock_Width, Rock_Hight);

			std::shared_ptr<Boss_Rock_Shadow> Object = GetLevel()->CreateActor<Boss_Rock_Shadow>(50);
			Object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X + Shadow_Pos_Left,Transform.GetWorldPosition().Y+ Shadow_Pos_Down });
			//Rock_Shadow_Pos = { Transform.GetWorldPosition().X + Shadow_Pos_Left, Transform.GetWorldPosition().Y + Shadow_Pos_Down + 800.0f }; 
			Rock_Degree -= Rock_Degree_control;

			if (abs(Rock_Degree) > 180)
			{
				Rock_Width += 150;
				Rock_Hight += 150;
				Rocks_Number++;
				Rock_Degree = 0;
				Rock_Degree_control -= 1;
			}


			if (Rocks_Number == 5)
			{
				Rock_Width = 350.0f;
				Rock_Hight = 300.0f;
				Rocks_Number = 0;
				Rock_Degree_control = 10;
				Rock_Degree = 0; 
				AD = false;
			}


		}

		ChangeState(Boss_Monster_State::Rock_Down);
		AD = true;
		return; 
	}

}

void Boss_Monster::Rock_positioning(float _width, float _hight)
{
	// 타원의 중심
	float x = 0;
	float y = 0;



	Shadow_Pos_Left = x + _width * cos(Rock_Degree * GameEngineMath::PI / 180);
	Shadow_Pos_Down = y + _hight * sin(Rock_Degree * GameEngineMath::PI / 180);

}

void Boss_Monster::Rock_Down_Update(float _Time)
{
	if (AD == false)
	{
		TimeTest += _Time;
		if (TimeTest > 0.3)
		{
			TimeTest = 0;
			AD = true;
		}

	}

	while (AD)
	{
		float4 Acsc = Random.RandomFloat(-1, 1000);
		Rock_positioning(Rock_Width, Rock_Hight);

		std::shared_ptr<Boss_Rock> Object = GetLevel()->CreateActor<Boss_Rock>(50);

		if (Rock_Down_Sound_Check == false)
		{
			Rock_Down_Sound = GameEngineSound::SoundPlay("golem_dungeon_king_golem_avalanch_rock.wav");
			Rock_Down_Sound_Check = true;
		}


		Object->Transform.SetLocalPosition({ Transform.GetWorldPosition().X + Shadow_Pos_Left,Transform.GetWorldPosition().Y + Shadow_Pos_Down + 800 });
		Object->Set_BossPos({ Transform.GetWorldPosition().X + Shadow_Pos_Left,Transform.GetWorldPosition().Y + Shadow_Pos_Down + 800 });
		Object->Random.SetSeed(static_cast<long long>(Acsc.X++));
		Object->Set_Seed(static_cast<const int>(Acsc.X));
		Rock_Degree -= Rock_Degree_control;

		if (abs(Rock_Degree) > 180)
		{
			Rock_Width += 150;
			Rock_Hight += 150;
			Rock_Degree = 0;
			Rocks_Number++;
			Rocks_Check++; 
			Rock_Degree_control -= 1;
		}

		if (Rocks_Number == 1)
		{
			Rock_Down_Sound_Check = false;
			Rocks_Number = 0;
			AD = false;
		}
	}
	if (Rocks_Check == 5)
	{
		Rock_Down_Sound_Check = false;
		Rocks_Check = 0;
		Rock_Width = 350.0f;
		Rock_Hight = 300.0f;
		Rocks_Number = 0;
		Rock_Degree_control = 10;
		Rock_Degree = 0;
		AD = false;
		ChangeState(Boss_Monster_State::StickyArm_Start);
		return; 
	}
	
	Random.SetSeed(static_cast<long long>(Time++));
}

void Boss_Monster::StickyArm_Start_Update(float _Time)
{
	AD = true;

	if (Slime_pre_Sound_Check == false)
	{
		if (Boss->GetCurIndex() > 8)
		{
			Slime_pre_Sound = GameEngineSound::SoundPlay("golem_dungeon_king_golem_slimearm_prepare.wav");
			Slime_pre_Sound_Check = true;
		}	
	}



	if (Boss->IsCurAnimationEnd())
	{
		Slime_pre_Sound_Check = false;
		Bosswirst = GetLevel()->CreateActor<Boss_Wirst>();

		Bosswirst->Set_BossPos({ Transform.GetWorldPosition().X-140.0f ,Transform.GetWorldPosition().Y+110.0f });
		Bosswirst->Transform.SetWorldPosition({ Transform.GetWorldPosition().X - 100.0f ,Transform.GetWorldPosition().Y-30.0f });
		ChangeState(Boss_Monster_State::StickyArm_Aim2Cycle);
		return; 
	}
}

void Boss_Monster::StickyArm_Aim2Cycle_Update(float _Time)
{
	if (Bosswirst->GetFinsih() == true)
	{
		Bosswirst->Death(); 
		Spawn_Sound_End = GameEngineSound::SoundPlay("golem_dungeon_king_golem_slimearm_end.wav"); 
		ChangeState(Boss_Monster_State::StickyArm_End);
		return;
	}
}

void Boss_Monster::StickyArm_End_Update(float _Time)
{
	if (Boss->IsCurAnimationEnd())
	{
		ChangeState(Boss_Monster_State::Idle);
		return; 
	}
}

void Boss_Monster::DeathUpdate(float _Time)
{
	Bgm.Stop();

	if (Boss->IsCurAnimationEnd())
	{
		Boss->AnimationPauseOn(); 
	}

}


