#include "../../Include/LinkedList/SingleLinkedList.h"

namespace LinkedList
{


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
		headNode->bodyPart.Render();
	}

	void SingleLinkedList::CreateHeadNode()
	{
		headNode = CreateNode();
		headNode->bodyPart.Initialize(nodeWidth, nodeHeight, defaultPosition, defaultDirection);
		return;
	}

	Node* SingleLinkedList::CreateNode()
	{
		return new Node;
	}
	
}


