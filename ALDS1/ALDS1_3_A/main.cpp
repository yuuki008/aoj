#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <climits>
#include <stack>
using namespace std;

int main() {
  stack<int> stack;
  char s[100];

  while (cin >> s) {
    if (s[0] == '+') {
      int a = stack.top();
      stack.pop();
      int b = stack.top();
      stack.pop();
      stack.push(a + b);
    } else if (s[0] == '-') {
      int a = stack.top();
      stack.pop();
      int b = stack.top();
      stack.pop();
      stack.push(b - a);
    } else if (s[0] == '*') {
      int a = stack.top();
      stack.pop();
      int b = stack.top();
      stack.pop();
      stack.push(a * b);
    } else {
      stack.push(atoi(s));
    }
  }

  cout << stack.top() << endl;

  return 0;
}
