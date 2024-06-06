#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  cin.ignore();

  string line;
  getline(cin, line);
  istringstream iss(line);
  
  vector<int> a;
  int number;

  while (iss >> number) {
    a.push_back(number);
  }

  for (int i=n-1; i>=0; i--) {
    cout << a[i];
    if (i > 0) {
      cout << " ";
    }
  }
  cout << endl;
}
