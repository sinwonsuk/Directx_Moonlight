#include "PreCompile.h"
#include "Boss_Monster_UI.h"

Boss_Monster_UI::Boss_Monster_UI()
{
}

Boss_Monster_UI::~Boss_Monster_UI()
{
}

void Boss_Monster_UI::Start()
{
	GameEngineInput::AddInputObject(this); 

	{
		Monster_HpBar = CreateComponent<GameEngineUIRenderer>(800);
		Monster_HpBar->SetSprite("Boss1_Hp_UI", 2);
		Monster_HpBar->SetPivotType(PivotType::Left);
		Monster_HpBar->Transform.SetWorldPosition({ -440.0f,-300.0f });
		Monster_HpBar->AutoSpriteSizeOn();
		Monster_HpBar->SetAutoScaleRatio(2.0f);
	    Monster_HpBar->GetColorData().MulColor = { 1,1,1,0 };
		Monster_HpBar->On();
	}
	{
		Monster_BaseBar = CreateComponent<GameEngineUIRenderer>(800);
		Monster_BaseBar->SetSprite("Boss1_Hp_UI", 1);
		Monster_BaseBar->SetPivotType(PivotType::Left);
		Monster_BaseBar->AutoSpriteSizeOn();
		Monster_BaseBar->Transform.SetWorldPosition({ -450.0f,-300.0f });
		Monster_BaseBar->SetAutoScaleRatio(2.0f);
		Monster_BaseBar->GetColorData().MulColor = { 1,1,1,0 };
		Monster_BaseBar->On();

	}
}

void Boss_Monster_UI::Update(float _Delta)
{
	/*Monster_HpBar->GetColorData().MulColor = { 1,1,1,Number };
	Monster_BaseBar->GetColorData().MulColor = { 1,1,1,Number };*/

	/*if (GameEngineInput::IsPress('S', this))
	{
		Number -= 0.01;
	}
	if (GameEngineInput::IsPress('W', this))
	{
		Number += 0.01;
	}*/
	if (AlphaCheck ==false)
	{
		Number += _Delta * 2;
		Monster_HpBar->GetColorData().MulColor = { 1,1,1,Number };
		Monster_BaseBar->GetColorData().MulColor = { 1,1,1,Number };
		//int a = 0;
	}

	if (Number >= 0.9)
	{
		/*Monster_HpBar->GetColorData().MulColor = { 1,1,1,1};
		Monster_BaseBar->GetColorData().MulColor = { 1,1,1,1 };*/
		AlphaCheck = true;
	}
}
