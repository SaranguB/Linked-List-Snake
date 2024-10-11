#pragma once
#include "UI/UIElement/ImageView.h"

namespace Element
{
	class Obstacle
	{
	private:
		UI::UIElement::ImageView* obstacleImage;
		sf::Vector2i gridPosition;
		float cellWidth;
		float cellHeight;

		void InitializeObstacleImage();
		sf::Vector2f GetObstacleImagePosition();

	public:
		Obstacle();
		~Obstacle();

		void Initialize(sf::Vector2i gridPos, float width, float height);
		void Update();
		void Render();


	};
}
