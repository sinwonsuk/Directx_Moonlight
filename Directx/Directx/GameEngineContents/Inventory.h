#pragma once
#include <GameEngineCore/GameEngineActor.h>

class Inventory_Move
{
	float4 Move;
};



// Ό³Έν :
class Inventory : public GameEngineActor
{
public:

public:
	// constrcuter destructer
	Inventory();
	~Inventory();

	// delete Function
	Inventory(const Inventory& _Other) = delete;
	Inventory(Inventory&& _Other) noexcept = delete;
	Inventory& operator=(const Inventory& _Other) = delete;
	Inventory& operator=(Inventory&& _Other) noexcept = delete;




protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	bool check = false;
	std::shared_ptr<class GameEngineUIRenderer> Inventroy_Screen;

	std::shared_ptr<class GameEngineUIRenderer> Inventroy_Select;
	bool Inventory_Start = false;

};
