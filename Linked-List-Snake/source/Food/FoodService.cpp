#include "../../Include/Food/FoodService.h"
#include "../../Include/Food/FoodItem.h"
#include "../../Include/Global/ServiceLocator.h"
#include "../../Include/Level/LevelModel.h"

namespace Food
{
	using namespace Global;
	using namespace Level;
	using namespace LinkedListLib;

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
		elapsedDuration = spawnDuration;
	}

	void FoodService::Update()
	{

		if (currentSpawningStatus == FoodSpawningStatus::ACTIVE)
		{
			
			UpdateElapsedDuration();
			HandleFoodSpawning();
		}

		if (currentFoodItem)currentFoodItem->Update();
	}

	void FoodService::Render()
	{
		if (currentFoodItem)currentFoodItem->Render();
	}

	void FoodService::Reset()
	{
		elapsedDuration = 0;
	}

	
	void FoodService::HandleFoodSpawning()
	{
		if (ServiceLocator::getInstance()->GetPlayerService()->IsPlayerDead())return;
		if (elapsedDuration >= spawnDuration)
		{
			DestroyFood();
			Reset();
			SpawnFood();
		}
	}

	void FoodService::DestroyFood()
	{
		if (currentFoodItem)delete currentFoodItem;
		currentFoodItem = nullptr;
	}
	
	void FoodService::SpawnFood()
	{
		currentFoodItem = CreateFood(GetValidSpawnPosition(), GetRandomFoodType());
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

	FoodType FoodService::GetRandomFoodType()
	{

		std::uniform_int_distribution<int> distribution(0, FoodItem::numberOfFoods - 1);
		return static_cast<FoodType>(distribution(randomEngine));
	}

	void FoodService::StartFoodSpawning()
	{
		
		currentSpawningStatus = FoodSpawningStatus::ACTIVE;

		cellWidth = ServiceLocator::getInstance()->GetlevelService()->GetCellWidth();
		cellHeight = ServiceLocator::getInstance()->GetlevelService()->GetCellHeight();
	}

	void FoodService::StopFoodSpawning()
	{
		currentSpawningStatus = FoodSpawningStatus::IN_ACTIVE;

		DestroyFood();
		Reset();
	}

	bool FoodService::ProcessFoodCollision(Node* headNode, FoodType& outFoodType)
	{
		if (currentFoodItem && currentFoodItem->GetFoodPosition() == headNode->bodyPart.GetPosition())
		{
			outFoodType = currentFoodItem->GetFoodType();
			return true;
		}
		return false;
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

	void FoodService::UpdateElapsedDuration()
	{
		elapsedDuration += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}
	
}
