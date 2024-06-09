#include <iostream>
#include <vector>
using namespace std;

#define MAX 100000

// グローバル変数の宣言
int numPackages, numTrucks;
long long packages[MAX];

// 最大積載量maxCapacityで全ての荷物を積むことができるかチェックする関数
int check(long long maxCapacity) {
    int currentPackageIndex = 0;

    // 各トラックに積み込む
    for (int truck = 0; truck < numTrucks; truck++) {
        long long currentLoad = 0; // 現在のトラックの積載量

        // トラックに詰めるだけ荷物を積む
        while (currentLoad + packages[currentPackageIndex] <= maxCapacity) {
            currentLoad += packages[currentPackageIndex];
            currentPackageIndex++;
            if (currentPackageIndex == numPackages) return currentPackageIndex;
        }
    }

    return currentPackageIndex;
}

int main() {
    cin >> numPackages >> numTrucks;
    for (int i = 0; i < numPackages; i++) {
        cin >> packages[i];
    }

    long long left = 0;
    long long right = 100000 * 10000;
    long long mid;

    // 二分探索で最小の積載量を求める
    while (right - left > 1) {
        mid = (left + right) / 2;
        int numLoadedPackages = check(mid);
        if (numLoadedPackages >= numPackages) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << right << endl;

    return 0;
}
