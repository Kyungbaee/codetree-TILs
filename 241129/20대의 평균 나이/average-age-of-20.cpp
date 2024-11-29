#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    float avg_age;
    int cnt=0;

    while(true)
    {
        int age;
        cin >> age;

        if(age < 20 || age > 29)
        {
            cout << fixed;
            cout.precision(2);
            cout << avg_age/cnt;
            break;
        }
        avg_age += age;
        cnt++;

    }
    return 0;
}