#include "../../Include/Level/LevelService.h"
#include "../../Include/Level/LevelController.h"
#include "../../Include/Global/ServiceLocator.h"

namespace Level
{
	using namespace Global;

	LevelService::LevelService()
	{
		levelController = new LevelController();
	}
	LevelService::~LevelService()
	{
		delete(levelController);
	}

	void LevelService::Initialize()
	{
		levelController->Initialize();
	}

	void LevelService::Update()
	{
		levelController->Update();
	}

	void LevelService::Render()
	{
		levelController->Render();
	}
	void LevelService::CreateLevel(LevelNumber levelToLoad)
	{
		currentLevel = levelToLoad;
		SpawnPlayer();
	}

	float LevelService::GetCellWidth()
	{
		return levelController->GetCellWidth();
	}

	float LevelService::GetCellHeight()
	{
		return levelController->GetCellHeight();
	}

	void LevelService::SpawnPlayer()
	{
		ServiceLocator::getInstance()->GetPlayerService()->SpawnPlayer();
	}
}
