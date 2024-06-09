#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <climits>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> w(n);
  for (int i = 0; i < n; i++) cin >> w[i];

  // 降順にソート
  sort(w.begin(), w.end(), greater<int>());

  vector<int> loadCount(k, 0);

  for(int i = 0; i < n; i++) {
    auto min = min_element(loadCount.begin(), loadCount.end());
    *min += w[i];
  }

  auto max = max_element(loadCount.begin(), loadCount.end());

  cout << *max << endl;

  return 0;
}
