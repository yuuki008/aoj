#include <iostream>
#include <vector>
using namespace std;

void maxHeapify(vector<int> &A, int i, int heapSize) {
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  int largest = i;

  if (l < heapSize && A[l] > A[largest]) {
    largest = l;
  }

  if (r < heapSize && A[r] > A[largest]) {
    largest = r;
  }

  if (largest != i) {
    swap(A[i], A[largest]);
    maxHeapify(A, largest, heapSize);
  }
}

void buildMaxHeap(vector<int> &A) {
  int heapSize = A.size();
  for (int i = heapSize / 2 - 1; i >= 0; i--) {
    maxHeapify(A, i, heapSize);
  }
}

int main() {
  int H;
  cin >> H;
  vector<int> heap(H);

  for(int i=0; i<H; i++) cin >> heap[i];

  buildMaxHeap(heap);

  for (int i = 0; i < heap.size(); i++) {
    cout << " " << heap[i];
  }
  cout << endl;

  return 0;
}
