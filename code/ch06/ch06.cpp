#include <iostream>

using namespace std;

int main() {

  // 1. 分配一个对象的内存空间
  int *hello;
  hello = new int; // 分配 sizeof(int) 大小的内存空间，并将地址赋值给 hello
  *hello = 5; // 给 hello 所指向的空间赋值为 5
  cout << "hello: " << *hello << endl;
  delete hello; // 用完之后归还内存
  //   delete hello; // ERROR! 不能删除已经删除的内存空间

  // 2. 分配一个数组的内存空间
  int *world;
  world = new int[5]; // 分配的空间大小为 5 * sizeof(int)，首地址赋值给 world
  world[0] = 3;
  cout << "world[0]: " << world[0] << endl;
  //   world[50] = 333; // ERROR! 编译通过，但数组越界了
  delete[] world; // 归还内存
  //   delete[] world;  // ERROR! 不能删除已经删除的内存空间

  return 0;
}