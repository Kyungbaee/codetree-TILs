#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, i=1;
    cin >> n;

    while(true)
    {
        if((n/i)<=1) {
            cout << i;
            break;
        }
        else n /= i;
        i++;
    }
    return 0;
}