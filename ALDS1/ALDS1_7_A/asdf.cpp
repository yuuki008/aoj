#include <vector>
#include <iostream>
using namespace std;

int main () {
  vector<int> a = { 1, 2, 3, 4, 5 };

  vector<int> b(a.begin()+2, a.end());

  for(int i=0; i<b.size(); i++) {
    cout << b[i] << endl;
  }

  return 0;
};
