#pragma once
#include "Framework.h"
#include "Dungeon.h"

class GameManager
{
private:
	GameManager() {}

public:
	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;

	static GameManager& GetInstance() {
		static GameManager instance;
		return instance;
	}

	Character* ChoiceJobs();

    void GamePlay() 
    {
		Character* player = nullptr;
		GameState gameState = ChoiceJob;
		Dungeon dungeon;
		while (true) 
		{
			switch (gameState)
			{
			case ChoiceJob:
				cout << "현재 상태는 '직업 선택' 입니다." << endl;
				player = ChoiceJobs();
				gameState = VisitStore;
				break;
			case VisitStore:
				cout << "현재 상태는 '상점 방문' 입니다." << endl;
				gameState = ChoiceDungeon;
				break;
			case ChoiceDungeon:
				cout << "현재 상태는 '던전 선택' 입니다." << endl;
				gameState = dungeon.StartDungeon(static_cast<Hero*>(player));

				break;
			case Boss:

				break;
			default:
				break;
			}
		}
    }
};
