#include "PreCompile.h"
#include "golem_Stone.h"
#include "Player.h"
golem_Stone::golem_Stone()
{
}

golem_Stone::~golem_Stone()
{
}

void golem_Stone::Start()
{
	Stone = CreateComponent<GameEngineSpriteRenderer>(100);
	Stone->CreateAnimation("golemhead_cycle_down", "golemhead_cycle_down", 0.1f, -1, -1, true);
	Stone->CreateAnimation("golemhead_cycle_left", "golemhead_cycle_left", 0.1f, -1, -1, true);
	Stone->CreateAnimation("golemhead_cycle_right", "golemhead_cycle_right", 0.1f, -1, -1, true);
	Stone->CreateAnimation("golemhead_cycle_up", "golemhead_cycle_up", 0.1f, -1, -1, true);
	Stone->CreateAnimation("golemhead_prepare_down", "golemhead_prepare_down", 1.0f, -1, -1, true);
	Stone->CreateAnimation("golemhead_prepare_left", "golemhead_prepare_left", 0.1f, -1, -1, true);
	Stone->CreateAnimation("golemhead_prepare_right", "golemhead_prepare_right", 0.1f, -1, -1, true);
	Stone->CreateAnimation("golemhead_prepare_up", "golemhead_prepare_up", 0.1f, -1, -1, true);

	//Wizard->SetPivotType(PivotType::Bottom);

	Stone->AutoSpriteSizeOn();
	Stone->SetAutoScaleRatio(2.0f);
	Stone->ChangeAnimation("golem_Wizard_Up_Move");

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y });


	{
		Col = CreateComponent<GameEngineCollision>();
		Col->Transform.SetLocalScale({ 300.0f,300.0f });

	}

}

void golem_Stone::Update(float _Delta)
{
	float4 Player = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
	float4 Monster = { -1,0,0 };
	float Dot = float4::DotProduct3D(Player.NormalizeReturn(), Monster);
	float radian = atan2(Player.Y, Player.X) - atan2(Monster.Y, Monster.X);
	degree = abs(radian * (180.0 / 3.141592));


	Time += _Delta;



	UpdateState(_Delta);
}
void golem_Stone::AnimationCheck(const std::string_view& _AnimationName)
{
	Stone->ChangeAnimation(_AnimationName);
}