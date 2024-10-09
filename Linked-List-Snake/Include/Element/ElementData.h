#pragma once
#include <SFML/System/Vector2.hpp>

namespace Element
{
	enum class ElementType
	{
		OBSTACLE,
	};

	struct ElementData
	{
		ElementData(ElementType type, sf::Vector2i pos)
		{
			elementType = type;
			position = pos;
		}

		ElementType elementType;
		sf::Vector2i position;
	};
}
