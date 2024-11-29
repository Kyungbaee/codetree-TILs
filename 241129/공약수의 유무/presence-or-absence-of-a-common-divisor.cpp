#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b;
    bool chk = false;
    cin >> a >> b;
    
    for(int i=a; i<=b; i++)
    {
        if(1920%i==0 && 2880%i==0)
        {
            chk = true;
            break;
        }
    }
    if(chk) cout << 1;
    else cout << 0;
    return 0;
}