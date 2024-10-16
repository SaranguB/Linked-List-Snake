#pragma once
#include "Node.h"

namespace LinkedListLib
{
	enum class Operation
	{
		HEAD,
		MID,
		TAIL,
	};

	class LinkedList
	{
	protected:

		virtual Node* CreateNode() = 0;
		sf::Vector2i GetNewNodePosition(Node* referenceNode, Operation operation);
		Direction GetReverseDirection(Direction referenceDirection);

		int FindMiddleNode();
		Node* FindNodeAtIndex(int index);
		void InitializeNode(Node* newNode, Node* referenceNode, Operation operation);

		Node* headNode;

		float nodeWidth;
		float nodeHeight;

		sf::Vector2i defaultPosition;
		Direction defaultDirection;

		int linkedListSize;
	public:
		LinkedList();
		virtual ~LinkedList();

		void Initialize(float width, float height, sf::Vector2i position, Direction direction);

		void render();

		virtual void InsertNodeAtTail() = 0;
		virtual void InsertNodeAtHead() = 0;
		virtual void InsertNodeAtMiddle() = 0;
		virtual void InsertNodeAtIndex(int index) = 0;

		virtual void RemoveNodeAtTail() = 0;
		virtual void RemoveNodeAtHead() = 0;
		virtual void RemoveNodeAtMiddle() = 0;
		virtual void RemoveNodeAt(int index) = 0;
		virtual void RemoveAllNodes() = 0;
		virtual void RemoveHalfNodes() = 0;



		virtual Direction reverse() = 0;

		virtual void UpdateNodePosition();
		virtual void UpdateNodeDirection(Direction directionToSet);

		Node* GetHeadNode();
		int GetLinkedListSize();
		bool ProcessNodeCollision();
		void ReverseNodeDirections();

		std::vector<sf::Vector2i> GetNodesPositionList();


	};
}