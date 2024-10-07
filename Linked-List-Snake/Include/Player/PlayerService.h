#pragma once

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
	};

}