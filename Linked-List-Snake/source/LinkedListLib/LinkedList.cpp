#include "../../Include/LinkedListLib/LinkedList.h"

namespace LinkedListLib
{
	using namespace Player;
	LinkedList::LinkedList()
	{
		headNode = nullptr;
	}

	LinkedList::~LinkedList()
	{
	}

	void LinkedList::Initialize(float width, float height, sf::Vector2i position, Direction direction)
	{
		nodeWidth = width;
		nodeHeight = height;
		defaultPosition = position;
		defaultDirection = direction;
		linkedListSize = 0;
	}

	void LinkedList::InitializeNode(Node* newNode, Node* referenceNode, Operation operation)
	{
		if (referenceNode == nullptr)
		{
			newNode->bodyPart.Initialize(nodeWidth, nodeHeight, defaultPosition, defaultDirection);
			return;
		}

		sf::Vector2i position = GetNewNodePosition(referenceNode, operation);

		newNode->bodyPart.Initialize(nodeWidth, nodeHeight, position, referenceNode->bodyPart.GetDirection());
	}

	void LinkedList::render()
	{
		Node* currentNode = headNode;

		while (currentNode != nullptr)
		{
			currentNode->bodyPart.Render();
			currentNode = currentNode->next;
		}
	}

	void LinkedList::UpdateNodePosition()
	{
		Node* currentNode = headNode;

		while (currentNode != nullptr)
		{
			currentNode->bodyPart.UpdatePosition();
			currentNode = currentNode->next;
		}
	}

	void LinkedList::UpdateNodeDirection(Direction directionToSet)
	{
		Node* currentNode = headNode;

		while (currentNode != nullptr)
		{
			Direction previousDirection = currentNode->bodyPart.GetDirection();

			currentNode->bodyPart.SetDirection(directionToSet);
			directionToSet = previousDirection;
			currentNode = currentNode->next;
		}
	}

	Node* LinkedList::GetHeadNode()
	{
		return headNode;
	}

	int LinkedList::GetLinkedListSize()
	{
		return linkedListSize;
	}

	bool LinkedList::ProcessNodeCollision()
	{
		if (headNode == nullptr)return false;

		sf::Vector2i predictedPosition = headNode->bodyPart.GetNextPosition();

		Node* currentNode = headNode->next;

		while (currentNode != nullptr)
		{
			if (currentNode->bodyPart.GetNextPosition() == predictedPosition)return true;
			currentNode = currentNode->next;

		}

		return false;
	}

	void LinkedList::ReverseNodeDirections()
	{
		Node* currentNode = headNode;

		while (currentNode != nullptr)
		{
			currentNode->bodyPart.SetDirection(GetReverseDirection(currentNode
				->bodyPart.GetPreviousDirection()));
			currentNode = currentNode->next;
		}
	}

	std::vector<sf::Vector2i> LinkedList::GetNodesPositionList()
	{
		std::vector<sf::Vector2i> nodesPositionList;

		Node* currentNode = headNode;

		while (currentNode != nullptr)
		{
			nodesPositionList.push_back(currentNode->bodyPart.GetPosition());
			currentNode = currentNode->next;
		}

		return nodesPositionList;
	}

	sf::Vector2i LinkedList::GetNewNodePosition(Node* referenceNode, Operation operation)
	{
		switch (operation)
		{
		case Operation::HEAD:
			return referenceNode->bodyPart.GetNextPosition();

		case Operation::TAIL:
			return referenceNode->bodyPart.GetPreviousPosition();

		}
		return defaultPosition;
	}

	Direction LinkedList::GetReverseDirection(Direction referenceDirection)
	{
		switch (referenceDirection)
		{
		case Direction::UP:
			return Direction::DOWN;
		case Direction::DOWN:
			return Direction::UP;
		case Direction::LEFT:
			return Direction::RIGHT;
		case Direction::RIGHT:
			return Direction::LEFT;
		}
	}

	int LinkedList::FindMiddleNode()
	{
		Node* slow = headNode;
		Node* fast = headNode;
		int middleIndex = 0;

		while (fast != nullptr && fast->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
			middleIndex++;
		}
		return middleIndex;;
	}

	Node* LinkedList::FindNodeAtIndex(int index)
	{
		int currentIndex = 0;

		Node* currentNode = headNode;
		Node* previousNode = nullptr;


		while (currentNode != nullptr && currentIndex <= index)
		{
			previousNode = currentNode;
			currentNode = currentNode->next;
			currentIndex++;
		}
		return previousNode;
	}

}