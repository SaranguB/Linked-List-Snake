#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "SnakeController.h"
#include "Level/LevelConfig.h"

namespace Player
{
	class SnakeController;
	class PlayerService
	{
	private:
		SnakeController* snakeController;

		void CreateController();

	public:
		PlayerService();
		~PlayerService();

		void Initialize();
		void Update();
		void Render();

		void SpawnPlayer(Level::LinkedListType levelType);

		std::vector<sf::Vector2i> GetCurrentSnakePositionList();

		int GetPlayerScore();

		TimeComplexity GetTimeComplexity();
		LinkedListOperations GetLastOperation();

		bool IsPlayerDead();

	};

}