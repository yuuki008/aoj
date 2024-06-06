#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  string s, p;
  cin >> s >> p;

  s += s;

  for (int i = 0; i < s.size(); i++) {
    if (s.substr(i, p.size()) == p) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
