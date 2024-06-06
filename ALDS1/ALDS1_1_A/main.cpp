#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];

  for (int i=0; i<n;i++) {
    int v = a[i];
    int j = i - 1;

    while (j >=0 && a[j] > v) {
      a[j+1] = a[j];
      j--;
    }

    a[j+1] = v;

    for (int k=0; k<n; k++) {
      cout << a[k];
      if (k < n-1) cout << " ";
    }
    cout << endl;
  }
  return 0;
}
