#pragma once
#include "BodyPart.h"

namespace Player
{
	struct Node
	{
		BodyPart bodyPart;
		Node* next = nullptr;
	};
}
