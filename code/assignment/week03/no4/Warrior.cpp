#include <string>

using namespace std;

class Warrior {
  string type;
  int life;
  int strength;

public:
  Warrior(string type, int life = 0, int strength = 0);
  string getType();
  int getLife();
  void setLife(int life);
  int getStrength();
};

Warrior::Warrior(string type, int life, int strength) {
  this->type = type;
  this->life = life;
  this->strength = strength;
}

string Warrior::getType() { return this->type; }

int Warrior::getLife() { return this->life; }

void Warrior::setLife(int life) { this->life = life; }

int Warrior::getStrength() { return this->strength; }