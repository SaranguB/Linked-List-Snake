#pragma once
#include "../../Include/Player/BodyPart.h"

namespace LinkedList
{
	struct Node
	{
		
		Player::BodyPart bodyPart;
		Node* next = nullptr;
	};
}
