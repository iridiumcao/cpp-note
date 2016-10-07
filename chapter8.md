#第08讲 函数缺省参数

> 相对于 Java，这是 C++ 特有的功能，对程序的扩充性有一定好处，是 C++ 灵活性的一个体现。  
> 视频地址：[https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/r9ucP/han-shu-que-sheng-can-shu](https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/r9ucP/han-shu-que-sheng-can-shu)

一个函数在定义时，可以设置参数的缺省值。调用函数时，可以通过省写参数值调用这些缺省值。  
例如：
``` C++
void hello(string firstName, string lastName = "", string middleName = "");
```

调用时可以这样：
``` C++
hello("Yi", "Cao", "Zong");
hello("Yi", "Cao");
hello("Yi");
```
以上，可以省略最有边的一个或多个参数。但不可以**只**省略当中的参数，如：
``` C++
hello("Yi",,"Zong");
```

([代码下载](code/ch08/ch08.cc))