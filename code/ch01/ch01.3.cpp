#include <iostream>
#include<algorithm>

using namespace std;

const unsigned int NUM = 5;

// 这里定义 a 在 b 前的条件，比较小的排在前面
// 所以这里定义的是从小到大的排列顺序
bool compare(int a, int b) {
    return a < b;
}

int main() {
    unsigned int array[NUM] = {8, 123, 11, 10, 4};
    sort(array, array + NUM, compare);
    for(int i = 0; i < NUM; i++) {
        cout << array[i] << " "; //本例执行结果：4 8 10 11 123 
    }

    return 0;
}