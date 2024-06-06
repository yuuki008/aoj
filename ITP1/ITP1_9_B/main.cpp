#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  while (true) {
    string s;
    cin >> s;

    if (s == "-") break;

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
      int h;
      cin >> h;

      string t = s.substr(h, s.size()-h);
      s = t + s.substr(0, h);
    }

    cout << s << endl;
  }
  return 0;
}
