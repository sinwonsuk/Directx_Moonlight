#pragma once

class Black_Smith : public GameEngineActor
{
public:
	// constrcuter destructer
	Black_Smith();
	~Black_Smith();

	// delete Function
	Black_Smith(const Black_Smith& _Other) = delete;
	Black_Smith(Black_Smith&& _Other) noexcept = delete;
	Black_Smith& operator=(const Black_Smith& _Other) = delete;
	Black_Smith& operator=(Black_Smith&& _Other) noexcept = delete;

	void Black_Smith_Open_Close(); 
	void Black_Smith_Move();
	void Item_InforMation_01(); 
	void Item_Buy_01();

	void Item_InforMation_02();

	void Item_Buy_02();

	void Item_InforMation_03();

	void Item_Buy_03();

	void Black_Smith_effect(int _Sprite);


protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	bool Black_Smith_Start = false;
	float Number = 1.0f;
	bool check = false;
	GameEngineSoundPlayer Open;
	GameEngineSoundPlayer Craft;
	GameEngineSoundPlayer Select_Sound;

	std::shared_ptr<GameEngineCollision> Col;

	std::shared_ptr<class GameEngineUIRenderer> black;
	std::shared_ptr<class GameEngineUIRenderer> blacksmith_figure;
	std::shared_ptr<class GameEngineUIRenderer> blacksmith_workbench;
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

	std::shared_ptr<class GameEngineUIRenderer> Item_Weapon_01;
	std::shared_ptr<class GameEngineUIRenderer> Item_Weapon_02;
	std::shared_ptr<class GameEngineUIRenderer> Item_Weapon_03;

	std::shared_ptr<class GameEngineUIRenderer> blacksmith_OX_Enough_01;
	std::shared_ptr<class GameEngineUIRenderer> blacksmith_OX_Enough_02;
	std::shared_ptr<class GameEngineUIRenderer> blacksmith_OX_Enough_03;

	std::shared_ptr<class GameEngineSpriteRenderer> Npc;
	

	int Itme_Money = 0;

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
