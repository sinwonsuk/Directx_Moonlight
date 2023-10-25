#include "PreCompile.h"
#include "CameraCollision.h"

CameraCollision::CameraCollision()
{
}

CameraCollision::~CameraCollision()
{
}

void CameraCollision::Start()
{

	{
		Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::CameraCollision);
		Col->Transform.SetLocalScale({ 1280.0f,720.0f });
		Col->SetCollisionType(ColType::AABBBOX2D);
	}

}

void CameraCollision::Update(float _Delta)
{
	Col->Transform.SetWorldPosition({ GetLevel()->GetMainCamera()->Transform.GetWorldPosition().X, GetLevel()->GetMainCamera()->Transform.GetWorldPosition().Y});

}
