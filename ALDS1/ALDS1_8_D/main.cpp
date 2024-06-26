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

  void insert(int val, int priority) { root = _insert(root, val, priority); }

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

    return tmp;
  }

  Node *leftRotate(Node *t) {
    Node *tmp = t->right;
    t->right = tmp->left;
    tmp->left = t;
    return tmp;
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

struct Command {
  string type;
  int value;
  int priority;
};

int main() {
  const int n = 16;

  Command commands[n] = {
      {"insert", 35, 99}, // テストコメント
      {"insert", 3, 80},  // テストコメント
      {"insert", 1, 53},  // テストコメント
      {"insert", 14, 25}, // テストコメント
      {"insert", 80, 76}, // テストコメント
      {"insert", 42, 3},  // テストコメント
      {"insert", 86, 47}, // テストコメント
      {"insert", 21, 12}, // テストコメント
      {"insert", 7, 10},  // テストコメント
      {"insert", 6, 90},  // テストコメント
      {"print", 0, 0},    // テストコメント
      {"find", 21, 0},    // テストコメント
      {"find", 22, 0},    // テストコメント
      {"delete", 35, 0},  // テストコメント
      {"delete", 99, 0},  // テストコメント
      {"print", 0, 0}     // テストコメント
  };
  Treap treap;
  for (int i = 0; i < n; i++) {
    Command cmd = commands[i];
    if (cmd.type == "insert") {
      treap.insert(cmd.value, cmd.priority);
    } else if (cmd.type == "find") {
      treap.find(cmd.value);
    } else if (cmd.type == "print") {
      treap.print();
    }
  };
  return 0;
}
