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

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:

	EventParameter Event;

	std::shared_ptr<class GameEngineSpriteRenderer> Shop;

	std::shared_ptr<class GameEngineSpriteRenderer> Black;


	std::shared_ptr<GameEngineCollision> Col;
	
	bool CameraMove = false;




};

