#include "../../Include/Food/FoodService.h"
#include "../../Include/Food/FoodItem.h"
#include "../../Include/Global/ServiceLocator.h"
#include "../../Include/Level/LevelModel.h"

namespace Food
{
	using namespace Global;
	using namespace Level;
	FoodService::FoodService() : randomEngine(randomDevice())
	{
		currentFoodItem = nullptr;
	}

	FoodService::~FoodService()
	{
		DestroyFood();

	}

	void FoodService::Initialize()
	{

	}

	void FoodService::Update()
	{
		if (currentFoodItem)currentFoodItem->Update();
	}

	void FoodService::Render()
	{
		if (currentFoodItem)currentFoodItem->Render();
	}

	void FoodService::DestroyFood()
	{
		if (currentFoodItem)delete currentFoodItem;
	}

	void FoodService::StateFoodSpawning()
	{
		cellWidth = ServiceLocator::getInstance()->GetlevelService()->GetCellWidth();
		cellHeight = ServiceLocator::getInstance()->GetlevelService()->GetCellHeight();
		SpawnFood();

	}

	sf::Vector2i  FoodService::GetRandomPosition()
	{
		std::uniform_int_distribution<int> xDistribution(0, LevelModel::numberOfColumns - 1);
		std::uniform_int_distribution<int> yDistribution(0, LevelModel::numberOfRows - 1);

		int xPosition = xDistribution(randomEngine);
		int yPosition = yDistribution(randomEngine);

		return sf::Vector2i(xPosition, yPosition);
	}

	
	void FoodService::SpawnFood()
	{
		currentFoodItem = CreateFood(GetValidSpawnPosition(), GetRandomFoodType());
	}

	FoodType FoodService::GetRandomFoodType()
	{

		std::uniform_int_distribution<int> distribution(0, FoodItem::numberOfFoods - 1);
		return static_cast<FoodType>(distribution(randomEngine));
	}

	FoodItem* FoodService::CreateFood(sf::Vector2i position, FoodType type)
	{

		FoodItem* food = new FoodItem();
		food->Initialize(position, cellWidth, cellHeight, type);

		return food;
	}

	bool FoodService::IsValidPosition(std::vector<sf::Vector2i> positionData, sf::Vector2i foodPosition)
	{

		for (int i = 0;i < positionData.size();i++)
		{
			if (foodPosition == positionData[i])return false;
		}
		return true;
	}
	sf::Vector2i FoodService::GetValidSpawnPosition()
	{
		std::vector<sf::Vector2i> playerPositionData = ServiceLocator::getInstance()
			->GetPlayerService()->GetCurrentSnakePositionList();

		std::vector<sf::Vector2i> elementsPositionData = ServiceLocator::getInstance()->GetElementService()
			->GetElementPositionList();

		sf::Vector2i spawnPosition;

		do spawnPosition = GetRandomPosition();
		while (!IsValidPosition(playerPositionData, spawnPosition) || !IsValidPosition(elementsPositionData, spawnPosition));

		return spawnPosition;
	}
}
