#pragma once
#include <GameEngineCore/GameEngineActor.h>

// 설명 :
class TownMap : public GameEngineActor
{
public:
	
public:
	// constrcuter destructer
	TownMap();
	~TownMap();

	// delete Function
	TownMap(const TownMap& _Other) = delete;
	TownMap(TownMap&& _Other) noexcept = delete;
	TownMap& operator=(const TownMap& _Other) = delete;
	TownMap& operator=(TownMap&& _Other) noexcept = delete;

	GameEngineColor GetColor(float4 _Pos, GameEngineColor _DefaultColor = {255, 255, 255, 255});

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:

	EventParameter Event;
	bool check = false;
	// 맵 
	std::shared_ptr<class GameEngineSpriteRenderer> BackGround;


	// 주인공 집 
	std::shared_ptr<class GameEngineSpriteRenderer> Will_House;
	std::shared_ptr<class GameEngineSpriteRenderer> Will_House_animation;
	std::shared_ptr<class GameEngineSpriteRenderer> Will_House_WoodBox;
	std::shared_ptr<class GameEngineSpriteRenderer> Will_House_Object;
	std::shared_ptr<class GameEngineSpriteRenderer> Will_House_OilLamp;
	std::shared_ptr<class GameEngineSpriteRenderer> Will_House_sign;
	std::shared_ptr<class GameEngineSpriteRenderer> Village_Left_Rival_Fence;
	std::shared_ptr<class GameEngineSpriteRenderer> Village_Down_Rival_Fence;
	std::shared_ptr<class GameEngineSpriteRenderer> Village_Right_Rival_Fence;
	std::shared_ptr<class GameEngineSpriteRenderer> Village_Up_Rival_Fence;
	std::shared_ptr<class GameEngineSpriteRenderer> Will_House_Big_Tree;
	std::shared_ptr<class GameEngineSpriteRenderer> Will_House_Tree;
	std::shared_ptr<class GameEngineSpriteRenderer> Will_House_Tree_02;
	std::shared_ptr<class GameEngineSpriteRenderer> Dungeon;
	std::shared_ptr<class GameEngineSpriteRenderer> tree_stump;



	//주인공 옆

	std::shared_ptr<class GameEngineSpriteRenderer> Wood_Box_Strong;
	std::shared_ptr<class GameEngineSpriteRenderer> House_04;
	std::shared_ptr<class GameEngineSpriteRenderer> House_04_Tent;

	// 공원 

	std::shared_ptr<class GameEngineSpriteRenderer> Park_Right_Up_Tree;
	std::shared_ptr<class GameEngineSpriteRenderer> Park_Middle_Up_Tree;
	std::shared_ptr<class GameEngineSpriteRenderer> Park_Middle_Up_Bench;
	std::shared_ptr<class GameEngineSpriteRenderer> Park_Middle_Up_OilLamp;
	std::shared_ptr<class GameEngineSpriteRenderer> Park_Left_Up_Bench;
	std::shared_ptr<class GameEngineSpriteRenderer> Park_Left_Middle_Tree;
	std::shared_ptr<class GameEngineSpriteRenderer> Park_Left_Bottom_Tree;
	std::shared_ptr<class GameEngineSpriteRenderer> Park_Middle_Left_Bench;

	std::shared_ptr<class GameEngineSpriteRenderer> Park_Left_Bottom_OilLamp;
	std::shared_ptr<class GameEngineSpriteRenderer> Park_Left_Bottom_Bench;
	std::shared_ptr<class GameEngineSpriteRenderer> Park_Middle_Bottom_Tree;
	std::shared_ptr<class GameEngineSpriteRenderer> Park_Right_Bottom_Tree;
	std::shared_ptr<class GameEngineSpriteRenderer> Park_Barrel;

	// 위 도로 오브젝트 

	std::shared_ptr<class GameEngineSpriteRenderer> Village_Board;
	std::shared_ptr<class GameEngineSpriteRenderer> Boxs;
	std::shared_ptr<class GameEngineSpriteRenderer> Road_Up_Object;


	// 대장간 
	std::shared_ptr<class GameEngineSpriteRenderer> Village_Rival_House;
	std::shared_ptr<class GameEngineSpriteRenderer> Village_Rival_House_Roof;
	std::shared_ptr<class GameEngineSpriteRenderer> Village_Rival_Desk;
	std::shared_ptr<class GameEngineSpriteRenderer> Village_Rival_Flowerpot_01;
	std::shared_ptr<class GameEngineSpriteRenderer> Village_Rival_OilLamp;
	std::shared_ptr<class GameEngineSpriteRenderer> Village_Rival_Flowerpot_02;
	std::shared_ptr<class GameEngineSpriteRenderer> Village_Rival_Flowerpot_03;
	std::shared_ptr<class GameEngineSpriteRenderer> Village_Rival_Fountain;

	// 마녀의 집 
	std::shared_ptr<class GameEngineSpriteRenderer> Village_WitchHome;
	std::shared_ptr<class GameEngineSpriteRenderer> Village_Witch_Table_old;
	std::shared_ptr<class GameEngineSpriteRenderer> Village_Witch_House_old;
	std::shared_ptr<class GameEngineSpriteRenderer> Village_Witch_Roof_old;
	std::shared_ptr<class GameEngineSpriteRenderer> Village_Witch_Storage_old;
	std::shared_ptr<class GameEngineSpriteRenderer> Village_Witch_OilLamp;

	// Npc 하우스 


	std::shared_ptr<class GameEngineSpriteRenderer> Village_House_04;
	std::shared_ptr<class GameEngineSpriteRenderer> Village_House_05;
	std::shared_ptr<class GameEngineSpriteRenderer> Village_House_06;
	std::shared_ptr<class GameEngineSpriteRenderer> Village_House_06_OilLamp;

	// 스미스 하우스 

	std::shared_ptr<class GameEngineSpriteRenderer> Village_Blacksmith_Fence;
	std::shared_ptr<class GameEngineSpriteRenderer> Village_Blacksmith_Stand2_old;
	std::shared_ptr<class GameEngineSpriteRenderer> Village_Blacksmith_Stand1_old;
	std::shared_ptr<class GameEngineSpriteRenderer> Village_Blacksmith_House;
	std::shared_ptr<class GameEngineSpriteRenderer> Village_Blacksmith_Roof_old;


	//돌 
	std::shared_ptr<class GameEngineSpriteRenderer> Village_BigStone;
	std::shared_ptr<class GameEngineSpriteRenderer> Village_BigStone_02;
	// 나무 
	std::shared_ptr<class GameEngineSpriteRenderer> Up_Tree_01;
	std::shared_ptr<class GameEngineSpriteRenderer> Up_Tree_02;
	std::shared_ptr<class GameEngineSpriteRenderer> Up_Tree_03;
	std::shared_ptr<class GameEngineSpriteRenderer> Up_Tree_04;
	std::shared_ptr<class GameEngineSpriteRenderer> Big_Up_Tree_01;

	std::shared_ptr<class GameEngineSpriteRenderer> Middle_Tree_01;
	std::shared_ptr<class GameEngineSpriteRenderer> Middle_Tree_02;
	std::shared_ptr<class GameEngineSpriteRenderer> Big_Middle_Tree_01;
	
	std::shared_ptr<class GameEngineSpriteRenderer> Bottom_Tree_01;
	std::shared_ptr<class GameEngineSpriteRenderer> Bottom_Tree_02;
	std::shared_ptr<class GameEngineSpriteRenderer> Bottom_Tree_03;
	std::shared_ptr<class GameEngineSpriteRenderer> Bottom_Tree_04;
	std::shared_ptr<class GameEngineSpriteRenderer> Bottom_Tree_05;
	std::shared_ptr<class GameEngineSpriteRenderer> Bottom_Tree_06;
	std::shared_ptr<class GameEngineSpriteRenderer> Bottom_Tree_07;
	std::shared_ptr<class GameEngineSpriteRenderer> Bottom_Tree_08;
	std::shared_ptr<class GameEngineSpriteRenderer> Bottom_Tree_09;
	std::shared_ptr<class GameEngineSpriteRenderer> Bottom_Tree_10;
	std::shared_ptr<class GameEngineSpriteRenderer> Bottom_Tree_11;
	std::shared_ptr<class GameEngineSpriteRenderer> Bottom_Tree_12;
	// 박스 
	std::shared_ptr<class GameEngineSpriteRenderer> Middle_Box_01;
	std::shared_ptr<class GameEngineSpriteRenderer> Middle_Box_02;
	std::shared_ptr<class GameEngineSpriteRenderer> Middle_Box_03;

	std::shared_ptr<class GameEngineSpriteRenderer> Bottom_Box_01;
	std::shared_ptr<class GameEngineSpriteRenderer> Bottom_Box_02;
	std::shared_ptr<class GameEngineSpriteRenderer> Bottom_Box_03;
	std::shared_ptr<class GameEngineSpriteRenderer> Bottom_Box_04;
	std::shared_ptr<class GameEngineSpriteRenderer> Bottom_Box_05;
	std::shared_ptr<class GameEngineSpriteRenderer> Bottom_Box_06;


	// 우물 

	std::shared_ptr<class GameEngineSpriteRenderer> Village_Well_animation;


	std::shared_ptr<GameEngineCollision> Col;
	std::shared_ptr<GameEngineCollision> Col_02;
	std::shared_ptr<GameEngineCollision> Col_03;
	std::shared_ptr<GameEngineCollision> Col_04;





	
};

