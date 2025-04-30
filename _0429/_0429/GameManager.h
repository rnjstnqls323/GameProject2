#pragma once
#include "Framework.h"
#include "Dungeon.h"
#include "Store.h"
#include "Hero.h"


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

	Hero* ChoiceJobs();

    void GamePlay() 
    {
		Hero* player = nullptr;
		GameState gameState = ChoiceJob;
		Dungeon dungeon;
		Store store;
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
				
				gameState = store.VisitStore(player);
				break;
			case ChoiceDungeon:
				cout << "현재 상태는 '던전 선택' 입니다." << endl;
				gameState = dungeon.StartDungeon(static_cast<Hero*>(player));

				break;
			case GameOver:
				cout << "게임 오버" << endl;
				return;

			case GameClear:
				cout << "와우! 게임 클리어" << endl;
				return;

			}
		}
    }
};
