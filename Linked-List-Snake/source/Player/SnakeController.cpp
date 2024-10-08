#include "../../Include/Player/SnakeController.h"
#include "../../Include/Global/ServiceLocator.h"
#include "../../Include/Event/EventService.h"

namespace Player
{
	using namespace LinkedList;
	using namespace Global;
	using namespace Event;

	SnakeController::SnakeController()
	{
		singleLinkedList = nullptr;
		CreateLinkedList();
		currentSnakeDirection = defaultDirection;

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
			DelayedUpdate();

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

	void SnakeController::DelayedUpdate()
	{
		elapsedDuration += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (elapsedDuration >= movementFrameDuration)
		{
			elapsedDuration = 0;
			UpdateSnakeDirection();
			ProcessSnakeCollision();
			MoveSnake();
		}
	}

	void SnakeController::SpawnSnake()
	{
		for (int i = 0;i < initialSnakeLength;i++)
		{
			singleLinkedList->InsertNodeAtTail();
		}
	}

	void SnakeController::ProcessPlayerInput()
	{
		EventService* eventService = ServiceLocator::getInstance()->getEventService();

		if (eventService->pressedUpArrowKey() && currentSnakeDirection != Direction::DOWN)
		{
			currentSnakeDirection = Direction::UP;
		}
		else if (eventService->pressedDownArrowKey() && currentSnakeDirection != Direction::UP)
		{
			currentSnakeDirection = Direction::DOWN;
		}
		else if (eventService->pressedLeftArrowKey() && currentSnakeDirection != Direction::RIGHT)
		{
			currentSnakeDirection = Direction::LEFT;
		}
		else if (eventService->pressedRightArrowKey() && currentSnakeDirection != Direction::LEFT)
		{
			currentSnakeDirection = Direction::RIGHT;

		}

	}

	void SnakeController::UpdateSnakeDirection()
	{
		singleLinkedList->UpdateNodeDirection(currentSnakeDirection);
	}

	void SnakeController::MoveSnake()
	{
		singleLinkedList->UpdateNodePosition();
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