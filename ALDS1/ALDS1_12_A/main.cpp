#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> P;


int prim(int n, vector<vector<P>> adj) {
  priority_queue<P, vector<P>, greater<P>> pq;

  vector<bool> inMst(n, false);
  int mst_weight = 0;

  pq.push({ 0, 0 });

  while (!pq.empty()) {
    int weight = pq.top().first;
    int u = pq.top().second;
    pq.pop();

    if (inMst[u]) continue;

    inMst[u] = true;
    mst_weight += weight;

    for (auto& edge : adj[u]) {
      int v = edge.second;
      int w = edge.first;
      if (!inMst[v]) {
        pq.push({ w, v });
      }
    }
  }

  return mst_weight;
};

int main () {
  int n;
  cin >> n;
  vector<vector<P>> adj(n);

  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      int weight;
      cin >> weight;
      if(weight == -1) continue;

      adj[i].push_back({ weight, j });
    }
  }

  int mst_weight = prim(n, adj);
  cout << mst_weight << endl;
  return 0;
}
