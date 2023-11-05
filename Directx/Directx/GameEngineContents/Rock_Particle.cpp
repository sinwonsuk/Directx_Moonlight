#include "PreCompile.h"
#include "Rock_Particle.h"

Rock_Particle::Rock_Particle()
{

}

Rock_Particle::~Rock_Particle()
{

}

void Rock_Particle::Start()
{
	Rock = CreateComponent<GameEngineSpriteRenderer>();
	Rock->SetSprite("Boos1_Rock Particles", 0);
	Rock->AutoSpriteSizeOn();
	Rock->SetAutoScaleRatio(1.0f);
}

void Rock_Particle::Update(float _Delta)
{
	Time += _Delta; 
	

	if (RockCheck == false)
	{
		int A = Random.RandomInt(0, 3);

		Pos_X = Random.RandomInt(-1, 1);
		Pos_Y = Random.RandomFloat(-1, 1);
		Height = Random.RandomFloat(10, 11);

		switch (A)
		{
		case 0:
		{
			Rock->SetSprite("Boos1_Rock", A);
		}
		break;

		case 1:
		{
			Rock->SetSprite("Boos1_Rock", A);
		}
		break;
		case 2:
		{
			Rock->SetSprite("Boos1_Rock", A);
		}
		break;
		case 3:
		{
			Rock->SetSprite("Boos1_Rock", A);
		}
		break;
		case 4:
		{
			Rock->SetSprite("Boos1_Rock", A);
		}
		break;
		case 5:
		{
			Rock->SetSprite("Boos1_Rock", A);
		}
		break;

		default:
			break;
		}
		
		RockCheck = true;
	}



	if ( gravity==true)
	{
		Transform.AddWorldPosition(float4{ float(Pos_X),Pos_Y }*200.0f * _Delta);
	}
	
	
	asd += { float4::DOWN * Height* _Delta };
	
	if (gravity == true)
	{
		Transform.AddWorldPosition({ asd });
		Transform.AddWorldRotation({ 0.0f,0.0f,asd.Y });
		
	}
	


	if (Transform.GetWorldPosition().Y <= BossPos.Y - 20.0f)
	{
		gravity = false;
	}

	if (gravity == false )
	{
		Number -= _Delta*2;
		Rock->GetColorData().MulColor = { 1,1,1,Number };
	
		int a = 0;
	}
	


	if (Number <= 0.2)
	{
		this->Death(); 
	}











}
