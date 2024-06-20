#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Node {
  public:
    int id;
    int parent;
    int depth;
    vector<int> children;

    Node(int id) : id(id), parent(-1), depth(0) {}
    string type() {
      if (parent == -1) return "root";
      else if (children.size() == 0) return "leaf";
      return "internal node";
    }
};

void setDepth(int id, vector<Node>& nodes, int depth) {
  nodes[id].depth = depth;

  int size = nodes[id].children.size();

  for(int i=0; i<size; i++) {
    Node child = nodes[id].children[i];
    setDepth(child.id, nodes, depth+1);
  };
};

int main() {
  int n;
  cin >> n;

  vector<vector<int>>in;
  vector<Node> nodes;

  for(int i=0; i<n; i++) {
    int id, k;
    cin >> id >> k;

    Node node = Node(id);
    for (int j=0; j<k; j++) {
      int c;
      cin >> c;
      node.children.push_back(c);
    }
    nodes.push_back(node);
  };

  // node の id 番目に node をセット
  for(int i=0; i<n; i++) swap(nodes[i], nodes[nodes[i].id]);

  // parent のセット
  for(int i=0; i<n; i++) {
    Node parent = nodes[i];
    vector<int> children = nodes[i].children;

    for(int j=0; j<children.size(); j++) {
      int childId = children[j];
      nodes[childId].parent = parent.id;
    }
  }

  // root を見つける
  int rootId = 0;
  for(const auto node : nodes) {
    if(node.parent == -1) {
      rootId = node.id;
      break;
    }
  }

  setDepth(rootId, nodes, 0);

  for(int i=0; i<n; i++) {
    cout << "node " << nodes[i].id << ": ";
    cout << "parent = " << nodes[i].parent << ", ";
    cout << "depth = " << nodes[i].depth << ", ";
    cout << nodes[i].type() << ", ";

    vector<int> children = nodes[i].children;
    cout << "[";
    for (int j=0; j<children.size(); j++) {
      cout << children[j];
      if (j<children.size()-1) cout << ", ";
    };
    cout << "]" << endl;
  }

  return 0;
}

