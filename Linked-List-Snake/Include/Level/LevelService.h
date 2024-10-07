#pragma once
#include "LevelNumber.h"
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


	};
}
