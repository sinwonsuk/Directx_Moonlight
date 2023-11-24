#include "PreCompile.h"
#include "Black_Out.h"

Black_Out::Black_Out()
{
}

Black_Out::~Black_Out()
{
}

void Black_Out::Start()
{
	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y });

	{
		black = CreateComponent<GameEngineUIRenderer>(500);
		black->SetSprite("Black", 0);
		black->SetImageScale({ 200000.0f,200000.0f });
		black->GetColorData().PlusColor = { 0.0f,0.0f,0.0f,-1.0f };

	}
}

void Black_Out::Update(float _Delta)
{

	{
		Number += _Delta;
		black->GetColorData().PlusColor = {0, 0, 0, Number };
	}

	if (Number > 0.91)
	{
		Check = true;
	}

}
