#pragma once

class Potion_NPC : public GameEngineActor
{
public:
	// constrcuter destructer
	Potion_NPC();
	~Potion_NPC();

	// delete Function
	Potion_NPC(const Potion_NPC& _Other) = delete;
	Potion_NPC(Potion_NPC&& _Other) noexcept = delete;
	Potion_NPC& operator=(const Potion_NPC& _Other) = delete;
	Potion_NPC& operator=(Potion_NPC&& _Other) noexcept = delete;

	void Potion_Open_Close();
	void Potion_Move();
	void Item_InforMation_01();
	void Item_Buy_01();

	void Item_InforMation_02();

	void Item_Buy_02();

	void Item_InforMation_03();

	void Item_Buy_03();

	void Potion_Npc_effect(int _Sprite);


protected:
	void Start() override;
	void Update(float _Delta) override;

private:

	GameEngineSoundPlayer Open;
	GameEngineSoundPlayer Craft;
	GameEngineSoundPlayer Select_Sound;

	bool Black_Smith_Start = false;
	float Number = 1.0f;
	bool check = false;

	std::shared_ptr<GameEngineCollision> Col;

	std::shared_ptr<class GameEngineUIRenderer> black;
	std::shared_ptr<class GameEngineUIRenderer> Witch_figure;
	std::shared_ptr<class GameEngineUIRenderer> Witch_Jar;
	std::shared_ptr<class GameEngineUIRenderer> Item_Sort;
	std::shared_ptr<class GameEngineUIRenderer> Store_name;
	std::shared_ptr<class GameEngineUIRenderer> Item_Information;
	std::shared_ptr<class GameEngineUIRenderer> Item_Window_01;

	std::shared_ptr<class GameEngineUIRenderer> Item_Window_02;
	std::shared_ptr<class GameEngineUIRenderer> Item_Window_03;
	std::shared_ptr<class GameEngineUIRenderer> Item_Window_04;
	std::shared_ptr<class GameEngineUIRenderer> Item_Select;

	std::shared_ptr<class GameEngineUIRenderer> BrokenSword;
	std::shared_ptr<class GameEngineUIRenderer> AncientPot;
	std::shared_ptr<class GameEngineUIRenderer> EmpoweredCrystal;
	std::shared_ptr<class GameEngineUIRenderer> FireJelly;
	std::shared_ptr<class GameEngineUIRenderer> crystals4elect;
	std::shared_ptr<class GameEngineUIRenderer> Item_Sword;
	std::shared_ptr<class GameEngineUIRenderer> Item_Gloves;
	std::shared_ptr<class GameEngineUIRenderer> Money;

	std::shared_ptr<class GameEngineUIRenderer> Enought_Item_Number_01;
	std::shared_ptr<class GameEngineUIRenderer> Enought_Item_Number_02;
	std::shared_ptr<class GameEngineUIRenderer> Enought_Item_Number_03;


	std::shared_ptr<class GameEngineUIRenderer> Item_Number_01;
	std::shared_ptr<class GameEngineUIRenderer> Item_Number_02;
	std::shared_ptr<class GameEngineUIRenderer> Item_Number_03;

	std::shared_ptr<class GameEngineUIRenderer> Item_Potion_01;
	std::shared_ptr<class GameEngineUIRenderer> Item_Potion_02;
	std::shared_ptr<class GameEngineUIRenderer> Item_Potion_03;

	std::shared_ptr<class GameEngineUIRenderer> blacksmith_OX_Enough_01;
	std::shared_ptr<class GameEngineUIRenderer> blacksmith_OX_Enough_02;
	std::shared_ptr<class GameEngineUIRenderer> blacksmith_OX_Enough_03;

	std::shared_ptr<class GameEngineSpriteRenderer> Npc;

	int Potion_Number_01 = 1;
	int Potion_Number_02 = 1;
	int Potion_Number_03 = 1;
	int Itme_Money = 0;
	bool PotionCheck = false;
	int BrokenSword_Item_Number = 0;
	int EmpoweredCrystal_Item_Number = 0;
	int crystals4elect_Item_Number = 0;
	int AncientPot_Item_Number = 0;
	int FireJelly_Item_Number = 0;





	int Check = 0;

	int Enough_Item_01 = 0;
	int Enough_Item_02 = 0;
	int Enough_Item_03 = 0;

	int Item_Number_Check_01 = 0;
	int Item_Number_Check_02 = 0;
	int Item_Number_Check_03 = 0;

	size_t Move_X = 0;
	size_t Move_Y = 0;

};
