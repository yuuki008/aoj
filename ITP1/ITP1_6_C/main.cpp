#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;

  map<int, map<int, vector<int>>> building = {
    {0, {
      {0, vector<int>(10, 0)},
      {1, vector<int>(10, 0)},
      {2, vector<int>(10, 0)}
    }},
    {1, {
      {0, vector<int>(10, 0)},
      {1, vector<int>(10, 0)},
      {2, vector<int>(10, 0)}
    }},
    {2, {
      {0, vector<int>(10, 0)},
      {1, vector<int>(10, 0)},
      {2, vector<int>(10, 0)}
    }},
    {3, {
      {0, vector<int>(10, 0)},
      {1, vector<int>(10, 0)},
      {2, vector<int>(10, 0)}
    }}
  };

  int b, f, r, v;
  for (int i=0; i<n; i++) {
    cin >> b >> f >> r >> v;

    building[b-1][f-1][r-1] += v;
  }

  for(int i=0; i<4; i++) {
    for(int j=0; j<3; j++) {
      for(int k=0; k<10;k++) {
        cout << " " << building[i][j][k];
      }

      cout << endl;
    }

    if (i != 3) {
      cout << "####################" << endl;
    }
  }
  return 0;
}
