	#pragma once
#include <SFML/System/Vector2.hpp>
#include "Direction.h"
#include"../LinkedListLib/LinkedList.h"
#include <vector>
#include "../../Include/Food/FoodService.h"
#include "Level/LevelConfig.h"

namespace Player
{
	enum class TimeComplexity
	{
		NONE,
		ONE,
		N,
	};

	enum class LinkedListOperations
	{
		NONE,
		INSERT_AT_HEAD,
		INSERT_AT_TAIL,
		INSERT_AT_MID,
		REMOVE_AT_HEAD,
		REMOVE_AT_TAIL,
		REMOVE_AT_MID,
		DELETE_HALF_LIST,
		REVERSE_LIST,
	};

	enum class SnakeState
	{
		ALIVE,
		DEAD,
	};

	enum class InputState
	{
		WAITING,
		PROCESSING
	};

	class SnakeController
	{
	private:
		LinkedListLib::LinkedList* linkedList;

		int playerScore = 0;

		TimeComplexity timeComplexity;
		LinkedListOperations lastLinkedListOperations;

		const int initialSnakeLength = 10;
		SnakeState currenSnakeState;
		const float restartDuration = 2.f;
		float restartCounter;

		InputState inputState;

		const sf::Vector2i defaultPosition = sf::Vector2i(25, 13);

		const Direction defaultDirection = Direction::RIGHT;

		Direction currentSnakeDirection;

		void ProcessPlayerInput();
		void UpdateSnakeDirection();
		void MoveSnake();
		
		void HandleRestart();
		
		void RespawnSnake();
		void Reset();

		const float movementFrameDuration = 0.1f;
		float elapsedDuration;

		void ProcessSnakeCollision();

		void ProcessBodyCollision();
		void ProcessElementsCollision();
		void ProcessFoodCollision();
		void OnFoodCollelcted(Food::FoodType foodType);

	public:
		SnakeController();
		~SnakeController();

		void Initialize();
		void Update();
		void Render();
		void DelayedUpdate();
		void SpawnSnake();

		void InitializeLinkedList();

		void SetSnakeState(SnakeState state);
		SnakeState GetSnakeState();

		std::vector<sf::Vector2i> GetCurrentSnakePositionList();

		int GetPlayerScore();

		TimeComplexity GetTimeComplexity();
		LinkedListOperations GetLastOperation();

		void CreateLinkedList(Level::LinkedListType levelType);

		bool IsSnakeDead();


	};

}