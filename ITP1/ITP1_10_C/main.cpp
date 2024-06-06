#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

double calcMean(const vector<double> v) {
  double sum = 0;

  for (int i = 0; i < v.size(); i++) {
    sum += v[i];
  }

  return sum / v.size();
}

int main() {
  int n;
  while (true) {
    cin >> n;
    if (n == 0) break;

    vector<double> S(n);
    for(int i = 0; i < n; i++) {
      double s;
      cin >> s;
      S[i] = s;
    }

    double mean = calcMean(S);
    double sumSquareDifferences = 0.0;

    for(int i = 0; i < n; i++) {
      double diff = S[i] - mean;
      sumSquareDifferences += diff * diff;
    }

    double variance = sumSquareDifferences / n;
    double standardDeviation = sqrt(variance);

    cout << fixed << setprecision(8) << standardDeviation << endl;
  }
  return 0;
}
