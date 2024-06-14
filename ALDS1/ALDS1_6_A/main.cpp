#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <climits>

using namespace std;

vector<int> countingSort(vector<int> arr) {
  int n = arr.size();
  int min = INT_MAX;
  int max = INT_MIN;

  for(int i=0; i<n; i++) {
    if (arr[i] < min) min = arr[i];
    if (arr[i] > max) max = arr[i];
  };
  int range = max - min + 1;

  vector<int> count(range, 0);
  vector<int> output(n);

  for(int i=0; i<n; i++) count[arr[i]-min]++;

  for(int i=1; i<range; i++) count[i] += count[i-1];

  for(int i=0; i<n; i++) {
    int out_i = count[arr[i]-min]-1;
    output[out_i] = arr[i];
    count[arr[i]-min]--;
  }

  return output;
};


int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0; i<n; i++) cin >> A[i];

  vector<int>ans = countingSort(A);

  for(int i=0; i<n; i++) {
    if (i != 0) cout << " ";
    cout << ans[i];
  };

  cout << endl;

  return 0;
}
