#include "Headquarter.cpp"
#include "Warrior.cpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
  int groups;
  cin >> groups;

  Warrior &warriorArray[] = new Warrior[]{
      new Warrior("dragon"), new Warrior("ninja"), new Warrior("iceman"),
      new Warrior("lion"), new Warrior("wolf")};

  for (int i = 0; i < groups; i++) {
    cout << "Case: " << (i + 1) << endl;
    int initLife;
    int life[] = {};
    cin >> initLife;
    for (int j = 0; j < 5; i++) {
      cin >> life[i];
      warriorArray[i]->setLife(life[i]);
    }
  }

  return 0;
}