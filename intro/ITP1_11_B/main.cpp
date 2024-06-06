#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

struct Dice {
  int top;
  int south;
  int east;
  int west;
  int north;
  int bottom;

  Dice(const vector<int>& values) {
    top = values[0];
    south = values[1];
    east = values[2];
    west = values[3];
    north = values[4];
    bottom = values[5];
  }

  void roll(char c) {
    int tmp;
    switch (c) {
      case 'N':
        tmp = top;
        top = south;
        south = bottom;
        bottom = north;
        north = tmp;
        break;
      case 'S':
        tmp = top;
        top = north;
        north = bottom;
        bottom = south;
        south = tmp;
        break;
      case 'E':
        tmp = top;
        top = west;
        west = bottom;
        bottom = east;
        east = tmp;
        break;
      case 'W':
        tmp = top;
        top = east;
        east = bottom;
        bottom = west;
        west = tmp;
        break;
      case 'R':
        tmp = south;
        south = west;
        west = north;
        north = east;
        east = tmp;
        break;
      default:
        break;
    }
  }
};

int main() {
  vector<int> dice_values;

  for (int i = 0; i < 6; i++) {
    int v;
    cin >> v;
    dice_values.push_back(v);
  }

  Dice dice(dice_values);

  int q;
  cin >> q;

  for (int i = 0; i < q; i++) {
    int top, south;
    cin >> top >> south;

    while (dice.top != top) {
      if (dice.south == top) {
        dice.roll('N');
      } else if (dice.north == top) {
        dice.roll('S');
      } else if (dice.east == top) {
        dice.roll('W');
      } else if (dice.west == top) {
        dice.roll('E');
      } else {
        dice.roll('N');
        dice.roll('N');
      }
    }

    while (dice.south != south) {
      dice.roll('R');
    }

    cout << dice.east << endl;
  }

  return 0;
}
