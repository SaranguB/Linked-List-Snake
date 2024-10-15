#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>

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

		void SpawnPlayer();

		std::vector<sf::Vector2i> GetCurrentSnakePositionList();

		int GetPlayerScore();

	};

}