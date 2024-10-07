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

		float bodyPartWidth;
		float bodyPartHeight;

		void CreateBodyPartImage();
		void Destroy();

		void InitializeBodyPartImage();
		sf::Vector2f GetBodyPartScreenPosition();

		float GetRotationAngle();

		void UpdatePosition();

		sf::Vector2i GetNextPositionUp();
		sf::Vector2i GetNextPositionDown();
		sf::Vector2i GetNextPositionLeft();
		sf::Vector2i GetNextPositionRight();

	public:
		BodyPart();
		~BodyPart();

		void Initialize(float width, float height, sf::Vector2i position, Direction direction);
		void Update();
		void Render();

		Direction GetDirection();
		void SetDirection(Direction direction);

		sf::Vector2i GetNextPosition();
		void  SetPosition(sf::Vector2i position);
		sf::Vector2i GetPosition();

	};
}