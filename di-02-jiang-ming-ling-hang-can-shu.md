# 第02讲 命令行参数

> 这部分知识是关于 C++ 程序的交互功能的。  
> 视频地址：[https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/nTsWR/ming-ling-xing-can-shu](https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/nTsWR/ming-ling-xing-can-shu)

在字符界面的 shell 中执行命令时，命令行中的所有字串，称为「命令行参数」。命令行参数可以有多个，以空格分隔。

例如 Windows CMD Shell 中

```text
> copy file1.txt file2.txt
```

上面这行命令中，_copy_, _file1.txt_, 和 _file2.txt_ 都是命令行参数。

再举一个 Linux Bash Shell 中的例子

```bash
$ cp file1 file2
```

以上，_cp_, _file1_, 和 _file2_ 都是命令行参数。

## 如何在程序中获取命令行参数？

C 的 main 函数完整格式是

```c
/*
 * argc 程序启动时，命令行参数的个数。C/C++ 规定，可执行程序本身的文件名，也算一个命令行参数，
 *      故 argc 的值至少为1.
 * argv 指针数组，其中的每个元素都是一个 char* 类型的指针，该指针指向一个字符串，这个字符串里
 *      存放中命令行参数。如 argv[0] 指向第一个命令行参数，即可执行程序的文件名，argv[2]指向
 *      第二个命令行参数，argv[2]指向第三个。
 *      这个参数的类型是 char**.
 */
int main(int argc, char * argv[]) {
    ... ...
}
```

下面是一段可执行的代码

```cpp
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        cout << argv[i] << ", ";
    }

    return 0;
}
```

\([代码下载](https://github.com/iridiumcao/cpp-note/tree/880e117845a17eb6c60956118ca4255ee37bb412/code/ch02/ch02.cpp)\)

编译执行，可以有如下输入输出：

```bash
$ g++ ch02.cpp -o hello
$ ./hello a b c "d e" f 100
./hello, a, b, c, d e, f, 100,
```

最后一行是输出，其中也可以看到如果某参数本身含有空格，如 _d e_，可以通过双引号括起来。

