#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Tutorial_Map_Manager.h"
class TutorialMap_05 : public GameEngineActor, public Tutorial_Map_Manager
{
public:
	// constrcuter destructer
	TutorialMap_05();
	~TutorialMap_05();

	// delete Function
	TutorialMap_05(const TutorialMap_05& _Other) = delete;
	TutorialMap_05(TutorialMap_05&& _Other) noexcept = delete;
	TutorialMap_05& operator=(const TutorialMap_05& _Other) = delete;
	TutorialMap_05& operator=(TutorialMap_05&& _Other) noexcept = delete;



protected:
	void Start() override;
	void Update(float _Delta) override;

private:

	std::shared_ptr<class GameEngineSpriteRenderer> BackGround;
	std::shared_ptr<class GameEngineSpriteRenderer> Map_floor_01;
	std::shared_ptr<class GameEngineSpriteRenderer> LeftDoor;
	std::shared_ptr<class GameEngineSpriteRenderer> RightDoor;

	std::shared_ptr<class GameEngineSpriteRenderer> OpenDoor;
	std::shared_ptr<class GameEngineSpriteRenderer> CloseDoor;


	std::shared_ptr<class GameEngineSpriteRenderer> Scroll_Attack;
	std::shared_ptr<class GameEngineSpriteRenderer> Scroll_Portion;
	std::shared_ptr<GameEngineCollision> Collision_Door;
	std::vector<std::shared_ptr<class BabySlime>> Slimes;


	int Slime_Check = 0; 

	GameEngineSoundPlayer Close_Sound; 
	GameEngineSoundPlayer Open_Sound;
	bool Close_Sound_Check = false;
	bool Open_Sound_Check = false;
	//std::vector<std::shared_ptr<class BabySlime>> Slime;

};