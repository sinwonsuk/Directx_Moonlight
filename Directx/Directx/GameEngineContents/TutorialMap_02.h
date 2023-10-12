#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Tutorial_Map_Manager.h"
class TutorialMap_02 : public GameEngineActor, public Tutorial_Map_Manager
{
public:
	// constrcuter destructer
	TutorialMap_02();
	~TutorialMap_02();

	// delete Function
	TutorialMap_02(const TutorialMap_02& _Other) = delete;
	TutorialMap_02(TutorialMap_02&& _Other) noexcept = delete;
	TutorialMap_02& operator=(const TutorialMap_02& _Other) = delete;
	TutorialMap_02& operator=(TutorialMap_02&& _Other) noexcept = delete;



protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	float Map_Number = 0.0f;
	std::shared_ptr<class GameEngineSpriteRenderer> BackGround;
	std::shared_ptr<class GameEngineSpriteRenderer> Map_floor_01;
	std::shared_ptr<class GameEngineSpriteRenderer> LeftDoor;
	std::shared_ptr<class GameEngineSpriteRenderer> RightDoor;
	std::shared_ptr<class GameEngineSpriteRenderer> Scroll;
	std::shared_ptr<GameEngineCollision> Collision_Door;

};