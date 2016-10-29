# 第21讲 运算符重载

> 因为惯用 Java，个人很不习惯 C++ 这个特性，且认为运算符重载引入的复杂性远远比带来的方便多，这是一个不必要的特性。学习它，只是为了读懂别人的代码，恐怕自己是不会主动使用它的。  
> 视频地址：
> * 运算符重载的基本概念：<https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/bWQ2h/yun-suan-fu-zhong-zai-de-ji-ben-gai-nian>
> * 赋值运算符的重载：<https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/fLzUY/fu-zhi-yun-suan-fu-de-zhong-zai>
> * 运算符重载为友元函数：<https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/Oukpq/yun-suan-fu-zhong-zai-wei-you-yuan-han-shu>

## 1. 运算符重载的基本概念

运算符连接的表达式，完全可以视同函数的另外一种写法而已，本质上就是函数。类似牛顿和莱布尼兹各自发明了不同的符号系统表达微积分。  
运算符重载，会对运算符号赋予新的定义，理解上和函数重载是类似的。运算符重载的本质即函数重载。运算符可以被重载为普通函数或成员函数。  
它的定义格式如下：

``` C++
返回值类型 operator 运算符(形参表) {
    ...
}
```

### 1.1 重载为普通函数的例子

``` C++
class Complex {
 public:
  double real;
  double imaginary;

  Complex(double real = 0.0, double imaginary = 0.0) {
    this->real = real;
    this->imaginary = imaginary;
  }
};

Complex operator+(const Complex &a, const Complex &b) {
  return Complex(a.real + b.real, a.imaginary + b.imaginary);
}

int main() {
  Complex a(1, 2), b(2, 3), c;
  c = a + b;
  return 0;
}
```

([代码下载](code/ch21/sample1.cc), 为了代码规范，源代码将 ``real`` 和 ``imaginary`` 属性声明为 ``private``，并使用友元重载方式)

### 1.2 重载为成员函数的例子

运算的目数比前面重载为普通函数时少一个。

`` a + b `` 相当于调用 ``a.operator+(b)``，具体参下例：

``` C++
class Complex {
  double real;
  double imaginary;

 public:
  Complex(double real = 0.0, double imaginary = 0.0) {
    this->real = real;
    this->imaginary = imaginary;
  }

  Complex operator-(const Complex &);  // 运算符目数只有一个
};

Complex Complex::operator-(const Complex &a) {
  return Complex(real - a.real, imaginary - a.imaginary);
}

int main() {
  Complex a(1, 2), b(3.4, 4.5), c, d;
  d = a - b;  // 相当于 c = a.operator-(b)
  return 0;
}
```

([代码下载](code/ch21/sample2.cc))

## 2. 赋值运算符"="的重载

如果想把不同类型的对象做赋值，比如把 ``double`` 型变量赋值给 ``Complex`` 对象，把 ``char *`` 型字符串赋值给字符串对象等等，就需要重载赋值运算符。
这个符号比较特殊，和前面的双目运算符不一样。赋值运算符**只能重载为成员函数**。
例子参 [sample3.cc](code/ch21/sample3.cc)  

> 个人实在是讨厌这个特性，不同类型之间的赋值，多写一个构造函数会死么？偏要用这种极不符合认知习惯的方式？！

### 2.1 深浅复制

对象的复制（copy，拷贝，or clone, 克隆）,可以通过赋值运算来完成。但默认的对象是复制，是逐个字节的复制，称为浅复制。
如两个相同类型的对象 ``a, b`` 对 ``a`` 赋值：``a = b``，如果 ``b`` 中包含指针，那么就会把指针复制给 ``a``, 
如果赋值后 ``b`` 对象销毁了，``b``中的指针指向的对象也销毁了。而此时 ``a`` 中还有那个指针，却指不到正确的值，成了所谓的**野指针**。
这时就需要重新定义赋值运算，即重载赋值运算符。  
运算符重载时，应尽量保留运算符原本的特性，所以返回值最好是引用类型。  
Java 中不会有野指针的问题。Java 中的深浅复制也是一个值得思考的好问题。(TODO)

## 3. 运算符重载为友元函数

前面讲到，运算符重载的几种情况：

* 重载为普通函数
* 重载为成员函数，其中赋值操作符只能重载为成员函数

如果运算符重载为普通函数，但又需要使用对象的私有变量时，就可以把重载函数声明为类的友元来实现。当然，不用友元，给类加几个 getter 也是可以的，像 Java 那样。  
参这个例子：
> 这个例子非常好地展示了重载的正确使用方式，但也显示重载真的很难用。

``` C++
class Complex {
  double real;
  double imaginary;

 public:
  Complex(double real = 0.0, double imaginary = 0.0) {
    this->real = real;
    this->imaginary = imaginary;
  }

  Complex operator+(double real);
  friend Complex operator+(double real,
                           const Complex &c);  // 因为要用到 Complex
                                               // 对象的私有成员，所以也作为
                                               // Complex 的友元

  void print();
};

Complex Complex::operator+(double real) {
  return Complex(this->real + real, imaginary);
}

// 重载为普通函数，以满足 double + Complex 的算式
Complex operator+(double real, const Complex &c) {
  return Complex(real + c.real, c.imaginary);
}

void Complex::print() { ... }

int main() {
  Complex a(1, 2), b, c;
  b = a + 5;  // 用到的成员函数
  b.print();
  c = 5 + a;  // 用到的普通函数，并是 Complex 的友元
  c.print();
  return 0;
}
```

([代码下载](code/ch21/sample4.cc))  
特别要注意 ``b = a + 5`` 和 `` c = 5 + a`` 调用的是不同的运算符重载函数。这里也显示运算符的重载不支持交换律，如果要重载``+``，就必须写两个重载函数，一个以成员函数出现，一个是全局函数但作为类的友元函数出现，这点让代码显得很丑陋。