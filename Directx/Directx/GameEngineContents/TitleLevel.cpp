#include "PreCompile.h"
#include "TitleLevel.h"
#include "Title.h"
#include <GameEnginePlatform/GameEngineSound.h>

TitleLevel::TitleLevel() 
{
}

TitleLevel::~TitleLevel() 
{
}

void TitleLevel::Start()
{
	GameEngineInput::AddInputObject(this);

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




	GetMainCamera()->Transform.SetLocalPosition({ 0.0f, 0.0f, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);


	std::shared_ptr<Title> Object = CreateActor<Title>(TitleOrder::Title);

	GameEngineDirectory NewDir;
	NewDir.MoveParentToExistsChild("GameEngineResources");
	NewDir.MoveChild("ContentsResources");
	NewDir.MoveChild("Sound");

	GameEngineSound::SoundLoad(NewDir.PlusFilePath("main_menu_screen.wav"));
	GameEngineSound::SoundLoad(NewDir.PlusFilePath("will_step_golem_dungeon.wav"));
	GameEngineSound::SoundLoad(NewDir.PlusFilePath("tutorial_scroll.wav"));
	GameEngineSound::SoundLoad(NewDir.PlusFilePath("golem_dungeon_floor.wav"));
	GameEngineSound::SoundLoad(NewDir.PlusFilePath("will_roll.wav"));
	GameEngineSound::SoundLoad(NewDir.PlusFilePath("golem_dungeon_turret_shot.wav"));
	GameEngineSound::SoundLoad(NewDir.PlusFilePath("golem_dungeon_babyslime_hit.wav"));
	GameEngineSound::SoundLoad(NewDir.PlusFilePath("golem_dungeon_slime_pop.wav"));
	GameEngineSound::SoundLoad(NewDir.PlusFilePath("will_damaged.wav"));
	GameEngineSound::SoundLoad(NewDir.PlusFilePath("gui_selector_pick.wav"));
	GameEngineSound::SoundLoad(NewDir.PlusFilePath("spear_main_attack_swing2.wav"));
	GameEngineSound::SoundLoad(NewDir.PlusFilePath("spear_main_attack_swing3.wav"));
	GameEngineSound::SoundLoad(NewDir.PlusFilePath("spear_main_attack_swing.wav"));

	GameEngineSound::SoundLoad(NewDir.PlusFilePath("golem_dungeon_golem_roll.wav"));
	GameEngineSound::SoundLoad(NewDir.PlusFilePath("golem_dungeon_soldier_sword_crash.wav"));
	GameEngineSound::SoundLoad(NewDir.PlusFilePath("golem_dungeon_golem_hit.wav"));
	GameEngineSound::SoundLoad(NewDir.PlusFilePath("enemy_death.wav"));
	GameEngineSound::SoundLoad(NewDir.PlusFilePath("golem_dungeon_normal_door_closing.wav"));
	GameEngineSound::SoundLoad(NewDir.PlusFilePath("golem_dungeon_normal_door_opening.wav"));
	GameEngineSound::SoundLoad(NewDir.PlusFilePath("will_death.wav"));
	GameEngineSound::SoundLoad(NewDir.PlusFilePath("will_shop_bed_wake.wav"));

	GameEngineSound::SoundLoad(NewDir.PlusFilePath("shop_day_open.wav"));

	GameEngineSound::SoundLoad(NewDir.PlusFilePath("gui_selector_movement.wav"));
	GameEngineSound::SoundLoad(NewDir.PlusFilePath("gui_inventory_open.wav"));

	GameEngineSound::SoundLoad(NewDir.PlusFilePath("gui_inventory_open.wav"));

	GameEngineSound::SoundLoad(NewDir.PlusFilePath("shop_visitor_enters_shop_bell.wav"));
	GameEngineSound::SoundLoad(NewDir.PlusFilePath("shop_door_closing.wav"));
	GameEngineSound::SoundLoad(NewDir.PlusFilePath("shop_item_sold.wav"));
	GameEngineSound::SoundLoad(NewDir.PlusFilePath("visitor_talk_too_cheap.wav"));
	GameEngineSound::SoundLoad(NewDir.PlusFilePath("rynoka_day_normal.wav"));

	GameEngineSound::SoundLoad(NewDir.PlusFilePath("blacksmith_open_gui.wav"));
	GameEngineSound::SoundLoad(NewDir.PlusFilePath("blacksmith_craft_weapon.wav"));

	GameEngineSound::SoundLoad(NewDir.PlusFilePath("witch_open_gui.wav"));
	GameEngineSound::SoundLoad(NewDir.PlusFilePath("witch_craft_potion.wav"));


	/*GameEngineSound::Load(NewDir.GetPlusFileName("cuphead-opening-theme.mp3").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_player_weapon_peashot_death_001.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_player_weapon_upshot_loop_01.wav").GetFullPath());

	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_player_weapon_upshot_loop_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("MUS_Tutorial.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_player_jump_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_player_dash_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_player_weapon_crackshot_turret_parryexplode.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_player_parry_slap_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("bgm_map_world_1.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("a-good-day-for-a-swell-battle.mp3").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("cuphead-a-knockout.mp3").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_BulldogPlane_Loop.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("mus_dlc_dogfight_a.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_BulldogPlane_IntroFlyby.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_PlayerPlane_Loop.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P1_Bulldog_EjectUp.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P1_Bulldog_EjectDown.wav").GetFullPath());

	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P1_TerrierPlane_Bark_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P1_DogFlexHugoVocal_02.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P1_DogFlexHugoVocal_04.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P1_Bulldog_Boneshot_01.wav").GetFullPath());

	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P1_TerrierPlane_Baseball_Whistle_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P1_CatGun_Shoot_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P1_Bulldog_PlaneExplodes.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P2_TerrierJetpack_BarkShoot_06.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P2_TerrierJetpack_Loop.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P2_TerrierJetpack_Explosion_01.wav").GetFullPath());

	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P3_DogCopter_Intro.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P3_DogCopter_Laser_BuildOut_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P3_DogCopter_Laser_Fire_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P3_DogCopter_Laser_Fire_03.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P3_DogCopter_Settle_GrabScreen.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P3_DogCopter_Laser_Fire_03.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P3_DogCopter_ScreenRotate.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_DLC_Dogfight_P3_DogCopter_DogBowl_Fire_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("cuphead-a-knockout.mp3").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_player_hit_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_player_death_01.wav").GetFullPath());

	GameEngineSound::Load(NewDir.GetPlusFileName("clown_dash_start_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_clown_clown_dash_end_03.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("Clown_Music.mp3").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("clown_bumper_death_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("clown_regular_duck_spin_01.wav").GetFullPath());

	GameEngineSound::Load(NewDir.GetPlusFileName("clown_coaster_main_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_level_clown_warning_lights_loop_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_clown_coaster_ratchet_loop.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("clown_bumper_move_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("clown_helium_intro_continue_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("clown_intro_continue_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("clown_dog_balloon_regular_intro_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("clown_dog_balloon_regular_death_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("clown_horse_head_spit_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("clown_horseshoe_land_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("clown_horseshoe_drop_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("clown_horse_clown_fall_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("clown_horse_death_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("clown_swing_face_intro_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("clown_swing_open_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("clown_swing_face_attack_intro_02.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("clown_penguin_roll_end_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("clown_penguin_death_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("clown_penguin_clap_01.wav").GetFullPath());
	GameEngineSound::Load(NewDir.GetPlusFileName("sfx_player_weapon_peashoot_ex_impact_02.wav").GetFullPath());

	GameEngineSound::Load(NewDir.GetPlusFileName("MUS_GoodEnding.wav").GetFullPath());*/



}




void TitleLevel::Update(float _Delta)
{
	
}
 

void TitleLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	sound = GameEngineSound::SoundPlay("main_menu_screen.wav");

	
}

void TitleLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	sound.Stop();
	int a = 0;
}