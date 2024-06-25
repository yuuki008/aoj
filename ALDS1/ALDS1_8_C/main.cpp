#include <iostream>

using namespace std;

struct Node {
  int val;
  Node *parent;
  Node *left;
  Node *right;
  Node(int v) : val(v), parent(nullptr), left(nullptr), right(nullptr){};
};

class BST {
public:
  BST() : root(nullptr){};

  void insert(int v) { root = insertRec(nullptr, root, v); }

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

  void remove(int v) { deleteNode(root, v); }

private:
  Node *root;

  Node *insertRec(Node *parent, Node *node, int v) {
    if (node == nullptr)
      return new Node(v);

    if (v < node->val)
      node->left = insertRec(node, node->left, v);
    else if (v > node->val)
      node->right = insertRec(node, node->right, v);

    node->parent = parent;
    return node;
  }

  Node *deleteNode(Node *root, int v) {
    if (!root)
      return root;

    if (v < root->val) {
      root->left = deleteNode(root->left, v);
      return root;
    };
    if (v > root->val) {
      root->right = deleteNode(root->right, v);
      return root;
    };

    if (!root->left) {
      Node *tmp = root->right;
      delete root;
      return tmp;
    } else if (!root->right) {
      Node *tmp = root->left;
      delete root;
      return tmp;
    }

    Node *minNode = root->right;
    while (minNode && !minNode) {
      minNode = minNode->left;
    }
    root->val = minNode->val;
    root->right = deleteNode(root->right, minNode->val);
    return root;
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
  int n;
  cin >> n;

  BST bst;
  for (int i = 0; i < n; i++) {
    string order;
    cin >> order;

    if (order == "insert") {
      int val;
      cin >> val;
      bst.insert(val);
    } else if (order == "find") {
      int val;
      cin >> val;
      bst.find(val);
    } else if (order == "delete") {
      int val;
      cin >> val;
      bst.remove(val);
    } else if (order == "print")
      bst.print();
  }
  return 0;
}
