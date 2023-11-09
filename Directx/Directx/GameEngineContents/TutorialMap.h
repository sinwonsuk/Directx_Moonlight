#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Tutorial_Map_Manager.h"

class TutorialMap : public GameEngineActor , public Tutorial_Map_Manager
{
public:
	// constrcuter destructer
	TutorialMap();
	~TutorialMap();

	// delete Function
	TutorialMap(const TutorialMap& _Other) = delete;
	TutorialMap(TutorialMap&& _Other) noexcept = delete;
	TutorialMap& operator=(const TutorialMap& _Other) = delete;
	TutorialMap& operator=(TutorialMap&& _Other) noexcept = delete;




protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	float Map_Number = 200.0f; 
	std::shared_ptr<class GameEngineSpriteRenderer> BackGround;
	std::shared_ptr<class GameEngineSpriteRenderer> Map_floor_01;
	std::shared_ptr<class GameEngineSpriteRenderer> LeftDoor;
	std::shared_ptr<class GameEngineSpriteRenderer> RightDoor;
	std::shared_ptr<class GameEngineSpriteRenderer> Scroll;
	std::shared_ptr<GameEngineCollision> Collision_Door;
	std::shared_ptr<GameEngineSpriteRenderer> Pixel;
	bool check = false;
};