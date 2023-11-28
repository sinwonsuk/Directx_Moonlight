#include "PreCompile.h"
#include "Black_Smith_Effect.h"

Black_Smith_Effect::Black_Smith_Effect()
{
}

Black_Smith_Effect::~Black_Smith_Effect()
{
}

void Black_Smith_Effect::Start()
{
	Effect = CreateComponent<GameEngineUIRenderer>(99);
	Effect->CreateAnimation("Black_Smith_Effect", "Black_Smith_Effect", 0.1f, -1, -1, false);
	Effect->AutoSpriteSizeOn();
	Effect->SetAutoScaleRatio(2.5f);
	Effect->ChangeAnimation("Black_Smith_Effect");


	Items = CreateComponent<GameEngineUIRenderer>(99);
	Items->SetSprite("Items", 0);
	Items->AutoSpriteSizeOn();
	Items->SetAutoScaleRatio(2.5f);
	Items->Off(); 

	Sound = GameEngineSound::SoundPlay("blacksmith_craft_weapon.wav");
}

void Black_Smith_Effect::Update(float _Delta)
{
	Items->SetSprite("Items", SetSprite);

	if (Effect->GetCurIndex() > 6)
	{
		Items->On();
	}
	if (Effect->IsCurAnimationEnd())
	{
		//Items->On(); 
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
