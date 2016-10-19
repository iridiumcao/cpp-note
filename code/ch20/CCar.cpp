class CCar {
public:
  int price;
  void setPrice(int p);
};

void CCar::setPrice(int p) { price = p; }

int main() {
  CCar car;
  car.setPrice(200000);
  return 0;
}