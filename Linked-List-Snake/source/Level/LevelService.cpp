#include "../../Include/Level/LevelService.h"
#include "../../Include/Level/LevelController.h"

namespace Level
{
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
	}
}
