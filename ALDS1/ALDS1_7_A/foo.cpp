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
  int n = 13;

  vector<vector<int>> input = {
    {0, 3, 1, 4, 10},
    {1, 2, 2, 3},
    {2, 0},
    {3, 0},
    {4, 3, 5, 6, 7},
    {5, 0},
    {6, 0},
    {7, 2, 8, 9},
    {8, 0},
    {9, 0},
    {10, 2, 11, 12},
    {11, 0},
    {12, 0}
  };

  vector<Node> nodes;

  for(int i=0; i<n; i++) {
    int id = input[i][0];
    Node node = Node(id);

    if (input[i][1] == 0) {
      nodes.push_back(node);
      continue;
    };

    vector<int> children(input[i].begin()+2, input[i].end());
    for(int j=0; j<children.size(); j++) {
      node.children.push_back(children[j]);
    }
    nodes.push_back(node);
  };

  vector<Node> sorted;
  for(int i=0; i<n; i++) {
    int id = nodes[i].id;
    swap(nodes[id], nodes[i]);
  };


  for(int i=0; i<n; i++) {
    vector<int> children = nodes[i].children;

    for(int j=0; j<children.size(); j++) {
      int childId = children[j];
      nodes[childId].parent = nodes[i].id;
    }
  };

  int rootId=0;
  for (const auto& node : nodes) {
    if (node.parent == -1) {
      rootId = node.id;
      break;
    }
  }
  setDepth(rootId, nodes, 0);

  for(int i=0; i<n; i++) {
    cout << "node: " << nodes[i].id << ": ";
    cout << "parent: " << nodes[i].parent << ", ";
    cout << "depth: " << nodes[i].depth << ", ";
    cout << "type: " << nodes[i].type() << ", ";

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

