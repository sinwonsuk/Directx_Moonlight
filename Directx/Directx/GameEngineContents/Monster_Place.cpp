#include "PreCompile.h"
#include "Monster_Place.h"

#include "BabySlime.h"
#include "golem_Solder.h"
#include "golem_Stone.h"
#include "golem_Wizard.h"
#include "SlimeHermit.h"

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
	


	srand((unsigned)time(NULL));

	Random_number = rand() % 6 + 2;

	Random_Monster = rand() % 5;

	//int Random_Monster = rand() % 5;

	
	for (size_t i = 0; i <= Random_number; i++)
	{
		srand((unsigned)time(NULL));
		Random_Monster = rand() % 5;
		

	

		
		//Random.RandomVectorBox2D(Left_Top, Right_Top, Bottom_Bottom, Top_Bottom);
		//Random.SetSeed(Random_A++);

		//GameEngineRandom Random_Mon;
		int A = Random2.RandomInt(0, 4);

	

		//Random.SetSeed(Random_B++);

		switch (A)
		{
		case 0:
		{
			std::shared_ptr<BabySlime> Object = GetLevel()->CreateActor<BabySlime>();
			Object->Transform.SetLocalPosition(Random.RandomVectorBox2D(Left_Top, Right_Top, Bottom_Bottom, Top_Bottom));
			Random.SetSeed(Random_A++);


			/*std::shared_ptr<golem_Solder> Object = GetLevel()->CreateActor<golem_Solder>();
			Object->Transform.SetLocalPosition(Random.RandomVectorBox2D(Left_Top, Right_Top, Bottom_Bottom, Top_Bottom));*/
			break;
		}
		case 1:
		{
			std::shared_ptr<golem_Solder> Object = GetLevel()->CreateActor<golem_Solder>();
			Object->Transform.SetLocalPosition(Random.RandomVectorBox2D(Left_Top, Right_Top, Bottom_Bottom, Top_Bottom));
			Random.SetSeed(Random_A++);
			break;
		}
		case 2:
		{
			std::shared_ptr<golem_Stone> Object = GetLevel()->CreateActor<golem_Stone>();
			Object->Transform.SetLocalPosition(Random.RandomVectorBox2D(Left_Top, Right_Top, Bottom_Bottom, Top_Bottom));
			Random.SetSeed(Random_A++);

			/*std::shared_ptr<golem_Solder> Object = GetLevel()->CreateActor<golem_Solder>();
			Object->Transform.SetLocalPosition(Random.RandomVectorBox2D(Left_Top, Right_Top, Bottom_Bottom, Top_Bottom));*/
			break;
		}
		case 3:
		{
			std::shared_ptr<golem_Wizard> Object = GetLevel()->CreateActor<golem_Wizard>();
			Object->Transform.SetLocalPosition(Random.RandomVectorBox2D(Left_Top, Right_Top, Bottom_Bottom, Top_Bottom));
			Random.SetSeed(Random_A++);

			/*std::shared_ptr<golem_Solder> Object = GetLevel()->CreateActor<golem_Solder>();
			Object->Transform.SetLocalPosition(Random.RandomVectorBox2D(Left_Top, Right_Top, Bottom_Bottom, Top_Bottom));*/
			break;
		}
		case 4:
		{
			std::shared_ptr<SlimeHermit> Object = GetLevel()->CreateActor<SlimeHermit>();
			Object->Transform.SetLocalPosition(Random.RandomVectorBox2D(Left_Top, Right_Top, Bottom_Bottom, Top_Bottom));
			Random.SetSeed(Random_A++);

			/*std::shared_ptr<golem_Solder> Object = GetLevel()->CreateActor<golem_Solder>();
			Object->Transform.SetLocalPosition(Random.RandomVectorBox2D(Left_Top, Right_Top, Bottom_Bottom, Top_Bottom));*/
			break;
		}
		default:
			break;
		}
	}



	
}

void Monster_Place::Start()
{

}


void Monster_Place::Update(float _Delta)
{
	if (test == false)
	{
		Monsters({ sd });
		test = true;
	}
	










}
