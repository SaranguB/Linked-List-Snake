#pragma once
#include "../LinkedList.h"

namespace LinkedListLib
{
	namespace DoubleLinked

	{
		using namespace Player;
		class DoubleLinkedList : public LinkedList
		{
		protected:
			virtual Node* CreateNode() override;

		public:
			DoubleLinkedList();
			~DoubleLinkedList();

			void InsertNodeAtTail() override;
			void InsertNodeAtHead() override;
			void InsertNodeAtIndex(int index) override;
			void InsertNodeAtMiddle() override;

			void ShiftNodesAfterInsertion(Node* newNode, Node* currentNode, Node* previousNode);

			void RemoveAllNodes() override;
			void RemoveNodeAt(int index) override;
			void RemoveNodeAtIndex(int index);
			void RemoveNodeAtMiddle() override;
			void RemoveNodeAtTail() override;
			void RemoveHalfNodes() override;
			void RemoveNodeAtHead() override;
			void ShiftNodesAfterRemoval(Node* currentNode);


			Direction Reverse() override;
		};
	}
}