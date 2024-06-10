#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <climits>
using namespace std;

void merge(vector<int> &A, int left, int mid, int right, int &cnt) {
  int n1 = mid-left;
  int n2 = right-mid;

  vector<int> L(n1+1);
  vector<int> R(n2+1);

  for(int i=0; i<n1; i++) L[i] = A[left+i];
  for(int i=0; i<n2; i++) R[i] = A[mid+i];

  L[n1] = INT_MAX;
  R[n2] = INT_MAX;

  int l = 0;
  int r = 0;

  for(int i=left; i<right; i++) {
    cnt++;
    if (L[l] <= R[r]) {
      A[i] = L[l];
      l++;
    } else {
      A[i] = R[r];
      r++;
    }
  }
}


void mergeSort(vector<int> &A, int left, int right, int &cnt) {
  if (left+1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, left, mid, cnt);
    mergeSort(A, mid, right, cnt);
    merge(A, left, mid, right, cnt);
  }
}


int main() {
  int n;
  cin >> n;
  vector<int> A(n);

  for(int i=0; i<n; i++) cin >> A[i];

  int cnt = 0;
  mergeSort(A, 0, n, cnt);


  for(int i=0; i<n; i++) {
    if (i) cout << " ";
    cout << A[i];
  }

  cout << endl;
  cout << cnt << endl;
  return 0;
}
