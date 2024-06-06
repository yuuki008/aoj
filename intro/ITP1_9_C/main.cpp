#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;

  int tarou = 0;
  int hanako = 0;

  for (int i=0; i<n; i++) {
    string t, h;
    cin >> t >> h;

    if (t > h) {
      tarou += 3;
    } else if(t < h) {
      hanako += 3;
    } else {
      tarou += 1;
      hanako += 1;
    }
  }

  cout << tarou << " " << hanako << endl;
}
