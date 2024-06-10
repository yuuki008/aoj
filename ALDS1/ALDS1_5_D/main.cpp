#include <iostream>
#include <vector>
using namespace std;


// 反転数を求めるプログラム
// 反転数は配列の要素においてある要素がその後に現れる要素よりも大きい場合のペアの数を指す。
// このプログラムでマージソートを使って反転数を求めている。
// バブルソートでも反転数を求められるが O(n^2) かかるため O(n log n) のマージソートを使っている。
// マージソートは、再帰的に配列を分割していき、結合しながらソートしていくアルゴリズムである。
// L と R に分けた配列を結合していく時に、反転数を求める。

long long mergeAndCount(vector<int>& arr, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;
  
  vector<int> L(n1);
  vector<int> R(n2);
  
  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (int i = 0; i < n2; i++)
    R[i] = arr[mid + 1 + i];
  
  int i = 0, j = 0, k = left;
  long long inv_count = 0;
  
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k++] = L[i++];
    } else {
      arr[k++] = R[j++];
      // n1 は左部分配列の要素数
      // i は現在の左部分配列のインデックス
      // n1 - i は残りの左部分配列の要素数
      inv_count += (n1 - i);
    }
  }
  
  while (i < n1)
    arr[k++] = L[i++];
  while (j < n2)
    arr[k++] = R[j++];
  
  return inv_count;
}

long long mergeSortAndCount(vector<int>& arr, int left, int right) {
  long long inv_count = 0;
  if (left < right) {
    int mid = left + (right - left) / 2;
    
    inv_count += mergeSortAndCount(arr, left, mid);
    inv_count += mergeSortAndCount(arr, mid + 1, right);
    
    inv_count += mergeAndCount(arr, left, mid, right);
  }
  return inv_count;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  
  cout << mergeSortAndCount(arr, 0, n - 1) << endl;
  return 0;
}
