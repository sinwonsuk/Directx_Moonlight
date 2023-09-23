#include "PreCompile.h"
#include "golem_Wizard.h"
#include "Player.h"


golem_Wizard::golem_Wizard()
{
}

golem_Wizard::~golem_Wizard()
{
}

void golem_Wizard::Start()
{
	Wizard = CreateComponent<GameEngineSpriteRenderer>(100);
	Wizard->CreateAnimation("golem_Wizard_Down_Attack", "golem_Wizard_Down_Attack", 0.1f, -1, -1, true);
	Wizard->CreateAnimation("golem_Wizard_Down_Move", "golem_Wizard_Down_Move", 0.1f, -1, -1, true);
	Wizard->CreateAnimation("golem_Wizard_Left_Attack", "golem_Wizard_Left_Attack", 0.1f, -1, -1, true);
	Wizard->CreateAnimation("golem_Wizard_Left_Move", "golem_Wizard_Left_Move", 0.1f, -1, -1, true);
	Wizard->CreateAnimation("golem_Wizard_Right_Attack", "golem_Wizard_Right_Attack", 1.0f, -1, -1, true);
	Wizard->CreateAnimation("golem_Wizard_Right_Move", "golem_Wizard_Right_Move", 0.1f, -1, -1, true);
	Wizard->CreateAnimation("golem_Wizard_Up_Attack", "golem_Wizard_Up_Attack", 0.1f, -1, -1, true);
	Wizard->CreateAnimation("golem_Wizard_Up_Move", "golem_Wizard_Up_Move", 0.1f, -1, -1, true);

	//Wizard->SetPivotType(PivotType::Bottom);

	Wizard->AutoSpriteSizeOn();
	Wizard->SetAutoScaleRatio(2.0f);
	Wizard->ChangeAnimation("golem_Wizard_Up_Move");

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y });
	

	{
		Col = CreateComponent<GameEngineCollision>();
		Col->Transform.SetLocalScale({ 300.0f,300.0f });

	}


}

void golem_Wizard::Update(float _Delta)
{
	float4 Player = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
	float4 Monster = { -1,0,0 };
	float Dot = float4::DotProduct3D(Player.NormalizeReturn(), Monster);
	float radian = atan2(Player.Y, Player.X) - atan2(Monster.Y, Monster.X);
	degree = abs(radian * (180.0 / 3.141592));
	
	
	Time += _Delta; 

	

	UpdateState(_Delta); 
}

void golem_Wizard::AnimationCheck(const std::string_view& _AnimationName)
{
	Wizard->ChangeAnimation(_AnimationName);
}

