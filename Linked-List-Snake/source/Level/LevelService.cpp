#include "../../Include/Level/LevelService.h"
#include "../../Include/Level/LevelController.h"
#include "../../Include/Global/ServiceLocator.h"
#include "Element/ElementData.h"

namespace Level
{
	using namespace Global;
	using namespace Element;

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
		SpawnLevelElements(levelToLoad);
		SpawnFood();
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

	void LevelService::SpawnLevelElements(LevelNumber levelToLoad)
	{
		float cellWidth = levelController->GetCellWidth();
		float cellHeight = levelController->GetCellHeight();

		std::vector<ElementData> elementDataList = levelController->GetElementDataList((int)levelToLoad);
		ServiceLocator::getInstance()->GetElementService()->spawnElements(elementDataList, cellWidth, cellHeight);
	}

	void LevelService::SpawnFood()
	{
		ServiceLocator::getInstance()->GetFoodService()->StateFoodSpawning();
	}

	LevelNumber LevelService::GetCurrentLevel()
	{
		return currentLevel;
	}

	void LevelService::SetCurrentLevelNumber(LevelNumber levelToLoad)
	{
		currentLevel = levelToLoad;
	}

	void LevelService::SpawnPlayer()
	{
		ServiceLocator::getInstance()->GetPlayerService()->SpawnPlayer();
	}
}
