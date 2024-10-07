#pragma once
#include <vector>
#include "LevelData.h"

namespace Level
{
	class LevelModel
	{
	private:
		std::vector<LevelData> levelConfiguration;

		float CellWidth;
		float CellHeight;

	public:
		LevelModel();
		~LevelModel();

		void Initialize(int width, int height);

		static const int numberOfRows = 28;
		static const int numberOfColumns = 50;

		float GetCellWidth();
		float GetCellHeight();
	};
}
