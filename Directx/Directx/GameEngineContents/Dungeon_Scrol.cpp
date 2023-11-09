#include "PreCompile.h"
#include "Dungeon_Scrol.h"

Dungeon_Scrol::Dungeon_Scrol()
{
}

Dungeon_Scrol::~Dungeon_Scrol()
{
}

void Dungeon_Scrol::Start()
{
	Scrol = CreateComponent<GameEngineUIRenderer>();
	Scrol->CreateAnimation("Scrol", "Scrol", 0.1f, -1, -1, false);
	Transform.AddLocalPosition({ 0.0f,-200.0f });

	Scrol->AutoSpriteSizeOn();
	Scrol->SetAutoScaleRatio(2.0f);
	Scrol->ChangeAnimation("Scrol");
	





}

void Dungeon_Scrol::Update(float _DeltaTime)
{
	if (Time < 0.7)
	{
		if (Scrol->GetCurIndex() > 9)
		{
			Time += _DeltaTime;
			Scrol->AnimationPauseOn();
		}
	}
	

	if (Time > 0.7)
	{
		Scrol->AnimationPauseOff();
	}


	if (Scrol->IsCurAnimationEnd() )
	{
		Transform.AddLocalPosition({ float4::DOWN * Speed * _DeltaTime });

	}

	if (Transform.GetWorldPosition().Y < -400.0f)
	{
		this->Death(); 
	}

}
