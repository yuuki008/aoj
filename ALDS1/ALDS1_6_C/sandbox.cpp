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

int partition(vector<Card> &A, int l, int r) {
  int pivot_v = A[r].value;
  int pivot_i = l-1;

  for(int i=l; i<r; i++) {
    if(A[i].value <= pivot_v) {
      pivot_i++;
      Card tmp = A[pivot_i];
      A[pivot_i] = A[i];
      A[i] = tmp;
    };
  };

  Card tmp = A[pivot_i+1];
  A[pivot_i+1] = A[r];
  A[r] = tmp;

  return pivot_i+1;
}


void quickSort(vector<Card> &A, int l, int r) {
  if (l < r) {
    int pivot = partition(A, l, r);

    quickSort(A, l, pivot-1);
    quickSort(A, pivot+1, r);
  };
};

void bubbleSort(vector<Card> &A) {
  int n = A.size();

  for(int i=n; i>=0; i--) {
    for (int j=i; j<n-1; j++) {
      if(A[j].value > A[j+1].value) {
        Card tmp = A[j];
        A[j] = A[j+1];
        A[j+1] = tmp;
      }
    }
  }
};


int main() {
  int n = 6;
  vector<Card> A = {
    { 'D', 3 },
    { 'H', 2 },
    { 'D', 1 },
    { 'S', 3 },
    { 'D', 2 },
    { 'C', 1 }
  };

  vector<Card> qsA = A;
  quickSort(qsA, 0, n-1);

  vector<Card> bsA = A;
  bubbleSort(bsA);

  bool isStable = true;

  for(int i=0; i<n; i++) {
    if (bsA[i].suit != qsA[i].suit) isStable = false;
  };

  if (isStable == true) cout << "Stable" << endl;
  else cout << "Not Stable" << endl;


  for(int i=0; i<n; i++) cout << qsA[i].suit << " " << qsA[i].value << endl;
  cout << endl;

  return 0;
}
