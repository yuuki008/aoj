#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define DUMMY -1

int H;

int left(int node) { return 2 * node; }

int right(int node) { return 2 * node + 1; }

void print(vector<int> &A, int n) {
  for (int i = 1; i <= n; i++) {
    if (i > 1)
      cout << " ";
    cout << A[i];
  }
  cout << endl;
}

void arrange(vector<int> &A) {
  int i;
  int b = 0;
  int node = 1;
  int nextnode;

  for (i = H; i > 1; i /= 2) {
    b++;
  }
  while (b > 0) {
    if (H & (1 << b - 1)) {
      nextnode = right(node);
    } else {
      nextnode = left(node);
    }
    swap(A[node], A[nextnode]);
    node = nextnode;
    b--;
  }
}

int main() {
  int i, n;
  cin >> H;
  n = H;
  vector<int> V(n);
  for (i = 0; i < n; i++) {
    cin >> V[i];
  }

  /* 1. ソート */
  sort(V.begin(), V.end());

  vector<int> ORDER(H + 1);
  for (i = 1; i <= H; i++) {
    ORDER[i] = i;
  }
  while (H > 1) {
    swap(ORDER[1], ORDER[H--]);
    arrange(ORDER);
  }

  vector<int> RES(n + 1);
  for (i = 1; i <= n; i++) {
    RES[ORDER[i]] = V[i - 1];
  }
  print(RES, n);

  return 0;
}
