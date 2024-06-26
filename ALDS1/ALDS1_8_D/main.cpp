#include <iostream>
#include <string>
using namespace std;

struct Node {
  int val;
  int priority;
  Node *left;
  Node *right;
  Node(int val, int priority)
      : val(val), priority(priority), left(nullptr), right(nullptr) {}
};

class Treap {
public:
  Treap() : root(nullptr) {}

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
  }

  void insert(int val, int priority) { root = _insert(root, val, priority); }

  void _delete(int val) { root = remove(root, val); }

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
  }

  Node *_remove(Node *t, int val) {
    if (!t->left && !t->right) {
      delete t;
      return nullptr;
    }

    if (!t->left) {
      t = leftRotate(t);
    } else if (!t->right) {
      t = rightRotate(t);
    } else if (t->left->priority > t->right->priority) {
      t = rightRotate(t);
    } else {
      t = leftRotate(t);
    }

    return remove(t, val);
  }

  Node *remove(Node *node, int val) {
    if (!node)
      return nullptr;
    if (val == node->val)
      return _remove(node, val);

    if (val < node->val) {
      node->left = remove(node->left, val);
    } else {
      node->right = remove(node->right, val);
    }

    return node;
  }

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
  }

  void preOrderRec(Node *node) {
    if (node != nullptr) {
      cout << " " << node->val;
      preOrderRec(node->left);
      preOrderRec(node->right);
    }
  }
};

struct Command {
  string type;
  int value;
  int priority;
};

int main() {
  int n;
  cin >> n;

  Treap treap;
  for (int i = 0; i < n; i++) {
    string order;
    cin >> order;

    if (order == "insert") {
      int val, priority;
      cin >> val >> priority;
      treap.insert(val, priority);
    } else if (order == "find") {
      int val;
      cin >> val;
      treap.find(val);
    } else if (order == "delete") {
      int val;
      cin >> val;
      treap._delete(val);
    } else if (order == "print")
      treap.print();
  }
  return 0;
}
