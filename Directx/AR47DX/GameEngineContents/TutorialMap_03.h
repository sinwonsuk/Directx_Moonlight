#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Tutorial_Map_Manager.h"
class TutorialMap_03 : public GameEngineActor, public Tutorial_Map_Manager
{
public:
	// constrcuter destructer
	TutorialMap_03();
	~TutorialMap_03();

	// delete Function
	TutorialMap_03(const TutorialMap_03& _Other) = delete;
	TutorialMap_03(TutorialMap_03&& _Other) noexcept = delete;
	TutorialMap_03& operator=(const TutorialMap_03& _Other) = delete;
	TutorialMap_03& operator=(TutorialMap_03&& _Other) noexcept = delete;



protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> BackGround;
	std::shared_ptr<class GameEngineSpriteRenderer> Map_floor_01;
	std::shared_ptr<class GameEngineSpriteRenderer> LeftDoor;
	std::shared_ptr<class GameEngineSpriteRenderer> RightDoor;
	std::shared_ptr<GameEngineCollision> Collision_Door;

};

