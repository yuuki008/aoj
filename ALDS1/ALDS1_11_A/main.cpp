#include <iostream>
#include <vector>
using namespace std;

// GOAL: matrix
//     1, 2, 3, 4
// 1: [0, 1, 0, 1]
// 2: [0, 0, 0, 1]
// 3: [0, 0, 0, 0]
// 4: [0, 0, 1, 0]

int main() {
  int n;
  cin >> n;

  vector<vector<int>> matrix(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;

    for (int j = 0; j < k; j++) {
      int edge;
      cin >> edge;
      matrix[u - 1][edge - 1] = 1;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << matrix[i][j];
      if (j != n - 1)
        cout << " ";
    }
    cout << endl;
  }
  return 0;
}
