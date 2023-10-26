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

}

void CameraCollision::Update(float _Delta)
{
	Col->Transform.SetWorldPosition({ GetLevel()->GetMainCamera()->Transform.GetWorldPosition().X, GetLevel()->GetMainCamera()->Transform.GetWorldPosition().Y});

}
