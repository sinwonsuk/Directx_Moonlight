#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include "Inventory.h"
// Ό³Έν :
class ShopLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	ShopLevel();
	~ShopLevel();

	// delete Function
	ShopLevel(const ShopLevel& _Other) = delete;
	ShopLevel(ShopLevel&& _Other) noexcept = delete;
	ShopLevel& operator=(const ShopLevel& _Other) = delete;
	ShopLevel& operator=(ShopLevel&& _Other) noexcept = delete;


protected:
	void Start() override;

	void Update(float _Delta) override;

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;
	bool check = false;
private:
	std::shared_ptr<class PlayMap> Map;
	std::shared_ptr<class Shop_House> House;
	std::shared_ptr<class Inventory> ad;
	Inventory* AD;
}; 

