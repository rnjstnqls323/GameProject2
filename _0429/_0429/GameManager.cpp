#include "Framework.h"
#include "GameManager.h"


Hero* GameManager::ChoiceJobs()
{
	cout << "******************************" << endl;
	cout << "*           직업 선택         *" << endl;
	cout << "*          1. 전사            *" << endl;
	cout << "*          2. 마법사          *" << endl;
	cout << "*          3. 궁수            *" << endl;
	cout << "******************************" << endl;
	int num;
	Hero* player = nullptr;
	cout << endl << "직업 선택 : ";
	cin >> num;
	if (num == 1) 
	{
		player = new Warrior(LoadDatas("전사", "player"));
		cout << "당신의 직업은 전사입니다. 행운을 빕니다." << endl;
		return player;
	}
	else 
	{
		cout << "다시 골라주세요." << endl;
		cin >> num;
	}
}
