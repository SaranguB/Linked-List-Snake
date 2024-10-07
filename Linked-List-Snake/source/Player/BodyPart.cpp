#include "../../Include/Player/BodyPart.h"
#include "../../Include/Global/Config.h"

namespace Player
{

	using namespace UI::UIElement;
	using namespace Global;

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
		bodyPartImage->initialize(Config::snake_body_texture_path, bodyPartWidth,bodyPartHeight,GetBodyPartScreenPosition());
		bodyPartImage->setOriginAtCentre();
	}

	sf::Vector2f BodyPart::GetBodyPartScreenPosition()
	{
		return sf::Vector2f();
	}

	void BodyPart::Render()
	{
		bodyPartImage->render();
	}


}
