#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Tutorial_Map_Manager.h"
class TutorialMap_04 : public GameEngineActor, public Tutorial_Map_Manager
{
public:
	// constrcuter destructer
	TutorialMap_04();
	~TutorialMap_04();

	// delete Function
	TutorialMap_04(const TutorialMap_04& _Other) = delete;
	TutorialMap_04(TutorialMap_04&& _Other) noexcept = delete;
	TutorialMap_04& operator=(const TutorialMap_04& _Other) = delete;
	TutorialMap_04& operator=(TutorialMap_04&& _Other) noexcept = delete;



protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> Scroll;
	std::shared_ptr<class GameEngineSpriteRenderer> BackGround;
	std::shared_ptr<class GameEngineSpriteRenderer> Map_floor_01;
	std::shared_ptr<class GameEngineSpriteRenderer> LeftDoor;
	std::shared_ptr<class GameEngineSpriteRenderer> RightDoor;
	std::shared_ptr<GameEngineCollision> Collision_Door;

};

