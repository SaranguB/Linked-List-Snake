#include "Global/ServiceLocator.h"
#include "../../Include/Main/GameService.h"

namespace Global
{
	using namespace Main;
	using namespace Graphics;
	using namespace Event;
	using namespace Sound;
	using namespace UI;
	using namespace Time;
	using namespace Level;
	using namespace Player;
	using namespace Element;

	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr;
		event_service = nullptr;
		sound_service = nullptr;
		ui_service = nullptr;
		time_service = nullptr;
		levelService = nullptr;
		playerService = nullptr;
		elementService = nullptr;

		createServices();
	}

	ServiceLocator::~ServiceLocator() { clearAllServices(); }

	void ServiceLocator::createServices()
	{
		event_service = new EventService();
		graphic_service = new GraphicService();
		sound_service = new SoundService();
		ui_service = new UIService();
		time_service = new TimeService();
		levelService = new LevelService();
		playerService = new PlayerService();
		elementService = new ElementService();
	}

	void ServiceLocator::initialize()
	{
		graphic_service->initialize();
		sound_service->initialize();
		event_service->initialize();
		ui_service->initialize();
		time_service->initialize();
		levelService->Initialize();
		playerService->Initialize();
		elementService->Initialize();
	}

	void ServiceLocator::update()
	{
		graphic_service->update();
		event_service->update();
		time_service->update();
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			levelService->Update();
			elementService->Update();
			playerService->Update();

		}
		ui_service->update();

	}

	void ServiceLocator::render()
	{
		graphic_service->render();

		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			levelService->Render();
			elementService->Render();
			playerService->Render();
		}
		ui_service->render();

	}

	void ServiceLocator::clearAllServices()
	{
		delete(ui_service);
		delete(graphic_service);
		delete(sound_service);
		delete(event_service);
		delete(time_service);
		delete(levelService);
		delete(playerService);
		delete(elementService);
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	EventService* ServiceLocator::getEventService() { return event_service; }

	GraphicService* ServiceLocator::getGraphicService() { return graphic_service; }

	SoundService* ServiceLocator::getSoundService() { return sound_service; }

	UIService* ServiceLocator::getUIService() { return ui_service; }

	Time::TimeService* ServiceLocator::getTimeService() { return time_service; }

	Level::LevelService* ServiceLocator::GetlevelService()
	{
		return levelService;
	}

	Player::PlayerService* ServiceLocator::GetPlayerService()
	{
		return playerService;
	}

	Element::ElementService* ServiceLocator::GetElementService()
	{
		return elementService;
	}

	void ServiceLocator::deleteServiceLocator() { delete(this); }
}