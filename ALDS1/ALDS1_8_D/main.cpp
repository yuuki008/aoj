#include <iostream>
#include <string>
using namespace std;

struct Node {
  int val;
  int priority;
  Node *parent;
  Node *left;
  Node *right;
  Node(int val, int priority)
      : val(val), priority(priority), parent(nullptr), left(nullptr),
        right(nullptr){};
};

class Treap {
public:
  Treap() : root(nullptr){};
  void print() {
    inOrderRec(root);
    cout << endl;
    preOrderRec(root);
    cout << endl;
  }
  void find(int v) {
    Node *currentNode = root;

    bool found = false;
    while (currentNode != nullptr) {
      if (currentNode->val == v) {
        found = true;
        break;
      }

      if (currentNode->val > v)
        currentNode = currentNode->left;
      else
        currentNode = currentNode->right;
    }

    if (found)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  };
  void insert(int val) {}

private:
  Node *root;
  Node *_insert(Node *t, int val, int priority) {
    if (!t)
      return new Node(val, priority);

    if (val == t->val)
      return t;

    if (val < t->val) {
      t->left = _insert(t->left, val, priority);
      if (t->priority < t->left->priority)
        t = rightRotate(t);
    } else {
      t->right = _insert(t->right, val, priority);
      if (t->priority < t->right->priority)
        t = leftRotate(t);
    }

    return t;
  };

  Node *rightRotate(Node *t) {
    Node *tmp = t->left;
    t->left = tmp->right;
    tmp->right = t;
    return t;
  }

  Node *leftRotate(Node *t) {
    Node *tmp = t->right;
    t->right = tmp->left;
    tmp->left = t;
    return t;
  }

  void inOrderRec(Node *node) {
    if (node != nullptr) {
      inOrderRec(node->left);
      cout << " " << node->val;
      inOrderRec(node->right);
    }
  };

  void preOrderRec(Node *node) {
    if (node != nullptr) {
      cout << " " << node->val;
      preOrderRec(node->left);
      preOrderRec(node->right);
    }
  };
};

int main() {
  const int n = 16;

  const string orders[n] = {"insert 35 99", "insert 3 80",  "insert 1 53",
                            "insert 14 25", "insert 80 76", "insert 42 3",
                            "insert 86 47", "insert 21 12", "insert 7 10",
                            "insert 6 90",  "print",        "find 21",
                            "find 22",      "print"};

  Treap treap;
  for (int i = 0; i < n; i++) {
    string order = orders[i];
    if (order.substr(0, 6) == "insert") {
      int pos = order.find(" ", 7);
      int val = stoi(order.substr(7, pos - 7));
      int priority = stoi(order.substr(pos + 1));
      treap.insert(val); // 優先度の処理を追加
    } else if (order.substr(0, 4) == "find") {
      int val = stoi(order.substr(5));
      treap.find(val);
    } else if (order == "print")
      treap.print();
  }
  return 0;
}
