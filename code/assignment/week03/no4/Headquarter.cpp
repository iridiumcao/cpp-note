#include "Warrior.cpp"
#include <string>

using namespace std;

// 司令部
class Headquarter {
  string type;
  int life;
  Warrior warriorArray[];

public:
  Headquarter(string type, int life);
  string getType();
  int getLife();
  void minusLife(int m);
  Warrior *getWarriorArray();
  void setWarriorArray(Warrior *warriorArray);
};

Headquarter::Headquarter(string type, int life) {
  this->type = type;
  this->life = life;
}

string Headquarter::getType() { return this->type; }

int Headquarter::getLife() { return this->life; }

void Headquarter::minusLife(int m) { this->life -= m; }

Warrior *Headquarter::getWarriorArray() { return this->warriorArray; }

void Headquarter::setWarriorArray(Warrior *warriorArray) {
  this->warriorArray = warriorArray;
}
