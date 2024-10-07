#include "../../Include/Player/SnakeController.h"

namespace Player
{
	SnakeController::SnakeController()
	{

	}
	Player::SnakeController::~SnakeController()
	{
	}
	void SnakeController::Initialize()
	{
	}

	void SnakeController::Update()
	{

		switch (currenSnakeState)
		{
		case SnakeState::ALIVE:
			ProcessPlayerInput();
			UpdateSnakeDirection();
			ProcessSnakeCollision();
			MoveSnake();

			break;

		case SnakeState::DEAD:
			HandleRestart();
			break;

		}

	}

	void SnakeController::ProcessPlayerInput()
	{
	}
	void SnakeController::UpdateSnakeDirection()
	{
	}
	void SnakeController::MoveSnake()
	{
	}
	void SnakeController::ProcessSnakeCollision()
	{
	}
	void SnakeController::HandleRestart()
	{
	}
	void SnakeController::Reset()
	{
	}
	void SnakeController::RespawnSnake()
	{
	}

	void SnakeController::Render()
	{
	}

	void SnakeController::SpawnSnake()
	{

	}

	void SnakeController::SetSnakeState(SnakeState state)
	{
		currenSnakeState = state;
	}
	SnakeState SnakeController::GetSnakeState()
	{
		return currenSnakeState;
	}
	
}