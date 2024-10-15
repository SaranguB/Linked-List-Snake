#pragma once
#include "Direction.h"
#include "UI/UIElement/ImageView.h"

namespace Player
{

	class BodyPart
	{
	private:
		UI::UIElement::ImageView* bodyPartImage;
		sf::Vector2i gridPosition;

		Direction direction;
		Direction previousDirection;

		float bodyPartWidth;
		float bodyPartHeight;

		void CreateBodyPartImage();
		void Destroy();

		void InitializeBodyPartImage();
		sf::Vector2f GetBodyPartScreenPosition();

		float GetRotationAngle();


		sf::Vector2i GetNextPositionUp();
		sf::Vector2i GetNextPositionDown();
		sf::Vector2i GetNextPositionLeft();
		sf::Vector2i GetNextPositionRight();

	public:
		BodyPart();
		~BodyPart();

		void Initialize(float width, float height, sf::Vector2i position, Direction direction);
		void UpdatePosition();

		void Render();

		Direction GetDirection();
		Direction GetPreviousDirection();
		void SetDirection(Direction newDirection);

		sf::Vector2i GetNextPosition();
		sf::Vector2i GetPreviousPosition();
		void  SetPosition(sf::Vector2i position);
		sf::Vector2i GetPosition();



	};
}