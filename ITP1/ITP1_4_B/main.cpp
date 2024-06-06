#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  double x;
  cin >> x;

  double area = M_PI * x * x;
  double circumference = 2 * M_PI * x;

  cout << fixed << setprecision(5);
  cout << area << " " << circumference << endl;

  return 0;
}
