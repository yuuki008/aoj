#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  string str;
  cin >> str;

  int q;
  cin >> q;
  
  for (int i=0; i<q; i++) {
    string command;
    cin >> command;

    if (command == "print") {
      int a, b;
      cin >> a >> b;
      cout << str.substr(a, b-a+1) << endl;
    } else if (command == "reverse") {
      int a, b;
      cin >> a >> b;
      reverse(str.begin()+a, str.begin()+b+1);
    } else if (command == "replace") {
      int a, b;
      string p;
      cin >> a >> b >> p;

      str.replace(a, b-a+1, p);
    }
  }

  return 0;
}
