#include <iostream>
#include <vector>
using namespace std;

/* INPUT */
/* 10 9 */
/* 0 1 */
/* 0 2 */
/* 3 4 */
/* 5 7 */
/* 5 6 */
/* 6 7 */
/* 6 8 */
/* 7 8 */
/* 8 9 */
/* 3 */
/* 0 1 */
/* 5 9 */
/* 1 3 */

/* GOAL */
/* yes */
/* yes */
/* no */

bool dfs(int s, int t, vector<vector<int>> A, vector<bool> visited) {
  if (s == t) return true;
  if (visited[s]) return false;

  visited[s] = true;

  for (int i = 0; i < A[s].size(); i++) {
    bool found = dfs(A[s][i], t, A, visited);
    if (found) return true;
  }

  return false;
}

int main () {
  int n;
  cin >> n;
  int m;
  cin >> m;
  vector<vector<int>> A(n);
  for (int i = 0; i < m; i++) {
    int s, t;
    cin >> s >> t;

    A[s].push_back(t);
    A[t].push_back(s);
  }
  int q;
  cin >> q;

  for (int i=0; i<q; i++) {
    int s, t;
    cin >> s >> t;
    vector<bool> visited(n, false);

    bool found = dfs(s, t, A, visited);
    if (found) cout << "yes" << endl;
    else cout << "no" << endl;
  }

  return 0;
}
