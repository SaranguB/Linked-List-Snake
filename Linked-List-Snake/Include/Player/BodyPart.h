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
	public:

	};
}