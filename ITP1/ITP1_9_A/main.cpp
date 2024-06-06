#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  string w;
  cin >> w;

  int cnt = 0;
  while (true) {
    string t;
    cin >> t;
    if (t == "END_OF_TEXT") {
      break;
    }

    transform(t.begin(), t.end(), t.begin(), ::tolower);
    if (t == w) {
      cnt++;
    }
  }

  cout << cnt << endl;
  return 0;
}
