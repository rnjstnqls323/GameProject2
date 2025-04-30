#include <fstream>
#include "ExelTable.h"

Datas LoadDatas(string name)
{
	Datas monster = {};
	ifstream file(MONSTER_DATA_PATH);
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
		monster.speed = stoi(token);
		
		getline(ss, token, ',');
		monster.attackPower = stoi(token);
		getline(ss, token, ',');
		monster.exp = stoi(token);
		getline(ss, token, ',');
		monster.coin = stoi(token);
		if (monster.name == name) 
		{
			return monster;
		}
	}
	file.close();
	return monster;
}

StrongDatas LoadStrongDatas(string name,string status)
{
	StrongDatas data = {};
	ifstream file;
	if (status == "hero")
		ifstream file(HERO_DATA_PATH);
	else
		ifstream file(BOSS_DATA_PATH);
	
	if (!file.is_open()) {
		cout << "파일 오픈 실패" << endl;
		return data;
	}
	string line;
	getline(file, line);
	while (getline(file, line)) {
		stringstream ss(line);
		string token;
		
		getline(ss, data.name, ',');

		getline(ss, token, ',');
		data.hp = stoi(token);
		getline(ss, token, ',');
		data.speed = stoi(token);
		getline(ss, token, ',');
		data.attackPower = stoi(token);
		getline(ss, token, ',');
		data.exp = stoi(token);
		getline(ss, token, ',');
		data.coin = stoi(token);
		getline(ss, token, ',');
		data.level = stoi(token);
		getline(ss, data.skill, ',');
		getline(ss, token, ',');
		data.damage = stoi(token);
		getline(ss, token, ',');
		data.mp = stoi(token);
		if (data.name == name)
		{
			return data;
		}
	}
	file.close();
	return data;
}

