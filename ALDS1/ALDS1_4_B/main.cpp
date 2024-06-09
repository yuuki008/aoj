#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <climits>
using namespace std;

bool binarySearch(vector<int> S, int key) {
  int left = 0;
  int right = S.size();
  while (left < right) {
    int mid = (left + right) / 2;
    if (S[mid] == key) return true;

    if (key < S[mid]) right = mid;
    else left = mid + 1;
  }

  return false;
}

int main() {
  int n;
  cin >> n;
  vector<int> S(n);
  for(int i=0; i<n; i++) cin >> S[i];

  int q;
  cin >> q;
  vector<int> T(q);
  for(int i=0; i<q; i++) cin >> T[i];

  int cnt = 0;

  for(int i=0; i<q; i++) {
    if(binarySearch(S, T[i])) cnt++;
  }

  cout << cnt << endl;
  return 0;
}
