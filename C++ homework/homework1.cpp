#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int age;
    string goal;
    int goal_score;
    int ach; // ach => achieve
    double visach;

    cout << "이름을 입력하세요 :";
    cin >> name;
    cout << "나이를 입력하세요 : ";
    cin >> age;
    cout << "나의 목표를 입력하세요 : ";
    cin >> goal;
    cout << "목표 수치를 입력하세요(0 ~ 100) :";
    cin >> goal_score;
    cout << "현재 진행 수치를 입력하세요(0 ~ 100) : ";
    cin >> ach;
    cout << "비전 활성화 여부(1 : 시작, 0 : 대기) : ";
    cin >> visach; 

    if (goal_score != 0) {
        visach = (double)visach / goal_score * 100;
    } else {
        visach = 0;
    } 

    cout << "--- 나의 성장 비전 리포트 ---\n"; 
    cout << "성함: " << name << " (" << age << "세)\n";
    cout << "목표 비전: " << goal <<"\n";
    cout << "진행도: " << ach << '/' << goal_score << "\n" ;
    cout << "현재 달성률: " << visach << "%" <<"\n" ;
    
    if(ach == 1) {
        cout << "운영 상태 진행중";
    }
    else {
        cout << "운영 상태 대기중";
    }
    return 0;
}




