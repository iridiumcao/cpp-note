#include <stdio.h>
#include <stdlib.h>

#define NUM 5

/*
 *比较函数的编写规则：
 * 1. 如果要让 *elem1 排在 *elem2 之前，则返回值是负整数
 * 2. 如果 *elem1 和 *elem2 谁前谁後皆可，即两元素相等，则返回零
 * 3. 如果要让 *elem1 排在 *elem2 之後，则返回值是正整数
 */
int myCompare(const void * elem1, const void *elem2) {
    unsigned int *p1, *p2;
    p1 = (unsigned int *) elem1; //! 这里必须使用 cast 得到实际的类型
    p2 = (unsigned int *) elem2;
    return *p1 - *p2; //本例执行结果：4 8 10 11 123 
    //如果返回语句这样：
    //return (*p1 % 10) - (*p2 % 10);
    //那么程序执行的结果将是：10 11 123 4 8，程序的排序依据是各数对10的模，即个位数的大小。
}

int main() {
    unsigned int array[NUM] = {8, 123, 11, 10, 4};
    qsort(array, NUM, sizeof(unsigned int), myCompare);
    for(int i = 0; i < NUM; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}