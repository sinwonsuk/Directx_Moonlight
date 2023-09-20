#include "PreCompile.h"
#include "golem_Wizard.h"
#include "Player.h"
#include <math.h>

#include <d3d11_4.h>
#include <d3dcompiler.h>
#include <DirectXPackedVector.h>
#include <DirectXCollision.h>


golem_Wizard::golem_Wizard()
{
}

golem_Wizard::~golem_Wizard()
{
}

void golem_Wizard::Start()
{
	Wizard = CreateComponent<GameEngineSpriteRenderer>(100);
	Wizard->CreateAnimation("golem_Wizard_Down_Attack", "golem_Wizard_Down_Attack", 0.1f, -1, -1, true);
	Wizard->CreateAnimation("golem_Wizard_Down_Move", "golem_Wizard_Down_Move", 0.1f, -1, -1, true);
	Wizard->CreateAnimation("golem_Wizard_Left_Attack", "golem_Wizard_Left_Attack", 0.1f, -1, -1, true);
	Wizard->CreateAnimation("golem_Wizard_Left_Move", "golem_Wizard_Left_Move", 0.1f, -1, -1, true);
	Wizard->CreateAnimation("golem_Wizard_Right_Attack", "golem_Wizard_Right_Attack", 0.1f, -1, -1, true);
	Wizard->CreateAnimation("golem_Wizard_Right_Move", "golem_Wizard_Right_Move", 0.1f, -1, -1, true);
	Wizard->CreateAnimation("golem_Wizard_Up_Attack", "golem_Wizard_Up_Attack", 0.1f, -1, -1, true);
	Wizard->CreateAnimation("golem_Wizard_Up_Move", "golem_Wizard_Up_Move", 0.1f, -1, -1, true);




	Wizard->AutoSpriteSizeOn();
	Wizard->SetAutoScaleRatio(2.0f);
	Wizard->ChangeAnimation("golem_Wizard_Up_Move");

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y });
	

}
float golem_Wizard::Angle( float4 Player,float4 Monster)
{

	


		
		
	//size_t Productdot = (Player.X * Monster.X) + (Player.Y * Monster.Y);
		
	float Dot = float4::DotProduct3D(Player.NormalizeReturn(), Monster.NormalizeReturn());

	float P_Length = sqrt(Player.X * Player.X + Player.Y * Player.Y);
	float M_Length = sqrt(Monster.X * Monster.X + Monster.Y * Monster.Y);



	float angleRad = acos(Dot / (P_Length * M_Length));

	


	float Degree = Dot * (180.0 / 3.141592);

	


	 
	//외적의 z성분으로 방향이 결정된다.

	float angle = (Player.X * Monster.Y - Player.Y * Monster.Y > 0.0f) ? Degree : -Degree;

	return angle;
}
void golem_Wizard::Update(float _Delta)
{
	float4 Player = Player::this_Player->Transform.GetWorldPosition() - Transform.GetWorldPosition();
	float4 Monster = { -1,0,0 };
	float Dot = float4::DotProduct3D(Player.NormalizeReturn(), Monster);
	float radian = atan2(Player.Y, Player.X) - atan2(Monster.Y, Monster.X);
	float Degree = radian * (180.0 / 3.141592);
	
	

	Transform.SetLocalRotation({ 0.0f,0.0f,Degree});

	UpdateState(_Delta); 
}

void golem_Wizard::AnimationCheck(const std::string_view& _AnimationName)
{
	Wizard->ChangeAnimation(_AnimationName);
}

