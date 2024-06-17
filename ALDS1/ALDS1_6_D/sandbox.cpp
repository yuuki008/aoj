#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

static const int MAXW = 10000;

int main () {
  int n;
  cin >> n;
  vector<int> A;
  for(int i=0; i<n; i++) cin >> A[i];

  vector<int>sorted=A;
  sort(sorted.begin(),  sorted.end());

  vector<int>positions(MAXW);
  vector<bool>visited(n);

  for(int i=0; i <n; i++) positions[sorted[i]] = i;

  int ans = 0;
  for(int i=0; i<n; i++) {
    if(visited[i]) continue;

    int current_i=i;
    int sum=0;
    int minW=INT_MAX;
    int length=0;

    while (true) {
      visited[current_i] = true;
      length++;
      int current = positions[current_i];
      minW = min(current, minW);
      sum+=current;
      current_i = positions[current];
      if (visited[current_i]) break;
    }

    ans += min(sum+(length-2)*minW, minW+sum+(length+1)*sorted[0]);
  };

  cout << ans << endl;
  return 0;
}
