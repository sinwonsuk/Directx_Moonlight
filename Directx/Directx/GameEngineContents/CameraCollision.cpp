#include "PreCompile.h"
#include "CameraCollision.h"

CameraCollision* CameraCollision::CameraCol; 
CameraCollision::CameraCollision()
{
}

CameraCollision::~CameraCollision()
{
}

void CameraCollision::Start()
{

	CameraCol = this;

	{
		Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::CameraCollision);
		Col->Transform.SetLocalScale({ 1100.0f,550.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);
	}
	{
		Bag_Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Bag);
		Bag_Col->Transform.SetLocalScale({ 50.0f,50.0f });
		//Bag_Col->SetCollisionType(ColType::AABBBOX2D);
	}
}

void CameraCollision::Update(float _Delta)
{
	Col->Transform.SetWorldPosition({ GetLevel()->GetMainCamera()->Transform.GetWorldPosition().X, GetLevel()->GetMainCamera()->Transform.GetWorldPosition().Y});
	Bag_Col->Transform.SetWorldPosition({ GetLevel()->GetMainCamera()->Transform.GetWorldPosition().X+600, GetLevel()->GetMainCamera()->Transform.GetWorldPosition().Y+160 });
}
