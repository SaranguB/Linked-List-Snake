#pragma once
#include "LevelConfig.h"
namespace Level
{
	class LevelController;
	class LevelService
	{
	private:
		LevelController* levelController;
		LevelNumber currentLevel;


		void SpawnPlayer();

	public:
		LevelService();
		~LevelService();

		void Initialize();
		void Update();
		void Render();

		void CreateLevel(LevelNumber levelToLoad);

		float GetCellWidth();
		float GetCellHeight();

		void SpawnLevelElements(LevelNumber levelToLoad);

		void SpawnFood();

		LevelNumber GetCurrentLevel();
		void SetCurrentLevelNumber(LevelNumber levelToLoad);
	};
}
