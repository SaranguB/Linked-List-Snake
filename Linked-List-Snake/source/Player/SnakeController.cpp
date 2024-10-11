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
		Reset();
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

			if (currenSnakeState == SnakeState::ALIVE)
				MoveSnake();

			inputState = InputState::WAITING;
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
		if (inputState == InputState::PROCESSING)return;

		EventService* eventService = ServiceLocator::getInstance()->getEventService();

		if (eventService->pressedUpArrowKey() && currentSnakeDirection != Direction::DOWN)
		{
			currentSnakeDirection = Direction::UP;
			inputState = InputState::PROCESSING;
		}
		else if (eventService->pressedDownArrowKey() && currentSnakeDirection != Direction::UP)
		{
			currentSnakeDirection = Direction::DOWN;
			inputState = InputState::PROCESSING;

		}
		else if (eventService->pressedLeftArrowKey() && currentSnakeDirection != Direction::RIGHT)
		{
			currentSnakeDirection = Direction::LEFT;
			inputState = InputState::PROCESSING;

		}
		else if (eventService->pressedRightArrowKey() && currentSnakeDirection != Direction::LEFT)
		{
			currentSnakeDirection = Direction::RIGHT;
			inputState = InputState::PROCESSING;


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
		if (singleLinkedList->ProcessNodeCollission())
		{
			currenSnakeState = SnakeState::DEAD;
		}
	}

	void SnakeController::HandleRestart()
	{
		restartCounter += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (restartCounter >= restartDuration)
		{
			RespawnSnake();
		}
	}

	void SnakeController::Reset()
	{
		currenSnakeState = SnakeState::ALIVE;
		currentSnakeDirection = defaultDirection;
		elapsedDuration = 0;
		restartCounter = 0;
		inputState = InputState::WAITING;
	}
	void SnakeController::RespawnSnake()
	{
		singleLinkedList->RemoveAllNodes();
		Reset();
		SpawnSnake();
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