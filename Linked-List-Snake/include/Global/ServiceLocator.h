#pragma once
#include "Graphics/GraphicService.h"
#include "Event/EventService.h"
#include "UI/UIService.h"
#include "Sound/SoundService.h"
#include "Time/TimeService.h"
#include "Level/LevelService.h"
#include "Player/PlayerService.h"
#include "Element/ElementService.h"
#include "Food/FoodService.h"

namespace Global
{
    class ServiceLocator
    {
    private:
        Event::EventService* event_service;
        Graphics::GraphicService* graphic_service;
        Sound::SoundService* sound_service;
        UI::UIService* ui_service;
        Time::TimeService* time_service;
        Level::LevelService* levelService;
        Player::PlayerService* playerService;
        Element::ElementService* elementService;
        Food::FoodService* foodService;

        ServiceLocator();
        ~ServiceLocator();

        void createServices();
        void clearAllServices();

    public:
        static ServiceLocator* getInstance();

        void initialize();
        void update();
        void render();

        Event::EventService* getEventService();
        Graphics::GraphicService* getGraphicService();
        Sound::SoundService* getSoundService();
        UI::UIService* getUIService();
        Time::TimeService* getTimeService();
        Level::LevelService* GetlevelService();
        Player::PlayerService* GetPlayerService();
        Element::ElementService* GetElementService();
        Food::FoodService* GetFoodService();

        void deleteServiceLocator();
    };
}