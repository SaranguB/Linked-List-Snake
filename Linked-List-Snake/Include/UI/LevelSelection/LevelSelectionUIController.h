#pragma once
#include "UI/Interface/IUIController.h"
#include "UI/UIElement/ImageView.h"
#include "UI/UIElement/ButtonView.h"

namespace UI
{
	namespace LevelSelection
	{
		class LevelSelectionUIController : public Interface::IUIController
		{
		private:
			UIElement::ImageView* backgroundImage;

			UIElement::ButtonView* levelOneButton;
			UIElement::ButtonView* levelTwoButton;
			UIElement::ButtonView* MenuButton;

			const float buttonWidth = 400.f;
			const float buttonHeight = 140.f;

			const float backgroundAlpha = 85.f;

			const float levelOneYPosition = 500.f;
			const float levelTwoYPosition = 700.f;
			const float MenuYPosition = 900.f;

			void CreateImage();
			void CreateButtons();
			void InitializeBackgroundImage();
			void InitializeButtons();

			void RegisterButtonCallback();
			void SingleLinkedListButtonCallback();
			void DoubleLinkedListButtonCallback();
			void MenuButtonCallback();

		public:
			LevelSelectionUIController();
			~LevelSelectionUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
		};
	}
}
