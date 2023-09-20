#include "PreCompile.h"
#include "Slime_Potal.h"

Slime_Potal::Slime_Potal()
{
}

Slime_Potal::~Slime_Potal()
{
}

void Slime_Potal::Start()
{
	Potal_Open = CreateComponent<GameEngineSpriteRenderer>(100);
	Potal_Open->CreateAnimation("SlimePotal_Open", "SlimePotal_Open", 0.1f, -1, -1, false);
	Potal_Open->CreateAnimation("SlimePotal_Ing", "SlimePotal_Ing", 0.1f, -1, -1, true);

	Potal_Open->AutoSpriteSizeOn();
	Potal_Open->SetAutoScaleRatio(2.0f);
	Potal_Open->ChangeAnimation("SlimePotal_Open");
	
	



}

void Slime_Potal::Update(float _Delta)
{
	UpdateState(_Delta);
}




void Slime_Potal::AnimationCheck(const std::string_view& _AnimationName)
{
	Potal_Open->ChangeAnimation(_AnimationName); 

}


void Slime_Potal::ChangeState(Slime_Potal_State _State)
{
	Slime_Potal_State NextState = _State;
	Slime_Potal_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case Slime_Potal_State::open:
		AnimationCheck("SlimePotal_Open");
		break;
	case Slime_Potal_State::Ing:
		AnimationCheck("SlimePotal_Ing");
		break;

	default:
		break;
	}

}

void Slime_Potal::UpdateState(float _Time)
{
	switch (StateValue)
	{
	case Slime_Potal_State::open:
		OpenUpdate(_Time);
		break;
	case Slime_Potal_State::Ing:
		IngUpdate(_Time);
		break;

	default:
		break;
	}
}


void Slime_Potal::OpenUpdate(float _Time)
{
	if(Potal_Open->IsCurAnimationEnd())
	{
		ChangeState(Slime_Potal_State::Ing);
		return; 
	}
}

void Slime_Potal::IngUpdate(float _Time)
{

}