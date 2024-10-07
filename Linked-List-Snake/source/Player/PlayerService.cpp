#include "../../Include/Player/PlayerService.h"
#include "../../Include/Player/SnakeController.h"

namespace Player
{

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

	void PlayerService::SpawnPlayer()
	{

	}
}


