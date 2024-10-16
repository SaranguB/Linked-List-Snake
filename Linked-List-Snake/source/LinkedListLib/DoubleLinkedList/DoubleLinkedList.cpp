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
			if (index < 0 ||
				index >= linkedListSize)return;

			if (index == 0)
			{
				InsertNodeAtHead();
				return;
			}

			Node* newNode = CreateNode();

			int currentIndex = 0;
			Node* currentNode = headNode;
			Node* previousNode = nullptr;

			while (currentNode != nullptr && currentIndex < index)
			{
				previousNode = currentNode;
				currentNode = currentNode->next;
				currentIndex++;
			}

			previousNode->next = newNode;
			static_cast<DoubleNode*>(newNode)->previous = previousNode;
			newNode->next = currentNode;
			static_cast<DoubleNode*>(currentNode)->previous = newNode;

			InitializeNode(newNode, headNode, Operation::TAIL);
			linkedListSize++;

			ShiftNodesAfterInsertion(newNode, currentNode, previousNode);
		}

		void DoubleLinkedList::InsertNodeAtMiddle()
		{
			if (headNode == nullptr)
			{
				InsertNodeAtHead();
				return;
			}

			int middleIndex = FindMiddleNode();
			InsertNodeAtIndex(middleIndex);
		}


		void DoubleLinkedList::ShiftNodesAfterInsertion(Node* newNode, Node* currentNode, Node* previousNode)
		{
			Node* nextNode = currentNode;
			currentNode = newNode;

			while (currentNode != nullptr && nextNode != nullptr)
			{

				currentNode->bodyPart.SetPosition(nextNode->bodyPart.GetPosition());
				currentNode->bodyPart.SetDirection(nextNode->bodyPart.GetDirection());

				previousNode = currentNode;
				currentNode = nextNode;
				nextNode = nextNode->next;

			}

			InitializeNode(currentNode, previousNode, Operation::TAIL);
		}



		void DoubleLinkedList::RemoveNodeAtHead()
		{
			linkedListSize--;

			Node* currentNode = headNode;
			headNode = headNode->next;

			if (headNode != nullptr)
			{
				static_cast<DoubleNode*>(headNode)->previous = nullptr;
			}

			currentNode->next = nullptr;
			delete currentNode;
		}

		void DoubleLinkedList::RemoveNodeAtTail()
		{
			if (headNode == nullptr)return;

			linkedListSize--;

			Node* currentNode = headNode;

			if (currentNode->next == nullptr)
			{
				RemoveNodeAtHead();
				return;
			}

			while (currentNode->next != nullptr)
			{
				currentNode = currentNode->next;
			}

			Node* previous = static_cast<DoubleNode*>(currentNode)->previous;
			previous->next = nullptr;
			delete(currentNode);
		}

		void DoubleLinkedList::RemoveHalfNodes()
		{
			if (linkedListSize <= 1)return;

			int halfLength = linkedListSize / 2;
			int  newTailIndex = halfLength - 1;

			Node* previousNode = FindNodeAtIndex(newTailIndex);
			Node* currentNode = previousNode->next;

			while (currentNode != nullptr)
			{
				Node* nodeToDelete = currentNode;
				currentNode = currentNode->next;

				delete(nodeToDelete);

				linkedListSize--;
			}
			previousNode->next = nullptr;
		}

		void DoubleLinkedList::RemoveAllNodes()
		{
			if (headNode == nullptr)return;

			while (headNode != nullptr)
			{
				RemoveNodeAtHead();
			}
		}

		void DoubleLinkedList::RemoveNodeAt(int index)
		{
			if (index < 0 || index >= linkedListSize)return;

			if (index == 0)
			{
				RemoveNodeAtHead();
			}
			else
			{
				RemoveNodeAtIndex(index);
			}
		}

		void DoubleLinkedList::RemoveNodeAtIndex(int index)
		{
			linkedListSize--;

			int currentIndex = 0;
			Node* currentNode = headNode;
			Node* previousNode = nullptr;

			while (currentNode != nullptr && currentIndex < index)
			{
				previousNode = currentNode;
				currentNode = currentNode->next;
				currentIndex++;
			}

			if (previousNode != nullptr)
			{
				previousNode->next = currentNode->next;
			}

			if (currentNode->next != nullptr)
			{
				Node* nextNode = currentNode->next;
				static_cast<DoubleNode*>(nextNode)->previous = previousNode;
			}
			
			ShiftNodesAfterRemoval(currentNode);
			delete(currentNode);
			
		}

		void DoubleLinkedList::RemoveNodeAtMiddle()
		{
			if (headNode == nullptr)return;

			int middleIndex = FindMiddleNode();
			RemoveNodeAt(middleIndex);
		}

		void DoubleLinkedList::ShiftNodesAfterRemoval(Node* currentNode)
		{
			sf::Vector2i previousPosition = currentNode->bodyPart.GetPosition();
			Direction previousDirection = currentNode->bodyPart.GetDirection();

			currentNode = currentNode->next;

			while (currentNode != nullptr)
			{
				sf::Vector2i tempPosition = currentNode->bodyPart.GetPosition();
				Direction tempDirection = currentNode->bodyPart.GetDirection();

				currentNode->bodyPart.SetPosition(previousPosition);
				currentNode->bodyPart.SetDirection(previousDirection);

				currentNode = currentNode->next;
				previousPosition = tempPosition;
				previousDirection = tempDirection;
			}
		}
	}
}