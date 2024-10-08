#include "../../Include/Player/SnakeController.h"
#include "../../Include/Global/ServiceLocator.h"

namespace Player
{
	using namespace LinkedList;
	using namespace Global;

	SnakeController::SnakeController()
	{
		singleLinkedList = nullptr;
		CreateLinkedList();
	}

	void SnakeController::CreateLinkedList()
	{
		singleLinkedList = new SingleLinkedList();
	}

	Player::SnakeController::~SnakeController()
	{
		delete singleLinkedList;
	}

	void SnakeController::Initialize()
	{
		float width = ServiceLocator::getInstance()->GetlevelService()->GetCellHeight();
		float height = ServiceLocator::getInstance()->GetlevelService()->GetCellWidth();

		singleLinkedList->Initialize(width, height, defaultPosition, defaultDirection);
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

	void SnakeController::Render()
	{
		singleLinkedList->Render();
	}

	void SnakeController::SpawnSnake()
	{
		singleLinkedList->CreateHeadNode();
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

	

	void SnakeController::SetSnakeState(SnakeState state)
	{
		currenSnakeState = state;
	}
	SnakeState SnakeController::GetSnakeState()
	{
		return currenSnakeState;
	}

}