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
	std::shared_ptr<class GameEngineSpriteRenderer> BackGround;
	std::shared_ptr<class GameEngineSpriteRenderer> Will_House;
	std::shared_ptr<class GameEngineSpriteRenderer> Will_House_animation;
	std::shared_ptr<class GameEngineSpriteRenderer> Will_House_WoodBox;
	std::shared_ptr<class GameEngineSpriteRenderer> Will_House_Object;
	std::shared_ptr<class GameEngineSpriteRenderer> Will_House_OilLamp;
	std::shared_ptr<class GameEngineSpriteRenderer> Will_House_sign;


};

