# 第09讲 面向对象程序设计方法

> C++ 是一门面向对象\(Object Oriented\)的语言。  
> 视频地址：[https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/Av9Da/mian-xiang-dui-xiang-cheng-xu-she-ji-fang-fa](https://www.coursera.org/learn/cpp-chengxu-sheji/lecture/Av9Da/mian-xiang-dui-xiang-cheng-xu-she-ji-fang-fa)

在 C++ 之前的 C 语言，是**面向过程**的语言，没有**对象**的概念，写程序时，需要直接将问题的整个流程用代码写出来，一环套一环，环环紧密结合（耦合）。用面向过程的语言肯定也能解决问题的，但有一些缺点：

* 程序分解难
* 不易维护（理解现有的代码难度较高，修改现有代码难度更高）  

  于是乎，面向对象的代码应运而生。

视频中老师提到的结构化程序相关内容，比如问题分解、自顶向下的设计方法等等，我并不认为这是什么设计方法特有的，同时，也不认为它们有什么问题，这些无论是什么设计方法，都会用到的一些比较普遍的实践方法。

面向对象的设计方法，主要得益于程序语言对**类型\(class\)**的支持。具体在设计程序时，一般有下面一些步骤： 1. 分析问题（不管什么设计方法，这步都是必须的） 2. 抽象实体，建立类。类中包含抽象的实体属性和行为 3. 通过类建立不同的实体对象，并对类/对象之间业务逻辑编码。

C++ 中定义类型的一个简单示例：

```cpp
#include <iostream>
#include <string>

using namespace std;

class Person {
private:
  string name;
  int age;

public:
  Person(string, int);
  void hello(Person person);
  string getName() { return name; };
  void setName(string name) { this->name = name; }
  int getAge() { return age; };
  void setAge(int age) { this->age = age; }
};

Person::Person(string name, int age) {
  this->name = name;
  this->age = age;
}

void Person::hello(Person person) {
  cout << "Hello, " << person.getName() << "!" << endl;
}

int main() {
  Person p("Chen", 5);
  p.hello(p);
  cout << "(He is " << p.getAge() << " years old.)" << endl;
  delete &p;
  return 0;
}
```

\([代码下载](https://github.com/iridiumcao/cpp-note/tree/880e117845a17eb6c60956118ca4255ee37bb412/code/ch09/Person.cc)\)

它和 Java 类似，但也有不同，相应的 Java 版本可以这么写：

```java
public class Person {
    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    void hello(Person p) {
        System.out.println("Hello, " + p.getName() + "!");
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public static void main(String[] args) {
        Person p = new Person("Chen", 5);
        p.hello(p);
        System.out.println("(He is " + p.getAge() + " years old.)");
    }
}
```

\([代码下载](https://github.com/iridiumcao/cpp-note/tree/880e117845a17eb6c60956118ca4255ee37bb412/code/ch09/Person.java)\)

以上两段代码是等效的，其中可以简单看出一些语法层面的不同，如

* `this`关键字的用法。C++ 中称为`this`指针，用`->`访问成员，而 Java 中称为`this`引用，使用圆点`.`访问成员。`this`指向当前对象。
* 函数定义的方式。C++ 可以分成两部分，在类定义中声明，在类外部具体定义，也可以在声明时定义；而 Java 只有一种写法，就是声明时直接定义。
* 创建对象的方式，这个比较有意思，C++ 中不需`new`关键字，但 Java 需要。
* 对象使用后，C++ 需要显式归还内存，而 Java 不需要。
* 通过观察`main`函数定义的位置，可见 C++ 可以定义不属于任何对象的函数\(全局函数\)，可见 C++ 面向对象不如 Java 纯粹。

---

[\<Previous](ch-08-default-parameter.md) \| [Home](SUMMARY.md) \| [Next\>](ch-10-oo-history.md)