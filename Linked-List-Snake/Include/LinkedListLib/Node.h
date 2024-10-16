#pragma once
#include "Player/BodyPart.h"

namespace LinkedListLib
{
	using namespace Player;

	struct Node
	{
		BodyPart bodypart;
		Node* next = nullptr;
	}
}
