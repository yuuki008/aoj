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
    if (s == "0") {
      break;
    }

    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
      sum += s[i] - '0';
    }
    cout << sum << endl;
  }
}
