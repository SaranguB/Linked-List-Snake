#pragma once
#include "Node.h"
#include "../../Include/Player/Direction.h"
namespace LinkedList
{
	enum class Operation
	{
		HEAD,
		MID,
		TAIL,
	};

	class SingleLinkedList
	{
	private:

		Node* headNode;
		float nodeWidth;
		float nodeHeight;

		sf::Vector2i defaultPosition;
		Player::Direction defaultDirection;

		Node* CreateNode();
		void RemoveNodeAtHead();

		void InitializeNode(Node* newNode, Node* referenceNode, Operation operation);

	public:
		SingleLinkedList();
		~SingleLinkedList();

		void Initialize(float width, float height, sf::Vector2i position, Player::Direction direction);
		void Render();

		void UpdateNodeDirection(Player::Direction directionToSet);
		void UpdateNodePosition();

		sf::Vector2i GetNewNodePosition(Node* referenceNode, Operation operation);
		void InsertNodeAtTail();
		void RemoveAllNodes();
		bool ProcessNodeCollission();

		std::vector<sf::Vector2i> GetNodePositionList();

		Node* GetHeadNode();

	};
}