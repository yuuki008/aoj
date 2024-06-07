#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// バブルソート（安定ソート）
void bubbleSort(vector<string>& data) {
    int n = data.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (data[j][1] < data[j - 1][1]) 
                swap(data[j], data[j - 1]);
        }
    }
}

// 選択ソート（不安定ソート）
void selectionSort(vector<string>& data) {
    int n = data.size();
    for (int i = 0; i < n; i++) {
        int mini = i;
        for (int j = i; j < n; j++) {
            if (data[j][1] < data[mini][1]) 
                mini = j;
        }
        if (mini != i) 
            swap(data[i], data[mini]);
    }
}

// 配列の表示
void printArray(const vector<string>& data) {
    for (size_t i = 0; i < data.size(); i++) {
        if (i > 0) cout << " ";
        cout << data[i];
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<string> data1(n), data2(n);

    // データの入力
    for (int i = 0; i < n; i++) {
        cin >> data1[i];
        data2[i] = data1[i];
    }

    // バブルソートの実行
    bubbleSort(data1);
    // 選択ソートの実行
    selectionSort(data2);

    // 結果の表示
    printArray(data1);
    cout << "Stable" << endl;

    printArray(data2);
    if (data1 == data2) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }

    return 0;
}
