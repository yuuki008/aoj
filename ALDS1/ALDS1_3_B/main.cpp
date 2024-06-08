#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <climits>
#include <queue>
using namespace std;

int main() {
  int n,q;
  cin >> n >> q;

  queue<pair<string, int>> processingQueue;
  for (int i=0; i<n; i++) {
    string name;
    int time;
    cin >> name >> time;
    processingQueue.push(make_pair(name, time));
  };

  
  int currentTime = 0;
  while (!processingQueue.empty()) {
    pair<string, int> p = processingQueue.front();
    processingQueue.pop();
    if(p.second <= q) {
      currentTime += p.second;
      cout << p.first << " " << currentTime << endl;
    } else {
      int newSecond = p.second - q;
      currentTime += q;
      processingQueue.push(make_pair(p.first, newSecond));
    }
  }
  return 0;
}
