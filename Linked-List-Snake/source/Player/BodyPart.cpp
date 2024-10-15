#include "../../Include/Player/BodyPart.h"
#include "../../Include/Global/Config.h"
#include "../../Include/Level/LevelView.h"
#include "../../Include/Level/LevelModel.h"

namespace Player
{

	using namespace UI::UIElement;
	using namespace Global;
	using namespace Level;

	BodyPart::BodyPart()
	{
		CreateBodyPartImage();
		gridPosition = sf::Vector2i(0, 0);
	}

	void Player::BodyPart::CreateBodyPartImage()
	{
		bodyPartImage = new ImageView();
	}


	BodyPart::~BodyPart()
	{
		Destroy();
	}

	void BodyPart::Destroy()
	{
		delete bodyPartImage;
	}


	void BodyPart::Initialize(float width, float height, sf::Vector2i position, Direction dir)
	{
		bodyPartWidth = width;
		bodyPartHeight = height;
		gridPosition = position;
		direction = dir;

		InitializeBodyPartImage();

	}


	void BodyPart::InitializeBodyPartImage()
	{
		bodyPartImage->initialize(Config::snake_body_texture_path, bodyPartWidth, bodyPartHeight, GetBodyPartScreenPosition());
		bodyPartImage->setOriginAtCentre();
	}

	sf::Vector2f BodyPart::GetBodyPartScreenPosition()
	{

		float xScreenPosition = LevelView::borderOffsetLeft + (gridPosition.x * bodyPartWidth) + (bodyPartWidth / 2);
		float yScreenPosition = LevelView::borderOffsetTop + (gridPosition.y * bodyPartHeight) + (bodyPartHeight / 2);

		return sf::Vector2f(xScreenPosition, yScreenPosition);
	}

	float BodyPart::GetRotationAngle()
	{
		switch (direction)
		{
		case Player::Direction::UP:
			return 270.f;

		case Player::Direction::DOWN:
			return 90.f;

		case Player::Direction::RIGHT:
			return 0;

		case Player::Direction::LEFT:
			return 180.f;

		}
	}

	void BodyPart::UpdatePosition()
	{
		gridPosition = GetNextPosition();

		bodyPartImage->setPosition(GetBodyPartScreenPosition());
		bodyPartImage->setRotation(GetRotationAngle());
		bodyPartImage->update();

	}



	void BodyPart::Render()
	{
		bodyPartImage->render();
	}

	Direction BodyPart::GetDirection()
	{

		return direction;
	}

	Direction BodyPart::GetPreviousDirection()
	{
		return previousDirection;
	}

	void BodyPart::SetDirection(Direction newDirection)
	{
		previousDirection = direction;
		direction = newDirection;
	}

	sf::Vector2i BodyPart::GetNextPosition()
	{
		switch (direction)
		{
		case Direction::UP:
			return GetNextPositionUp();

		case Direction::DOWN:
			return GetNextPositionDown();

		case Direction::LEFT:
			return GetNextPositionLeft();

		case Direction::RIGHT:
			//printf("right");
			return GetNextPositionRight();

		default:
			return gridPosition;
		}
	}

	sf::Vector2i BodyPart::GetPreviousPosition()
	{
		switch (direction)
		{
		case Direction::UP:
			return GetNextPositionDown();

		case Direction::DOWN:
			return GetNextPositionUp();

		case Direction::LEFT:
			return GetNextPositionRight();

		case Direction::RIGHT:
			//printf("right");
			return GetNextPositionLeft();

		default:
			return gridPosition;
		}
	}

	void BodyPart::SetPosition(sf::Vector2i position)
	{
		gridPosition = position;
	}

	sf::Vector2i BodyPart::GetPosition()
	{
		return gridPosition;
	}


	sf::Vector2i BodyPart::GetNextPositionUp()
	{
		return sf::Vector2i(gridPosition.x, (gridPosition.y - 1 + (LevelModel::numberOfRows)) % (LevelModel::numberOfRows));

	}

	sf::Vector2i BodyPart::GetNextPositionDown()
	{
		return sf::Vector2i(gridPosition.x, (gridPosition.y + 1) % (LevelModel::numberOfRows));
	}

	sf::Vector2i BodyPart::GetNextPositionLeft()
	{
		return sf::Vector2i((gridPosition.x - 1 + LevelModel::numberOfColumns) %
			(LevelModel::numberOfColumns), gridPosition.y);

	}

	sf::Vector2i BodyPart::GetNextPositionRight()
	{
		return sf::Vector2i((gridPosition.x + 1) % (LevelModel::numberOfColumns), gridPosition.y);
	}



}
