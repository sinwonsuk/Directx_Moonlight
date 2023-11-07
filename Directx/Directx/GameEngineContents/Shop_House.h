#pragma once
#include <GameEngineCore/GameEngineActor.h>

// ���� :
class Shop_House : public GameEngineActor
{
public:

public:
	// constrcuter destructer
	Shop_House();
	~Shop_House();

	// delete Function
	Shop_House(const Shop_House& _Other) = delete;
	Shop_House(Shop_House&& _Other) noexcept = delete;
	Shop_House& operator=(const Shop_House& _Other) = delete;
	Shop_House& operator=(Shop_House&& _Other) noexcept = delete;

	GameEngineColor GetColor(float4 _Pos, GameEngineColor _DefaultColor = { 255, 255, 255, 255 });

	void PixelCollision(float _Delta);
	std::shared_ptr<class Black_Out> black_Out;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	bool check = false;

	bool test = false;

	EventParameter Up_Event;
	EventParameter Down_Event;
	EventParameter Event;
	std::shared_ptr<class GameEngineSpriteRenderer> Shop;
	std::shared_ptr<class GameEngineSpriteRenderer> Shop_02;
	std::shared_ptr<class GameEngineSpriteRenderer> Shop_Table;
	std::shared_ptr<class GameEngineSpriteRenderer> Shop_Counter;
	std::shared_ptr<class GameEngineSpriteRenderer> Shop_Carpet;
	std::shared_ptr<class GameEngineSpriteRenderer> Shop_Stove;
	std::shared_ptr<class GameEngineSpriteRenderer> shop_stove_Fire;
	std::shared_ptr<class GameEngineSpriteRenderer> shop_cauldron;
	std::shared_ptr<class GameEngineSpriteRenderer> shop_Desk;
	std::shared_ptr<class GameEngineSpriteRenderer> shop_Box;
	std::shared_ptr<class GameEngineSpriteRenderer> shop_Bed;
	std::shared_ptr<class GameEngineSpriteRenderer> bed_carpet;
	std::shared_ptr<class GameEngineSpriteRenderer> Room_Stove_Fire;
	std::shared_ptr<class GameEngineSpriteRenderer> Room_Stove;
	std::shared_ptr<class GameEngineSpriteRenderer> Shop_door;
	std::shared_ptr<class GameEngineSpriteRenderer> Pixel;
	std::shared_ptr<class GameEngineSpriteRenderer> Black;


	std::shared_ptr<GameEngineCollision> Down_Col;
	std::shared_ptr<GameEngineCollision> Up_Col;

	std::shared_ptr<GameEngineCollision> Col;
	std::shared_ptr<GameEngineCollision> Change_Town;

	
	bool CameraMove = false;

	bool Up_CameraMove = false;


};

