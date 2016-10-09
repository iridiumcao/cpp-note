#include <iostream>

using namespace std;

class Human {
private:
  string name;

private:
  double weight;

private:
  double height;

public:
  Human(string, double, double);

public:
  string getName() { return this->name; };

public:
  void eat();

public:
  void sleep();

public:
  void daCat();

public:
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
