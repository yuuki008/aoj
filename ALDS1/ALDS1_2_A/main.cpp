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

  bool flag = true;

  int swap_count = 0;
  while (flag) {
    flag = false;
    for (int i=n-1; i>0; i--){
      if (A[i] < A[i-1]) {
        swap_count++;
        swap(A[i], A[i-1]);
        flag = true;
      }
    }
  }

  for (int i=0; i<n; i++) {
    cout << A[i];
    if (i != n-1) {
      cout << " ";
    }
  }
  cout << endl;
  cout << swap_count << endl;

  return 0;
}
