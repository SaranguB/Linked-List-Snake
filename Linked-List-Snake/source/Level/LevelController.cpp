#include "../../Include/Level/LevelController.h"
#include "../../Include/Level/LevelModel.h"
#include "../../Include/Level/LevelView.h"

namespace Level
{
	using namespace Element;

	LevelController::LevelController()
	{
		levelModel = new LevelModel();
		levelView = new LevelView(this);
	}

	LevelController::~LevelController()
	{
		delete(levelModel);
		delete(levelView);
	}

	void LevelController::Initialize()
	{
		levelView->Initialize();
		levelModel->Initialize(levelView->GetGridWidth(), levelView->GetGridHeight());

	}

	void LevelController::Update()
	{
		levelView->Update();
	}

	void LevelController::Render()
	{
		levelView->Render();
	}
	float LevelController::GetCellWidth()
	{
		return levelModel->GetCellWidth();
	}

	float LevelController::GetCellHeight()
	{
		return levelModel->GetCellHeight();
	}
	const std::vector<ElementData>& LevelController::GetElementDataList(int levelToLoad)
	{
		return levelModel->GetElementDataList(levelToLoad);
	}
}
