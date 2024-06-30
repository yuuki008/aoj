#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, long long> memo;

int fib(int n) {
  if (memo.find(n) != memo.end())
    return memo[n];
  if (n == 0)
    return 1;
  if (n == 1)
    return 1;

  memo[n] = fib(n - 1) + fib(n - 2);
  return memo[n];
}

int main() {
  int n;
  cin >> n;
  cout << fib(n) << endl;
}
