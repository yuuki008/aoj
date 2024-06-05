#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;

  char suit;
  int rank;

  map<char, vector<int>> cards = {
    {'S', vector<int>(14, 0)},
    {'H', vector<int>(14, 0)},
    {'C', vector<int>(14, 0)},
    {'D', vector<int>(14, 0)}
  };

  for (int i=0; i<n; i++) {
    cin >> suit >> rank;

    cards[suit][rank] = 1;
  }

  for (char suit : {'S', 'H', 'C', 'D'}) {
    for (int rank=1; rank<=13; rank++) {
      if (cards[suit][rank] != 1) {
        cout << suit << " " << rank << endl;
      }
    }
  }
}
