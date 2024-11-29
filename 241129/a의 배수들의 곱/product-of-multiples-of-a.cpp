#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b, mul=1;
    cin >> a >> b;

    for(int i=a; i<=b; i++)
    {
        if(i%a==0) mul *= i;
    }
    cout << mul;
    return 0;
}