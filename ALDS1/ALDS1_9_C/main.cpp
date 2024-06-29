#include <iostream>
#include <vector>
using namespace std;

vector<int> heap;

void heapify_up(int i) {
  if (i == 0) return; // If it's the root, return
  int parent = (i - 1) / 2;
  if (heap[parent] < heap[i]) {
    swap(heap[parent], heap[i]);
    heapify_up(parent);
  }
}

void insert(int key) {
  heap.push_back(key);
  heapify_up(heap.size() - 1);
}

void heapify_down(int i) {
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int largest = i;

  if (left < heap.size() && heap[left] > heap[largest]) {
    largest = left;
  }
  if (right < heap.size() && heap[right] > heap[largest]) {
    largest = right;
  }

  if (largest != i) {
    swap(heap[i], heap[largest]);
    heapify_down(largest);
  }
}

void extract() {
  if (heap.size() < 1)
    return;

  cout << heap[0] << endl;
  heap[0] = heap.back();
  heap.pop_back();
  heapify_down(0);
}

int main() {
  while (true) {
    string op;
    cin >> op;
    if (op == "insert") {
      int val;
      cin >> val;
      insert(val);
    } else if (op == "extract") {
      extract();
    } else if (op == "end") {
      break;
    }
  }

  return 0;
}

