// 编译步骤：
// 将 Humman.cpp 和 main.cpp 放在同一个目录，
// 对 main.cpp 执行编译命令即可：
// g++ main.cpp -o ch11
#include "Human.cpp"
#include <iostream>

int main() {
  using std::cout;
  using std::endl;

  Human maomao("Miaomiao", 55.0, 1.68);
  cout << maomao.getName() << "'s BMI is " << maomao.calcBMI() << endl;

  // 以下开始吃饭睡觉打猫猫了
  maomao.eat();
  maomao.sleep();
  maomao.daCat();
  return 0;
}