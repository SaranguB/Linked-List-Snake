#pragma once
#include "Player/BodyPart.h"

namespace LinkedListLib
{
	using namespace Player;

	struct Node
	{
		BodyPart bodyPart;
		Node* next = nullptr;
	};
}
