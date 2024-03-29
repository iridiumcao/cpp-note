#include <iostream>

using namespace std;

int sum(int a, int b) {
    return a + b;
}

int minus2(int a, int b) {
    return a - b;
}

int main() {
    int (*pf)(int, int); // 定义函数指针
    pf = sum; // pf 指向 sum 函数
    // 以上两句也可以一行完成：定义+赋值，如下
    // int (*pf)(int, int) = sum;

    cout << pf(3, 2) << endl; // 5

    pf = minus2; // pf 指向 minus 函数
    cout << pf(3, 2) << endl; // 1
    return 0;
}
