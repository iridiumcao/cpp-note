class String {
  char *p;

public:
  String() { p = new char[10]; }
  ~String();
};

String::~String() { delete[] p; }