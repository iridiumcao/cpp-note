#include "Warrior.cpp"
#include <map>
#include <string>
#include <vector>

using namespace std;

// 司令部
class Headquarter {
	string type;
	int totalStrength;
	string warriorNameArray[5] = { 0 };
	vector<Warrior> warriorList;
	// 各种武士对应的数量
	map<string, int> countWarriors;
	// 是否还能制造武士
	bool active;

public:
	Headquarter(string type, int totalStrength, string warriorNameArray[5]);
	bool createWarrior(const string &type, int strength, Warrior &warrior);
	string getType();
	int getTotalStrength();
	map<string, int> getCountWarriors();
	bool isActive();
	void setActive(bool active);
};

Headquarter::Headquarter(string type, int totalStrength,
		string warriorNameArray[]) {
	this->type = type;
	this->totalStrength = totalStrength;

	for (int i = 0; i < 5; i++) {
		this->warriorNameArray[i] = warriorNameArray[i];
		this->countWarriors.insert( { warriorNameArray[i], 0 });
	}
	this->active = true;
}

bool Headquarter::createWarrior(const string &type, int strength,
		Warrior &warrior) {
	if (this->totalStrength > strength) {
		Warrior warrior(type, strength);
		this->warriorList.push_back(warrior);
		this->totalStrength -= strength;
		this->countWarriors.insert(
				pair<string, int>(type,
						this->countWarriors.find(type)->second + 1));
		return true;
	} else {
		return false;
	}
}

string Headquarter::getType() {
	return this->type;
}

int Headquarter::getTotalStrength() {
	return this->totalStrength;
}

map<string, int> Headquarter::getCountWarriors() {
	return this->countWarriors;
}

bool Headquarter::isActive() {
	return this->active;
}

void Headquarter::setActive(bool active) {
	this->active = active;
}
