#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <climits>
using namespace std;

int n, q;
vector<int> a;
vector<int> m;


bool exhaustiveSearch(int i, int m) {
  if (m == 0) return true;
  if (m < 0 || i >= n) return false;

  if (exhaustiveSearch(i+1, m-a[i])) return true;
  return exhaustiveSearch(i+1, m);
}

int main() {
  cin >> n;
  for(int i=0; i<n; i++) {
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
  }

  cin >> q;
  for(int i=0; i<q; i++) {
    int tmp;
    cin >> tmp;
    m.push_back(tmp);
  }
  

  for(int i=0; i<q; i++) {
    if (exhaustiveSearch(0, m[i])) cout << "yes" << endl;
    else cout << "no" << endl;
  }
  
  return 0;
}
