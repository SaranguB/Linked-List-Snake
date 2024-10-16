#pragma once
#include "../Node.h"

namespace LinkedListLib
{
	namespace DoubleLinked
	{
		struct DoubleLinked : public Node
		{
			Node* previous = nullptr;
		};
	}
}
