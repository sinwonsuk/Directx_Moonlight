#include "PreCompile.h"
#include "Boss_Wirst.h"
#include "Player.h"





void Boss_Wirst::ChangeState(Boss_Wirst_State _State)
{
	Boss_Wirst_State NextState = _State;
	Boss_Wirst_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case Boss_Wirst_State::Start:

		break;
	case Boss_Wirst_State::Rotation:
	
		break;
	case Boss_Wirst_State::End:
		
		break;

	
	}
}

void Boss_Wirst::UpdateState(float _Time)
{
	

	switch (StateValue)
	{
	case Boss_Wirst_State::Start:
		Start_Update(_Time);
		break;
	case Boss_Wirst_State::Rotation:
		Rotation_Update(_Time);
		break;
	case Boss_Wirst_State::End:
		End_Update(_Time);
		break;
	
	default:
		break;
	}
}


void Boss_Wirst::Start_Update(float _Time)
{
	if (Time < 6)
	{
		float4 Player = Player::this_Player->Transform.GetWorldPosition() - BossPos;
		float4 Monster = { 1,0,0 };
		float Dot = float4::DotProduct3D(Player.NormalizeReturn(), Monster);
		float radian = atan2(Player.Y, Player.X) - atan2(Monster.Y, Monster.X);
		Degree = float((radian * (180.0f / 3.141592)));

		// 타원의 중심
		float x = 0;
		float y = 0;

		float _width = 140;
		float _hight = 150;



		Wirst_Rotation.X = x + _width * cos(Degree * GameEngineMath::PI / 180);
		Wirst_Rotation.Y = y + _hight * sin(Degree * GameEngineMath::PI / 180);


		Transform.SetWorldPosition({ BossPos.X + Wirst_Rotation.X,BossPos.Y + Wirst_Rotation.Y });


		{
			float4 Player = Player::this_Player->Transform.GetWorldPosition() - BossPos;
			float4 Monster = { 0,-1,0 };
			float Dot = float4::DotProduct3D(Player.NormalizeReturn(), Monster);
			float radian = atan2(Player.Y, Player.X) - atan2(Monster.Y, Monster.X);
			Degree = float((radian * (180.0f / 3.141592)));
			Transform.SetWorldRotation({ 0.0f,0.0f,Degree });
		}
	}

	if (Time > 6)
	{
		ChangeState(Boss_Wirst_State::Rotation);
		return; 
	}
}

void Boss_Wirst::Rotation_Update(float _Time)
{
	if (abs(Arm->Transform.GetLocalScale().Y) < 1300)
	{
		Arm->Transform.AddLocalScale({ 0.0f ,-Speed* _Time });
		Wirst->Transform.AddLocalPosition({ 0,-Speed * _Time });
	}



	if (abs(Arm->Transform.GetLocalScale().Y) >= 1300)
	{
		if (Check == false)
		{
			Wirst->Transform.AddLocalRotation({ 0.0f,0.0f, Rotation_Speed* _Time });
			Arm->Transform.AddLocalRotation({ 0.0f,0.0f, Rotation_Speed * _Time });

		}

		if (Arm->Transform.GetWorldRotationEuler().Z >= 90)
		{
			Check = true;
		}


		if (Check == true)
		{
			Wirst->Transform.AddLocalRotation({ 0.0f,0.0f, -Rotation_Speed * _Time });
			Arm->Transform.AddLocalRotation({ 0.0f,0.0f, -Rotation_Speed * _Time });

		}

		if (Arm->Transform.GetWorldRotationEuler().Z <= -90)
		{
			++Rotation_Number;
			Check = false;
		}
	}

	if (Rotation_Number == 2)
	{
		Wirst->Transform.SetWorldPosition({ BossPos.X - 1400.0f, BossPos.Y - 60.0f });
		ChangeState(Boss_Wirst_State::End);
		return; 
	}


}

void Boss_Wirst::End_Update(float _Time)
{
	if (Arm->Transform.GetLocalScale().Y < -100 )
	{
		
		Arm->Transform.AddLocalScale({ 0.0f ,Speed * _Time });
		Wirst->Transform.AddWorldPosition({ Speed * _Time, 0 });
		
		
	}
	else
	{
		finish = true;
	}
	if (finish == true)
	{
		this->Off(); 
	}

}
