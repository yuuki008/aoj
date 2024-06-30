#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int dfs(int key, int time, vector<vector<int>> A, vector<int> &d,
        vector<int> &h) {
  if (h[key] != -1  || d[key] != -1) return time;

  time++;
  d[key] = time;

  for (int i = 0; i < A[key].size(); i++) {
    time = dfs(A[key][i], time, A, d, h);
  }

  time++;
  h[key] = time;

  return time;
}

int main() {
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
  vector<int> h(n, -1);

  int time = 0;
  for (int i=0; i<n; i++) {
    if (d[i] != -1) continue;

    time = dfs(i, time, A, d, h);
  }

  for (int i = 0; i < n; i++) {
    cout << i + 1 << " ";
    cout << d[i] << " ";
    cout << h[i] << endl;
  }
  return 0;
}
