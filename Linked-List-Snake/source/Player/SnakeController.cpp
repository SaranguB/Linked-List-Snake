#include "../../Include/Player/SnakeController.h"
#include "../../Include/Global/ServiceLocator.h"
#include "../../Include/Event/EventService.h"
#include "../../Include/Sound/SoundService.h"
#include "../../Include/Element/ElementService.h"
#include "Level/LevelConfig.h"
#include "LinkedListLib/DoubleLinked/DoubleLinkedList.h"
#include "LinkedListLib/SingleLinked/SingleLinkedList.h"

namespace Player
{
	using namespace LinkedListLib;
	using namespace Global;
	using namespace Event;
	using namespace Sound;
	using namespace Element;
	using namespace Food;
	using namespace Level;
	using namespace SingleLinked;
	using namespace DoubleLinked;

	SnakeController::SnakeController()
	{
		linkedList = nullptr;
		currentSnakeDirection = defaultDirection;

	}

	void SnakeController::CreateLinkedList(LinkedListType levelType)
	{
		switch (levelType)
		{

		case LinkedListType::SINGLE_LINKED_LIST:

			linkedList = new SingleLinkedList();
			break;

		case LinkedListType::DOUBLE_LINKED_LIST:
			linkedList = new DoubleLinkedList();
			break;
		}

		InitializeLinkedList();
	}

	bool SnakeController::IsSnakeDead()
	{
		return currenSnakeState == SnakeState::DEAD;
	}

	Player::SnakeController::~SnakeController()
	{
		delete linkedList;
	}

	void SnakeController::Initialize()
	{
		
	}

	void SnakeController::InitializeLinkedList()
	{
		float width = ServiceLocator::getInstance()->GetlevelService()->GetCellHeight();
		float height = ServiceLocator::getInstance()->GetlevelService()->GetCellWidth();

		Reset();
		linkedList->Initialize(width, height, defaultPosition, defaultDirection);
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
		linkedList->render();
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
			linkedList->InsertNodeAtTail();
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
		linkedList->UpdateNodeDirection(currentSnakeDirection);
	}

	void SnakeController::MoveSnake()
	{
		linkedList->UpdateNodePosition();
	}

	void SnakeController::ProcessSnakeCollision()
	{
		ProcessBodyCollision();
		ProcessElementsCollision();
		ProcessFoodCollision();
	}

	void SnakeController::ProcessBodyCollision()
	{
		if (linkedList->ProcessNodeCollision())
		{
			currenSnakeState = SnakeState::DEAD;
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
		}
	}

	void SnakeController::ProcessElementsCollision()
	{
		ElementService* elementService = ServiceLocator::getInstance()->GetElementService();

		if (elementService->ProcessElementCollision(linkedList->GetHeadNode()))
		{
			currenSnakeState = SnakeState::DEAD;
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);

		}
	}

	void SnakeController::ProcessFoodCollision()
	{
		FoodService* foodService = ServiceLocator::getInstance()->GetFoodService();

		FoodType foodType;

		if (foodService->ProcessFoodCollision(linkedList->GetHeadNode(), foodType))
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::PICKUP);

			playerScore++;
			foodService->DestroyFood();
			OnFoodCollelcted(foodType);
		}
	}

	void SnakeController::OnFoodCollelcted(FoodType foodType)
	{
		switch (foodType)
		{
		case FoodType::PIZZA:
			linkedList->InsertNodeAtTail();
			lastLinkedListOperations = LinkedListOperations::INSERT_AT_TAIL;
			timeComplexity = TimeComplexity::N;
			break;

		case FoodType::BURGER:
			linkedList->InsertNodeAtHead();
			lastLinkedListOperations = LinkedListOperations::INSERT_AT_HEAD;
			timeComplexity = TimeComplexity::ONE;
			break;

		case FoodType::CHEESE:
			linkedList->InsertNodeAtMiddle();
			lastLinkedListOperations = LinkedListOperations::INSERT_AT_MID;
			timeComplexity = TimeComplexity::N;
			break;

		case FoodType::APPLE:
			linkedList->RemoveNodeAtHead();
			lastLinkedListOperations = LinkedListOperations::REMOVE_AT_HEAD;
			timeComplexity = TimeComplexity::ONE;
			break;

		case FoodType::MANGO:
			//Delete at Middle
			linkedList->RemoveNodeAtMiddle();
			lastLinkedListOperations = LinkedListOperations::REMOVE_AT_MID;
			timeComplexity = TimeComplexity::N;
			break;

		case FoodType::ORANGE:
			//Delete at Tail
			linkedList->RemoveNodeAtTail();
			lastLinkedListOperations = LinkedListOperations::REMOVE_AT_TAIL;
			timeComplexity = TimeComplexity::N;
			break;

		case FoodType::POISION:
			//Delete half the snake
			linkedList->RemoveHalfNodes();
			lastLinkedListOperations = LinkedListOperations::DELETE_HALF_LIST;
			timeComplexity = TimeComplexity::N;
			break;

		case FoodType::ALCOHOL:
			//Reverse the snake
			currentSnakeDirection = linkedList->Reverse();
			lastLinkedListOperations = LinkedListOperations::REVERSE_LIST;
			timeComplexity = TimeComplexity::N;
			break;
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
		timeComplexity = TimeComplexity::NONE;
		lastLinkedListOperations = LinkedListOperations::NONE;
		currenSnakeState = SnakeState::ALIVE;
		currentSnakeDirection = defaultDirection;
		elapsedDuration = 0;
		restartCounter = 0;
		playerScore = 0;
		inputState = InputState::WAITING;
	}
	void SnakeController::RespawnSnake()
	{
		linkedList->RemoveAllNodes();
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

	std::vector<sf::Vector2i> SnakeController::GetCurrentSnakePositionList()
	{
		return linkedList->GetNodesPositionList();;
	}

	int SnakeController::GetPlayerScore()
	{
		return playerScore;
	}

	TimeComplexity SnakeController::GetTimeComplexity()
	{
		return timeComplexity;
	}

	LinkedListOperations SnakeController::GetLastOperation()
	{
		return lastLinkedListOperations;
	}

}