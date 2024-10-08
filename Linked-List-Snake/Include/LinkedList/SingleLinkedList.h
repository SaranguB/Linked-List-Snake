#pragma once
#include "Node.h"
#include "../../Include/Player/Direction.h"
namespace LinkedList
{
	class SingleLinkedList
	{
	private:

		Node* headNode;
		float nodeWidth;
		float nodeHeight;

		sf::Vector2i defaultPosition;
		Player::Direction defaultDirection;

		Node* CreateNode();

	public:
		SingleLinkedList();
		~SingleLinkedList();

		void Initialize(float width, float height, sf::Vector2i position, Player::Direction direction);
		void Render();

		void UpdateNodeDirection(Player::Direction directionToSet);
		void UpdateNodePosition();

		sf::Vector2i GetNewNodePosition(Node* referenceNode);
		void InsertNodeAtTail();
	};
}