#pragma once
#include <vector>
#include "LevelData.h"
#include "Element/ElementService.h"
#include "Element/ElementData.h"
#include "Level/LevelData.h"



namespace Level
{
	class LevelModel
	{
	private:
		std::vector<LevelData> levelConfiguration;

		std::vector<Element::ElementData> levelOneElementList = {};
		std::vector<Element::ElementData> levelTwoElementList = { 
			//TOP - LEFT
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1, 1)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(2, 1)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(3, 1)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1, 2)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1, 3)),

//TOP-RIGHT
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(50, 1)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(50, 2)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(50, 3)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(49, 1)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(48, 1)),

//BOTTOM-LEFT
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1, 26)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1, 25)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(1, 24)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(2, 26)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(3, 26)),

//BOTTOM-RIGHT
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(50, 26)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(50, 25)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(50, 24)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(49, 26)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(48, 26)),

//CENTER-TOP-BAR
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(21, 11)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(22, 11)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(23, 11)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(24, 11)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(25, 11)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(26, 11)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(27, 11)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(28, 11)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(29, 11)),

//CENTER-BOTTOM-BAR
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(21, 15)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(22, 15)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(23, 15)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(24, 15)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(25, 15)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(26, 15)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(27, 15)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(28, 15)),
Element::ElementData(Element::ElementType::OBSTACLE, sf::Vector2i(29, 15)),
		};

		

		float CellWidth;
		float CellHeight;

		void InitializeLevelData();
	public:
		LevelModel();
		~LevelModel();

		void Initialize(int width, int height);

		static const int numberOfRows = 28;
		static const int numberOfColumns = 52;

		float GetCellWidth();
		float GetCellHeight();

		const std::vector<Element::ElementData>& GetElementDataList(int levelToLoad);
	};
}
