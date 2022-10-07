# 第06讲 动态内存分配

> C++ 的内存分配和回收需要程序员写代码完成，这点比 Java 要复杂些。  
> 视频地址：[https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/KzGkF/dong-tai-nei-cun-fen-pei](https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/KzGkF/dong-tai-nei-cun-fen-pei)

C++ 作为 C 的超集，既可以用 C 的 `malloc` 来分配内存，也可以用 C++ 特有的 `new`，一般使用后者更方便。

1. 分配一个对象的空间。例如：

   ```cpp
   int * hello;
   hello = new int; // 分配 sizeof(int) 大小的内存空间，并将地址赋值给 hello
   *hello = 5; // 给 hello 所指向的空间赋值为 5
   delete hello; // 用完之后归还内存
   delete hello; // ERROR! 不能删除已经删除的内存空间
   ```

   以上的赋值语句可以简写为

   ```cpp
   int * hello = new int;
   ```

2. 分配一个数组的空间。例如：

   ```cpp
   int * world;
   world = new int[5]; // 分配的空间大小为 5 * sizeof(int)，首地址赋值给 world
   world[0] = 3;
   world[50] = 333; // ERROR! 编译通过，但数组越界了
   delete [] world; // 归还内存
   delete [] world; // ERROR! 不能删除已经删除的内存空间
   ```

   以上的赋值语句可以简写为

   ```cpp
   int * world = new int[5];
   ```

\([代码下载](https://github.com/iridiumcao/cpp-note/tree/880e117845a17eb6c60956118ca4255ee37bb412/code/ch06/ch06.cpp)\)

---

[\<Previous](ch-05-const.md) \| [Home](SUMMARY.md) \| [Next\>](ch-07-function.md)