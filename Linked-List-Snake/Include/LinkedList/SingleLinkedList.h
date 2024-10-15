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
		int linkedListSize;
		Node* headNode;
		float nodeWidth;
		float nodeHeight;

		sf::Vector2i defaultPosition;
		Player::Direction defaultDirection;

		Node* CreateNode();
		void RemoveNodeAtHead();

		void InitializeNode(Node* newNode, Node* referenceNode, Operation operation);
		void ShiftNodesAfterInsertion(Node* newNode, Node* currentNode, Node* previousNode);

	public:
		SingleLinkedList();
		~SingleLinkedList();

		void Initialize(float width, float height, sf::Vector2i position, Player::Direction direction);
		void Render();

		void UpdateNodeDirection(Player::Direction directionToSet);
		void UpdateNodePosition();

		sf::Vector2i GetNewNodePosition(Node* referenceNode, Operation operation);
		void InsertNodeAtTail();
		void InsertNodeAtHead();
		void InsertNodeAtIndex(int index);
		void InsertNodeAtMiddle();

		void RemoveAllNodes();
		void RemoveNodeAtIndex(int index);
		void RemoveNodeAt(int index);
		void RemoveNodeAtMiddle();
		void ShiftNodesAfterRemoval(Node* currentNode);
		int FindMiddleNode();

		bool ProcessNodeCollission();

		std::vector<sf::Vector2i> GetNodePositionList();

		Node* GetHeadNode();


	};
}