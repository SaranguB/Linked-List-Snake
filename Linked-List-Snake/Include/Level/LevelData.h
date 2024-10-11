#pragma once
#include "LevelService.h"
#include "Element/ElementData.h"

namespace Level
{
	struct LevelData
	{
		LevelData(LevelNumber ind, std::vector<Element::ElementData>* DataList)
		{
			levelIndex = ind;
			elementDataList = DataList;
		}

		LevelNumber levelIndex;
		std::vector<Element::ElementData>* elementDataList;

	};
}


