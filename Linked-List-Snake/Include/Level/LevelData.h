#pragma once
#include "LevelService.h"

namespace Level
{
	struct LevelData
	{
		LevelData(LevelNumber ind)
		{
			levelIndex = ind;
		}

		LevelNumber levelIndex;
	};
}


