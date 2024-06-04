#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
  string input;
  vector<int> numbers;

  getline(cin, input);

  stringstream ss(input);
  int number;

  while (ss >> number){
    numbers.push_back(number);
  }

  sort(numbers.begin(), numbers.end());

  for (int i = 0; i < numbers.size()-1; i++) {
    cout << numbers[i];
    cout << " ";
  }

  cout << numbers[numbers.size()-1] << endl;
  return 0;
}
