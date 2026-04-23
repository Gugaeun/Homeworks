#include <iostream>
#include <bitset>
#include <climits>
using namespace std;

// 안전 계산 함수
bool safe_calc(int a, int b, char op, int &result) {
    if (op == '+') {
        if ((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b)) {
            return false;
        }
        result = a + b;
    }
    else if (op == '-') {
        if ((b < 0 && a > INT_MAX + b) || (b > 0 && a < INT_MIN + b)) {
            return false;
        }
        result = a - b;
    }
    else if (op == '*') {
        if (a != 0 && b != 0) {
            if (a > INT_MAX / b || a < INT_MIN / b) {
                return false;
            }
        }
        result = a * b;
    }
    else if (op == '/') {
        if (b == 0) {
            cout << "❌ 0으로 나눌 수 없습니다.\n";
            exit(1);
        }
        result = a / b;
    }
    return true;
}

int main() {
    int num[4];
    char op[3];

    // 입력
    cout << "첫번째 숫자 입력: ";
    cin >> num[0];
    cout << "첫번째 연산자 입력: ";
    cin >> op[0];

    cout << "두번째 숫자 입력: ";
    cin >> num[1];
    cout << "두번째 연산자 입력: ";
    cin >> op[1];

    cout << "세번째 숫자 입력: ";
    cin >> num[2];
    cout << "세번째 연산자 입력: ";
    cin >> op[2];

    cout << "네번째 숫자 입력: ";
    cin >> num[3];

    int temp;

    // 1단계: *, /
    for (int i = 0; i < 3; i++) {
        if (op[i] == '*' || op[i] == '/') {
            if (!safe_calc(num[i], num[i + 1], op[i], temp)) {
                cout << "❌ 오버플로우/언더플로우 발생!\n";
                return 0;
            }
            num[i + 1] = temp;
            op[i] = '+'; // 무력화
        }
    }

    // 2단계: +, -
    int result = num[0];

    for (int i = 0; i < 3; i++) {
        if (!safe_calc(result, num[i + 1], op[i], temp)) {
            cout << "❌ 오버플로우/언더플로우 발생!\n";
            return 0;
        }
        result = temp;
    }

    // 출력
    cout << "\n[결과]\n";
    cout << "Bin : " << bitset<16>(result) << endl;
    cout << "Dec : " << result << endl;
    cout << "Hex : 0x" << hex << uppercase << result << endl;

    return 0;
}