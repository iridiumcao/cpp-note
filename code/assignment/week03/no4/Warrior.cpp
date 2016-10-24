#include <string>

using namespace std;

class Warrior {
  // 武士类型
  string type;
  // 武士的初始生命值，其实就是「力量」
  int strength;

public:
  Warrior(string type, int strength);
  string getType();
  int getStrength();
};

Warrior::Warrior(string type, int strength) {
  this->type = type;
  this->strength = strength;
}

string Warrior::getType() { return this->type; }

int Warrior::getStrength() { return this->strength; }