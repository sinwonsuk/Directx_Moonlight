#include "PreCompile.h"
#include "EndLevel.h"
#include "Ending.h"
End_Level::End_Level()
{
}

End_Level::~End_Level()
{
}

void End_Level::Start()
{
	
}

void End_Level::Update(float _Delta)
{
}

void End_Level::LevelStart(GameEngineLevel* _PrevLevel)
{
	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();

	//GetMainCamera()->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

	end = CreateActor<Ending>(); 
}

void End_Level::LevelEnd(GameEngineLevel* _NextLevel)
{

}
