#include "PreCompile.h"
#include "Black.h"

Black::Black()
{


}

Black::~Black()
{


}

void Black::Start()
{

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y });

	{
		black = CreateComponent<GameEngineUIRenderer>(500);
		black->SetSprite("Black", 0);
		black->SetImageScale({ 5000.0f,5000.0f });
		black->Transform.AddLocalPosition({ 0.0f,0.0f });
		
	}

}

void Black::Update(float _Delta)
{
	switch (fade)
	{
	case Fade::FideIn:
	{
		Number -= _Delta / 2;
		black->GetColorData().MulColor = { 1,1,1,Number };
	}
		break;
	case Fade::FadeOut:
		break;
	default:
		break;
	}
	
	



	if (Number <= 0.1)
	{
		this->Death();
	}


}
