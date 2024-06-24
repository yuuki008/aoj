#include <iostream>

using namespace std;

struct Node {
  int val;
  Node* left;
  Node* right;
  Node(int v) : val(v), left(nullptr), right(nullptr){};
};

class BST {
  public:
    BST() : root(nullptr) {};

    void insert(int v) {
      root = insertRec(root, v);
    }

    void print() {
      inOrderRec(root);
      cout << endl;
      preOrderRec(root);
      cout << endl;
    }

    void find(int v) {
      Node* currentNode = root;

      bool found=false;
      while(currentNode != nullptr) {
        if (currentNode->val == v) {
          found=true;
          break;
        }

        if(currentNode->val > v) currentNode = currentNode->left;
        else currentNode = currentNode->right;
      }

      if (found) cout << "yes" << endl;
      else cout << "no" << endl;
    }

  private:
    Node* root;

    Node* insertRec(Node *node, int v) {
      if (node == nullptr) return new Node(v);

      if (v < node->val) node->left= insertRec(node->left, v);
      else if (v > node->val) node->right = insertRec(node->right, v);

      return node;
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
  for (int i=0; i<n; i++) {
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
    } else if (order == "print") bst.print();
  }
  return 0;
}
