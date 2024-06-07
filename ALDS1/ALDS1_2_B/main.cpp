#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <climits>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> A(n);
  for(int i=0; i<n;i++) {
    int a;
    cin >> a;
    A[i] = a;
  }

  int swap_count = 0;
  for (int i=0; i<n; i++) {
    int minj = i;
    for (int j=i; j<n; j++) {
      if (A[j] < A[minj]) minj = j;
    }

    if (i != minj) {
      swap_count++;
      swap(A[i], A[minj]);
    };
  }

  for(int i=0; i<n;i++){
    cout << A[i];
    if (i != n-1) cout << " ";
  }

  cout << endl;
  cout << swap_count << endl;
  return 0;
}
