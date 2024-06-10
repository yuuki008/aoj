#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <climits>
using namespace std;

struct Point {
  double x, y;
};

double th = M_PI * 60.0 / 180.0;

void koch(int d, Point a, Point b) {
  if (d == 0) return;

  Point s, t, u;
  s.x = (2.0 * a.x + 1.0 * b.x) / 3.0;
  s.y = (2.0 * a.y + 1.0 * b.y) / 3.0;
  t.x = (1.0 * a.x + 2.0 * b.x) / 3.0;
  t.y = (1.0 * a.y + 2.0 * b.y) / 3.0;
  u.x = (t.x-s.x) * cos(th) - (t.y-s.y) * sin(th) + s.x;
  u.y = (t.x-s.x) * sin(th) + (t.y-s.y) * cos(th) + s.y;

  koch(d-1, a, s);
  printf("%.8f %.8f\n", s.x, s.y);
  koch(d-1, s, u);
  printf("%.8f %.8f\n", u.x, u.y);
  koch(d-1, u, t);
  printf("%.8f %.8f\n", t.x, t.y);
  koch(d-1, t, b);
}

int main() {
  int n;
  cin >> n;

  Point a, b;
  a.x = 0.0;
  a.y = 0.0;
  b.x = 100.0;
  b.y = 0.0;

  printf("%.8f %.8f\n", a.x, a.y);
  koch(n, a, b);
  printf("%.8f %.8f\n", b.x, b.y);

  return 0;
}
