#include "PreCompile.h"
#include "Title.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineCollision.h>

Title::Title()
{

}

Title::~Title()
{

}

void Title::Start()
{
	{
		Title_BG_Back = CreateComponent<GameEngineSpriteRenderer>(-100);
		Title_BG_Back->CreateAnimation("Title", "Title", 0.1f, -1, -1);
		Title_BG_Back->ChangeAnimation("Title");
		Title_BG_Back->SetImageScale({ 1280.0f,720.0f });

	}
	{
		Title_BG_Front = CreateComponent<GameEngineSpriteRenderer>(100);
		Title_BG_Front->CreateAnimation("Title_Front", "Title_Front", 0.1f, -1, -1);
		Title_BG_Front->ChangeAnimation("Title_Front");
		Title_BG_Front->SetImageScale({ 1280.0f,720.0f });
	}
	
	{
		Title_Logo = CreateComponent<GameEngineSpriteRenderer>(0);
		Title_Logo->SetAutoScaleRatio(2.0f);
		Title_Logo->Transform.AddLocalPosition({ 0.0f,120.0f });
		Title_Logo->SetSprite("TitleLoge");
	}
	{
		Title_Select_01 = CreateComponent<GameEngineSpriteRenderer>(0);
		Title_Select_01->SetAutoScaleRatio(1.2f);
		Title_Select_01->Transform.AddLocalPosition({ 0.0f,-100.0f });
		Title_Select_01->SetSprite("Title_Select",0);

	}
	
	{
		Title_Select_02 = CreateComponent<GameEngineSpriteRenderer>(0);
		Title_Select_02->SetAutoScaleRatio(1.2f);
		Title_Select_02->Transform.AddLocalPosition({ 0.0f,-200.0f });
		Title_Select_02->SetSprite("Title_Select", 1);
	}

	{
		Title_Select_Effect_Left = CreateComponent<GameEngineSpriteRenderer>(0);
		Title_Select_Effect_Left->SetAutoScaleRatio(1.1f);
		Title_Select_Effect_Left->Transform.AddLocalPosition({ -75.0f,-50.0f });
		Title_Select_Effect_Left->LeftFlip();
		Title_Select_Effect_Left->SetSprite("Title_Select_Effect", 0);
	}

	{
		Title_Select_Effect_Right = CreateComponent<GameEngineSpriteRenderer>(0);
		Title_Select_Effect_Right->SetAutoScaleRatio(1.1f);
		Title_Select_Effect_Right->Transform.AddLocalPosition({ 65.0f,-50.0f });
		Title_Select_Effect_Right->SetSprite("Title_Select_Effect", 0);
	}



}

void Title::Update(float _Delta)
{
	




}
