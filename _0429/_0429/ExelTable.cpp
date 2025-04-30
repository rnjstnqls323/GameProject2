#include <fstream>
#include "ExelTable.h"

Datas LoadDatas(string name, string type)
{
	Datas monster = {};
	string path = "";
	if (type == "monster")
	{
		path = MONSTER_DATA_PATH;
	}
	else if (type == "player")
	{
		path = HERO_DATA_PATH;
	}
	
	ifstream file(path);

	if (!file.is_open()) {
		cout << "파일 오픈 실패" << endl;
		return monster;
	}
	string line;
	getline(file, line);
	while (getline(file, line)) {
		stringstream ss (line);
		string token;
		
		getline(ss, monster.name, ',');
		getline(ss, token, ',');
		monster.hp = stoi(token);
		
		getline(ss, token, ',');
		monster.attackPower = stoi(token);
		getline(ss, token, ',');
		monster.exp = stoi(token);
		getline(ss, token, ',');
		monster.coin = stoi(token);
		getline(ss, token, ',');
		monster.level = stoi(token);
		getline(ss, monster.skill, ',');
		getline(ss, token, ',');
		monster.skillDamage = stoi(token);
		getline(ss, token, ',');
		monster.mp = stoi(token);
		if (monster.name == name) 
		{
			return monster;
		}
	}
	file.close();
	return monster;
}

