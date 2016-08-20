#include <iostream>

using namespace std;

// 打印命令行参数
int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        cout << argv[i] << ", ";
    }

    return 0;
}