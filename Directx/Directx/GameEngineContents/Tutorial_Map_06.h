#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Tutorial_Map_Manager.h"
class TutorialMap_06 : public GameEngineActor, public Tutorial_Map_Manager
{
public:
	// constrcuter destructer
	TutorialMap_06();
	~TutorialMap_06();

	// delete Function
	TutorialMap_06(const TutorialMap_06& _Other) = delete;
	TutorialMap_06(TutorialMap_06&& _Other) noexcept = delete;
	TutorialMap_06& operator=(const TutorialMap_06& _Other) = delete;
	TutorialMap_06& operator=(TutorialMap_06&& _Other) noexcept = delete;



protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	bool PlayerCheck = false;
	std::shared_ptr<class GameEngineSpriteRenderer> BackGround;
	std::shared_ptr<class GameEngineSpriteRenderer> Map_floor_01;
	std::shared_ptr<class GameEngineSpriteRenderer> LeftDoor;
	std::shared_ptr<class GameEngineSpriteRenderer> RightDoor;
	std::shared_ptr<GameEngineCollision> Collision_Door;
	float TimeCheck = 0.0f;
	GameEngineRandom Random;

};