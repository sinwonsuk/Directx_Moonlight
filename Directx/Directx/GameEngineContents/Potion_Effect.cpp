#include "PreCompile.h"
#include "Potion_Effect.h"

Potion_Effect::Potion_Effect()
{
}

Potion_Effect::~Potion_Effect()
{
}

void Potion_Effect::Start()
{
	Effect = CreateComponent<GameEngineUIRenderer>(99);
	Effect->CreateAnimation("Witch_Effect", "Witch_Effect", 0.1f, -1, -1, false);
	Effect->AutoSpriteSizeOn();
	Effect->SetAutoScaleRatio(2.5f);
	Effect->ChangeAnimation("Witch_Effect");


	Items = CreateComponent<GameEngineUIRenderer>(99);
	Items->SetSprite("Items", 0);
	Items->AutoSpriteSizeOn();
	Items->SetAutoScaleRatio(3.0f);
	Items->Off();
}

void Potion_Effect::Update(float _Delta)
{
	Items->SetSprite("Items", SetSprite);

	if (Effect->GetCurIndex() > 16)
	{
		Items->On();
	}
	if (Effect->IsCurAnimationEnd())
	{
		
		Effect->Off();
		Animation_Finish = true;
	}

	if (Animation_Finish == true)
	{



		if (Prev_Pos.Y > Transform.GetWorldPosition().Y + 10)
		{
			gravity = false;
		}
		if (Prev_Pos.Y < Transform.GetWorldPosition().Y - 10)
		{
			gravity = true;
			Check++;
		}


		{
			Number -= _Delta / 2;
			Items->GetColorData().MulColor = { 1,1,1,Number };

			if (Number <= 0.1)
			{
				this->Death();
			}
		}

	}
}
