#include <iostream>
#include <vector>
#include <string>
using namespace std;

class DoubleLinkedList {
  struct Node {
    int key;
    Node *prev, *next;
    Node(int k) : key(k), prev(nullptr), next(nullptr) {}
  };
  Node* head;
  Node* tail;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    void insert(int key) {
      Node* node = new Node(key);

      if (head == nullptr) {
        head = tail = node;
      } else {
        node->next = head;
        head->prev = node;
        head = node;
      }
    }

    void remove(int key) {
      Node* current = head;

      while (current != nullptr) {
        if (current-> key != key) {
          current = current->next;
          continue;
        }


        if (current->prev != nullptr) {
          current->prev->next = current->next;
        } else {
          head = current->next;
        }
        if (current->next != nullptr) {
          current->next->prev = current->prev;
        } else {
          tail = current->prev;
        }
        delete current;
        break;
      }
    }

    void removeFirst() {
      if (head == nullptr) return;

      Node* current = head;
      head = head->next;
      head->prev = nullptr;
      delete current;
    }

    void removeLast() {
      if (tail == nullptr) return;

      Node* current = tail;
      tail = tail->prev;
      tail->next = nullptr;
      delete current;
    }

    void display() {
      Node* current = head;
      while (current != nullptr) {
        cout << current->key;
        if (current->next != nullptr) {
          cout << " ";
        }
        current = current->next;
      }
      cout << endl;
    }
};

int main() {
  int n;
  cin >> n;

  DoubleLinkedList list;

  for (int i = 0; i < n; i++) {
    string command;
    cin >> command;

    if (command == "insert") {
      int key;
      cin >> key;
      list.insert(key);
    } else if (command == "delete") {
      int key;
      cin >> key;
      list.remove(key);
    } else if (command == "deleteFirst") {
      list.removeFirst();
    } else if (command == "deleteLast") {
      list.removeLast();
    }
  }

  list.display();

  return 0;
}
