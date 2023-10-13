#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
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

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	bool check = false;
	EventParameter Up_Event;
	EventParameter Down_Event;
	std::shared_ptr<class GameEngineSpriteRenderer> Shop;
	std::shared_ptr<class GameEngineSpriteRenderer> Shop_02;
	std::shared_ptr<class GameEngineSpriteRenderer> Shop_Table;
	std::shared_ptr<class GameEngineSpriteRenderer> Shop_Counter;
	std::shared_ptr<class GameEngineSpriteRenderer> Shop_Carpet;
	std::shared_ptr<class GameEngineSpriteRenderer> Shop_Stove;
	std::shared_ptr<class GameEngineSpriteRenderer> shop_stove_Fire;
	std::shared_ptr<class GameEngineSpriteRenderer> shop_cauldron;
	std::shared_ptr<class GameEngineSpriteRenderer> sdsdsds;
	std::shared_ptr<class GameEngineSpriteRenderer> Black;


	std::shared_ptr<GameEngineCollision> Down_Col;
	std::shared_ptr<GameEngineCollision> Up_Col;

	std::shared_ptr<GameEngineCollision> Col;

	bool CameraMove = false;

	bool Up_CameraMove = false;


};

