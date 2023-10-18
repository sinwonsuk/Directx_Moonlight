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


	GameEngineCore::CreateLevel<TitleLevel>("TitleLevel");
	GameEngineCore::CreateLevel<TutorialLevel>("TutorialLevel");
	GameEngineCore::CreateLevel<WorldLevel>("WorldLevel");
	GameEngineCore::CreateLevel<ShopLevel>("ShopLevel");
	GameEngineCore::CreateLevel<Dungeon_Entrance_Level>("Dungeon_Entrance_Level");

	GameEngineCore::ChangeLevel("TitleLevel");



}

void ContentsCore::Update(float _Delta)
{

}

void ContentsCore::Release()
{

}