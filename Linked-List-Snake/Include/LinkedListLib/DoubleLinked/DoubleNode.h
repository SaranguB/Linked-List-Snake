#pragma once
#include "../Node.h"

namespace LinkedListLib
{
	namespace DoubleLinked
	{
		struct DoubleNode : public Node
		{
			Node* previous = nullptr;
		};
	}
}
