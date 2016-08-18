#include <iostream>

using namespace std;

int sum(int a, int b) {
    return a + b;
}

int main() {
    int (*pf)(int, int); // 定义函数指针
    pf = sum; // pf 指向 sum 函数
    cout << pf(3, 2) << endl;
    return 0;
}
