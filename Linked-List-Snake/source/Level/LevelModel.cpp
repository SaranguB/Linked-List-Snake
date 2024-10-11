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
		CellWidth = width / numberOfColumns;
		CellHeight = height / numberOfRows;

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
