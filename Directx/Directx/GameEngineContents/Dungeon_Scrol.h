#pragma once
class Dungeon_Scrol : public GameEngineActor
{
public:

public:
	// constrcuter destructer
	Dungeon_Scrol();
	~Dungeon_Scrol();

	// delete Function
	Dungeon_Scrol(const Dungeon_Scrol& _Other) = delete;
	Dungeon_Scrol(Dungeon_Scrol&& _Other) noexcept = delete;
	Dungeon_Scrol& operator=(const Dungeon_Scrol& _Other) = delete;
	Dungeon_Scrol& operator=(Dungeon_Scrol&& _Other) noexcept = delete;




protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	bool check = false;
	std::shared_ptr<class GameEngineUIRenderer> Scrol;

	std::shared_ptr<class GameEngineUIRenderer> Inventroy_Select;
	bool Inventory_Start = false;
	float Speed = 600.0f;

	float Time = 0.0f;
};
