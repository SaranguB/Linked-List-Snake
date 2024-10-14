#include "../../Include//Element/Obstacle.h"
#include "../../Include/Level/LevelView.h"
#include "../../Include/Global/Config.h"

namespace Element
{
	using namespace UI::UIElement;
	using namespace Level;
	using namespace Global;

	Obstacle::Obstacle()
	{
		obstacleImage = new ImageView();
	}

	Obstacle::~Obstacle()
	{
		delete obstacleImage;
	}

	void Obstacle::Initialize(sf::Vector2i gridPos, float width, float height)
	{
		gridPosition = gridPos;
		cellWidth = width;
		cellHeight = height;
		InitializeObstacleImage();
	}

	void Obstacle::InitializeObstacleImage()
	{
		sf::Vector2f screenPosition = GetObstacleImagePosition();
		obstacleImage->initialize(Config::obstacle_texture_path, cellWidth, cellHeight, screenPosition);

		obstacleImage->show();
	}

	sf::Vector2f Obstacle::GetObstacleImagePosition()
	{
		float screenPositionX = LevelView::borderOffsetLeft + (cellWidth * gridPosition.x);
		float screenPositionY = LevelView::borderOffsetTop + (cellHeight * gridPosition.y);

		return sf::Vector2f(screenPositionX, screenPositionY);
	}

	void Obstacle::Update()
	{
		obstacleImage->update();
	}

	void Obstacle::Render()
	{
		obstacleImage->render();
	}
	sf::Vector2i Obstacle::GetObstaclePosition()
	{
		return gridPosition;
	}
}


