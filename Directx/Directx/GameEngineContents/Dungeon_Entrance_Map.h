#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Dungeon_Entrance_Map : public GameEngineActor
{
public:

public:
	// constrcuter destructer
	Dungeon_Entrance_Map();
	~Dungeon_Entrance_Map();

	// delete Function
	Dungeon_Entrance_Map(const Dungeon_Entrance_Map& _Other) = delete;
	Dungeon_Entrance_Map(Dungeon_Entrance_Map&& _Other) noexcept = delete;
	Dungeon_Entrance_Map& operator=(const Dungeon_Entrance_Map& _Other) = delete;
	Dungeon_Entrance_Map& operator=(Dungeon_Entrance_Map&& _Other) noexcept = delete;

	
	void PixelCollision(float _Delta);
	GameEngineColor GetColor(float4 _Pos, GameEngineColor _DefaultColor = { 255, 255, 255, 255 });

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	

	
	std::shared_ptr<class GameEngineSpriteRenderer> BackGround;
	std::shared_ptr<class GameEngineSpriteRenderer> DungeonsEntrance_Top;
	std::shared_ptr<class GameEngineSpriteRenderer> Shop_Table;
	std::shared_ptr<class GameEngineSpriteRenderer> Shop_Counter;
	std::shared_ptr<class GameEngineSpriteRenderer> Shop_Carpet;
	std::shared_ptr<class GameEngineSpriteRenderer> Shop_Stove;
	std::shared_ptr<class GameEngineSpriteRenderer> Dungeon_Entrance_Pixel;

	bool check = false;
	

	std::shared_ptr<GameEngineCollision> Change_Dungeon;
	std::shared_ptr<GameEngineCollision> Change_Town;



};