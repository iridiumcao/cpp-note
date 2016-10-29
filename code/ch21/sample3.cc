// 赋值运算符重载

#include <string.h>
#include <iostream>

using namespace std;

class String {
 private:
  char *str;

 public:
  String() : str(NULL) {}
  String(String &);  // 为了程序的健壮，还需要重新复制构造函数。
  const char *c_str() { return str; }
  char *operator=(const char *s);
  ~String();
};

String::String(String &s) {
  if (s.str) {
    str = new char[strlen(s.str) + 1];
    strcpy(str, s.str);
  } else {
    str = NULL;
  }
}

char *String::operator=(const char *s) {
  if (str == s) {
    return str;
  }
  if (str) {
    delete[] str;
  }
  if (s) {
    str = new char[strlen(s) + 1];
    strcpy(str, s);
  } else {
    str = NULL;
  }

  return str;
}

String::~String() {
  if (str) {
    delete[] str;
  }
}

int main() {
  String s;
  s = "Good luck";  // 相当于 s.operator=("Good luck")
  cout << s.c_str() << endl;
  // String s2 = "hello"; // ERROR!
  // 这是一个初始化语句，要调用相关的构造器，但是没有，所以报错了。
  s = "ABC";
  cout << s.c_str() << endl;
  return 0;
}
