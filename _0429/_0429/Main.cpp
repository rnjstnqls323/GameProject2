#include "Framework.h"
#include "GameManager.h"



int main() {
	/*vector<Monster> monster;
	monster.push_back(LoadDatas("monster"));*/
	cout << "RPG게임 시작!" << endl;
	GameManager& gameManager = GameManager::GetInstance();
	gameManager.GamePlay();
}