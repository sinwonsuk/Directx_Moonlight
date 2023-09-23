#include "PreCompile.h"
#include "golem_Solder.h"
#include "Player.h"

golem_Solder::golem_Solder()
{

}

golem_Solder::~golem_Solder()
{
}

void golem_Solder::Start()
{
	Solder = CreateComponent<GameEngineSpriteRenderer>(100);
	Solder->CreateAnimation("GolemSolder_Attack_Down", "GolemSolder_Attack_Down", 0.1f, -1, -1, false);
	Solder->CreateAnimation("GolemSoldier_Move_Down", "GolemSoldier_Move_Down", 0.1f, -1, -1, true);
	Solder->CreateAnimation("GolemSolder_Attack_Left", "GolemSolder_Attack_Left", 0.1f, -1, -1, false);
	Solder->CreateAnimation("GolemSoldier_Move_Left", "GolemSoldier_Move_Left", 0.1f, -1, -1, true);
	Solder->CreateAnimation("GolemSolder_Attack_Right", "GolemSolder_Attack_Right", 0.1f, -1, -1, false);
	Solder->CreateAnimation("GolemSoldier_Move_Right", "GolemSoldier_Move_Right", 0.1f, -1, -1, true);
	Solder->CreateAnimation("GolemSolder_Attack_Up", "GolemSolder_Attack_Up", 0.1f, -1, -1, false);
	Solder->CreateAnimation("GolemSoldier_Move_Up", "GolemSoldier_Move_Up", 0.1f, -1, -1, true);

	//Solder->SetPivotType(PivotType::Bottom);

	Solder->AutoSpriteSizeOn();
	Solder->SetAutoScaleRatio(2.0f);
	Solder->ChangeAnimation("GolemSoldier_Move_Down");

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y });
	{
		Col = CreateComponent<GameEngineCollision>();
		Col->Transform.SetLocalScale({ 100.0f,100.0f }); 

	}



}

void golem_Solder::Update(float _Delta)
{
	float4 Player = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
	float4 Monster = { -1,0,0 };
	float Dot = float4::DotProduct3D(Player.NormalizeReturn(), Monster);
	float radian = atan2(Player.Y, Player.X) - atan2(Monster.Y, Monster.X);
	degree = abs(radian * (180.0 / 3.141592));


	Time += _Delta;

	UpdateState(_Delta);
}

void golem_Solder::AnimationCheck(const std::string_view& _AnimationName)
{
	Solder->ChangeAnimation(_AnimationName);
}
