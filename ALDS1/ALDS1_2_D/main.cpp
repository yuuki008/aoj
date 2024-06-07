#include<iostream>
#include<vector>
using namespace std;

int cnt = 0;

void insertionSort(int A[], int n, int g) {
  for(int i=g; i<n; i++) {
    int v = A[i];
    int j = i - g;
    while (j >= 0 && A[j] > v) {
      cnt++;
      A[j+g] = A[j];
      j -= g;
    }

    A[j+g] = v;
  }
}

void shellSort(int A[], vector<int> G, int n) {
  for(int i=G.size()-1; i>=0; i--) {
    insertionSort(A, n, G[i]);
  }
}

int main() {
  int n;
  cin >> n;
  
  int A[1000000];
  for(int i=0; i<n; i++) {
    cin >> A[i];
  }

  vector<int> G;
  int h = 1;
  while (h <= n) {
    G.push_back(h);
    h = 3*h + 1;
  }

  shellSort(A, G, n);

  cout << G.size() << endl;
  for(int i=G.size()-1; i>=0; i--) {
    cout << G[i];
    if (i != 0) cout << " ";
  }
  cout << endl;
  cout << cnt << endl;
  for(int i=0; i<n; i++) {
    cout << A[i] << endl;
  }

  return 0;
}