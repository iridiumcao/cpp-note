#include <iostream>
#include <string>

using namespace std;

class Person {
private:
  string name;
  int age;

public:
  Person(string, int);
  void hello(Person person);
  string getName() { return name; };
  void setName(string name) { this->name = name; }
  int getAge() { return age; };
  void setAge(int age) { this->age = age; }
};

Person::Person(string name, int age) {
  this->name = name;
  this->age = age;
}

void Person::hello(Person person) {
  cout << "Hello, " << person.getName() << "!" << endl;
}

int main() {
  Person p("Chen", 5);
  p.hello(p);
  cout << "(He is " << p.getAge() << " years old.)" << endl;
  delete &p;
  return 0;
}
