#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <climits>
using namespace std;

int partition(vector<int> &A, int p, int r) {
  int x = A[r];
  int i = p-1;

  for (int j=p; j<r; j++) {
    /* cout << "##########" << endl; */
    /* cout << "i   : " << i << endl; */
    /* cout << "x   : " << x << endl; */
    /* cout << "j   : " << j << endl; */
    /* cout << "A[i]: " << A[i] << endl; */
    /* cout << "A[j]: " << A[j] << endl; */

    if (A[j] <= x) {
      i=i+1;
      int tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    };
  };

  int tmp = A[i+1];
  A[i+1] = A[r];
  A[r] = tmp;

  return i+1;
}

int main() {
  int n=12;
  vector<int> A = { 13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11 };

  int pivot = partition(A, 0, n-1);

  for(int i=0; i<n; i++) {
    if (i!=0) cout << " ";

    if (pivot == i) {
      cout << "[" << A[i] << "]";
    } else {
      cout << A[i];
    };
  }

  cout << endl;
  return 0;
}
