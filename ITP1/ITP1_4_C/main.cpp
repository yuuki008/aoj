#include <iostream>

using namespace std;

int main() {
  while (true) {
    int a, b;
    char op;

    cin >> a >> op >> b;

    if(op == '+') {
      cout << a + b << endl;
    } else if (op == '-') {
      cout << a - b << endl;
    } else if (op == '*') {
      cout << a * b << endl;
    } else if (op == '/') {
      cout << a / b << endl;
    } else {
      break;
    }
  }

  return 0;
}
