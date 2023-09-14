#include "PreCompile.h"
#include "TutorialLevel.h"
#include "TutorialMap.h"
#include "Player.h"
TutorialLevel::TutorialLevel()
{

}

TutorialLevel::~TutorialLevel()
{

}

void TutorialLevel::Start()
{
	GetMainCamera()->Transform.SetLocalPosition({ 0.0f, 0.0f, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

	{
		std::shared_ptr<TutorialMap> Object = CreateActor<TutorialMap>();
	}
	{
		std::shared_ptr<Player> Object = CreateActor<Player>();
	}
}

void TutorialLevel::Update(float _Delta)
{

}

void TutorialLevel::LevelStart(GameEngineLevel* _PrevLevel)
{

}

void TutorialLevel::LevelEnd(GameEngineLevel* _NextLevel)
{

}
