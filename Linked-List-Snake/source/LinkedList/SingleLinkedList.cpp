#include "../../Include/LinkedList/SingleLinkedList.h"

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


	sf::Vector2i SingleLinkedList::GetNewNodePosition(Node* referenceNode)
	{

		Direction referenceDirection = referenceNode->bodyPart.GetDirection();
		sf::Vector2i referencePosition = referenceNode->bodyPart.GetPosition();

		switch (referenceDirection)
		{
		case Direction::UP:
			return sf::Vector2i(referencePosition.x, referencePosition.y - 1);
			break;

		case Direction::DOWN:
			return sf::Vector2i(referencePosition.x, referencePosition.y + 1);
			break;

		case Direction::LEFT:
			return sf::Vector2i(referencePosition.x - 1, referencePosition.y);
			break;

		case Direction::RIGHT:
			return sf::Vector2i(referencePosition.x + 1, referencePosition.y);
			break;
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
			return;
		}

		while (currentNode->next != nullptr)
		{
			currentNode = currentNode->next;
		}

		currentNode->next = newNode;
		newNode->bodyPart.Initialize(nodeWidth, nodeHeight,
			GetNewNodePosition(currentNode), currentNode->bodyPart.GetDirection());


	}

	Node* SingleLinkedList::CreateNode()
	{
		return new Node;
	}

}


