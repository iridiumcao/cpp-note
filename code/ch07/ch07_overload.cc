#include <iostream>

using namespace std;

int main() {
  int iMax = max(3, 4); // invoke function a
  cout << "function a: " << iMax << endl;
  double dMax = max(2.5, 3.2); // invoke function b
  cout << "function b: " << dMax << endl;
  //   max(2, 3.4);   // compile ERROR!
  return 0;
}

// function a
int max(int x, int y) {
  if (x > y) {
    return x;
  } else {
    return y;
  }
}

// function b
double max(double x, double y) {
  if (x > y) {
    return x;
  } else {
    return y;
  }
}