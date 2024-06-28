#include <initializer_list>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H;
  cin >> H;
  vector<int> heap(H);

  for (int i = 0; i < H; i++)
    cin >> heap[i];

  for (int i = 1; i < H + 1; i++) {
    int key = heap[i - 1];

    cout << "node " << i << ": ";
    cout << "key = " << key << ", ";
    int parent = i / 2 - 1;
    if (parent >= 0)
      cout << "parent key = " << heap[parent] << ", ";

    int left = 2 * i - 1;
    if (left < heap.size())
      cout << "left key = " << heap[left] << ", ";

    int right = 2 * i;
    if (right < heap.size())
      cout << "right key = " << heap[right] << ", ";
    cout << endl;
  }
};
