#include "PreCompile.h"
#include "Ending.h"
#include "Black.h"
#include "black_Out.h"
Ending::Ending()
{
}

Ending::~Ending()
{
}

void Ending::Start()
{
	

	End = CreateComponent<GameEngineSpriteRenderer>(-48);

	//Transform.SetWorldScale({ 1280.0f,720.0f });
	End->CreateAnimation("end", "end", 0.08f, -1, -1, false);
	End->SetImageScale({ 1280,720.0f });
	End->ChangeAnimation("end");
	End->On(); 




}

void Ending::Update(float _Delta)
{




	Time += _Delta;

	/*if (Time > 2)
	{
		End->On(); 
	}
	*/
	

}
