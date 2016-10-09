class Hello {
private:
  int x, y;

public:
  void init(int x = 0, int y = 0);

  // 如果要使用缺省参数就会和下一个方法混淆
  void valueX(int val = 0) { x = val; }

  int valueX() { return x; }
};