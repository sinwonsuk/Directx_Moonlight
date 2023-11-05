#include "PreCompile.h"
#include "Boss_Wirst.h"
#include "Player.h"
Boss_Wirst::Boss_Wirst()
{
}

Boss_Wirst::~Boss_Wirst()
{
}



void Boss_Wirst::Start()
{
	//float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	
	GameEngineInput::AddInputObject(this); 

	Wirst = CreateComponent<GameEngineSpriteRenderer>(200);
	Wirst->SetSprite("Boss_Wrist", 0);
	Wirst->AutoSpriteSizeOn();
	Wirst->SetAutoScaleRatio(2.0f);
	Wirst->Transform.AddLocalPosition({ -5.0f,-50.0f });
	Wirst->SetPivotType(PivotType::Bottom);

	Arm = CreateComponent<GameEngineSpriteRenderer>(198);
	Arm->SetSprite("sticky_Arm", 0);
	Arm->Transform.AddLocalPosition({ -20.0f,80.0f });
	Arm->Transform.SetLocalScale({ 30.0f,1.0f }); 
	Arm->SetPivotType(PivotType::Bottom);
	




}

void Boss_Wirst::Update(float _Delta)
{
	Time += _Delta; 

	
	/*
	if (Time > 3)
	{
		if (abs(Arm->Transform.GetLocalScale().Y) < 1300)
		{
			Arm->Transform.AddLocalScale({0.0f ,-5 });
			Wirst->Transform.AddLocalPosition({ 0,-5 });
		}
	


		if (abs(Arm->Transform.GetLocalScale().Y) >= 1300 && Rotation_Number < 1)
		{
			if (Check == false)
			{
				Wirst->Transform.AddLocalRotation({ 0.0f,0.0f, 1 });
				Arm->Transform.AddLocalRotation({ 0.0f,0.0f, 1 });

			}

			if (Arm->Transform.GetWorldRotationEuler().Z >= 90)
			{
				Check = true;
			}


			if (Check == true)
			{
				Wirst->Transform.AddLocalRotation({ 0.0f,0.0f, -1 });
				Arm->Transform.AddLocalRotation({ 0.0f,0.0f, -1 });

			}

			if (Arm->Transform.GetWorldRotationEuler().Z <= -90)
			{
				++Rotation_Number; 
				Check = false;
			}
		}
	}*/

	UpdateState(_Delta);
}
