struct CCar {
  int price;
};

void setPrice(struct CCar *this, int p) { this->price = p; }

int main() {
  struct CCar car;
  setPrice(&car, 200000);
  return 0;
}