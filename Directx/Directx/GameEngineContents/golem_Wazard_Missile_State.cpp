#include "PreCompile.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "gloem_Wazard_Missile.h"
#include "Player.h"

void gloem_Wazard_Missile::ChangeState(golem_Wazard_missile_State _State)
{
	golem_Wazard_missile_State NextState = _State;
	golem_Wazard_missile_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case golem_Wazard_missile_State::Missile:
		AnimationCheck("golemturret_Attack");
		break;
	case golem_Wazard_missile_State::Finish:
		AnimationCheck("golemturret_Attack_Finish");
		break;
	}

}

void gloem_Wazard_Missile::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case golem_Wazard_missile_State::Missile:
		AttackUpdate(_Time);
		break;
	case golem_Wazard_missile_State::Finish:
		FinishUpdate(_Time);
		break;
	default:
		break;
	}
}

void gloem_Wazard_Missile::AttackUpdate(float _Time)
{
	/*if (AttackCheck == false)
	{
		AttackDir = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
		AttackCheck = true; 
	}*/


	Transform.AddLocalPosition({ AttackDir.NormalizeReturn() * _Time * Speed });


	float4 Left_Stone_Pos = { Transform.GetWorldPosition().X - 20.0f,Transform.GetWorldPosition().Y };
	float4 Right_Stone_Pos = { Transform.GetWorldPosition().X + 20.0f,Transform.GetWorldPosition().Y };
	float4 Up_Stone_Pos = { Transform.GetWorldPosition().X,Transform.GetWorldPosition().Y + 20.0f };
	float4 Down_Stone_Pos = { Transform.GetWorldPosition().X ,Transform.GetWorldPosition().Y - 20.0f };


	if (Col->Collision(ContentsCollisionType::CameraCollision) ==false)
	{
		ChangeState(golem_Wazard_missile_State::Finish);
		return;
	}











	/*if (GameEngineColor::MAGENTA == GetColor({ Left_Stone_Pos }, { 255,0,0,255 }, "Tutorial_Map_Pixel.png"))
	{
		ChangeState(golem_Wazard_missile_State::Finish);
		return;
	}
	else if (GameEngineColor::MAGENTA == GetColor({ Right_Stone_Pos }, { 255,0,0,255 }, "Tutorial_Map_Pixel.png"))
	{
		ChangeState(golem_Wazard_missile_State::Finish);
		return;
	}
	else if (GameEngineColor::MAGENTA == GetColor({ Up_Stone_Pos }, { 255, 0, 0, 255 }, "Tutorial_Map_Pixel.png"))
	{
		ChangeState(golem_Wazard_missile_State::Finish);
		return;
	}
	else if (GameEngineColor::MAGENTA == GetColor({ Down_Stone_Pos }, { 255, 0, 0, 255 }, "Tutorial_Map_Pixel.png"))
	{
		ChangeState(golem_Wazard_missile_State::Finish);
		return;
	}

    else if (GameEngineColor::BLUE == GetColor({ Left_Stone_Pos }, { 0,0,255,255 }, "Tutorial_Map_Pixel.png"))
	{
		ChangeState(golem_Wazard_missile_State::Finish);
		return;
	}
	else if (GameEngineColor::BLUE == GetColor({ Right_Stone_Pos }, { 0,0,255,255 }, "Tutorial_Map_Pixel.png"))
	{		
		ChangeState(golem_Wazard_missile_State::Finish);
		return;
	}
	else if (GameEngineColor::BLUE == GetColor({ Up_Stone_Pos }, { 0, 0, 255, 255 }, "Tutorial_Map_Pixel.png"))
	{		
		ChangeState(golem_Wazard_missile_State::Finish);
		return;
	}
	else if (GameEngineColor::BLUE == GetColor({ Down_Stone_Pos }, { 0, 0, 255, 255 }, "Tutorial_Map_Pixel.png"))
	{		
		ChangeState(golem_Wazard_missile_State::Finish);
		return;
	}*/






}

GameEngineColor gloem_Wazard_Missile::GetColor(float4 _Pos, GameEngineColor _DefaultColor, std::string_view _Name)
{
	_Pos.Y *= -1.0f;

	std::shared_ptr<GameEngineTexture> Tex = GameEngineTexture::Find(_Name);

	return Tex->GetColor(_Pos, _DefaultColor);
}

void gloem_Wazard_Missile::FinishUpdate(float _Time)
{
	if (Missile->IsCurAnimationEnd())
	{
		this->Death();

	}
}