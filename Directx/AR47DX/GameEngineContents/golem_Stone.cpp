#include "PreCompile.h"
#include "golem_Stone.h"
#include "Player.h"
#include "Spear_Effect.h"
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
	Stone->CreateAnimation("golemhead_prepare_down", "golemhead_prepare_down", 0.1f, -1, -1, true);
	Stone->CreateAnimation("golemhead_prepare_left", "golemhead_prepare_left", 0.1f, -1, -1, true);
	Stone->CreateAnimation("golemhead_prepare_right", "golemhead_prepare_right", 0.1f, -1, -1, true);
	Stone->CreateAnimation("golemhead_prepare_up", "golemhead_prepare_up", 0.1f, -1, -1, true);

	Stone->CreateAnimation("golemhead_stunned_down", "golemhead_stunned_down", 0.1f, -1, -1, true);
	Stone->CreateAnimation("golemhead_stunned_left", "golemhead_stunned_left", 0.1f, -1, -1, true);
	Stone->CreateAnimation("golemhead_stunned_right", "golemhead_stunned_right", 0.1f, -1, -1, true);
	Stone->CreateAnimation("golemhead_stunned_up", "golemhead_stunned_up", 0.1f, -1, -1, true);

	//Wizard->SetPivotType(PivotType::Bottom);

	Stone->AutoSpriteSizeOn();
	Stone->SetAutoScaleRatio(2.0f);
	Stone->ChangeAnimation("golemhead_prepare_up");

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y });


	{
		Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::GolemStone);
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

	CollisionStop(_Delta, "Tutorial_Map_Pixel.png");

	UpdateState(_Delta);
}
void golem_Stone::AnimationCheck(const std::string_view& _AnimationName)
{
	Stone->ChangeAnimation(_AnimationName);
}

void golem_Stone::CollisionStop(float _Delta, std::string_view _Name)
{

	float4 Left_Stone_Pos = { Transform.GetWorldPosition().X - 20.0f,Transform.GetWorldPosition().Y };
	float4 Right_Stone_Pos = {Transform.GetWorldPosition().X + 20.0f,Transform.GetWorldPosition().Y };
	float4 Up_Stone_Pos = { Transform.GetWorldPosition().X,Transform.GetWorldPosition().Y + 20.0f };
	float4 Down_Stone_Pos = { Transform.GetWorldPosition().X ,Transform.GetWorldPosition().Y - 20.0f };


	if (GameEngineColor::AC == GetColor({ Left_Stone_Pos }, { 255,0,0,255 }, _Name))
	{
		Transform.AddLocalPosition({ float4::RIGHT * _Delta * 10.0f });
		ChangeState(golem_Stone_State::LeftCollision);
		return; 
	}
	else if (GameEngineColor::AC == GetColor({ Right_Stone_Pos }, { 255,0,0,255 }, _Name))
	{
		Transform.AddLocalPosition({ float4::LEFT * _Delta * 10.0f });
		ChangeState(golem_Stone_State::RightCollision);
		return;
	}
	else if (GameEngineColor::AC == GetColor({ Up_Stone_Pos }, { 255, 0, 0, 255 }, _Name))
	{
		Transform.AddLocalPosition({ float4::DOWN * _Delta * 10.0f });
		ChangeState(golem_Stone_State::UpCollision);
		return;
	}
	else if (GameEngineColor::AC == GetColor({ Down_Stone_Pos }, { 255, 0, 0, 255 }, _Name))
	{
		Transform.AddLocalPosition({ float4::UP * _Delta * 10.0f });
		ChangeState(golem_Stone_State::DownCollision);
		return;
	}

	else if (GameEngineColor::BLUE == GetColor({ Left_Stone_Pos }, { 0,0,255,255 }, _Name))
	{
		Transform.AddLocalPosition({ float4::RIGHT * _Delta * 10.0f });
		ChangeState(golem_Stone_State::LeftCollision);
		return;
	}
	else if (GameEngineColor::BLUE == GetColor({ Right_Stone_Pos }, { 0,0,255,255 }, _Name))
	{
		Transform.AddLocalPosition({ float4::LEFT * _Delta * 10.0f });
		ChangeState(golem_Stone_State::RightCollision);
		return;
	}
	else if (GameEngineColor::BLUE == GetColor({ Up_Stone_Pos }, { 0, 0, 255, 255 }, _Name))
	{
		Transform.AddLocalPosition({ float4::DOWN * _Delta * 10.0f });
		ChangeState(golem_Stone_State::UpCollision);
		return;
	}
	else if (GameEngineColor::BLUE == GetColor({ Down_Stone_Pos }, { 0, 0, 255, 255 }, _Name))
	{
		Transform.AddLocalPosition({ float4::UP * _Delta * 10.0f });
		ChangeState(golem_Stone_State::DownCollision);
		return;
	}



}

GameEngineColor golem_Stone::GetColor(float4 _Pos, GameEngineColor _DefaultColor, std::string_view _Name)
{
	_Pos.Y *= -1.0f;

	std::shared_ptr<GameEngineTexture> Tex = GameEngineTexture::Find(_Name);

	return Tex->GetColor(_Pos, _DefaultColor);
}