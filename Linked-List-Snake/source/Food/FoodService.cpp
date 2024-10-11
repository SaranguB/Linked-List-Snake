#include "../../Include/Food/FoodService.h"
#include "../../Include/Food/FoodItem.h"
#include "../../Include/Global/ServiceLocator.h"

namespace Food
{
	using namespace Global;

	FoodService::FoodService()
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

	FoodItem* FoodService::CreateFood(sf::Vector2i position, FoodType type)
	{

		FoodItem* food = new FoodItem();
		food->Initialize(position, cellWidth, cellHeight, type);

		return food;
	}

	void FoodService::SpawnFood()
	{
		currentFoodItem = CreateFood(sf::Vector2i(4, 6), FoodType::BURGER);
	}
}
