#pragma once
#include <GameEngineCore/GameEngineActor.h>
	class Object_jar : public GameEngineActor
	{
	public:
		// constrcuter destructer
		Object_jar();
		~Object_jar();

		// delete Function
		Object_jar(const Object_jar& _Other) = delete;
		Object_jar(Object_jar&& _Other) noexcept = delete;
		Object_jar& operator=(const Object_jar& _Other) = delete;
		Object_jar& operator=(Object_jar&& _Other) noexcept = delete;



	protected:
		void Start() override;
		void Update(float _Delta) override;

	private:
		std::shared_ptr<class GameEngineSpriteRenderer> Jar;
	/*	std::shared_ptr<class GameEngineSpriteRenderer> Title_BG_Front;
		std::shared_ptr<class GameEngineSpriteRenderer> Title_Select_01;
		std::shared_ptr<class GameEngineSpriteRenderer> Title_Select_02;
		std::shared_ptr<class GameEngineSpriteRenderer> Title_Select_Effect_Left;
		std::shared_ptr<class GameEngineSpriteRenderer> Title_Select_Effect_Right;
		std::shared_ptr<class GameEngineSpriteRenderer> Title_Logo;*/


	};

