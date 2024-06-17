#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

int minimumCost(vector<int>& weights) {
  int numItems = weights.size();
  vector<int> sorted(weights);
  sort(sorted.begin(), sorted.end());

  vector<int> finalPosition(numItems);
  for (int i = 0; i < numItems; i++) {
    finalPosition[sorted[i]] = i;
  }

  vector<bool> visited(numItems, false);
  int total = 0;
  for (int i = 0; i < numItems; i++) {
    if (visited[i]) continue;

    int currentIndex = i;
    int sum = 0;
    int minW = INT_MAX;
    int length = 0;

    while (true) {
      visited[currentIndex] = true;
      length++;
      int current = weights[currentIndex];
      minW = min(minW, current);
      sum += current;
      currentIndex = finalPosition[current];
      if (visited[currentIndex]) break;
    }

    total += min(sum + (length - 2) * minW,
                 minW + sum + (length + 1) * sorted[0]);
  }

  return total;
}

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  int ans = minimumCost(A);
  cout << ans << endl;
  return 0;
}
