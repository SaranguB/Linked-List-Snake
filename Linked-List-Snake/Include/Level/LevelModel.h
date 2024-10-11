#pragma once
#include <vector>
#include "LevelData.h"

namespace Level
{
	class LevelModel
	{
	private:
		std::vector<LevelData> levelConfiguration;

		std::vector<Element::ElementData> levelOneElementList;
		std::vector<Element::ElementData> levelTwoElementList;
		std::vector<LevelData> levelConfiguration;

		float CellWidth;
		float CellHeight;

		void InitializeLevelData();
	public:
		LevelModel();
		~LevelModel();

		void Initialize(int width, int height);

		static const int numberOfRows = 28;
		static const int numberOfColumns = 53;

		float GetCellWidth();
		float GetCellHeight();

		const std::vector<Element::ElementData>& GetElementDataList(int levelToLoad);
	};
}
