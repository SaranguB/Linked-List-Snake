#pragma once
#include <SFML/System/Vector2.hpp>
#include <random>
#include <vector>
#include "FoodType.h"
#include <random>
#include "../../Include/LinkedListLib/SingleLinked/SingleNode.h"

namespace Food
{
	class FoodItem;

	enum FoodSpawningStatus
	{
		ACTIVE,
		IN_ACTIVE,
	};

	class FoodService
	{
	private:
		FoodItem* currentFoodItem;
		float cellWidth;
		float cellHeight;
		
		const float spawnDuration = 4.f;
		float elapsedDuration;

		FoodItem* CreateFood(sf::Vector2i position, FoodType type);

		std::default_random_engine randomEngine;
		std::random_device randomDevice;

		void SpawnFood();
		bool IsValidPosition(std::vector<sf::Vector2i> positionData, sf::Vector2i foodPosition);
		sf::Vector2i GetValidSpawnPosition();
		void UpdateElapsedDuration();

		void HandleFoodSpawning();

		FoodSpawningStatus currentSpawningStatus;

	public:
		FoodService();
		~FoodService();

		void Initialize();
		void Update();
		void Render();
		void Reset();

		void DestroyFood();
		void StateFoodSpawning();


		sf::Vector2i GetRandomPosition();

		FoodType GetRandomFoodType();

		void StartFoodSpawning();
		void StopFoodSpawning();
		
		bool ProcessFoodCollision(LinkedListLib::Node* headNode, FoodType& outFoodType);
	};
}
