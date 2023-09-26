#include "PreCompile.h"
#include "BabySlime.h"
#include "Spear.h"
BabySlime::BabySlime()
{


}

BabySlime::~BabySlime()
{


}

void BabySlime::Start()
{
	babySlime = CreateComponent<GameEngineSpriteRenderer>(100);

	

	babySlime->CreateAnimation("babyslime_walk", "babyslime_walk", 0.1f, -1, -1, true);

	babySlime->AutoSpriteSizeOn();
	babySlime->SetAutoScaleRatio(2.0f);
	babySlime->ChangeAnimation("babyslime_walk");

	/*Efffet = CreateComponent<GameEngineSpriteRenderer>(100);

	Efffet->CreateAnimation("spearHitEffect_3", "spearHitEffect_3.png", 0.1f, -1, -1, false);
	Efffet->AutoSpriteSizeOn();
	Efffet->SetAutoScaleRatio(0.7f);
	Efffet->ChangeAnimation("spearHitEffect_3");
	Efffet->Off(); */

	

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y });

	
	
	{
		Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::BabySlime);
		Col->Transform.SetLocalScale({ 15.0f,15.0f });
	}


}


void BabySlime::Update(float _Delta)
{

	
	


	/*Col->Collision(ContentsCollisionType::Spear, [this](std::vector<std::shared_ptr<GameEngineCollision>>& _Collision)
	{
			
				GameEngineActor* Object = _Collision[0]->GetActor();


				Spear* ptr = dynamic_cast<Spear*>(Object);

				switch (ptr->GetStateValue())
				{
				case Spear_State::Spear_Down_01:
				{
					
					Efffet->Transform.SetLocalRotation({ 0.0f,0.0f,-90.0f });
				}
				break;
				case Spear_State::Spear_Down_02:
				{
					
					Efffet->Transform.SetLocalRotation({ 0.0f,0.0f,-90.0f });
				}
				break;
				case Spear_State::Spear_Down_03:
				{
					
					Efffet->Transform.SetLocalRotation({ 0.0f,0.0f,-90.0f });
				}
				break;
				case Spear_State::Spear_Left_01:
					break;
				case Spear_State::Spear_Left_02:
					break;
				case Spear_State::Spear_Left_03:
					break;
				case Spear_State::Spear_Right_01:
				{
					Efffet->On();
				}
				break;
				case Spear_State::Spear_Right_02:
				{
					Efffet->On();
				}
				break;
				case Spear_State::Spear_Right_03:
				{
					Efffet->On();
				}
				break;
				case Spear_State::Spear_Up_01:
					break;
				case Spear_State::Spear_Up_02:
					break;
				case Spear_State::Spear_Up_03:
					break;
				default:
					break;
				}
			
	});
		*/
	



	UpdateState(_Delta); 
}


void BabySlime::AnimationCheck(const std::string_view& _AnimationName)
{
	babySlime->ChangeAnimation(_AnimationName);
}
