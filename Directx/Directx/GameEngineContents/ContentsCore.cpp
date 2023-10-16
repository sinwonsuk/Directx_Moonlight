#include "PreCompile.h"
#include "ContentsCore.h"

#include <GameEngineCore/GameEngineSampler.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include "PlayLevel.h"
#include "TitleLevel.h"
#include "WorldLevel.h"
#include "TutorialLevel.h"
#include "ShopLevel.h"
#include "Dungeon_Entrance_Level.h"
ContentsCore::ContentsCore() 
{
}

ContentsCore::~ContentsCore() 
{
}

void ContentsCore::Start()
{
	//기본적으로 SpriteRenderer를 만들때 넣어줄 샘플러를 지정합니다.
	//GameEngineSpriteRenderer::SetDefaultSampler("POINT");

	//GameEngineCore::CreateLevel<TitleLevel>("TitleLevel");
	GameEngineCore::CreateLevel<TutorialLevel>("TutorialLevel");
	GameEngineCore::CreateLevel<WorldLevel>("WorldLevel");
	GameEngineCore::CreateLevel<ShopLevel>("ShopLevel");
	GameEngineCore::CreateLevel<Dungeon_Entrance_Level>("Dungeon_Entrance_Level");

	GameEngineCore::ChangeLevel("TutorialLevel");

	// 자기 텍스처 로드해야 한다.

}

void ContentsCore::Update(float _Delta)
{

}

void ContentsCore::Release()
{

}