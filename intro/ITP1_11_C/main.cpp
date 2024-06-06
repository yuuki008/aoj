#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

struct Dice {
    int faces[6]; // 0: top, 1: front, 2: right, 3: left, 4: back, 5: bottom

  Dice(const vector<int>& values) {
    for (int i = 0; i < 6; i++) {
    faces[i] = values[i];
    }
  }
  void roll(char c) {
    int tmp;

    switch (c) {
      case 'N': // North
        tmp = faces[0];
        faces[0] = faces[1];
        faces[1] = faces[5];
        faces[5] = faces[4];
        faces[4] = tmp;
        break;
      case 'S': // South
        tmp = faces[0];
        faces[0] = faces[4];
        faces[4] = faces[5];
        faces[5] = faces[1];
        faces[1] = tmp;
        break;
      case 'E': // East
        tmp = faces[0];
        faces[0] = faces[3];
        faces[3] = faces[5];
        faces[5] = faces[2];
        faces[2] = tmp;
        break;
      case 'W': // West
        tmp = faces[0];
        faces[0] = faces[2];
        faces[2] = faces[5];
        faces[5] = faces[3];
        faces[3] = tmp;
        break;
      case 'R': // Right rotation (horizontal rotation)
        tmp = faces[1];
        faces[1] = faces[2];
        faces[2] = faces[4];
        faces[4] = faces[3];
        faces[3] = tmp;
        break;
      default:
        break;
    }
  }

  bool isEqual(const Dice& other) const {
    for (int i = 0; i < 6; i++) {
        if (faces[i] != other.faces[i]) {
            return false;
        }
    }
    return true;
  }
};

int main() {
  vector<int> dice1_values;
  vector<int> dice2_values;

  for (int i = 0; i < 6; i++) {
    int v;
    cin >> v;
    dice1_values.push_back(v);
  }

  for (int i = 0; i < 6; i++) {
    int v;
    cin >> v;
    dice2_values.push_back(v);
  }

  Dice dice1(dice1_values);
  Dice dice2(dice2_values);

  string rotations = "NNNNWNNNWNNNENNNENNNWNNN";

  for (char c : rotations) {
    dice1.roll(c);
    if (dice1.isEqual(dice2)) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;

  return 0;
}
