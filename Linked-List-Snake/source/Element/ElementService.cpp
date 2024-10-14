#include "../../Include/Element/ElementService.h"


namespace Element
{

	ElementService::ElementService()
	{
	}
	ElementService::~ElementService()
	{
	}
	void ElementService::Initialize()
	{
	}
	void ElementService::Update()
	{
		for (int i = 0;i < obstacleList.size();i++)
		{
			obstacleList[i]->Update();
		}
	}
	void ElementService::Render()
	{
		for (int i = 0;i < obstacleList.size();i++)
		{
			obstacleList[i]->Render();
		}
	}


	const void ElementService::spawnElements(std::vector<ElementData>& elementDataList, float cellWidth, float cellHeight)
	{
		for (int i = 0;i < elementDataList.size();i++)
		{
			switch (elementDataList[i].elementType)
			{
			case ElementType::OBSTACLE:
				spawnObstacle(elementDataList[i].position, cellWidth, cellHeight);
				break;
			}
		}

	}
	std::vector<sf::Vector2i> ElementService::GetElementPositionList()
	{
		std::vector<sf::Vector2i> elementPositionList;

		for (int i = 0;i < obstacleList.size();i++)
		{
			elementPositionList.push_back(obstacleList[i]->GetObstaclePosition());
		}
		return elementPositionList;
	}

	

	void ElementService::spawnObstacle(sf::Vector2i position, float cellWidth, float cellHeight)
	{
		Obstacle* obstacle = new Obstacle();

		obstacle->Initialize(position, cellWidth, cellHeight);
		obstacleList.push_back(obstacle);
	}

	bool ElementService::ProcessElementCollision(LinkedList::Node* headNode)
	{

		for (int i = 0;i < obstacleList.size();i++)
		{
			if (obstacleList[i]->GetObstaclePosition() == headNode->bodyPart.GetNextPosition()
				|| obstacleList[i]->GetObstaclePosition() == headNode->bodyPart.GetPosition())
			{
				return true;
			}
		}

		return false;
	}
	

	
}
