#include "PreCompile.h"
#include "TutorialLevel.h"
#include "TutorialMap.h"
#include "TutorialMap_02.h"
#include "TutorialMap_03.h"
#include "TutorialMap_04.h"
#include "Tutorial_Map_05.h"
#include "Tutorial_Map_06.h"
#include "Player.h"
#include "Player_UI.h"
TutorialLevel::TutorialLevel()
{

}

TutorialLevel::~TutorialLevel()
{

}

void TutorialLevel::Start()
{
	{
		// 엔진용 쉐이더를 전부다 전부다 로드하는 코드를 친다.
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources");
		Dir.MoveChild("Texture");
		std::vector<GameEngineFile> Files = Dir.GetAllFile();

		for (size_t i = 0; i < Files.size(); i++)
		{
			// 구조적으로 잘 이해하고 있는지를 자신이 명확하게 인지하기 위해서
			GameEngineFile& File = Files[i];
			GameEngineTexture::Load(File.GetStringPath());
		}


		GameEngineSprite::CreateCut("spearHitEffect_3.png", 3, 1);

	}


	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources");
		Dir.MoveChild("FolderTexture");
		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			// 구조적으로 잘 이해하고 있는지를 자신이 명확하게 인지하기 위해서
			GameEngineDirectory& Dir = Directorys[i];

			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}




	}

	GameEngineSprite::CreateSingle("Button_E.png");
	GameEngineSprite::CreateSingle("Button_I.png");
	GameEngineSprite::CreateSingle("Button_J.png");
	GameEngineSprite::CreateSingle("Button_K.png");
	GameEngineSprite::CreateSingle("Button_Space.png");
	GameEngineSprite::CreateSingle("Button_Z.png");
	GameEngineSprite::CreateSingle("Circle.png");
	GameEngineSprite::CreateSingle("HealthBar_Base.png");
	GameEngineSprite::CreateSingle("Heart.png");
	GameEngineSprite::CreateSingle("Hp_Bar.png");
	GameEngineSprite::CreateSingle("Pocket.png");
	GameEngineSprite::CreateSingle("Bag.png");
	GameEngineSprite::CreateSingle("Training_Spear.png");
	GameEngineSprite::CreateSingle("MiniWill.png");

	GameEngineSprite::CreateSingle("Attack_Roll_Scroll.png");
	GameEngineSprite::CreateSingle("Cliff_Roll_Scroll.png");
	GameEngineSprite::CreateSingle("Enemy_Roll_Scroll.png");
	GameEngineSprite::CreateSingle("Portion_Roll_Scroll.png");
	GameEngineSprite::CreateSingle("Roll_Scroll.png");



	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();

	GetMainCamera()->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, 15000.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

	/*{
		std::shared_ptr<Player> Object = CreateActor<Player>();
	}*/

	{
		std::shared_ptr<TutorialMap> Object = CreateActor<TutorialMap>();
	}

	//{
	//	std::shared_ptr<TutorialMap_02> Object = CreateActor<TutorialMap_02>();
	//}
	//{
	//	std::shared_ptr<TutorialMap_03> Object = CreateActor<TutorialMap_03>();
	//}
	//{
	//	std::shared_ptr<TutorialMap_04> Object = CreateActor<TutorialMap_04>();
	//}
	//{
	//	std::shared_ptr<TutorialMap_05> Object = CreateActor<TutorialMap_05>();
	//}
	//{
	//	std::shared_ptr<TutorialMap_06> Object = CreateActor<TutorialMap_06>();
	//}

	//{
	//	std::shared_ptr<Player_UI> Object = CreateActor<Player_UI>();
	//}
	GameEngineInput::AddInputObject(this);
}

void TutorialLevel::Update(float _Delta)
{
	if (GameEngineInput::IsPress('1', this))
	{
		GameEngineCore::ChangeLevel("WorldLevel");
	}
	/*if (GameEngineInput::IsPress('A'))
	{
		GetCamera(0)->Transform.AddLocalPosition(float4::LEFT * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('D'))
	{
		GetCamera(0)->Transform.AddLocalPosition(float4::RIGHT * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('W'))
	{
		GetCamera(0)->Transform.AddLocalPosition(float4::UP * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('S'))
	{
		GetCamera(0)->Transform.AddLocalPosition(float4::DOWN * _Delta * Speed);
	}*/
	float4 awdd = GetMainCamera()->Transform.GetLocalPosition();

	TransformData Data = GetMainCamera()->Transform.GetConstTransformDataRef(); 

	float4x4 sda = Data.WorldViewProjectionMatrix;

	int a = 0; 

	//OutputDebugStringA(sda.ToString("\n").c_str());
}

void TutorialLevel::LevelStart(GameEngineLevel* _PrevLevel)
{

}

void TutorialLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	Player::this_Player->Death();
	Player::this_Player = nullptr;
	
}
