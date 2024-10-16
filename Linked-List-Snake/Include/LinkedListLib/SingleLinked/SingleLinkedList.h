#pragma once
#include <SFML/System/Vector2.hpp>
#include "LinkedListLib/Node.h"
#include "../SingleLinked/SingleNode.h"
#include "LinkedListLib/LinkedList.h"

namespace LinkedListLib
{
	namespace SingleLinked
	{
		class SingleLinkedList : public LinkedList
		{
		protected:


			virtual Node* CreateNode() override;


		public:
			SingleLinkedList();
			~SingleLinkedList();

			void InsertNodeAtTail() override;
			void InsertNodeAtHead() override;
			void InsertNodeAtIndex(int index) override;
			void InsertNodeAtMiddle() override;

			void ShiftNodesAfterInsertion(Node* newNode, Node* currentNode, Node* previousNode) ;

			void RemoveAllNodes() override;
			void RemoveNodeAt(int index) override;
			void RemoveNodeAtIndex(int index) ;
			void RemoveNodeAtMiddle() override;
			void RemoveNodeAtTail() override;
			void RemoveHalfNodes() override;
			void RemoveNodeAtHead() override;

			void ShiftNodesAfterRemoval(Node* currentNode);
			
			void ReverseNodeDirections();
			Player::Direction reverse() override;

		};
	}
}