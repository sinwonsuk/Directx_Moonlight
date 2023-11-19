#include "PreCompile.h"
#include "Player_UI.h"
#include <GameEngineCore/GameEngineUIRenderer.h>
#include <GameEngineCore/FadePostEffect.h>
int Player_UI::gold = 0;
Player_UI::Player_UI()
{


}

Player_UI::~Player_UI()
{


}

void Player_UI::Start()
{


	Pocket = CreateComponent<GameEngineUIRenderer>();
	Pocket->SetSprite("Pocket.png");
	Pocket->AutoSpriteSizeOn();
	Pocket->SetAutoScaleRatio(1.0f);
	Pocket->Transform.AddLocalPosition({ -580.0f,310.0f });

	Gold_UI = CreateComponent<GameEngineUIRenderer>(10);
	std::string numberStr = std::to_string(gold);
	Gold_UI->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);
	Gold_UI->Transform.AddLocalPosition({ -580.0f,270.0f });


	Heart = CreateComponent<GameEngineUIRenderer>();
	Heart->SetSprite("Heart.png");
	Heart->AutoSpriteSizeOn();
	Heart->SetAutoScaleRatio(2.0f);
	Heart->Transform.AddLocalPosition({ -490.0f,320.0f });



	HealthBar_Base = CreateComponent<GameEngineUIRenderer>();
	HealthBar_Base->SetSprite("HealthBar_Base.png");
	HealthBar_Base->AutoSpriteSizeOn();
	HealthBar_Base->SetAutoScaleRatio(2.0f);
	HealthBar_Base->Transform.AddLocalPosition({ -405.0f,320.0f });

	Hp_Bar = CreateComponent<GameEngineUIRenderer>(10);
	Hp_Bar->SetSprite("Hp_Bar.png");
	Hp_Bar->AutoSpriteSizeOn();
	Hp_Bar->SetAutoScaleRatio(1.9f);
	Hp_Bar->SetPivotType(PivotType::Left);
	Hp_Bar->Transform.AddLocalPosition({ -468.0f,320.0f });





	Bag_Circle = CreateComponent<GameEngineUIRenderer>(10);
	Bag_Circle->SetSprite("Circle.png");
	Bag_Circle->AutoSpriteSizeOn();
	Bag_Circle->SetAutoScaleRatio(2.0f);
	Bag_Circle->Transform.AddLocalPosition({ 590.0f,160.0f });



	Bag = CreateComponent<GameEngineUIRenderer>(10);
	Bag->SetSprite("Bag.png");
	Bag->AutoSpriteSizeOn();
	Bag->SetAutoScaleRatio(2.0f);
	Bag->Transform.AddLocalPosition({ 590.0f,160.0f });


	Button_I = CreateComponent<GameEngineUIRenderer>(10);
	Button_I->SetSprite("Button_I.png");
	Button_I->AutoSpriteSizeOn();
	Button_I->SetAutoScaleRatio(1.0f);
	Button_I->Transform.AddLocalPosition({ 560.0f,130.0f });


	Weapon_Circle = CreateComponent<GameEngineUIRenderer>(10);
	Weapon_Circle->SetSprite("Circle.png");
	Weapon_Circle->AutoSpriteSizeOn();
	Weapon_Circle->SetAutoScaleRatio(2.0f);
	Weapon_Circle->Transform.AddLocalPosition({ 590.0f,260.0f });

	Weapon_Spear = CreateComponent<GameEngineUIRenderer>(10);
	Weapon_Spear->SetSprite("Training_Spear.png");
	Weapon_Spear->AutoSpriteSizeOn();
	Weapon_Spear->SetAutoScaleRatio(2.0f);
	Weapon_Spear->Transform.AddLocalPosition({ 590.0f,260.0f });

	Button_J = CreateComponent<GameEngineUIRenderer>(10);
	Button_J->SetSprite("Button_J.png");
	Button_J->AutoSpriteSizeOn();
	Button_J->SetAutoScaleRatio(1.0f);
	Button_J->Transform.AddLocalPosition({ 590.0f,220.0f });


	Button_K = CreateComponent<GameEngineUIRenderer>(10);
	Button_K->SetSprite("Button_K.png");
	Button_K->AutoSpriteSizeOn();
	Button_K->SetAutoScaleRatio(1.0f);
	Button_K->Transform.AddLocalPosition({ 548.0f,240.0f });

	Button_E = CreateComponent<GameEngineUIRenderer>(10);
	Button_E->SetSprite("Button_E.png");
	Button_E->AutoSpriteSizeOn();
	Button_E->SetAutoScaleRatio(1.0f);
	Button_E->Transform.AddLocalPosition({ 610.0f,330.0f });


	Button_Space = CreateComponent<GameEngineUIRenderer>(10);
	Button_Space->SetSprite("Button_Space.png");
	Button_Space->AutoSpriteSizeOn();
	Button_Space->SetAutoScaleRatio(1.0f);
	Button_Space->Transform.AddLocalPosition({ 550.0f,330.0f });

	Mini_Will = CreateComponent<GameEngineUIRenderer>(10);
	Mini_Will->SetSprite("MiniWill.png");
	Mini_Will->AutoSpriteSizeOn();
	Mini_Will->SetAutoScaleRatio(1.0f);
	Mini_Will->Transform.AddLocalPosition({ 520.0f,320.0f });



}

void Player_UI::Update(float _Delta)
{
	//GetLevel()->GetMainCamera()->GetCameraAllRenderTarget()->CreateEffect<FadePostEffect>();
	Button_E->GetSprite()->GetSpriteData(0).Texture = nullptr;


	std::string numberStr = std::to_string(gold);
	Gold_UI->SetText("µ¸¿ò", numberStr, 20.0f, float4::WHITE, FW1_CENTER);

}
