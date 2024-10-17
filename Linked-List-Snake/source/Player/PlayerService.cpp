#include "../../Include/Player/PlayerService.h"
#include "../../Include/Player/SnakeController.h"

namespace Player
{
	using namespace Level;

	PlayerService::PlayerService()
	{
		snakeController = nullptr;

		CreateController();
	}

	void PlayerService::CreateController()
	{
		snakeController = new SnakeController();
	}

	PlayerService::~PlayerService()
	{
		delete(snakeController);
	}

	void PlayerService::Initialize()
	{
		snakeController->Initialize();
	}

	void PlayerService::Update()
	{
		snakeController->Update();
	}

	void PlayerService::Render()
	{
		snakeController->Render();
	}

	void PlayerService::SpawnPlayer(LinkedListType levelType)
	{
		snakeController->CreateLinkedList(levelType);
		snakeController->SpawnSnake();
	}
	std::vector<sf::Vector2i> PlayerService::GetCurrentSnakePositionList()
	{
		return snakeController->GetCurrentSnakePositionList();
	}
	int PlayerService::GetPlayerScore()
	{
		return snakeController->GetPlayerScore();
	}
	TimeComplexity PlayerService::GetTimeComplexity()
	{
		return snakeController->GetTimeComplexity();
	}
	LinkedListOperations PlayerService::GetLastOperation()
	{
		return snakeController->GetLastOperation();;
	}
}


