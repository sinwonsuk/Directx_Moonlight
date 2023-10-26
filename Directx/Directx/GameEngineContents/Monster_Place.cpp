#include "PreCompile.h"
#include "Monster_Place.h"

#include "BabySlime.h"
#include "golem_Solder.h"
#include "golem_Stone.h"
#include "golem_Wizard.h"
#include "SlimeHermit.h"
#include "MiniBoss.h"
Monster_Place::Monster_Place()
{

}

Monster_Place::~Monster_Place()
{

}

void Monster_Place::Monsters(float4 _Pos)
{
	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	
	// 왼쪽위  
	float Left_Top = _Pos.X - HalfWindowScale.X;

	// 오른쪽 위 
	float Right_Top = _Pos.X + HalfWindowScale.X;

	// 위 아래 

	float Top_Bottom = _Pos.Y + HalfWindowScale.Y;


	// 왼쪽 아래 
	float Bottom_Bottom = _Pos.Y - HalfWindowScale.Y;

	

	// 위치 지정 
	

	Random_B += 1;

	Random3.SetSeed(Random_B);
	Random2.SetSeed(Random_C);
	Random.SetSeed(Random_A);

	int a = Random3.RandomInt(4, 8);


	
	
	for (size_t i = 0; i <= a; i++)
	{
		
		//Random.RandomVectorBox2D(Left_Top, Right_Top, Bottom_Bottom, Top_Bottom);
		//Random.SetSeed(Random_A++);

		//GameEngineRandom Random_Mon;
		//Random2.SetSeed(Random_B++);

		int A = Random2.RandomInt(0, 5); 
		

		//Random.SetSeed(Random_B++);

		switch (A)
		{
		case 0:
		{
			/*while (true)
			{
				Monster_Pos = Random.RandomVectorBox2D(0, 1280, 0, 720);

				if (ObjectCollision(Name.c_str(), Monster_Pos) == true)
				{

					std::shared_ptr<BabySlime> Object = GetLevel()->CreateActor<BabySlime>();
					Object->Transform.SetLocalPosition({ sd.X - 640 + Monster_Pos.X ,  sd.Y + 360 - Monster_Pos.Y });
					break;
				}

				else 
				{
					continue;
				}
			}
			
			break;*/
		}
		case 1:
		{
			while (true)
			{
				Monster_Pos = Random.RandomVectorBox2D(0, 1280, 0, 720);

				if (ObjectCollision(Name.c_str(), Monster_Pos) == true)
				{
					std::shared_ptr<golem_Solder> Object = GetLevel()->CreateActor<golem_Solder>();
					Object->Transform.SetLocalPosition({ sd.X - 640 + Monster_Pos.X ,  sd.Y + 360 - Monster_Pos.Y });
					break;
				}

				else
				{
					continue;
				}
			}
			break;
		}
		case 2:
		{
			/*while (true)
			{
				Monster_Pos = Random.RandomVectorBox2D(0, 1280, 0, 720);

				if (ObjectCollision(Name.c_str(), Monster_Pos) == true)
				{
					std::shared_ptr<golem_Wizard> Object = GetLevel()->CreateActor<golem_Wizard>();
					Object->Transform.SetLocalPosition({ sd.X - 640 + Monster_Pos.X ,  sd.Y + 360 - Monster_Pos.Y });
					break;
				}

				else
				{
					continue;
				}
			}
			break;*/
		}
		case 3:
		{
			/*while (true)
			{
				Monster_Pos = Random.RandomVectorBox2D(0, 1280, 0, 720);

				if (ObjectCollision(Name.c_str(), Monster_Pos) == true)
				{
					std::shared_ptr<golem_Stone> Object = GetLevel()->CreateActor<golem_Stone>();

					Object->Transform.SetLocalPosition({ sd.X - 640 + Monster_Pos.X ,  sd.Y + 360 - Monster_Pos.Y });
					Object->SetPos(sd);
					Object->SetName(Name);
					Object->Set_Basic_Pos({640,-360});
					break;
				}

				else
				{
					continue;
				}
			}
			break;*/
		}
		case 4:
		{
			/*while (true)
			{
				Monster_Pos = Random.RandomVectorBox2D(0, 1280, 0, 720);

				if (ObjectCollision(Name.c_str(), Monster_Pos) == true)
				{
					std::shared_ptr<SlimeHermit> Object = GetLevel()->CreateActor<SlimeHermit>();
					Object->Transform.SetLocalPosition({ sd.X - 640 + Monster_Pos.X ,  sd.Y + 360 - Monster_Pos.Y });
					break;
				}

				else
				{
					continue;
				}
			}
			break;*/
		}
		case 5:
		{
			/*while (true)
			{
				Monster_Pos = Random.RandomVectorBox2D(0, 1280, 0, 720);

				if (ObjectCollision(Name.c_str(), Monster_Pos) == true)
				{
					std::shared_ptr<MiniBoss> Object = GetLevel()->CreateActor<MiniBoss>();
					Object->Transform.SetLocalPosition({ sd.X - 640 + Monster_Pos.X ,  sd.Y + 360 - Monster_Pos.Y });
					break;
				}

				else
				{
					continue;
				}
			}
			break;*/
		}
		default:
			break;
		}
	}
	
	
	
	//Random_A += 5;

	
}

void Monster_Place::Start()
{

}

GameEngineColor Monster_Place::GetColor(float4 _Pos, GameEngineColor _DefaultColor, std::string_view _Name)
{
	//_Pos.Y *= -1.0f;

	std::shared_ptr<GameEngineTexture> Tex = GameEngineTexture::Find(_Name);

	return Tex->GetColor(_Pos, _DefaultColor);
}

bool Monster_Place::ObjectCollision(std::string_view _Name, float4 _Transform)
{

	
	//float4 Ad = { 640,-360 };


	if (GameEngineColor::RED == GetColor({ /*Ad-*/ _Transform }, { 0,0,0,255 }, _Name))
	{
		
		return true; 
	}

	else if (GameEngineColor::RED != GetColor({ /*Ad-*/ _Transform }, { 0,0,0,255 }, _Name))
	{
		return false;
	}
}
void Monster_Place::Update(float _Delta)
{


	int a = 0;

	if (test == false)
	{
		Monsters({ sd });
		test = true;
	}
	










}
