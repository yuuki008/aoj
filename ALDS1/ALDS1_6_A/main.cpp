#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <climits>
using namespace std;

vector<int> countingSort(vector<int>& arr) {
    int size = arr.size();
    if (size == 0) return arr; // 空配列の処理

    // 最大値と最小値を見つける
    int max_val = *max_element(arr.begin(), arr.end());
    int min_val = *min_element(arr.begin(), arr.end());

    // カウント配列のサイズを決定
    int range = max_val - min_val + 1;
    vector<int> count(range, 0);
    vector<int> output(size, 0);

    // 出現回数をカウント
    for (int num : arr) {
        count[num - min_val]++;
    }

    // 累積和を計算
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // 出力配列に値を配置
    for (int i = size - 1; i >= 0; i--) {
        int current_val = arr[i];
        int output_index = count[current_val - min_val] - 1;
        output[output_index] = current_val;
        count[current_val - min_val]--;
    }

    return output;
}


int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for(int i=0; i<n; i++) cin >> A[i];

  vector<int> sorted = countingSort(A);
  for (int i=0; i<n; i++) {
    if (i != 0) cout << " ";
    cout << sorted[i];
  };
  cout << endl;

  return 0;
}
