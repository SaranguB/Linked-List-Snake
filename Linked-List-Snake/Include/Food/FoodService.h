#pragma once
#include <SFML/System/Vector2.hpp>
#include <random>
#include <vector>
#include "FoodType.h"
#include <random>

namespace Food
{
	class FoodItem;
	class FoodService
	{
	private:
		FoodItem* currentFoodItem;
		float cellWidth;
		float cellHeight;
			

		FoodItem* CreateFood(sf::Vector2i position, FoodType type);

		std::default_random_engine randomEngine;
		std::random_device randomDevice;

		void SpawnFood();
		bool IsValidPosition(std::vector<sf::Vector2i> positionData, sf::Vector2i foodPosition);
		sf::Vector2i GetValidSpawnPosition();

	public:
		FoodService();
		~FoodService();

		void Initialize();
		void Update();
		void Render();

		void DestroyFood();
		void StateFoodSpawning();


		sf::Vector2i GetRandomPosition();

		FoodType GetRandomFoodType();
		 
	};
}
