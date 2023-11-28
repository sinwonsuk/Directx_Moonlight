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
	std::shared_ptr<class Black_Out> black_Out;
	std::shared_ptr<class Black_Out> black_Out_02;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:


	
	std::shared_ptr<class GameEngineSpriteRenderer> BackGround;
	std::shared_ptr<class GameEngineSpriteRenderer> DungeonsEntrance_Top;
	std::shared_ptr<class GameEngineSpriteRenderer> Dungeon_Door;
	std::shared_ptr<class GameEngineSpriteRenderer> Dungeon_Door_02;
	std::shared_ptr<class GameEngineSpriteRenderer> Dungeon_Door_03;
	std::shared_ptr<class GameEngineSpriteRenderer> Dungeon_Door_04;
	std::shared_ptr<class GameEngineSpriteRenderer> Dungeon_Entrance_Pixel;
	std::shared_ptr<class GameEngineSpriteRenderer> Dungeon_Open;
	std::shared_ptr<class GameEngineSpriteRenderer> Dungeon_Close;
	bool check = false;

	bool CollisionCheck = false;
	

	std::shared_ptr<GameEngineCollision> Change_Dungeon;
	std::shared_ptr<GameEngineCollision> Change_Town;
	std::shared_ptr<GameEngineCollision> Dungeon_Near;


	std::shared_ptr<GameEngineCollision> Dungeon_Door_Col;
	bool Black_Check_02 = false;
	bool Black_Check = false;
};