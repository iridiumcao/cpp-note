#include <iostream>

using namespace std;

void hello(string firstName, string lastName = "", string middleName = "") {
  cout << "Hello, " << firstName << " " << middleName << " " << lastName
       << ";-)" << endl;
}

int main() {
  hello("Yi", "Cao", "Zong");
  hello("Yi", "Cao");
  hello("Yi");
//   hello("Yi", , "Zong"); // compile ERROR!
  return 0;
}