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
  int n = 4;
  vector<vector<int>> A = {{1, 2, 2, 4}, {2, 1, 4}, {3, 0}, {4, 1, 3}};
  vector<vector<int>> matrix(n, vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    int u = A[i][0];

    int k = A[i][1];

    for (int j = 2; j < 2 + k; j++) {
      int node = A[i][j];
      matrix[u - 1][node - 1] = 1;
    }
  };

  for (int i = 0; i < n; i++) {
    cout << i + 1 << ": ";
    for (int j = 0; j < n; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
