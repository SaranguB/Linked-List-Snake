#pragma once
#include <SFML/System/Vector2.hpp>
#include <random>
#include <vector>
#include "FoodType.h"

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

		void SpawnFood();


	public:
		FoodService();
		~FoodService();

		void Initialize();
		void Update();
		void Render();

		void DestroyFood();
		void StateFoodSpawning();
	};
}
