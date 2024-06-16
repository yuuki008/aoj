#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Card {
  char suit;
  int value;
  int order;
};

int partition(vector<Card> &A, int l, int r) {
  int pivot = A[r].value;
  int i = l-1;

  for(int j=l; j<r; j++) {
    if(A[j].value <= pivot) {
      i++;
      swap(A[i], A[j]);
    };
  };

  swap(A[i+1], A[r]);
  return i+1;
};

void quickSort(vector<Card> &A, int l, int r) {
  if (l < r) {
    int mid = partition(A, l, r);
    quickSort(A, l, mid-1);
    quickSort(A, mid+1, r);
  }
}
int main () {
  int n;
  cin >> n;

  vector<Card>A(n);
  for (int i=0; i<n; i++) {
    cin >> A[i].suit >> A[i].value;
    A[i].order = i;
  }


  vector<Card> qsA = A;
  quickSort(qsA, 0, n-1);

  bool isStable = true;
  for(int i=1; i<n; i++) {
    if(qsA[i-1].value == qsA[i].value && qsA[i-1].order > qsA[i].order) {
      isStable = false;
      break;
    };
  };

  if (isStable == true) cout << "Stable" << endl;
  else cout << "Not stable" << endl;

  for(int i=0; i<n; i++) cout << qsA[i].suit << " " << qsA[i].value << endl;

  return 0;
}
