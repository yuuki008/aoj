#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    // vector<斜面 \ の位置>
    vector<int> stack;
    // vector<水たまり開始位置, 水たまりの面積>
    vector<pair<int, int>> ans;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '\\') {
            stack.push_back(i);
            continue;
        }

        if (s[i] == '_' || stack.size() == 0) {
            continue;
        }

        if (s[i] == '/') {
            int leftslope = stack.back();
            stack.pop_back();
            int area = i - leftslope;
            while (ans.size() > 0 && ans.back().first > leftslope) {
                area += ans.back().second;
                ans.pop_back();
            }
            ans.push_back(make_pair(leftslope, area));
        }
    }

    int sum = 0;
    for (int i = 0; i < ans.size(); i++) {
        sum += ans[i].second;
    }
    cout << sum << endl;
    cout << ans.size() << " ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].second;
        if (i != ans.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
    return 0; 
}
