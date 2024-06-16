#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <climits>
using namespace std;

int recursion_count = 0;

struct Card {
  char suit;
  int value;
};
// クイックソートのパーティション分割関数
int partition(vector<Card>& A, int l, int r) {
  int pivot = A[r].value;
  int i = l - 1;
  for (int j = l; j < r; j++) {
    if (A[j].value <= pivot) {
      i++;
      swap(A[i], A[j]);
    }
  }
  swap(A[i + 1], A[r]);
  return i + 1;
}

// クイックソートの実装
void quickSort(vector<Card>& A, int l, int r) {
  if (l < r) {
    int pivot = partition(A, l, r);
    quickSort(A, l, pivot - 1);
    quickSort(A, pivot + 1, r);
  }
}

// バブルソート
void bubbleSort(vector<Card>&A) {
  int n = A.size();

  for(int i=0; i<n; i++) {
    for (int j=i+1; j<n; j++) {
      if (A[j].value<A[j-1].value) swap(A[j], A[j-1]);
    }
  }
}

int main() {
  int n = 12;
  vector<Card> A = {
    {'H', 3}, {'S', 3}, {'D', 3}, {'C', 3},
    {'H', 1}, {'S', 1}, {'D', 1}, {'H', 2},
    {'C', 1}, {'S', 2}, {'D', 2}, {'C', 2}
  };


  vector<Card> qsA = A;
  quickSort(qsA, 0, n-1);

  vector<Card> bsA = A;
  bubbleSort(A);

  cout << "クイックソート結果" << endl;
  for(int i=0; i<n; i++) cout << qsA[i].suit << " " << qsA[i].value << endl;
  cout << endl;

      // 見出しの出力
  int width=5;
  std::cout << std::setw(width) << "クイックソート" << "    " << std::setw(width) << "バブルソート" << std::endl;
  std::cout << "================================" << std::endl;

    // 配列の要素を出力
  for (size_t i = 0; i < qsA.size(); i++) {
    std::cout << std::setw(width) << qsA[i].suit << " " << qsA[i].value;
    std::cout << std::setw(width) << " ";

    std::cout << "    ";

    std::cout << std::setw(width) << bsA[i].suit << " " << qsA[i].value;
    std::cout << std::setw(width) << " ";

    std::cout << std::endl;
  }

  return 0;
}
