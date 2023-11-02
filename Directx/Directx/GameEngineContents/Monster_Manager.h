#pragma once

class Monster_Manager
{
public:
	// constrcuter destructer
	Monster_Manager();
	~Monster_Manager();

	Monster_Manager(const Monster_Manager& _Other) = delete;
	Monster_Manager(Monster_Manager&& _Other) noexcept = delete;
	Monster_Manager& operator=(const Monster_Manager& _Other) = delete;
	Monster_Manager& operator=(Monster_Manager&& _Other) noexcept = delete;


	void MonsterCollision(float _Delta, std::string_view _Name);
	void Monster_Move(float _Delta, std::string_view _Name);
	static int Map_Check;
protected:
	std::shared_ptr<class GameEngineCollision> Monster;

private:
	bool Door_Collison_Check = false;


};