#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
  double a, b, C;
  cin >> a >> b >> C;

  double S, L, h;

  S = 0.5 * a * b * sin(C * M_PI / 180);
  L = a + b + sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(C * M_PI / 180));
  h = b * sin(C * M_PI / 180);

  cout << fixed << setprecision(8) << S << endl;
  cout << fixed << setprecision(8) << L << endl;
  cout << fixed << setprecision(8) << h << endl;
  return 0;
}
