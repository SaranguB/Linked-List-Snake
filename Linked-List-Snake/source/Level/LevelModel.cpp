#include "../../Include/Level/LevelModel.h"

namespace Level
{
	using namespace Element;

	LevelModel::LevelModel()
	{
	}

	LevelModel::~LevelModel()
	{
	}

	void LevelModel::Initialize(int width, int height)
	{
		CellWidth = static_cast<float>(width) / static_cast<float>(numberOfColumns);
		CellHeight = static_cast<float>(height) / static_cast<float>(numberOfRows);

		InitializeLevelData();
	}

	void LevelModel::InitializeLevelData()
	{
		levelConfiguration.push_back(LevelData(LevelNumber::ONE, &levelOneElementList));
		levelConfiguration.push_back(LevelData(LevelNumber::TWO, &levelTwoElementList));
	}

	float LevelModel::GetCellWidth()
	{
		return CellWidth;
	}

	float LevelModel::GetCellHeight()
	{
		return CellHeight;
	}

	const std::vector<Element::ElementData>& LevelModel::GetElementDataList(int levelToLoad)
	{
		return *levelConfiguration[levelToLoad].elementDataList;
	}



}
