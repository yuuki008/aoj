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

  map<string, int> dict;

  for(int i=0; i<n; i++) {
    string op;
    string str;

    cin >> op >> str;

    if (op == "insert") {
      dict[str] = 1;
      continue;
    }


    if (dict.find(str) != dict.end()) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }

  return 0;
}
