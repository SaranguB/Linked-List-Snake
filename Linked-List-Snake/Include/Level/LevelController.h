#pragma once
#include "Level/LevelModel.h"

namespace Level
{
	class LevelModel;
	class LevelView;
	class LevelController
	{
	private:
		LevelModel* levelModel;
		LevelView* levelView;

	public:
		LevelController();
		~LevelController();

		void Initialize();
		void Update();
		void Render();

		float GetCellWidth();
		float GetCellHeight();

		const std::vector<Element::ElementData>& GetElementDataList(int levelToLoad);


	};
}
