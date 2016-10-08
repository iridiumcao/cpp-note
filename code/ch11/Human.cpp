#include <iostream>

using namespace std;

class Human {
private:
  string name;
  double weight;
  double height;

public:
  Human(string, double, double);
  string getName() { return this->name; };
  void eat();
  void sleep();
  void daCat();

  // calculate Body Mass Index
  double calcBMI();
}; // 这里分号是必须的

Human::Human(string name, double weight, double height) {
  this->name = name;
  this->weight = weight;
  this->height = height;
}

void Human::eat() { cout << "Eat an apple..." << endl; }

void Human::sleep() { cout << "Sleeping..." << endl; }

void Human::daCat() { cout << "打一下猫猫……嘿嘿" << endl; }

// BMI = weight / (height * height)
double Human::calcBMI() { return this->weight / (this->height * this->height); }
