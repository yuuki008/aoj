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

  vector<int> R(n);
  for(int i=0; i<n;i++) {
    int r;
    cin >> r;
    R[i] = r;
  }

  int maxdiff = INT_MIN;
  int minv = R[0];

  for(int i=1; i<n; i++) {
    maxdiff = max(maxdiff, R[i]-minv);
    minv = min(minv, R[i]);
  }

  cout << maxdiff << endl;
}
