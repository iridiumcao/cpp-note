# 第22讲 实例——长度可变的整型数组类

> 本讲对应的视频讲座对问题的分析很好，完整再现了如何分析和实现整个程序的过程，不容错过。  
> 视频地址：<https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/BU0zX/shi-li-chang-du-ke-bian-de-zheng-xing-shu-zu-lei>

本例实现了一个 ``List`` 的数据结构的一部分基本的内容，非常有参考价值！来源于教材，重载了 ``=``, ``[]``, 和复制构造函数。
以下是完整代码，值得反复观摩、玩味。
``` C++
#include <cstring>
#include <iostream>
using namespace std;

class CArray {
  int size;  // 数组元素的个数
  int *ptr;  //指向动态分配的数组

 public:
  CArray(int size = 0);
  CArray(const CArray &a);
  ~CArray();
  void push_back(int v);  // append an element to the array tail
  int length() { return size; }
  CArray &operator=(const CArray &a);

  // the [] is an operator with TWO operands (双目运算符)
  // 返回值必须 int & 而非 int, 否则不支持 a[i] = 4,
  // 因为非引用的类型不支持作为左值使用
  int &operator[](int i) { return ptr[i]; }
};

CArray::CArray(int size) {
  this->size = size;
  if (size == 0) {
    this->ptr = NULL;
  } else {
    this->ptr = new int[size];
  }
}

// deep clone
CArray::CArray(const CArray &a) {
  if (!a.ptr) {
    ptr = NULL;
    size = 0;
    return;
  }

  ptr = new int[a.size];
  memcpy(ptr, a.ptr, sizeof(int) * a.size);
  size = a.size;
}

CArray::~CArray() {
  if (this->ptr) {
    delete[] this->ptr;
  }
}

// deep clone
CArray &CArray::operator=(const CArray &a) {
  if (ptr = a.ptr) {  // 为了可以对自身赋值，比如 a = a 这种
    return *this;
  }

  if (a.ptr == NULL) {
    if (ptr) {
      delete[] ptr;
    }
    ptr = NULL;
    size = 0;
    return *this;
  }

  if (size < a.size) {  // if the space is enough, it's not necessary to assign
                        // new space.
    if (ptr) {
      delete[] ptr;
    }
    ptr = new int[a.size];
  }
  memcpy(ptr, a.ptr, sizeof(int) * a.size);
  size = a.size;
  return *this;
}

void CArray::push_back(int v) {
  if (ptr) {
    int *tmpPtr = new int[size + 1];
    memcpy(tmpPtr, ptr, sizeof(int) * size);
    delete[] ptr;
    ptr = tmpPtr;
  } else {
    ptr = new int[1];
  }
  ptr[size++] = v;
}

int main() {
  CArray a;
  for (int i = 0; i < 5; ++i) {
    a.push_back(i);
  }

  CArray a2, a3;
  a2 = a;  // override =
  for (int i = 0; i < a.length(); ++i) {
    cout << a2[i] << " ";  // override []
  }

  a2 = a3;
  for (int i = 0; i < a2.length(); ++i) {
    cout << a2[i] << " ";
  }

  cout << endl;
  a[3] = 100;
  CArray a4(a);
  for (int i = 0; i < a4.length(); ++i) {
    cout << a4[i] << " ";
  }

  return 0;
}
```
([代码下载](code/ch22/sample_array.cc))， 输出：
```
0 1 2 3 4 
0 1 2 100 4
```