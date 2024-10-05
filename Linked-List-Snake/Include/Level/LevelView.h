#pragma once
#include "UI/UIElement/RectangleShapeView.h"

namespace Level
{
	class LevelController;
	class LevelView
	{
	private:
		UI::UIElement::RectangleShapeView* backgroundRectangle;
		UI::UIElement::RectangleShapeView* borderRectangle;

		const sf::Color backgroundColor = sf::Color(180, 200, 160);
		const sf::Color borderColor = sf::Color::Black;

		float gridWidth;
		float gridHeight;

		void CalculateGridExtends();
		void InitializeBorder();

	public:
		LevelView(LevelController* controller);
		~LevelView();

		void Initialize();
		void Update();
		void Render();


		void InitializeBackground();

		static const int borderThickness = 10;
		static const int borderOffsetLeft = 40;
		static const int borderOffsetTop = 40;

		float GetGridWidth();
		float GetGridHeight();


	};
}
