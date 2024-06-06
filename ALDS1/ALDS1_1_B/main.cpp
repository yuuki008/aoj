#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int cmd(int x, int y) {
  if (x < y) {
    return cmd(y, x);
  }

  if (x % y == 0) {
    return y;
  }

  return cmd(y, x % y);
}

int main() {
  int x, y;
  cin >> x >> y;

  cout << cmd(x, y) << endl;
  return 0;
}
