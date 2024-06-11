#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <climits>
using namespace std;

// C は A の各要素の出現回数を記録するカウント配列
// B は、ソートした配列を格納する配列
int n=7;

void outputArray(vector<int> A) {
  for (int i=0; i<A.size(); i++) cout << A[i] << " ";
}

vector<int> countingSort(vector<int>& arr) {
  int size = arr.size();

  vector<int> count(size, 0);
  vector<int> output(size, 0);

  for (int num : arr) count[num]++;
  
  for (int i=1; i<size; i++) {
    count[i] += count[i-1];
  };
  
  cout << "cout" << endl;
  outputArray(count);
  cout << endl;

  for (int i=size-1; i>=0; i--) {
    int current_val = arr[i];
    int output_index = count[current_val]-1;
    output[output_index] = current_val;

    count[current_val]--;
  }

  return output;
}

int main() {
  cin >> n;
  vector<int> A(n);
  for(int i=0; i<n; i++) cin >> A[i]; 

  vector<int> sorted = countingSort(A);

  outputArray(sorted);

  return 0;
}
