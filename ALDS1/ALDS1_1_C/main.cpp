#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

bool isPrime(int x) {
    if (x <= 1) return false; 
    if (x <= 3) return true; 
    if (x % 2 == 0 || x % 3 == 0) return false; 

    for (int i = 5; i * i <= x; i += 6) {
      if (x % i == 0 || x % (i + 2) == 0) return false;
    }
    return true;
}
int main()
{
  int n;
  cin >> n;
  
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    if (isPrime(x)) ans++;
  }

  cout << ans << endl;
  return 0;
}
