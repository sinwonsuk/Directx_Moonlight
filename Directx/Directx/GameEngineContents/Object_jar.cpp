#include "PreCompile.h"
#include "Object_jar.h"

Object_jar::Object_jar()
{
}

Object_jar::~Object_jar()
{
}

void Object_jar::Start()
{

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y });


	{
		Jar = CreateComponent<GameEngineSpriteRenderer>(100);
		Jar->SetAutoScaleRatio(2.0f);

		Jar->Transform.AddLocalPosition({ 0.0f,-100.0f });
		Jar->SetSprite("Map_Object", 0);
	}
}

void Object_jar::Update(float _Delta)
{
}
