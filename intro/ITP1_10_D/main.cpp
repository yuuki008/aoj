#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

double minkowski(vector<double> x, vector<double> y, int p) {
  double sum = 0;
  for (int i = 0; i < x.size(); i++) {
    sum += pow(abs(x[i] - y[i]), p);
  }
  return pow(sum, 1.0 / p);
}

double chebyshev(vector<double> x, vector<double> y) {
  double max = 0;
  for (int i = 0; i < x.size(); i++) {
    double diff = abs(x[i] - y[i]);
    if (diff > max) {
      max = diff;
    }
  }
  return max;
}



int main() {
  int n;
  cin >> n;

  vector<double> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> y[i];
  }

  double minkowski_1 = minkowski(x, y, 1);
  double minkowski_2 = minkowski(x, y, 2);
  double minkowski_3 = minkowski(x, y, 3);
  double chebyshev_distance = chebyshev(x, y);

  cout << fixed << setprecision(6) << minkowski_1 << endl;
  cout << fixed << setprecision(6) << minkowski_2 << endl;
  cout << fixed << setprecision(6) << minkowski_3 << endl;
  cout << fixed << setprecision(6) << chebyshev_distance << endl;

  return 0;
}
