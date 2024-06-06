#include <iostream>
#include <climits>

using namespace std;

int main() {
  int n;
  cin >> n;

  int min_val = INT_MAX;
  int max_val = INT_MIN;
  long long sum_val = 0;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;

    sum_val += a;

    if (a < min_val) {
      min_val = a;
    }
    if (a > max_val) {
      max_val = a;
    }
  }

  cout << min_val << " " << max_val << " " << sum_val << endl;

  return 0;
}
