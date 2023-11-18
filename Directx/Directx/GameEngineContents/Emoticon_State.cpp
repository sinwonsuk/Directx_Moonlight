#include "PreCompile.h"
#include "Emoticon.h"

void Emoticon::ChangeState(Emoticon_State _State)
{
	Emoticon_State NextState = _State;
	Emoticon_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case Emoticon_State::Base:
	
		break;
	case Emoticon_State::Stop:
		break;
	case Emoticon_State::Smile:
		
		break;
	}

}

void Emoticon::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case Emoticon_State::Base:
		BaseUpdate(_Time);
		break;
	case Emoticon_State::Stop:
		StopUpdate(_Time);
		break;
	case Emoticon_State::Smile:
		SmileUpdate(_Time);
		break;
	default:
		break;
	}
}


void Emoticon::BaseUpdate(float _Time)
{
	
	
}

void Emoticon::StopUpdate(float _Time)
{
	Stop->On();
	Time += _Time;

	if (Time > 2)
	{
		Stop->Off(); 
		Time = 0;
		ChangeState(Emoticon_State::Smile);
		return;
	}
}

void Emoticon::SmileUpdate(float _Time)
{
	Smile->On();
	Time += _Time;

	if (Time > 2)
	{
		Time = 0;
		this->Death(); 
		return;
	}
}

