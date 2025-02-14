#include "../../Include/LinkedList/SingleLinkedList.h"
#include <iostream>

namespace LinkedList
{

	using namespace Player;
	LinkedList::SingleLinkedList::SingleLinkedList()
	{
		headNode = nullptr;
	}

	SingleLinkedList::~SingleLinkedList()
	{
	}

	void SingleLinkedList::Initialize(float width, float height, sf::Vector2i position, Player::Direction direction)
	{
		nodeWidth = width;
		nodeHeight = height;
		defaultPosition = position;
		defaultDirection = direction;
		linkedListSize = 0;
	}

	void SingleLinkedList::InitializeNode(Node* newNode, Node* referenceNode, Operation operation)
	{
		if (referenceNode == nullptr)
		{
			newNode->bodyPart.Initialize(nodeWidth, nodeHeight, defaultPosition, defaultDirection);
			return;
		}

		sf::Vector2i position = GetNewNodePosition(referenceNode, operation);

		newNode->bodyPart.Initialize(nodeWidth, nodeHeight, position, referenceNode->bodyPart.GetDirection());
	}

	void SingleLinkedList::Render()
	{
		Node* currentNode = headNode;

		while (currentNode != nullptr)
		{
			currentNode->bodyPart.Render();
			currentNode = currentNode->next;
		}

	}

	void SingleLinkedList::UpdateNodeDirection(Player::Direction directionToSet)
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

	void SingleLinkedList::UpdateNodePosition()
	{
		Node* currentNode = headNode;

		while (currentNode != nullptr)
		{
			currentNode->bodyPart.UpdatePosition();
			currentNode = currentNode->next;
		}

	}

	sf::Vector2i SingleLinkedList::GetNewNodePosition(Node* referenceNode, Operation operation)
	{

		switch (operation)
		{
		case LinkedList::Operation::HEAD:
			return referenceNode->bodyPart.GetNextPosition();

		case LinkedList::Operation::TAIL:
			return referenceNode->bodyPart.GetPreviousPosition();

		}
		return defaultPosition;
	}

	void SingleLinkedList::InsertNodeAtTail()
	{
		linkedListSize++;
		Node* newNode = CreateNode();
		Node* currentNode = headNode;

		if (currentNode == nullptr)
		{
			headNode = newNode;
			InitializeNode(newNode, nullptr, Operation::TAIL);
			return;
		}

		while (currentNode->next != nullptr)
		{
			currentNode = currentNode->next;
		}

		currentNode->next = newNode;
		InitializeNode(newNode, currentNode, Operation::TAIL);

		//std::cout << "Inserted new node at position: " << newNode->bodyPart.GetPosition().x << ", " << newNode->bodyPart.GetPosition().y << std::endl;


	}

	void SingleLinkedList::InsertNodeAtHead()
	{
		linkedListSize++;
		Node* newNode = CreateNode();

		if (headNode == nullptr)
		{
			headNode = newNode;
			InitializeNode(newNode, nullptr, Operation::HEAD);
			return;
		}

		InitializeNode(newNode, headNode, Operation::HEAD);
		newNode->next = headNode;
		headNode = newNode;
	}

	void SingleLinkedList::InsertNodeAtIndex(int index)
	{
		if (index < 0 || index >= linkedListSize)return;

		if (index == 0)
		{
			InsertNodeAtHead();
			return;
		}

		Node* newNode = CreateNode();

		int currentIndex = 0;
		Node* currentNode = headNode;
		Node* previousNode = nullptr;

		while (currentNode != nullptr && currentIndex < index)
		{
			previousNode = currentNode;
			currentNode = currentNode->next;
			currentIndex++;
		}

		previousNode->next = newNode;
		newNode->next = currentNode;
		InitializeNode(newNode, previousNode, Operation::TAIL);
		linkedListSize++;

		ShiftNodesAfterInsertion(newNode, currentNode, previousNode);
	}

	void SingleLinkedList::InsertNodeAtMiddle()
	{
		if (headNode == nullptr)
		{
			InsertNodeAtHead();
			return;
		}

		int middleIndex = FindMiddleNode();
		InsertNodeAtIndex(middleIndex);
	}

	void SingleLinkedList::ShiftNodesAfterInsertion(Node* newNode, Node* currentNode, Node* previousNode)
	{
		Node* nextNode = currentNode;
		currentNode = newNode;

		while (currentNode != nullptr && nextNode != nullptr)
		{

			currentNode->bodyPart.SetPosition(nextNode->bodyPart.GetPosition());
			currentNode->bodyPart.SetDirection(nextNode->bodyPart.GetDirection());

			previousNode = currentNode;
			currentNode = nextNode;
			nextNode = nextNode->next;

		}

		InitializeNode(currentNode, previousNode, Operation::TAIL);
	}

	void SingleLinkedList::RemoveAllNodes()
	{
		if (headNode == nullptr)return;
		while (headNode != nullptr)
		{
			RemoveNodeAtHead();
		}
	}

	void SingleLinkedList::RemoveNodeAt(int index)
	{
		if (index < 0 || index >= linkedListSize)return;

		if (index == 0)
		{
			RemoveNodeAtHead();
		}
		else
		{
			RemoveNodeAtIndex(index);
		}
	}

	void SingleLinkedList::RemoveNodeAtIndex(int index)
	{
		if (index < 0 || index >= linkedListSize)return;

		int currentIndex = 0;
		Node* currentNode = headNode;
		Node* previousNode = nullptr;
		while (currentNode != nullptr && currentIndex < index)
		{
			previousNode = currentNode;
			currentNode = currentNode->next;
			currentIndex++;
		}

		previousNode->next = currentNode->next;
		ShiftNodesAfterRemoval(currentNode);
		delete(currentNode);
		linkedListSize--;

	}


	void SingleLinkedList::RemoveNodeAtMiddle()
	{
		if (headNode == nullptr)return;

		int middleIndex = FindMiddleNode();
		RemoveNodeAt(middleIndex);
	}

	void SingleLinkedList::RemoveNodeAtTail()
	{
		if (headNode == nullptr)return;
		linkedListSize--;

		Node* currentNode = headNode;
		if (currentNode->next == nullptr)
		{
			RemoveNodeAtHead();
			return;
		}

		while (currentNode->next->next != nullptr)
		{
			currentNode = currentNode->next;
		}

		delete(currentNode->next);
		currentNode->next = nullptr;
	}

	void SingleLinkedList::RemoveHalfNode()
	{
		if (linkedListSize <= 1)return;

		int halfLength = linkedListSize / 2;
		int  newTailIndex = halfLength - 1;

		Node* previousNode = FindNodeAtIndex(newTailIndex);
		Node* currentNode = previousNode->next;

		while (currentNode != nullptr)
		{
			Node* nodeToDelete = currentNode;
			currentNode = currentNode->next;

			delete(nodeToDelete);

			linkedListSize--;
		}
		previousNode->next = nullptr;
	}

	void SingleLinkedList::ShiftNodesAfterRemoval(Node* currentNode)
	{
		sf::Vector2i previousPosition = currentNode->bodyPart.GetPosition();
		Direction previousDirection = currentNode->bodyPart.GetDirection();

		currentNode = currentNode->next;

		while (currentNode != nullptr)
		{
			sf::Vector2i tempPosition = currentNode->bodyPart.GetPosition();
			Direction tempDirection = currentNode->bodyPart.GetDirection();

			currentNode->bodyPart.SetPosition(previousPosition);
			currentNode->bodyPart.SetDirection(previousDirection);

			currentNode = currentNode->next;
			previousPosition = tempPosition;
			previousDirection = tempDirection;
		}

	}

	int SingleLinkedList::FindMiddleNode()
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
		return middleIndex;
	}

	Direction SingleLinkedList::GetReverseDirection(Direction referenceDirection)
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

	void SingleLinkedList::ReverseNodeDirections()
	{
		Node* currentNode = headNode;

		while (currentNode != nullptr)
		{
			currentNode->bodyPart.SetDirection(GetReverseDirection(currentNode
				->bodyPart.GetPreviousDirection()));
			currentNode = currentNode->next;
		}
	}

	Player::Direction SingleLinkedList::reverse()
	{
		Node* currentNode = headNode;
		Node* previousNode = nullptr;
		Node* nextNode = nullptr;

		while (currentNode != nullptr)
		{
			nextNode = currentNode->next;
			currentNode->next = previousNode;

			previousNode = currentNode;
			currentNode = nextNode;
		}
		headNode = previousNode;

		ReverseNodeDirections();
		return headNode->bodyPart.GetDirection();
	}

	Node* SingleLinkedList::FindNodeAtIndex(int index)
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



	void SingleLinkedList::RemoveNodeAtHead()
	{
		Node* currentNode = headNode;
		headNode = headNode->next;

		currentNode->next = nullptr;
		delete currentNode;
		linkedListSize--;
	}





	bool SingleLinkedList::ProcessNodeCollission()
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

	std::vector<sf::Vector2i> SingleLinkedList::GetNodePositionList()
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

	Node* SingleLinkedList::GetHeadNode()
	{
		return headNode;
	}

	Node* SingleLinkedList::CreateNode()
	{


		return new Node();
	}

}


