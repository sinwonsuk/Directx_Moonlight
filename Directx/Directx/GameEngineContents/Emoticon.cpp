#include "PreCompile.h"
#include "Emoticon.h"


Emoticon::Emoticon()
{


}

Emoticon::~Emoticon()
{


}

void Emoticon::Start()
{
	Base = CreateComponent<GameEngineSpriteRenderer>(140);
	Base->SetSprite("Visitor_Base", 0);
	Base->AutoSpriteSizeOn();
	Base->SetAutoScaleRatio(2.0f);


	Stop = CreateComponent<GameEngineSpriteRenderer>(140);
	Stop->CreateAnimation("visitortalk_thinkcycle", "visitortalk_thinkcycle", 0.2f, -1, -1, false);
	Stop->AutoSpriteSizeOn();
	Stop->SetAutoScaleRatio(2.0f);
	Stop->ChangeAnimation("visitortalk_thinkcycle");
	Stop->Off();

	Smile = CreateComponent<GameEngineSpriteRenderer>(140);
	Smile->CreateAnimation("visitortalk_toocheap", "visitortalk_toocheap", 0.1f, -1, -1, false);
	Smile->AutoSpriteSizeOn();
	Smile->SetAutoScaleRatio(2.0f);
	Smile->ChangeAnimation("visitortalk_toocheap");
	Smile->Off();
}

void Emoticon::Update(float _Delta)
{
	
	UpdateState(_Delta);

}

