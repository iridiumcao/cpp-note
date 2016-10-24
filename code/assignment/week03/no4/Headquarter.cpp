#include "Warrior.cpp"
#include <map>
#include <string>
#include <vector>

using namespace std;

// 司令部
class Headquarter {
  string type;
  int totalStrength;
  string warriorNameArray[];
  vector<Warrior> warriorList;
  // 各种武士对应的数量
  map<string, int> countWarriors;
  // 是否还能制造武士
  bool active;

public:
  Headquarter(string type, int totalStrength, string warriorNameArray[]);
  Warrior createWarrior(const string &type, int strength);
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
  this->warriorNameArray = warriorNameArray;

  for (int i = 0; i < 5; i++) {
    this->countWarriors->insert(pair<string, int>(warriorNameArray[i], 0));
  }

  this->active = true;
}

Headquarter::createWarrior(const string &type, int strength) {
  if (this->totalStrength > strength) {
    Warrior warrior(type, strength);

    this->warriorList->push(warrior);
    this->totalStrength -= strength;
    this->countWarriors->insert(
        pair<string, int>(type, this->countWarriors->find(type) + 1));
    return warrior;
  } else {
    return nullptr;
  }
}

string Headquarter::getType() { return this->type; }

int Headquarter::getTotalStrength() { return this->life; }

map<string, int> Headquarter::getCountWarriors() { return this->countWarriors; }

bool Headquarter::isActive() { return this->active; }

void Headquarter::setActive(bool active) { this->active = active; }