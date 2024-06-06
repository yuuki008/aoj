#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    map<char, int> letter_count;

    for (char c = 'a'; c <= 'z'; ++c) {
        letter_count[c] = 0;
    }

    string s, line;

    // 標準入力から全ての行を読み込む
    while (getline(cin, line)) {
        s += line + '\n';  // 各行の後に改行を追加
    }

    // 各文字を処理
    for (char c : s) {
        if (c >= 'A' && c <= 'Z') {
            c = c + ('a' - 'A');  // 大文字を小文字に変換
        }
        if (c >= 'a' && c <= 'z') {
            letter_count[c] += 1;  // a〜zの範囲内の文字のみカウント
        }
    }

    // 結果を出力
    for (char c = 'a'; c <= 'z'; ++c) {
        cout << c << " : " << letter_count[c] << endl;
    }

    return 0;
}
