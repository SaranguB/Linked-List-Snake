#pragma once

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
		const int initialSnakeLength = 10;
		SnakeState currenSnakeState;

		void ProcessPlayerInput();
		void UpdateSnakeDirection();
		void MoveSnake();
		void ProcessSnakeCollision();
		void HandleRestart();
		void Reset();
		void RespawnSnake();

	public:
		SnakeController();
		~SnakeController();

		void Initialize();
		void Update();
		void Render();

		void SpawnSnake();

		void SetSnakeState(SnakeState state);
		SnakeState GetSnakeState();
	};

}