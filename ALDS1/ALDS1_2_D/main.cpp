#include<iostream>
#include<vector>
using namespace std;

long long cnt;

void insertion_sort(int seq[], int n, int g) {
  int i, j, v;
  for (i = g; i < n; i++) {
    v = seq[i];
    j = i - g;
    while (j >= 0 && seq[j] > v) {
      seq[j+g] = seq[j];
      j -= g;
      cnt++;
    }
    seq[j+g] = v;
  }
}

void shell_sort(int seq[], vector<int> G, int n, int m) {
  int i, g;
  
  for (i = m-1; i >= 0; i--) {
    g = G[i];
    insertion_sort(seq, n, g);
  }    
}

int main() {
  int i, n, m, g;
  int seq[1000000];
  vector<int> G;
  
  cin >> n;
  for (i = 0; i < n; i++) cin >> seq[i];
  
  g = 1;
  while (g <= n) {
    G.push_back(g);
    g = 3 * g + 1;
  }
  m = G.size();

  shell_sort(seq, G, n, m);

  cout << m << endl;
  for (i = m-1; i >= 0; i--) {
    if (i < m - 1) cout << " ";
    cout << G[i];
  }
  cout << endl;
  cout << cnt << endl;
  for (i = 0; i < n; i++) cout << seq[i] << endl;
  
  return 0;
}