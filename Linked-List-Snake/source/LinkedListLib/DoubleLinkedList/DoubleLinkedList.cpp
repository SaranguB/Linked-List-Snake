#include "../../Include/LinkedListLib/DoubleLinked/DoubleLinkedList.h"

namespace LinkedListLib
{
	namespace DoubleLinked
	{
		Node* DoubleLinkedList::CreateNode()
		{
			return new DoubleNode();
		}

		DoubleLinkedList::DoubleLinkedList() = default;

		DoubleLinkedList::~DoubleLinkedList() = default;

		

		void DoubleLinkedList::InsertNodeAtHead()
		{
			linkedListSize++;
			Node* newNode = CreateNode();

			if (headNode == nullptr)
			{
				headNode = newNode;
				static_cast<DoubleNode*>(newNode)->previous = nullptr;
				InitializeNode(newNode, nullptr, Operation::HEAD);
				return;
			}

			InitializeNode(newNode, headNode, Operation::HEAD);

			newNode->next = headNode;
			static_cast<DoubleNode*>(headNode)->previous = newNode;

			headNode = newNode;
		}

		void DoubleLinkedList::InsertNodeAtTail()
		{
			linkedListSize++;
			Node* newNode = CreateNode();
			Node* currentNode = headNode;

			if (currentNode == nullptr)
			{
				headNode = newNode;
				static_cast<DoubleNode*>(newNode)->previous = nullptr;
				InitializeNode(newNode, nullptr, Operation::TAIL);
				return;
			}

			while (currentNode->next != nullptr)
			{
				currentNode = currentNode->next;
			}

			currentNode->next = newNode;
			static_cast<DoubleNode*>(newNode)->previous = currentNode;
			InitializeNode(newNode, currentNode, Operation::TAIL);
		}

		void DoubleLinkedList::InsertNodeAtIndex(int index)
		{
		}

		void DoubleLinkedList::InsertNodeAtMiddle()
		{
		}

	}
}