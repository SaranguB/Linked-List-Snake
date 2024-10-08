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
	}

	Node* SingleLinkedList::CreateNode()
	{
		return new Node;
	}

	void SingleLinkedList::Render()
	{
	}
}


