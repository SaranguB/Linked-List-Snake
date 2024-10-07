#include "../../Include/Level/LevelModel.h"

namespace Level
{
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
	}

	float LevelModel::GetCellWidth()
	{
		return CellWidth;
	}

	float LevelModel::GetCellHeight()
	{
		return CellHeight;
	}

	

}
