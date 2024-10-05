#include "../../Include/Level/LevelView.h"
#include "Global/ServiceLocator.h"

namespace Level
{
	using namespace UI::UIElement;
	using namespace Global;

	LevelView::LevelView(LevelController* controller)
	{
		LevelController* levelController = controller;
		backgroundRectangle = new RectangleShapeView();
		borderRectangle = new RectangleShapeView();
	}

	LevelView::~LevelView()
	{
		delete(backgroundRectangle);
		delete(borderRectangle);
	}


	void LevelView::Initialize()
	{
		InitializeBackground();
		CalculateGridExtends();
		InitializeBorder();
	}

	void LevelView::CalculateGridExtends()
	{
		sf::RenderWindow* gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

		gridWidth = gameWindow->getSize().x - 2 * borderOffsetLeft;
		gridHeight = gameWindow->getSize().y - 2 * borderOffsetTop;
	}

	void LevelView::InitializeBorder()
	{
		sf::RenderWindow* gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

		sf::Vector2f bordrSize = sf::Vector2f(gridWidth, gridHeight);
		sf::Vector2f borderPosition = sf::Vector2f(borderOffsetLeft, borderOffsetTop);

		borderRectangle->initialize(bordrSize, borderPosition, borderThickness, sf::Color::Transparent, borderColor);
		borderRectangle->show();
	}

	void LevelView::Update()
	{
		backgroundRectangle->update();
		borderRectangle->update();
	}
	void LevelView::Render()
	{
		backgroundRectangle->render();
		borderRectangle->render();
	}


	void LevelView::InitializeBackground()
	{
		sf::RenderWindow* gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

		sf::Vector2f backgroundSize = sf::Vector2f(gameWindow->getSize().x, gameWindow->getSize().y);

		backgroundRectangle->initialize(backgroundSize, sf::Vector2f(0, 0), 0, backgroundColor);
		backgroundRectangle->show();

	}
	float LevelView::GetGridWidth()
	{
		return gridWidth;
	}
	float LevelView::GetGridHeight()
	{
		return gridHeight;
	}
}
