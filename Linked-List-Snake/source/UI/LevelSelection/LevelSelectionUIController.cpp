#include "UI/LevelSelection/LevelSelectionUIController.h"
#include "UI/MainMenu/MainMenuUIController.h"
#include "Main/GameService.h"
#include "Graphics/GraphicService.h"
#include "Sound/SoundService.h"
#include "Event/EventService.h"
#include "Global/Config.h"
#include "Global/ServiceLocator.h"
#include "Level/LevelData.h"


namespace UI
{
	namespace LevelSelection
	{

		using namespace Global;
		using namespace Main;
		using namespace UIElement;
		using namespace Sound;



		LevelSelectionUIController::LevelSelectionUIController()
		{
			CreateImage();
			CreateButtons();
		}

		void LevelSelectionUIController::CreateImage()
		{
			backgroundImage = new ImageView();
		}

		void LevelSelectionUIController::CreateButtons()
		{
			levelOneButton = new ButtonView();
			levelTwoButton = new ButtonView();
			MenuButton = new ButtonView();
		}

		LevelSelectionUIController::~LevelSelectionUIController()
		{
			delete levelOneButton;
			delete levelTwoButton;
			delete MenuButton;
			delete backgroundImage;
		}

		void LevelSelectionUIController::initialize()
		{
			InitializeBackgroundImage();
			InitializeButtons();
			RegisterButtonCallback();
		}

		void LevelSelectionUIController::InitializeBackgroundImage()
		{
			sf::RenderWindow* gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

			backgroundImage->initialize(Config::background_texture_path, gameWindow->getSize().x,
				gameWindow->getSize().y, sf::Vector2f(0, 0));

			backgroundImage->setImageAlpha(backgroundAlpha);
		}

		void LevelSelectionUIController::InitializeButtons()
		{
			levelOneButton->initialize("level one", Config::level_one_button_texture_path,
				buttonWidth, buttonHeight, sf::Vector2f(0, levelOneYPosition));
			levelTwoButton->initialize("Level Two", Config::level_two_button_texture_path,
				buttonWidth, buttonHeight, sf::Vector2f(50, levelTwoYPosition));
			MenuButton->initialize("level Two", Config::menu_button_texture_path,
				buttonWidth, buttonHeight, sf::Vector2f(0, MenuYPosition));

			levelOneButton->setCentreAlinged();
			levelTwoButton->setCentreAlinged();
			MenuButton->setCentreAlinged();
		}

		void LevelSelectionUIController::RegisterButtonCallback()
		{
			levelOneButton->registerCallbackFuntion(std::bind(&LevelSelectionUIController::LevelOneButtonCallback, this));
			levelTwoButton->registerCallbackFuntion(std::bind(&LevelSelectionUIController::LevelTwoButtonCallback, this));

			MenuButton->registerCallbackFuntion(std::bind(&LevelSelectionUIController::MenuButtonCallback, this));
		}

		void LevelSelectionUIController::LevelOneButtonCallback()
		{
			GameService::setGameState(GameState::LINKED_LIST_SELECTION);
			ServiceLocator::getInstance()->GetlevelService()->CreateLevel(Level::LevelNumber::ONE);
			ServiceLocator::getInstance()->GetlevelService()->SetCurrentLevelNumber(Level::LevelNumber::ONE);
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			

		}

		void LevelSelectionUIController::LevelTwoButtonCallback()
		{
			GameService::setGameState(GameState::LINKED_LIST_SELECTION);
			ServiceLocator::getInstance()->GetlevelService()->CreateLevel(Level::LevelNumber::TWO);
			ServiceLocator::getInstance()->GetlevelService()->SetCurrentLevelNumber(Level::LevelNumber::TWO);
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);

		}

		void LevelSelectionUIController::MenuButtonCallback()
		{
			GameService::setGameState(GameState::MAIN_MENU);
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);


		}

		void LevelSelectionUIController::update()
		{
			backgroundImage->update();
			levelOneButton->update();
			levelTwoButton->update();
			MenuButton->update();
		}
		void LevelSelectionUIController::render()
		{
			backgroundImage->render();
			levelOneButton->render();
			levelTwoButton->render();
			MenuButton->render();
		}
		void LevelSelectionUIController::show()
		{
			backgroundImage->show();
			levelOneButton->show();
			levelTwoButton->show();
			MenuButton->show();
		}

	}
}