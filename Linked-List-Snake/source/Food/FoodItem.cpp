#include "../../Include/Food/FoodItem.h"
#include "../../Include/Global/Config.h"
#include "../../Include/Level/LevelView.h"
namespace Food
{
	using namespace Global;
	using namespace Level;
	using namespace UI::UIElement;
	
	FoodItem::FoodItem()
	{
		foodImage = new ImageView;
	}

	FoodItem::~FoodItem()
	{
		delete foodImage;
	}

	void FoodItem::Initialize(sf::Vector2i gridPos, float width, float height, FoodType type)
	{
		gridPosition = gridPos;
		cellWidth = width;
		cellHeight = height;
		foodType = type;

		IntializeFoodItem();
	}

	void FoodItem::IntializeFoodItem()
	{
		sf::Vector2f screenPosition = GetFoodImagePosition();
		sf::String foodTexturePath = GetTexturePath();

		foodImage->initialize(foodTexturePath, cellWidth, cellHeight, screenPosition);
		foodImage->show();
	}


	

	void FoodItem::Update()
	{
		foodImage->update();
	}

	void FoodItem::Render()
	{
		foodImage->render();
	}

	sf::String FoodItem::GetTexturePath()
	{

		switch (foodType)
		{
		case Food::FoodType::APPLE:
			return Config::apple_texture_path;

		case Food::FoodType::MANGO:
			return Config::mango_texture_path;

		case Food::FoodType::ORANGE:
			return Config::orange_texture_path;

		case Food::FoodType::PIZZA:
			return Config::pizza_texture_path;

		case Food::FoodType::BURGER:
			return Config::burger_texture_path;

		case Food::FoodType::CHEESE:
			return Config::cheese_texture_path;

		case Food::FoodType::POISION:
			return Config::poision_texture_path;

		case Food::FoodType::ALCOHOL:
			return Config::alcohol_texture_path;
		}

	}
	sf::Vector2f FoodItem::GetFoodImagePosition()
	{
		float screen_position_x = LevelView::borderOffsetLeft + (cellWidth * gridPosition.x);
		float screen_position_y = LevelView::borderOffsetTop + (cellHeight * gridPosition.y);

		return sf::Vector2f(screen_position_x, screen_position_y);
	}
	FoodType FoodItem::GetFoodType()
	{
		return foodType;
	}
	sf::Vector2i FoodItem::GetFoodPosition()
	{
		return gridPosition;
	}
}

