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
		Node* newNode = CreateNode();
		Node* currentNode = headNode;

		if (currentNode == nullptr)
		{
			headNode = newNode;
			newNode->bodyPart.Initialize(nodeWidth, nodeHeight, defaultPosition, defaultDirection);
			//std::cout << "Inserted head node at position: " << defaultPosition.x << ", " << defaultPosition.y << std::endl;
			return;
		}

		while (currentNode->next != nullptr)
		{
			currentNode = currentNode->next;
		}

		currentNode->next = newNode;
		newNode->bodyPart.Initialize(nodeWidth, nodeHeight,
			GetNewNodePosition(currentNode, Operation::TAIL), currentNode->bodyPart.GetDirection());

		//std::cout << "Inserted new node at position: " << newNode->bodyPart.GetPosition().x << ", " << newNode->bodyPart.GetPosition().y << std::endl;


	}

	void SingleLinkedList::RemoveAllNodes()
	{
		if (headNode == nullptr)return;
		while (headNode != nullptr)
		{
			RemoveNodeAtHead();
		}
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

	void SingleLinkedList::RemoveNodeAtHead()
	{
		Node* currentNode = headNode;
		headNode = headNode->next;

		currentNode->next = nullptr;
		delete currentNode;
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


