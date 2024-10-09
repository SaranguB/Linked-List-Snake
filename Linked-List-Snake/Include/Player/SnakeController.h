#pragma once
#include <SFML/System/Vector2.hpp>
#include "Direction.h"
#include"../LinkedList/SingleLinkedList.h"


namespace Player
{
	enum class SnakeState
	{
		ALIVE,
		DEAD,
	};

	class SnakeController
	{
	private:
		LinkedList::SingleLinkedList* singleLinkedList;
		void CreateLinkedList();

		const int initialSnakeLength = 10;
		SnakeState currenSnakeState;


		const sf::Vector2i defaultPosition = sf::Vector2i(25, 13);

		const Direction defaultDirection = Direction::RIGHT;

		Direction currentSnakeDirection;

		void ProcessPlayerInput();
		void UpdateSnakeDirection();
		void MoveSnake();
		void ProcessSnakeCollision();
		void HandleRestart();
		void Reset();
		void RespawnSnake();

		const float movementFrameDuration = 0.1f;
		float elapsedDuration;

	public:
		SnakeController();
		~SnakeController();

		void Initialize();
		void Update();
		void Render();
		void DelayedUpdate();
		void SpawnSnake();

		void SetSnakeState(SnakeState state);
		SnakeState GetSnakeState();
	};

}