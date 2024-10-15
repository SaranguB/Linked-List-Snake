	#pragma once
#include "Obstacle.h"
#include <vector>
#include <Element/ElementData.h>
#include "../LinkedList/Node.h"

namespace Element
{
	class ElementService
	{
	private:
		std::vector<Obstacle*> obstacleList;


		void spawnObstacle(sf::Vector2i position, float cellWidth, float cellHeight);

	public:
		ElementService();
		~ElementService();

		void Initialize();
		void Update();
		void Render();

		const void spawnElements(std::vector<ElementData>& elementDataList, float cellWidth, float cellHeight);

		std::vector<sf::Vector2i> GetElementPositionList();

		bool ProcessElementCollision(LinkedList::Node* headNode);

	};
}
