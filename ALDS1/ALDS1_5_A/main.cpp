#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <climits>
using namespace std;
// int n = 5;
// int q = 1;
// vector<int> a = { 1, 5, 7, 10, 21 };
// vector<int> m = { 21 };
int n, q;
vector<int> a;
vector<int> m;


bool exhaustiveSearch(int i, int m) {
  if (i > n) return false;
  if (m < 0) return false;
  if (m == 0) return true;

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
