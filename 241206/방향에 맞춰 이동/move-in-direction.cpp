#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int x=0, y=0;
    int n;
    cin >> n;

    while(n--)
    {
        char dir;
        int len;

        cin >> dir >> len;

        if(dir=='W') x -= len;
        if(dir=='S') y -= len;
        if(dir=='N') y += len;
        if(dir=='E') x += len;
    }
    
    cout << x << " " << y;
    return 0;
}