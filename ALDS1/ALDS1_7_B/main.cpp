#include <iostream>
#include <vector>
using namespace std;

#define MAX 25
#define NIL -1


struct Node {
  int p, l, r;
  Node(): p(NIL), l(NIL), r(NIL) {}
};

vector<Node> nodes(MAX);
vector<int> depths(MAX);
vector<int> sibling(MAX, -1);
vector<int> degrees(MAX);
vector<int> heights(MAX);
int max_depth;

/**
 * Computes the depth and height of the nodes in a binary tree.
 *
 * @param id The ID of the current node.
 * @param depth The depth of the current node.
 * @return The height of the current node.
 */
int computeDepthAndHeight(int id, int depth) {
  if (depth > max_depth) max_depth = depth;
  depths[id] = depth;

  int l = nodes[id].l;
  int r = nodes[id].r;

  int leftHeight = 0;
  int rightHeight = 0;
  if (l != NIL) leftHeight = computeDepthAndHeight(l, depth + 1);
  if (r != NIL) rightHeight = computeDepthAndHeight(r, depth + 1);

  int height = (leftHeight > rightHeight) ? leftHeight : rightHeight;
  heights[id] = height;
  return height + 1;
}

int main () {
  int n;
  cin >> n;

  for(int i=0; i<n; i++) {
    int id, l, r;
    cin >> id >> l >> r;

    nodes[id].l = l;
    nodes[id].r = r;

    if (l != NIL) {
      nodes[l].p = id;
      degrees[id] += 1;
    }

    if (r != NIL) {
      nodes[r].p = id;
      degrees[id] += 1;
    }

    if (l != NIL && r != NIL) {
      sibling[l]=r;
      sibling[r]=l;
    }
  }

  // ルートの探索
  int root = 0;
  for (int i=0;i<n;i++) {
    if(nodes[i].p == NIL) {
      root = i;
      break;
    }
  }

  computeDepthAndHeight(root, 0);


  for (int i=0; i<n; i++) {
    cout << "node " << i << ": ";
    cout << "parent = " << nodes[i].p << ", ";
    cout << "sibling = " << sibling[i] << ", ";
    cout << "degree = " << degrees[i] << ", ";
    cout << "depth = " << depths[i] << ", ";
    cout << "height = " << heights[i] << ", ";

    if (nodes[i].p == NIL) cout << "root";
    else if (nodes[i].l == NIL && nodes[i].r == NIL) cout << "leaf";
    else cout << "internal node";
    cout << endl;
  }
  return 0;
}
