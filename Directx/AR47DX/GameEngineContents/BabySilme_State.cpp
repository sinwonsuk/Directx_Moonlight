#include "PreCompile.h"
#include "BabySlime.h"
#include "Player.h"
void BabySlime::ChangeState(BabySlime_State _State)
{
	BabySlime_State NextState = _State;
	BabySlime_State PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case BabySlime_State::Walk:
		AnimationCheck("babyslime_walk");
		break;

	}

}

void BabySlime::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case BabySlime_State::Walk:
		WalkUpdate(_Time); 
		break;
	default:
		break;
	}
}

void BabySlime::WalkUpdate(float _Time)
{

	float4 Move = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();


	if (600 > abs(Player::this_Player->Transform.GetWorldPosition().X - Transform.GetWorldPosition().X))
	{
		Transform.AddLocalPosition({ Move.NormalizeReturn() * 150.0f * _Time });
	}

	if (Col->Collision(ContentsCollisionType::Player) == false)
	{
		if (Col->Collision(ContentsCollisionType::BabySlime, { 0,5.0f }))
		{
			Transform.AddLocalPosition({ 0.0f, -250.0f * _Time });
		}
		 if (Col->Collision(ContentsCollisionType::BabySlime, { 0,-5.0f }))
		{
			Transform.AddLocalPosition({ 0.0f, 250.0f * _Time });
		}
		 if (Col->Collision(ContentsCollisionType::BabySlime, { 5.0f,0.0f }))
		{
			Transform.AddLocalPosition({ -250.0f * _Time, 0.0f });
		}
		 if (Col->Collision(ContentsCollisionType::BabySlime, { -5.0f,0.0f }))
		{
			Transform.AddLocalPosition({ 250.0f * _Time, 0.0f });
		}
	}
	if (Col->Collision(ContentsCollisionType::Player) == true)
	{

		if (Col->Collision(ContentsCollisionType::BabySlime, { 0,5.0f }))
		{
			Transform.AddLocalPosition({ -Move.NormalizeReturn() * 150.0f * _Time });
		}
		 if (Col->Collision(ContentsCollisionType::BabySlime, { 0,-5.0f }))
		{
			Transform.AddLocalPosition({ -Move.NormalizeReturn() * 150.0f * _Time });
		}
	  if (Col->Collision(ContentsCollisionType::BabySlime, { 5.0f,0.0f }))
		{
			Transform.AddLocalPosition({ -Move.NormalizeReturn() * 150.0f * _Time });
		}
		 if (Col->Collision(ContentsCollisionType::BabySlime, { -5.0f,0.0f }))
		{
			Transform.AddLocalPosition({ -Move.NormalizeReturn() * 150.0f * _Time });
		}



	}
	


	

}
