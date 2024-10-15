#pragma once
#include "UI/UIElement/ImageView.h"
#include "FoodType.h"

namespace Food
{
	class FoodItem
	{
	private:
		UI::UIElement::ImageView* foodImage;

		sf::Vector2i gridPosition;
		float cellWidth;
		float cellHeight;
		FoodType foodType;

		void IntializeFoodItem();
	public:
		FoodItem();
		~FoodItem();

		void Initialize(sf::Vector2i gridPos, float width, float height, FoodType type);
		void Update();
		void Render();
		static const int numberOfFoods = 8;

		sf::String GetTexturePath();
		sf::Vector2f GetFoodImagePosition();

		FoodType GetFoodType();
		sf::Vector2i GetFoodPosition();

	};
}
