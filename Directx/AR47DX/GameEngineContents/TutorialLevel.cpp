#include "PreCompile.h"
#include "TutorialLevel.h"
#include "TutorialMap.h"
#include "TutorialMap_02.h"
#include "TutorialMap_03.h"
#include "TutorialMap_04.h"
#include "Tutorial_Map_05.h"
#include "Tutorial_Map_06.h"
#include "Player.h"
TutorialLevel::TutorialLevel()
{

}

TutorialLevel::~TutorialLevel()
{

}

void TutorialLevel::Start()
{
	

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();

	GetMainCamera()->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

	{
		std::shared_ptr<Player> Object = CreateActor<Player>();
	}

	{
		std::shared_ptr<TutorialMap> Object = CreateActor<TutorialMap>();
	}

	{
		std::shared_ptr<TutorialMap_02> Object = CreateActor<TutorialMap_02>();
	}
	{
		std::shared_ptr<TutorialMap_03> Object = CreateActor<TutorialMap_03>();
	}
	{
		std::shared_ptr<TutorialMap_04> Object = CreateActor<TutorialMap_04>();
	}
	{
		std::shared_ptr<TutorialMap_05> Object = CreateActor<TutorialMap_05>();
	}
	{
		std::shared_ptr<TutorialMap_06> Object = CreateActor<TutorialMap_06>();
	}
}

void TutorialLevel::Update(float _Delta)
{
	/*if (GameEngineInput::IsPress('A'))
	{
		GetCamera(0)->Transform.AddLocalPosition(float4::LEFT * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('D'))
	{
		GetCamera(0)->Transform.AddLocalPosition(float4::RIGHT * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('W'))
	{
		GetCamera(0)->Transform.AddLocalPosition(float4::UP * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('S'))
	{
		GetCamera(0)->Transform.AddLocalPosition(float4::DOWN * _Delta * Speed);
	}*/

}

void TutorialLevel::LevelStart(GameEngineLevel* _PrevLevel)
{

}

void TutorialLevel::LevelEnd(GameEngineLevel* _NextLevel)
{

}
