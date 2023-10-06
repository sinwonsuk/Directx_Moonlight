#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
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
	bool check = false;
	std::shared_ptr<class GameEngineSpriteRenderer> BackGround;
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

	std::shared_ptr<class GameEngineSpriteRenderer> Wood_Box_Strong;

	std::shared_ptr<class GameEngineSpriteRenderer> House_04;
	std::shared_ptr<class GameEngineSpriteRenderer> House_04_Tent;
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
	std::shared_ptr<class GameEngineSpriteRenderer> Village_Board;

};

