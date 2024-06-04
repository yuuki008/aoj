#include <iostream>
#include <iomanip> // 追加
using namespace std;

int main() {
    int a, b;

    cin >> a >> b;

    // 整数の割り算
    int intResult = a / b;

    // 浮動小数点数の割り算
    double floatResult = static_cast<double>(a) / b;

    // 結果の出力
    cout << intResult;
    cout << " ";
    cout << a % b;
    cout << " ";
    cout << fixed << setprecision(5) << floatResult << endl;

    return 0;
}
