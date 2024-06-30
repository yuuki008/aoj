#include <iostream>
#include <vector>

using namespace std;

void bfs(int key, vector<vector<int>>&A, vector<int>& d, int distance) {
  if (d[key] != -1 && distance > d[key]) return;

  d[key] = distance;

  for (int i=0; i<A[key].size(); i++) {
    bfs(A[key][i], A, d, distance+1);
  }
}

int main () {
  int n;
  cin >> n;

  vector<vector<int>> A(n);
  for(int i=0; i<n; i++) {
    int u, k;
    cin >> u >> k;

    for (int j=0; j<k; j++) {
      int v;
      cin >> v;
      A[u-1].push_back(v-1);
    }
  }

  vector<int> d(n, -1);

  bfs(0, A, d, 0);

  for(int i=0; i<n; i++) {
    cout << i+1 << " " << d[i] << endl;
  }
  return 0;
}
