#include "PreCompile.h"
#include "BabySlime.h"

BabySlime::BabySlime()
{


}

BabySlime::~BabySlime()
{


}

void BabySlime::Start()
{

	babySlime = CreateComponent<GameEngineSpriteRenderer>(100);

	//player->SetImageScale({ 100.0f, 100.0f });

	babySlime->CreateAnimation("babyslime_walk", "babyslime_walk", 0.1f, -1, -1, true);

	/*babySlime->CreateAnimation("UpIdle", "UpIdle", 0.1f, -1, -1, true);
	babySlime->CreateAnimation("LeftIdle", "LeftIdle", 0.1f, -1, -1, true);
	babySlime->CreateAnimation("DownIdle", "DownIdle", 0.1f, -1, -1, true);
	babySlime->CreateAnimation("RightIdle", "RightIdle", 0.1f, -1, -1, true);*/


	



	babySlime->AutoSpriteSizeOn();
	babySlime->SetAutoScaleRatio(2.0f);
	babySlime->ChangeAnimation("babyslime_walk");



	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y });

	//babySlime->SetFrameEvent("Start", 34, std::bind(&Player::TestEvent, this, std::placeholders::_1));

}


void BabySlime::Update(float _Delta)
{
	UpdateState(_Delta); 
}


void BabySlime::AnimationCheck(const std::string_view& _AnimationName)
{
	babySlime->ChangeAnimation(_AnimationName);
}
